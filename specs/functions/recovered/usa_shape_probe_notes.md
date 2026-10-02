# USA source-shape probe notes

These candidates remain behavior-recovered C with USA assembly splits. The
measurements below are from the isolated, linked IDO 5.3 verifier; no exact
match or C substitution is claimed.

| Function | ROM/C bytes | Baseline differing words | Bounded result |
| --- | ---: | ---: | --- |
| `func_80053C08` | 1088/1088 | 99 | Explicit typed owner alias reduced differences to 89; declaration-order variants remained nonexact. Source restored. |
| `func_8002D048` | 1148/1128 | 248, plus 5 missing | Replacing the default switch `break` with an explicit outgoing `goto` compiled identically. Source restored. |
| `func_8008E074` | 940/920 | 229, plus 5 missing | Advancing the command pointer after each of the first two packets compiled identically. Source restored. |
| `func_800125E4` | 980/948 | 229, plus 8 missing | No source experiment: a forced volatile or address-taken index lacks ROM evidence. |
| `func_8000F5A0` | 1164/1224 | 287, plus 15 extra | Scalar framebuffer-end pointer worsened the C body to 1268 bytes (26 extra words); source shape restored. |
| `func_80097400` | 1356/1288 | 314, plus 17 missing | ROM-backed byte/halfword types and redundant classification branch retained; now 1336 bytes, 332 differing words, 5 missing. |
| `func_8001DDA8` | 2328/2212 | 536, plus 29 missing | Missing vector-normalization call restored; now 2220 bytes, 551 differing words, 27 missing. |
| `func_80066144` | 1120/1140 | 277, plus 5 extra | Active-array-size reduction changed only the first differing byte; dropping an explicit `f64` cast yielded 1132 bytes/267 differing words, and an unsuffixed literal restored the baseline. All variants reverted. |
| `func_80048F74` | 1372/1352 | 326, plus 5 missing | Moving the key block ahead of locals or the order array after scalars left size and word differences unchanged; both variants reverted. |

In `func_8002D048`, the ROM's default unsigned-float conversion has three
distinct exits to `0x8002D2C4`; IDO merges them in the current C at
`0x8002D100`. The `goto` did not recover any exit. Do not retry the same-edge
spelling without new control-flow evidence.

For `func_800125E4`, the ROM's eight-byte frame saves `$s0` at `sp+4` and
homes incoming `$a1` at `sp+0xC`, outside the allocated frame. Its three
reloads occur on mutually exclusive paths; nothing takes the index's address
or passes a stack pointer onward. Those accesses do not justify volatile
semantics or a fabricated local array.

In `func_8000F5A0`, the ROM computes the framebuffer end into `$t1` at
`0x8000F608` and compares against it in the sampling loop. The `sp+0x2C`
slot instead holds height, reloaded at `0x8000F658`. The existing C's
single-element end array is only a nonmatching source-shape attempt, not a
recovered original stack layout. Its misleading comment was removed; a
behavior-equivalent scalar-end test was reverted after the isolated verifier
showed a larger mismatch.

For `func_80097400`, the ROM loads the incoming conversion code as a byte
(`0x8009744C`, `0x80097594`), stores/reloads the exponent as a signed halfword
at `sp+0x9A`, and normalizes the classification value to signed halfword width.
Both recovered callers already declare the conversion parameter as `u8`.
The behavior-only C now uses `u8 conversion`, `s16 kind`, and `s16 exponent`,
and retains the ROM's `binary < 0` classification branch at `0x80097518`.
Although that branch is unreachable after the preceding mask, IDO emits a
corresponding `bgez` in the corrected C and reduces the length deficit by four
words. The remaining mismatch is not an isolated halfword placement: the ROM
frame is `0xD0` bytes and saves `$s0`–`$s5`, whereas C uses `0xC8` and saves
`$s0`–`$s7`; the ROM stores the exponent at `sp+0x9A` while C retains it in
`$s7`, and the digit/aggregate stack offsets also differ. No declaration-order
or artificial volatile/array variant is supported. The USA split remains
assembly because the linked object is still nonexact.

For `func_8001DDA8`, the ROM calls vector normalizer `func_800154D0` at
`0x8001DE24` immediately after storing the vector length. The C had omitted
this call; adding it makes all 28 direct `jal` targets match in order. The
negative-pitch branch already adds the correct 90.0f (`0x42B4` at
`0x8001DEDC`); the later positive-pitch branch subtracts 180.0f (`0x4334`
at `0x8001DF00`). An initial proposal confused the two constants and was
rejected by parent disassembly. The USA split remains assembly.

A same-source regional comparison found no currently nonmatching USA unit
that is exact in Japan or Europe. A programmatic scan of the first 25 ranked
USA candidates found no predominantly stack-offset-only equal-size miss
(highest was 7 such words among 77 differences), so a broad declaration-order
sweep has no current evidence basis.

## Separate state-four/state-five blocks in func_80060DE4

The canonical switch at 80060ED0 indexes `jtbl_800AD0B8`. ROM entries 4/5
(at ROM ADCC8/ADCCC) target
80061074/80061088 respectively. Each block independently stores 0x10 to
object+0x88 and clears the apply-range flag. The old C grouped the cases;
its linked jump table sent both to 80060FD4. Separate source cases now produce
distinct targets 80060FD4/80060FE4, recovering the evidenced branch structure
without changing their common behavior.

The isolated comparison changes from 4840/5260 bytes, 1158 differing overlap
words and 105 missing words, to 4856/5260 bytes, 1190 differing overlap words
and 101 missing words. The larger overlap diff includes shifted instructions;
this is a structural recovery, not an exact match. No split or matching
configuration changes were made. The private mechanical draft was only a hint;
addresses, table entries, stores and branch destinations were checked against
the canonical USA binary and disassembly before retaining the source change.

## Current-object reads in func_80060DE4

The initial switch now reads `object->unk14` rather than the incoming argument.
The canonical load is at 80060ED0, after the proximity helper and node flag
loop. Both node loops now reread `object->unk34`, matching loads at 80060EBC
and 80060F20, rather than retaining one pointer snapshot. The choice-count
and special-set locals are initialized before the proximity call, matching
80060E30/80060E34 and their pre-call spills at 80060E78/80060E7C.

Sequential isolated results (C/ROM bytes; differing overlap/missing words):

- Baseline after separate cases 4/5: 4856/5260; 1190/101.
- Current-object switch: 5080/5260; 1235/45.
- Node-table rereads: 5096/5260; 1223/41.
- Pre-call local initialization: 5100/5260; 1224/40.

All 56 direct call targets still match the ROM in order. These edits recover
source structure and load timing; they do not establish a new exact match or
prove that the existing helper changes the state field. The USA split remains
assembly-backed.

## Startup branches in func_8001ADD4

Mode-two state initialization now has explicit zero/one store branches,
matching 8001AE98–8001AEA8. The four assigned-entry checks and the lock check
now each independently clear D_800A23AC, matching stores at 8001B068,
8001B080, 8001B094, 8001B0A8 and 8001B0BC. The former combined OR collapsed
these into a common store. Behavior is unchanged for the distinct nonvolatile
objects, but the source now expresses the ROM's separate conditional effects.
Parent verification reports 5432/5680 bytes, 1324 differing words and 62
missing, versus 5384/5680, 1337 differing and 74 missing before the edit.
A loop-spelling experiment had no additional effect and was reverted.

## Signed texture coordinates in func_8003D4F4

Before floating-point geometry, the original loads incoming Y with signed
halfword load at 8003DCFC from sp+0x192, and X at 8003DE0C/8003DE28/8003DF10
from sp+0x18E. Its frame is 0x188 bytes, so these are the low halfwords of
the incoming argument homes at +0x190 and +0x18C. The C now explicitly casts
both coordinates through `s16` before converting to float. Previously values
outside the signed-halfword range produced different geometry.

Parent verification remains 2664/2984 bytes, 664 differing overlap words and
80 missing. The changed load width is a semantic correction; shifted code
positions leave the overall word-difference count unchanged. This function
remains assembly-backed.

`tests/test_texture_coordinates.c` captures the production renderer's geometry
for ordinary coordinates (2,4), positive wraparound (65537,65539), and signed
wraparound (65535,32768). The corrected source emits (2,4), (1,3), and
(-1,-32768); the prior source fails the wrapped-coordinate assertion.

A post-edit IDO 5.3 sweep of these three units at O1/O2/O3, each with MIPS II
or MIPS III plus `-32`, produced no exact match. No per-unit flags changed.
Do not repeat those six profiles on these unchanged source hashes.

For `func_8006E6F8`, canonical constant comparisons at 8006F5D0–8006F5E4 and
8006F73C–8006F754 compare 0.5 against zero before flag updates. Direct literal
predicates folded away; artificial local-variable versions grew from 4696 to
4732/4752 bytes but remained nonexact. All were rejected and the original
4696/4880-byte source restored (1164 differing words, 46 missing). These
experiments establish no new semantic correction.

## Transition aggregate in func_80064034

The four words at D_8011A240 through D_8011A24C are now a typed local view
of one transition record: float progress, two integer enable flags, float
final progress. Canonical instructions at 80064034–8006403C form the record
base and load its +4 flag. Later accesses at 800642C0, 800644A8/80064680,
and 800648DC confirm the +4/+8/+12 fields. Source reads still occur at the
original use sites, including after helpers; no snapshot replaces those reads.
The phase selection uses a conditional expression and initializes the existing
model-progress local after it. No literal-pool mapping changed.

Isolated results (C/ROM bytes; differing/missing words): original 2476/2580,
616/26; typed view 2476/2580, 613/26; moved initialization 2480/2580, 612/25;
retained conditional selection 2484/2580, 594/24. Parent re-audit confirmed
the final result. A six-profile IDO 5.3 O1/O2/O3, MIPS II/MIPS III-32 sweep
found no exact match. The function remains assembly-backed.

## Rejected and unchanged follow-ups after f519834

- `func_80056844`: float `pos`/`column` declarations changed 548 to 546
  differing words at the same 2472/2980-byte size, but parent review rejected
  the inferred type. The ROM stores truncated `pos` at 800568B4 and reloads
  it as a signed halfword at 80056910; no persistent float use was found.
  Original signed-halfword declarations restored. Volatile constants were
  also rejected (2636 bytes, 652 differing words).
- `func_80041258`: 1812/1884 bytes, 446 differing words, 18 missing. Anchor
  tests at 80041418/80041540, timed double arithmetic at 80041664–80041778,
  and completion/helper ordering at 80041988–8004199C agree with C. The two
  16-by-3 arrays match stack blocks separated by 0xC0; no smaller layout
  was justified. No source change.
- `func_80060DE4`: moving its initial speed read before the early guards
  changed 5100 to 5092 bytes, 1242 differing words and 42 missing; the
  experiment stayed in /tmp and was not retained.
- `func_8007531C`: a 60-second, eight-worker decomp-permuter pilot with
  stack differences enabled started at score 10 and produced no improved
  candidate. Its 372 target bytes were checked against the canonical ROM
  after linking at 8007531C. Search artifacts stayed outside the repository;
  the source remains unchanged. No unmeasured iteration count is claimed.

## Three-component projection scratch in func_8001F5AC

The `screen` local is now three floats. The helper `func_80033590` writes
only x/y/z, including through `func_800155EC` and `func_80015268`; the ROM
places its destination at sp+0xA4 next to the three-float world vector at
sp+0x98. The former four-float declaration had no fourth-component use.
Parent audit remains 2616/2692 bytes but moves from 614 to 613 differing
words, and the frame now matches the canonical 440 bytes instead of 448.
A declaration-order trial added no improvement and was reverted.

## Single-precision mesh threshold in func_800834F0

D_800ADD10 is now declared `f32`. Canonical `lwc1` at 80083668 and `c.lt.s`
at 80083674 establish both load width and comparison precision. The ROM word
is `3DCCCCCD` (approximately 0.1). The previous `f64` declaration read eight
bytes as approximately 5.238690037323579e-11, selecting a different mesh
branch for ordinary small positive factors. The type correction yields
2704/2192 bytes, 544 differing overlap words and 128 extra words, compared
to 2708/2192, 544 and 129 before. An unrelated loop rewrite was rejected.

A six-profile IDO 5.3 O1/O2/O3 MIPS II/MIPS III-32 sweep of the three newly
changed sources (1F5AC, 76180, 834F0) found no exact match. Three transient
compile failures in the concurrent O3/MIPS III pass were rerun serially;
all three then compiled and remained nonexact. The full accepted-profile
ledger completed with no compile/link failures.

The independent `func_80027150` audit retained no edit: signed-byte selectors,
initialization order at 8002719C–800271AC, random-angle calculation at
800271FC–80027228, six-case phase dispatch, and increment-before-effect
ordering agree with C. Its audit remains 2200/2236 bytes, 543 differing words,
and 9 missing words.

`tests/test_mesh_threshold.c` checks the fallback path at factor 0.0396 and
the expanded mesh at factor 0.19, with canaries around 27-vertex and
26-command buffers. Both paths pass. In a temporary host comparison, the
previous source supplied with the canonical bytes' former double
interpretation fails the fallback vertex-copy assertion. The test does not
claim a host-native double has the ROM's byte order; the old interpreted
numeric value is supplied explicitly for that comparison.

## Camera yaw coefficient in func_80021294

The horizontal-motion factor is now `70.0f`, correcting `140.0f`. The raw
USA ROM word at 800217A0 is `3C01428C`, materializing binary32 70.0. The
following arithmetic multiplies by the time step (800217B8), then the axis
(800217C8), converts to double, multiplies by 1.5 (800217D4), and adds to
the previous yaw. No compensating factor of two appears.

Parent comparison confirms the entire compiled text differs from the prior
source in only one word, at offset 0x4F8: `3C01430C` becomes `3C01428C`.
Both audits remain 3312/3312 bytes with 596 differing words because broad
scheduling differences place that instruction differently from the target.
A six-profile O1/O2/O3 MIPS II/MIPS III-32 sweep found no exact match.
