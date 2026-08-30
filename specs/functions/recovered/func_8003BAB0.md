# func_8003BAB0 — emit one clipped texture strip

## Verified boundary

- USA VRAM `[0x8003BAB0, 0x8003D110)`, ROM `[0x3C6B0, 0x3DD10)`,
  5,728 bytes.
- The body restores its `0x1E0`-byte frame, returns at `0x8003D108`, and has
  a `nop` delay slot at `0x8003D10C`.
- The three direct USA references resolve to the same call site represented in
  the recovered `func_8003D4F4` translation unit; duplicate generated assembly
  views account for the repeated textual references.

## Inputs and state

The caller passes a display-list cursor, an image resource, one strip from that
resource, screen bounds, texture coordinates and derivatives, two reversal
flags, a rotation pair, and rendering flags. The routine reads the strip span
and data pointer plus the resource's image type, pixel-size selector, dimensions
and default strip height.

`D_80114548`, `D_8011454C`, `D_80114540`, and `D_80114544` are respectively
the left, top, right, and bottom clipping limits. `D_800A48D0` caches the most
recent strip data pointer. The only callees are `func_8003B860`, which emits an
axis-aligned split quad around a pivot, and `func_8003B324`, which emits a
rotated four-vertex quad.

## Behavior

The function aligns the source width according to its four supported pixel-size
selectors, rejects strips wholly outside the clipping rectangle, and clips each
remaining edge to quarter-pixel coordinates. Clipping the left or top edge also
advances the starting texture coordinate using the supplied derivatives.

When the strip data pointer differs from the cached pointer, it emits the RDP
image, tile, load, synchronization, and tile-size commands appropriate to 4-,
8-, 16-, or 32-bit source pixels, then updates the cache. Clamp and mask fields
are selected from the resource dimensions and high rendering flags.

For the ordinary path it emits a texture rectangle, starting texture
coordinates, signed derivatives, and a final pipe synchronization command. If
either transformed-quad flag is set, it instead constructs full-strip texture
coordinates, calls the pivoted or rotated quad helper, and then synchronizes.
The display-list cursor is written back on every path, including rejection.

Pixel-size selectors outside `0` through `3` are not a supported input. The
original reads an uninitialized alignment temporary for such a selector and
does not issue a texture load, so no deterministic behavior is claimed there.

## Regional evidence

| build | entry | ROM | size | return / delay slot |
| --- | --- | --- | ---: | --- |
| USA | `0x8003BAB0` | `0x3C6B0` | 5,728 | `0x8003D108` / `0x8003D10C` |
| Japan | `0x8003C430` | `0x3D030` | 5,728 | `0x8003DA88` / `0x8003DA8C` |
| Europe | `0x800403F0` | `0x40FF0` | 5,728 | `0x80041A48` / `0x80041A4C` |

All three bodies have the same frame size, instruction count, exit shape, and
two-helper structure. Regional addresses are structural evidence only; USA is
the canonical comparison target.

## Status

Behavior-recovered C, not byte-matching. An exact linked comparison found a
2,288-byte IDO 5.3 body and a 2,264-byte IDO 7.1 body against the 5,728-byte
canonical body; both first differ in byte `0x3`. The compact shared command
construction intentionally does not reproduce the original source's expanded
per-format macro shape.
