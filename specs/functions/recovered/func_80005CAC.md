# func_80005CAC

## Boundary

- USA VRAM range: 0x80005CAC .. 0x80005CD0 inclusive (0x28 = 40 bytes, 10 instructions).
- USA ROM offset: 0x68AC.
- Ends with a return whose delay slot performs the single-precision division
  that produces the result, so the divide is part of the function.
- **Boundary corrected.** The assignment file gave size 80, which comes from a
  heuristic inventory entry that runs 40 bytes past the return and into the
  next function. The next function begins at 0x80005CD4 with its own stack
  frame and has two direct call sites of its own, so 0x80005CD0 is the last
  instruction here. Correct size is 40.

## Callers and callees

- Six direct call sites in the USA build. Every site places a pointer in
  argument 1, transfers a value out of a floating-point register into the
  argument-2 slot (so argument 2 is an `f32`), and passes a small integer as
  argument 3. The result is consumed as a float.
- No callees (leaf function).

## Globals and access widths

- None. All state comes through the argument-1 object.

## Object layout used

- offset 0x11C — pointer to an array of 32-bit floats (the key array).

## Regional addresses

Body is instruction-for-instruction identical in every version and references
no relocatable symbols, so a single source form covers all four builds.

| version  | VRAM       | ROM    |
|----------|------------|--------|
| us       | 0x80005CAC | 0x68AC |
| jp       | 0x80005CAC | 0x68AC |
| eu       | 0x80005CAC | 0x68AC |
| lrg_rev1 | 0x80005CAC | 0x68AC |

## Recovered behavior

Computes the normalized position of a value inside one segment of a key array
— the classic inverse-lerp used to drive interpolation between two adjacent
keys.

Given the object, a position, and a segment index, it reads the array pointer
from the object, takes the key at the index as the lower bound and the very
next key as the upper bound, and returns the position's distance above the
lower bound divided by the width of the segment. A result of 0 means the
position sits exactly on the lower key, 1 means it sits on the upper key, and
values outside 0..1 mean the position lies outside the segment. The function
performs no bounds checking and does not guard against a zero-width segment.

Source-shape note: the two key reads must be held in named locals for the
compiler to reproduce the original float register assignment, while the array
pointer must be reached through the object expression rather than a named
pointer local to reproduce the original integer register assignment.

## Status

Exact. Byte-identical in USA, Japan, Europe and the large-cartridge revision.
