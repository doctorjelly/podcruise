# func_8003F8FC

## Boundary
USA VRAM 0x8003F8FC-0x8003F974 (120 bytes, 30 instructions). Ends with a
return whose delay slot is empty. Boundary confirmed: the single direct caller
targets 0x8003F8FC, and no branch from the preceding function crosses into it.
Boundary not corrected.

## Callers
One direct caller, func_8003F974, which forwards its own first argument, a
fixed 32-bit literal, and its own second argument.

## Callees
func_80018450, called with a constant selector 0xEE06 and the address of the
locally assembled message.

## Globals
None.

## Regional addresses
- Japan: 0x8004028C (ROM 0x040E8C)
- Europe: 0x8004429C (ROM 0x044E9C)
- lrg_rev1: shares the USA address.

## Recovered behavior
The routine assembles a sixteen-word message block in its own stack frame.
The first word is the first argument, the second word is the second argument,
and the remaining fourteen words are copied in order from the fourteen words
beginning at the address given by the third argument. The completed block is
then handed to func_80018450 together with the fixed selector value 0xEE06.
The routine returns nothing and keeps no state.

## Status
behavior. The recovered source produces the identical copy loop and call
sequence, but the compiler places the message block four bytes lower in the
frame and biases the copy cursors by two words, so the frame size and the two
prologue load addresses differ. Eight source-shape experiments (block
assignment, struct form, explicit copy prologue, pointer-walk form, several
padded array sizes) narrowed it to that single placement difference without
closing it. Behavior is certain.
