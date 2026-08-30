# func_80074CDC

## Verified facts

- The USA body spans VRAM `0x80074CDC` through `0x8007531B`, ROM `0x758DC`,
  1600 bytes. `jr ra` is at `0x80075314` with a nop delay slot;
  `func_8007531C` begins next.
- Both direct calls come from `func_80077054`. Its vector, trigonometric,
  interpolation, and two follow-up helpers and tuning globals are in the
  matching unit.
- Japan and Europe equivalents begin at `0x8007590C` and `0x8007A1BC`.

## Behavior

The routine advances four control-surface phases and derives an animation
strength from speed and accumulated motion. It rotates and offsets the enabled
left, right, center, and linked surfaces, runs two follow-up updates, and limits
the final surface's displacement from the vehicle body.

## Status

Behavior recovered from the USA binary and independently expressed in C; not
byte-matching. IDO 5.3 `-O2` emits 1572 bytes for the 1600-byte target and first
differs at byte `0x3`; 374 instruction words differ across 17 blocks. Regional
binaries were used only for structural and relocation confirmation.
