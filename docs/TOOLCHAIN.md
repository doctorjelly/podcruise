# Toolchain provenance

Audit date: 2026-08-18.

This document separates tools used on the maintainer's machine from material
distributed by this repository. A tool's presence in the local environment
does not put its executable or source into Git.

## Installed bootstrap tools

| Component | Validated version | License/provenance | Repository treatment |
|---|---:|---|---|
| `splat64` | 0.50.0 | MIT; upstream `ethteck/splat` | Version requirement only; package not vendored |
| `spimdisasm` | 1.42.4 | MIT; upstream `Decompollaborate/spimdisasm` | Transitive executable-analysis dependency; not vendored |
| `rabbitizer` | 1.16.2 | MIT; upstream `Decompollaborate/rabbitizer` | Transitive instruction decoder; not vendored |
| GNU MIPS binutils | 2.47 | GNU licenses; official Homebrew cross-binutils formula | Locally installed assembler/linker/objcopy; not vendored |
| host C compiler | Apple Clang 17 family | Apple toolchain installation | Syntax and warnings only; not a matching compiler |

`requirements-lock.txt` records every Python distribution and exact version in
the validated environment. They are installed from the Python package index,
not copied into this repository. Local package metadata and upstream license
files identify the remaining transitive packages as permissively licensed
(MIT/BSD/Apache-2.0) or, for `tqdm`, dual MPL-2.0/MIT.

The current Homebrew binutils installation is suitable for proving that an
untouched split can be reassembled and linked exactly. The formula is not yet a
fully reproducible toolchain pin: Homebrew may advance the packaged version.
Future CI or release work should obtain a fixed source revision, retain its
license notices, and record the build recipe.

## Deliberately excluded

- No SGI/IDO executable, proprietary Nintendo SDK component, leaked header,
  library, or documentation is committed or downloaded by project scripts.
- No code or authored symbol names are imported from `sp00nznet/racer`, because
  that repository had no explicit license at the audit date.
- `asm-differ`, `m2c`, and `decomp-permuter` are roadmap candidates, not current
  dependencies. Each must receive its own version and license review before it
  becomes required tooling.

## Compiler gap

Instruction patterns strongly suggest an IDO-family compiler, but neither the
exact release nor flags are established. A provenance-cleared matching compiler
is therefore a hard gate: current C files may describe recovered behavior, but
the project reports zero matching C bytes.

Acceptable future routes include a demonstrably lawful user-supplied compiler
installation or a suitably licensed clean-room implementation. Convenience is
not sufficient provenance.
