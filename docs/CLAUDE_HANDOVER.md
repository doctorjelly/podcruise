# Decompilation handover

Audit date: 2026-08-19. This is a handover for continuing source recovery from
the current working tree, especially with Claude or another low-cost agent.

## Objective and non-negotiable definition of progress

The project goal is reviewed C which eventually rebuilds the canonical USA ROM
byte-for-byte. Japan and Europe are structural, relocation, and source-version
evidence. The LRG revision is an independently verified build target. An exact
assembly round trip is necessary infrastructure, but it is not C decompilation.

For every recovered function, verify the complete boundary and MIPS delay slot,
inspect callers/callees/globals/regional equivalents, write an original compact
behavior specification, then write independently expressed C. Keep address
names until semantics justify more. Report **behavior recovered** separately
from **byte-matching**. Only the compiler verifier can establish the latter.

Start each session by reading, in order:

1. `STATE_OF_THE_ART.md`
2. `docs/IP_POLICY.md`
3. `docs/DECOMP_STATUS.md`
4. `docs/ROADMAP.md`
5. `analysis/REPORT.md`
6. this file

Then run `git status --short` and the ROM inventory check shown below.

## Critical working-tree warning

Branch `main` is at commit `41e476f054b7` (`Bootstrap IP-safe multi-version
decompilation`), but essentially the entire current decompilation tranche is a
dirty/untracked working tree: this audit saw 64 changed or untracked paths
before adding this file. Do not treat HEAD as the current project baseline.

Do not run `git reset`, `git checkout`, `git clean`, or bulk-delete untracked
files. Do not rewrite unrelated changes. In particular, there is an untracked,
zero-byte file whose filename is one space (`./ `, mode 0664). It is probably
accidental, but it has not been removed because ownership is unclear.

## Verified state

These are facts from fresh IDO 5.3 `-O2` verifier and rebuild reports:

| Build | Exact C functions | Exact C bytes | Current rebuilt SHA-1 |
|---|---:|---:|---|
| USA retail | 506 | 49,308 | `3542d5597c8a56ea8f5c63bceae97a24c4c08d58` |
| LRG revision | 506 | 49,308 | `f71908f15a14ee124f9b471467432ade87e0951c` |
| Japan retail | 462 | 45,392 | `9577ccd2d069d0e7e306cf21ddb0e4765a308072` |
| Europe retail | 458 | 44,764 | `899a8245da017289c88e97327fdcd6694b770a25` |

All four reports have `byte_identical: true` and no first difference. The
current gates also pass: ROM inventory, 25 host/tool tests, `make safety`, and
`git diff --check`.

The hand-maintained behaviour headline is retired. `make manifest` generates
`analysis/source_manifest.json` from the matching configuration and the
per-version comparison reports: 562 functions have reviewed C covering 61,476
canonical bytes, of which 506 match exactly. The target fails if any source
under `src/` is not measured by a matching unit, so the headline cannot drift
again. Three sources are deliberately unmeasured and carry a recorded reason in
`tools/make_source_manifest.py`.

There is no defensible total decompilation percentage yet. The current
`0x1000`-`0x99000` interval mixes CPU code, data, RSP microcode, and assets.

## What the last round established

### Exact C

- `func_80017BA8` is an exact 112-byte USA function and matches independently
  in Japan, Europe, and LRG. It copies selected floats into an object
  substructure and sets two low flag bits.
- `func_80015390` is exact at 48 bytes with the direct grouped dot-product
  expression now in `src/functions/func_80015328.c`.
- The existing exact wait/state functions `func_8002DFBC`, `func_8002E034`,
  and `func_8002E0B4` remain exact in all configured regions.

### Audit correction

LRG's verifier had 137 exact functions, but its split YAML substituted only
133. `config/lrg_rev1.yaml` was missing C splits for `func_80017BA8`,
`func_8002DFBC`, `func_8002E034`, and `func_8002E0B4`. Those four splits are
now present. A fresh LRG round trip substitutes 137 functions and remains
byte-identical.

### Behavior-recovered C

- `func_80017B3C`: forwards two floats and one word to `func_8001734C` using
  the substructure at `+0x1C`, then sets flag bits 0 and 1.
- `func_80017B7C`: stores three `f32` arguments at `+0x40`, `+0x44`, and
  `+0x48`, then sets flag bits 0 and 1. The original round incorrectly typed
  the last argument as `f64`; this audit corrected it to `f32`. The resulting
  compiler output has the exact 44-byte size and differs only in scheduling.
- `func_80017C18` and `func_80017C98`: produce a 16-float output. Element 0 is
  source `+0x1C`; elements 3, 7, and 11 are zero; elements 1, 2, 4-6, 8-10,
  and 12-14 copy source `+0x20` through `+0x48`; element 15 is `1.0f`. The
  previous C/spec had three positions reversed. This audit corrected both C
  files and the specification. Both now compile to the exact 128-byte size and
  first differ at byte offset `0x01`; they are not byte matches.
- `func_80011838`, `func_80011888`, `func_800152CC`, `func_80015630`, and
  `func_80008548` have reviewed behavior and source but remain nonmatching.

The host test for `func_80017B3C` uses a weak `func_8001734C` stub in
`tests/host_link_stubs.c`; that proves the wrapper's observable behavior, not
the callee's behavior or ABI.

## Current USA mismatch inventory

Straight from `analysis/c_matches.us.json`. Every recovered source now has a
matching unit, so this table is the complete set of reviewed C that the
identified compiler does not yet reproduce. `actual/target` are compiled and
canonical sizes in bytes.

| Function | Actual/target | First difference |
|---|---:|---|
| `func_80006704` | 144/140 | `0x61` |
| `func_80008548` | 188/8 | `0x8` |
| `func_8001004C` | 52/52 | `0x16` |
| `func_80011838` | 176/80 | `0x1F` |
| `func_80011888` | 104/8 | `0x8` |
| `func_800129E4` | 368/376 | `0x4` |
| `func_800152CC` | 88/84 | `0x1` |
| `func_80016BF4` | 184/184 | `0x15` |
| `func_80017B3C` | 68/64 | `0x0` |
| `func_80017B7C` | 44/44 | `0x0` |
| `func_80017C18` | 128/128 | `0x1` |
| `func_80017C98` | 128/128 | `0x1` |
| `func_80017E88` | 88/84 | `0xC` |
| `func_800183C0` | 120/120 | `0x15` |
| `func_80029C24` | 276/276 | `0x1E` |
| `func_8002E6E0` | 144/20 | `0x1` |
| `func_8002FB90` | 196/200 | `0x3` |
| `func_8002FC80` | 56/88 | `0x1` |
| `func_800320E0` | 272/272 | `0x6` |
| `func_80034650` | 392/392 | `0x0` |
| `func_800358A0` | 176/172 | `0x64` |
| `func_8003D370` | 212/212 | `0x1` |
| `func_8004110C` | 264/264 | `0x15` |
| `func_8004E034` | 112/108 | `0x3` |
| `func_8004FF7C` | 52/44 | `0x14` |
| `func_80050208` | 136/136 | `0x1` |
| `func_8006FED0` | 8/24 | `0x0` |
| `func_80089290` | 248/236 | `0x0` |
| `func_8008D22C` | 72/72 | `0x1` |
| `func_8008D274` | 16/16 | `0x5` |
| `func_8008F34C` | 176/176 | `0x1` |
| `func_80090B24` | 228/252 | `0x9` |
| `func_80092850` | 472/156 | `0x7` |
| `func_80095B68` | 176/184 | `0x5` |

Most of these are correct behaviour at the correct size, differing only in
which register the compiler chose. The per-function notes in
`specs/functions/recovered/` record what was already ruled out, so do not
repeat those experiments.

The Japan and Europe configured mismatch subsets are the relocated forms of the
same functions. Do not infer a regional match from a USA result.

## Recommended next source tranche

The easy isolated leaves are largely exhausted. Stop spending long turns on
source permutations for one scheduling `nop`. Recover a bounded, contiguous
source island so prototypes, types, and translation-unit scheduling can inform
one another.

### Priority 1: transform/object island `0x8001723C`-`0x80017D47`

Work outward from the exact `func_80017BA8` and the corrected neighboring
sources. Start in this order:

1. `func_80017D18` (48 bytes, three direct callers). It calls
   `func_800174B8`, then exact `func_80017BA8`; the complete USA body and delay
   slot are already clear. Japan is at `0x80017E48`, Europe at `0x800181A8`.
2. `func_800174B8` (104-byte analyzer candidate, 17 direct callers). Japan is
   at `0x800175E8`, Europe at `0x80017948`. Establish its actual output layout
   from `func_80017D18` and several other callers before choosing a type.
3. `func_8001734C`, the unresolved callee of behavior-recovered
   `func_80017B3C`. The analyzer's 272-byte entry is only a starting boundary
   hypothesis: inspect the neighboring `func_8001745C` entry and all incoming
   branches before splitting it. The normalized 32-byte regional mapper did
   not find a unique Japan/Europe match, so locate regional bodies through
   adjacency and relocated callers rather than assuming a delta.
4. Continue only as far as the small related entries `func_8001745C`,
   `func_80017520`, and `func_80017580` if call/type evidence indicates the
   original functions shared a translation unit.

For each entry, write facts before semantics. In particular, confirm whether
an apparent entry is a true callable boundary, a shared tail, or an internal
branch target. Build an isolated USA verifier unit first. Group functions in
one C file only when ordering/alignment or shared static data supports a common
original object.

This island should also provide the new context needed to revisit
`func_80017B3C`, `func_80017B7C`, `func_80017C18`, and `func_80017C98`.

### Priority 2: context-driven mismatch cleanup

After the transform island has stable types/TU grouping:

- retry the four nearby behavior-only functions as a grouped unit;
- retry the vector group `func_800151C0`, `func_800153C0`,
  `func_800153EC`, and exact neighbor `func_80015390` as a coherent source
  object rather than isolated expressions;
- revisit `func_80017E88`/`func_800183C0` only if the object layout becomes
  firmer;
- prioritize materially wrong source shapes (`func_80017FD0`,
  `func_8002E82C`, `func_800156DC`) over endlessly permuting already-correct
  scheduling mismatches.

`func_8002E6E0` has a source candidate, but its analyzer size of 20 bytes is
not a credible full matching unit. Resolve its boundary before counting or
configuring it. `func_80034824` and `func_80038734` are region-specific empty
stubs for Japan and Europe respectively; neither is a canonical USA recovery.

### Short metrics cleanup, not a scaffolding project

Create one explicit, reviewable source-recovery manifest (or extend the current
evidence ledger) so candidate name, canonical ROM/VRAM, corrected size, spec,
source, and status have one definition. It must handle shared-tail effective
sizes and the three bootstrap functions. Make `tools/make_report.py` consume
that source, then regenerate the status documents. Keep this bounded; source
recovery remains the main work.

## Boundary traps already established

- `func_800152CC` spans `0x800152CC`-`0x80015327` (92 bytes). The apparent
  `0x80015320` entry is its shared false-return tail.
- `func_80011888` starts at `0x80011888`, not the apparent prologue at
  `0x80011890`; the preceding global load is executed and consumed.
- `func_80008548` starts at `0x80008548`, not `0x80008550`, for the same
  pre-prologue-load reason. Its full size is 200 bytes.
- `0x80018178`, `0x8001818C`, and `0x800181A0` are internal/shared tails of
  the exact 88-byte `func_80018164`, not separate functions.

## Exact workflow

Start-of-session checks:

```sh
git status --short
python3 tools/rom_inventory.py \
  --config config/versions.json \
  --output analysis/roms.json \
  --check
```

Per function:

1. Inspect the complete USA body including the return delay slot, every direct
   caller and branch target, callees, global access widths, and neighboring
   boundaries.
2. Inspect Japan/Europe bodies independently; relocation is evidence, not
   proof.
3. Add original prose to the closest `specs/functions/*.md` file.
4. Write clear C in `src/functions/` using address names and established types.
5. Add an isolated matching unit to the relevant `config/c_matching*.json`.
6. Run `make match-c`. Record behavior-only status if bytes differ.
7. Add C splits to YAML only for versions which match exactly.
8. Run `make roundtrip-all` after any split change.

Before handoff or presentation, always run:

```sh
make test
make safety
git diff --check
```

## IP and provenance requirements

- Never commit ROMs, extracted assets, generated assembly, ELFs, rebuilt ROMs,
  IDO/compiler binaries, or proprietary SDK material.
- Never use `git add -f` on ignored game-derived files.
- Local IDO static-recomp binaries are maintainer-approved tools only; keep
  them uncommitted and do not add download/install automation.
- Do not copy source, comments, types, or authored symbols from
  `SW_RACER_RE`, `sp00nznet/racer`, or other unlicensed prior art. Those repos
  are not provenance for this source tree.
- Generated binary-derived material stays under ignored `analysis/generated/`
  or `build/` paths.

## Useful project files

- Canonical matching config/report: `config/c_matching.json`,
  `analysis/c_matches.us.json`
- Regional matching configs/reports: `config/c_matching.jp.json`,
  `config/c_matching.eu.json`, `config/c_matching.lrg_rev1.json`
- Split configs: `config/us.yaml`, `config/jp.yaml`, `config/eu.yaml`,
  `config/lrg_rev1.yaml`
- Exact rebuild reports: `analysis/rebuild.*.json`
- Current execution guide: `docs/NEXT_DECOMP_PLAN.md`
- Function/spec sources: `src/functions/`, `specs/functions/`
- Local ignored disassembly: `analysis/generated/<version>/asm/`

## Definition of a successful next handoff

A useful next tranche ends with reviewed behavior for the selected island,
exact comparisons recorded for every attempted function, YAML substitutions
only for genuine regional matches, all four round trips still byte-identical,
and tests/safety/diff checks passing. Do not report a decompilation percentage
until executable/data/microcode/asset classification supplies a real
denominator.

## Parallel tranche status (checkpoint)

Verified from fresh generated reports, not by hand:

| Build | Exact C functions | Exact C bytes | Round trip byte-identical |
|---|---:|---:|---|
| USA retail | 380 | 30,876 | true |
| LRG revision | 380 | 30,876 | true |
| Japan retail | 352 | 30,136 | true |
| Europe retail | 351 | 29,908 | true |

Starting point for this tranche was 137 functions / 4,484 bytes on USA and LRG
and 79 / 3,256 on Japan and Europe.

### Toolchain corrections established this tranche

- The accepted profile now passes `-Wab,-r4300_mul`. The original build inserts
  one `nop` between consecutive floating-point multiplies; the USA image
  contains no adjacent floating-point multiply pair and 218 nop-separated
  pairs. Adding the flag produced no regressions and immediately resolved the
  whole "compiler omits one scheduled nop" class.
- Matching units may now carry a `flags` key that replaces the profile flags
  for one translation unit. Several regions are demonstrably not `-O2`:
  `-O1` around `0x8008ADB0`-`0x80097950`, `-O3` at `0x80089610`,
  `-Wo,-loopunroll,0` at `0x8008C2F0`/`0x80092850`, and `-mips3 -o32` for the
  64-bit integer support routines at `0x8008AB0C`-`0x8008AC48`.
- Three USA units had ROM offsets that did not equal `vram - 0x7FFFF400`, so
  they were being compared against the wrong bytes. `func_80017FD0`,
  `func_8002E770` and `func_8002E82C` are all exact now. Every config is
  checked against that invariant.
- Regional units must export the regional symbol name; four units linked at a
  Japan/Europe address while exporting the USA name, which verified but broke
  the regional link. The merge step now normalises this.

### Host test

`tests/test_global_state.c` links every recovered source, so each function this
tranche recovered retired the hand-written double that used to stand in for it.
Where a double only counted calls, the assertion now observes the real
function's own state; where the real function writes a memory-mapped hardware
register, the call was removed, because that address is unmapped in a host
process and the byte-match verifier is the right check for it. Expect to repeat
this each time a tranche lands: a double and a recovered implementation cannot
both define the symbol.

`tests/host_link_stubs.c` is generated rather than hand-edited now; the weak
stand-ins are sized and aligned as arrays because recovered sources index these
objects as tables.

### Remaining USA mismatches

See the mismatch table above; it is now the complete set, because every
recovered source has a matching unit and is measured on every run.

## Audit of the "hand-written assembly" verdicts

The previous tranche retired around 25 bodies as hand-written. That count was
roughly right and its membership and reasoning were not. Every claim was
re-tested against the compiler itself rather than against impressions.

### Reasons that were wrong

- **Unaligned word access.** Retired `func_80096AD0` and `func_80092850` on the
  grounds that "IDO 5.3 cannot emit `lwl`/`lwr` from portable C". It can: a
  byte-aligned struct assignment emits `lwl`/`lwr`/`swl`/`swr`.
- **Floating-point control transfers.** A plain `(unsigned)float` cast emits
  `cfc1`/`ctc1` to save the rounding mode around the conversion.
- **A non-standard calling convention.** Retired `func_8008E420` for reading
  `$s0`-`$s6`. At `-O3` IDO allocates registers across a translation unit, so a
  file-local function takes arguments in whatever registers suit and is emitted
  with no ELF symbol at all. Written `static` beside a caller and compiled at
  `-O3`, it reproduces the register assignment, frame and length first try.
- **The disassembler's "Handwritten function" marker.** A heuristic, wrong in
  both directions: it flagged ordinary compiler output and missed genuine
  assembly.

### Reasons that hold, and how they were established

`make classify` writes `analysis/non_c_functions.json`: 27
bodies, 4,608 bytes, each with a decisive reason. The compiler
has **no inline assembly** — it parses `asm("mtc0 ...")` as a call to an
undeclared function named `asm` — so for these there is no C input at all.

Decisive classes: coprocessor-0 transfers; cache maintenance; the
kernel-reserved registers `$k0`/`$k1`; trapping arithmetic (`add`, `addi`,
`sub`), because C addition may not trap; and an unmatched *left* half of a
partial word access, which writes a run-time number of bytes. An unmatched
*right* half is ordinary — the compiler emits it for a trailing piece whose
start is word-aligned — and treating it as decisive produced a false positive
that the check below caught.

The rule is validated against the strongest available control: none of the
functions the verifier reproduces byte-for-byte is flagged. That is a test, not
a claim.

### What the re-examination actually recovered

Two of the three "wrongly retired" functions turned out to be genuinely
hand-written after all, but only after the false reasons were removed and real
ones found: `func_80096AD0` reads a register nothing defined, as a seed so that
a full-width comparison sees only a fresh fragment; `func_80092850` clears a
run-time one to three bytes with an unpartnered left-half store. `func_80092250`
proved hand-written on the sharpest evidence of all — it forms one address with
a trapping `add` and the same address elsewhere with `addu`, which no single C
source produces. `func_8008E420` was the one genuine recovery: ordinary `-O3`
compiler output.

Boundaries moved a long way in the process. `func_80092250` is 772 bytes, not
the 116 the label scan claimed, absorbing two fragments that branch into each
other. `func_8008CB00` is a four-instruction trampoline copied into the
exception vectors plus a handler that reclaims 52 bytes the scan had given to
its neighbour. `func_8008D044` is 180 bytes, not 232, and contains no
privileged instruction at all once correctly bounded.

### Tooling changes this forced

- A unit may carry `text_offset`, so a file-local function with no ELF symbol
  can still be located and compared. Each result records whether its size was
  confirmed by a symbol or taken from configuration.
- A unit may carry `rodata_vram`, for an object with its own constant pool.
- `make classify` separates three different kinds of remaining assembly:
  bodies no C can produce, interior fragments the label scan promoted by
  mistake, and bodies nothing references at all. Only the third is
  segmentation work, and it is a third of the remaining bytes.
