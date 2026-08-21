# func_8000AAF8

## Boundary

- USA VRAM range: `0x8000AAF8` .. `0x8000AB23` inclusive (44 bytes / 11 words).
- USA ROM offset: `0xB6F8`.
- Ends with a return at `0x8000AB1C` whose delay slot is empty.
- The single conditional branch targets that return, inside the range.
- 3 direct call sites target `0x8000AAF8`; the preceding function ends with its
  own return at `0x8000AAF0`, and the next function starts at `0x8000AB24`.
- Boundary as assigned is correct.

## Callers / callees

- Callers: 3 direct call sites.
- Callees: none. This is a leaf.

## Globals and access widths

- `D_800D2190` — base of the array of 32-byte records. One 32-bit floating point
  field at record offset `0x10` is written.

  The assignment listed this global as `D_800D21A0`. That symbol is simply the
  `+0x10` field of the record at index 0: because there is only one store here,
  the compiler folds the constant field offset into the address materialisation,
  and the disassembler then names the folded address as its own symbol. The
  recovered source expresses it as element `0x10` of the shared `D_800D2190`
  table, which produces exactly the same instruction words, and keeps the table
  base consistent with the other four functions in this group.

## Argument note

Parameter two is a single-precision float arriving in an integer argument
register (parameter one is an integer), moved into the floating point unit
without conversion. The signature is `(s16, f32)`.

## Regional addresses

| version | vram | rom | `D_800D2190` | folded address |
| --- | --- | --- | --- | --- |
| us | 0x8000AAF8 | 0xB6F8 | 0x800D2190 | 0x800D21A0 |
| jp | 0x8000AAF8 | 0xB6F8 | 0x800D53E0 | 0x800D53F0 |
| eu | 0x8000AAF8 | 0xB6F8 | 0x800DAE30 | 0x800DAE40 |
| lrg_rev1 | 0x8000AAF8 | 0xB6F8 | 0x800D2190 | 0x800D21A0 |

The `+0x10` relationship holds in every version, which independently confirms
that this is the same table and the same record field.

Regional bodies read independently: identical to USA apart from the relocated
table address.

## Recovered behaviour

Sets the third floating point field of a record.

Parameters: a 16-bit signed record index and one single-precision float.

If the index is negative the routine returns without touching anything.
Otherwise the value is written into the record's field at offset `0x10`.
`func_8000A44C` initialises that field to 0.0 when it resets a record, so its
neutral value is zero — consistent with a rotation angle or a depth/offset,
sitting immediately after the unit-valued scale pair set by `func_8000AAC0`.

The routine returns nothing.

## Status

Exact. USA, Japan, Europe and `lrg_rev1` verified byte-identical.
