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

## Batch call and literal checks after the camera correction

A direct-call sequence comparison across all 167 nonmatching USA functions
found only the known `func_80088BFC` local-helper placement discrepancy:
two calls target 80088B80 rather than canonical 80088B70. All other ordered
direct-call target lists agree. This check does not establish branch behavior,
indirect-call correctness, or argument values.

A bounded materialized-float scan found no additional proven literal error.
The apparent 320.0 candidate in 800879B8 and 255.0/256.0 pair in 80010B34
also occur in their canonical bodies; differing order caused false positives.
The -45.0 candidate in 8001DDA8 is insufficient evidence because the source
contains both clamp signs and the ROM can derive signs through arithmetic.

The camera routine's `cam[0]`, `[5]`, and `[6]` map to scalar globals 800D7388,
800D739C and 800D73A0. Intermediate storage includes the independently used
byte array at 800D7390; no homogeneous seven-float record is established.
A private direct-scalar rewrite removes the cross-object pointer view but
regresses from 3312 bytes/596 differing words to 3292/756, changing address
materialization and scheduling. It was not retained; this layout concern
remains open rather than being treated as a verified aggregate declaration.

## Unsigned selected rank in func_800228C0

The selected scroll rank now explicitly converts the signed player rank to
`u8`. Canonical 800231BC loads the stored primary rank with `lbu`; when
the signed secondary rank is smaller, 800231E8 masks it with `andi 0xFF`.
The selection comparison itself remains signed (`lb` at 800231CC and
`slt` at 800231D8). Thus a negative byte still participates in the signed
selection but becomes its unsigned low-byte value before the threshold and
scroll calculation. Both assignments now preserve that distinction.

Parent comparison finds only two changed compiled words: moves become byte
masks at offsets 0x8D8 and 0x900. The audit remains 6064/6064 bytes with
1446 differing words. The scalar integer-load scan's other candidate, the
`lbu` for 8001A408's switch, is a valid bounds-check optimization; no change
was warranted there.

## Case-local index reloads in func_8002B574

Each top-level case now loads `D_800A2620`, including distinct call/no-call
paths in case 9. This reproduces canonical tails at 8002B72C, 8002B734 and
8002B740. With the table configured at 800A9E90, all 18 used jump-table
entries exactly match ROM. The compiled function remains 1584/1584 bytes:
131 differing words before placement, 129 after placement alone, and 134
after the recovered load structure. Stack and register differences remain;
the exact table is not a claim of exact code. The emitted eight-byte tail
padding is not part of the 72-byte canonical table.

The six-profile IDO 5.3 O1/O2/O3 MIPS II/MIPS III-32 sweep of 228C0,
2B574 and 0D5EC found no exact match. One concurrent O3/MIPS II compile
failed; a serial retry compiled every unit and remained nonexact.

## Real audio-helper composition experiment

A private replacement of 8F3FC's fabricated 8EEE4 stand-in with its recovered
implementation compiles the helper to 460 rather than canonical 464 bytes.
The subsequent 8F0B4, 8F34C and 8F3FC bodies therefore start four bytes early.
The 176-byte 8F34C body remains exact internally, but its address would no
longer be canonical. No merged unit or replacement is retained. Existing
standalone exact coverage is preserved; the remaining helper scheduling
issue overlaps previously exhausted source experiments.

## Further bounded scalar and expression-order audits

The direct scalar-store audit checked 435 canonical store sites for declared
s8/u8/s16/u16/s32/u32/f32/f64 globals and found no width mismatch. It
excludes array, pointer, and aggregate accesses. A separate same-position
load/store comparison with matching operand bits and nearby instructions
found no width-change candidate among the same-size nonmatching functions.

In 800547EC, the ROM computes `progress - 460` before materializing 280
for the horizontal HUD coordinate, while C schedules those literals in the
opposite order. Both values and the arithmetic are correct. A separate
float intermediate regressed from 4864 bytes/929 differing words to 4864/936;
reusing `screenX` left the original output unchanged. Both experiments were
reverted. This is scheduling evidence, not another literal-value defect.

## Signed initializer induction variable in 80072AD0

The bounded loop index is now s32. The ROM's 75-entry vector loop compares
its byte offset against 900 with signed `slti` at 800731E0; the former u32
declaration emitted `sltiu`. All loops using this index begin at zero and
have small fixed bounds. The type change alters six induction comparisons
from unsigned to signed and changes no other compiled words. It restores
the instruction at 800731E0 exactly; other changed comparisons remain in
regions with separate operand/scheduling differences. The audit stays
2452/2452 bytes and improves from 253 to 252 differing words.

## US14 bounded shape and literal checks

`func_80007594` remains unchanged after three private trials. Baseline is
396/380 bytes, 89 differing words, 4 extra words, first difference at 0x5.
Moving `previous = entry` before the containment check (the ROM does this in
the branch delay slot) generated byte-identical text. Replacing the anchor
pointer with direct global field accesses worsened the audit to 388/380,
90 differing words and 2 extra words. Typing the backing buffer as `u8 *`
also generated byte-identical text. The ROM retains the list anchor in `$s1`
and later reuses `$s1` for the backing buffer; the current C allocation and
spills remain unresolved.

`func_80055D38` also remains unchanged. Baseline is 1868/1836 bytes, 421
differing words, 8 extra words, first difference at 0x60. A private `s32
baseAlpha` preserved across `func_8006E2FC`, with the existing `s16 alpha`
view used for the 2.5 scale, worsened the audit to 434 differing words and
still 8 extra words. The ROM's full-width value at 80056008 is saved at
sp+0x34 across the helper and reloaded at 8005601C; the candidate emitted a
similar v1/sp+0x38 lifetime but did not improve the comparison.

In `func_8001A408`, the two compact-mode vertical coordinates for IDs 0x4F
and 0x50 now use `100.0f`. ROM loads `0x42C80000` at 8001A6F8 and 8001A770,
then multiplies the first progress value at 8001A718 and 8001A784. The
separate horizontal slide for ID 0x51 still uses `320.0f`, matching
`0x43A00000` at 8001A8CC. The source correction changes only the compiled
LUI words at offsets +0x2EC and +0x35C, from `0x3C0143A0` to `0x3C0142C8`;
the audit remains 2432/2508 bytes, 603 differing words and 19 missing words.

In `func_8001F5AC`, the underline position changed from `100.0` to `160.0`.
The canonical double literal is established by `0x3C014064` at 8001F988,
followed by zeroing its low word. The correction changes one compiled word at
offset +0x3CC; the audit is 2616/2692 bytes, 613 differing words and 19
missing words.

Three worker-reported private variants for `func_8008BC30` made no progress:
a persistent local message count, per-message `u16` scratch count, and a
`previous = now - previous` accumulator spelling all remained 400/396 bytes,
95 differing words and one extra word. Each retained a 96-byte frame versus
the ROM's 80-byte frame. The canonical loop reloads and decrements the global
count, then resets it from the schedule after the optional callback. No
shared source change was made.

Two apparent immediate mismatches in `func_8005E1A4` were scheduling false
positives. At 8005E7E4, ROM's `0x240E009B` was paired with compiled
`0x240E009A`; at 8005E854, ROM's `0x240C005A` was paired with compiled
`0x240C0036`. These are color components from distinct kind-4 substates:
the source has `(0x9B, 0x9A, 0xA7)` for substate 1 and `(0x5A, 0x36, 0x28)`
for substate 2. The complete branch sequences contain the same values in
different instruction order. Baseline remains 2152/2152 bytes and 281
differing words; no source change was made.

The three changed units were rechecked under all six IDO 5.3 O1/O2/O3
MIPS II/MIPS III profiles; none became exact. An aligned one-word shift-amount
scan over the 167 nonmatching functions found no further candidates with
at least four identical surrounding instructions. Full USA validation retains
1181 exact functions / 361112 bytes and a byte-identical 32-job ROM rebuild.
Host tests, repository safety, and the strict source manifest pass.

## US15 caller contracts and semantic audits

A bounded declaration scan compared scalar signatures in nonmatching callers
with retained exact callees. It identified 85 candidate declarations, many
of which differ only in ignored returns, signedness of raw bits, or integer
argument widths. It is a triage list, not a complete ABI verifier.

The real text-width return contract of `func_800129B8` is now explicit; see
its dedicated spec. Its 44-byte exact body is preserved. The associated
font tag and shared declarations leave `func_800129E4` text unchanged at
376/376 bytes with 33 differing words. A focused callee audit confirmed the
character/control predicates, extended glyph selection, load widths, and
signed glyph advances; only register allocation and scheduling remain.
The prior 26-call unsuccessful attempt was respected, so no new variants
were tried.

`func_8000F0DC` now declares `D_800D57E8` and the fourth argument of
`func_8000EEE0` as `f32`. The setter `func_8000FD74` stores its float argument
into that table, and `func_8000EEE0` multiplies the supplied scale as a float.
The caller at 8000F544 loads those bits into the fourth ABI argument register
before the call at 8000F558; a GPR load here does not imply an integer C
parameter. Correcting both declarations leaves the entire compiled text
unchanged: 1236/1220 bytes, 257 differing words and four extra words.

No additional behavior defect was established by the bounded return-width
checks. `func_8002D9D0` returns only 3 or 4, and `func_80025148` stores its
result as a byte. The sampled signed declarations of `func_80017DA4` feed
equality or bit-mask tests, while `func_80088360` supplies graphics payload
bits directly. These mismatches remain declaration cleanup opportunities,
not evidence of arithmetic or control-flow errors.

The separate 864-case texture packet oracle and its limits are recorded in
`func_8003BAB0.md`. It found no source defect. The sine/cosine formal names
in that callee and `func_8003B324` remain historically swapped, but their
actual values and formulas are correct; no behavioral rewrite was made.

The consumed-return scan additionally recovered the actual index-to-resource
contract of `func_80030154`, documented in `runtime_leaf_wrappers.md`.
Its corrected pointer return preserves the exact 32-byte wrapper and the
504-byte exact loader. Other sampled void/s32 mismatches at `func_8001D05C`
and `func_80028E78` discard their results and established no behavioral defect.

An automation preflight for `func_80080A1C` verified its 464-byte ROM span
at 0x8161C. The two text differences include `nop` versus `mov.s` at
80080BB8 and a floating store-register change at 80080BD4. The stack-aware
permuter baseline scored 205: zero stack/branch/reordering penalties, one
register difference, one insertion and one deletion. It failed the planned
register-only gate, so no timed search was launched and no source changed.

Final US15 verification retains 1181 exact functions / 361112 bytes. The 32-job
USA rebuild is byte-identical; full host/tool tests, repository safety,
strict manifest and whitespace checks pass.

## US16 bounded ABI and code-shape checks

The 56 whole-USA declaration-versus-void-definition return pairs were
checked for multiline, nested, and returned-call consumption. No additional
consumed result was found: the source call sites discard the values, and
canonical caller spot checks showed that later `$v0` uses came from a
separate helper or control-flow path. The separately isolated
`func_8003931C` case is documented in `runtime_leaf_wrappers.md`; its
corrected contract preserves the wrapper's existing 36-byte exact match.

An 11-entry global-type conflict scan did not establish 11 conflicting
objects. The candidates are alternate byte views, mixed record views, or
end-marker comparisons. For example, `D_801489C8` is a float-triple table in
`func_80085EB0`, while `func_80085AB4` compares against it as an end marker.
`D_800A23B0[3]` refers to `D_800A23BC`, a separately named global in another
unit. No global declarations were changed from this scan.

A private direct-final-field-store spelling for `func_80080A1C` grew to
468/464 bytes, with 11 differing words and one extra word, versus the
464/464-byte, two-difference baseline described above. The candidate was
rejected.

An unaligned-operation count scan isolated `func_800834F0`: the ROM has no
unaligned word operations where the former compiled C had 304. The packed
vertex color correction is documented in its dedicated spec. A private
eight-byte-aligned vertex union emitted identical text to the retained
four-byte-aligned record; no union was retained. A six-profile IDO 5.3 sweep
of this changed source found no exact match.

An arithmetic-opcode histogram exposed the missing comparison at 80040100
in `func_80040050`. Its condition result is overwritten by the comparison
at 80040108 before any conditional branch reads it. A private nonempty
guard spelling (`current >= 0 && current >= 6`) did not recover it: the
compiler retained extra control flow and emitted 448/428 bytes, 68 differing
words and five extra words. That variant was rejected; no empty predicate
or unrelated source steering was retained.


Final US16 checks retain 1181 exact functions / 361112 bytes. The 32-job USA
round trip is byte-identical; full host/tool tests, safety, the strict source
manifest, and whitespace checks pass. A subsequent `func_800784F8` unordered
clamp-predicate investigation remains private and is not part of this tranche.


## US17 ordered predicates and vector parameters

The floating-comparison histogram isolated three functions whose canonical
bodies use more ordered inclusive comparisons than the recovered code:
`func_800784F8`, `func_80079824`, and `func_8001ADD4`. The first two had
real unordered-input discrepancies; their dedicated specs record the ROM
branch proofs, retained corrections, and actual-function regressions.
Parent checks independently reproduce both original-source failures and
pass the corrected tests with floating-conversion sanitization. The nine
exhaust tuning floats were checked against their raw canonical ROM words.
A stricter aligned one-word comparison-opcode scan found no further sites.

`func_8001ADD4` has no demonstrated NaN error. The comparisons at 8001BA10
and 8001BA8C are lower range guards following the earlier `<540` and `<900`
tests. Unordered values continue toward the final arm, as they do in the
current source chain. A private explicit range-guard variant grew from
5432/5680 bytes and 1324 differing words to 5488/5680 and 1337; it was
rejected without a shared source edit.

The second and third `func_800834F0` parameters are now vector pointers,
matching all recovered caller groups and their canonical stack-address
arguments. They are only forwarded recursively. This contract correction
leaves the emitted 2096-byte body unchanged; its dedicated spec records the
call-site evidence.

Six-profile IDO 5.3 sweeps of each changed clamp source found no exact match.
No profile change, dummy local, or empty conditional was retained.


Final US17 validation retains 1181 exact functions / 361112 bytes. Both new
regressions pass against the corrected production functions and fail with
original sources. The full host/tool suite, 32-job byte-identical USA rebuild,
safety check, strict source manifest, and whitespace check pass. Subsequent
conversion-opcode triage remains outside this committed tranche.

## US18 floating conversion shapes

The first random animation selection in `func_80060DE4` now uses the
canonical unsigned conversion; its later signed selection is unchanged.
The resulting IDO 5.3 and 7.1 bodies are both 5220/5260 bytes, with 949
differing words and ten missing words, versus the previous 5100-byte body,
1224 differences and 40 missing words. The USA random helper can round to
the normalized upper endpoint in single precision, so choice five reaches
the default arm. No ordinary finite-input behavior change is claimed.

The two terminal arrow fades in `func_80058058` now use signed truncation,
matching the instructions at 80059D20 and 80059DF4. The component fade keeps
its unsigned conversion. This removes two incorrect unsigned conversion
sequences, but does not recover an exact body: IDO 5.3 changes from
7676/7676 bytes and 1708 differing words to 7428/7676, 1665 differences
and 62 missing words. The old equal size was not evidence of a correct
conversion shape. Both tuning values at 800ACF04/08 are positive 223.25f
(435F4000 at ROM ADB04/08); an early private negative-value inference used
incorrect ROM offsets and was discarded. Six-profile IDO 5.3 sweeps of
both changed sources found no exact match.

A private `func_80020030` variant separated modes 13 and 15 to reproduce
the two canonical double-precision subtraction blocks. It worsened the
body from 4708/4708 bytes and 962 differences to 4752/4708 and 1084,
and displaced the adjacent `func_80021294` by 44 bytes. All 100 numeric
bytes within the combined unit's 144-byte pool were unchanged. The
variant was rejected; no compensating padding or shared edit was retained.

Final US18 validation retains 1181 exact functions / 361112 bytes. The
32-job USA round trip is byte-identical. Full host/tool tests, safety,
the strict source manifest, and whitespace checks pass. Both changed
functions remain assembly-backed in the canonical rebuild.

## Follow-on unary and integer triage

An aligned one-word floating-arithmetic opcode scan found no candidates.
A unary-opcode histogram isolated `func_8005F33C` and `func_80047DB0`:
the former folds the canonical negation of positive 30 into a negative
literal, while the latter uses unary negation where ROM multiplies the
angle by negative one at 80048410. Neither establishes a finite-input or
signed-zero behavior error. The existing positive-30 source experiment
was not repeated. The current 47DB0 audit is 1884/1884 bytes with 390
differing words.

The extra negations in `func_80058058` come from adding a negative wobble
where ROM subtracts the positive wobble. A private temporary that scales
the middle row's horizontal wobble before selecting addition/subtraction
produced 7392/7676 bytes, 1655 differing words and 71 missing words,
versus the retained 7428-byte body with 1665 differences and 62 missing
words. This behavior-equivalent shape trial was not retained.

Signed division and integer-mask histogram checks found no new discrepancy.
In 8528C, extra arithmetic shifts repeat a correctly rounded signed
midpoint division. In 401FC, the two canonical ANDI-one sites at 403FC and
40590 duplicate a flag predicate already represented in C. The indirect
call scan found matching target counts across six functions and 19 JALRs.
A private differential-execution pilot remains pending and is not evidence
of additional recovered behavior or exact coverage.

## US19 bounded execution and vertex packing

The private integer-only execution pilot for `func_8003B860` completed
4,884 cases and four independent packet fixtures without a machine-code
discrepancy. Its dedicated spec records the opcode limits, instruction
microtests, branch coverage and separated original-C undefined-input domain.
The retained four unsigned casts define offscreen coordinate packing while
preserving all 592 compiled bytes. A nine-case actual-function regression
passes shift sanitization and fails with the original signed shifts.
Six IDO 5.3 compiler profiles found no exact match after the correction.

An independent `func_80090B24` alias audit found the input load, total store,
and complementary-total reload in the same order as C, including overlapping
accumulator/input pointers. No source variant was justified.

Final validation retains 1181 exact functions / 361112 bytes, with no compile
or link errors. The 32-job USA rebuild is byte-identical; the full host/tool
suite, safety, strict source manifest, and whitespace checks pass. The packet
function remains assembly-backed in that rebuild.

## US20 packet execution and compiler-search triage

The bounded `func_800125E4` pilot passes 1,792 matrix cases, nine independent
ROM packet fixtures and seventeen interpreter microtests. Both outcomes of
all five conditional branches were exercised. The dedicated spec separates
defined inputs from negative-index and trailing-array extension cases and
records the scratch-stack comparison boundary. The parent reran the complete
pilot. No source correction was demonstrated.

The fresh `func_80076B34` baseline is 1312/1312 bytes with nine differing
words. Its linked-target scorer finds three reorderings, not register-only
differences. Three private argument-temporary variants were unchanged or
worse, and no timed search was launched. Its spec now distinguishes these
current measurements from the earlier 12-byte deficit.

Two ten-function preflight batches scored existing linked objects against
verified raw-ROM targets with stack and branch differences enabled. Only
53C08, 46DC4 and 963CC had exclusively register penalties (scores 290, 360
and 375 respectively). The remaining seventeen candidates had stack,
branch, reordering, insertion or deletion penalties and were not sent to
a permutation search. These are triage scores, not exactness evidence.

A 60-second, 32-worker `func_80053C08` pilot improved the scorer from 290
to 100. Independent compilation confirms a 1088/1088-byte candidate with
17 differing words, versus 52 in the current source. Its only change is an
empty conditional after an already-proven record access. All seventeen
remaining differences are register substitutions in two short regions;
one region also swaps the operands of a symmetric BNE. A second and final
60-second search seeded from that candidate produced no improvement. The
nonexact empty conditional was not retained. Current production C, compiler
configuration, and exact coverage are unchanged by this tranche.

## US21 bounded searches and racer-selection definedness

Three timed, private permutation pilots remained nonexact. The 963CC search
ran for 60 seconds with 32 workers; its best 832-byte candidate reduced
differing words from 56 to 45 by adding redundant masks. The 4BE90 and
5EF08 searches each ran for 60 seconds with 16 workers. Their best candidates
reduced differences from 72 to 34 and from 66 to 53 respectively, but used
shift splitting and an uninitialized pointer read. None was retained or
continued. The dedicated specs record parser-preserved same-line groups.
A fresh ten-function linked-object scoring batch qualified only 4BE90 and
5EF08 for these register-only searches.

Inspection of 4BE90 exposed a separate signed-shift defect. The canonical
SLL by 13 followed by a zero test checks the low 19 flag bits. Expressing
that predicate as `flags & 0x7FFFF` defines it for ordinary mask 0x40002
and negative flag words, while preserving all 3008 compiled bytes exactly.
The function remains nonmatching at 72 differing words. Six IDO 5.3
optimization/ISA profiles found no exact match after this correction.

Two private 46DC4 interface probes changed its color-helper declaration to
the callee's byte-width parameters, then cached the existing narrowed alpha.
Both produced 2912 bytes against 2908, with 613 differing words and one extra
instruction. The canonical caller already narrows its main alpha explicitly;
the new instruction was register preservation, not a missing truncation.
Neither variant was retained, and this contract mismatch remains unresolved.


On resumption, the six-case actual-function racer-selection regression passes
shift sanitization and the original source fails at mask 0x40002. Singleton
bits 18 and 19 explicitly cover the predicate boundary. The saved USA ledger
has the current source hash, and its 32-job round trip completed byte-identically.
The parent independently repeated the isolated 4BE90 audit with unchanged
3008-byte/72-word metrics. USA ROM inventory, safety and strict manifest pass.

A fresh 494D0 audit locates five mismatched live-pointer spill offsets while
its matrix and vector stack addresses already agree. Three declaration-order
variants worsen the current 1860-byte, 76-word baseline to 83, 83 and 79
words. No source variant was retained; its spec records the stopping point.


## Resumed exact clipping recovery

`func_80036A1C` now matches all 1376 canonical bytes after grouping an existing
conditional on one source line. Non-whitespace source tokens are unchanged.
The independent parent audit, USA ledger and 32-job byte-identical rebuild
confirm the match; the linker map selects its C object at 80036A1C. Exact
coverage is now 1182 functions / 362488 bytes (58.32%), with every exact
function substituted. Its dedicated spec records the schedule, rejected
probes and bounded grouping minimization.

Ten further linked-object preflights found no register-only candidates.
Three concrete frustum-lifetime variants for 85FB0 also remained nonexact
and were discarded. Its dedicated spec records those experiments. No other
production source or compiler configuration was changed by these probes.

Final full host/tool tests, safety and strict source manifest pass. The USA
ledger has no compile/link errors or stale source hashes. The six-case racer
regression was independently rerun against original and corrected sources.
The progress chart was regenerated for the new exact coverage.


## US24 focused source-line grouping

The actual-function 70BBC candidate matches all 732 USA bytes after grouping
three consecutive source boundaries in its rewind correction. The expressions
and statements are unchanged. Its dedicated spec records the two original
instruction-scheduling differences, corrected search generator and exact form.

Other bounded formatting searches found no improvement:

| Function | Candidate layouts | Baseline differing words | Result |
|---|---:|---:|---|
| 62270 | 78 | 4 | Every text byte unchanged. |
| 073A4 | 10 | 7 | Baseline or worse. |
| 48F74 | 45 | 7 | Baseline or worse. |
| 81360 | 91 | 6 | Every text byte unchanged. |
| 6907C | 57 | 6 | Every text byte unchanged. |
| 33140 | 136 | 8 | Every text byte unchanged. |
| 30FF8 | 32 | 9 | Every text byte unchanged. |

These are local source-boundary searches, not new behavior recoveries. The
30FF8 search enumerates all boundary combinations in the six-line framebuffer
array initialization block. The five-function batch covers the measured
store, loop, clamp and vector-copy mismatch regions. No variant was retained.
For 6D150, reversing the mode comparison operands, dot-product factors, or
both also reproduces the baseline exactly; its spec now records those stops.

Separately, 82BE0 now expresses the LCG multiply and addition as unsigned
32-bit operations, then converts the state to the target signed representation.
Canonical MULTU/MFLO/ADDIU establish wrapping low-word arithmetic. The
independent audit preserves all 152 compiled function bytes and the five
existing mismatches. Six IDO 5.3 optimization/ISA profiles find no exact match.


The parent independently confirmed 70BBC's exact bytes and its linker-map C
substitution. The 32-job USA rebuild remains byte-identical with 1183 exact
functions / 363220 bytes (58.44%). The eight fixed-vector RNG regression
passes undefined-behavior sanitization and fails against the original source
on seed two. Full host/tool tests, current-source USA ledger, strict manifest,
safety, USA ROM inventory and whitespace checks pass. The progress chart was
regenerated for the new exact coverage.

## US25 further grouping boundaries

Three additional near-match grouping searches found no changed compiled text.
The 7531C search enumerated all 64 layouts across six initialization/guard
boundaries and retained the same two-word register-clear swap. The two 69A64
windows enumerated 32 and 128 layouts and retained seven differing words.
All 64 layouts in the 76B34 helper-call window retained its nine differences.
Together these were 288 source-line layouts (64 + 160 + 64); none changed exact
USA coverage.
The dedicated specs identify these exhausted windows and current baselines.
No source changes were retained, and independent windows with no individual
improvement were not multiplied into a larger combined search.

A private attempt to obtain compiler line mappings found that the default
linked object's debug information provides no source lines through objdump.
Adding `-g3` changes 7531C from 372 to 376 bytes with 90 differing words;
this does not provide an unchanged-code mapping and was not retained.

For 4FF7C, two private initialized-static probes used a custom linker script to
place a 16-byte `.data` block at the canonical state address. Both data images
match the ROM's all-ones block. The mixed-type source emits 44 text bytes with
seven differing words; the all-signed source emits 40 bytes with eight
differing words. Neither is exact, and no shared source or linker configuration
changed.

A ten-function score preflight found no candidate satisfying the register-only
search gate (`/tmp/us25-score-gates/result.json`). No exact bytes were added,
and current exact USA coverage remains 1183 functions / 363220 bytes, unchanged
from the `a217897` baseline.

## US26 bounded source-line grouping batch A

Five functions received isolated baseline audits followed by token-preserving
source-line grouping only in the listed windows. Candidate inputs changed no
non-whitespace source tokens. Source-layout counts are distinct generated
sources; compiled-text diversity hashes exactly the measured function-symbol
bytes, excluding any output-section padding. Across all 624 audits, no output
reduced the baseline word differences or matched the ROM.

| Function | Exhausted source windows (1-based lines) | Layouts | Distinct compiled symbol hashes | Best / baseline word differences |
| --- | --- | ---: | ---: | ---: |
| `func_800320E0` | 20–27 settings assignments; 31–38 clamp loop | 254 | 1 | 9 / 9 |
| `func_800801B8` | 42–48 status `-2` and first node loop | 63 | 1 | 9 / 9 |
| `func_80067AB4` | 75–87 final `unk208` blend | 78 | 1 | 14 / 14 |
| `func_80075490` | 30–42 main loop; 44–48 recursive branch | 93 | 2 | 15 / 15 |
| `func_80030328` | 37–53 staged-copy success path | 136 | 3 | 16 / 16 |

The grouped layouts changed no production source, and none is retained. The
matching-object verifier confirmed the respective canonical symbol sizes of
272, 408, 444, 364, and 276 bytes. Hashes were computed over each candidate's
first symbol-size bytes; 370 of the 624 `.text.bin` files also contain padding.
The full private reports are under `/tmp/us26-group-batch-a/`. These windows
are exhausted for this whitespace-grouping dimension; no combinations across
windows were expanded because none improved individually.

## US26 `func_80046DC4` pilot

The fresh USA linked-object gate again measured 2,908 bytes and score 360,
consisting only of 72 register differences. Stack and branch differences,
reorderings, insertions, and deletions were all zero. A single 60-second,
16-worker private pilot produced a best score of 110; its candidate uses an
artificial `y * 1.0f` term in the selected-row Y expression. The independent
canonical audit measured 2,908 bytes and 21 differing words, first at `+0x56`
versus the baseline's 61 words. The candidate was rejected and no production
change was made. Iterations were not measured. The dedicated spec records the
audit and private artifact location.

No exact USA bytes were added by these probes. Current exact USA coverage
remains 1183 functions / 363220 bytes.

## US26 bounded source-line grouping batch B

Five USA functions received isolated baseline audits followed by token-preserving
source-line grouping in the listed 1-based windows. All window lines contain no
line comments or preprocessor directives. Layout counts describe distinct
boundary cases; each source retains its non-whitespace token stream. Best word
differences tie the baseline for every target, so no candidate matched or
improved the ROM output.

| Function | Exhausted source windows | Layouts | Distinct generated sources | Compiled function-byte hashes | Best / baseline word differences |
| --- | --- | ---: | ---: | ---: | ---: |
| `func_8006AF48` | 64–70 clamp; 77–82 adjustment | 96 | 95 | 1 | 9 / 9 |
| `func_80008090` | 80–82 global setup; 84–93 timeout clear; 144–159 sound-start branch | 169 | 169 | 4 | 17 / 17 |
| `func_80007FC8` | 25–33 owner/index/table guard; 33–38 return path | 288 | 287 | 1 | 18 / 18 |
| `func_80030964` | 21–34 sentinel/Data parsing; 35–47 Anim stream loop | 169 | 169 | 2 | 20 / 20 |
| `func_8008E54C` | 120–153 first target loop; 162–200 target-loop tail | 1302 | 1302 | 4 | 16 / 16 |

The final window plan contains 2,024 distinct layout cases and 2,022 distinct
source files. There were 2,721 audit executions because an initial 8E54C probe
of narrower windows was followed by the expanded 8E54C tail window; 697 window
cases were repeated between those runs. For 8E54C, the full translation unit
and its preceding helper prefix were preserved. The target begins at text offset
`0x12C`, and the configured
`-O3` flags remained in effect. The verifier compared the configured 1,184-byte
target span beginning at that offset; the function-byte hashes likewise use
that target slice and do not claim an ELF symbol-size measurement. The other
hashes cover their configured function-size bytes, excluding section padding.
All candidates returned the expected configured function sizes. No source,
configuration, or test changes were retained. Private reports and inputs are
under `/tmp/us26-group-batch-b/` (`results-first-complete.json` for the initial
run and `results.json` for the expanded 8E54C run).

## US26 bounded structural triage: func_80010EA0 and func_8001E6C0

`func_80010EA0` measured 2,156/2,120 bytes with 453 differing words. Three
private guard spellings around its state branch measured 2,164 bytes/453
differences (word guard), 2,144/455 (value guard), and 2,148/447 (combined
guards). None matched; all stayed private. The canonical speed checks at
80011408 and 80011444 confirm the source's 100-then-300 thresholds, so they
were not reversed or otherwise changed.

`func_8001E6C0` initially measured 3,436/3,492 bytes with 855 differing words.
The USA assembly loads `D_800A9C30` and `D_800A9C38` once before the controller
loop and keeps their values live across its backedge. The source now snapshots
those two doubles before the loop and reuses them in its byte-setting updates.
The corrected C frame is `0x58`, matching the ROM rather than the former
`0x48`; the function retains the same 33 ordered direct calls. The fresh
isolated result is 3,424/3,492 bytes, 835 differing words, 17 missing and no
extra words. This is a ROM-supported source-lifetime recovery, not an exact
match or a demonstrated runtime bug. Both ROM values are 255.0 in the
unclassified raw remainder segment; no global immutability or ownership is
claimed. Details and load sites are in `func_8001E6C0.md`.

A private host harness with helper stubs and ten fixed state cases passed for
both the original and updated function under UBSan, including zero/multiple
controllers, upper/lower clamps, ordinary decreases, and early quit. Reproduce
from the repository root with:

```sh
gcc -std=c99 -Wall -Wextra -Werror -fsanitize=undefined -fno-sanitize-recover=all -I include /tmp/us26-structure-two/behavior/harness.c /tmp/us26-structure-two/behavior/old-func.c -o /tmp/us26-structure-two/behavior/test-old
/tmp/us26-structure-two/behavior/test-old
gcc -std=c99 -Wall -Wextra -Werror -fsanitize=undefined -fno-sanitize-recover=all -I include /tmp/us26-structure-two/behavior/harness.c src/functions/func_8001E6C0.c -o /tmp/us26-structure-two/behavior/test-new
/tmp/us26-structure-two/behavior/test-new
```

The updated source's isolated canonical audit is reproducible with
`python3 tools/audit_c_unit.py --config config/c_matching.json --unit func_8001E6C0 --build-root /tmp/us26-structure-two/final-audit`.
No compiler configuration or test files changed. A six-profile IDO 5.3 sweep
(O1/O2/O3 × MIPS II/MIPS III-32) found no exact build:

| Profile | C bytes | Word differences | Size delta (words) |
| --- | ---: | ---: | ---: |
| O1 MIPS II | 3676 | 859 | 46 extra |
| O1 MIPS III-32 | 3344 | 827 | 37 missing |
| O2 MIPS II | 3424 | 835 | 17 missing |
| O2 MIPS III-32 | 2956 | 721 | 134 missing |
| O3 MIPS II | 3424 | 835 | 17 missing |
| O3 MIPS III-32 | 2956 | 721 | 134 missing |

No flags or configuration changes were retained. The complete USA ledger,
run with 32 jobs, reports 1,183 exact functions / 363,220 bytes; all 1,183 canonical
roundtrip substitutions were byte-identical (SHA1
`3542d5597c8a56ea8f5c63bceae97a24c4c08d58`). `make test` passed 32 tests,
along with safety, strict-manifest, and USA-only inventory gates. Validation
artifacts are in `/tmp/us26-structure-two/validation/`.


## US27 bounded no-match tranche

No source or configuration candidate was retained; exact coverage remains 1,183
functions / 363,220 bytes. The following observations are from isolated probes
and do not establish broader source or ABI conclusions.

- `func_80006C00`: both natural loop forms over the unchanged global bounds
  emitted 328 bytes against the 348-byte ROM, each with 76 differing words.
  Both use a `0x38` frame against ROM `0x30`; bound reloads were already
  separate, so neither form is exact.
- `func_80088BFC`: two orders of two empty function definitions put the empty
  functions at `0x80088B70`/`0x80088B78`; the helper slice at `0x80088B80`
  verified as 124 bytes. The main at `0x80088BFC` measured 1,352 bytes with 20
  differing words. In both orders, its two calls still target `0x80088B80`,
  while ROM calls `0x80088B70`; both preserve the 0x40-byte rodata at
  `0x800ADD90`. The ELF did not establish named helper `STT_FUNC` symbols, and
  definition order did not recover the layout.
- Five-unit structural comparison used each configured raw ROM offset and full
  function size, disassembled as MIPS big-endian, then compared complete linked
  ELF function symbols. The corrected `func_80027D24` raw span includes its
  full 844-byte prefix/body (`0x80027D24..0x80028070`); generated assembly's
  interior label is not a safe extraction boundary.

| Function | ROM / C symbol bytes | ROM → C frame |
| --- | ---: | ---: |
| `func_800125E4` | 980 / 948 | `-8` → none |
| `func_80010B34` | 876 / 840 | `-0xE0` → `-0xE0` |
| `func_80027D24` | 844 / 836 | `-0x48` → `-0x48` |
| `func_8008BC30` | 396 / 400 | `-0x50` → `-0x60` |
| `func_8008EADC` | 520 / 504 | `-0x50` → `-0x58` |

The direct-call sequences match for these five; `8EADC` also has two matching
indirect calls. The stack/save differences in `8BC30` and `8EADC` confirm known
compiler-lifetime mismatches, while `125E4`, `10B34`, and `27D24` add no new
source hypothesis. Raw disassembly and corrected metrics are in
`/tmp/us26-struct-triage/audited-raw-report.md`; the earlier invalid
label-based extraction is retained separately for diagnosis.

The one IDO 5.3 `-O0` trial on unchanged `func_800125E4.c` emitted a 1,656-byte
function (980-byte ROM; 244 differing overlapping words, 169 extra words).
It allocates an 8-byte frame but saves no `$s0` and does not home incoming
`$a1`, unlike ROM's `$s0` save and `sp+0xC` argument home. Source SHA256 was
unchanged (`2595c214872993fa7075dc6a30be53fe8379fcf2fff6fe162ef7eb94072f3620`).
This targeted compiler hypothesis failed; no additional O0 trial is indicated.

For `func_80056844`, the baseline IDO 5.3 O0 form measured 2,896/2,980 bytes
(709 differing words, 21 missing); inlining the exact initializer expressions
for its 23 never-reassigned float aliases emitted 2,448/2,980 bytes (596
differing, 133 missing). All 76 direct calls remained in canonical order. The
literal form's 0x40 frame is smaller than ROM's 0x1B8; baseline frame was
0x98. This is not a size/frame improvement and no third form was tested.
Earlier `pos`/`column` and volatile-constant results remain recorded above.

The USA indirect-call scan checked source and accepted function-slice hashes
for 165 functions. For `func_8008F0B4`, the accepted compiled span starts at
`0x8008F03C`, 0x78 bytes before the canonical `0x8008F0B4`; the scan uses the
accepted actual address and size reported for the compiled span. Its callback
is at relative `+0x3C` in both. This does not establish canonical placement or
ELF symbol size. Across all 165 functions, the scan found 3,070 direct JALs
and 19 link-register JALRs in both ROM and C; the JALRs occur in six functions.
The event-stream comparison checks direct-target and call-kind ordering; 164
functions matched, with `func_80088BFC` the one event-interleaving mismatch. A
separate operand tally confirms all 19 JALRs use `rs25/rd31` (`$t9`/`$ra`), but
neither tally proves runtime target identity, callback dataflow, or ABI
equivalence.
`func_80060DE4` has three ROM `jr` dispatch sites versus one C site; they are
computed switch dispatches backed by raw tables at `0x800AD0B8`, `0x800AD1C4`,
and `0x800AD1F0`, not missed callbacks. Private artifacts: `/tmp/us27-06c00/`,
`/tmp/us27-88bfc-layout/`, `/tmp/us27-56844-o0/`, `/tmp/us27-125e4-o0/`,
`/tmp/us27-indirect-audit/`, and `/tmp/us26-struct-triage/`.

## US28 stack-lifetime and definedness follow-up

Three private captures for `func_80021F84` were nonexact. Its active source is
`src/functions/func_80021F8C.c`; the legacy `src/functions/func_80021F84.c` is
unrelated. The baseline was 2,068/2,068 bytes, 16 differing words, frame
`0xB0`. Capturing the selected index in `value` produced 19 differences and a
spill at `+0x34`, while reuse of `kind` also produced 19 and moved it to
`+0x30`. Reusing `flags` produced
2,084/2,068 bytes, 505 differing words, and frame `0xB8`. The canonical spill
is `+0x2C`. MIPS debug data provided no local-location mapping, so these trials
do not identify a named original local.

Two private pointer-capture forms for `func_80042970` each measured 592/584
bytes, 145 differing words, and two extra words; the C/ROM frames were
`0x160`/`0x158`. Their compiled texts differ by one word at `+0x94`, so the
forms are not duplicates. Historical source coverage remains unknown: 219
archived outputs yielded 56 distinct outputs, but their source inputs are
absent.

`func_80042BB8` retains a block-scoped pointer to `actor->unk050` across the
two helpers that consume that embedded vector. Its linked 820-byte function
matches the canonical pointer spill/reload at `0x80042CC8` and `0x80042D24`,
and remains nonexact at 73 differing words versus the 75-word baseline. The
frame (`0xD0`) and matrix homes are unchanged. Its signed left shift is now a
defined `u32` bit-27 test: canonical `SLL 4` / `BGEZL` at `0x80042C98` /
`0x80042C9C` tests that bit and discards higher bits. The seven-case actual
function shift-sanitizer test passes, including a helper mutation observed by
the later copy through the same vector address; the original fails UBSan on
`0x08000000`. The symbol-prefix SHA256 is
`4989f16439a9c114f038459084656765fd3fafc1a73a4608b55c7a37aaefbc2f`.

Full validation artifacts are under `/tmp/us28-42bb8-validation/`. All 1,348
current USA source hashes were checked; the exact name/hash/size set is
unchanged at 1,183 functions / 363,220 bytes, with a byte-identical USA
roundtrip (SHA1 `3542d5597c8a56ea8f5c63bceae97a24c4c08d58`). Host regressions,
32 Python tests, safety, strict manifest, and USA-only inventory pass. No exact
bytes were added, so the chart is unchanged.

Private evidence paths: 21F84 captures `/tmp/us28-21f84-flags/` and
`/tmp/us28-21f84-last2/`; 42970 pointer forms 1 and 2 are in
`/tmp/us27-42970-pointer-locals/`.

## US29 transition-dispatch follow-up

The later third pointer form for `func_80042970` was also nonexact and falls
outside the US28 token interval. It measured 592/584 bytes, with 144 differing
words and two extra words; its frame is `0x158` and saves an additional `$s1`.
The private form is under `/tmp/us27-42970-pointer-locals/form3/`. No fresh
source forms were run for `func_80031324` or `func_80040050` in this tranche.

For `func_80060DE4`, the label-only table layout emitted 320 rodata bytes;
the internal-literal form emitted 352 bytes but still had 42 differing words
in the primary table. A full-pool form also internalized the initial `0.1f` /
`0.2f` reads, but its first two emitted words reversed that order (`0.2f`, then
`0.1f`). It placed generated rodata at `0x800AD0B0` and emitted a 360-byte
payload plus 8 bytes of alignment padding.
The raw words immediately after the compared 352-byte span, at ROM
`0xADE18/0xADE1C`, are `0x80062C64/0x80062328`; the full-pool padding would
extend past that span, so that form was rejected. These generated spans do not
establish the original unit boundary.

The retained C uses the ten verified ROM pool values as typed literals,
adds explicit case-4 labels before the two nested switch defaults, and keeps
the ROM-evidenced duplicate `unk88 = 0` store from case `0x22` falling through
to case `0x1E`. Its generated 352-byte rodata spans `0x800AD0B8..0x800AD218`;
the two nested five-word tables and both literal pools match ROM, while 42
primary-table words differ. The exact function symbol is 5,228/5,260 bytes,
780 words differ and 8 words are missing (32 bytes); the frame is `0xA0` versus
ROM `0x98`. Its function-slice SHA256 is
`8ea121a4d821fbb8017df4a85654be419209976a2b9db7c497233a56ab58c136`; source
SHA256 is `05b83f4540268a3b76cefe2ff0d79f4b5fc9cd9ae5ac086a5cdbf59a1740c6e9`.
A fixed ten-case actual-function UBSan fixture passes with `-Wall -Wextra
-Werror`; it is private at `/tmp/us29-60de4-harness/test_fallthrough.c`.
Stage artifacts remain under `/tmp/us29-60de4-case4/`.

Final validation artifacts are under `/tmp/us29-60de4-validation/`. The
authoritative IDO 5.3 O2 ledger has all 1,348 source hashes current; the exact
name/hash/size tuple remains 1,183 functions / 363,220 bytes. The USA32
canonical roundtrip is byte-identical. `make test` (32 Python tests and host
targets), safety, strict manifest, USA-only inventory, and diff check pass.
No new test or Makefile change was needed; the generated host stubs dropped
the ten unused globals.

## US30 bounded lifetime, table and pool checks

The private `func_80060DE4` case-`0x14` lifetime reconstruction was rejected:
5228/5260 symbol bytes and eight missing words stayed unchanged, while
aligned word differences rose from 780 to 810. The frame stayed `0xA0`
versus ROM `0x98`; delta moved from `sp+0x94` to `sp+0x54`, versus ROM
`sp+0x4C`. All 56 ordered calls and the 352-byte generated rodata were
unchanged. The 5232-byte text section includes four padding bytes excluded
from symbol comparison. Artifacts: `/tmp/us30-60de4-frame-sol/case14/`.

A read-only alias audit found all 61 raw and compiled target words identical
across four tables in three functions: `8005337C` (7), `8008F3FC` (17), and
`8004BE90` (19 plus 18). No case-grouping hypothesis or compile followed.
Details: `/tmp/us30-table-alias-triage/report.md`.

The retained `func_8000D5EC` field cache follows ROM's single-read bit-toggle
lifetime and removes its redundant else-path load. Its symbol shrinks from
512 to 504 bytes for ROM's 496; differing overlap words rise from 69 to 70,
and extra words fall from four to two. Frame `0x20` and all five ordered
calls agree with ROM. The explicit cached-field pointer form emits identical
bytes and was not retained. The earlier toggle audit reported 71/68 words
before the accepted pool correction; its separately identified pointer-trial
input is unavailable, so that historical coverage relies on the recorded
notes. Available direct-global and later source copies contain neither new
cache form. The 504-byte symbol excludes eight bytes of section padding.
The semantic table is 36 bytes at `0x800A863C`, with one differing target;
twelve artifact padding bytes follow and overlap raw ROM words
`C0C387FE B851EB85 00000000`, not an established 48-byte owned pool.

The changed cache source was checked under six IDO 5.3 profiles, with actual
commands checked against per-unit flags. None matched. O1/MIPS II and
O1/MIPS III-32 each emit 528 bytes, 118 overlap differences and eight extra
words; O2/O3 MIPS II each emit 504 bytes, 70 differences and two extra
words; O2/O3 MIPS III-32 each emit 504 bytes, 71 differences and two extra
words. All use canonical `0x8000D5EC` and have no missing words. O2/MIPS II
reused the identical prior effective flags/source result. Artifacts:
`/tmp/us30-wrongsize-sol/cached-toggle/`, `cached-pointer/`, and
`cached-toggle/profile-check/summary.json` under that same parent.

The private `func_800320E0` literal form was rejected: symbol size stayed
272 bytes and overlap differences rose from nine to twelve. Its twelve
correct payload bytes are at full VRAM `0x800AA3A0`, `0x800AA3A4`, and
`0x800AA3A8`; four section-padding bytes overlap the neighboring word at
`0x800AA3AC` (raw `80032214`). Artifacts:
`/tmp/us30-small-pools/320e0-pilot/`. `func_80014F54` received only a
read-only verification of its eleven-value pool; it was not compiled, and
this establishes no immutability claim. Raw pool artifacts:
`/tmp/us30-small-pools-320e0.bin` and `/tmp/us30-small-pools-14f54.bin`.

The final `func_8000F0DC` read-only follow-up stopped at 1236/1220 bytes
and frames `0x78/0x60`. Extra `$s8` and `$f20` preservation accounts for
four additional words, but the input, volume and intensity lifetimes agree
with ROM's stack-held values. No natural source hypothesis or compile
followed. Evidence: `/tmp/us30-0f0dc-live/assessment.txt`.

Final validation passes. The isolated approved `func_8000D5EC` source
produces 504/496 symbol bytes, 70 overlap differences and two extra words;
source SHA256 is
`5994e7d3f117a3351690794cc1b851684c50473bc612f1a5d126a0397bb5fca0`.
The canonical ledger explicitly uses `ido53_o2`, with all 1,348 source
hashes and its configuration hash current. Its exact name/hash/size set is
unchanged at 1,183 functions / 363,220 bytes. The USA32 canonical roundtrip
is byte-identical at SHA1 `3542d5597c8a56ea8f5c63bceae97a24c4c08d58`.
All 32 tests, safety, strict manifest, USA-only inventory and diff check pass.
Logs are `/tmp/us30-0d5ec-validation/{isolated,ledger,roundtrip,test,safety,manifest,inventory}.log`.
This is a natural single-read source recovery, not an exact match or a
runtime-bug claim; no exact bytes were added.
