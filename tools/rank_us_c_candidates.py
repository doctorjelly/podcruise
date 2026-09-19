#!/usr/bin/env python3
"""Rank current, unaudited USA matching-C misses by linked instruction words.

Uses the accepted compiler ledger and its retained linked objects. Stale source,
configuration, or object bytes are excluded rather than ranked as evidence.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import struct
from pathlib import Path


ROOT = Path(__file__).resolve().parent.parent


def digest(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--limit", type=int, default=20)
    parser.add_argument("--include-audited", action="store_true")
    args = parser.parse_args()

    config = json.loads((ROOT / "config/c_matching.json").read_text())
    report = json.loads((ROOT / "analysis/c_matches.us.json").read_text())
    config_hash = digest(json.dumps(
        config, sort_keys=True, separators=(",", ":")
    ).encode())
    if config_hash != report["config_sha256"]:
        parser.error("USA matching report has a stale configuration")

    profile_id = config["accepted_profile"]
    profile = next(p for p in report["profiles"] if p["profile"] == profile_id)
    rom = (ROOT / config["rom"]).read_bytes()
    logged = (ROOT / "docs/function_token_log.tsv").read_text()
    units = {
        function["name"]: (unit, function)
        for unit in config["units"]
        for function in unit["functions"]
    }
    rows = []
    stale = 0
    for result in profile["functions"]:
        name = result["name"]
        size = result.get("actual_size")
        target_size = result.get("expected_size")
        if result.get("verified_match") or size is None or target_size is None:
            continue
        if not args.include_audited and (
            name in logged
            or (ROOT / f"specs/functions/recovered/{name}.md").exists()
        ):
            continue
        unit, function = units[name]
        source = ROOT / unit["source"]
        if not source.is_file() or digest(source.read_bytes()) != result["source_sha256"]:
            stale += 1
            continue
        object_text = (
            ROOT / "build/c-matches/us" / profile_id / unit["id"]
            / f"{unit['id']}.text.bin"
        )
        if not object_text.is_file():
            stale += 1
            continue
        offset = int(result["actual_vram"], 16) - int(unit["link_vram"], 16)
        actual = object_text.read_bytes()[offset : offset + size]
        expected_offset = int(function["rom"], 16)
        expected = rom[expected_offset : expected_offset + target_size]
        if digest(actual) != result["actual_sha256"] or len(expected) != target_size:
            stale += 1
            continue
        words = sum(
            left != right
            for left, right in zip(
                struct.iter_unpack(">I", expected),
                struct.iter_unpack(">I", actual),
            )
        )
        size_words = abs(size - target_size) // 4
        rows.append((words + size_words, words, name, target_size, size,
                     result["first_difference"]))

    print("name\tROM/C bytes\tdifferent words\tsize words\tfirst byte")
    for _, words, name, target_size, size, first in sorted(rows)[:args.limit]:
        print(f"{name}\t{target_size}/{size}\t{words}\t"
              f"{abs(size - target_size) // 4}\t{first}")
    print(f"ranked={len(rows)} stale_skipped={stale}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
