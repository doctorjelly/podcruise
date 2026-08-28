#!/usr/bin/env python3
"""Build one contiguous, verified IDO C unit as a linkable partial-decomp object."""

from __future__ import annotations

import argparse
import os
from pathlib import Path

from tools.verify_c_matches import (
    compiler_defines,
    first_difference,
    linker_script,
    load_matching_config,
    parse_function_symbols,
    parse_text_section,
    resolve_binutils,
    resolve_compiler,
    run,
    section_alignment_args,
)


def compiler_flags(value) -> list[str]:
    """Accept per-unit flags as a list or as one shell-style string.

    Workers record `flags` both ways. A string was previously spread one
    character per argument, which the compiler rejected with an error that
    named neither the unit nor the cause.
    """
    if isinstance(value, str):
        return shlex.split(value)
    return list(value)


def contiguous_span(unit: dict) -> int:
    cursor = int(unit["link_vram"], 0)
    for function in unit["functions"]:
        vram = int(function["vram"], 0)
        if vram != cursor:
            raise ValueError(
                f"{unit['id']}: {function['name']} begins at 0x{vram:X}, "
                f"leaving a gap after 0x{cursor:X}"
            )
        cursor += int(function["size"])
    return cursor - int(unit["link_vram"], 0)


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--config", type=Path, default=Path("config/c_matching.json"))
    parser.add_argument("--unit", required=True)
    parser.add_argument("--profile", required=True)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--ido-root", type=Path)
    parser.add_argument("--binutils-root", type=Path)
    args = parser.parse_args()

    root = Path(__file__).resolve().parent.parent
    config = load_matching_config(root, args.config)
    try:
        unit = next(item for item in config["units"] if item["id"] == args.unit)
        profile = next(item for item in config["profiles"] if item["id"] == args.profile)
    except StopIteration as error:
        raise SystemExit("unknown matching unit or compiler profile") from error

    span = contiguous_span(unit)
    ido_root = args.ido_root or Path(
        os.environ.get("PODCRUISE_IDO_ROOT", root / "build/toolchain")
    )
    binutils_root = args.binutils_root or Path(
        os.environ.get("PODCRUISE_BINUTILS_ROOT", root / "build/toolchain/binutils-mips")
    )
    compiler = resolve_compiler(ido_root, profile["ido_version"])
    binutils, binutils_env = resolve_binutils(root, binutils_root)

    work = root / "build/c-integration" / unit["id"]
    work.mkdir(parents=True, exist_ok=True)
    compiler_object = work / "compiler.o"
    aligned_object = work / "compiler.aligned.o"
    linked_elf = work / "linked.elf"
    linked_text = work / "linked.text.bin"
    packed_text = work / "packed.text.bin"
    script = work / "link.ld"
    script.write_text(linker_script(unit), encoding="utf-8")

    run(
        [
            str(compiler),
            "-c",
            *compiler_flags(unit.get("flags", profile["flags"])),
            *compiler_defines(unit),
            "-Iinclude",
            unit["source"],
            "-o",
            str(compiler_object),
        ],
        root,
    )
    run(
        [
            str(binutils["objcopy"]),
            *section_alignment_args(unit),
            str(compiler_object),
            str(aligned_object),
        ],
        root,
        binutils_env,
    )
    run(
        [
            str(binutils["ld"]),
            "-T",
            str(script),
            "-o",
            str(linked_elf),
            str(aligned_object),
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
            str(linked_elf),
            str(linked_text),
        ],
        root,
        binutils_env,
    )

    text_vram, _ = parse_text_section(
        run([str(binutils["objdump"]), "-h", str(linked_elf)], root, binutils_env)
    )
    symbols = parse_function_symbols(
        run(
            [str(binutils["nm"]), "-S", "--defined-only", str(linked_elf)],
            root,
            binutils_env,
        )
    )
    compiled = linked_text.read_bytes()[:span]
    rom = (root / config["rom"]).read_bytes()
    for function in unit["functions"]:
        name = function["name"]
        # A file-local function compiled with interprocedural register
        # allocation carries no ELF symbol, so the unit states where in its own
        # .text the body starts. The refusal check below is unchanged.
        if name in symbols:
            actual_vram, actual_size = symbols[name]
        elif "text_offset" in function:
            actual_vram = text_vram + int(function["text_offset"], 0)
            actual_size = int(function["size"])
        else:
            raise SystemExit(f"{unit['id']}: missing compiled symbol {name}")
        expected_vram = int(function["vram"], 0)
        expected_size = int(function["size"])
        start = actual_vram - text_vram
        actual = linked_text.read_bytes()[start : start + actual_size]
        rom_start = int(function["rom"], 0)
        expected = rom[rom_start : rom_start + expected_size]
        difference = first_difference(expected, actual)
        if actual_vram != expected_vram or difference is not None:
            raise SystemExit(
                f"refusing to integrate nonmatching {name}: "
                f"address 0x{actual_vram:X}, first difference {difference}"
            )

    packed_text.write_bytes(compiled)
    output = root / args.output
    output.parent.mkdir(parents=True, exist_ok=True)
    command = [
        str(binutils["objcopy"]),
        "-I",
        "binary",
        "-O",
        "elf32-tradbigmips",
        "-B",
        "mips",
        "--rename-section",
        ".data=.text,alloc,load,readonly,code,contents",
        "--set-section-alignment",
        ".text=4",
    ]
    unit_vram = int(unit["link_vram"], 0)
    for function in unit["functions"]:
        offset = int(function["vram"], 0) - unit_vram
        command.extend(
            ["--add-symbol", f"{function['name']}=.text:{offset},global,function"]
        )
    command.extend([str(packed_text), str(output)])
    run(command, root, binutils_env)
    print(f"{unit['id']}: packed {len(unit['functions'])} matching C functions ({span} bytes)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
