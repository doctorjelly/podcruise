# USA constant-pool placement audit

The 2026-10-01 audit examined every currently nonmatching unit lacking an
explicit read-only-data address. Thirteen compiled units emitted a pool.
Three complete pool byte sequences had unique matches in the canonical USA
ROM's data region, and the corresponding USA instructions independently
confirmed those addresses:

| Unit | Pool VRAM | Pool bytes | Current comparison |
| --- | --- | ---: | --- |
| `func_8008EADC` | `0x800ADF18` | 16 | 508/520 bytes, 127 differing overlap words |
| `func_80081360` | `0x800ADC90` | 32 | 456/456 bytes, 6 differing words |
| `func_8008F3FC` | `0x800ADF40` | 80 | 1352/1352 bytes, 116 differing words |

The first two pools contain numeric constants. The third is a jump table.
The configured addresses now reproduce those canonical references rather than
placing pools immediately after isolated text. This reduces `func_80081360`
from 16 to 6 differing words and `func_8008F3FC` from 118 to 116.
All three units remain assembly-backed; no exact coverage is added.

The remaining six words in `func_80081360` are register choices in two clamp
comparisons and a fixed-step timestamp update. A local timestep, reuse of the
previous-timestamp local, and a volatile timestep declaration were tested and
reverted because they worsened the comparison.

Whole-pool nonmatches were not assigned guessed addresses. Padding, immediate
constant materialization, and source-generated jump-target offsets must be
resolved before those units can establish a single correct pool placement.
