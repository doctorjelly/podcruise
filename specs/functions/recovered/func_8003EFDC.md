# func_8003EFDC

## Boundary
USA VRAM 0x8003EFDC-0x8003F083 (0xA8 = 168 bytes), ROM 0x3FBDC.
0x28-byte frame; the body ends with a return whose delay slot is empty. Both
arms of the internal branch converge on the shared epilogue at 0x8003F078 and
neither leaves the range. Ten direct call sites all target 0x8003EFDC.

## Callers / callees
Ten direct callers; every inspected site writes four words into the outgoing
argument area (offsets 0x10 through 0x1C), which fixes the eight-argument
signature, and none of them reads the return register afterwards.

Calls `func_8003F1C0` once on each arm with the same eight-argument shape. Note
that `func_8003F1C0` is itself mis-split by the label scan: the call target is
0x8003F1C0 but its stack adjustment does not appear until 0x8003F1D8, so the six
instructions in between belong to it. That is a note for whoever recovers the
callee, not a correction to this function's own boundary.

## Argument shape
| position | width | evidence |
| -------- | ----- | -------- |
| 1 | s16 | homed, then sign-extended through a 16-bit shift pair |
| 2 | s16 | same |
| 3 | f32 | arrives in an integer register and is round-tripped through the FPU |
| 4 | u8 | homed, then masked to eight bits and moved back |
| 5 | u8 | read back from its incoming stack slot as a single unsigned byte |
| 6 | u8 | same |
| 7 | u8 | same |
| 8 | word | read once from its incoming stack slot and tested against zero |

## Globals
`D_800AAB44` and `D_800AAB4C`. Neither is dereferenced here; the address of one
or the other is computed and passed on as the callee's eighth argument.

## Regional addresses
- JP 0x8003F95C, ROM 0x4055C; the callee moves to 0x8003FB44 and the two data
  addresses to 0x800ADBF4 and 0x800ADBFC. The body is the same 168 bytes and was
  read instruction by instruction.
- lrg_rev1 shares the USA addresses and the USA symbol addresses.
- EU is structurally different and is deliberately excluded. The corresponding
  body is at 0x8004391C, ROM 0x4451C, and is 264 bytes: on each arm it reads a
  further global selector and chooses between three data addresses rather than
  one, which is the multi-language build of the same routine. It cannot be
  produced from this source and needs its own recovery.

## Recovered behavior
This is a two-way dispatcher in front of a single worker routine. All seven
payload arguments - a pair of signed 16-bit coordinates, a floating point
value and four unsigned byte channels - are forwarded untouched. The last
argument is a flag that selects which of two fixed data blocks the worker should
operate against: the first when the flag is set, the second when it is clear.
The worker is then called once, and this function returns nothing of its own.

## Notes on shape
No shape experiments were needed; a straight `if`/`else` over the flag with the
two calls written out in full matched on the first attempt. The parameter widths
are the whole content of the match: the two sign-extensions, the byte mask on
the fourth argument and the three byte reloads from the incoming stack slots all
follow directly from declaring them `s16`, `u8` and `u8` rather than `s32`.

## Status
exact - USA, JP and lrg_rev1 verified byte-identical. EU excluded: structurally
different body.
