#!/usr/bin/env python3
"""Record byte hashes—not bytes—for the first reviewed behavior candidates."""

from __future__ import annotations

import argparse
import csv
import hashlib
import json
from pathlib import Path


FUNCTIONS = (
    {"name": "func_80000520", "vram": 0x80000520, "rom": 0x1120, "size": 12},
    {"name": "func_8000052C", "vram": 0x8000052C, "rom": 0x112C, "size": 12},
    {"name": "func_80000538", "vram": 0x80000538, "rom": 0x1138, "size": 12},
)


def slice_sha256(path: Path, offset: int, size: int) -> str:
    with path.open("rb") as handle:
        handle.seek(offset)
        data = handle.read(size)
    if len(data) != size:
        raise ValueError(f"short read from {path} at 0x{offset:X}")
    return hashlib.sha256(data).hexdigest()


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--versions", type=Path, required=True)
    parser.add_argument("--mappings", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()

    root = args.versions.resolve().parent.parent
    versions = json.loads(args.versions.read_text(encoding="utf-8"))["versions"]
    retail = {item["id"]: item for item in versions if item["id"] in {"us", "jp", "eu"}}

    target_offsets: dict[tuple[str, str], int] = {}
    with args.mappings.open(encoding="utf-8", newline="") as handle:
        for row in csv.DictReader(handle):
            if row["status"] == "unique_match":
                target_offsets[(row["source_name"], row["target"])] = int(row["target_rom"], 0)

    records = []
    for function in FUNCTIONS:
        builds = {}
        for version_id in ("us", "jp", "eu"):
            offset = (
                function["rom"]
                if version_id == "us"
                else target_offsets[(function["name"], version_id)]
            )
            path = root / retail[version_id]["path"]
            builds[version_id] = {
                "rom": f"0x{offset:06X}",
                "sha256": slice_sha256(path, offset, function["size"]),
            }
        hashes = {build["sha256"] for build in builds.values()}
        records.append(
            {
                "name": function["name"],
                "us_vram": f"0x{function['vram']:08X}",
                "size_bytes": function["size"],
                "builds": builds,
                "identical_bytes_in_all_retail_builds": len(hashes) == 1,
                "status": "behavior_recovered_match_unverified",
            }
        )

    output = {
        "schema": 1,
        "functions": records,
        "recovered_behavior_bytes": sum(item["size_bytes"] for item in records),
        "matching_c_bytes": 0,
        "warning": "Byte identity across ROMs is evidence of shared code, not proof that candidate C matches.",
    }
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(output, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    for record in records:
        print(
            f"{record['name']}: {record['size_bytes']} bytes, "
            f"all-retail-identical={record['identical_bytes_in_all_retail_builds']}"
        )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
