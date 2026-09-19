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
| USA retail | 1,066 | 251,720 | 40.50% | 1,348 | 1,066 |
| Japan retail | 911 | 203,028 | 32.67% | 990 | 911 |
| Europe retail | 913 | 211,300 | 34.00% | 990 | 913 |
| USA LRG revision | 1,066 | 251,720 | 40.50% | 1,348 | 1,064 |

The apparent decline from 40.55% is an accounting correction: four functions
totalling 300 bytes were counted twice, once in a combined translation unit
and again as standalone units. No matching source or USA substitution was lost.

"Configured" counts function entries with reviewed C under compiler test, not
translation units. The gap between configured and exact is nonmatching C,
including candidates with current compile/link failures. The USA manifest
covers 1,348 functions and 616,960 original bytes in reviewed C, or 99.26% of
CPU text; only the exact 40.50% is eligible for substitution in the canonical
rebuild.

The strict manifest audit finds four explained, unconfigured source files: two
regional-only stubs and two retained alternate candidates for corrected USA
function boundaries. It finds no unexplained source file. Those four are not
included in the reviewed-C figure above.

Exact counts come from per-version linked-byte comparison reports. The USA
report was rerun on the current worktree; the regional figures use their
existing reports, deduplicated by function address. A USA match is never
assumed to carry to Japan or Europe.

The current USA worktree passed `make roundtrip-us` byte-identically with 1,066
C substitutions. The other three builds passed prior `make roundtrip-all`
checks, but were not rerun after this USA ledger correction.
