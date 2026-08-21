# func_8005F9CC

## Boundary
USA VRAM 0x8005F9CC-0x8005FA37, ROM 0x605CC, size 108 bytes (27 instructions).
Ends with a return with an empty delay slot. One direct caller. Boundary
confirmed, not corrected.

## Callers / callees
One caller. Calls func_8002FAFC twice (counter reads bracketing the work),
func_80030274, func_800801B8 and func_8005F948.

## Globals and access widths
`D_8011B1E4` is a 32-bit accumulator, read and written once each through a
single materialised address.

## Regional addresses
- Japan: 0x80060534 / ROM 0x061134, accumulator at 0x8011E454, callees
  func_8003055C, func_80030CD4, func_80080E58, func_800604B0.
- Europe: 0x80064EB0 / ROM 0x065AB0, accumulator at 0x80123E84, callees
  func_800330BC, func_80033834, func_80085698, func_80064E2C.
- lrg_rev1: identical to USA addresses.

## Behavior
The routine takes a pointer to a large object. It samples the free-running
counter, then calls func_80030274 with the 32-bit field at offset 0x1B4 of the
object and stores the result in the object's field at offset 0x2C. It samples
the counter a second time and folds the elapsed span into the global
accumulator: the accumulator gains the second sample and loses the first, so
the accumulator ends up carrying the time consumed by the intervening call.
It then calls func_800801B8 with the freshly stored field at 0x2C and the field
at 0x30, and finally calls func_8005F948 with the object itself. No value is
returned.

## Compilation notes
The second counter sample must be taken into its own local; folding the call
directly into the accumulator expression reverses the operand order of the
addition.

## Status
Exact in USA, Japan, Europe and lrg_rev1.
