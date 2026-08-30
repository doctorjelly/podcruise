# func_8006DB1C

## Verified facts

- The USA body spans VRAM `0x8006DB1C` through `0x8006E007`, ROM `0x6E71C`,
  1260 bytes. `jr ra` is at `0x8006E000` with a nop delay slot;
  `func_8006E008` begins next.
- Its direct caller is `func_8006FA08`. Its timing/random helpers and the
  tuning constants it reads are recorded in its matching unit.
- Japan and Europe equivalents begin at `0x8006E68C` and `0x80072FFC`.

## Behavior

The routine derives a target scalar for a vehicle from mode flags, motion
values, timing, and a slowly changing randomized index. It clamps exceptional
states, keeps that index within a small range around its reference, and then
moves the current scalar toward the target with separate rise and fall rates.

## Status

Behavior recovered from the USA binary and independently expressed in C; not
byte-matching. IDO 5.3 `-O2` emits the exact 1260-byte length and first differs
at byte `0x1B`; 251 instruction words differ across 15 blocks. Regional
binaries were used only for structural and relocation confirmation.
