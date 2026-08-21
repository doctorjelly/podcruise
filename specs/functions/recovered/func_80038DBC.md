# func_80038DBC — set or clear one flag bit of a global control word

## Boundary

- **Corrected.** The assignment gave `0x80038DBC`, size 72. The generated
  listing splits the region into two heuristic labels, `func_80038DBC` (36
  bytes) and `func_80038DE0` (24 bytes), and the assignment size is twice the
  first label's length rather than the real extent.
- The real function is `0x80038DBC` .. `0x80038DF7` inclusive, **60 bytes**,
  ROM `0x399BC`, translation unit `main_18B28.s`.
- `func_80038DE0` is not a function: it has zero direct call sites, it is the
  target of the conditional branch that opens `func_80038DBC`, and its first
  instruction completes an address that was only half-formed in that branch's
  delay slot. It is the `else` arm of this function.
- The function has two return points, one for each arm. The first return's
  delay slot carries the store of the cleared word; the second return's delay
  slot is empty.
- The next real function, `func_80038DF8`, begins immediately at `0x80038DF8`
  and has its own callers, so the corrected end is confirmed on both sides.

## Callers

Sixteen direct call sites, in the routines at `0x80042EF4`, `0x80046330`,
`0x8004CA50`, `0x8005E1A4` and `0x80087198`. Every site loads a small literal
into the first argument register — the observed values are `0` and `1` — and
no site uses a return value. The signature is therefore
`void (signed 32-bit flag)`.

## Callees

None (leaf).

## Globals and access widths

| Symbol | Width | Use |
| --- | --- | --- |
| `D_800D6960` | 32-bit word at byte offset `0x1C` | read, bit-modified, written back |

Only the single word at offset `0x1C` from the symbol is touched, and only bit
`0x40` of it changes; all other bits are preserved in both arms. The base
address is materialised once per arm and reused for the load and the store,
which is how the original compiler addresses a word at a fixed offset from a
named object.

## Regional addresses

| Version | VRAM | ROM | Size |
| --- | --- | --- | --- |
| USA | `0x80038DBC` | `0x399BC` | 60 |
| Japan | `0x8003981C` | `0x3A41C` | 60 |
| Europe | `0x8003D72C` | `0x3E32C` | 60 |
| lrg_rev1 | `0x80038DBC` | `0x399BC` | 60 |

All four bodies are structurally identical; only the data symbol relocates.

- Japan: `D_800D6960` -> `D_800D9BD0`.
- Europe: `D_800D6960` -> `D_800DF600`.
- lrg_rev1: unchanged from USA.

## Recovered behaviour

The routine takes one integer flag. When the flag is non-zero it clears bit
`0x40` of the control word that lives at offset `0x1C` of the global block; when
the flag is zero it sets that same bit. Nothing else is read or written and
there is no return value. Callers use it as a two-state switch, passing 1 to
turn the condition off and 0 to turn it on.

## Status

Exact. Byte-identical in USA, Japan, Europe and lrg_rev1, at 60 bytes.
