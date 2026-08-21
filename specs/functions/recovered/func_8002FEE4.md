# func_8002FEE4

## Boundary
VRAM 0x8002FEE4-0x8002FF38 (84 bytes), ROM 0x30AE4. Frame 0x20, return
sequence with an empty delay slot. Single direct caller targets the entry.

## Callers / callees
1 caller. Calls func_8002FC58, then conditionally func_8002FAFC and
func_8002FAC4.

## Globals
None.

## Regional addresses
- jp: 0x80030944 (ROM 0x31544); callees func_800306B8, func_8003055C, func_80030524
- eu: 0x800334A4 (ROM 0x340A4); callees func_80033218, func_800330BC, func_80033084
- lrg_rev1: identical to USA

## Behavior
Given a byte count, the routine first asks a query routine for the currently
available amount and compares the request against it as an unsigned quantity.
If the request is not strictly smaller than what is available it fails and
returns a null pointer without any further effect. Otherwise it obtains the
current allocation cursor, advances the cursor by the requested count via the
setter routine, and returns the cursor value it obtained before the advance —
that is, the base of the region just handed out. This is a simple bump
allocator carve-off.

## Status
exact in usa, jp, eu and lrg_rev1.
