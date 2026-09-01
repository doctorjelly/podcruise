# func_8006E2FC

## Verified facts

- The true USA body spans VRAM `0x8006E2FC` through `0x8006E42B`, ROM
  `0x6EEFC`, 304 bytes. The candidate labels at `0x8006E358`, `0x8006E3C0`,
  and `0x8006E3F8` are internal branch targets, not function entries.
- The default arm returns at `0x8006E350`, the mode-zero clamp can return at
  `0x8006E3B8`, mode one returns at `0x8006E3F0`, and the remaining paths share
  the `jr ra` at `0x8006E424`. Every return's delay slot was included: the
  clamp and mode-one slots store the result, while the others are `nop`.
- `func_80055D38` is the sole direct caller. It passes an object, two local
  byte-color buffers, and the address of a float.
- The object reads are a selector at `0x210` and floats at `0x7C`, `0x1A0`, and
  `0x214`. The function has no callees or global references.
- Japan maps uniquely to `0x8006EE6C` / ROM `0x6FA6C`; Europe maps uniquely to
  `0x800737DC` / ROM `0x743DC`. Their next mapped entry is also 304 bytes
  later, supporting the merged USA boundary.

## Behavior

Initialize the first output color to green, the second to opaque white with a
100-byte fourth component, and the scalar output to zero. Three object modes
override those defaults. Mode zero keeps the colors and computes the scalar as
the `0x1A0` value divided by three quarters of the `0x7C` value, clamped to one.
Mode one changes the second color to orange with a 200-byte fourth component
and copies the `0x214` scalar. Mode two makes the first color yellow, selects
the same orange second color, and sets the scalar to one. Other modes retain
the defaults.

## Status

Byte-matching C in canonical USA. An exact linked IDO 5.3 `-O2` comparison
reproduces all 304 bytes. Expressing the mode-one copy as division by `1.0f`
preserves the behavior while causing IDO to materialize the reciprocal and emit
the ROM's multiply, schedule, and floating-point registers. No regional
compiler-match claim is made.
