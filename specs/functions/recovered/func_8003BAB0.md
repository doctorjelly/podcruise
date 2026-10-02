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

Behavior-recovered C, not byte-matching. The current linked IDO 5.3 comparison
emits 5,728 bytes at the canonical address, with 1,255 differing words and
first difference at byte `0x5F`. The earlier smaller-body measurements describe
a superseded source, not the current expanded per-format macro output.

## Bounded packet audit

The four format branches begin at `8003BEAC`, `8003C2C8`, `8003C6E0`, and
`8003CAF0` in `analysis/generated/us/asm/main_3BF24.s`. Let `W` be the aligned
strip span and `H` the resource's default cross-span. Their packet arithmetic
agrees with the current source:

| Format | Width alignment | Pixels per load unit | Render F5 line |
| --- | ---: | ---: | --- |
| 0 | 16 | 4 | `ceil(W / 16)` |
| 1 | 8 | 2 | `ceil(W / 8)` |
| 2 | 4 | 1 | `ceil(W / 4)` |
| 3 | 2 | 1 | `ceil(W / 4)` |

F3 clamps `ceil(W * H / pixels_per_load_unit) - 1` to `0x7FF`.
With flag `0x400`, DXT is zero; otherwise it is
`ceil(2048 / (W / width_alignment))`. The first/load F5 has zero line bits,
tile index 7, and size selector 2 for formats 0–2 or 3 for format 3.
The second/render F5 uses the table's nine-bit line field and the actual
format as its size selector. F2 packs `4 * (W - 1)` and `4 * (H - 1)`,
each masked to twelve bits.

A private host pilot compared these assembly-derived F3/F5/F2 fields and
command counts in 864 cases: four formats, flag `0x400` off/on, cached/new
strip data, widths `7,8,9,15,16,17`, and heights
`1,7,8,9,15,16,17,257,1025`. All agree, including load-count saturation and
twelve-bit height wrapping. The pilot held image type zero, ordinary clamp
flags, and geometry inside the clipping rectangle; it does not establish
the remaining clipping or transformed-quad behavior. No source correction
or permanent regression test was warranted by this bounded audit.
