# func_8006D9DC

## Boundary

- USA VRAM range: 0x8006D9DC .. 0x8006DB18 inclusive (0x140 = 320 bytes, 80 instructions).
- USA ROM offset: 0x6E5DC.
- No stack frame; ends with a return whose delay slot is empty. Every exit path
  branches to that single return. Assigned size 320 was correct; no boundary
  correction.

## Callers and callees

- Ten direct call sites in the USA build (five distinct callers). Two arguments:
  a pointer to a large per-object state block, and a float target that callers
  pass as one, minus one or zero. No return value.
- Leaf function; no callees.

## Globals and access widths

- `D_800AD6A4` — one 32-bit float, read on the rising path. Rate of increase.
- `D_800AD6A8` — one 32-bit float, read on the falling path. Rate of decrease.
- `D_800AD6B0` — one 64-bit float, read once. Snap threshold.
- `D_80120BF0` — one 64-bit float, read on both rate paths and explicitly
  narrowed to single precision before use. It behaves as a frame time step.

State block accesses, both 32-bit floats:

- offset 0x1A0 — a speed-like quantity, read only, compared against 200.
- offset 0x208 — the value this routine drives, read and written.

## Regional addresses

Body is instruction-for-instruction identical in every version; only the four
globals move.

| version  | VRAM       | ROM     | rise       | fall       | threshold  | time step  |
|----------|------------|---------|------------|------------|------------|------------|
| us       | 0x8006D9DC | 0x6E5DC | D_800AD6A4 | D_800AD6A8 | D_800AD6B0 | D_80120BF0 |
| jp       | 0x8006E54C | 0x6F14C | D_800B08E4 | D_800B08E8 | D_800B08F0 | D_80123E60 |
| eu       | 0x80072EBC | 0x73ABC | D_800B6304 | D_800B6308 | D_800B6310 | D_80129890 |
| lrg_rev1 | 0x8006D9DC | 0x6E5DC | D_800AD6A4 | D_800AD6A8 | D_800AD6B0 | D_80120BF0 |

## Recovered behavior

Eases the object's steering-like value at offset 0x208 towards a requested
target, one frame's worth at a time.

The requested target is overridden to zero whenever the object's speed quantity
at offset 0x1A0 is below 200, so a slow object is always driven back to neutral
regardless of what the caller asked for.

If the current value is below the target it is increased by the rise rate scaled
by the frame time step, and clamped so it cannot overshoot above the target. If
it is above the target it is decreased by the fall rate scaled by the same time
step, and clamped so it cannot overshoot below the target. If it already equals
the target neither branch runs.

Finally, when the target is neutral, a dead-zone rule applies: if the magnitude
of the resulting value is smaller than the threshold constant, the value is
halved. This pulls a nearly centred value towards zero faster than the plain
decay would, without ever snapping it exactly to zero.

Source-shape notes established by matching:

- The requested target is overwritten in place rather than copied into a local;
  the original writes zero straight into the incoming argument register.
- Both rate expressions narrow the time step to single precision before
  multiplying, so the whole product stays single precision. Leaving it as a
  double would widen the rate and the running value too.
- The value at offset 0x208 is re-read from memory after each update for the
  clamp test, which is the ordinary shape when the update and the test are
  written as separate statements against the same member.
- The neutral test and the halving are double-precision: the target is compared
  against a plain double zero, and the halving multiplies by a double one-half,
  narrowing the result back on the store.
- The magnitude is computed inline as a conditional negation rather than through
  an absolute-value operation.

## Status

Exact. Byte-identical in USA, Japan, Europe and the large-cartridge revision.
