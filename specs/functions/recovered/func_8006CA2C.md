# func_8006CA2C

## Verified facts

- The USA body spans VRAM `0x8006CA2C` through `0x8006D0BF`, ROM `0x6D62C`,
  1684 bytes. `jr ra` is at `0x8006D0B8` with a nop delay slot;
  `func_8006D0C0` begins next.
- Direct callers are `func_8006E6F8` and `func_8006FB00`. The collision,
  random-selection, audio, effect, and response helpers and globals are listed
  in its matching unit.
- Japan and Europe equivalents begin at `0x8006D59C` and `0x80071F0C`.

## Behavior

The routine updates six collision or impact channels and their cooldowns. It
selects the strongest active hit, probabilistically triggers effects and audio,
determines whether the impact is toward the vehicle's front or rear, and sends
that result to `func_80070764`.

## Status

Behavior recovered from the USA binary and independently expressed in C; not
byte-matching. IDO 5.3 `-O2` emits the exact 1684-byte body and first differs at
byte `0x49`; 84 instruction words differ across 40 blocks. Regional binaries
were used only for structural and relocation confirmation.
