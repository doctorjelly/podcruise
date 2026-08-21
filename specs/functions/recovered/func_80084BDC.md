# func_80084BDC

## Boundary
VRAM 0x80084BDC-0x80084C2C (80 bytes), ROM 0x857DC. Ends with the standard
return whose delay slot is empty. Five direct callers all target 0x80084BDC.
Boundary as assigned is correct.

## Callers / callees
5 callers. Calls func_80083190, func_80016CAC, func_80016BF4.

## Globals
None.

## Regional addresses
- jp: 0x800858BC (ROM 0x864BC), callees func_80083E70 / func_80016DDC / func_80016D24
- eu: 0x8008A0BC (ROM 0x8ACBC), callees func_80088670 / func_8001713C / func_80017084
- lrg_rev1: identical to USA

## Behavior
The routine reserves a 64-byte working area on its own stack, large enough for a
four-by-four floating-point transform. It takes five pointer arguments. The
third argument is handed to the transform builder together with the working
area, which fills the area in. The freshly built transform is then applied
twice: once with the first and fourth arguments, and once with the second and
fifth. Nothing is returned; all results are written through the pointers the
caller supplied.

## Status
exact (USA, Japan, Europe, lrg_rev1), default -O2 profile.
