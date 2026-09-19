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
| USA retail | 1,069 | 254,816 | 41.00% | 1,348 | 1,069 |
| Japan retail | 913 | 204,688 | 32.93% | 990 | 911 |
| Europe retail | 915 | 212,960 | 34.26% | 990 | 913 |
| USA LRG revision | 1,069 | 254,816 | 41.00% | 1,348 | 1,064 |

The earlier decline from 40.55% to 40.50% was an accounting correction: four functions
totalling 300 bytes were counted twice, once in a combined translation unit
and again as standalone units. No matching source or USA substitution was lost.

"Configured" counts function entries with reviewed C under compiler test, not
translation units. The gap between configured and exact is nonmatching C,
including candidates with current compile/link failures. The USA manifest
covers 1,348 functions and 616,960 original bytes in reviewed C, or 99.26% of
CPU text; only the exact 41.00% is eligible for substitution in the canonical
rebuild.

The strict manifest audit finds four explained, unconfigured source files: two
regional-only stubs and two retained alternate candidates for corrected USA
function boundaries. It finds no unexplained source file. Those four are not
included in the reviewed-C figure above.

Exact counts come from per-version linked-byte comparison reports, rerun on
the current worktree and deduplicated by function address. A USA match is
never assumed to carry to Japan or Europe.

The current USA worktree passed `make roundtrip-us` byte-identically with 1,069
C substitutions. The other three builds passed prior `make roundtrip-all`
checks, but were not rerun after this source change.

Two current USA candidates remain assembly-backed despite ROM-supported
corrections. `func_80076180` now preserves four previously omitted RNG advances:
its C and ROM have 46 direct calls each, but the compiled body is 2,320 versus
2,484 bytes. `func_8004BE90` now links its jump table at the ROM's
`0x800AB13C` address (4-byte alignment); its compiled body remains 3,000 versus
3,008 bytes. Neither correction increases matching-C coverage.

Two further USA source candidates now follow the ROM's behavior but still do
not match its bytes. `func_80077054` clamps a turn against `+50.0` and `-50.0`
in double precision, not `+3.140625` and `-3.140625`; its compiled body is
3,112 versus 3,136 bytes. `func_800718DC` uses `D_800AD900` as the threshold
for the `KPow` path and `D_800AD8F0` for the other relevant hit paths; its
compiled body is 4,484 versus 4,596 bytes, with seven direct calls still
merged away by its shared C case blocks. Both remain assembly-backed.

Further ROM-backed corrections remain nonmatching: `func_8004EA08` now makes
the sixth independent sign draw for its generated item (`2,128/2,124` compiled/
ROM bytes); `func_8001D05C` now copies an 18-byte zero initializer from the
canonical `0x800A8BF4` data address (`3,304/3,308` bytes); and
`func_80021294` links its switch table at `0x800A9C7C` (`3,184/3,312`
bytes). Their USA split entries still name assembly, not matching C.
