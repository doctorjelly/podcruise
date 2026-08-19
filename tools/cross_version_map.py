#!/usr/bin/env python3
"""Map function candidates between region builds using normalized MIPS windows."""

from __future__ import annotations

import argparse
import csv
import json
import struct
from collections import Counter
from pathlib import Path


def parse_int(value: str) -> int:
    return int(value, 0)


def normalize_instruction(word: int) -> int:
    """Remove operands likely to change after relocation while retaining shape."""
    opcode = word >> 26
    if opcode == 0:
        # R-type: preserve opcode, shift amount, and function; discard registers.
        return (word & 0x000007C0) | (word & 0x3F)
    if opcode in (2, 3):
        # Absolute jump/call: preserve only opcode.
        return opcode << 26
    if opcode in (16, 17, 18, 19):
        # Coprocessor instructions have useful format/function bits and no
        # ordinary relocation immediate in most forms.
        return word
    # I-type: preserve opcode and register roles, discard the immediate.
    return word & 0xFFFF0000


def normalized_words(data: bytes, start: int, end: int) -> list[int]:
    end = min(end, len(data))
    end -= (end - start) % 4
    words = struct.unpack(f">{(end - start) // 4}I", data[start:end])
    return [normalize_instruction(word) for word in words]


def window_key(words: list[int], index: int, length: int) -> bytes:
    return struct.pack(f">{length}I", *words[index : index + length])


def unique_window_index(words: list[int], length: int) -> dict[bytes, int | None]:
    result: dict[bytes, int | None] = {}
    for index in range(0, len(words) - length + 1):
        key = window_key(words, index, length)
        if key in result:
            result[key] = None
        else:
            result[key] = index
    return result


def load_candidates(path: Path) -> list[dict[str, str]]:
    with path.open(encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle))


def parse_target(value: str) -> tuple[str, Path]:
    if "=" not in value:
        raise argparse.ArgumentTypeError("target must be ID=PATH")
    target_id, path = value.split("=", 1)
    return target_id, Path(path)


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--source-rom", type=Path, required=True)
    parser.add_argument("--source-functions", type=Path, required=True)
    parser.add_argument("--target", type=parse_target, action="append", required=True)
    parser.add_argument("--scan-start", type=parse_int, required=True)
    parser.add_argument("--scan-end", type=parse_int, required=True)
    parser.add_argument("--window", type=int, default=32)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--summary", type=Path, required=True)
    args = parser.parse_args()

    if args.window < 4:
        raise SystemExit("window must contain at least four instructions")

    source_data = args.source_rom.read_bytes()
    source_words = normalized_words(source_data, args.scan_start, args.scan_end)
    candidates = load_candidates(args.source_functions)
    output_rows: list[dict[str, str | int]] = []
    summaries: dict[str, object] = {}

    for target_id, target_path in args.target:
        target_data = target_path.read_bytes()
        target_words = normalized_words(target_data, args.scan_start, args.scan_end)
        target_index = unique_window_index(target_words, args.window)
        matched = 0
        ambiguous_or_missing = 0
        deltas: Counter[int] = Counter()

        for candidate in candidates:
            source_offset = int(candidate["rom"], 0)
            source_index = (source_offset - args.scan_start) // 4
            row: dict[str, str | int] = {
                "source_name": candidate["name"],
                "source_vram": candidate["vram"],
                "source_rom": candidate["rom"],
                "target": target_id,
                "window_instructions": args.window,
            }
            if source_index < 0 or source_index + args.window > len(source_words):
                row.update(status="source_out_of_range", target_rom="", target_vram="", delta_bytes="")
                ambiguous_or_missing += 1
            else:
                key = window_key(source_words, source_index, args.window)
                target_word_index = target_index.get(key)
                if target_word_index is None:
                    row.update(status="not_unique_or_missing", target_rom="", target_vram="", delta_bytes="")
                    ambiguous_or_missing += 1
                else:
                    target_offset = args.scan_start + target_word_index * 4
                    target_vram = 0x80000400 + (target_offset - 0x1000)
                    delta = target_offset - source_offset
                    row.update(
                        status="unique_match",
                        target_rom=f"0x{target_offset:06X}",
                        target_vram=f"0x{target_vram:08X}",
                        delta_bytes=delta,
                    )
                    matched += 1
                    deltas[delta] += 1
            output_rows.append(row)

        summaries[target_id] = {
            "target_rom": target_path.as_posix(),
            "candidate_count": len(candidates),
            "unique_matches": matched,
            "unique_match_percent": round(100.0 * matched / len(candidates), 2),
            "not_unique_or_missing": ambiguous_or_missing,
            "distinct_deltas": len(deltas),
            "most_common_deltas": [
                {"delta_bytes": delta, "count": count}
                for delta, count in deltas.most_common(12)
            ],
        }
        print(
            f"{target_id}: {matched:,}/{len(candidates):,} unique "
            f"({100.0 * matched / len(candidates):.2f}%), {len(deltas)} relocation deltas"
        )

    args.output.parent.mkdir(parents=True, exist_ok=True)
    fieldnames = [
        "source_name",
        "source_vram",
        "source_rom",
        "target",
        "status",
        "target_rom",
        "target_vram",
        "delta_bytes",
        "window_instructions",
    ]
    with args.output.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=fieldnames, lineterminator="\n")
        writer.writeheader()
        writer.writerows(output_rows)

    summary = {
        "schema": 1,
        "method": "unique 32-bit MIPS instruction-shape windows with relocation-sensitive operands removed",
        "scan_start": f"0x{args.scan_start:X}",
        "scan_end": f"0x{args.scan_end:X}",
        "window_instructions": args.window,
        "targets": summaries,
        "warning": "A structural match is boundary evidence, not proof of semantic identity.",
    }
    args.summary.write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
