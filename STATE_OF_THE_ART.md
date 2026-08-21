# podcruise: state of the art and the remote host handoff

Status date: 2026-08-19

Working copy: the repository root.


Baseline commit: `41e476f054b77add7d3f643cbe38193efd28fe09`

## Mission

`podcruise` is an IP-conscious, multi-version source-decompilation project for
the Nintendo 64 release of *Star Wars Episode I: Racer*.

The target is not merely a native static recompilation and not merely assembly
that round-trips. The intended definition of 100% is:

1. a legally obtained, user-supplied USA retail ROM is validated;
2. game logic is represented by reviewed C, with assembly retained only where
   it is demonstrably handwritten or otherwise intentionally non-C;
3. data and assets are represented by declarations or extraction recipes;
4. a reproducible, provenance-cleared toolchain rebuilds the canonical USA ROM
   byte-for-byte;
5. Japan, Europe, and the later USA revision are reconstructed from shared and
   version-specific source.

## Honest progress snapshot

| Metric | Current state |
|---|---:|
| Supplied ROM filenames | 6 |
| Unique ROM images | 4 |
| Unique images with exact hybrid rebuild | 4 |
| USA function-boundary candidates | 1,692 |
| Functions represented by reviewed C | 562 / 61,476 original bytes |
| USA/LRG C substitutions | 506 functions / 49,308 bytes each |
| Japan C substitutions | 462 functions / 45,392 bytes |
| Europe C substitutions | 458 functions / 44,764 bytes |

Those counts come from `analysis/source_manifest.json`, which
`tools/make_source_manifest.py` derives from the matching configuration and the
per-version comparison reports. They are not maintained by hand, and `make
manifest` fails if a recovered source is not measured by any unit.

An untouched round trip proves that splitting, assembling, linking, placement,
padding, and binary export are coherent. It is a prerequisite for matching C,
not source-decompilation progress by itself.

## ROM corpus

The ROMs live under the Git-ignored `roms/originals/` directory. They are
private build inputs and must never be added to Git, uploaded to GitHub, placed
in CI artifacts, or attached to issues.

| Build | Game/revision | SHA-1 | Role |
|---|---|---|---|
| USA retail | `NEPE` rev 0 | `3542d5597c8a56ea8f5c63bceae97a24c4c08d58` | canonical matching target |
| Japan retail | `NEPJ` rev 0 | `9577ccd2d069d0e7e306cf21ddb0e4765a308072` | comparison build |
| Europe retail | `NEPP` rev 0 | `899a8245da017289c88e97327fdcd6694b770a25` | comparison build |
| USA LRG revision | `NEPE` rev 1 | `f71908f15a14ee124f9b471467432ade87e0951c` | comparison/build target |

The three revision 1 filenames are byte-identical aliases of
the last image. Preserve their filenames locally for provenance, but treat them
as one independent binary observation.

Run this after any copy to validate filenames, sizes, headers, and hashes:

```sh
python3 tools/rom_inventory.py \
  --config config/versions.json \
  --output analysis/roms.json \
  --check
```

## What has been learned from the binaries

The conservative USA scan currently treats ROM `0x1000` through `0x99000` as a
coarse executable interval. It found 624 high-, 773 medium-, and 295
low-confidence function candidates. Those are hypotheses, not 1,692 proven
functions; CPU code, embedded data, RSP microcode, and possible tables still
need more precise segmentation.

A relocation-tolerant 32-instruction window matcher found unique structural
correspondences for:

- 1,592 of 1,692 USA candidates in Japan (94.09%);
- 1,562 of 1,692 USA candidates in Europe (92.32%).

These results strongly support shared source lineage and help identify moved
code/data. They are not a decompilation percentage.

The examined USA interval contains 3,125 unconditional branches lowered as
`beq zero, zero` and only four absolute `j` instructions. This strongly suggests
an IDO-family compiler. Exact comparison of the recovered tranche identifies
IDO 5.3; IDO 7.1 reproduces fewer functions on the same sources.

The tranche also identified around 25 bodies that no C input can produce:
privileged coprocessor transfers, cache maintenance, and unaligned-word string
primitives. The generated disassembly independently marks them handwritten.
These are the assembly that the definition of done deliberately allows to
remain.

## Recovered source tranches

`src/bootstrap_state.c` contains three independently written C candidates based
on the compact behavioral specification in
`specs/functions/bootstrap_state.md`:

- `func_80000520`: stores its argument to a 32-bit global;
- `func_8000052C`: clears a neighboring 32-bit global;
- `func_80000538`: returns that second global.

Those three functions and 559 further functions have independently written
specifications and independently written C, held in `src/functions/`. The
identified compiler reproduces 506 of them exactly, totalling 49,308 canonical
bytes, and the USA and LRG hybrid builds substitute all 506. Japan substitutes
462 (45,392 bytes) and Europe 458 (44,764 bytes), each independently verified
against its own image rather than inferred from the USA result. All four unique
rebuilt ROMs retain their expected SHA-1. The remaining reviewed sources are
behavior-recovered only: their current C does not match and is not substituted.
The exact mismatch inventory is in `docs/CLAUDE_HANDOVER.md`.

## Working build and analysis commands

From the repository root:

```sh
make setup
make inventory
make all
make test
make safety
make match-c
make roundtrip-all
```

`make setup` creates an ignored Python environment and installs the exact
versions in `requirements-lock.txt`. `make roundtrip-all` additionally requires
GNU MIPS binutils commands installed with the `mips-linux-gnu-` prefix.

The four verified hybrid-rebuild SHA-1 values are:

```text
USA     3542d5597c8a56ea8f5c63bceae97a24c4c08d58
Japan   9577ccd2d069d0e7e306cf21ddb0e4765a308072
Europe  899a8245da017289c88e97327fdcd6694b770a25
LRG     f71908f15a14ee124f9b471467432ade87e0951c
```

## Toolchain and provenance boundary

Validated components are Splat 0.50.0, spimdisasm 1.42.4, Rabbitizer 1.16.2,
GNU MIPS binutils 2.34, and the local-only Decompals v1.2 IDO 5.3/7.1 release
tools. These tools remain untracked.

No SGI/IDO executable, proprietary Nintendo SDK component, leaked header,
library, or documentation is committed or downloaded by project scripts. No
source or authored symbol names were copied from the unlicensed
`sp00nznet/racer` prior-art repository.

IDO 5.3 is established, with `-G 0 -O2 -mips2 -non_shared -Xcpluscomm -signed
-Wab,-r4300_mul` as the accepted profile. The `-Wab,-r4300_mul` flag is the
VR4300 multiply workaround: the original build separates consecutive
floating-point multiplies with a `nop`, and the USA image contains no adjacent
floating-point multiply pair against 218 nop-separated pairs.

Per-object flag changes are now proven rather than hypothetical. A matching
unit may carry its own `flags`, and the recovered set already contains
translation units built at `-O1` and `-O3`, one built with loop unrolling
disabled, and the 64-bit integer support routines built for MIPS III. The open
task is to map those object boundaries rather than to establish that they
exist.

## Highest-value next work

The next commits should be dominated by source recovery rather than additional
scaffolding:

1. refine the coarse executable range into verified CPU text, data, RSP
   microcode, and asset segments while preserving exact round trips;
2. use the per-function compile/diff harness on each recovered tranche;
3. classify likely libultra and compiler-runtime routines independently;
4. select 25–50 small high-confidence leaf functions;
5. inspect their callers, callees, global accesses, and regional equivalents;
6. write compact behavioral specifications and independently written C;
7. substitute only verified source into the build and report behavior-recovered
   and byte-matching progress separately;
8. extend compiler/version/flag fingerprints across probable original objects.

## IP-safety rules

- `roms/originals/`, `analysis/generated/` and `build/` may exist in a working
  directory but must remain Git-ignored.
- Never use `git add -f` on an ignored game-derived path.
- Never place ROMs or extracted assets in Git LFS; LFS is still publication.
- Run `make safety`, `git diff --check`, and review `git status --ignored`
  before every commit or push.
- Restrict ROM permissions on a shared machine to the owning account.
- Do not expose a working directory through an HTTP server, shared filesystem
  export, CI artifact, or public backup.
- Absolute paths from an operator's machine, and the names of private hosts,
  do not belong in committed files. `make safety` enforces this.

This workflow reduces avoidable IP exposure; it is an engineering policy, not
legal advice.
