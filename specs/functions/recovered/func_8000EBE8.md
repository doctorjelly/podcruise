# `func_8000EBE8` USA source-order audit

The current C is 760/760 bytes at the canonical address, but differs in 78
words, first at byte `0xA6`; the parent reran the isolated linked-object
verifier after restoring the source. The ROM computes the x result from
`res[0] / res[3]` before computing y from `res[1] / res[3]`, while the C
states the independent y assignment first. Stack offsets already agree.

A Luna Low audit tried x-first statements, x-first statements on one source
line, and x-first with the `f32 x`/`f32 y` declaration order swapped. Every
form remained 760/760 bytes with 80 differing words and the same first
byte. No source edit was retained. Further work needs evidence beyond this
local x/y statement order.
