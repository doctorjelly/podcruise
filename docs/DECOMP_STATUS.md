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

| Build | Exact functions | Exact bytes | Share of CPU text | Configured units |
|---|---:|---:|---:|---:|
| USA retail | 913 | 189,860 | 30.55% | 1,072 |
| Japan retail | 832 | 166,080 | 26.72% | 838 |
| Europe retail | 832 | 173,400 | 27.90% | 837 |
| USA LRG revision | 912 | 188,992 | 30.41% | 1,072 |

"Configured" counts functions with a reviewed C source under test. The gap
between configured and exact is behaviour-recovered work: the source compiles,
and in many cases to the original's exact length, but the bytes do not yet
match. Behaviour recovery is not counted as decompilation progress.

Each figure is produced by `make match-c`, which compiles every unit with the
identified toolchain and compares it against that version's own ROM. A USA
match is never assumed to carry to Japan or Europe.

All four unique images rebuild byte-identically with these substitutions in
place; `make roundtrip-all` is the check.
