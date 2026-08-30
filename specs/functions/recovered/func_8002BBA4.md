# func_8002BBA4

## Boundary and interface

The canonical USA function occupies ROM `0x2C7A4` / VRAM `0x8002BBA4`
through the `nop` return delay slot at `0x8002C77C`, exactly `0xBDC` (3,036)
bytes. The next routine begins at `0x8002C780`. Unique structural matches place
the corresponding entry at Japan `0x8002C620` and Europe `0x8002EB8C`; they are
used only as relocation evidence.

Six recovered callers agree on seven arguments: a menu/context pointer, X and
Y positions, a row spacing, the active item index, this label's item index,
and a label pointer. The context fields read here are words at offsets `0x08`
and `0x10` plus a signed byte at `0x6C`.

The routine calls `func_80014CC0`, `func_80015630`, `func_80082BE0`,
`func_80015268`, `func_8000AB24`, and `func_8003EC40`. It reads four
three-float color records at `D_800A2624` through `D_800A2648`, an animation
phase at `D_800A4B54`, and the auxiliary label at `D_800A987C`.

## Behavior

Copy the four color records into locals. When the active and label indices are
equal, convert the animation phase to an angle, derive one trigonometric
component, and blend the primary color between the third and fourth records.
For context state 9/substate 3, replace the primary color with three random
components in the range produced by `random / 2^31 * 129 + 64`, and replace
the secondary color with `(25, 128, 128)`.

For context state 9/substate 0, when the context byte is nonzero and both item
indices are four, first draw the auxiliary label thirty pixels left of the
requested X position. Its Y position is the row spacing times the label index
plus the base Y.

For context state 3/substate 1, selected item zero updates object color `0x7F`
and selected item one updates object color `0x80`, both from the primary color
with full alpha. Finally draw the caller's label at the requested X and derived
Y. Use the primary RGB vector for a selected label and the secondary vector
otherwise; all drawn and stored components are converted to unsigned bytes and
alpha is 255.

## Status

Behavior recovered from the canonical USA body and independently expressed in
C. IDO 5.3 `-O2 -mips2` emits the same 3,036-byte length at the canonical
address but first differs at byte `0x3` because its stack frame and local
placement differ. It is not byte-matching and is not eligible for hybrid-build
substitution.
