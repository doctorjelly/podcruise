# func_8007E0AC

## Boundary
- USA VRAM `0x8007E0AC` .. `0x8007E0EC` (exclusive), ROM `0x7ECAC`, size 64 bytes.
- One 0x18-byte frame, one call, two stores, then the epilogue; the closing return
  has an empty delay slot.
- The function immediately before it returns four words earlier and does not branch
  into this range. Eight direct call sites all target `0x8007E0AC`.

## Callers
Eight call sites, all in one selector-driven routine that tests a saved mode value
against successive small constants; each of them stores the returned pointer into
its own frame and then passes it on to `func_800305E8`. The saved result is what
established that this routine has a pointer return value rather than being void.

## Callees
- `func_80018324(record, size)` — pointer plus a 32-bit count; called with `0x5064`.

## Globals
- `D_8011C950` — the record itself. Its address is passed to the helper, the 32-bit
  field at `+0x14` is cleared, the pointer field at `+0x18` is written, and the
  record address is returned.
- `D_8011C970` — the storage area at `+0x20` from the record base; only its address
  is taken.

Unlike the sibling routine `func_80046974`, this build treats the touched fields as
members of one aggregate: the record base is materialised once after the call and
both stores use displacements from it.

## Regional addresses
| version | entry | ROM | size | helper | record | area |
| --- | --- | --- | --- | --- | --- | --- |
| us | 0x8007E0AC | 0x7ECAC | 64 | func_80018324 | D_8011C950 | D_8011C970 |
| jp | 0x8007ED4C | 0x7F94C | 64 | func_80018454 | D_8011FBC0 | D_8011FBE0 |
| eu | 0x8008358C | 0x8418C | 64 | func_800187B4 | D_801255F0 | D_80125610 |
| lrg_rev1 | 0x8007E0AC | 0x7ECAC | 64 | func_80018324 | D_8011C950 | D_8011C970 |

## Recovered behaviour
The routine resets one fixed record and returns a handle to it. It hands the record's
base address and a fixed length of `0x5064` bytes to the shared preparation helper,
clears the record's counter field, points the record's link field at the adjacent
storage area, and returns the record's address so the caller can keep using it.

## Status
Exact on USA, JP, EU and lrg_rev1.
