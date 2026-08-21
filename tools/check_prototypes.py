#!/usr/bin/env python3
"""Cross-check every recovered function's definition against its declarations.

A wrong prototype can still reproduce the original bytes, because the value the
call should have passed is often already in the right register. The byte
comparison therefore cannot catch this class at all, and five real defects were
found here after their functions had been verified byte-identical.

Two disagreements are deliberate and are listed below. The original was built
from unprototyped C, so a caller could pass more arguments than the callee
accepted; where the caller's own bytes prove it did, reproducing the
disagreement is faithful and forcing agreement would be wrong.
"""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

DEFINITION = re.compile(
    r"^([A-Za-z_][\w \*]*?)\b(func_[0-9A-F]{8})\s*\(([^;{]*?)\)\s*\{", re.M)
EXTERN = re.compile(
    r"^\s*extern\s+([A-Za-z_][\w \*]*?)\b(func_[0-9A-F]{8})\s*\(([^;]*?)\)\s*;", re.M)
HEADER = re.compile(
    r"^\s*([A-Za-z_][\w \*]*?)\b(func_[0-9A-F]{8})\s*\(([^;]*?)\)\s*;", re.M)

# (callee, declaring file, declared arity) -> why this exact disagreement is
# faithful. Keyed on all three so that any *other* disagreement involving the
# same callee still fails.
ACCEPTED = {
    ("func_80031BBC", "func_80031B70.c", 2): (
        "passes its own second argument, which the original left in place "
        "rather than setting up; the callee never reads it"),
    ("func_8003FA24", "func_8007BDF4.c", 3): (
        "passes a third argument the callee ignores; the caller's bytes show "
        "the register genuinely set before the call"),
    ("func_80008C58", "func_80008BC4.c", 7): (
        "passes a seventh argument the callee never reads: the callee's frame "
        "only ever loads incoming stack words at +0x10 and +0x14, while the "
        "caller writes a third one at +0x18. Dropping the extra argument "
        "shortens the caller from its original 148 bytes to 140, so the "
        "disagreement is what the original build did"),
}


def parameters(text: str) -> int | None:
    """Parameter count, or None when the declaration does not specify one.

    Empty parentheses are C's "unspecified arguments", not zero arguments; only
    `(void)` means zero. Conflating them reports a disagreement that is not one.
    """
    text = " ".join(text.split())
    if text == "":
        return None
    if text == "void":
        return 0
    return len(text.split(","))


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", type=Path)
    args = parser.parse_args()
    root = args.root or Path(__file__).resolve().parent.parent

    definitions: dict[str, tuple[str, int]] = {}
    declarations: dict[str, list[tuple[str, int]]] = {}
    sources = sorted(root.joinpath("src").rglob("*.c"))
    headers = sorted(root.joinpath("include").rglob("*.h"))
    for path in sources + headers:
        text = path.read_text(encoding="utf-8", errors="replace")
        for _, name, params in DEFINITION.findall(text):
            count = parameters(params)
            definitions[name] = (path.name, 0 if count is None else count)
        pattern = HEADER if path.suffix == ".h" else EXTERN
        for _, name, params in pattern.findall(text):
            declarations.setdefault(name, []).append((path.name, parameters(params)))

    problems = []
    for name, declared in sorted(declarations.items()):
        if name not in definitions:
            continue
        defined_in, arity = definitions[name]
        for where, count in declared:
            if count is None:
                continue        # unprototyped: specifies nothing to disagree with
            if count == arity or (name, where, count) in ACCEPTED:
                continue
            problems.append(
                f"{name}: defined in {defined_in} with {arity} parameter(s), "
                f"declared in {where} with {count}")

    print(f"definitions {len(definitions)}, declarations {len(declarations)}, "
          f"accepted disagreements {len(ACCEPTED)}")
    for problem in problems:
        print(f"  {problem}")
    if problems:
        print(f"prototype disagreements: {len(problems)}")
        return 1
    print("prototype agreement: clean")
    return 0


if __name__ == "__main__":
    sys.exit(main())
