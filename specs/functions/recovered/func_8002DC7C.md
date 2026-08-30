# func_8002DC7C

## Boundary

- USA VRAM `0x8002DC7C` through `0x8002DCF3`, ROM `0x2E87C`, 120 bytes.
- Analyzer labels at `0x8002DCA8` and `0x8002DCE8` are internal branch
  targets. The body has returns at `0x8002DCA0`, `0x8002DCE0`, and
  `0x8002DCEC`; each following delay slot belongs to this function.
- The next independent prologue begins at `0x8002DCF4`.

## References

The direct USA caller at `0x80025274` passes one object pointer and tests the
returned word. The function is a leaf. It reads a signed byte at object offset
`0x6C`, the flag word `D_80113688`, and four signed halfwords at offsets
`0x0C` through `0x12` in `D_80113E60`.

## Behavior

When the object's mode byte is zero, returns true exactly when bit `0x20` is
set in the global flag word. For a nonzero mode, it instead returns true only
when the four global halfwords equal `0x3FFF`, `0x3FFF`, `0x3FFF`, and
`0x00FF`, respectively. Every failed test returns false.

## Status

Behavior recovered, not byte-matching. IDO 5.3 emits the correct 120-byte body
and matches every instruction after the initial global-address setup. The
first difference is at byte offset `0x8`: the recovered build places the flag
global's `lui` before the mode branch and the value-block `addiu` in its delay
slot, while the original schedules those two independent instructions in the
opposite order. No exact claim is made.
