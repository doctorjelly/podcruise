#!/usr/bin/env python3
"""Validate local N64 ROMs and emit a deterministic, metadata-only inventory."""

from __future__ import annotations

import argparse
import binascii
import hashlib
import json
import re
import sys
from collections import defaultdict
from pathlib import Path
from typing import Any


Z64_MAGIC = bytes.fromhex("80371240")
REGION_NAMES = {
    "A": "Asia",
    "D": "Germany",
    "E": "USA",
    "F": "France",
    "I": "Italy",
    "J": "Japan",
    "P": "Europe",
    "S": "Spain",
    "U": "Australia",
}
BUILD_RE = re.compile(rb"v\d{2}[A-Za-z]{3}\d{2}\.\d{4}")


def _hashes(path: Path) -> dict[str, str]:
    md5 = hashlib.md5(usedforsecurity=False)
    sha1 = hashlib.sha1(usedforsecurity=False)
    sha256 = hashlib.sha256()
    crc = 0
    with path.open("rb") as handle:
        while chunk := handle.read(1024 * 1024):
            md5.update(chunk)
            sha1.update(chunk)
            sha256.update(chunk)
            crc = binascii.crc32(chunk, crc)
    return {
        "crc32": f"{crc & 0xFFFFFFFF:08x}",
        "md5": md5.hexdigest(),
        "sha1": sha1.hexdigest(),
        "sha256": sha256.hexdigest(),
    }


def inspect_rom(path: Path) -> dict[str, Any]:
    size = path.stat().st_size
    with path.open("rb") as handle:
        header = handle.read(0x40)
        handle.seek(0)
        data = handle.read()

    if len(header) != 0x40:
        raise ValueError(f"{path}: file is too short for an N64 header")

    magic = header[:4]
    byte_order = "z64 (big-endian)" if magic == Z64_MAGIC else "unknown"
    game_code = header[0x3B:0x3F].decode("ascii", errors="replace")
    region_code = chr(header[0x3E]) if 0x20 <= header[0x3E] < 0x7F else "?"
    build_stamps = sorted({item.decode("ascii") for item in BUILD_RE.findall(data)})

    result: dict[str, Any] = {
        "size_bytes": size,
        "byte_order": byte_order,
        "header": {
            "magic": magic.hex(),
            "clock_rate": f"0x{int.from_bytes(header[4:8], 'big'):08x}",
            "entry_point": f"0x{int.from_bytes(header[8:12], 'big'):08x}",
            "release": f"0x{int.from_bytes(header[12:16], 'big'):08x}",
            "crc1": f"{int.from_bytes(header[16:20], 'big'):08x}",
            "crc2": f"{int.from_bytes(header[20:24], 'big'):08x}",
            "title": header[0x20:0x34].decode("ascii", errors="replace").rstrip(" \0"),
            "game_code": game_code,
            "region_code": region_code,
            "region": REGION_NAMES.get(region_code, "Unknown"),
            "revision": header[0x3F],
        },
        "build_stamps": build_stamps,
    }
    result.update(_hashes(path))
    return result


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--config", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--check", action="store_true", help="fail on a missing file or hash mismatch")
    args = parser.parse_args()

    config_path = args.config.resolve()
    repo_root = config_path.parent.parent
    config = json.loads(config_path.read_text(encoding="utf-8"))
    records: list[dict[str, Any]] = []
    failures: list[str] = []

    for version in config["versions"]:
        path = repo_root / version["path"]
        if not path.is_file():
            failures.append(f"{version['id']}: missing {version['path']}")
            continue
        record = {
            "id": version["id"],
            "label": version["label"],
            "path": version["path"],
            "role": version["role"],
        }
        record.update(inspect_rom(path))
        for algorithm in ("sha1", "sha256"):
            expected = version[f"expected_{algorithm}"].lower()
            if record[algorithm] != expected:
                failures.append(
                    f"{version['id']}: {algorithm} mismatch "
                    f"(expected {expected}, got {record[algorithm]})"
                )
        if record["byte_order"] != "z64 (big-endian)":
            failures.append(f"{version['id']}: unsupported byte order {record['byte_order']}")
        records.append(record)

    duplicate_groups: list[dict[str, Any]] = []
    by_sha256: dict[str, list[str]] = defaultdict(list)
    for record in records:
        by_sha256[record["sha256"]].append(record["id"])
    for digest, ids in sorted(by_sha256.items()):
        if len(ids) > 1:
            duplicate_groups.append({"sha256": digest, "ids": ids})

    output = {
        "schema": 1,
        "rom_count": len(records),
        "unique_rom_count": len(by_sha256),
        "duplicate_groups": duplicate_groups,
        "roms": records,
    }
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(output, indent=2, sort_keys=True) + "\n", encoding="utf-8")

    print("id                    game  rev  crc32     sha1                                      build")
    for record in records:
        build = ",".join(record["build_stamps"]) or "-"
        print(
            f"{record['id']:<21} "
            f"{record['header']['game_code']:<4}  "
            f"{record['header']['revision']:>3}  "
            f"{record['crc32']}  {record['sha1']}  {build}"
        )
    if duplicate_groups:
        print("duplicate groups:")
        for group in duplicate_groups:
            print(f"  {', '.join(group['ids'])}: {group['sha256']}")

    if failures:
        for failure in failures:
            print(f"ERROR: {failure}", file=sys.stderr)
        return 1 if args.check else 0
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
