# func_8003EDD4

## Boundary
- USA VRAM 0x8003EDD4 .. 0x8003EE47 (116 bytes), ROM 0x3F9D4.
- Terminates with the return jump at 0x8003EE40 and an empty delay slot at
  0x8003EE44. Assigned boundary confirmed correct.
- One direct caller, which targets 0x8003EDD4; the first instruction is the
  frame adjustment and nothing precedes it.

## Callers
- One call site (USA 0x8000E36C). It fills three outgoing stack slots before the
  call, confirming that the routine takes seven parameters, four in registers
  and three on the stack.

## Callees
- func_8003EA84 (USA 0x8003EA84), called with nine arguments.

## Globals
- None.

## Parameter widths (evidence)
- Parameters one and two are sign-extended from 16 bits on entry, so both are
  signed 16-bit.
- Parameters three and four are masked to 8 bits on entry, so both are unsigned
  8-bit.
- Parameters five and six are re-read from the low byte of their incoming stack
  slots with an unsigned byte load, so both are unsigned 8-bit as well.
- Parameter seven is read as a full 32-bit word and forwarded unchanged; it is a
  pointer or 32-bit integer.

## Regional addresses
| version  | vram       | rom      | size | callee                |
|----------|------------|----------|------|-----------------------|
| us       | 0x8003EDD4 | 0x3F9D4  | 116  | func_8003EA84         |
| jp       | 0x8003F754 | 0x40354  | 116  | func_8003F404         |
| eu       | 0x80043714 | 0x44314  | 116  | func_800433C4         |
| lrg_rev1 | 0x8003EDD4 | 0x3F9D4  | 116  | func_8003EA84         |

All four bodies were read independently and match instruction for instruction
apart from the relocated call target.

## Recovered behaviour
A thin adapter. It forwards all seven of its parameters, in order and unchanged,
to func_8003EA84 and appends two constants: -1 as the eighth argument and 1 as
the ninth. The two trailing constants are what the wrapper exists to supply, so
callers that want the default pair can use the short form.

Nothing is computed, no result is inspected, and the return value of the callee
is simply left in place.

## Source shape notes
The whole 116-byte body is the compiler's argument marshalling: the four
register parameters are homed, narrowed to their declared widths and moved back
into place, the three stack parameters are reloaded and re-stored into the
outgoing area, and the two literals are materialised. Declaring the parameters
with the widths listed above and writing a single forwarding call reproduces it
byte for byte.

## Status
Exact in USA on the first attempt, and exact in Japan, Europe and lrg_rev1.
