# Object accessor leaves

Status: **byte-matching C; integrated into exact USA and LRG rebuilds**.

These specifications are original descriptions derived from the supplied USA,
Japan, and Europe binaries. The surrounding object identity is not yet proven,
so address-based function names and offset-based field descriptions remain.

## Boundaries, delay slots, and behavior

Every listed USA start is a direct `jal` target and follows a complete preceding
return. Each body is a leaf. Japan and Europe contain a unique normalized match
with the same control flow, access widths, and return/delay-slot roles.

| Function | Bytes | Behavior | USA terminal return / delay slot |
|---|---:|---|---|
| `func_80017D48` | 8 | Store a word at object offset `0x1C`. | `80017D48` / store the word |
| `func_80017D58` | 40 | For indices zero through seven, store a float in the array beginning at offset `0x1C`; otherwise do nothing. | `80017D78` / no operation |
| `func_80017DA4` | 8 | Return the word at offset `0x00`. | `80017DA4` / load the word |
| `func_80017DAC` | 8 | Return the word at offset `0x14`. | `80017DAC` / load the word |
| `func_80017DDC` | 8 | Return the signed halfword at offset `0x20`. | `80017DDC` / load the halfword |
| `func_80017DE4` | 8 | Return the signed halfword at offset `0x22`. | `80017DE4` / load the halfword |
| `func_80017DEC` | 8 | Return the word at offset `0x24`. | `80017DEC` / load the word |
| `func_80017DF4` | 44 | If mode is zero, copy offsets `0x2C` and `0x28` to the two outputs; otherwise clear both outputs. | `80017E08` or `80017E18` / final store or no operation |
| `func_80017E20` | 52 | Copy six floats from offsets `0x08` through `0x1C` to a packed output array. | `80017E4C` / store the sixth float |
| `func_80017E54` | 8 | Return the word at offset `0x14`. | `80017E54` / load the word |
| `func_80017E5C` | 20 | Read the pointer at offset `0x18` and return one indexed word. | `80017E68` / load the word |
| `func_80017E70` | 24 | Store a word at offset `0x08` only when the selector equals two. | `80017E80` / no operation |
| `func_80017EDC` | 8 | Return the word at offset `0x00`. | `80017EDC` / load the word |
| `func_80017EE4` | 8 | Return the word at offset `0x04`. | `80017EE4` / load the word |
| `func_80017EEC` | 8 | Store a word at offset `0x04`. | `80017EEC` / store the word |
| `func_80017EF4` | 8 | Return the word at offset `0x00`. | `80017EF4` / load the word |
| `func_80017F20` | 8 | Return the constant four. | `80017F20` / form the result |

The provisional analyzer split `func_80017DF4` at `0x80017E10`. That address
has no direct caller and is an internal/shared tail: both later stores and the
second return belong to the function, making its verified span 44 bytes.

## Callers and regional evidence

| Function | USA direct callers | Japan / Europe VRAM |
|---|---:|---|
| `func_80017D48` | 5 | `80017E78` / `800181D8` |
| `func_80017D58` | 3 | `80017E88` / `800181E8` |
| `func_80017DA4` | 26 | `80017ED4` / `80018234` |
| `func_80017DAC` | 31 | `80017EDC` / `8001823C` |
| `func_80017DDC` | 1 | `80017F0C` / `8001826C` |
| `func_80017DE4` | 1 | `80017F14` / `80018274` |
| `func_80017DEC` | 2 | `80017F1C` / `8001827C` |
| `func_80017DF4` | 1 | `80017F24` / `80018284` |
| `func_80017E20` | 1 | `80017F50` / `800182B0` |
| `func_80017E54` | 3 | `80017F84` / `800182E4` |
| `func_80017E5C` | 1 | `80017F8C` / `800182EC` |
| `func_80017E70` | 1 | `80017FA0` / `80018300` |
| `func_80017EDC` | 2 | `8001800C` / `8001836C` |
| `func_80017EE4` | 7 | `80018014` / `80018374` |
| `func_80017EEC` | 1 | `8001801C` / `8001837C` |
| `func_80017EF4` | 5 | `80018024` / `80018384` |
| `func_80017F20` | 6 | `80018050` / `800183B0` |

Caller setup confirms floating-point argument registers for `func_80017D58`,
stack output addresses for `func_80017DF4`, a packed float destination for
`func_80017E20`, selector value two for `func_80017E70`, and integer/index uses
for the word accessors. No listed body has a callee.

## Facts and inferences

Observed facts are the entry points, return paths, delay slots, field offsets,
access widths, direct callers, and regional instruction-shape agreement. The
signed halfword return types follow directly from `lh`. Treating the offset
patterns as one or more C structures is an inference; no structure name or
field semantics is claimed yet.

The independently expressed C matches all 276 canonical USA bytes under IDO
5.3 `-O2`, including each return path and delay slot. It is therefore
byte-matching C. The same-address LRG functions independently match as well;
the C is substituted into both byte-identical rebuilds.
