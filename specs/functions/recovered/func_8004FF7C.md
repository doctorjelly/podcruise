# func_8004FF7C — clear the four selection slots

## Boundary

* USA VRAM `0x8004FF7C` .. `0x8004FFA7` (44 bytes, 11 instructions), ROM `0x50B7C`.
* Ends with the return instruction at `0x8004FFA0` whose delay slot holds the
  last of the four stores, so the delay slot is part of the body.
* One direct caller targets the entry; the preceding function ends with its own
  return at `0x8004FF74`. The assigned boundary is correct.

## Callers and callees

* Callers: 1.
* Callees: none — leaf.

## Globals and access widths

| symbol | width | use |
| --- | --- | --- |
| `D_800A4B6C` | 32-bit | selection slot 0 |
| `D_800A4B70` | 32-bit | selection slot 1 |
| `D_800A4B74` | 32-bit | selection slot 2 |
| `D_800A4B78` | 32-bit | selection slot 3 |

The four words are contiguous and are immediately followed by the four-word
table used by `func_8004F6E8` (`D_800A4B7C`), so this region is one block of
module-private state.

## Regional addresses

| version | entry | ROM | first slot |
| --- | --- | --- | --- |
| usa | `0x8004FF7C` | `0x50B7C` | `D_800A4B6C` |
| japan | `0x80050BE8` | `0x517E8` | `D_800A78DC` |
| europe | `0x80054C24` | `0x55824` | `D_800A9E6C` |
| lrg_rev1 | `0x8004FF7C` | `0x50B7C` | same as usa |

All three regional bodies were read independently and have exactly the same
eleven-instruction shape, including the same grouping of the stores.

## Recovered behaviour

Mark all four selection slots as empty by writing all-ones into each of the four
consecutive words. Nothing is read and nothing is returned.

## Status

Behaviour recovered; not byte-identical.

The recovered C produces the same four stores with the same four distinct
constant registers as the original, and the first five instructions are
identical, but the original packs the last three stores under a single address
register while the isolated build emits one address setup per store (52 bytes
against the original 44).

Cause, established by experiment rather than guessed: the IDO assembler only
folds several `%hi` address setups into one when the symbols being stored to are
**section-local to the translation unit being assembled** (a `static`
file-scope object, assembled as `.lcomm`). With `.comm` symbols, with `.extern`
symbols, and with globals that carry an initialiser, the assembler emits a fresh
address setup for every store, whatever the compiler's instruction order is —
this was checked directly by assembling hand-written input in each of those
forms. The original module therefore declared this block of state `static`.

The matching harness supplies every referenced symbol as an absolute address at
link time, which forces the C to declare them `extern`, which in turn forbids
the fold. Reproducing this function byte-for-byte needs a unit that *defines*
the block as file-static and a link that places the unit's `.bss` at
`0x800A4B6C`; that is a change to the shared verification tooling, so it is
recorded here instead of made. Note that the same fold does not affect the other
four functions in this group: they address the same block through ordinary
address registers, which the assembler treats identically for local and external
symbols, and all four are exact.

Also checked: the mismatch is not compiler-version related — the IDO 7.1 profile
produces the same output as 5.3 for both candidate source shapes.
