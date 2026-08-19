#!/usr/bin/env python3
"""Fail if a committable file violates the repository's conservative IP gate."""

from __future__ import annotations

import subprocess
import sys
from pathlib import Path


ROM_SUFFIXES = {".z64", ".n64", ".v64", ".rom"}
GENERATED_OR_BINARY_SUFFIXES = {
    ".7z",
    ".a",
    ".aif",
    ".aiff",
    ".asm",
    ".bin",
    ".bmp",
    ".dat",
    ".dll",
    ".dylib",
    ".elf",
    ".exe",
    ".jpg",
    ".jpeg",
    ".mp3",
    ".o",
    ".ogg",
    ".png",
    ".rar",
    ".raw",
    ".s",
    ".so",
    ".tga",
    ".wav",
    ".zip",
}
FORBIDDEN_PARTS = {"asm", "assets", "extracted"}
MAX_CANDIDATE_SIZE = 5 * 1024 * 1024
ROM_MAGICS = {
    bytes.fromhex("80371240"),
    bytes.fromhex("40123780"),
    bytes.fromhex("37804012"),
}


def main() -> int:
    root = Path(__file__).resolve().parent.parent
    # Include tracked files plus untracked files that are not ignored. This
    # catches a problem before the first `git add`, not only after it.
    result = subprocess.run(
        ["git", "ls-files", "--cached", "--others", "--exclude-standard", "-z"],
        cwd=root,
        check=True,
        stdout=subprocess.PIPE,
    )
    failures: list[str] = []
    for raw_name in result.stdout.split(b"\0"):
        if not raw_name:
            continue
        relative = raw_name.decode("utf-8", errors="surrogateescape")
        path = root / relative
        if path.suffix.lower() in ROM_SUFFIXES:
            failures.append(f"committable ROM extension: {relative}")
            continue
        if path.suffix.lower() in GENERATED_OR_BINARY_SUFFIXES:
            failures.append(f"committable generated/binary extension: {relative}")
            continue
        if FORBIDDEN_PARTS.intersection(path.parts):
            failures.append(f"committable generated-content path: {relative}")
            continue
        if path.is_file():
            if path.stat().st_size > MAX_CANDIDATE_SIZE:
                failures.append(f"committable file exceeds 5 MiB review limit: {relative}")
                continue
            with path.open("rb") as handle:
                if handle.read(4) in ROM_MAGICS:
                    failures.append(f"committable N64 ROM magic: {relative}")
    if failures:
        for failure in failures:
            print(f"ERROR: {failure}", file=sys.stderr)
        return 1
    print("repository safety check passed: committable files satisfy the automated IP gate")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
