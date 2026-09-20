# USA residual assembly-label audit

The current generated USA assembly listings were scanned for `nonmatching`
labels. Every configured C function's ROM interval in `config/c_matching.json`
was subtracted first, including behavior-only C, so a label inside an already
recovered body was not counted as a fresh function. Duplicate labels were
removed. The remaining 139 labels break down as follows:

| Generated classification | Count | Interpretation |
| --- | ---: | --- |
| Explicitly marked handwritten | 23 | Includes exception, cache, and low-level hardware routines; retain as assembly unless a specific body is proved compiler-generated. |
| Unmarked, four bytes | 114 | Too short to be a self-contained returning MIPS function; treat as label-scan fragments, not 114 recovery tasks. |
| Unmarked, longer than four bytes | 2 | Inspected below. |

All 18 surviving labels of at least 24 bytes are explicitly marked
handwritten in their generated listing. The two longer unmarked labels are:

- `func_80000400`, 20 bytes at ROM `0x1000`: startup code initializes `$sp`
  and jumps to `func_80000450`, followed by padding. It is not a normal C
  function entered with a valid stack.
- `func_80093C20`, 16 bytes at ROM `0x94820`: `cfc1` and `ctc1` access the
  floating-point control register before returning. This is a hardware
  primitive, not a new ordinary C body.

This is a classification of *generated labels*, not proof that every byte of
the remaining ROM is recovered C. The next productive queue is the existing
behavior-recovered C that still fails exact comparison. Rebuild this inventory
if the USA split or configured C intervals change; do not assign the 114
four-byte fragments as independent functions.
