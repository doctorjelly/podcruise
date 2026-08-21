# func_80011CDC

## Boundary
USA VRAM 0x80011CDC-0x80011D60, ROM 0x128DC, size 132 bytes. Ends with the
return instruction whose delay slot restores the stack pointer. Boundary
confirmed correct.

## Callers / callees
Six callers. Calls func_80008F28 (no arguments) and func_80011B18 (three
arguments: two addresses and a length).

## Globals
None.

## Regional addresses
- jp 0x80011CDC (ROM 0x128DC), inner routine relocated to func_80011B18
  (same address)
- eu 0x8001216C (ROM 0x12D6C), inner routine func_80011FA8
- lrg_rev1 shares the USA addresses.

## Behavior
A chunked transfer driver. It takes a source position, a destination position
and a total length, all as signed 32-bit values. It first runs the servicing
routine once. While the remaining length is positive it clamps the next chunk
to at most 2048 units, hands that chunk to the transfer routine, advances both
positions by the chunk size, reduces the remaining length by it, and runs the
servicing routine again before re-testing. Returns nothing.

## Status
exact in USA, Japan, Europe and lrg_rev1.
