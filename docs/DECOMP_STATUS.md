# Decompilation status semantics

This project reports different kinds of progress separately so that tooling
milestones cannot be mistaken for recovered source.

| Metric | Current meaning |
|---|---|
| ROM coverage | All bytes are represented by local generated assembly or opaque local blobs. |
| Round-trip coverage | All four unique supplied images rebuild byte-identically with verified C substitutions. |
| Function candidates | Heuristic boundaries awaiting different levels of validation. |
| Behavior recovered | A compact human-reviewed specification and independently written source candidate exist. |
| Matching C | Source has been compiled with the identified toolchain and matches original bytes exactly. |

## Current coverage

Matching-C coverage is measured against main-processor text, ROM `0x1000` to
`0x98BE4` — **621,540 bytes**. `docs/SEGMENTATION.md` sets out why that is the
denominator, which bytes are excluded as signal-processor microcode or padding,
and why the earlier `0x99000` interval was wrong.

| Build | Exact functions | Exact bytes | Share of CPU text | Configured functions | Hybrid substitutions |
|---|---:|---:|---:|---:|---:|
| USA retail | 1,067 | 252,736 | 40.66% | 1,348 | 1,067 |
| Japan retail | 912 | 204,044 | 32.83% | 990 | 911 |
| Europe retail | 914 | 212,316 | 34.16% | 990 | 913 |
| USA LRG revision | 1,067 | 252,736 | 40.66% | 1,348 | 1,064 |

The apparent decline from 40.55% is an accounting correction: four functions
totalling 300 bytes were counted twice, once in a combined translation unit
and again as standalone units. No matching source or USA substitution was lost.

"Configured" counts function entries with reviewed C under compiler test, not
translation units. The gap between configured and exact is nonmatching C,
including candidates with current compile/link failures. The USA manifest
covers 1,348 functions and 616,960 original bytes in reviewed C, or 99.26% of
CPU text; only the exact 40.66% is eligible for substitution in the canonical
rebuild.

The strict manifest audit finds four explained, unconfigured source files: two
regional-only stubs and two retained alternate candidates for corrected USA
function boundaries. It finds no unexplained source file. Those four are not
included in the reviewed-C figure above.

Exact counts come from per-version linked-byte comparison reports, rerun on
the current worktree and deduplicated by function address. A USA match is
never assumed to carry to Japan or Europe.

The current USA worktree passed `make roundtrip-us` byte-identically with 1,067
C substitutions. The other three builds passed prior `make roundtrip-all`
checks, but were not rerun after this source change.
