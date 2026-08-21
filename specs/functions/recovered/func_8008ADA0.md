# func_8008ADA0 — read one audio-interface hardware register

## Boundary
- USA VRAM `0x8008ADA0`..`0x8008ADAB` (12 bytes), ROM `0x8B9A0`.
- Three words: the upper half of the register address is formed, the return
  branch follows, and its delay slot performs the load into the return
  register. The `jr $ra` plus a real (non-nop) delay slot confirm the end.
- The address `0x8008ADA0` is the direct `jal` target of the only caller, and
  the preceding function ends before it. Assigned boundary correct.

## Callers / callees
- Three call sites, all inside `func_8002E134` (the first is at `0x8002E278`).
- No callees; leaf function, no stack frame at all.

## Globals / hardware
- One 32-bit read from the memory-mapped word at physical-uncached address
  `0xA450000C`. This is the audio-interface length/status word, i.e. an I/O
  register, not RAM. Access width: 32 bits, one read.

## Regional addresses
- Japan `0x8008BA90` / ROM `0x08C690`.
- Europe `0x800902F0` / ROM `0x090EF0`.
- lrg_rev1 shares the USA address `0x8008ADA0` / ROM `0x8B9A0`.
- All three regional bodies were read independently and are identical, as
  expected: a hardware address does not move between builds.

## Recovered behavior
Returns the current 32-bit contents of the audio-interface register at
`0xA450000C`. Nothing else happens: no state is kept, nothing is written, and
the value is handed straight back to the caller.

## Recovery note
The address is a literal in the source, not a named external object. That is
observable: taking the address of a named `extern` object costs an extra
instruction to add the low half of the relocated address, and the original body
has no such instruction — it folds the low half into the load's displacement,
which only happens for an address the compiler knows numerically. The access is
marked volatile because the location is a hardware register whose value changes
outside the program; the byte output is the same either way, so the qualifier
is not doing any matching work.

## Status
Exact in USA, Japan, Europe and lrg_rev1. Compiles under the project's standard
`-mips2` profile.
