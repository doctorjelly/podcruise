# func_8000FCA4

## Boundary

- USA VRAM range `0x8000FCA4`-`0x8000FCBB` inclusive, ROM `0x108A4`, size 24
  bytes (6 instructions).
- Terminates with a return whose delay slot holds the single store the function
  performs. The preceding function `func_8000FA2C` tears down an `0x80`-byte
  frame and returns at `0x8000FC9C`, so the assigned entry point is a true
  boundary.
- Leaf function, no frame; the second argument's home slot is written by the
  compiler because that argument is a narrow (byte-wide) type.

## Callers

Eleven direct call sites, all in the same later code region. Observed sites pass
a constant index of `0` and byte values such as `0x14`, `0x40` and `0x80`,
immediately after calling a related setter, which reads as configuring one
channel of a small table.

## Callees and globals

- `D_8009B827` (USA), written one byte at a time. The base address is not word
  aligned, which together with the four-byte index stride shows the target is a
  single byte field inside an array of four-byte records; this function reaches
  the fourth byte of each record.

## Parameters

1. signed 32-bit integer index
2. unsigned 8-bit value

Returns nothing.

## Regional addresses

| Version | Function VRAM | ROM | Size | Global |
| --- | --- | --- | --- | --- |
| USA | 0x8000FCA4 | 0x108A4 | 24 | D_8009B827 |
| Japan | 0x8000FCA4 | 0x0108A4 | 24 | D_8009C517 |
| Europe | 0x80010104 | 0x010D04 | 24 | D_800A0D77 |

Both regional bodies were read independently: identical six-instruction shape,
with the global relocated in each build and the European copy of the code moved
1120 bytes later.

## Recovered behavior

A one-line setter. It selects the entry at the given index in a table of
four-byte records and overwrites the single byte field this accessor owns with
the supplied value. The index is not range checked and nothing else is read or
written.

## Status

Exact. USA, Japan, and Europe all verify byte-identical.
