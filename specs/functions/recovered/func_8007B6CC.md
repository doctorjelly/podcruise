# func_8007B6CC

## Boundary
USA VRAM 0x8007B6CC-0x8007B744 (120 bytes, 30 instructions). The return's
delay slot restores the stack pointer. Four direct callers all target the
entry. Boundary not corrected.

## Callers
Four direct callers.

## Callees
- func_80006E50, taking an item and a fixed 32-bit mask value 0x10000000.
- func_80006E74, taking an item and a single-precision floating-point value.

## Globals
D_8011C8F0: a table of pointers indexed by the routine's argument; each entry
points at a zero-terminated list of words.

## Regional addresses
- Japan: function 0x8007C36C (ROM 0x07CF6C); table at 0x8011FB60.
- Europe: function 0x80080BAC (ROM 0x0817AC); table at 0x80125590.
- lrg_rev1: shares the USA addresses.

## Recovered behavior
The routine selects a list from the pointer table using its argument as the
index. It then walks that list until it reaches the terminating zero entry.
For every item in the list it makes two calls: the first applies the fixed
mask 0x10000000 to the item, the second sets the item's associated
floating-point quantity to zero. An empty list produces no calls at all. The
routine returns nothing.

## Status
exact. USA, Japan, Europe and lrg_rev1 all verified byte-identical.
