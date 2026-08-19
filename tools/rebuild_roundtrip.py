#!/usr/bin/env python3
"""Reassemble an untouched splat split and prove that it matches its input ROM."""

from __future__ import annotations

import argparse
import hashlib
import json
import shutil
import subprocess
from pathlib import Path


def sha1(path: Path) -> str:
    digest = hashlib.sha1(usedforsecurity=False)
    with path.open("rb") as handle:
        while chunk := handle.read(1024 * 1024):
            digest.update(chunk)
    return digest.hexdigest()


def run(command: list[str], root: Path) -> None:
    print(" ".join(command), flush=True)
    subprocess.run(command, cwd=root, check=True)


def relative_argument(path: Path, root: Path) -> str:
    """Use the same spelling as splat's linker script to avoid double inputs."""
    return path.relative_to(root).as_posix()


def first_difference(left: Path, right: Path) -> int | None:
    with left.open("rb") as left_handle, right.open("rb") as right_handle:
        offset = 0
        while True:
            left_chunk = left_handle.read(1024 * 1024)
            right_chunk = right_handle.read(1024 * 1024)
            if left_chunk == right_chunk:
                if not left_chunk:
                    return None
                offset += len(left_chunk)
                continue
            common = min(len(left_chunk), len(right_chunk))
            for index in range(common):
                if left_chunk[index] != right_chunk[index]:
                    return offset + index
            return offset + common


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--version", choices=("us", "jp", "eu"), required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()

    root = Path(__file__).resolve().parent.parent
    config = json.loads((root / "config/versions.json").read_text(encoding="utf-8"))
    version = next(item for item in config["versions"] if item["id"] == args.version)

    tools = {}
    for name in ("as", "ld", "objcopy"):
        executable = f"mips-linux-gnu-{name}"
        resolved = shutil.which(executable)
        if resolved is None:
            raise SystemExit(
                f"missing {executable}; on macOS run: brew install mips-linux-gnu-binutils"
            )
        tools[name] = resolved

    generated = root / "analysis/generated" / args.version
    build = root / "build" / args.version
    object_root = build / "analysis/generated" / args.version
    asm_objects = object_root / "asm"
    asset_objects = object_root / "assets"
    asm_objects.mkdir(parents=True, exist_ok=True)
    asset_objects.mkdir(parents=True, exist_ok=True)

    header_o = asm_objects / "header.o"
    main_o = asm_objects / "main.o"
    ipl3_o = asset_objects / "ipl3.o"
    remainder_o = asset_objects / "remainder.o"
    objects = [header_o, ipl3_o, main_o, remainder_o]

    for name, output in (("header", header_o), ("main", main_o)):
        run(
            [
                tools["as"],
                "-march=vr4300",
                "-mabi=32",
                "-I",
                str(generated / "include"),
                "-o",
                str(output),
                str(generated / "asm" / f"{name}.s"),
            ],
            root,
        )

    for name, output in (("ipl3", ipl3_o), ("remainder", remainder_o)):
        run(
            [
                tools["ld"],
                "-r",
                "-b",
                "binary",
                "-o",
                str(output),
                str(generated / "assets" / f"{name}.bin"),
            ],
            root,
        )

    elf_path = build / f"podcruise.{args.version}.elf"
    map_path = build / f"podcruise.{args.version}.map"
    rom_path = build / f"podcruise.{args.version}.z64"
    run(
        [
            tools["ld"],
            "--no-check-sections",
            "--omagic",
            "-T",
            str(generated / "undefined_funcs_auto.txt"),
            "-T",
            str(generated / "undefined_syms_auto.txt"),
            "-T",
            str(generated / f"podcruise.{args.version}.ld"),
            "-Map",
            str(map_path),
            "-o",
            str(elf_path),
            *[relative_argument(path, root) for path in objects],
        ],
        root,
    )
    run([tools["objcopy"], "-O", "binary", str(elf_path), str(rom_path)], root)

    source_path = root / version["path"]
    expected_sha1 = version["expected_sha1"]
    source_sha1 = sha1(source_path)
    rebuilt_sha1 = sha1(rom_path)
    difference = first_difference(source_path, rom_path)
    matched = difference is None and source_sha1 == rebuilt_sha1 == expected_sha1
    result = {
        "schema": 1,
        "version": args.version,
        "expected_sha1": expected_sha1,
        "source_sha1": source_sha1,
        "rebuilt_sha1": rebuilt_sha1,
        "size_bytes": rom_path.stat().st_size,
        "byte_identical": matched,
        "first_difference": None if difference is None else f"0x{difference:X}",
        "toolchain": {
            "assembler": "GNU mips-linux-gnu-as",
            "linker": "GNU mips-linux-gnu-ld",
            "binary_export": "GNU mips-linux-gnu-objcopy",
        },
        "scope": "untouched local assembly and opaque binary round trip; zero C functions",
    }
    output_path = root / args.output
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(json.dumps(result, indent=2, sort_keys=True) + "\n", encoding="utf-8")

    if not matched:
        print(
            f"ERROR: {args.version} rebuild differs; expected {expected_sha1}, "
            f"got {rebuilt_sha1}, first difference {result['first_difference']}"
        )
        return 1
    print(f"{args.version}: byte-identical round trip ({rebuilt_sha1})")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
