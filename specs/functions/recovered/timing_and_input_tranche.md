# Timing and input recovery tranche

## Verified USA facts

| Function | ROM | Bytes | Return / delay slot | Direct callers |
| --- | ---: | ---: | --- | --- |
| `func_8002E124` | `0x02ED24` | 472 | `8002E2F4: jr ra` / `8002E2F8: nop` | `80008F40`, `8002DFF0`, `8002E068`, `8002E568` |
| `func_8002EA28` | `0x02F628` | 620 | `8002EC8C: jr ra` / `8002EC90: move v0,t2` | `8002ECB0` |

`func_8002E124` calls `func_800811DC`, `func_8008AC48`,
`func_8008AB48`, `func_8008ADA0`, `func_800073A4`, and `func_8002E0B4`.
It reads and updates the four adjacent timing globals from `D_800A26A0`
through `D_800A26BC`. `func_8002EA28` is a leaf. It reads controller-enable
state from `D_800D697C`, `D_800D7490`, and `D_800D7498`, consumes the four
six-byte samples at `D_800D74C0`, publishes the decoded states at
`D_800D74D8`, copies the current button mask to `D_800D74A8`, and clears
`D_800A26D8` before returning that state array.

Unique normalized 32-instruction mappings place `func_8002E124` at Japan
`0x8002EB84` and Europe `0x800316C4`, and place `func_8002EA28` at Japan
`0x8002F488` and Europe `0x80031FC8`. These mappings are structural and
relocation evidence only.

## Behavioral specifications

- `func_8002E124` saves the previous filtered clock value, obtains and filters
  a new clock value, prevents it from moving backward, initializes a periodic
  deadline, and services an expired deadline. Large overruns increment a
  counter. The deadline then advances by a short interval on a failed status
  query, or by a full interval after running two maintenance helpers.
- `func_8002EA28` optionally clears the first published controller state,
  decodes each enabled raw controller sample, clamps both signed axes to the
  range -100 through 100, expands the sixteen button bits into byte flags, and
  clears disabled entries. It finally clears the refresh latch and returns the
  published-state array.

## Exact compiler status

Both functions are independently expressed, behavior-recovered C. Canonical
USA IDO 5.3 `-O2` comparisons report:

| Function | ROM bytes | C bytes | First difference | Differing overlap words |
| --- | ---: | ---: | ---: | ---: |
| `func_8002E124` | 472 | 472 | `0x04` | 104 |
| `func_8002EA28` | 620 | 620 | `0x99` | 30 |

Neither function is byte-matching. For `func_8002EA28`, an explicit output
pointer increased the mismatch to 87 words, declaration reordering had no
effect, and reversing the mask/global assignment increased it to 35; all were
restored. For `func_8002E124`, a split-word union, a saved-clock local,
same-line grouping, declaration reordering, and an explicit status local all
failed to improve the baseline and were restored. No exact-match claim is
made.
