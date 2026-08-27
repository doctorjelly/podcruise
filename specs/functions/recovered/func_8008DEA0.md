# func_8008DEA0

## Boundary and regional evidence

The USA body is VRAM `0x8008DEA0` through `0x8008E074`, ROM `0x08EAA0`, 468
bytes. It ends with `jr $ra` at `0x8008E06C` and a `nop` delay slot. The
routine is installed as a callback by `func_8008D684`; `func_800887D0` also
invokes it directly during object setup. Its only call is the 32-byte copy
helper `func_80096710`.

The unique structural equivalents are Japan `0x8008EB90` / ROM `0x08F790`
and Europe `0x800933F0` / ROM `0x093FF0`. Their shared relocation relative to
the surrounding audio routines supports the USA boundary.

## Behavior

For mode 4, reset three state counters, keep the existing source, publish its
identifier, and copy the source channel count when the optional channel block
exists. For mode 5, install the supplied source and select one of two stream
handlers from its type byte. Type zero aligns a byte count to nine-byte
blocks, derives a geometry size, copies three channel fields and a 32-byte
payload, or clears those fields when the channel is absent. Type one selects
the alternate handler and copies or clears the same three fields without the
payload. Other modes and source types make no further change.

## Status

Behavior recovered only. This source has no matching unit and has not passed
an exact IDO comparison.
