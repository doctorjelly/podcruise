# Decompilation handover after the bulk recovery round

Audit date: 2026-08-20 (America/Los_Angeles)

Baseline: `main` at `a67e8297a8165174d7d62d9272c20bb91cd0935f`
(`Stop committing ROM-derived analysis output, and use neutral input names`).
The worktree was clean before this handover was written.

This file is the current operational handover for Claude or another agent. The
coverage figures in `STATE_OF_THE_ART.md`, `docs/ROADMAP.md`, and
`analysis/REPORT.md` are older snapshots. `docs/DECOMP_STATUS.md` is closer,
but its LRG and configured-unit figures are also stale. Regenerate those files
only after the source manifest is green.

## Goal and reporting rule

The canonical goal is independently written, reviewed C that IDO compiles to
the USA ROM bytes exactly. Japan and Europe must be mapped and compared
independently; LRG is an independent USA-revision build target. An assembly
round trip is infrastructure, not C decompilation.

Keep these categories separate:

- **Fact:** directly established from ROM bytes, control flow, a fresh tool
  result, or a passing build.
- **Inference:** a boundary, type, translation-unit grouping, or regional
  correspondence still needing direct proof.
- **Behavior-recovered C:** source and an original behavior specification exist,
  but bytes do not match or have not been compared.
- **Byte-matching C:** the accepted compiler profile produced exactly the
  canonical bytes. Nothing else earns this label.

For each function, confirm its real entry and return delay slot, incoming
branches, callers, callees, global access widths, and regional equivalents
before editing C or configuration.

## Freshly verified state

`make match-c` and `make roundtrip-all` were rerun from this commit during the
audit. These are facts:

| Build | Configured functions | Exact functions | Exact bytes | Hybrid rebuild |
|---|---:|---:|---:|---|
| USA | 1,074 | 913 | 189,860 | byte-identical |
| LRG revision | 1,074 (inherits USA) | 913 | 189,860 | byte-identical |
| Japan | 838 | 832 | 166,080 | byte-identical |
| Europe | 837 | 832 | 173,400 | byte-identical |

The USA CPU-text denominator currently documented in
`docs/SEGMENTATION.md` is 621,540 bytes, so exact USA C is 30.55% of that
denominator. The USA verifier measures 283,360 target bytes in total. Its 161
nonmatching functions therefore account for 93,500 measured target bytes; 85
of those functions already compile to the correct size.

The exact round-trip SHA-1 values are:

- USA: `3542d5597c8a56ea8f5c63bceae97a24c4c08d58`
- LRG: `f71908f15a14ee124f9b471467432ade87e0951c`
- Japan: `9577ccd2d069d0e7e306cf21ddb0e4765a308072`
- Europe: `899a8245da017289c88e97327fdcd6694b770a25`

The accepted default profile remains IDO 5.3 with:

```text
-G 0 -O2 -mips2 -non_shared -Xcpluscomm -signed -Wab,-r4300_mul
```

Per-unit `flags`, `rodata_vram`, and `text_offset` are supported and already
needed for non-default and whole-translation-unit cases.

## What is broken after the last round

Do not begin another broad recovery wave yet. The bulk round added much more C
than its bookkeeping and host tests can currently support.

### 1. The strict source manifest fails

There are 1,222 tracked C files under `src/functions/`. `make manifest` reports
1,074 configured functions / 283,360 target bytes, then fails because 185
source files have no matching unit. Two have legitimate recorded regional-only
reasons; **183 are unexplained**.

This violates the project's standing invariant that every recovered source is
measured or has a narrow recorded reason. Until it is fixed, 1,074 is a
verifier-configuration count, not a defensible count of every C file in the
tree.

Three obvious filename/definition collisions should be audited first:

- `src/functions/func_8000EEE0.c` is reported as defining `func_80062EC8`.
- `src/functions/func_800290B4.c` is reported as defining `func_800290A4`.
- `src/functions/func_8002E134.c` is reported as defining `func_8002E124`.

Do not solve this by broadly allowlisting the 183 files. For each source,
either establish the real function extent and add a verifier unit, merge it
into the correct translation unit, or record a specific evidence-backed reason
why it is not an independent USA function.

### 2. `make test` fails in the host link

`make host-check` and `make prototypes` pass, but `make test` regenerates
`tests/host_link_stubs.c` and then fails. The current failures are:

| Source | Host failure | Current USA status |
|---|---|---|
| `func_800401FC.c` | unused `D_800AAC30` | unmeasured |
| `func_80042EEC.c` | unused constant-pool stand-in reference | exact |
| `func_80063344.c` | unused `rodataFiller` | exact |
| `func_8007C818.c` | unused `padPool` | measured, nonmatching |
| `func_8006E008.c` | uninitialized `state` | exact |
| `func_80082C80.c` | possibly uninitialized `holder` | exact |
| `func_800845A0.c` | possibly uninitialized `dummy` | unmeasured |
| `tests/test_global_state.c` | calls `func_80014F2C` with no argument | callee exact; prototype requires one `f32` |

The host compiler also warns that `func_80017D80`, `func_80053220`, and
`func_8007B34C` can fall off non-void functions. Those three are exact and the
Makefile intentionally downgrades that warning because the ROM has paths that
leave the return register untouched.

Do not “fix” exact functions by initializing locals or adding returns without
rerunning the exact compiler comparison. Some unusual C is deliberately
reproducing a file-local `-O3` register interface or original undefined
behavior. Prefer narrowly documented host-only handling for proven exact
cases. Unmeasured sources should instead be made valid and behaviorally sound
before they are counted.

`tools/gen_host_stubs.py` currently generates a large update to the tracked
stub file because the source tree grew. Commit that generated update only after
the host build itself passes. The audit restored the tracked version so this
handover is not mixed with a 1,300-line generated diff.

### 3. Status and classification documents disagree

Current stale examples:

- `STATE_OF_THE_ART.md` says 506 exact USA functions.
- `docs/ROADMAP.md` and `analysis/REPORT.md` say 439.
- `docs/DECOMP_STATUS.md` says 913 USA but 912 LRG and 1,072 configured.
- Fresh verification says 913 USA/LRG and 1,074 configured.

`make classify` currently emits 27 non-C candidates / 4,332 bytes, 33
branch-only interiors, and 183 unreferenced bodies. Treat the decisive
instruction classes as useful evidence, but do not trust its byte totals or
all its extents yet. It still consumes coarse generated labels and contradicts
manually established boundary corrections, including the exception-handler
area. It also still presents the `0x80097FF0` signal-processor transfer image
as function-like labels. Make classification consume verified extents or mark
its output provisional before using it as a denominator.

### 4. Regional coverage is not yet complete

Japan and Europe have very few configured mismatches, but their configs contain
236/237 fewer functions than USA. Some difference is legitimate version drift;
the rest must be mapped rather than assumed absent. A USA byte match never
automatically grants a Japan or Europe match.

## Immediate plan

### Milestone A: restore a green, honest baseline

1. Fix the host-test failures above without regressing exact IDO results.
2. Regenerate and commit `tests/host_link_stubs.c` once `make test` passes.
3. Triage the 183 unexplained sources in bounded groups and make
   `make manifest` pass strictly.
4. Re-run all match and round-trip reports.
5. Regenerate the status/report documents from the now-complete manifest.

This is integration work, not optional cleanup: new recovery cannot be counted
reliably while sources bypass the verifier.

### Milestone B: integrate the safest unmeasured sources

Four unmeasured sources received temporary isolated USA probes during this
audit. These are **inferences and behavior-only results**, not accepted config
entries:

| Source entry | Boundary hypothesis | Temporary IDO 5.3 result | Regional evidence |
|---|---:|---|---|
| `func_80030964` | 280 bytes | 280/280, first difference `0x15` | JP `0x800313C4`, EU `0x80033F24` |
| `func_80050F88` | 560 bytes | 556/560, first difference `0x3B` | JP `0x80051BF4`, EU `0x80055C30` |
| `func_80082BE0` | 160 bytes | 152/160, first difference `0x13` | EU `0x800880C0`; JP not unique |
| `func_8008528C` | 1,328 bytes | 1,312/1,328, first difference `0x1` | JP `0x80085F80`, EU `0x8008A76C` |

Recheck each full extent, return delay slot, external branch, and absolute
symbol list, then add USA units as behavior-only if those facts hold. Do not
add YAML splits until exact. These four are useful because they turn existing
C into measured work without pretending it matches.

Several other orphan filenames start at analyzer labels that are only a
prelude inside a larger function. The local USA disassembly established that
these short labeled fragments do not return:

- `func_8000D9A8`: two instructions
- `func_80024954`: three instructions
- `func_80028E78`: four instructions
- `func_800290A4`: four instructions
- `func_8002C780`: three instructions
- `func_8002CC28`: three instructions
- `func_8002DA0C`: seven instructions
- `func_80050F88`: two-instruction prelude at the label
- `func_80082BE0`: two-instruction prelude at the label

Do not configure any of those fragment lengths as functions. Establish the
parent/full extent and use one matching unit for the actual C body.

### Milestone C: recover the getter-table island

USA `0x8002D5C8` through `0x8002D6DB` contains 23 consecutive real 12-byte
address-return callbacks, each with a `jr $ra` and an address-forming delay
slot. Their addresses are taken by a table even though no direct `jal` caller
exists. `func_8002D6DC` is a related 16-byte return.

Existing unmeasured sources cover `func_8002D64C` through `func_8002D6B8`.
Missing callbacks before and after that range can be recovered as one bounded
behavior tranche. A temporary `func_8002D64C` probe had the correct 12-byte
size but used `$v0` as the address base where the target uses `$v1`, so it was
not exact. Compile the original-looking callback group and its function-pointer
table as a coherent translation unit before spending time on isolated source
permutations.

Japan becomes uniquely mappable from USA `func_8002D664` onward at roughly a
`+0xA64` relocation. Earlier Japan and Europe members are too short and
identical for unique byte search; locate the complete table by adjacency and
the relocated global destinations.

### Milestone D: target correct-size near matches

After the baseline is green, the best exact-match queue is the 85 USA
mismatches already at the correct size. Start with this bounded ten-function
tranche and read any existing spec notes before trying source shapes:

| Function | Size | First difference |
|---|---:|---:|
| `func_8008D274` | 16 | `0x5` |
| `func_8008C738` | 48 | `0x0` |
| `func_8001004C` | 52 | `0x16` |
| `func_8008D22C` | 72 | `0x1` |
| `func_8002FE94` | 80 | `0x4` |
| `func_80038D5C` | 96 | `0x41` |
| `func_8008C280` | 112 | `0x21` |
| `func_80030B90` | 120 | `0x2D` |
| `func_800903D0` | 120 | `0x35` |
| `func_80063AE0` | 128 | `0x3` |

Use whole-object experiments when file-local `-O3` allocation, constant-pool
placement, or sibling clobbers are plausible. Do not burn a long turn trying
random expression permutations for one scheduler difference.

### Milestone E: rebuild the remaining-work queue

The `163 functions / 44,312 bytes` queue in `docs/NEXT_DECOMP_PLAN.md` predates
the bulk import and should not be assigned again blindly. Once Milestones A and
B are complete:

1. regenerate candidate/reference/branch ledgers;
2. subtract exact units, behavior-only units, verified branch interiors,
   signal-processor images, data, and proven hand-written assembly;
3. stage the remaining genuine C by translation-unit island, not merely by
   small analyzer label;
4. map each accepted USA island to Japan and Europe before closing it.

The hand-written routines with decisive coprocessor/cache/kernel-register or
other compiler-impossible instructions remain assembly in an exact rebuild;
they are not failures to recover original C because no original C could have
produced them. Keep that set small and evidence-backed.

## Working procedure for Claude

Read in this order at the start of a session:

1. `STATE_OF_THE_ART.md`
2. `docs/IP_POLICY.md`
3. `docs/DECOMP_STATUS.md`
4. `docs/ROADMAP.md`
5. `analysis/REPORT.md`
6. this handover

For current metrics, prefer a fresh generated report over the stale narrative
documents. Generated ROM-derived reports and disassembly are ignored and must
not be committed.

Start with:

```sh
git status --short
python3 tools/rom_inventory.py \
  --config config/versions.json \
  --output analysis/roms.json \
  --check
```

For each function:

1. Inspect the complete USA body, including entry prelude and return delay slot.
2. Inspect incoming branches, direct callers, callees, globals, and access widths.
3. Locate Japan and Europe independently using adjacency and relocation evidence.
4. Write an original compact behavior specification.
5. Write independently expressed C; keep address names until semantics justify
   a better name.
6. Add an isolated or evidence-backed grouped matching unit.
7. Run the accepted compiler comparison and record behavior-only versus exact.
8. Add a YAML C split only for a region proven exact.

Centralize edits to shared JSON, YAML, headers, tests, and ledgers. If using
parallel workers, give each worker exclusive source files and re-prove every
claimed match centrally.

## Required gates

The desired final gate is:

```sh
make match-c && make roundtrip-all && make manifest && make classify
make test && make safety && git diff --check
python3 tools/rom_inventory.py \
  --config config/versions.json \
  --output analysis/roms.json \
  --check
```

At this handover, `make match-c`, `make roundtrip-all`, `make classify`,
`make host-check`, `make prototypes`, `make safety`, the ROM inventory, and
`git diff --check` pass. `make manifest` and the full `make test` gate do not
pass for the separate reasons above.

## Provenance and repository safety

- Use only the maintainer-supplied ROMs and independently derived local
  evidence for source recovery.
- Do not copy source, comments, types, or authored symbols from unlicensed
  prior decompilation/reverse-engineering repositories.
- Local IDO static-recomp binaries are approved uncommitted tools. Never commit
  or redistribute them and do not add download/install automation for them.
- Never commit ROMs, extracted assets, generated assembly, rebuilt binaries,
  compiler/SDK files, or binary-derived reports.
- Never use `git add -f` on ignored game-derived material.
- Stage explicit safe paths and inspect the staged diff before each small
  commit.

The next successful handover should have a passing strict manifest and host
test, freshly generated consistent status metrics, no unverified YAML split,
and all four hybrid rebuilds still byte-identical.
