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

## Unrelated prefix removal and width audit (2026-10-02)

`func_800401FC` no longer emits an unused eight-byte zero array before its
constants. Those ROM bytes at 800AAC30 contain an unrelated string; canonical
loads at 8004046C and 80040700 reference AAC38 and AAC40. Configuring the
pool at AAC38 preserves every compiled text byte and matches all 16 pool
bytes (`3F7FFFEF 3F7FFFEF 3DCCCCCD 00000000`). The function remains nonexact.

A bounded scalar-extern audit covered all 167 nonmatching USA function
intervals, deduplicating generated assembly addresses and excluding arrays,
pointers, and structures. It found 1,383 direct symbolic `lwc1` loads of
declared `f32` globals and 459 `ldc1` loads of declared `f64` globals, with
no opposite-width loads. This does not cover indirect or aggregate accesses.

In `func_80066144`, the first two compiled pool words have the opposite
order to the ROM, but their references preserve the correct signs and
short-circuit predicate order. Local bounds optimized back to baseline;
array and scalar static objects added unsupported layout/code changes and
were reverted. Final baseline: 1120/1120 bytes, 266 differing words.

## Adjacent camera-unit pools

`func_80020030` now places its pool at 800A9C40 with alignment 8. All 60
used numeric bytes match the USA ROM. Parent audit remains 4708/4708 bytes
and improves from 969 to 962 differing words. This address was previously
unconfigured, placing the isolated pool after the compiled text.

A private combined compilation of 80020030 and 80021294 emits a 144-byte
pool with the same structure as the ROM: 60 numeric bytes, an 11-entry
jump table at A9C7C, then 40 numeric bytes at A9CA8. All 100 numeric bytes
match. The standalone second function instead inserts four bytes between
its table and doubles because its pool starts four bytes off an eight-byte
boundary. Composition removes that padding naturally. Both function
addresses and sizes are correct in the experiment, but the 11 case targets
remain four bytes below canonical and text remains nonexact.

The follow-up reconciliation retains `unit_80020030.c`, which includes the
two original sources in ROM order. Vector-helper declarations now agree
with `vector_math.h`; existing three-float array arguments use the established
vector type. The shared table declaration is `s32[]`, with the original byte
access explicitly preserved, and the state structure has a tag for its
forward declaration. No duplicate symbol aliases or padding objects are
needed. The configuration records both included sources and canonical
function boundaries. Parent verification confirms all 100 numeric bytes.

Both functions remain assembly-backed and nonexact: 4708/4708 bytes with
962 differing words, and 3312/3312 bytes with 596 differing words. Changing
the table declaration produces ten register-allocation changes in the first
function without changing its aggregate mismatch count; the second source's
standalone text is unchanged by the declaration reconciliation.

The reconciled combined unit was also tested under six IDO 5.3 O1/O2/O3
MIPS II/MIPS III-32 profiles. None matched. One concurrent O3/MIPS II
compile failed transiently; its serial retry compiled both functions at
4708/3312 bytes and remained nonexact. The accepted full ledger has no
compile/link failures.

## Selector table prefix and two rejected mappings

`func_8000D5EC` no longer emits three artificial zero words before its jump
table. Canonical dispatch at 8000D604/8000D60C references 800A863C directly,
which is now the configured table start with alignment 4. Eight of nine
entries match ROM; the final entry is 8000D7DC instead of 8000D7CC because
the function still emits 512 bytes for a 496-byte target. Differing words
improve from 71 to 69. No toggle or register experiments were repeated.

No pool mapping is retained for 80064034: its emitted 0.1f word is an
immediate in ROM at 80064524/80064528. A matching byte sequence elsewhere
does not establish a pool address. For 80047DB0, ROM loads 3B808080 at
AAF9C and double 3F689374BC6A7EFA at AAFA0, verified at instructions
800481F0 and 80048280. Both source values are correct, but the isolated
object inserts four bytes before the double while ROM has none. Moving
the section alone cannot reproduce both addresses; compilation-unit
composition remains a possible follow-up.

## Exact function 8007C818 pool prefix

The artificial eight-byte `padPool` in 8007C818 is removed, and the actual
pool starts at 800ADB68 with alignment 8. Canonical loads at 8007CADC
and 8007CB50 reference ADB68 and ADB70. The two emitted doubles are
`3FC3333333333334` and `3FE99999A0000000`, matching all 16 ROM bytes.
The preceding ROM bytes at ADB60 are `400CCCCD3A83126F`, not the fabricated
1.0 double. Parent audit preserves the exact 1072-byte function. This
function was already exact in the accepted ledger; the cleanup adds no
coverage.

## Exact 469B4 tables and bounded six-function composition

The eight-byte zero prefix in 800469B4 is removed; its tables now start
directly at 800AAEE8 with alignment 8. Parent verification preserves the
exact 1040-byte body and confirms all 45 table words against ROM. The
remaining 12 bytes in the isolated section are alignment padding, not part
of those tables.

A private composition of 469B4, 46DC4, 47920, 479A4, 47A78 and 47DB0
reproduces the entire 192-byte pool: the 45 table words, the float at AAF9C
and double at AAFA0. Four neighbors retain exact bodies in that experiment.
However, clean declaration reconciliation exposes conflicting color-call
prototypes: the u8 RGBA contract adds an instruction to 46DC4 and shifts
later addresses. Changing the callee's formals to s32 is not a solution:
it emits 140 rather than canonical 176 bytes. No wrapper, shared header,
or declaration aliases are retained. Existing exact integrations remain
standalone. A second private trial using named external constants in 47DB0
emits 1892/1884 bytes and 438 differing words, versus 1884/390 before;
it also was not retained.
