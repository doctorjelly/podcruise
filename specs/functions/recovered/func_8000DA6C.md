# func_8000DA6C

## Boundary

- USA VRAM range `0x8000DA6C`-`0x8000DA77` inclusive, ROM `0xE66C`, size 12
  bytes (3 instructions).
- The body is a global-address setup, a return, and the load of that global in
  the return's delay slot. The preceding function `func_8000D9B0` ends with its
  own stack teardown and return at `0x8000DA64`, so the assigned entry point is
  a true boundary.
- Leaf function, no frame.

## Callers

Two direct call sites (the same code reachable through two disassembled
segments). The caller stores the returned word into an argument block that it
then hands to a formatting routine, so the result is consumed as a plain 32-bit
integer.

## Callees and globals

- `D_8009B7E4` (USA), read once as a full 32-bit word.

## Parameters

None. Returns a signed 32-bit integer.

## Regional addresses

| Version | VRAM | ROM | Size | Global |
| --- | --- | --- | --- | --- |
| USA | 0x8000DA6C | 0xE66C | 12 | D_8009B7E4 |
| Japan | 0x8000DA6C | 0x00E66C | 12 | D_8009C4D4 |

The Japanese body was read independently: same three instructions, same
structure, with the global relocated to `0x8009C4D4`. No European counterpart
was supplied in the assignment, and the address one would reach by applying the
European code delta used elsewhere in this file holds an unrelated function, so
Europe is deliberately left unverified.

## Recovered behavior

A trivial accessor. It reads one global 32-bit variable and returns its current
value to the caller, with no side effects and no validation.

## Status

Exact. USA and Japan both verify byte-identical.
