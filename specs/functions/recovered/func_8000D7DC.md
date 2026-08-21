# func_8000D7DC

## Boundary
- USA VRAM `0x8000D7DC` .. `0x8000D818` (exclusive), ROM `0xE3DC`, size 60 bytes.
- Single 0x18-byte frame with the return address saved; two early exits converge on
  a shared epilogue, and the closing return has an empty delay slot.
- The two interior labels are branch targets of this function's own tests, not
  separate entries; the sole direct call site targets `0x8000D7DC`.

## Callers
One call site, in a routine that has just tested another condition; the argument is
set up by the caller and no result is used.

## Callees
- `func_8000C5F0(value)` — one integer argument.

## Globals
- `D_8009B7D8`, read as a 32-bit word; only bit 1 (mask `0x2`) is examined.

## Regional addresses
| version | entry | ROM | size | flag word | callee |
| --- | --- | --- | --- | --- | --- |
| us | 0x8000D7DC | 0xE3DC | 60 | D_8009B7D8 | func_8000C5F0 |
| jp | 0x8000D7DC | 0xE3DC | 60 | D_8009C4C8 | func_8000C5F0 |
| eu | 0x8000D870 | 0xE470 | 60 | D_800A0D28 | func_8000C5F0 |
| lrg_rev1 | 0x8000D7DC | 0xE3DC | 60 | D_8009B7D8 | func_8000C5F0 |

## Recovered behaviour
The routine acts only on one specific selector value: when its integer argument is
exactly eight, it consults a global flag word and, if the second-lowest bit of that
word is set, invokes the helper with the constant one. For any other argument value,
or when the flag bit is clear, it returns without doing anything. It reads no other
state and produces no result.

Note that the helper's address is unchanged across all four builds; only the flag
word moved between regions.

## Status
Exact on USA, JP, EU and lrg_rev1.
