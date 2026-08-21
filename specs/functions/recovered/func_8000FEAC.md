# func_8000FEAC

## Boundary

- USA VRAM range: 0x8000FEAC .. 0x8000FEEF inclusive (68 bytes, 17 instructions).
- USA ROM offset 0x10AAC.
- The body ends with the return jump at 0x8000FEE8, and its delay slot holds
  the final float store, so the last useful work happens in the delay slot.
- The following routine begins cleanly at 0x8000FEF0 with its own address
  setup. All eight direct call sites target 0x8000FEAC.
- Boundary correction: none.

## Callers

Eight direct call sites, all in the segment beginning at 0x80018B28 and all
inside the same per-object loop. The first argument is loaded from a 16-bit
signed field of the object being processed; the second is the address of a
sub-structure 0x50 bytes into the object; the third is either the -9999
sentinel or a negated value computed by the caller.

## Callees

None. Leaf routine, no stack frame.

## Globals and access widths

| symbol | shape | element access |
| --- | --- | --- |
| D_800D59B8 | 20 rows of 3 | 32-bit float store |
| D_800D5AA8 | 20 entries | 32-bit word store |

The 20-row shape follows from the addresses: D_800D59B8 plus 20 rows of 12
bytes lands exactly on D_800D5AA8, which func_8000FE78 in turn clears over
exactly 20 words.

## Regional addresses

| version | entry | ROM |
| --- | --- | --- |
| USA | 0x8000FEAC | 0x10AAC |
| Japan | 0x8000FEAC | 0x10AAC |
| Europe | 0x8001030C | 0x10F0C |
| lrg_rev1 | 0x8000FEAC | 0x10AAC |

Both tables move by 0x3250 in Japan and 0x8CA0 in Europe; the instruction
stream is identical in all four versions.

## Recovered behaviour

Records one entry of a paired table: a word tag and a three-component position.

The routine takes an index, a pointer to three consecutive floats, and a word.
It writes the word into the tag table at the index, then copies the three
floats into the index's row of the vector table, component by component.

No range check is performed, so the caller is responsible for supplying an
index below twenty; the call sites do guard the index indirectly through the
object list they iterate.

The pairing with func_8000FE78, which fills the tag table with -9999, and with
the call sites that pass -9999 explicitly, indicates the word is a validity or
ordering tag attached to the recorded position.

## Status

Byte-exact against USA, Japan, Europe and lrg_rev1. Matched on the first
attempt with no iteration.
