#!/usr/bin/env python3
"""Record a conservative compiler-family signal from unconditional control flow."""

from __future__ import annotations

import argparse
import json
import struct
from pathlib import Path


def parse_int(value: str) -> int:
    return int(value, 0)


def probe(data: bytes, start: int, end: int) -> dict[str, object]:
    region = data[start:end]
    region = region[: len(region) - (len(region) % 4)]
    words = struct.unpack(f">{len(region) // 4}I", region)
    absolute_jumps = sum(word >> 26 == 0x02 for word in words)
    pseudo_branches = sum(word & 0xFFFF0000 == 0x10000000 for word in words)

    if pseudo_branches >= max(16, absolute_jumps * 8):
        hypothesis = "IDO-family"
        strength = "strong family-level signal"
    elif absolute_jumps >= max(16, pseudo_branches * 8):
        hypothesis = "GCC/KMC-family"
        strength = "strong family-level signal"
    else:
        hypothesis = "undetermined"
        strength = "weak or mixed signal"

    return {
        "absolute_j_instructions": absolute_jumps,
        "beq_zero_zero_pseudo_branches": pseudo_branches,
        "hypothesis": hypothesis,
        "strength": strength,
    }


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--rom", type=Path, required=True)
    parser.add_argument("--code-start", type=parse_int, required=True)
    parser.add_argument("--code-end", type=parse_int, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()

    result = {
        "schema": 1,
        "rom": args.rom.as_posix(),
        "scan_start": f"0x{args.code_start:X}",
        "scan_end": f"0x{args.code_end:X}",
        **probe(args.rom.read_bytes(), args.code_start, args.code_end),
        "interpretation": (
            "IDO conventionally lowers an unconditional local branch to the "
            "beq $zero,$zero pseudo-instruction, whereas GCC/KMC commonly emits j."
        ),
        "warning": (
            "This identifies a likely compiler family only. It does not identify "
            "the compiler release, optimization flags, or per-library toolchain."
        ),
    }
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    print(
        f"compiler hypothesis: {result['hypothesis']} "
        f"(pseudo-b={result['beq_zero_zero_pseudo_branches']}, "
        f"j={result['absolute_j_instructions']})"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
