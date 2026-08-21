# func_8007BDF4

## Boundary
USA VRAM 0x8007BDF4-0x8007BE68 (116 bytes, ROM 0x7C9F4). Terminates with a
return whose delay slot is empty. Two direct call sites, both passing a single
pointer; boundary confirmed correct.

## Callers / callees
Callers: func_8007BE?? state dispatch sites at 0x8007BF1C and 0x8007C008.
Callees: func_8003FA24 (three arguments), func_8003FD7C (one argument).

## Globals
None. Two literal four-character tags are built inline: 0x5368616B and
0x634D616E.

## Regional addresses
- jp 0x8007CA94 (ROM 0x7D694); callees relocate to 0x800403B4 / 0x8004070C
- eu 0x800812D4 (ROM 0x81ED4); callees relocate to 0x800443C4 / 0x8004471C
- lrg_rev1 shares the USA addresses

## Behavior
Takes one object pointer. Reads the single-precision field at offset 0x10 of
the object and does nothing unless it exceeds 4.0.

When it does, the routine fills a small on-stack request record: a
four-character identifier tag followed by two single-precision values, both
set to zero. It then hands that record to the general dispatch routine along
with a second four-character identifier naming the destination, and the object
itself as the third argument.

Afterwards it clears the lowest bit of the object's flag word at offset 0x0C
and calls a follow-up routine with the object.

The stack frame reserves twenty-four bytes of local space although only twelve
are written; the request record therefore sits eight bytes above the base of
the local area. This is modelled as a larger enclosing record whose middle
member is the part that is filled in and whose address is what gets passed.

## Status
Exact in USA, Japan, Europe and lrg_rev1.
