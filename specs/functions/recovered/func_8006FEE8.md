# func_8006FEE8

## Verified facts

- The USA C body spans VRAM `0x8006FEE8` through `0x8007039B`, ROM `0x70AE8`,
  1204 bytes. `jr ra` is at `0x80070394`; its delay slot restores the 416-byte
  frame. The word at `0x8007039C` is alignment padding, not part of the
  function, and `func_800703A0` begins next. The heuristic 1208-byte candidate
  therefore overstates the function boundary by four bytes.
- No direct USA `jal` targets the entry; one aligned code pointer supports
  indirect dispatch. The body calls the ten helpers recorded in its matching
  unit and reads frame time from `D_80120BF0`.
- JP and EU equivalents begin at `0x80070A58` and `0x800753C8`.

## Behavior

This per-frame object update manages several state and collision flags, runs a
nearby-object query for a high-speed condition, updates timers and sampled
height, restores position from a transform when requested, then invokes the
remaining motion/state helpers in order. It also prepares a transient report
when the object's special-state bit is set.

## Status

Behavior recovered, not byte-matching. Against the corrected 1204-byte body,
IDO 5.3 `-O2` emits the exact length and differs in five instruction words,
starting at byte `0x177`: three use a different spill slot and two reverse the
floating-point operand registers. Three bounded layout variants regressed or
failed to improve the comparison.
