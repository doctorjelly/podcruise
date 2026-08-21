# Runtime leaf tranche

Status: **14 byte-matching C functions integrated into all four unique builds;
one additional function is behavior-recovered only**.

These descriptions were independently derived from the supplied USA, Japan,
Europe, and LRG binaries. All 15 entries are direct `jal` targets, follow a
complete preceding return, contain no call instruction, and end at the next
established entry. Address-based names remain because subsystem identities are
not yet proven.

## Boundaries, delay slots, and behavior

| Function | Bytes | Compact behavioral specification | USA return / executed delay slot | Status |
|---|---:|---|---|---|
| `func_8002DFB0` | 12 | Accept two words and return without changing game state. | `8002DFB4` / home the second argument at incoming stack offset four | byte-matching |
| `func_8002E028` | 12 | Clear one 32-bit global. | `8002E02C` / perform the clear | byte-matching |
| `func_8002E0A8` | 12 | Clear a neighboring 32-bit global. | `8002E0AC` / perform the clear | byte-matching |
| `func_8002F054` | 12 | Return one 32-bit global. | `8002F058` / load the return value | byte-matching |
| `func_8002F060` | 12 | Return one single-precision global. | `8002F064` / load the floating-point return value | byte-matching |
| `func_8002F1CC` | 24 | Clear a word global and set the neighboring byte global to one. | `8002F1DC` / perform the byte store | byte-matching |
| `func_80031BEC` | 24 | Set the indexed word in a global array to one. | `80031BFC` / perform the indexed store | byte-matching |
| `func_80031F94` | 16 | Follow a global pointer and clear its word at offset four. | `80031F9C` / perform the clear | byte-matching |
| `func_8003D488` | 20 | Zero-extend the 16-bit argument and store it in a 32-bit global. | `8003D494` / perform the store | byte-matching |
| `func_80073708` | 12 | Consume one pointer-shaped argument and return zero. | `8007370C` / place zero in the integer return register | byte-matching |
| `func_8007F22C` | 16 | Ignore the first argument, clear the word addressed by the second, and return zero. | `8007F234` / place zero in the return register | byte-matching |
| `func_8007F23C` | 16 | Perform the same operation as `func_8007F22C` for a separate call path. | `8007F244` / place zero in the return register | byte-matching |
| `func_80080350` | 12 | Consume one pointer-shaped argument and return floating-point zero. | `80080354` / home the argument at incoming stack offset zero | byte-matching |
| `func_800834DC` | 20 | Accept four words and return without changing game state. | `800834E8` / home the fourth argument at incoming stack offset twelve | byte-matching |
| `func_8008D274` | 16 | Return the pointer currently held in a slot, then replace the slot with that pointer's first pointer field. | `8008D27C` / update the slot | behavior-recovered only |

## Call and global evidence

A complete USA `jal` scan found 19 direct calls to `func_8002DFB0`, 16 to
`func_8002F054`, 12 to `func_8002F060`, and seven to `func_8008D274`. The
remaining functions have one or two direct callers each. None of the 15 bodies
has a callee.

Caller setup supplies the concrete type evidence used in the prototypes:

- `func_80031BEC` receives an unsigned-byte field as its array index at
  `0x80054388`.
- `func_8003D488` receives a value explicitly truncated to 16 bits at
  `0x8000ACA0`.
- The two call groups at `0x80080884`–`0x800808A4` and
  `0x80080C20`–`0x80080C40` pass the same object-relative pointer to
  `func_80080350`, `func_8007F22C`, and `func_8007F23C`; the latter two also
  receive distinct word output addresses. Their integer and floating-point
  results are stored immediately.
- The call at `0x8005F304` supplies four word arguments to `func_800834DC`.
- Calls to `func_8008D274` pass pointer slots and consume the returned old
  pointer. Multiple callers first test the old pointer's first field, agreeing
  with the observed one-link advance.

The address-only global correspondence is:

| Function | USA global(s) | Japan global(s) | Europe global(s) |
|---|---|---|---|
| `func_8002E028` | `800A268C` | `800A53FC` | `800A7C8C` |
| `func_8002E0A8` | `800A2690` | `800A5400` | `800A7C90` |
| `func_8002F054` | `800A26F4` | `800A5464` | `800A7CF4` |
| `func_8002F060` | `800D7740` | `800DA9B0` | `800E03E0` |
| `func_8002F1CC` | `800A26F8`, `800A26FC` | `800A5468`, `800A546C` | `800A7CF8`, `800A7CFC` |
| `func_80031BEC` | `800DB910` | `800DEB80` | `800E45B0` |
| `func_80031F94` | `800A2DD4` | `800A5B44` | `800A83D4` |
| `func_8003D488` | `800A48D4` | `800A7644` | `800A9BD4` |

## Regional equivalents

Each complete function has one unique normalized match in Japan and Europe.
The LRG revision retains the USA address and bytes for all 15.

| USA function | Japan VRAM | Europe VRAM |
|---|---|---|
| `func_8002DFB0` | `8002EA10` | `80031550` |
| `func_8002E028` | `8002EA88` | `800315C8` |
| `func_8002E0A8` | `8002EB08` | `80031648` |
| `func_8002F054` | `8002FAB4` | `800325F4` |
| `func_8002F060` | `8002FAC0` | `80032600` |
| `func_8002F1CC` | `8002FC2C` | `8003276C` |
| `func_80031BEC` | `8003264C` | `800351AC` |
| `func_80031F94` | `800329F4` | `80035554` |
| `func_8003D488` | `8003DE08` | `80041DC8` |
| `func_80073708` | `80074338` | `80078BE8` |
| `func_8007F22C` | `8007FECC` | `8008470C` |
| `func_8007F23C` | `8007FEDC` | `8008471C` |
| `func_80080350` | `80080FF0` | `80085830` |
| `func_800834DC` | `800841BC` | `800889BC` |
| `func_8008D274` | `8008DF64` | `800927C4` |

## Matching record

IDO 5.3 with the recorded `ido53_o2` profile reproduces the first 14
functions exactly in all four unique images: 220 bytes per build. These are
genuine byte-matching C and are substituted into each hybrid rebuild.

`func_8008D274` is behavior-recovered but not byte-matching. Its 16-byte C body
has the correct size and address, but the second instruction uses `t6` where
the binaries use `t9`; the first difference is byte offset `0x5`. It remains
assembly in every matching build. Address and structure names are intentionally
not inferred beyond the evidence above.
`func_80008548` is behavior-recovered: when the setup guard is clear, it
computes a scaled integer, optionally normalizes it using the runtime helpers,
and passes the result to the guarded setup call. Its 200-byte IDO shape remains
unmatched because of register and spill allocation.
`func_80011888` is behavior-recovered with its eight-byte pre-prologue load:
it conditionally runs three setup routines after an initial helper, otherwise
clears a global, then always forwards both arguments to the final routine.
