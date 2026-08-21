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
# Absolute paths from an operator's machine, scratch directories and private
# host names are not IP leaks, but they are still not publishable: they expose
# a contributor's filesystem layout and infrastructure to anyone who clones
# the repository. Recovered sources acquired these through generated comments,
# which is exactly the way they escape review.
# Assembled from fragments so that this file does not itself contain the
# literals it forbids, which would make the check flag its own source.
LOCAL_PATH_MARKERS = tuple(
    "/" + name for name in
    ("home/", "Users/", "media/", "tmp/claude", "var/folders/")
)
TEXT_SUFFIXES = {".c", ".h", ".md", ".py", ".json", ".yaml", ".yml", ".txt",
                 ".cfg", ".toml", ".ld", ".mk", ".s", ".sh"}
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
                    continue
            if path.suffix.lower() in TEXT_SUFFIXES or not path.suffix:
                body = path.read_text(encoding="utf-8", errors="replace")
                for marker in LOCAL_PATH_MARKERS:
                    if marker in body:
                        failures.append(
                            f"committable file contains a local machine path "
                            f"({marker!r}): {relative}")
                        break
    if failures:
        for failure in failures:
            print(f"ERROR: {failure}", file=sys.stderr)
        return 1
    print("repository safety check passed: committable files satisfy the automated IP gate")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
