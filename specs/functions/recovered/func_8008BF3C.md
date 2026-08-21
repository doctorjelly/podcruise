# func_8008BF3C — capture bus timing into the two device descriptors

## Boundary
- USA VRAM `0x8008BF3C`..`0x8008BFAF` (116 bytes), ROM `0x8CB3C`.
- Straight-line body, no branches at all; it ends with `jr $ra` whose delay
  slot holds the last of the ten stores. Assigned boundary correct.
- The single direct `jal` targets `0x8008BF3C`, and the preceding function ends
  before it.

## Callers / callees
- One direct call site, inside `func_8008BDC0` (at `0x8008BDEC`).
- No callees; leaf function, no stack frame.

## Globals
- `D_8014B0F0` — device descriptor for bus domain 0. Five single-byte fields
  are written, at byte offsets 5, 6, 7, 8 and 9 from the start of the object.
- `D_8014B168` — the matching descriptor for bus domain 1, same five offsets.
  It sits 0x78 bytes after the first, consistent with two entries of one
  descriptor type rather than two unrelated objects.
- Eight 32-bit reads from memory-mapped peripheral-interface registers, the
  four domain-0 bus timing words at `0xA4600014`, `0xA4600018`, `0xA460001C`,
  `0xA4600020`, and the four domain-1 words at `0xA4600024`, `0xA4600028`,
  `0xA460002C`, `0xA4600030`. Each is read as 32 bits and stored as 8 bits, so
  only the low byte of each register survives.

## Regional addresses
- Japan `0x8008CC2C` / ROM `0x08D82C`; its descriptors are `D_8014E360` and
  `D_8014E3D8` (same 0x78 spacing).
- Europe `0x8009148C` / ROM `0x09208C`; descriptors `D_80153D90` and
  `D_80153E08`.
- lrg_rev1 shares the USA addresses and the USA descriptor addresses.
- All three regional bodies were read independently; they are instruction-for-
  instruction the same shape, differing only in the two relocated descriptor
  addresses. The hardware register addresses are of course unchanged.

## Recovered behavior
Snapshots the bus timing configuration that the boot process left in the
peripheral interface, into the two software descriptors the rest of the code
uses to describe the two cartridge bus domains.

For the first descriptor it copies the four domain-0 timing parameters —
latency, pulse width, page size and release duration — out of their hardware
registers, narrowing each to a byte, and then tags the descriptor with domain
number 0. For the second descriptor it does the same with the four domain-1
registers and tags it with domain number 1.

Field placement within a descriptor: latency at offset 5, page size at 6,
release duration at 7, pulse width at 8, domain number at 9.

## Recovery note
The hardware registers are literal addresses in the source (same reasoning as
`func_8008ADA0`: the low halves are folded into the load displacements). The two
descriptors, by contrast, are named objects whose addresses are relocated and
therefore move between regions. Assignment order in the source is
latency, pulse width, page size, release duration, domain number; the original
scheduler hoisted each constant domain-number store into the gap after the
preceding load, which is why that store appears one slot early in both halves.

## Status
Exact in USA, Japan, Europe and lrg_rev1. Compiles under the project's standard
`-mips2` profile.
