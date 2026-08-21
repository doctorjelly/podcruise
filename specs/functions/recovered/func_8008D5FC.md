# func_8008D5FC

## Boundary
USA VRAM 0x8008D5FC-0x8008D683 (136 bytes), ROM 0x8E1FC. Ends with a return
whose delay slot is empty. One direct caller targets the entry. Boundary as
assigned is correct.

## Callees
func_80095AA0 (four arguments, two of them the addresses of func_8008EADC and
func_8008E9F0), func_80087FC0 (five arguments, the fifth on the stack).

## Globals
None; the two referenced function addresses are code symbols.

## Regional addresses
- Japan: 0x8008E2EC (ROM 0x08EEEC), with func_8008EADC -> func_8008F7CC,
  func_8008E9F0 -> func_8008F6E0, func_80095AA0 -> func_80096790 and
  func_80087FC0 -> func_80088CB0.
- Europe: 0x80092B4C (ROM 0x09374C), with the corresponding relocations.
- lrg_rev1: identical to USA addresses.

## Behavior
The routine initialises an object supplied by pointer, using a second scalar
argument as a creation parameter.

It first registers the object with a subsystem, supplying two callback routines
and a trailing selector of one. It then creates a resource by calling an
allocator with two zero leading arguments, the caller's scalar parameter, a
selector of one and a size of thirty-two, and stores the returned handle in the
object at byte offset 0x14.

Finally it primes the remaining object fields: the word at 0x24 is set to one,
the words at 0x1C, 0x28, 0x2C and 0x30 are cleared, the single-precision value
at 0x20 is set to zero and the single-precision value at 0x18 is set to one.
The routine returns nothing.

## Compilation note
This unit is an optimisation level three unit: at level two the compiler holds
the object pointer in a callee-saved register, while the original re-reads it
from its incoming home slot. Level three reproduces the original exactly.

## Status
Exact in USA, Japan, Europe and lrg_rev1.
