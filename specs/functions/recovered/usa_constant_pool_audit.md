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

## Linker alignment and exact float values (2026-10-02)

An audit of linked `.rodata` contents exposed leading padding at four already
configured addresses. Setting section alignment to 8 for `func_8008EADC` and
4 for `func_8001A408`, `func_8005337C`, and `func_800321F0` removes the
unintended leading bytes. Canonical references independently confirm bases
ADF18, A9B44, ACE6C and AA3AC: the three jump-table loads are at 8001A9B8,
800533BC and 80032208. The complete 16-byte numeric pool for 8008EADC now
matches the ROM, correcting the earlier placement-only audit's assumption
that the configured section start also placed its first constant there.

| Unit | Alignment | C/ROM bytes | Differing words before/after |
| --- | ---: | ---: | ---: |
| `func_8008EADC` | 8 | 508/520 | 127/127 |
| `func_8001A408` | 4 | 2432/2508 | 603/603 |
| `func_8005337C` | 4 | 1880/1880 | 160/159 |
| `func_800321F0` | 4 | 3388/3388 | 386/374 |

The remaining jump-table contents still reflect nonmatching code layouts;
these alignment corrections do not establish exact functions.

Four literals in `func_80076180` were one binary32 step too small. The ROM
loads D_800AD9E0/ADA20 with bits `3E4CCCD0` and D_800ADA18/ADA58 with bits
`3DCCCCD0`, confirmed at instructions 80076440, 80076640, 80076528 and
80076720. Exact decimal spellings `0.20000004768371582f` and
`0.10000002384185791f` now emit those words, instead of `3E4CCCCF` and
`3DCCCCCF`. All four compiled pool words were checked against ROM. The text
comparison is unchanged at 2484/2484 bytes and 167 differing words; fixing
the numeric payload is necessary independently of text matching.
