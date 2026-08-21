# func_8000AAC0

## Boundary

- USA VRAM range: `0x8000AAC0` .. `0x8000AAF7` inclusive (56 bytes / 14 words).
- USA ROM offset: `0xB6C0`.
- Ends with a return at `0x8000AAF0` whose delay slot is empty.
- The single conditional branch targets that return, inside the range.
- 106 direct call sites target `0x8000AAC0`; the preceding function ends with
  its own return at `0x8000AAB8` and does not branch across.
- Boundary as assigned is correct.

## Callers / callees

- Callers: 106 direct call sites.
- Callees: none. This is a leaf.

## Globals and access widths

- `D_800D2190` — base of the array of 32-byte records. Two 32-bit floating point
  fields at record offsets `0x08` and `0x0C` are written.

## Argument note

Parameters two and three are single-precision floats. Because parameter one is
an integer, the floats arrive in integer argument registers and are moved into
the floating point unit without conversion before being stored — the signature
is `(s16, f32, f32)`, not `(s16, s32, s32)`.

## Regional addresses

| version | vram | rom | `D_800D2190` |
| --- | --- | --- | --- |
| us | 0x8000AAC0 | 0xB6C0 | 0x800D2190 |
| jp | 0x8000AAC0 | 0xB6C0 | 0x800D53E0 |
| eu | 0x8000AAC0 | 0xB6C0 | 0x800DAE30 |
| lrg_rev1 | 0x8000AAC0 | 0xB6C0 | 0x800D2190 |

Regional bodies read independently: identical to USA apart from the relocated
table address.

## Recovered behaviour

Sets the floating point scale pair of a record.

Parameters: a 16-bit signed record index and two single-precision floats.

If the index is negative the routine returns without touching anything.
Otherwise the two floats are written into the record's fields at offsets `0x08`
and `0x0C`, in that order. `func_8000A44C` initialises exactly those two fields
to 1.0 when it resets a record, which identifies them as a horizontal/vertical
scale pair whose neutral value is unity.

The routine returns nothing.

## Status

Exact. USA, Japan, Europe and `lrg_rev1` verified byte-identical.
