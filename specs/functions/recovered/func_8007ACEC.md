# func_8007ACEC

## Boundary and evidence

USA is VRAM `0x8007ACEC`, ROM `0x07B8EC`, 756 bytes through `0x8007AFE0`.
The return at `0x8007AFD8` restores the 88-byte frame in its delay slot. No
direct caller is catalogued. The unique equivalents are Japan `0x8007B91C` /
ROM `0x07C51C` and Europe `0x800801CC` / ROM `0x080DCC`.

## Behavior

Run the object's common update and, unless its skip bit is set, execute the
ordered set of component updates. Publish either the object's fallback matrix
and threshold flag or the non-null matrices from selected table slots. When
either lighting bit is set and the light slot is valid, derive a repeating
fraction from the saved phase, use it to build ambient and diffuse colors with
a fixed forward direction, and update that light slot.

## Status

**Byte-matching C: USA and LRG.** IDO 5.3 `-O2` reproduces all 756 bytes in
both builds. Keeping the two equal red/green diffuse copies on one source line
reproduces the original scheduler's floating-point register assignment. Japan
and Europe remain structural evidence only; no byte-match claim is made for
them here.
