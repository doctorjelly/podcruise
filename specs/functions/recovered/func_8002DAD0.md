# func_8002DAD0

## Boundary

- USA VRAM range 0x8002DAD0 .. 0x8002DB1F inclusive, ROM 0x2E6D0, **80 bytes**
  (20 instructions).
- The assignment file gave 160 bytes. **Boundary corrected**: the inventory
  merged this function with the one that follows. The body ends with the return
  at 0x8002DB18 whose delay slot at 0x8002DB1C carries the result move; the
  next function starts at 0x8002DB20 with its own stack-frame prologue.
- Single return point. No stack frame.

## Callers and callees

- Twelve direct call sites in the USA build. Callees: none (leaf).
- One nearby caller passes a sign-extended byte for argument 2 and an
  eight-bit-masked value for argument 3, matching the widths below.

## Globals and access widths

- `D_8011368C` - array of unsigned bytes, read with an unsigned byte load,
  indexed by argument 2.
- `D_80113E68` - array of unsigned bytes, read with an unsigned byte load,
  indexed by argument 2.
- Both are read only.

## Arguments and result

- Argument 1: pointer to a record; only one field is read, a signed byte at
  byte offset 0x6C.
- Argument 2: signed 8-bit index.
- Argument 3: unsigned 8-bit bit position.
- Result: 32-bit integer, 0 or 1.
- Arguments 2 and 3 are written to their argument home slots on entry (IDO's
  handling of sub-word parameters); argument 1, being a pointer, is not.

## Recovered behavior

The function answers whether a particular flag bit is set for a given index.
It first selects one of two parallel byte tables according to a flag byte held
inside the record passed as the first argument: when that byte is non-zero the
first table is used, otherwise the second. It then reads the table entry for
the supplied index, tests the bit whose position is given by the third
argument, and returns one when that bit is set and zero when it is not.

The compiled form reads the first table unconditionally and overwrites the
value from the second table only on the fall-through path, which is what an
unconditional read followed by a conditional override produces; an if/else
pair produces an extra jump and does not match.

## Regional forms

- Japan: 0x8002E534, ROM 0x2F134, 80 bytes - identical sequence with the two
  tables relocated to 0x801170D8 (first table) and 0x801168FC (second table).
- Europe: 0x80031074, ROM 0x31C74, 80 bytes - identical sequence with the two
  tables relocated to 0x8011CB08 (first table) and 0x8011C32C (second table).
- lrg_rev1 shares the USA addresses and symbol addresses and matches there too.

## Status

exact - byte identical in USA, Japan, Europe and lrg_rev1.
