#!/usr/bin/env python3
"""Find conservative MIPS function candidates without importing symbol files."""

from __future__ import annotations

import argparse
import csv
import json
import struct
from collections import defaultdict
from pathlib import Path


JR_RA = 0x03E00008
VALID_PRIMARY_OPCODES = {
    0x00,
    0x01,
    0x02,
    0x03,
    0x04,
    0x05,
    0x06,
    0x07,
    0x08,
    0x09,
    0x0A,
    0x0B,
    0x0C,
    0x0D,
    0x0E,
    0x0F,
    0x10,
    0x11,
    0x12,
    0x14,
    0x15,
    0x16,
    0x17,
    0x18,
    0x19,
    0x1A,
    0x1B,
    0x20,
    0x21,
    0x22,
    0x23,
    0x24,
    0x25,
    0x26,
    0x27,
    0x28,
    0x29,
    0x2A,
    0x2B,
    0x2C,
    0x2D,
    0x2E,
    0x2F,
    0x30,
    0x31,
    0x32,
    0x34,
    0x35,
    0x36,
    0x37,
    0x38,
    0x39,
    0x3A,
    0x3C,
    0x3D,
    0x3E,
    0x3F,
}


def parse_int(value: str) -> int:
    return int(value, 0)


def sign16(value: int) -> int:
    return value - 0x10000 if value & 0x8000 else value


def jal_target(word: int, pc: int) -> int | None:
    if word >> 26 != 0x03:
        return None
    return ((pc + 4) & 0xF0000000) | ((word & 0x03FFFFFF) << 2)


def has_nonleaf_prologue(words: list[int], index: int) -> bool:
    word = words[index]
    if word & 0xFFFF0000 != 0x27BD0000 or sign16(word & 0xFFFF) >= 0:
        return False
    for candidate in words[index + 1 : index + 9]:
        if candidate & 0xFFFF0000 == 0xAFBF0000:
            return True
    return False


def has_valid_primary_opcode(word: int) -> bool:
    return word >> 26 in VALID_PRIMARY_OPCODES


def post_return_candidate(words: list[int], return_index: int) -> int | None:
    """Find a plausible start after `jr ra` and its executed delay slot."""
    index = return_index + 2
    # Compilers/linkers often align the next function with zero words. A small
    # cap avoids walking through a large zero-filled data region.
    skipped = 0
    while index < len(words) and words[index] == 0 and skipped < 8:
        index += 1
        skipped += 1
    if index >= len(words) or words[index] == 0:
        return None
    sample = words[index : index + 4]
    if len(sample) < 2:
        return None
    if not has_valid_primary_opcode(sample[0]):
        return None
    # Require the neighborhood to look instruction-like. Zero is a valid MIPS
    # nop, so count it as plausible after the nonzero first word.
    plausible = sum(word == 0 or has_valid_primary_opcode(word) for word in sample)
    return index if plausible >= 3 else None


def instruction_word(data: bytes, offset: int) -> int:
    return struct.unpack_from(">I", data, offset)[0]


def confidence(evidence: set[str]) -> str:
    if "entry" in evidence or {"jal_target", "prologue"}.issubset(evidence):
        return "high"
    if "jal_target" in evidence or "prologue" in evidence:
        return "medium"
    return "low"


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--rom", type=Path, required=True)
    parser.add_argument("--code-start", type=parse_int, required=True)
    parser.add_argument("--code-end", type=parse_int, required=True)
    parser.add_argument("--vram-start", type=parse_int, required=True)
    parser.add_argument("--csv", type=Path, required=True)
    parser.add_argument("--symbols", type=Path, required=True)
    parser.add_argument("--summary", type=Path, required=True)
    args = parser.parse_args()

    rom = args.rom.read_bytes()
    if args.code_start % 4 or args.code_end % 4:
        raise SystemExit("code range must be word-aligned")
    if args.code_end > len(rom) or args.code_start >= args.code_end:
        raise SystemExit("invalid code range")

    code = rom[args.code_start : args.code_end]
    words = list(struct.unpack(f">{len(code) // 4}I", code))
    vram_end = args.vram_start + len(code)
    evidence: dict[int, set[str]] = defaultdict(set)
    call_counts: dict[int, int] = defaultdict(int)
    evidence[args.vram_start].add("entry")

    for index, word in enumerate(words):
        rom_offset = args.code_start + index * 4
        pc = args.vram_start + (rom_offset - args.code_start)
        target = jal_target(word, pc)
        if target is not None and args.vram_start <= target < vram_end and target % 4 == 0:
            evidence[target].add("jal_target")
            call_counts[target] += 1
        if has_nonleaf_prologue(words, index):
            evidence[pc].add("prologue")
        if word == JR_RA:
            candidate_index = post_return_candidate(words, index)
            if candidate_index is not None:
                candidate_pc = args.vram_start + candidate_index * 4
                evidence[candidate_pc].add("post_return")

    # Function pointers embedded anywhere in the ROM strengthen candidates but
    # do not create boundaries on their own; arbitrary data can resemble a VRAM
    # address too easily.
    pointer_counts: dict[int, int] = defaultdict(int)
    for offset in range(0, len(rom) - 3, 4):
        value = instruction_word(rom, offset)
        if value in evidence:
            pointer_counts[value] += 1

    addresses = sorted(evidence)
    rows: list[dict[str, str | int]] = []
    for index, address in enumerate(addresses):
        rom_offset = args.code_start + (address - args.vram_start)
        next_address = addresses[index + 1] if index + 1 < len(addresses) else vram_end
        row = {
            "name": f"func_{address:08X}",
            "vram": f"0x{address:08X}",
            "rom": f"0x{rom_offset:06X}",
            "candidate_size": next_address - address,
            "confidence": confidence(evidence[address]),
            "evidence": "+".join(sorted(evidence[address])),
            "jal_calls": call_counts[address],
            "aligned_pointer_words": pointer_counts[address],
        }
        rows.append(row)

    args.csv.parent.mkdir(parents=True, exist_ok=True)
    with args.csv.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=list(rows[0]), lineterminator="\n")
        writer.writeheader()
        writer.writerows(rows)

    args.symbols.parent.mkdir(parents=True, exist_ok=True)
    with args.symbols.open("w", encoding="utf-8", newline="\n") as handle:
        handle.write("// Auto-derived by tools/analyze_mips.py; verify every boundary.\n")
        for row in rows:
            handle.write(f"{row['name']} = {row['vram']}; // type:func\n")

    by_confidence = defaultdict(int)
    by_evidence = defaultdict(int)
    for address in addresses:
        by_confidence[confidence(evidence[address])] += 1
        by_evidence["+".join(sorted(evidence[address]))] += 1

    summary = {
        "schema": 1,
        "rom": args.rom.as_posix(),
        "code_start": f"0x{args.code_start:X}",
        "code_end": f"0x{args.code_end:X}",
        "code_size_bytes": len(code),
        "vram_start": f"0x{args.vram_start:08X}",
        "vram_end": f"0x{vram_end:08X}",
        "candidate_count": len(rows),
        "by_confidence": dict(sorted(by_confidence.items())),
        "by_evidence": dict(sorted(by_evidence.items())),
        "method": [
            "ROM entry point",
            "in-range direct jal targets",
            "addiu sp,sp,-N followed by sw ra,N(sp) prologues",
            "plausible instruction starts following jr ra and its delay slot",
        ],
        "warning": "Candidates are evidence, not authoritative function boundaries.",
    }
    args.summary.write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8")

    print(f"code: 0x{args.code_start:X}-0x{args.code_end:X} ({len(code):,} bytes)")
    print(f"function candidates: {len(rows):,}")
    print("confidence: " + ", ".join(f"{key}={value}" for key, value in sorted(by_confidence.items())))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
