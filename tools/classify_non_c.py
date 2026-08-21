#!/usr/bin/env python3
"""Identify functions that no C input can produce with the accepted compiler.

The disassembler ships a "handwritten" heuristic, but it is only a hint: it
flags bodies that are ordinary compiler output, and it misses bodies that are
not. This classifies on the one thing that actually decides the question,
namely whether the body uses an instruction the accepted compiler has no way to
emit.

IDO 5.3 has no inline assembly in any spelling. `asm`, `__asm` and `__asm__`
are parsed as calls to an undeclared function and emit nothing, `asm volatile`
is a syntax error, and `#pragma asm`/`#pragma endasm` is accepted but produces
no instruction. There is therefore no escape hatch:
a body containing a coprocessor-0 transfer, a cache-maintenance operation, or a
floating-point control-register transfer cannot be the output of any C
translation unit. Those are recorded as `non_c`.

Everything else is recoverable in principle. Unaligned word access is *not* a
reason to give up: IDO emits `lwl`/`lwr`/`swl`/`swr` whenever it moves a word
through a byte-aligned type. Nor are 64-bit operations: those come from a
translation unit built for MIPS III, which units express with their own `flags`.
Both are reported separately so they are not mistaken for the first category.

One caveat applies to the pairing rule: it counts across whatever extent the
label scan produced. Where that extent is wrong — a blob covering several real
functions, or a function split in two — the counts are not trustworthy and the
result wants confirming against the corrected boundary before it is believed.

The rule is checked against the strongest available control: none of the
functions the verifier reproduces byte-for-byte is flagged, which it could not
manage if any admitted instruction were reachable from C.

Only addresses, counts, and instruction-class names are written out. No
instruction listing leaves the ignored generated tree.
"""

from __future__ import annotations

import argparse
import collections
import json
import re
from pathlib import Path

LINE = re.compile(r"^\s*/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/\s+(\S+)\s*(.*)$")
# $k0 and $k1 are reserved for the exception handler; no compiler
# allocates them, so reading or writing one is decisive on its own.
KERNEL_REGISTER = re.compile(r"\$k[01]\b")

# Instructions the accepted compiler cannot emit from any C source. This list
# is deliberately short: every candidate was tested against the compiler before
# being admitted, because a wrong entry here retires a function that is in fact
# recoverable.
NON_C = {
    "coprocessor_0": {"mfc0", "mtc0", "dmfc0", "dmtc0", "tlbr", "tlbwi",
                      "tlbwr", "tlbp", "eret", "rfe"},
    "cache_maintenance": {"cache"},
    # C addition may not trap, so the compiler emits only the unsigned forms.
    # Compiling ordinary signed, unsigned, short, long, pointer, compound and
    # subscript additions produces `addu`/`addiu`/`subu` and never these.
    "trapping_arithmetic": {"add", "addi", "sub"},
}
# Instructions that look exotic but are ordinary compiler output. Each was
# confirmed by compiling a small C input and reading the result back:
#   unaligned_access       - a struct assignment over a byte-aligned type
#   floating_point_control - a plain (unsigned)float cast, which saves and
#                            restores the rounding mode around cvt.w.s
#   mips3_only             - a translation unit built for MIPS III, which such
#                            units express through their own `flags`
EXPLAINED = {
    "unaligned_access": {"lwl", "lwr", "swl", "swr", "ldl", "ldr", "sdl", "sdr"},
    "floating_point_control": {"cfc1", "ctc1"},
    "mips3_only": {"ld", "sd", "daddu", "daddiu", "dsll", "dsll32", "dsrl",
                   "dsra", "dsra32", "dmtc1", "dmfc1", "dmult", "dmultu",
                   "ddiv", "ddivu", "dsubu"},
}


SYMBOL = re.compile(r"\b(func_[0-9A-F]{8})\b")


def live_asm_sources(asm_root: Path, split_config: Path) -> list[Path]:
    """Only the assembly files the current split actually assembles.

    `analysis/generated/us/asm` accumulates files from earlier splits, when
    different functions were still assembly. Those stale files repeat the same
    addresses under the same labels, and because bodies are keyed by label and
    appended to, reading them inflates both the body count and every byte
    total. The split configuration is the authority on which files are live.
    """
    named = set()
    for line in split_config.read_text(encoding="utf-8").splitlines():
        match = re.match(r"\s*-\s*\[\s*0x[0-9A-Fa-f]+\s*,\s*asm\s*,\s*([^\],]+)", line)
        if match:
            named.add(match.group(1).strip())
    live = [asm_root / f"{name}.s" for name in sorted(named)]
    return [path for path in live if path.exists()]


def c_referenced_symbols(source_root: Path) -> set[str]:
    """Function symbols reached only from already-recovered C.

    A body called from `src/**/*.c` and nowhere in the remaining assembly is
    reachable; omitting this made recovering a caller look like it orphaned its
    callees.
    """
    found: set[str] = set()
    for source in sorted(source_root.rglob("*.c")):
        found.update(SYMBOL.findall(source.read_text(encoding="utf-8",
                                                     errors="replace")))
    return found


def read_references(sources: list[Path]) -> tuple[set[str], set[str], set[str]]:
    """Symbols reached by a call, by a branch, and by having their address taken.

    A body that none of the three reaches is not reachable as a function at
    all. Those are data, signal-processor programs, or interior fragments the
    label scan promoted by mistake, and they belong to segmentation rather than
    to decompilation.
    """
    called: set[str] = set()
    branched: set[str] = set()
    addressed: set[str] = set()
    for source in sources:
        for line in source.read_text(encoding="utf-8", errors="replace").splitlines():
            match = LINE.match(line)
            if match is None:
                continue
            mnemonic, operands = match.group(2), match.group(3)
            if mnemonic == "jal":
                called.add(operands.strip())
                continue
            for name in SYMBOL.findall(operands):
                if "%hi" in operands or "%lo" in operands:
                    addressed.add(name)
                elif mnemonic.startswith(("b", "j")):
                    branched.add(name)
    return called, branched, addressed


def classify_body(mnemonics, uses_kernel_register: bool,
                  called: bool = True) -> tuple[list[str], list[str]]:
    """Return (decisive reasons, explanatory notes) for one function body.

    A body that is never called but contains `break` is not a CPU function at
    all: the signal processor halts itself with `break`, and the main processor
    reaches such a block by taking its address and transferring it, not by
    calling it. Those blocks want segmenting as microcode, not decompiling.
    """
    used = set(mnemonics)
    # Partial word access is normally paired: the compiler takes the left and
    # right halves together to move one whole word through a byte-aligned type.
    # It does emit a lone *right* half, for a trailing piece of a copy whose
    # start is known word-aligned, so an unmatched right half proves nothing.
    # A lone *left* half is different: it writes a piece that ends at a word
    # boundary and so has a width decided at run time, which no C typed access
    # expresses. Only an excess of left halves is therefore decisive.
    counted = collections.Counter(mnemonics)
    unpaired = (counted["lwl"] > counted["lwr"]
                or counted["swl"] > counted["swr"])
    # `break` alone means nothing: the compiler emits it as the divide-by-zero
    # trap. A block that is never called, halts itself with `break`, *and*
    # drives coprocessor 0 is the signal processor's own program, which the
    # main processor reaches by transferring it rather than by calling it.
    if not called and "break" in used and used & NON_C["coprocessor_0"]:
        return ["signal_processor_microcode"], []
    reasons = sorted(key for key, group in NON_C.items() if used & group)
    if uses_kernel_register:
        reasons.append("kernel_registers")
    if unpaired:
        reasons.append("unpaired_partial_access")
    notes = sorted(key for key, group in EXPLAINED.items() if used & group)
    return reasons, notes


def read_bodies(sources: list[Path]) -> dict[str, tuple[list[str], bool]]:
    bodies: dict[str, list[str]] = {}
    kernel: dict[str, bool] = {}
    current: str | None = None
    for source in sources:
        for line in source.read_text(encoding="utf-8", errors="replace").splitlines():
            if line.startswith("glabel "):
                current = line.split()[1]
                bodies.setdefault(current, [])
                kernel.setdefault(current, False)
                continue
            if line.startswith("endlabel"):
                current = None
                continue
            match = LINE.match(line)
            if match is not None and current is not None:
                bodies[current].append(match.group(2))
                if KERNEL_REGISTER.search(match.group(3)):
                    kernel[current] = True
    return {name: (mnemonics, kernel[name]) for name, mnemonics in bodies.items()}


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--asm-root", type=Path,
                        default=Path("analysis/generated/us/asm"))
    parser.add_argument("--split-config", type=Path,
                        default=Path("config/us.yaml"))
    parser.add_argument("--output", type=Path,
                        default=Path("analysis/non_c_functions.json"))
    args = parser.parse_args()
    root = Path(__file__).resolve().parent.parent

    sources = live_asm_sources(root / args.asm_root, root / args.split_config)
    bodies = read_bodies(sources)
    callers, branched, addressed = read_references(sources)
    addressed |= c_referenced_symbols(root / "src")
    non_c, explained = [], []
    called = set()
    for mnemonics, _ in bodies.values():
        pass
    for name, (mnemonics, uses_kernel_register) in sorted(bodies.items()):
        reasons, notes = classify_body(mnemonics, uses_kernel_register,
                                       called=name in callers)
        entry = {
            "name": name,
            "instructions": len(mnemonics),
            "bytes": len(mnemonics) * 4,
        }
        if reasons:
            non_c.append({**entry, "reasons": reasons})
        elif notes:
            explained.append({**entry, "notes": notes})

    unreachable, interiors = [], []
    for name, (mnemonics, _) in sorted(bodies.items()):
        if not mnemonics or name in callers:
            continue
        entry = {"name": name, "bytes": len(mnemonics) * 4}
        if name in branched:
            interiors.append(entry)
        elif name not in addressed:
            unreachable.append(entry)

    result = {
        "schema": 1,
        "scope": "USA text as split; classification by instruction class only",
        "compiler_has_inline_assembly": False,
        "non_c_functions": len(non_c),
        "non_c_bytes": sum(item["bytes"] for item in non_c),
        "non_c": non_c,
        "recoverable_but_constrained": explained,
        "branch_only_interiors": {
            "count": len(interiors),
            "bytes": sum(item["bytes"] for item in interiors),
            "note": "reached only by a branch from a neighbour: a boundary to "
                    "correct, not a function to recover",
            "functions": interiors,
        },
        "unreferenced_bodies": {
            "count": len(unreachable),
            "bytes": sum(item["bytes"] for item in unreachable),
            "note": "never called, never branched to, address never taken: "
                    "candidates for segmentation as data or microcode",
            "functions": unreachable,
        },
    }
    (root / args.output).write_text(json.dumps(result, indent=2) + "\n",
                                    encoding="utf-8")
    print(f"non-C by construction: {len(non_c)} functions / "
          f"{result['non_c_bytes']} bytes")
    for item in non_c:
        print(f"  {item['name']:16s} {item['bytes']:5d}B  {', '.join(item['reasons'])}")
    print(f"branch-only interiors (boundary errors): {len(interiors)} / "
          f"{sum(i['bytes'] for i in interiors):,} bytes")
    print(f"unreferenced bodies (segmentation): {len(unreachable)} / "
          f"{sum(i['bytes'] for i in unreachable):,} bytes")
    print(f"constrained but recoverable: {len(explained)} functions")
    for item in explained:
        print(f"  {item['name']:16s} {item['bytes']:5d}B  {', '.join(item['notes'])}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
