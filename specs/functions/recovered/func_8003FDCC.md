# `func_8003FDCC` USA compiler audit

Before the exact edit, the behavior-recovered C compiled to 620/644 bytes, with 106
different comparable words and six missing words; the first difference is
byte `0x03`. The canonical body is `8003FDCC..8004004F`, including the return
delay slot.

The six-word deficit is in the insertion-search loop. Replacing its
`for`/inner-`break` with `slot = 0; while (slot < found &&
distances[slot] < distance) { slot++; }` yields 644/644 bytes and 19
different words. Moving the `delta[3]` declaration immediately after
`distance` then reduces the difference to four words, with the frame, stack
slots, calls, and all other instructions exact. The four remaining words are
at `+0x1DC`, `+0x1E4`, `+0x1E8`, and `+0x1F4`: the ROM loads/stores shifted
vector components in z/y/x order, while IDO emitted x/y/z from that variant.

Reversing the three assignment statements, including a same-line grouping,
kept four differences. A whole-`Vec3f` assignment expanded to 664 bytes;
explicit block-local z/y/x snapshots changed register allocation to 31
different words. Other placements of `delta` left 10–19 differences.

A bounded `decomp-permuter` pilot found that keeping the original x/y/z
assignment order but grouping those three copies on one source line changes
IDO's schedule to the ROM's z/y/x load/store order. The parent independently
verified the smallest readable form with `python3 tools/audit_c_unit.py --unit
func_8003FDCC`: 644/644 bytes, canonical address, zero different words.
The USA split starts C at ROM `0x409CC` and resumes assembly at the exact
function end `0x40C50`. The integrated USA round trip remained byte-identical
at SHA-1 `3542d5597c8a56ea8f5c63bceae97a24c4c08d58`, with the C
substitution count increasing from 1067 to 1068; the linker map names this
function's C object at `0x8003FDCC`.
