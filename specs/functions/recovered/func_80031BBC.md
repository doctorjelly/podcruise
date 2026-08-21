# func_80031BBC

## Boundary

USA VRAM 0x80031BBC..0x80031BEB (48 bytes, ROM 0x327BC). The final instruction
pair is the return with an empty delay slot; the frame is 0x18 bytes and is
released before the return. Thirteen direct call sites target 0x80031BBC, and
the previous function ends with its own return before the label, so the
assigned boundary is correct.

## Callers

Thirteen direct call sites. The observable argument at those sites is either a
value forwarded unchanged from the caller's own first argument or a byte read
out of an object field (an unsigned byte loaded just before the call), so the
parameter is a small non-negative table index.

## Callees

`func_80031640`, which receives the same index the wrapper was given. That
callee itself accepts a single signed word (it compares it with minus one to
select a "do this for every entry" mode), so the wrapper simply forwards.

## Globals and access widths

- `D_800A290C` - an array of 32-bit words indexed by the argument. One entry is
  written with minus one.

The store is emitted in the call's delay slot, so it happens before the callee
runs.

## Regional addresses

| version  | vram       | rom      | callee       | table        |
|----------|------------|----------|--------------|--------------|
| us       | 0x80031BBC | 0x327BC  | func_80031640| D_800A290C   |
| jp       | 0x8003261C | 0x3321C  | func_800320A0| D_800A567C   |
| eu       | 0x8003517C | 0x35D7C  | func_80034C00| D_800A7F0C   |
| lrg_rev1 | 0x80031BBC | 0x327BC  | func_80031640| D_800A290C   |

Each regional body was read independently; the shape is identical and only the
relocated symbol addresses differ.

## Recovered behaviour

Mark the entry of the parallel word table selected by the index as unused by
writing the minus-one sentinel into it, then run the heavier per-entry reset
routine for that same index.

## Status

Byte-identical to the original in all four builds under the accepted IDO 5.3
`-O2` profile.
