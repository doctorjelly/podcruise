#!/usr/bin/env python3
"""Record measured per-function token usage from a completed agent wave.

Each worker in a wave is given exactly one function, so its transcript is a
genuine measurement rather than a batch total apportioned after the fact --
which AGENTS.md forbids. A worker that was given several functions is written
as one tranche row naming all of them, for the same reason.

Usage:
    python3 tools/log_function_tokens.py <workflow-run-dir> [--commit SHA] [--apply]
"""

# Python 3.9 evaluates annotations at definition time.
from __future__ import annotations
import argparse
import collections
import os
import datetime
import json
import pathlib
import re

ROOT = pathlib.Path(__file__).resolve().parent.parent
LOG = ROOT / "docs/function_token_log.tsv"
ASSIGN = re.compile(r"assign/([A-Za-z0-9_]+)\.(?:json|md)")


def wave_agents(run_dir: pathlib.Path):
    """Map each agent transcript to the assignment it was given."""
    for path in sorted(run_dir.glob("agent-*.jsonl")):
        batch, usage = None, collections.defaultdict(lambda: [0, 0, 0, 0, 0])
        for line in path.open(errors="replace"):
            try:
                record = json.loads(line)
            except Exception:
                continue
            if batch is None:
                found = ASSIGN.search(json.dumps(record.get("message", "")))
                if found:
                    batch = found.group(1)
            use = (record.get("message") or {}).get("usage") or {}
            rid = record.get("requestId") or (record.get("message") or {}).get("id")
            if not use or not rid:
                continue
            # Streamed responses repeat a requestId; keep the largest sample of
            # each rather than summing partials.
            slot = usage[rid]
            slot[0] = max(slot[0], use.get("input_tokens", 0) or 0)
            slot[1] = max(slot[1], use.get("cache_read_input_tokens", 0) or 0)
            slot[2] = max(slot[2], use.get("cache_creation_input_tokens", 0) or 0)
            slot[3] = max(slot[3], use.get("output_tokens", 0) or 0)
        totals = [sum(col) for col in zip(*usage.values())] if usage else [0, 0, 0, 0, 0]
        yield batch, totals, len(usage)


def outcomes():
    """Per-function verdicts from the USA verification report, when present."""
    report = ROOT / "analysis/c_matches.us.json"
    if not report.exists():
        return {}
    profile = json.loads(report.read_text())["profiles"][0]
    verdicts = {}
    for fn in profile["functions"]:
        name = fn.get("name")
        if not name:
            continue
        if fn.get("byte_identical"):
            verdicts[name] = ("exact", fn.get("expected_size", 0))
        elif fn.get("actual_size") == fn.get("expected_size"):
            verdicts[name] = ("no_match_correct_size", 0)
        else:
            verdicts[name] = ("no_match", 0)
    return verdicts


def functions_for(batch: str, assign_dir: pathlib.Path | None):
    """Resolve an assignment name to the function names it covers.

    The assignment directory is a scratch area outside the repository, so its
    location is supplied by the caller (--assign-dir or PODCRUISE_ASSIGN_DIR)
    rather than written here: an operator's absolute paths do not belong in
    committed files, and `make safety` enforces that.
    """
    if assign_dir is None:
        return [batch]
    target = assign_dir / f"{batch}.json"
    if not target.exists():
        return [batch]
    try:
        return [e["name"] for e in json.loads(target.read_text())]
    except Exception:
        return [batch]


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("run_dir", type=pathlib.Path)
    parser.add_argument("--commit", default="")
    parser.add_argument("--model", default="claude-opus-5")
    parser.add_argument("--reasoning", default="low")
    parser.add_argument("--assign-dir", type=pathlib.Path,
                        default=os.environ.get("PODCRUISE_ASSIGN_DIR"),
                        help="directory holding the worker assignment files")
    parser.add_argument("--apply", action="store_true")
    args = parser.parse_args()

    stamp = datetime.datetime.now().astimezone().isoformat(timespec="seconds")
    verdicts = outcomes()
    rows = []
    for batch, (inp, cached, cache_write, out, _), calls in wave_agents(args.run_dir):
        if batch is None:
            continue
        names = functions_for(batch, args.assign_dir)
        # One function per worker is a measurement; several is a tranche.
        scope = ("isolated-function-agent-raw" if len(names) == 1
                 else "agent-tranche-raw")
        note = (f"One {args.model} {args.reasoning} worker over {calls} API calls; "
                f"measured from the worker transcript, not apportioned.")
        seen = [verdicts.get(n, ("attempted", 0)) for n in names]
        result = "+".join(sorted({s[0] for s in seen}))
        gained = sum(s[1] for s in seen)
        rows.append("\t".join([
            stamp, args.commit, "+".join(names), result, str(gained),
            args.model, args.reasoning,
            str(inp + cached + cache_write), str(inp), str(cached),
            str(cache_write), str(out), "", str(inp + cached + cache_write + out),
            scope, "", "", "", note,
        ]))

    if not rows:
        print("no agent transcripts with an identifiable assignment")
        return 1
    print(f"{len(rows)} rows")
    if args.apply:
        with LOG.open("a") as handle:
            handle.write("\n".join(rows) + "\n")
        print(f"appended to {LOG.relative_to(ROOT)}")
    else:
        print(rows[0][:200])
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
