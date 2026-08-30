# func_8008AAE0

## Verified facts

- The canonical USA body spans VRAM `0x8008AAE0` through `0x8008AB0B`, ROM
  `0x8B6E0`, 44 bytes. It follows 96 bytes of zero padding and ends immediately
  before `func_8008AB0C`.
- The return is at `0x8008AB04`; its delay slot completes the o32 64-bit return
  representation. The function has no direct callers, callees, or globals.
- Byte searches locate the identical leaf at Japan VRAM `0x8008B7D0`, ROM
  `0x8C3D0`, and Europe VRAM `0x80090030`, ROM `0x90C30`.

## Behavior

The function accepts an unsigned 64-bit value and an unsigned 64-bit shift
count and returns the value shifted right by that count. Argument stores and
reloads implement the o32 calling convention; the operation itself uses the
MIPS III variable-width logical shift.

## Status

Byte-matching C for canonical USA. The independent one-expression function
compiles with IDO 5.3 using `-O2 -mips3 -32` to all 44 original bytes exactly.
The integrated canonical round trip reproduced SHA-1
`3542d5597c8a56ea8f5c63bceae97a24c4c08d58`.
