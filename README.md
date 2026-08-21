# podcruise

`podcruise` is a clean-room, multi-version decompilation project for the
Nintendo 64 release of *Star Wars Episode I: Racer*.

USA retail is the canonical matching target. Japan, Europe, and the later USA
revision are independent build targets and structural evidence for the shared
source tree. Shifted functions, changed constants, and localized data help
distinguish code boundaries from data and relocation artifacts.

This repository contains no ROM data. You must supply legally obtained ROMs;
all recognized ROM filename extensions are ignored by Git.

## Current state

- Six local ROM files inventoried: USA, Japan, Europe, and three identical
  filenames for the Limited Run Games revision.
- Reproducible N64 header and cryptographic-hash inventory.
- Independent MIPS function-candidate discovery from entry points, `jal`
  targets, and stack-frame prologues.
- Relocation-tolerant normalized-window mapping from USA functions into the
  Japan and Europe executables.
- `splat` configurations for all four unique supplied images, without
  committing extracted code or assets.
- Byte-identical hybrid rebuilds for all four unique images.
- 562 functions represented by independently written C, covering 61,476
  original instruction bytes. `make manifest` generates that ledger into
  `analysis/source_manifest.json` from the matching configuration and the
  per-version comparison reports, and fails if any recovered source is left
  unmeasured.
- Exact IDO 5.3 matches for 506 of them (49,308 bytes) in USA and LRG, 462
  (45,392 bytes) in Japan and 458 (44,764 bytes) in Europe, each verified
  against its own image. Those C functions are substituted in each exact hybrid
  build. The remaining reviewed candidates are behavior-recovered but not yet
  byte-matching; see [`docs/CLAUDE_HANDOVER.md`](docs/CLAUDE_HANDOVER.md) for
  the current backlog.

This is the beginning of a source-matching decompilation, not a claim that the
game is already decompiled or playable.

## Quick start

```sh
make inventory
make analyze
make map
make test
```

To install and run `splat` in the project-local environment:

```sh
make setup
make match-c
make roundtrip-all
```

`roundtrip-all` compiles and substitutes each build's verified C tranche, links
the remaining local assembly and opaque data, and requires byte identity with
all four unique validated inputs. The three third-party filenames are identical
aliases, so one LRG revision build covers the same bytes in all three files.

Generated assembly, extracted assets, build output, caches, and ROMs stay
untracked. The committed `analysis/` reports contain only hashes, addresses,
counts, and other metadata.

## ROM placement

The local working copy expects the exact paths listed in
[`config/versions.json`](config/versions.json). Run `make inventory` to verify
them. See [`roms/README.md`](roms/README.md) for the expected files and hashes.

## Strategy

USA retail is the canonical matching target because it is the earliest supplied
retail build. Other versions are separate targets, not patches to be blindly
merged. Work proceeds in this order:

1. establish exact ROM identity and segment boundaries;
2. derive and verify function boundaries across versions;
3. identify compiler, SDK, library, and overlay behavior;
4. split code/data with `splat` and preserve a matching-ROM build loop;
5. replace assembly one function at a time with matching C;
6. expand shared and version-specific source across every supplied build.

The detailed plan and evidence policy are in
[`docs/ROADMAP.md`](docs/ROADMAP.md).
Progress terminology is defined in
[`docs/DECOMP_STATUS.md`](docs/DECOMP_STATUS.md).
The installed-versus-distributed tool boundary and current license audit are in
[`docs/TOOLCHAIN.md`](docs/TOOLCHAIN.md).

## IP-safety boundary

The repository follows the conservative clean-room policy in
[`docs/IP_POLICY.md`](docs/IP_POLICY.md). In short: Git may contain original
project tooling and compact factual observations, but not ROM bytes, extracted
assets, generated disassembly, proprietary SDK/compiler files, or source copied
from prior projects. Run `make safety` before every commit.

## Prior art

The separate [`sp00nznet/racer`](https://github.com/sp00nznet/racer) project
demonstrated that the USA binary can be statically recompiled far enough to
boot and submit display lists. It provides useful public observations, but it
is not a source decompilation and currently has no explicit license. No source
from that repository is copied here. See [`docs/PRIOR_ART.md`](docs/PRIOR_ART.md).

## Legal

No copyrighted ROM, extracted asset, or generated disassembly is intended for
Git history. The project is for interoperability, research, and preservation.
No affiliation with Lucasfilm, LucasArts, Nintendo, or Disney is implied.

This operational policy reduces avoidable IP exposure; it is not a legal
opinion or a guarantee about every jurisdiction or use.
