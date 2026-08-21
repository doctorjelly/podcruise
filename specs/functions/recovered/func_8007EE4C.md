# func_8007EE4C

## Boundary
USA VRAM 0x8007EE4C..0x8007EE97 inclusive (76 bytes, 19 instructions), ROM
0x7FA4C. The final instruction pair is the return jump with an empty delay
slot; all four direct call sites target 0x8007EE4C, and the first executed
instruction is the frame adjustment, so the assigned boundary is correct.

## Callers
Four call sites (0x8007F450, 0x8007F5B0, 0x8007FE48, 0x80080E24). Every one
passes the address of a caller stack object as the first argument and a pointer
to an already-existing object as the second, then keeps the returned pointer in
a local or on the stack. The returned value is therefore the same pointer that
was passed in as the first argument.

## Callees
`func_8003B250`, called with the object being initialised and a zero second
argument. That callee treats its second argument as a record index (it scales
it by 0x54) and writes four consecutive words in the object, which confirms the
second argument is an integer index and not a pointer.

## Globals and access widths
None.

## Object layout used
The initialised object holds a pointer at 0x00, three single-precision floats
at 0x04, 0x08 and 0x0C, and four 32-bit words at 0x20, 0x24, 0x28 and 0x2C.
Offsets 0x10 through 0x1C are written by the callee, not here.

## Regional addresses
* JP 0x8007FAEC (ROM 0x806EC); helper at 0x8003BBD0.
* EU 0x8008432C (ROM 0x84F2C); helper at 0x8003FB90.
* lrg_rev1 shares the USA addresses.
Each regional body was read directly and matches the USA shape exactly apart
from the relocated call target.

## Recovered behavior
This is the constructor for a playback object. It records the supplied source
object in the first field, clears the four integer status words at 0x20-0x2C,
clears the three floating-point fields at 0x04-0x0C to zero, asks
`func_8003B250` to select record zero of the source, and finally returns the
object it just initialised so callers can chain from it.

## Notes on shape
The two zero stores at 0x08 and 0x0C are emitted in the order 0x0C then 0x08;
writing the source in that order is what reproduces the original scheduling.

## Status
Exact on USA, JP, EU and lrg_rev1 with the accepted `ido53_o2` profile.
