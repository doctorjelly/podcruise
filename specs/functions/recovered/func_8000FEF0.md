# func_8000FEF0 — reset the ten-slot request table and the forty-slot flag table

## Boundary

- USA VRAM range `0x8000FEF0` .. `0x8000FF53` inclusive; size 100 bytes
  (25 instructions).
- The body ends with the standard return instruction; its delay slot holds a
  no-operation, so the return pair occupies the last 8 bytes.
- The preceding function (`func_8000FEAC`) closes with its own return before
  this label, and every direct call site targets `0x8000FEF0` exactly, so the
  assigned entry point is the real boundary. No boundary correction needed.

## Callers

Four direct call sites in the USA build: `0x80052F94` (present in two overlay
segments that share the same address), `0x80060954`, `0x8008660C`. The function
takes no arguments and returns nothing.

## Callees

None. This is a leaf function with no stack frame.

## Globals and access widths

| symbol | role | width |
| --- | --- | --- |
| `D_800D5F80` | ten-entry table of signed words, first parallel column | 32-bit stores |
| `D_800D5FA8` | ten-entry table of signed words, second parallel column | 32-bit stores |
| `D_800D5FD0` | address one past the end of `D_800D5FA8`; appears only as the loop bound | address only |
| `D_800D5C38` | forty-byte flag table | 8-bit stores |
| `D_800D5C60` | address one past the end of `D_800D5C38`; appears only as the loop bound | address only |

`D_800D5FD0` and `D_800D5C60` are not referenced by the recovered source; the
original compiler materialises them as `D_800D5FA8 + 40` and `D_800D5C38 + 40`,
which the linker resolves to those same addresses.

## Regional addresses

| version | entry | ROM |
| --- | --- | --- |
| USA | `0x8000FEF0` | `0x10AF0` |
| Japan | `0x8000FEF0` | `0x10AF0` |
| Europe | `0x80010350` | `0x10F50` |
| `lrg_rev1` | `0x8000FEF0` | `0x10AF0` |

Regional data symbols (USA / Japan / Europe): `D_800D5F80` / `D_800D91D0` /
`D_800DEC20`; `D_800D5FA8` / `D_800D91F8` / `D_800DEC48`; `D_800D5C38` /
`D_800D8E88` / `D_800DE8D8`. All three regional bodies were read directly and
are instruction-for-instruction the same shape, differing only in those data
addresses.

## Recovered behaviour

The routine clears the bookkeeping used by the forty-slot registry that the
neighbouring functions in this file maintain.

1. Every one of the ten entries in each of the two parallel signed-word tables
   is set to negative one, which is the "no entry" sentinel that
   `func_80010014` later overwrites with real values.
2. Every one of the forty bytes of the flag table is set to zero, clearing the
   "slot in use" marks that `func_8000FF54` sets to one.

Both tables are walked front to back and nothing is read, so the routine is a
pure reset with no return value.

## Status

Exact. Byte-identical in USA, Japan, Europe and `lrg_rev1`.
