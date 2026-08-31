# Toolchain provenance

Audit date: 2026-08-30.

This document separates tools used on the maintainer's machine from material
distributed by this repository. A tool's presence in the local environment
does not put its executable or source into Git.

## Installed bootstrap tools

| Component | Validated version | License/provenance | Repository treatment |
|---|---:|---|---|
| `splat64` | 0.50.0 | MIT; upstream `ethteck/splat` | Version requirement only; package not vendored |
| `spimdisasm` | 1.42.4 | MIT; upstream `Decompollaborate/spimdisasm` | Transitive executable-analysis dependency; not vendored |
| `rabbitizer` | 1.16.2 | MIT; upstream `Decompollaborate/rabbitizer` | Transitive instruction decoder; not vendored |
| GNU MIPS binutils | 2.34 | GNU licenses; Ubuntu cross-binutils package, SHA-256 `db48a1c39796ad63e20e915f08cfc0a6f0c78eda5b1ca82f5f0c87bc4c184b02` | Extracted under ignored `build/toolchain`; not vendored |
| IDO static recompilation | Decompals v1.2, IDO 5.3/7.1 | Maintainer-approved local-only release tools | Archives and executables remain ignored; project scripts never download them |
| `decomp-permuter` | commit `fb516c435c6f362fbced66e171545324306b607b` | MIT; upstream `simonlindholm/decomp-permuter` | Optional local matching aid; source, target objects, and outputs are not vendored |
| host C compiler | Apple Clang 17 family | Apple toolchain installation | Syntax and warnings only; not a matching compiler |

`requirements-lock.txt` records every Python distribution and exact version in
the validated environment. They are installed from the Python package index,
not copied into this repository. Local package metadata and upstream license
files identify the remaining transitive packages as permissively licensed
(MIT/BSD/Apache-2.0) or, for `tqdm`, dual MPL-2.0/MIT.

The local IDO 5.3 and 7.1 release archives have SHA-256 values
`ab5c741561f80913d58c8b074771f23941a3edd312505a8ebed6d1dfeb65e506`
and `0d411696e178fcca34c31c3bf02011b928d7fd9c1fa7f8bf45070e0781b58e15`.
They are local development tools, not repository dependencies or distributable
project artifacts.

## Deliberately excluded

- No SGI/IDO executable, proprietary Nintendo SDK component, leaked header,
  library, or documentation is committed or downloaded by project scripts.
- No code or authored symbol names are imported from `sp00nznet/racer`, because
  that repository had no explicit license at the audit date.
- `asm-differ` and `m2c` are roadmap candidates, not current dependencies.
  Each must receive its own version and license review before it becomes
  required tooling. `decomp-permuter` has been reviewed and used locally, but
  remains optional and is not distributed by this repository.

## Matching compiler status

IDO 5.3 with the `ido53_o2` profile exactly reproduces 1,011 reviewed functions
totaling 230,456 bytes in the canonical USA image. Current regional reports
contain 888 exact functions (194,404 bytes) for Japan, 889 (202,528 bytes) for
Europe, and 993 (226,680 bytes) for the later USA revision. The configured
verifier also measures behavior-only candidates, which are excluded from those
match counts and reported in `docs/DECOMP_STATUS.md`.

The profile flags are `-G 0 -O2 -mips2 -non_shared -Xcpluscomm -signed
-Wab,-r4300_mul`. The last of those is the VR4300 multiply workaround: the
original build separates two consecutive floating-point multiplies with a
`nop`, and the USA image contains no adjacent floating-point multiply pair
against 218 nop-separated pairs. Adding it produced no regressions and resolved
every function that had previously been short by exactly one scheduled `nop`.

Compiler selection remains a per-object question, and it is now answered
per object rather than assumed. A unit in `config/c_matching*.json` may carry
its own `flags` list, which replaces the profile flags for that translation
unit alone. The recovered set already contains objects built at `-O1`, at
`-O3`, with `-Wo,-loopunroll,0`, and with `-mips3` for the 64-bit integer
support routines. A unit may also carry `rodata_vram` when the original object
had its own floating-point constant pool, so the load displacements resolve
against the address the original build used.
