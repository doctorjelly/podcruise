# func_8000FCBC

## Boundary

- USA VRAM range: 0x8000FCBC .. 0x8000FD73 inclusive (184 bytes, 46 instructions).
- USA ROM offset 0x108BC.
- The body ends with the return jump at 0x8000FD70; its delay slot is empty
  (a single no-operation), so the return sequence occupies the final 8 bytes.
- The preceding routine (ending at 0x8000FCB8) terminates with its own return
  and does not branch past its end into this label. Both direct call sites
  target 0x8000FCBC exactly, so the assigned entry is correct.
- Boundary correction: none.

## Callers

Two direct call sites, both in the segment beginning at 0x8005DF24. Callers
place a small index in the first argument, a numeric identifier in the second,
the address of a stack-resident three-component vector in the third, a float
literal in the fourth, and four further words on the outgoing stack area.

## Callees

None. This is a leaf routine; it establishes no stack frame.

## Globals and access widths

| symbol | shape | element access |
| --- | --- | --- |
| D_8009B814 | 2 entries | 32-bit word store |
| D_8009B81C | 2 entries | 32-bit float store |
| D_8009B824 | 2 rows of 4 | 8-bit byte store |
| D_800D5790 | 2 entries | 32-bit word store |
| D_800D57A0 | 2 entries | 32-bit word store |
| D_800D57B0 | 2 entries | 32-bit word store |
| D_800D57D0 | 2 rows of 3 | 32-bit float store |

The two-slot shape is confirmed by the guard (which admits only indexes 0 and 1)
and by the addresses of the neighbouring symbols: each array ends exactly where
the next one begins, so D_8009B814 spans 8 bytes, D_8009B81C 8 bytes,
D_8009B824 8 bytes (2 x 4), and D_800D57D0 24 bytes (2 x 3 floats).

## Regional addresses

| version | entry | ROM |
| --- | --- | --- |
| USA | 0x8000FCBC | 0x108BC |
| Japan | 0x8000FCBC | 0x108BC |
| Europe | 0x8001011C | 0x10D1C |
| lrg_rev1 | 0x8000FCBC | 0x108BC |

Data relocation observed by reading each regional body directly:
Japan adds 0xCF0 to the 0x8009xxxx group and 0x3250 to the 0x800D5xxx group;
Europe adds 0x5550 and 0x8CA0 respectively. Instruction sequences are otherwise
identical in all four versions.

## Recovered behaviour

The routine records one complete "slot" description for a player-like index.

It takes eight arguments: a slot index, an identifier word, a pointer to three
consecutive floats, a float value, and four byte-sized values.

Nothing at all happens unless the slot index is in range: negative indexes and
indexes of two or above are rejected outright and the routine returns without
touching memory. The range test is done as a signed lower-bound check followed
by a signed upper-bound check against two.

For an accepted index the routine writes, in order:

1. the identifier word into the first table at the slot;
2. the three floats pointed at by the third argument into the corresponding
   three-float row of the vector table, copied component by component;
3. the sentinel value -1000 into three separate parallel word tables at the
   slot (the same constant is reused for all three);
4. the float argument into the float table at the slot;
5. the four byte arguments into the four consecutive bytes of the slot's byte
   row.

The -1000 sentinel written to three tables strongly suggests "no value yet"
markers being reset whenever a slot is (re)registered.

## Status

Byte-exact against USA, Japan, Europe and lrg_rev1. Matched on the first
attempt with no iteration.
