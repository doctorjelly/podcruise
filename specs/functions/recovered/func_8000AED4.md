# func_8000AED4 — entry-table flag set

## Boundary

- USA VRAM range: `0x8000AED4` .. `0x8000AEFB`, **size 40 bytes**,
  10 instructions, ROM `0xBAD4`.
- Single return point at `0x8000AEF4`; its delay slot holds the word store
  that commits the updated field, so the store belongs to this function.
- Boundary confirmed correct: the single direct call site targets
  `0x8000AED4`; the preceding routine at `0x8000AEB4` (a read-only accessor
  for the very same field) closes with its own return plus a load in the delay
  slot at `0x8000AED0`; nothing branches into this range from outside.

## Callers

One direct call site, in the same translation unit, immediately after a run of
floating-point initialisation stores. That site passes the literal index 1 and
the literal mask 4, which is consistent with the two-argument reading below.

## Callees

None; leaf, no stack frame at all. Neither argument is spilled to a home slot,
which indicates both parameters are full 32-bit types rather than sub-word
ones — in particular the index here is a plain 32-bit integer, unlike the
16-bit index used by `func_8000AEFC`.

## Globals and access widths

| symbol | access | note |
|---|---|---|
| `D_8009B790` | 32-bit pointer load, then one 32-bit read-modify-write at element offset +0x00 | pointer to a heap/table base; element stride is 124 bytes |

The stride is formed as index x 31 x 4, i.e. 124 bytes per entry.

## Regional addresses

| version | vram | rom | `D_8009B790` |
|---|---|---|---|
| us | 0x8000AED4 | 0xBAD4 | 0x8009B790 |
| jp | 0x8000AED4 | 0xBAD4 | 0x8009C480 |
| eu | 0x8000AED4 | 0xBAD4 | 0x800A0CE0 |
| lrg_rev1 | 0x8000AED4 | 0xBAD4 | 0x8009B790 |

Each regional body was read independently; all four are identical apart from
the low half of the pointer's address (the high half happens to be 0x800A in
every version, including Europe, because of the sign-extension of the low
half).

## Recovered behaviour

`D_8009B790` holds a pointer to an array of 124-byte entries. Given an entry
index and a 32-bit bit mask, the routine turns on every bit of the mask in the
32-bit word at the very start of that entry: the word is read, the mask is
OR-ed in, and the result is stored back. The base pointer is read once. No
bounds check and no null check are performed, and nothing is returned.

## Status

Exact. Byte-identical against USA, Japan, Europe and lrg_rev1 at 40 bytes,
first attempt.
