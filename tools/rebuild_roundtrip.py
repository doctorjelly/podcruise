#!/usr/bin/env python3
"""Reassemble an untouched splat split and prove that it matches its input ROM."""

from __future__ import annotations

import argparse
import hashlib
import json
import os
import shutil
import subprocess
import sys
from pathlib import Path

if __package__:
    from tools.verify_c_matches import load_matching_config
else:
    from verify_c_matches import load_matching_config


def sha1(path: Path) -> str:
    digest = hashlib.sha1(usedforsecurity=False)
    with path.open("rb") as handle:
        while chunk := handle.read(1024 * 1024):
            digest.update(chunk)
    return digest.hexdigest()


def run(command: list[str], root: Path, env: dict[str, str] | None = None) -> None:
    print(" ".join(command), flush=True)
    subprocess.run(command, cwd=root, env=env, check=True)


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
    parser.add_argument(
        "--version", choices=("us", "jp", "eu", "lrg_rev1"), required=True
    )
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()

    root = Path(__file__).resolve().parent.parent
    config = json.loads((root / "config/versions.json").read_text(encoding="utf-8"))
    version = next(item for item in config["versions"] if item["id"] == args.version)

    tools = {}
    local_binutils = root / "build/toolchain/binutils-mips"
    for name in ("as", "ld", "objcopy"):
        executable = f"mips-linux-gnu-{name}"
        resolved = shutil.which(executable)
        local = local_binutils / "usr/bin" / executable
        if resolved is None and local.is_file():
            resolved = str(local.resolve())
        if resolved is None:
            raise SystemExit(
                f"missing {executable}; on macOS run: brew install mips-linux-gnu-binutils"
            )
        tools[name] = resolved

    tool_env = os.environ.copy()
    local_library = local_binutils / "usr/lib/x86_64-linux-gnu"
    if local_library.is_dir():
        previous = tool_env.get("LD_LIBRARY_PATH")
        tool_env["LD_LIBRARY_PATH"] = (
            str(local_library.resolve())
            if not previous
            else f"{local_library.resolve()}:{previous}"
        )

    generated = root / "analysis/generated" / args.version
    build = root / "build" / args.version
    object_root = build / "analysis/generated" / args.version
    asm_objects = object_root / "asm"
    asset_objects = object_root / "assets"
    asm_objects.mkdir(parents=True, exist_ok=True)
    asset_objects.mkdir(parents=True, exist_ok=True)
    generated_linker = (generated / f"podcruise.{args.version}.ld").read_text(
        encoding="utf-8"
    )

    objects: list[Path] = []
    for source in sorted((generated / "asm").glob("*.s")):
        output = asm_objects / f"{source.stem}.o"
        if relative_argument(output, root) not in generated_linker:
            continue
        run(
            [
                tools["as"],
                "-no-pad-sections",
                "-march=vr4300",
                "-mabi=32",
                "-I",
                str(generated / "include"),
                "-o",
                str(output),
                str(source),
            ],
            root,
            tool_env,
        )
        objects.append(output)

    for source in sorted((generated / "assets").glob("*.bin")):
        output = asset_objects / f"{source.stem}.o"
        if relative_argument(output, root) not in generated_linker:
            continue
        run(
            [
                tools["ld"],
                "-r",
                "-b",
                "binary",
                "-o",
                str(output),
                str(source),
            ],
            root,
            tool_env,
        )
        objects.append(output)

    c_function_count = 0
    regional_matching_config = root / f"config/c_matching.{args.version}.json"
    matching_config_path = (
        regional_matching_config
        if regional_matching_config.is_file()
        else root / "config/c_matching.json"
    )
    matching_config = load_matching_config(root, matching_config_path)
    matching_config_argument = matching_config_path.relative_to(root).as_posix()
    for unit in matching_config["units"]:
        c_object = build / Path(unit["source"]).with_suffix(".o")
        relative_c_object = c_object.relative_to(root).as_posix()
        if relative_c_object not in generated_linker:
            continue
        run(
            [
                sys.executable,
                "-m",
                "tools.build_matching_object",
                "--config",
                matching_config_argument,
                "--unit",
                unit["id"],
                "--profile",
                "ido53_o2",
                "--output",
                relative_c_object,
            ],
            root,
            tool_env,
        )
        objects.append(c_object)
        c_function_count += len(unit["functions"])

    elf_path = build / f"podcruise.{args.version}.elf"
    map_path = build / f"podcruise.{args.version}.map"
    rom_path = build / f"podcruise.{args.version}.z64"
    symbol_scripts = [
        generated / "undefined_funcs_auto.txt",
        generated / "undefined_syms_auto.txt",
    ]
    symbol_version = matching_config.get("symbol_version", args.version)
    manual_symbols = root / f"config/{symbol_version}/undefined_syms.manual.txt"
    if manual_symbols.is_file():
        symbol_scripts.append(manual_symbols)
    run(
        [
            tools["ld"],
            "--no-check-sections",
            "--omagic",
            *[
                argument
                for script in symbol_scripts
                for argument in ("-T", str(script))
            ],
            "-T",
            str(generated / f"podcruise.{args.version}.ld"),
            "-Map",
            str(map_path),
            "-o",
            str(elf_path),
            *[relative_argument(path, root) for path in objects],
        ],
        root,
        tool_env,
    )
    run(
        [tools["objcopy"], "-O", "binary", str(elf_path), str(rom_path)],
        root,
        tool_env,
    )

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
        "c_functions_substituted": c_function_count,
        "scope": (
            "hybrid source/assembly round trip"
            if c_function_count
            else "untouched local assembly and opaque binary round trip"
        ),
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
