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
table used by `func_8004F6E8` (`D_800A4B7C`). This establishes a contiguous
selection-state region adjacent to that table; contiguity alone does not prove
the original C linkage or ownership of either object.

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

The current shared matching ledger reports a 44-byte symbol at the canonical
address, with first difference at `+0x0C` and seven differing words. Its
compiled symbol hash is
`49250b848941297f071583d62d8539f437a81ddb8fa5ac1249ba32eb235ec5dc`. The
ledger's source hash matches the current `src/functions/func_8004FF7C.c`
(`0837802dfc1dbc35ee92216f6b15899761081095c311475523f9057fa8223420`).

A private initialized-static probe tested whether defining the four words
locally and placing their data section could recover the body. It used a custom
linker script to put `.data` at `0x800A4B6C`, with the function at its canonical
address and no absolute symbol aliases for the slots.

The mixed-type initialized candidate emitted 44 text bytes, with seven
differing instruction words at offsets `0x0C`, `0x10`, `0x14`, `0x18`, `0x1C`,
`0x20`, and `0x28`. Its 16-byte `.data` block was all `0xFF` and matched the
ROM range `[0xA576C, 0xA577C)`. A second candidate using signed declarations
for all four words emitted 40 text bytes with eight differing words; its
16-byte data block matched the same ROM range. Both probes are under
`/tmp/us25-4ff7c-data/` and remain private.

These probes show that a local initialized block can reproduce the required
data at a chosen address, but neither source shape reproduces the instruction
schedule. The earlier BSS-only placement explanation was too narrow; exact C
recovery remains unresolved. The mismatch is not compiler-version related:
the IDO 7.1 profile produced the same output as 5.3 for the earlier candidate
shapes. The other four functions that address this block remain exact.
