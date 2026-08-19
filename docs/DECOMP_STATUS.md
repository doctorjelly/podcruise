# Decompilation status semantics

This project reports different kinds of progress separately so that tooling
milestones cannot be mistaken for recovered source.

| Metric | Current meaning |
|---|---|
| ROM coverage | All bytes are represented by local generated assembly or opaque local blobs. |
| Round-trip coverage | USA, Japan, and Europe rebuild byte-identically from untouched local splits. |
| Function candidates | Heuristic boundaries awaiting different levels of validation. |
| Behavior recovered | A compact human-reviewed specification and independently written source candidate exist. |
| Matching C | Source has been compiled with the identified toolchain and matches original bytes exactly. |

Current source state:

- 3 behavior-recovered source candidates;
- 36 original instruction bytes represented by those behavioral candidates;
- 0 bytes claimed as matching C;
- exact IDO release and flags still unresolved;
- large-scale segment classification still unresolved.

The denominator for a future code percentage will not be chosen until CPU code,
RSP microcode, embedded data, and overlays are separated. Using the current
coarse 622 KiB interval as “all C code” would produce a misleading percentage.
