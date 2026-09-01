# Small mismatch audit tranche

## Verified USA facts

| Function | ROM | Size | Return / delay slot | Direct callers |
| --- | ---: | ---: | --- | --- |
| `func_80089144` | `0x089D44` | 308 | `80089270: jr ra` / `80089274: nop` | `func_80007B10` |
| `func_80031324` | `0x031F24` | 180 | `800313D0: jr ra` / `800313D4: nop` | `func_8002F750` |
| `func_80040050` | `0x040C50` | 428 | `800401F4: jr ra` / `800401F8: nop` | `func_80041058`, `func_800419BC`, `func_80043CD0` |
| `func_80080A1C` | `0x08161C` | 464 | `80080BE4: jr ra` / `80080BE8: nop` | `func_80080BEC` |

The first function calls `func_80087FC0`, `func_8008FDEC`, `func_8008FE60`,
`func_8008FC3C`, `func_8008FD60`, and `func_80088BFC`, and accesses
`D_800A6990`. `func_80031324` calls `func_80011DF0`, `func_8003043C`,
`func_800086F8`, `func_80030FF8`, `func_80031134`, `func_8000A920`,
`func_80008540`, `func_800811C0`, and `func_800812E8`; its globals are
`D_800D6960` and `D_800AA000`. `func_80040050` calls `func_80008B14` and
accesses `D_800A4AD4`, `D_800A6664`, and `D_80120BF0`. `func_80080A1C` calls
only `func_8008035C` and accesses `D_800A6704`, `D_800ADC70` through
`D_800ADC7C`, and `D_80120BF0`.

Normalized 32-instruction searches independently locate the regional bodies:

| USA | Japan | Europe |
| --- | --- | --- |
| `func_80089144` | `func_80089E34` | `func_8008E694` |
| `func_80031324` | `func_80031D84` | `func_800348E4` |
| `func_80040050` | `func_800409E0` | `func_800449F0` |
| `func_80080A1C` | `func_800816BC` | `func_80085EFC` |

These regional matches were used only to check structure and relocations; USA
remains canonical.

## Behavioral specifications

- `func_80089144` initializes an object, allocates and clears its element
  records, allocates a second pool, installs ownership and callback fields,
  registers the object with a global manager, configures mode 5, and stores the
  returned handle.
- `func_80031324` runs three preparation helpers, conditionally stores the first
  signed argument when a settings bit is clear, passes both signed arguments to
  the next stage, then invokes six fixed finalization calls with their observed
  constants and global buffer.
- `func_80040050` advances or replaces a global progress value according to two
  sentinel inputs. When progress first crosses six under the accepted actor
  state, it emits a fixed event. It clears a secondary timer below that
  threshold and otherwise advances the timer while the actor flag is set.
- `func_80080A1C` samples and retains an object's current and previous phase,
  advances or clears an age field, normalizes phases across a wrap, and detects
  one of two crossings selected by a global direction. A detected crossing
  clears the age, updates the retained phase, and returns one.

## Compiler status

All four bodies are independently expressed, behavior-recovered C. None is
byte-matching:

| Function | ROM bytes | IDO symbol bytes | Isolated padded bytes | First difference | Differing overlap words |
| --- | ---: | ---: | ---: | ---: | ---: |
| `func_80089144` | 308 | 308 | 320 | `0x09` | 65 |
| `func_80031324` | 180 | 156 | 160 | `0x03` | 39 |
| `func_80040050` | 428 | 420 | 432 | `0x1F` | 64 |
| `func_80080A1C` | 464 | 444 | 448 | `0x62` | 74 |

Exact USA IDO 5.3 `-O2` comparisons produced those measurements. The word
counts cover the shared byte range; the separate size columns expose missing
or extra instructions rather than silently treating alignment as function
code.

Bounded source-shape experiments were rejected and restored. Declaration order
and pool-size spelling did not improve `func_80089144`; a signed local did not
improve `func_80031324`; rearranging the sentinel cases made
`func_80040050` worse. For `func_80080A1C`, spelling the final Boolean test as
`hit == 1` recovered the 464-byte size but generated a `bnel` sequence absent
from the ROM and still differed in 73 words. Operand reversal did nothing and
an explicit ternary expanded the body to 476 bytes. No exact match is claimed.
