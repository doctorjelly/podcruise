#!/usr/bin/env python3
"""Regenerate the tracked exact-USA progress history and README SVG."""

from __future__ import annotations

import re
import subprocess
from datetime import datetime
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
STATUS = "docs/DECOMP_STATUS.md"
TSV = ROOT / "docs/decomp_progress.tsv"
SVG = ROOT / "docs/decomp_progress.svg"
ROW = re.compile(
    r"^\| USA retail \| ([0-9,]+) \| ([0-9,]+) \| ([0-9.]+)% \|",
    re.MULTILINE,
)


def parse_status(text: str) -> tuple[int, int, float]:
    match = ROW.search(text)
    if not match:
        raise ValueError("USA retail coverage row not found")
    return (int(match.group(1).replace(",", "")),
            int(match.group(2).replace(",", "")),
            float(match.group(3)))


def git(*args: str) -> str:
    return subprocess.check_output(
        ["git", *args], cwd=ROOT, text=True, stderr=subprocess.DEVNULL
    )


def history() -> list[tuple[datetime, str, int, int, float]]:
    points = []
    last_metrics = None
    log = git("log", "--reverse", "--format=%H%x09%cI", "--", STATUS)
    for line in log.splitlines():
        sha, timestamp = line.split("\t", 1)
        try:
            metrics = parse_status(git("show", f"{sha}:{STATUS}"))
        except (subprocess.CalledProcessError, ValueError):
            continue
        if metrics == last_metrics:
            continue
        points.append((datetime.fromisoformat(timestamp), sha[:8], *metrics))
        last_metrics = metrics

    current = parse_status((ROOT / STATUS).read_text(encoding="utf-8"))
    if current != last_metrics:
        points.append((datetime.now().astimezone(), "working-tree", *current))
    if not points:
        raise SystemExit("no exact-USA progress points found")
    return points


def write_tsv(points: list[tuple[datetime, str, int, int, float]]) -> None:
    lines = ["timestamp\tcommit\texact_functions\texact_bytes\tpercent_cpu_text"]
    lines.extend(
        f"{stamp.isoformat()}\t{commit}\t{functions}\t{size}\t{percent:.2f}"
        for stamp, commit, functions, size, percent in points
    )
    TSV.write_text("\n".join(lines) + "\n", encoding="utf-8")


def write_svg(points: list[tuple[datetime, str, int, int, float]]) -> None:
    width, height = 960, 460
    left, right, top, bottom = 76, 28, 50, 70
    plot_w, plot_h = width - left - right, height - top - bottom
    seconds = [point[0].timestamp() for point in points]
    start, end = min(seconds), max(seconds)
    if start == end:
        end = start + 1

    def x(stamp: datetime) -> float:
        return left + (stamp.timestamp() - start) * plot_w / (end - start)

    def y(percent: float) -> float:
        return top + (100.0 - percent) * plot_h / 100.0

    coords = [(x(point[0]), y(point[4])) for point in points]
    path = [f"M {coords[0][0]:.1f} {coords[0][1]:.1f}"]
    for px, py in coords[1:]:
        path.extend((f"H {px:.1f}", f"V {py:.1f}"))

    dates = []
    for point in points:
        date = point[0].date()
        if date not in dates:
            dates.append(date)
    if len(dates) > 7:
        indices = sorted({round(i * (len(dates) - 1) / 6) for i in range(7)})
        dates = [dates[index] for index in indices]

    current = points[-1]
    elements = [
        f'<svg xmlns="http://www.w3.org/2000/svg" width="{width}" height="{height}" viewBox="0 0 {width} {height}" role="img">',
        "<title>USA exact-matching C progress over time</title>",
        "<desc>Step chart from zero to one hundred percent, based on committed decompilation status milestones.</desc>",
        '<rect width="100%" height="100%" fill="#0d1117"/>',
        '<text x="76" y="28" fill="#f0f6fc" font-family="sans-serif" font-size="20" font-weight="600">USA exact-matching C progress</text>',
    ]
    for percent in range(0, 101, 20):
        py = y(float(percent))
        elements.append(f'<line x1="{left}" y1="{py:.1f}" x2="{width-right}" y2="{py:.1f}" stroke="#30363d"/>')
        elements.append(f'<text x="{left-12}" y="{py+4:.1f}" text-anchor="end" fill="#8b949e" font-family="sans-serif" font-size="12">{percent}%</text>')
    for date in dates:
        stamp = next(point[0] for point in points if point[0].date() == date)
        px = x(stamp)
        elements.append(f'<line x1="{px:.1f}" y1="{height-bottom}" x2="{px:.1f}" y2="{height-bottom+6}" stroke="#8b949e"/>')
        elements.append(f'<text x="{px:.1f}" y="{height-bottom+24}" text-anchor="middle" fill="#8b949e" font-family="sans-serif" font-size="11">{date.strftime("%b %d")}</text>')
    elements.extend([
        f'<path d="{" ".join(path)}" fill="none" stroke="#58a6ff" stroke-width="3" stroke-linejoin="round"/>',
        f'<circle cx="{coords[-1][0]:.1f}" cy="{coords[-1][1]:.1f}" r="5" fill="#58a6ff"/>',
        f'<text x="{coords[-1][0]-8:.1f}" y="{coords[-1][1]-12:.1f}" text-anchor="end" fill="#f0f6fc" font-family="sans-serif" font-size="13" font-weight="600">{current[4]:.2f}%</text>',
        f'<text x="{width-right}" y="{height-18}" text-anchor="end" fill="#8b949e" font-family="sans-serif" font-size="12">{current[2]:,} functions / {current[3]:,} bytes exact</text>',
        "</svg>",
    ])
    SVG.write_text("\n".join(elements) + "\n", encoding="utf-8")


def main() -> None:
    points = history()
    write_tsv(points)
    write_svg(points)
    print(f"wrote {len(points)} exact-USA milestones through {points[-1][4]:.2f}%")


if __name__ == "__main__":
    main()
