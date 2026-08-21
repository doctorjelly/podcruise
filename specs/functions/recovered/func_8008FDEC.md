# func_8008FDEC

## Boundary
- USA VRAM 0x8008FDEC .. 0x8008FE5F (116 bytes), ROM 0x909EC.
- Terminates with the return jump at 0x8008FE58 and the frame release in its
  delay slot at 0x8008FE5C. Assigned boundary confirmed correct.
- One direct caller targeting 0x8008FDEC. The two interior labels are the loop
  head and the loop exit, both reached only by branches from inside the body.

## Callers
- One call site.

## Callees
- func_80088050 (USA 0x80088050), called once per element with the element
  pointer first and the accumulator pointer second.

## Globals
- None.

## Regional addresses
| version  | vram       | rom      | size | callee                |
|----------|------------|----------|------|-----------------------|
| us       | 0x8008FDEC | 0x909EC  | 116  | func_80088050         |
| jp       | 0x80090ADC | 0x916DC  | 116  | func_80088D40         |
| eu       | 0x8009533C | 0x95F3C  | 116  | func_8008D5A0         |
| lrg_rev1 | 0x8008FDEC | 0x909EC  | 116  | func_80088050         |

All four bodies were read independently and match instruction for instruction
apart from the relocated call target.

## Recovered behaviour
Resets an accumulator and folds an array into it.

1. Clears five consecutive 32-bit words at the start of the accumulator object
   named by the first parameter. They are cleared with integer stores, so these
   are counters, flags or pointers rather than floats (a float zero would be
   moved through a floating-point register first).
2. If the element count in the third parameter is zero or negative, returns
   immediately.
3. Otherwise walks the array named by the second parameter, exactly `count`
   times, and calls func_80088050 once per element with that element and the
   accumulator. The array stride is 28 bytes, so its element type is a 28-byte
   record; the walk is a straight pointer advance of 28 bytes per iteration
   while a separate counter runs from zero up to the count.

The count is a signed 32-bit value; the guard is a signed "less than or equal to
zero" test, so a negative count is treated as empty rather than wrapping.

## Source shape notes
The five clearing stores are emitted in the order word 4, word 2, word 3,
word 0, word 1. Writing them as five plain statements in ascending order gives
ascending stores and misses at offset 0x0C of the body. The original order falls
out of grouping them as one lone assignment followed by two chained assignments:
clear word 4, then `w2 = w3 = 0`, then `w0 = w1 = 0`. IDO emits a chained
assignment's leftmost target first, so `w2 = w3 = 0` produces the 0x08 store
before the 0x0C store; writing the chain the other way round inverts both pairs.
That single change took the body from a first difference at 0x0C to an exact
match; nothing else in the routine needed tuning.

The loop counter is a separate local, never the parameter, and the element
pointer advances rather than being recomputed from an index.

## Status
Exact in USA after three source-shape experiments (ascending stores, chain
written right-to-left, chain written left-to-right), and exact in Japan, Europe
and lrg_rev1.
