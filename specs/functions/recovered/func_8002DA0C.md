# `func_8002DA0C` USA compiler audit

The current K&R-parameter source compiles to the canonical 196-byte size and
address, but two words differ: the spill/reload of `a2` use `sp+0x18` instead
of the ROM's `sp+0x1C` (instruction offsets `+0x58` and `+0x70`). An exhaustive
swap of its only two local declarations, `phase` and `state`, worsened the
comparison to four differing words (first byte `0x57`). Adding an unused
four-byte local before or after them worsened it to eight words (first byte
`0x1F`). The source was restored. Prior audits tried local narrowing, an
extra index, and branch-form changes; an older ANSI-parameter seed also had a
local permuter run in `/tmp`. Do not repeat those forms without new
stack-allocation evidence.

A separate one-minute stack-aware permuter pilot used an ANSI-parameter seed
that was independently shown to compile to the exact current K&R-source bytes.
Its target object matched all 196 ROM bytes and its baseline score was 8; the
pilot produced no lower-score candidate. The initial K&R seed could not be
randomized by this permuter parser, so it was not counted as a search.
