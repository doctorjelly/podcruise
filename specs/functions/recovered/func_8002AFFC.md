# func_8002AFFC

## Boundary and evidence

USA is VRAM `0x8002AFFC`, ROM `0x02BBFC`, 972 bytes through `0x8002B3C8`.
The return at `0x8002B3C0` has a `nop` delay slot. Direct callers are
`func_80021294`, `func_80021F84`, and `func_8002AD70`. The unique equivalents
are Japan `0x8002BA40` / ROM `0x02C640` and Europe `0x8002DEB0` / ROM
`0x02EAB0`.

## Behavior

Choose a camera anchor from a fixed origin, one of five object matrices, or
one of the world-position records selected by codes 26 through 30. An immediate
request publishes that anchor. Otherwise, generate a randomized endpoint near
it, using a different horizontal distribution for the world-position cases,
adjust the endpoint height for the special floor value, and publish the final
camera segment.

## Status

Behavior recovered only; the current compiler probe does not match the USA
function byte-for-byte.
