#!/usr/bin/env python3
"""Compile one matching unit and summarize its exact USA ROM comparison."""

from __future__ import annotations

import argparse
import contextlib
import io
import struct
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))

from tools.verify_c_matches import (
    load_matching_config,
    parse_text_section,
    resolve_binutils,
    resolve_compiler,
    run,
    verify_profile,
)


def word_differences(expected: bytes, actual: bytes) -> tuple[int, int, int]:
    """Return differing comparable words, missing words, and extra words."""
    if len(expected) % 4 or len(actual) % 4:
        raise ValueError("MIPS function lengths must be word-aligned")
    comparable = sum(
        left != right
        for left, right in zip(
            struct.iter_unpack(">I", expected), struct.iter_unpack(">I", actual)
        )
    )
    return comparable, max(0, (len(expected) - len(actual)) // 4), max(
        0, (len(actual) - len(expected)) // 4
    )


def audit(root: Path, config_path: Path, unit_id: str, profile_id: str | None,
          build_root: Path) -> bool:
    config = load_matching_config(root, config_path)
    unit = next((item for item in config["units"] if item["id"] == unit_id), None)
    if unit is None:
        raise ValueError(f"unknown matching unit: {unit_id}")
    selected = profile_id or config["accepted_profile"]
    profile = next((item for item in config["profiles"] if item["id"] == selected), None)
    if profile is None:
        raise ValueError(f"unknown compiler profile: {selected}")

    binutils, binutils_env = resolve_binutils(
        root, root / "build/toolchain/binutils-mips"
    )
    compiler = resolve_compiler(root / "build/toolchain", profile["ido_version"])
    rom = (root / config["rom"]).read_bytes()
    # verify_profile prints the entire linker command on a failed unit. The
    # per-function result already records failure, so keep this audit compact.
    with contextlib.redirect_stderr(io.StringIO()):
        results = verify_profile(
            root, build_root, rom, profile, [unit], compiler, binutils,
            binutils_env,
        )["functions"]
    unit_root = build_root / profile["id"] / unit_id
    linked_text_path = unit_root / f"{unit_id}.text.bin"
    linked_elf_path = unit_root / f"{unit_id}.elf"
    if linked_text_path.exists() and linked_elf_path.exists():
        linked_text = linked_text_path.read_bytes()
        text_vram, _ = parse_text_section(run(
            [str(binutils["objdump"]), "-h", str(linked_elf_path)],
            root, binutils_env,
        ))
    else:
        linked_text = b""
        text_vram = 0

    all_exact = True
    by_name = {function["name"]: function for function in unit["functions"]}
    for result in results:
        name = result["name"]
        if result.get("actual_size") is None:
            detail = result.get("build_error") or result.get("error") or ""
            phase = ("link" if "ld.bfd" in detail else
                     "compile" if "-c" in detail else "build")
            print(f"{name}: error={phase} failed")
            all_exact = False
            continue
        function = by_name[name]
        actual_vram = int(result["actual_vram"], 0)
        actual_size = result["actual_size"]
        offset = actual_vram - text_vram
        actual = linked_text[offset : offset + actual_size]
        expected_size = int(function["size"])
        rom_offset = int(function["rom"], 0)
        expected = rom[rom_offset : rom_offset + expected_size]
        if len(actual) != actual_size:
            raise ValueError(f"{name}: linked text is shorter than symbol size")
        differing, missing, extra = word_differences(expected, actual)
        exact = result["verified_match"]
        print(
            f"{name}: size={actual_size}/{expected_size} "
            f"address={'yes' if result['canonical_address'] else 'no'} "
            f"different_words={differing} missing_words={missing} "
            f"extra_words={extra} first={result['first_difference']} "
            f"exact={'yes' if exact else 'no'}"
        )
        all_exact &= exact
    return all_exact


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--config", type=Path, default=Path("config/c_matching.json"))
    parser.add_argument("--unit", required=True)
    parser.add_argument("--profile")
    parser.add_argument("--build-root", type=Path,
                        help="retain isolated build artifacts in this directory")
    args = parser.parse_args()
    root = Path(__file__).resolve().parent.parent
    if args.build_root is None:
        with tempfile.TemporaryDirectory(prefix="podcruise-audit-") as directory:
            return 0 if audit(root, args.config, args.unit, args.profile,
                              Path(directory)) else 1
    return 0 if audit(root, args.config, args.unit, args.profile,
                      args.build_root) else 1


if __name__ == "__main__":
    raise SystemExit(main())
