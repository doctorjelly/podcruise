#!/usr/bin/env python3
"""Derive one authoritative ledger of every recovered source function.

The matching configuration is the single definition of what has been recovered:
each unit names a source file, the canonical addresses it claims, and the size
of each function. This tool joins that with the per-version comparison reports
so that "behaviour recovered" and "matching" are counted from generated
evidence rather than maintained by hand.
"""

from __future__ import annotations

import argparse
import json
import subprocess
import sys
import tempfile
from pathlib import Path

VERSIONS = ("us", "jp", "eu", "lrg_rev1")
# Sources that deliberately have no USA matching unit, with the reason. Every
# other recovered source must be measured, so --strict fails on anything else.
UNMEASURED = {
    "src/functions/func_80034824.c": "Japan-only stub; no USA function at this address",
    "src/functions/func_80038734.c": "Europe-only stub; no USA function at this address",
    "src/functions/func_80092250.c": (
        "overlap-safe block copy, proven hand-written: it forms one address "
        "with a trapping add and the same address elsewhere with addu, which "
        "no single C source can produce. The file is kept as reviewed "
        "documentation of the behaviour, validated against the host library "
        "over every alignment and length combination, and must never be "
        "registered as a matching unit"
    ),
    "src/functions/func_80092850.c": (
        "buffer zero-fill. Its head clears a run-time one to three bytes with a "
        "single unpartnered left-half store; the compiler emits that form only "
        "for a piece that starts at a word boundary, never one that ends at "
        "one, so no C typed access reaches it. Kept as documentation of the "
        "behaviour"
    ),
    "src/functions/func_80096AD0.c": (
        "buffer equality test. Reviewed C reproduces the body's block layout "
        "and loop shapes, but one block reads a register nothing has defined "
        "and moves a run-time number of bytes with an unpartnered partial "
        "word read; kept as documentation of the behaviour, which was checked "
        "against the host library over 400,000 randomised cases"
    ),
}
UNITS_FOR = {"us": "us", "jp": "jp", "eu": "eu", "lrg_rev1": "us"}
CONFIG = {
    "us": "config/c_matching.json",
    "jp": "config/c_matching.jp.json",
    "eu": "config/c_matching.eu.json",
}


def defined_functions(root: Path, source: Path) -> set[str]:
    """Function symbols a source file defines, via a host compile."""
    with tempfile.TemporaryDirectory() as work:
        obj = Path(work) / (source.stem + ".o")
        built = subprocess.run(
            ["gcc", "-std=c11", "-I", "include", "-c", str(source), "-o", str(obj)],
            cwd=root, capture_output=True, text=True,
        )
        if built.returncode != 0:
            raise SystemExit(f"{source}: host compile failed\n{built.stderr}")
        listing = subprocess.run(["nm", str(obj)], capture_output=True, text=True).stdout
    names = set()
    for line in listing.splitlines():
        fields = line.split()
        if len(fields) == 3 and fields[1] in ("T", "t"):
            names.add(fields[2])
    return names


def load_report(root: Path, version: str) -> dict[tuple[str, str], dict]:
    path = root / f"analysis/c_matches.{version}.json"
    report = json.loads(path.read_text(encoding="utf-8"))
    accepted = json.loads(
        (root / CONFIG[UNITS_FOR[version]]).read_text(encoding="utf-8")
    )["accepted_profile"]
    profile = next(item for item in report["profiles"] if item["profile"] == accepted)
    return {(item["name"], item["expected_vram"]): item for item in profile["functions"]}


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--output", type=Path, default=Path("analysis/source_manifest.json"))
    parser.add_argument("--strict", action="store_true",
                        help="fail when a recovered source has no matching unit")
    args = parser.parse_args()
    root = Path(__file__).resolve().parent.parent

    reports = {version: load_report(root, version) for version in VERSIONS}
    us = json.loads((root / CONFIG["us"]).read_text(encoding="utf-8"))
    regional = {
        version: json.loads((root / CONFIG[version]).read_text(encoding="utf-8"))
        for version in ("jp", "eu")
    }

    entries: list[dict] = []
    claimed_sources: set[str] = set()
    for unit in us["units"]:
        claimed_sources.add(unit["source"])
        included_sources = unit.get("included_sources", [])
        if included_sources and len(included_sources) != len(unit["functions"]):
            raise SystemExit(
                f"{unit['id']}: included_sources must correspond to functions"
            )
        claimed_sources.update(included_sources)
        for index, function in enumerate(unit["functions"]):
            key = (function["name"], function["vram"])
            exact = [
                version for version in ("us", "lrg_rev1")
                if reports[version].get(key, {}).get("verified_match")
            ]
            entries.append({
                "name": function["name"],
                "vram": function["vram"],
                "rom": function["rom"],
                "size": int(function["size"]),
                "source": (included_sources[index]
                           if included_sources else unit["source"]),
                "unit": unit["id"],
                "flags": unit.get("flags"),
                "exact_versions": exact,
            })

    by_source: dict[str, list[dict]] = {}
    for entry in entries:
        by_source.setdefault(entry["source"], []).append(entry)
    for version, config in regional.items():
        for unit in config["units"]:
            for function in unit["functions"]:
                key = (function["name"], function["vram"])
                if not reports[version].get(key, {}).get("verified_match"):
                    continue
                siblings = by_source.get(unit["source"], [])
                index = unit["functions"].index(function)
                if index < len(siblings):
                    siblings[index]["exact_versions"].append(version)

    sources = sorted(
        [path.relative_to(root).as_posix()
         for path in (root / "src").rglob("*.c")]
    )
    orphans = []
    for source in sources:
        if source in claimed_sources:
            continue
        orphans.append({
            "source": source,
            "functions": sorted(defined_functions(root, root / source)),
            "reason": UNMEASURED.get(source),
        })

    recovered_functions = len(entries)
    recovered_bytes = sum(entry["size"] for entry in entries)
    # Counted straight from each version's own report: a regional build may
    # carry units the USA ledger has no entry for, and vice versa.
    exact_by_version = {
        version: {
            "functions": sum(item["verified_match"] for item in reports[version].values()),
            "bytes": sum(item["expected_size"] for item in reports[version].values()
                         if item["verified_match"]),
        }
        for version in VERSIONS
    }
    manifest = {
        "schema": 1,
        "scope": "every function represented by reviewed C in this repository",
        "recovered_functions": recovered_functions,
        "recovered_bytes": recovered_bytes,
        "exact": exact_by_version,
        "unclaimed_sources": orphans,
        "functions": sorted(entries, key=lambda item: int(item["vram"], 16)),
    }
    (root / args.output).write_text(json.dumps(manifest, indent=2) + "\n", encoding="utf-8")
    print(f"recovered {recovered_functions} functions / {recovered_bytes} bytes")
    for version in VERSIONS:
        counts = exact_by_version[version]
        print(f"  exact {version:9s} {counts['functions']:4d} / {counts['bytes']:6d} bytes")
    unexplained = [item for item in orphans if item["reason"] is None]
    if orphans:
        print(f"sources with no matching unit: {len(orphans)}"
              f" ({len(unexplained)} unexplained)")
        for item in orphans:
            note = item["reason"] or "NO RECORDED REASON"
            print(f"  {item['source']}: {', '.join(item['functions'])} — {note}")
    if args.strict and unexplained:
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
