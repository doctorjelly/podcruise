# func_8008ACD8

## Verified facts

- The USA function spans VRAM `0x8008ACD8` through `0x8008AD73`, ROM
  `0x8B8D8`, 156 bytes. Its `jr ra` is at `0x8008AD6C`; the delay slot restores
  the eight-byte stack frame.
- Two signed 64-bit arguments arrive split across `a0`/`a1` and `a2`/`a3`.
  The signed `ddiv` remainder is returned through `v0`/`v1`.
- The divide-by-zero and minimum-value divided by minus-one `break` sequences
  are compiler-generated traps. There are no callees or global references.
- No direct USA call site was found. Japan maps uniquely to `0x8008B9C8` / ROM
  `0x8C5C8`; Europe maps uniquely to `0x80090228` / ROM `0x90E28`. Both next
  mapped entries are 156 bytes later.

## Behavior

Compute the signed 64-bit remainder. If that nonzero remainder and the divisor
have opposite signs, add the divisor once. The result therefore follows the
divisor's sign, unlike plain C remainder when the dividend and divisor signs
differ.

## Status

Exact. A linked IDO 5.3 comparison with the unit's verified `-O1 -mips3 -32`
flags reproduces all 156 canonical USA bytes. The regional equivalents support
the boundary, but only USA is integrated here.
