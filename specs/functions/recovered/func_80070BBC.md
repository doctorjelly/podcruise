# func_80070BBC

## Boundary

The USA function occupies ROM `[0x717BC, 0x71A98)` and VRAM
`[0x80070BBC, 0x80070E98)`, for 732 bytes. The next function,
`func_80070E98`, begins at the exclusive end address `0x80070E98`; there is
no intervening assembly range to resume.

## Source-line grouping

The unchanged source token sequence compiles to the canonical 732-byte body
when the statements around the rewind correction are grouped as follows:

```c
                rewinding = 0;
                active = 0; scaled = object->track.unk08 * -10.0f; if (scaled < 0) { whole = (s32)(scaled - D_800AD840);
                } else {
                    whole = (s32)scaled;
                }
```

The required line joins are after `active = 0;`, after the `scaled`
assignment, and after the opening brace of the negative-correction branch.
Joining the later `object->track.unk08` assignment with the following
`}`/`else if` line is optional. This changes only whitespace and source-line
grouping; the candidate's non-whitespace token sequence equals the existing
source. The exact private candidate is `/tmp/70bbc-grouping/focus/f123.c`.

The baseline differs from the ROM in two adjacent words at VRAM
`0x80070D9C` and `0x80070DA0`: it emits the zero register clear before the
`lui` for `D_800AD840`, while the ROM emits the `lui` first. The grouping above
matches the ROM schedule.

A bounded enumeration tested 101 unique layouts. The initial generator omitted
a final newline and therefore implicitly joined the following `} else if`;
a corrected 16-combination pass explicitly checked that boundary and confirmed
that it is optional. The joins listed above are the minimal exact grouping
within the enumerated block.

## Verification status

The independent parent audit in `/tmp/us24-70bbc-parent` confirms the symbol at
`0x80070BBC` has size 732. Its linked text's first 732 bytes match the USA
ROM exactly; the extra four bytes in the isolated text artifact are alignment
padding outside the symbol. The build artifacts are under
`/tmp/us24-70bbc-parent/ido53_o2/func_80070BBC/`. The full USA ledger confirms
the match. The 32-job USA round trip substitutes this C object at its canonical
address, as verified by the linker map, and remains byte-identical with
1183 C substitutions.
