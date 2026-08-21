# func_8000FE1C

## Boundary

- USA VRAM range: 0x8000FE1C .. 0x8000FE77 inclusive (92 bytes, 23 instructions).
- USA ROM offset 0x10A1C.
- The body ends with the return jump at 0x8000FE70; its delay slot is empty.
- Two internal backward branches exist (the two loops) but neither leaves the
  range, and no branch from the preceding routine enters it. All four direct
  call sites target 0x8000FE1C.
- Boundary correction: none.

## Callers

Four direct call sites. In every one it appears next to func_8000FE78 in a
short run of reset calls, which is consistent with a state-clearing step run at
the start of a race or menu transition.

## Callees

None. Leaf routine, no stack frame, no arguments, no return value.

## Globals and access widths

| symbol | shape | element access |
| --- | --- | --- |
| D_8009B814 | 2 entries | 32-bit word store |
| D_8009B82C | 2 rows of 8 | 32-bit word store |

The loop bound is expressed as the address of the symbol that immediately
follows D_8009B82C (D_8009B86C, 64 bytes later), which independently confirms
the 2 x 8 word shape. These are the same two tables written by func_8000FCBC
and func_8000FD74.

## Regional addresses

| version | entry | ROM |
| --- | --- | --- |
| USA | 0x8000FE1C | 0x10A1C |
| Japan | 0x8000FE1C | 0x10A1C |
| Europe | 0x8001027C | 0x10E7C |
| lrg_rev1 | 0x8000FE1C | 0x10A1C |

Japan places the two tables 0xCF0 higher, Europe 0x5550 higher. The
instruction stream is identical in all four versions.

## Recovered behaviour

A parameterless reset. For each of the two slots it writes -1 into the slot's
entry of the identifier table, then writes -1 into all eight entries of that
slot's sub-entry row.

The value -1 is used consistently as the "empty" marker for these identifier
tables, matching func_8000FCBC and func_8000FD74, which fill the same tables
with real identifiers when a slot is registered.

The compiler expanded the inner eight-iteration loop into two passes of four
stores each, and turned both loops into pointer walks: the sub-entry row
pointer advances 16 bytes per unrolled pass and the row base advances 32 bytes
per slot.

## Iteration notes

The first attempt (counted `for` loops) produced the correct instruction count
and identical code apart from the ordering of the four unrolled stores relative
to the pointer increment. Rewriting the same two loops in `while` form, with
the counters initialised and incremented as separate statements, reproduced the
original scheduling exactly. Three experiments were spent: an explicit
post-increment pointer walk (worse), a flat single-dimension index (identical
to the first attempt), and the `while` form (exact).

## Status

Byte-exact against USA, Japan, Europe and lrg_rev1 after four source shapes.
