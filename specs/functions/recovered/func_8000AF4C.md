# func_8000AF4C

## Boundary

- USA VRAM range `0x8000AF4C` .. `0x8000AFD3` (last instruction word begins at
  `0x8000AFD0`), ROM `0xBB4C` .. `0xBBD3`, size 136 bytes.
- The body terminates with the return instruction at `0x8000AFCC` and its delay
  slot at `0x8000AFD0`; the delay slot performs the sixth and final store, so
  the return is genuinely the end of the routine.
- Assigned boundary confirmed correct: no branch inside the routine leaves the
  range, nothing branches into the label from the preceding routine, and the
  entry has no instruction ahead of it that callers depend on.

## Callers

Two recorded direct calls, both at `0x800312C4` (the generated split lists the
same address in two overlapping section files). Every call site targets the
entry address directly.

## Callees

None. This is a leaf routine with no frame adjustment; it uses only the
caller-provided argument home area.

## Globals and access widths

- `D_8009B790` — a 32-bit pointer slot holding the base of an array of 124-byte
  records. It is re-read from memory before every element store, because each
  store writes through the pointer and the compiler must assume the pointer slot
  itself may have been overwritten.
- Record fields written: 32-bit floating point values at record offsets `0x54`,
  `0x58`, `0x5C`, `0x60`, `0x64` and `0x68`.

## Regional addresses

| version | entry VRAM | ROM | size | `D_8009B790` equivalent |
| --- | --- | --- | --- | --- |
| USA | 0x8000AF4C | 0xBB4C | 136 | 0x8009B790 |
| Japan | 0x8000AF4C | 0x00BB4C | 136 | 0x8009C480 |
| Europe | 0x8000AF4C | 0x00BB4C | 136 | 0x800A0CE0 |
| lrg_rev1 | 0x8000AF4C | 0xBB4C | 136 | 0x8009B790 |

The three regional bodies were read independently; they are instruction-for-
instruction the same routine with only the global relocated.

## Recovered behaviour

The routine takes a signed 16-bit record selector followed by six single
precision values. It selects the record at that index inside the array pointed
to by the global base pointer and copies the six values, in argument order, into
the six consecutive float fields that begin 0x54 bytes into the record. Nothing
is read back, nothing is returned, and no bounds check is performed — a caller
is expected to pass a valid index.

The last three values arrive in the stack portion of the argument area, which is
why the routine reads them back from the caller's argument block rather than
receiving them in floating point registers.

## Status

Exact. USA, Japan, Europe and lrg_rev1 all verify byte-identical from the single
source file `src/functions/func_8000AF4C.c`.
