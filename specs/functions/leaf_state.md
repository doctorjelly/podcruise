# Small object and flag leaves

Status: **byte-matching C; integrated into exact USA and LRG rebuilds**.

These original behavioral specifications were derived from the supplied USA,
Japan, and Europe retail binaries. Address-based names remain because the
larger object and subsystem semantics are not established.

## Boundaries and behavior

Every entry is a direct call target, is a leaf, and ends at the listed `jr ra`
plus its executed delay slot. Regional equivalents are unique normalized
matches with the same instruction roles.

| Function | Bytes | USA / Japan / Europe VRAM | Behavior | USA return / delay slot |
|---|---:|---|---|---|
| `func_80006E50` | 16 | `80006E50` / `80006E50` / `80006E50` | Set the selected bits in the word at object offset `0x100`. | `80006E58` / store the result |
| `func_80006E60` | 20 | `80006E60` / `80006E60` / `80006E60` | Clear the selected bits in the word at object offset `0x100`. | `80006E6C` / store the result |
| `func_80006EB4` | 12 | `80006EB4` / `80006EB4` / `80006EB4` | Store the float argument at object offset `0x110`. | `80006EB8` / store the float |
| `func_80006F28` | 12 | `80006F28` / `80006F28` / `80006F28` | Store the float argument at object offset `0xDC`. | `80006F2C` / store the float |
| `func_80009524` | 24 | `80009524` / `80009524` / `80009524` | Return the selected bits from an indexed word. | `80009534` / apply the mask |
| `func_8000953C` | 32 | `8000953C` / `8000953C` / `8000953C` | Set selected bits in an indexed word. | `80009554` / store the result |
| `func_8000955C` | 36 | `8000955C` / `8000955C` / `8000955C` | Clear selected bits in an indexed word. | `80009578` / store the result |
| `func_80011764` | 20 | `80011764` / `80011764` / `80011BF4` | Store two floats in separate adjacent globals, in argument order. | `80011770` / store the second float |
| `func_80011778` | 44 | `80011778` / `80011778` / `80011C08` | Store the low byte of four integer arguments into four consecutive bytes beginning at `D_8009B874`. | `8001179C` / store the fourth byte |
| `func_80011824` | 20 | `80011824` / `80011824` / `80011CB4` | Store a signed word in an indexed word location. | `80011830` / store the word |
| `func_80011928` | 12 | `80011928` / `80011928` / `80011DB8` | Clear one 32-bit global. | `8001192C` / store zero |
| `func_8005EEFC` | 12 | `8005EEFC` / `8005FA64` / `800643E0` | Return one signed 32-bit global without changing memory. | `8005EF00` / load the result |

`func_80011928` is 12 bytes, not the analyzer's provisional 24-byte span: its
store delay slot is followed by three alignment no-ops before the next body.

## Global and caller evidence

| Functions | USA / Japan / Europe global | USA direct callers |
|---|---|---:|
| `func_80009524`, `func_8000953C`, `func_8000955C` | `800D2140` / `800D5390` / `800DADE0` | 19 / 15 / 12 |
| `func_80011764` | `8009B878` / `8009C568` / `800A0DC8` | 10 |
| `func_80011778` | `8009B874` / `8009C564` / `800A0DC4` | 2 |
| `func_80011824` | `800D6140` / `800D9390` / `800DEDE0` | 2 |
| `func_80011928` | `8009B810` / `8009C500` / `800A0D60` | 1 |
| `func_8005EEFC` | `8011AC8C` / `8011DEFC` / `8012392C` | 1 |

The four object-relative functions have 5, 6, 16, and 1 direct USA callers,
respectively. Caller argument setup agrees with masks for the flag routines,
floating-point registers for the float stores, and word indices/values for the
indexed routines. None of these functions has a callee.

## Facts, inferences, and matching status

The boundaries, delay slots, access widths, offsets, call sites, and regional
relocations are observed facts. Treating the first argument of the four
object-relative routines as the same broader structure is an inference; its
identity is deliberately unnamed.

The independently expressed C matches all 260 canonical USA bytes under IDO
5.3 `-O2`, as established by exact compiler comparison. These are therefore
byte-matching C, not merely behavior-recovered candidates. Independent
same-address comparison proves the LRG bytes too, and the functions are
included in both byte-identical rebuilds.
