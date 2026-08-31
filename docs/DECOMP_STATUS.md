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

| Build | Exact functions | Exact bytes | Share of CPU text | Configured units | Hybrid substitutions |
|---|---:|---:|---:|---:|---:|
| USA retail | 1,022 | 235,360 | 37.87% | 1,311 | 1,022 |
| Japan retail | 889 | 194,692 | 31.32% | 956 | 887 |
| Europe retail | 890 | 202,816 | 32.63% | 955 | 888 |
| USA LRG revision | 1,022 | 235,360 | 37.87% | 1,304 | 1,002 |

"Configured" counts translation units with reviewed C under compiler test. The
gap between configured and exact is behavior-recovered work: the source
compiles, and in many cases to the original's exact length, but the bytes do
not yet match. The USA manifest currently covers 1,348 functions and 616,984
original bytes in reviewed C, or 99.27% of CPU text; only the exact 37.87% is
eligible for substitution in the canonical rebuild.

The strict manifest audit currently finds only the two recorded regional-only
source exceptions and no unexplained source file. Those exceptions are not
included in the reviewed-C figure above.

Each figure is produced by `make match-c`, which compiles every unit with the
identified toolchain and compares it against that version's own ROM. A USA
match is never assumed to carry to Japan or Europe.

All four unique images rebuild byte-identically with these substitutions in
place; `make roundtrip-all` is the check.
