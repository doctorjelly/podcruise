#!/usr/bin/env python3
"""Compile recovered C locally and compare linked function bytes with a ROM."""

from __future__ import annotations

import argparse
import hashlib
import json
import pathlib
import shlex
import os
import re
import shutil
import subprocess
import sys
from pathlib import Path


SYMBOL_RE = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")


def sha256_bytes(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def sha256_file(path: Path) -> str:
    return sha256_bytes(path.read_bytes())


def sha256_tree(path: Path) -> str:
    digest = hashlib.sha256()
    for child in sorted(item for item in path.rglob("*") if item.is_file()):
        digest.update(child.relative_to(path).as_posix().encode("utf-8"))
        digest.update(b"\0")
        digest.update(bytes.fromhex(sha256_file(child)))
    return digest.hexdigest()


def load_matching_config(root: Path, path: Path) -> dict:
    """Load a matching config, resolving an optional repository-relative base."""
    resolved = path if path.is_absolute() else root / path
    config = json.loads(resolved.read_text(encoding="utf-8"))
    base_name = config.pop("extends", None)
    if base_name is None:
        return config
    base = load_matching_config(root, Path(base_name))
    base.update(config)
    return base


def run(command: list[str], root: Path, env: dict[str, str] | None = None) -> str:
    completed = subprocess.run(
        command,
        cwd=root,
        env=env,
        check=True,
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
    )
    return completed.stdout


def resolve_compiler(ido_root: Path, version: str) -> Path:
    candidates = (
        ido_root / f"ido-{version}" / "cc",
        ido_root / version / "cc",
    )
    for candidate in candidates:
        if candidate.is_file():
            return candidate.resolve()
    raise SystemExit(f"missing local IDO {version} compiler under {ido_root}")


def resolve_binutils(root: Path, binutils_root: Path) -> tuple[dict[str, Path], dict[str, str]]:
    tools: dict[str, Path] = {}
    for name in ("ld", "nm", "objcopy", "objdump"):
        executable = f"mips-linux-gnu-{name}"
        installed = shutil.which(executable)
        local = binutils_root / "usr/bin" / executable
        if installed is not None:
            tools[name] = Path(installed)
        elif local.is_file():
            tools[name] = local.resolve()
        else:
            raise SystemExit(f"missing {executable} in PATH or {binutils_root}")

    env = os.environ.copy()
    local_library = binutils_root / "usr/lib/x86_64-linux-gnu"
    if local_library.is_dir():
        previous = env.get("LD_LIBRARY_PATH")
        env["LD_LIBRARY_PATH"] = (
            str(local_library.resolve())
            if not previous
            else f"{local_library.resolve()}:{previous}"
        )
    return tools, env


def linker_script(unit: dict) -> str:
    lines: list[str] = []
    for name, value in sorted(unit["absolute_symbols"].items()):
        if SYMBOL_RE.fullmatch(name) is None:
            raise ValueError(f"invalid symbol name: {name}")
        lines.append(f"{name} = {value};")
    sections = [f"    .text {unit['link_vram']} : {{ *(.text) }}"]
    # A translation unit that used floating-point literals carries its own
    # constant pool, and the load displacements only reproduce when that pool
    # sits where the original build placed it.
    if unit.get("rodata_vram"):
        sections.append(f"    .rodata {unit['rodata_vram']} : {{ *(.rodata) }}")
    # A global the original object defined rather than imported has to sit at
    # its canonical address, or the compiler's single address materialisation
    # cannot be reproduced.
    if unit.get("bss_vram"):
        sections.append(
            f"    .bss {unit['bss_vram']} : {{ *(.bss) *(COMMON) }}")
    lines.extend(
        [
            "",
            "SECTIONS",
            "{",
            *sections,
            "    /DISCARD/ : { *(.options) *(.reginfo) *(.mdebug) *(.comment) }",
            "}",
            "",
        ]
    )
    return "\n".join(lines)


def compiler_defines(unit: dict) -> list[str]:
    arguments: list[str] = []
    for source_name, target_name in sorted(unit.get("defines", {}).items()):
        if (
            SYMBOL_RE.fullmatch(source_name) is None
            or SYMBOL_RE.fullmatch(target_name) is None
        ):
            raise ValueError(f"invalid compiler symbol remap: {source_name}={target_name}")
        arguments.append(f"-D{source_name}={target_name}")
    return arguments


def parse_text_section(output: str) -> tuple[int, int]:
    for line in output.splitlines():
        fields = line.split()
        if len(fields) >= 7 and fields[1] == ".text":
            return int(fields[3], 16) & 0xFFFFFFFF, int(fields[2], 16)
    raise ValueError("linked ELF has no .text section")


def parse_function_symbols(output: str) -> dict[str, tuple[int, int]]:
    symbols: dict[str, tuple[int, int]] = {}
    for line in output.splitlines():
        fields = line.split()
        if len(fields) != 4 or fields[2].lower() != "t":
            continue
        address, size, _, name = fields
        symbols[name] = (int(address, 16) & 0xFFFFFFFF, int(size, 16))
    return symbols


def first_difference(expected: bytes, actual: bytes) -> int | None:
    for offset, (left, right) in enumerate(zip(expected, actual)):
        if left != right:
            return offset
    if len(expected) != len(actual):
        return min(len(expected), len(actual))
    return None


def compiler_flags(value) -> list[str]:
    """Accept per-unit flags as a list or as one shell-style string.

    Workers record `flags` both ways. A string was previously spread one
    character per argument, which the compiler rejected with an error that
    named neither the unit nor the cause.
    """
    if isinstance(value, str):
        return shlex.split(value)
    return list(value)


def verify_profile(
    root: Path,
    build_root: Path,
    rom: bytes,
    profile: dict,
    units: list[dict],
    compiler: Path,
    binutils: dict[str, Path],
    binutils_env: dict[str, str],
) -> dict:
    profile_root = build_root / profile["id"]
    profile_root.mkdir(parents=True, exist_ok=True)
    function_results: list[dict] = []

    for unit in units:
        try:
            source = root / unit["source"]
            unit_root = profile_root / unit["id"]
            unit_root.mkdir(parents=True, exist_ok=True)
            object_path = unit_root / f"{unit['id']}.o"
            aligned_object_path = unit_root / f"{unit['id']}.aligned.o"
            elf_path = unit_root / f"{unit['id']}.elf"
            text_path = unit_root / f"{unit['id']}.text.bin"
            script_path = unit_root / f"{unit['id']}.ld"
            script_path.write_text(linker_script(unit), encoding="utf-8")

            # A unit may override the profile flags when its original translation
            # unit was demonstrably built differently (for example the 64-bit
            # integer support routines, which need the MIPS III instruction set).
            unit_flags = compiler_flags(unit.get("flags", profile["flags"]))
            run(
                [
                    str(compiler),
                    "-c",
                    *unit_flags,
                    *compiler_defines(unit),
                    "-Iinclude",
                    unit["source"],
                    "-o",
                    str(object_path),
                ],
                root,
            )
            # Isolated functions inherit a 16-byte input-section alignment from IDO.
            # The original functions are only 4-byte aligned within larger objects;
            # lowering section metadata places the unchanged code at canonical VRAM.
            run(
                [
                    str(binutils["objcopy"]),
                    "--set-section-alignment",
                    ".text=4",
                    str(object_path),
                    str(aligned_object_path),
                ],
                root,
                binutils_env,
            )
            run(
                [
                    str(binutils["ld"]),
                    "-T",
                    str(script_path),
                    "-o",
                    str(elf_path),
                    str(aligned_object_path),
                ],
                root,
                binutils_env,
            )
            run(
                [
                    str(binutils["objcopy"]),
                    "-O",
                    "binary",
                    "--only-section=.text",
                    str(elf_path),
                    str(text_path),
                ],
                root,
                binutils_env,
            )
            text_vram, text_size = parse_text_section(
                run([str(binutils["objdump"]), "-h", str(elf_path)], root, binutils_env)
            )
            symbols = parse_function_symbols(
                run(
                    [str(binutils["nm"]), "-S", "--defined-only", str(elf_path)],
                    root,
                    binutils_env,
                )
            )
            linked_text = text_path.read_bytes()
            if len(linked_text) != text_size:
                raise ValueError(f"{unit['id']}: extracted .text size is inconsistent")

            for function in unit["functions"]:
                name = function["name"]
                # A file-local function compiled with interprocedural register
                # allocation is emitted with no ELF symbol at all, so it cannot be
                # found by name. Such a unit states where in its own .text the body
                # begins. The byte comparison is unchanged; the only thing lost is
                # the independent confirmation of the compiled length, which is
                # recorded per function so the weaker check is never mistaken for
                # the stronger one.
                sized_from_config = False
                if name in symbols:
                    actual_vram, actual_size = symbols[name]
                elif "text_offset" in function:
                    actual_vram = text_vram + int(function["text_offset"], 0)
                    actual_size = int(function["size"])
                    sized_from_config = True
                else:
                    # One malformed unit must not abort measurement of every other
                    # unit. This happens when a source is rewritten so a function
                    # becomes `static` (no ELF symbol) without the unit gaining the
                    # `text_offset` that would locate it. Record the failure and
                    # carry on; the summary reports it as a non-matching function.
                    function_results.append(
                        {
                            "byte_identical": False,
                            "canonical_address": False,
                            "error": "missing compiled symbol",
                            "expected_size": int(function["size"]),
                            "name": name,
                            "size": int(function["size"]),
                            "verified_match": False,
                            "vram": function["vram"],
                        }
                    )
                    continue
                start = actual_vram - text_vram
                actual = linked_text[start : start + actual_size]
                rom_start = int(function["rom"], 0)
                expected_size = int(function["size"])
                expected = rom[rom_start : rom_start + expected_size]
                difference = first_difference(expected, actual)
                canonical_vram = int(function["vram"], 0)
                byte_identical = difference is None
                canonical_address = actual_vram == canonical_vram
                function_results.append(
                    {
                        "actual_sha256": sha256_bytes(actual),
                        "actual_size": actual_size,
                        "actual_vram": f"0x{actual_vram:08X}",
                        "byte_identical": byte_identical,
                        "canonical_address": canonical_address,
                        "expected_sha256": sha256_bytes(expected),
                        "expected_size": expected_size,
                        "expected_vram": function["vram"],
                        "first_difference": None if difference is None else f"0x{difference:X}",
                        "name": name,
                        "source": unit["source"],
                        "size_confirmed_by_symbol": not sized_from_config,
                        "source_sha256": sha256_file(source),
                        "verified_match": byte_identical and canonical_address,
                    }
                )

        except Exception as failure:
            # A unit that will not compile or link must not abort the whole
            # run. Workers add units to the configuration directly, so a
            # half-written or unresolvable one can appear at any time;
            # aborting would hide the state of every other unit behind it.
            print(f"!! {unit['id']}: {failure}", file=sys.stderr)
            for function in unit["functions"]:
                function_results.append({
                    "name": function["name"],
                    "expected_vram": function["vram"],
                    "expected_size": int(function["size"]),
                    "actual_vram": None,
                    "actual_size": None,
                    "expected_sha256": None,
                    "actual_sha256": None,
                    "byte_identical": False,
                    "verified_match": False,
                    "canonical_address": False,
                    "size_confirmed_by_symbol": False,
                    "first_difference": None,
                    "build_error": str(failure)[:200],
                })
            continue
    return {
        "compiler_tree_sha256": sha256_tree(compiler.parent),
        "flags": profile["flags"],
        "functions": function_results,
        "ido_version": profile["ido_version"],
        "isolated_text_alignment": 4,
        "matching_bytes": sum(
            item["expected_size"] for item in function_results if item["verified_match"]
        ),
        "matching_functions": sum(item["verified_match"] for item in function_results),
        "profile": profile["id"],
    }


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--config", type=Path, default=Path("config/c_matching.json"))
    parser.add_argument("--build-root", type=str, default=None,
                        help="private build tree, for an audit that must not "
                             "collide with a concurrent build")
    parser.add_argument("--output", type=Path, default=Path("analysis/c_matches.us.json"))
    parser.add_argument("--profile", action="append", dest="profiles")
    parser.add_argument("--ido-root", type=Path)
    parser.add_argument("--binutils-root", type=Path)
    args = parser.parse_args()

    root = Path(__file__).resolve().parent.parent
    config_path = root / args.config
    config = load_matching_config(root, config_path)
    selected = set(args.profiles or (profile["id"] for profile in config["profiles"]))
    profiles = [profile for profile in config["profiles"] if profile["id"] in selected]
    if len(profiles) != len(selected):
        known = {profile["id"] for profile in config["profiles"]}
        raise SystemExit(f"unknown profiles: {', '.join(sorted(selected - known))}")

    ido_root = args.ido_root or Path(
        os.environ.get("PODCRUISE_IDO_ROOT", root / "build/toolchain")
    )
    binutils_root = args.binutils_root or Path(
        os.environ.get("PODCRUISE_BINUTILS_ROOT", root / "build/toolchain/binutils-mips")
    )
    binutils, binutils_env = resolve_binutils(root, binutils_root)
    rom = (root / config["rom"]).read_bytes()
    # An independent audit needs its own build tree: the default one is shared
    # with whatever else is compiling, so a concurrent run would collide.
    build_root = (pathlib.Path(args.build_root) if getattr(args, "build_root", None)
                  else root / "build/c-matches") / config["version"]

    results = []
    for profile in profiles:
        compiler = resolve_compiler(ido_root, profile["ido_version"])
        result = verify_profile(
            root,
            build_root,
            rom,
            profile,
            config["units"],
            compiler,
            binutils,
            binutils_env,
        )
        results.append(result)
        print(
            f"{profile['id']}: {result['matching_functions']} canonical functions, "
            f"{result['matching_bytes']} bytes"
        )

    output = {
        "config_sha256": sha256_bytes(
            json.dumps(config, sort_keys=True, separators=(",", ":")).encode("utf-8")
        ),
        "profiles": results,
        "schema": 1,
        "scope": f"exact linked function-byte comparisons against the {config['version']} ROM",
        "version": config["version"],
    }
    output_path = root / args.output
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(json.dumps(output, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
