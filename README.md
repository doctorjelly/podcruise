# podcruise

`podcruise` is a clean-room, multi-version decompilation project for the
Nintendo 64 release of *Star Wars Episode I: Racer*.

The immediate objective is a byte-matching rebuild of the original USA retail
ROM. The Japan and Europe retail ROMs are treated as independent observations
of the same source tree: shifted functions, changed constants, and localized
data help distinguish code boundaries from data and relocation artifacts. The
2022 Limited Run Games image is retained only as post-link patch evidence.

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
- Initial `splat` configurations for extracting the three original retail
  builds without committing extracted code or assets.
- Byte-identical untouched split/rebuild round trips for USA, Japan, and Europe.
- Three independently specified source candidates, explicitly not yet claimed
  as byte-matching C.

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
make split-us
make roundtrip-us
```

`roundtrip-us` does not decompile any C. It reassembles the untouched local
split, links it, flattens it back to a ROM, and requires byte identity with the
validated input. This isolates the build system from later source-recovery
errors. `make roundtrip-all` performs the same proof for USA, Japan, and Europe.

Generated assembly, extracted assets, build output, caches, and ROMs stay
untracked. The committed `analysis/` reports contain only hashes, addresses,
counts, and other metadata.

## ROM placement

The local working copy expects the exact paths listed in
[`config/versions.json`](config/versions.json). Run `make inventory` to verify
them. See [`roms/README.md`](roms/README.md) for the expected files and hashes.

## Strategy

USA retail is the canonical matching target because it is the earliest of the
three supplied original retail builds. Japan and Europe are comparison targets,
not patches to be blindly merged. Work proceeds in this order:

1. establish exact ROM identity and segment boundaries;
2. derive and verify function boundaries across versions;
3. identify compiler, SDK, library, and overlay behavior;
4. split code/data with `splat` and preserve a matching-ROM build loop;
5. replace assembly one function at a time with matching C;
6. add Japan and Europe as build targets once common source boundaries settle.

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
