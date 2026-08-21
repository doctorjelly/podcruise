# func_8003ECB0

## Boundary
- USA VRAM 0x8003ECB0 - 0x8003ED13 inclusive, ROM 0x3F8B0, size 100 bytes
  (25 instructions).
- The previous function ends with its own return and empty delay slot two
  instructions earlier; no branch from it reaches into this label. This body
  ends with the return instruction plus an empty delay slot, and every direct
  call site targets 0x8003ECB0. Boundary as assigned is correct.

## Callers
53 direct call sites in the USA build - it is the plain, default-styled entry
point to the general text-queueing routine.

## Callees
- `func_8003EA84` (0x8003EA84) - the nine-argument text-queueing routine. Its
  own prologue shows the widths of its parameters: the first two are read back
  as 16-bit signed values, the next four as unsigned bytes, then a pointer, a
  signed 32-bit value and a signed 32-bit selector.

## Globals and access widths
None. The routine touches no global storage of its own.

## Regional addresses
| version   | entry      | ROM     | queueing routine |
|-----------|------------|---------|------------------|
| usa       | 0x8003ECB0 | 0x3F8B0 | 0x8003EA84       |
| japan     | 0x8003F630 | 0x40230 | 0x8003F404       |
| europe    | 0x800435F0 | 0x441F0 | 0x800433C4       |
| lrg_rev1  | 0x8003ECB0 | 0x3F8B0 | 0x8003EA84       |

Each regional body was read independently; all four are the same instruction
sequence, differing only in the call target.

## Recovered behavior
This is a convenience wrapper that queues a run of text for drawing at a given
screen position using the default appearance. It accepts a horizontal
position, a vertical position and the address of the text itself, and forwards
all three to the general queueing routine while filling in the remaining
arguments with fixed values: fully opaque white for the four colour channels,
a length limit of minus one meaning "draw the whole string", and a selector of
zero meaning the primary of the two text queues the general routine maintains.

The two coordinates are narrowed to 16-bit signed values on the way through,
matching the width the queueing routine reads them back at, so callers may
pass wider values and have them wrap consistently.

## Status
Exact in usa, japan, europe and lrg_rev1 under the accepted `ido53_o2`
profile; no per-unit compiler flags were needed.
