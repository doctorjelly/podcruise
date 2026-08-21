#!/usr/bin/env python3
"""Record byte hashes—not bytes—for reviewed behavior candidates."""

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
    {"name": "func_80005AFC", "vram": 0x80005AFC, "rom": 0x66FC, "size": 32},
    {"name": "func_80005B1C", "vram": 0x80005B1C, "rom": 0x671C, "size": 40},
    {"name": "func_80005B44", "vram": 0x80005B44, "rom": 0x6744, "size": 52},
    {"name": "func_80005B80", "vram": 0x80005B80, "rom": 0x6780, "size": 56},
    {"name": "func_80006E50", "vram": 0x80006E50, "rom": 0x7A50, "size": 16},
    {"name": "func_80006E60", "vram": 0x80006E60, "rom": 0x7A60, "size": 20},
    {"name": "func_80006EB4", "vram": 0x80006EB4, "rom": 0x7AB4, "size": 12},
    {"name": "func_80006F28", "vram": 0x80006F28, "rom": 0x7B28, "size": 12},
    {"name": "func_80006FD4", "vram": 0x80006FD4, "rom": 0x7BD4, "size": 8},
    {"name": "func_80006FDC", "vram": 0x80006FDC, "rom": 0x7BDC, "size": 8},
    {"name": "func_80008530", "vram": 0x80008530, "rom": 0x9130, "size": 8},
    {"name": "func_80008540", "vram": 0x80008540, "rom": 0x9140, "size": 8},
    {"name": "func_8000C530", "vram": 0x8000C530, "rom": 0xD130, "size": 8},
    {"name": "func_80033DC4", "vram": 0x80033DC4, "rom": 0x349C4, "size": 8},
    {"name": "func_80008610", "vram": 0x80008610, "rom": 0x9210, "size": 32},
    {"name": "func_800086F8", "vram": 0x800086F8, "rom": 0x92F8, "size": 32},
    {"name": "func_80008750", "vram": 0x80008750, "rom": 0x9350, "size": 16},
    {"name": "func_80008F58", "vram": 0x80008F58, "rom": 0x9B58, "size": 20},
    {"name": "func_80009524", "vram": 0x80009524, "rom": 0xA124, "size": 24},
    {"name": "func_8000953C", "vram": 0x8000953C, "rom": 0xA13C, "size": 32},
    {"name": "func_8000955C", "vram": 0x8000955C, "rom": 0xA15C, "size": 36},
    {"name": "func_8000AC90", "vram": 0x8000AC90, "rom": 0xB890, "size": 40},
    {"name": "func_80011764", "vram": 0x80011764, "rom": 0x12364, "size": 20},
    {"name": "func_800117E4", "vram": 0x800117E4, "rom": 0x123E4, "size": 12},
    {"name": "func_800117F0", "vram": 0x800117F0, "rom": 0x123F0, "size": 36},
    {"name": "func_80011814", "vram": 0x80011814, "rom": 0x12414, "size": 16},
    {"name": "func_80011824", "vram": 0x80011824, "rom": 0x12424, "size": 20},
    {"name": "func_800118F8", "vram": 0x800118F8, "rom": 0x124F8, "size": 32},
    {"name": "func_80011918", "vram": 0x80011918, "rom": 0x12518, "size": 16},
    {"name": "func_80011928", "vram": 0x80011928, "rom": 0x12528, "size": 12},
    {"name": "func_80011EA4", "vram": 0x80011EA4, "rom": 0x12AA4, "size": 40},
    {"name": "func_80011ECC", "vram": 0x80011ECC, "rom": 0x12ACC, "size": 28},
    {"name": "func_80011EE8", "vram": 0x80011EE8, "rom": 0x12AE8, "size": 28},
    {"name": "func_80014D20", "vram": 0x80014D20, "rom": 0x15920, "size": 44},
    {"name": "func_80014F2C", "vram": 0x80014F2C, "rom": 0x15B2C, "size": 40},
    {"name": "func_8001514C", "vram": 0x8001514C, "rom": 0x15D4C, "size": 36},
    {"name": "func_80015170", "vram": 0x80015170, "rom": 0x15D70, "size": 32},
    {"name": "func_80015190", "vram": 0x80015190, "rom": 0x15D90, "size": 48},
    {"name": "func_800151C0", "vram": 0x800151C0, "rom": 0x15DC0, "size": 32},
    {"name": "func_80015268", "vram": 0x80015268, "rom": 0x15E68, "size": 32},
    {"name": "func_80015288", "vram": 0x80015288, "rom": 0x15E88, "size": 28},
    {"name": "func_80015328", "vram": 0x80015328, "rom": 0x15F28, "size": 52},
    {"name": "func_8001535C", "vram": 0x8001535C, "rom": 0x15F5C, "size": 52},
    {"name": "func_80015390", "vram": 0x80015390, "rom": 0x15F90, "size": 48},
    {"name": "func_800153C0", "vram": 0x800153C0, "rom": 0x15FC0, "size": 44},
    {"name": "func_800153EC", "vram": 0x800153EC, "rom": 0x15FEC, "size": 60},
    {"name": "func_800155C0", "vram": 0x800155C0, "rom": 0x161C0, "size": 44},
    {"name": "func_800155EC", "vram": 0x800155EC, "rom": 0x161EC, "size": 68},
    {"name": "func_80015694", "vram": 0x80015694, "rom": 0x16294, "size": 36},
    {"name": "func_800156B8", "vram": 0x800156B8, "rom": 0x162B8, "size": 36},
    {"name": "func_800156DC", "vram": 0x800156DC, "rom": 0x162DC, "size": 72},
    {"name": "func_80017D48", "vram": 0x80017D48, "rom": 0x18948, "size": 8},
    {"name": "func_80017D58", "vram": 0x80017D58, "rom": 0x18958, "size": 40},
    {"name": "func_80017DA4", "vram": 0x80017DA4, "rom": 0x189A4, "size": 8},
    {"name": "func_80017DAC", "vram": 0x80017DAC, "rom": 0x189AC, "size": 8},
    {"name": "func_80017DB4", "vram": 0x80017DB4, "rom": 0x189B4, "size": 40},
    {"name": "func_80017DDC", "vram": 0x80017DDC, "rom": 0x189DC, "size": 8},
    {"name": "func_80017DE4", "vram": 0x80017DE4, "rom": 0x189E4, "size": 8},
    {"name": "func_80017DEC", "vram": 0x80017DEC, "rom": 0x189EC, "size": 8},
    {"name": "func_80017DF4", "vram": 0x80017DF4, "rom": 0x189F4, "size": 44},
    {"name": "func_80017E20", "vram": 0x80017E20, "rom": 0x18A20, "size": 52},
    {"name": "func_80017E54", "vram": 0x80017E54, "rom": 0x18A54, "size": 8},
    {"name": "func_80017E5C", "vram": 0x80017E5C, "rom": 0x18A5C, "size": 20},
    {"name": "func_80017E70", "vram": 0x80017E70, "rom": 0x18A70, "size": 24},
    {"name": "func_80017E88", "vram": 0x80017E88, "rom": 0x18A88, "size": 84},
    {"name": "func_80017EDC", "vram": 0x80017EDC, "rom": 0x18ADC, "size": 8},
    {"name": "func_80017EE4", "vram": 0x80017EE4, "rom": 0x18AE4, "size": 8},
    {"name": "func_80017EEC", "vram": 0x80017EEC, "rom": 0x18AEC, "size": 8},
    {"name": "func_80017EF4", "vram": 0x80017EF4, "rom": 0x18AF4, "size": 8},
    {"name": "func_80017EFC", "vram": 0x80017EFC, "rom": 0x18AFC, "size": 16},
    {"name": "func_80017F0C", "vram": 0x80017F0C, "rom": 0x18B0C, "size": 20},
    {"name": "func_80017F20", "vram": 0x80017F20, "rom": 0x18B20, "size": 8},
    {"name": "func_80017F28", "vram": 0x80017F28, "rom": 0x18B28, "size": 60},
    {"name": "func_80018084", "vram": 0x80018084, "rom": 0x18C84, "size": 68},
    {"name": "func_800180C8", "vram": 0x800180C8, "rom": 0x18CC8, "size": 76},
    {"name": "func_80018114", "vram": 0x80018114, "rom": 0x18D14, "size": 8},
    {"name": "func_8001811C", "vram": 0x8001811C, "rom": 0x18D1C, "size": 72},
    {"name": "func_80018164", "vram": 0x80018164, "rom": 0x18D64, "size": 88},
    {"name": "func_800182FC", "vram": 0x800182FC, "rom": 0x18EFC, "size": 40},
    {"name": "func_80018324", "vram": 0x80018324, "rom": 0x18F24, "size": 132},
    {"name": "func_800183A8", "vram": 0x800183A8, "rom": 0x18FA8, "size": 8},
    {"name": "func_800183B0", "vram": 0x800183B0, "rom": 0x18FB0, "size": 8},
    {"name": "func_800183C0", "vram": 0x800183C0, "rom": 0x18FC0, "size": 120},
    {"name": "func_80018440", "vram": 0x80018440, "rom": 0x19040, "size": 8},
    {"name": "func_80018448", "vram": 0x80018448, "rom": 0x19048, "size": 8},
    {"name": "func_80018450", "vram": 0x80018450, "rom": 0x19050, "size": 12},
    {"name": "func_80018470", "vram": 0x80018470, "rom": 0x19070, "size": 16},
    {"name": "func_8002DFB0", "vram": 0x8002DFB0, "rom": 0x2EBB0, "size": 12},
    {"name": "func_8002E028", "vram": 0x8002E028, "rom": 0x2EC28, "size": 12},
    {"name": "func_8002E0A8", "vram": 0x8002E0A8, "rom": 0x2ECA8, "size": 12},
    {"name": "func_8002F054", "vram": 0x8002F054, "rom": 0x2FC54, "size": 12},
    {"name": "func_8002F060", "vram": 0x8002F060, "rom": 0x2FC60, "size": 12},
    {"name": "func_8002F1CC", "vram": 0x8002F1CC, "rom": 0x2FDCC, "size": 24},
    {"name": "func_8002F1E4", "vram": 0x8002F1E4, "rom": 0x2FDE4, "size": 8},
    {"name": "func_8002FB18", "vram": 0x8002FB18, "rom": 0x30718, "size": 52},
    {"name": "func_8002FC58", "vram": 0x8002FC58, "rom": 0x30858, "size": 40},
    {"name": "func_8002FDBC", "vram": 0x8002FDBC, "rom": 0x309BC, "size": 60},
    {"name": "func_80030154", "vram": 0x80030154, "rom": 0x30D54, "size": 32},
    {"name": "func_80030274", "vram": 0x80030274, "rom": 0x30E74, "size": 36},
    {"name": "func_80030304", "vram": 0x80030304, "rom": 0x30F04, "size": 36},
    {"name": "func_80031924", "vram": 0x80031924, "rom": 0x32524, "size": 32},
    {"name": "func_800319CC", "vram": 0x800319CC, "rom": 0x325CC, "size": 40},
    {"name": "func_80031BEC", "vram": 0x80031BEC, "rom": 0x327EC, "size": 24},
    {"name": "func_80031F94", "vram": 0x80031F94, "rom": 0x32B94, "size": 16},
    {"name": "func_800390A4", "vram": 0x800390A4, "rom": 0x39CA4, "size": 8},
    {"name": "func_8003931C", "vram": 0x8003931C, "rom": 0x39F1C, "size": 36},
    {"name": "func_80039890", "vram": 0x80039890, "rom": 0x3A490, "size": 40},
    {"name": "func_8003F974", "vram": 0x8003F974, "rom": 0x40574, "size": 40},
    {"name": "func_8003D488", "vram": 0x8003D488, "rom": 0x3E088, "size": 20},
    {"name": "func_8005D310", "vram": 0x8005D310, "rom": 0x5DF10, "size": 20},
    {"name": "func_8005EEFC", "vram": 0x8005EEFC, "rom": 0x5FAFC, "size": 12},
    {"name": "func_80065804", "vram": 0x80065804, "rom": 0x66404, "size": 12},
    {"name": "func_80065C50", "vram": 0x80065C50, "rom": 0x66850, "size": 36},
    {"name": "func_80065C74", "vram": 0x80065C74, "rom": 0x66874, "size": 36},
    {"name": "func_80073708", "vram": 0x80073708, "rom": 0x74308, "size": 12},
    {"name": "func_8007EE40", "vram": 0x8007EE40, "rom": 0x7FA40, "size": 12},
    {"name": "func_8007F22C", "vram": 0x8007F22C, "rom": 0x7FE2C, "size": 16},
    {"name": "func_8007F23C", "vram": 0x8007F23C, "rom": 0x7FE3C, "size": 16},
    {"name": "func_80080350", "vram": 0x80080350, "rom": 0x80F50, "size": 12},
    {"name": "func_800827C0", "vram": 0x800827C0, "rom": 0x833C0, "size": 8},
    {"name": "func_800834DC", "vram": 0x800834DC, "rom": 0x840DC, "size": 20},
    {"name": "func_800811C0", "vram": 0x800811C0, "rom": 0x81DC0, "size": 12},
    {"name": "func_800811CC", "vram": 0x800811CC, "rom": 0x81DCC, "size": 16},
    {"name": "func_80081260", "vram": 0x80081260, "rom": 0x81E60, "size": 12},
    {"name": "func_80086CA0", "vram": 0x80086CA0, "rom": 0x878A0, "size": 40},
    {"name": "func_80086CC8", "vram": 0x80086CC8, "rom": 0x878C8, "size": 24},
    {"name": "func_8008B190", "vram": 0x8008B190, "rom": 0x8BD90, "size": 32},
    {"name": "func_80090634", "vram": 0x80090634, "rom": 0x91234, "size": 44},
    {"name": "func_80093864", "vram": 0x80093864, "rom": 0x94464, "size": 44},
    {"name": "func_8008D274", "vram": 0x8008D274, "rom": 0x8DE74, "size": 16},
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
    parser.add_argument("--matches", type=Path)
    parser.add_argument("--match-profile")
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()

    root = args.versions.resolve().parent.parent
    versions = json.loads(args.versions.read_text(encoding="utf-8"))["versions"]
    retail = {item["id"]: item for item in versions if item["id"] in {"us", "jp", "eu"}}

    matches: dict[str, dict] = {}
    if args.matches is not None and args.matches.is_file():
        matching_report = json.loads(args.matches.read_text(encoding="utf-8"))
        profile_id = args.match_profile
        if profile_id is None:
            raise SystemExit("--match-profile is required with --matches")
        try:
            profile = next(
                item for item in matching_report["profiles"] if item["profile"] == profile_id
            )
        except StopIteration as error:
            raise SystemExit(f"missing compiler profile {profile_id} in {args.matches}") from error
        for result in profile["functions"]:
            source = root / result["source"]
            source_current = source.is_file() and hashlib.sha256(source.read_bytes()).hexdigest() == result["source_sha256"]
            if result["verified_match"] and source_current:
                matches[result["name"]] = result

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
                "status": (
                    "byte_matching_c" if function["name"] in matches
                    else "behavior_recovered_match_unverified"
                ),
            }
        )

    output = {
        "schema": 1,
        "functions": records,
        "recovered_behavior_bytes": sum(item["size_bytes"] for item in records),
        "matching_c_bytes": sum(
            item["size_bytes"] for item in records if item["status"] == "byte_matching_c"
        ),
        "matching_c_functions": sum(
            item["status"] == "byte_matching_c" for item in records
        ),
        "matching_profile": args.match_profile if matches else None,
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
