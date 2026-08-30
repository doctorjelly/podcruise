# func_8005CBD8

## Verified facts

- The USA body spans VRAM `0x8005CBD8` through `0x8005D10B`, ROM `0x5D7D8`,
  1332 bytes. `jr ra` is at `0x8005D104`; its delay slot restores the
  352-byte stack frame. `func_8005D10C` begins next.
- No direct `jal` targets the routine. Its address occurs once in the USA data
  table at ROM `0xA2CA4`, establishing indirect dispatch. Its messaging,
  session, audio, and interface helpers and globals are in the matching unit.
- Japan and Europe equivalents begin at `0x8005D774` and `0x800620BC`.

## Behavior

This message handler sleeps or wakes its owner, initializes and resets a large
session-state record, routes assignment messages through a participant table,
and handles pause or restart requests. A begin message copies race/session
parameters, updates global flags and counters, starts the relevant subsystems,
and selects the next interface state.

## Status

Behavior recovered from the USA binary and independently expressed in C; not
byte-matching. IDO 5.3 `-O2` emits 1328 bytes for the 1332-byte target and first
differs at byte `0x37`; 280 instruction words differ across 13 blocks.
Regional binaries were used only for structural and relocation confirmation.
