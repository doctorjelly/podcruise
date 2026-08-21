# func_8008CAA0

## Boundary

- USA VRAM range: 0x8008CAA0 .. 0x8008CAB8 inclusive (0x1C = 28 bytes, 7
  instructions).
- USA ROM offset: 0x8D6A0.
- Terminates with a return whose delay slot is a no-operation, preceded by two
  further no-operations that cover the control-register hazard.
- Assigned size 28 was correct; no boundary correction. The single word between
  this body and the next function is alignment padding.

## Callers and callees

- Twenty-six direct call sites in the USA build.
- Leaf: no callees.
- Takes one integer argument; returns nothing.

## Globals and access widths

- None in memory. The routine reads and writes a processor control register
  (the system status register).

## Regional addresses

| version  | VRAM       | ROM     |
|----------|------------|---------|
| us       | 0x8008CAA0 | 0x8D6A0 |
| jp       | 0x8008D790 | 0x8E390 |
| eu       | 0x80091FF0 | 0x92BF0 |
| lrg_rev1 | 0x8008CAA0 | 0x8D6A0 |

Each regional body was read independently and is identical to the USA body.

## Recovered behavior

Reopens a critical section. It takes the bit pattern that the matching disable
routine (func_8008CA80) returned, reads the processor status register, sets
those bits back on top of the current value, and writes the register back.
Bits the argument leaves clear are untouched, so restoring a saved value of
zero correctly leaves interrupts masked.

## Status

Skipped. Same reason as func_8008CA80: the body transfers values to and from a
coprocessor 0 control register, which cannot be expressed in C without inline
assembly, and the project rules forbid that. The generated disassembly
independently flags both transfer instructions as handwritten.
