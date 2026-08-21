# func_8006FED0

## Boundary

USA VRAM 0x8006FED0 - 0x8006FEE7 inclusive (24 bytes, 6 instructions), ROM
0x70AD0. The body ends with a return whose delay slot is empty. The single
direct call site targets 0x8006FED0, which is the first instruction of the
range, and the preceding function ends with its own return before it. Boundary
as assigned is correct.

## Callers

One direct call site, at 0x80070360, which passes the object it is currently
processing as the only argument and ignores any result.

## Callees

None. This is a leaf.

## Globals and access widths

None.

## Parameters and return

One argument: a pointer to an object. No value is returned and nothing is
written.

## Regional addresses

| version | entry | rom |
| --- | --- | --- |
| us | 0x8006FED0 | 0x70AD0 |
| jp | 0x80070A40 | 0x71640 |
| eu | 0x800753B0 | 0x75FB0 |
| lrg_rev1 | 0x8006FED0 | 0x70AD0 |

All three regional bodies were read independently. They are byte-for-byte the
same as USA - this routine has no relocations at all, so every retail build
carries the identical 24 bytes.

## Recovered behavior

The routine reads the object's 32-bit status word at byte offset 0x60, tests
bit 0x80, and does nothing on either outcome. There is no store, no call, and
no return value; the branch for the set case lands on the very next instruction
after its own delay slot, so both outcomes reach the return immediately.

Behaviourally this is a no-op with a single read of offset 0x60. In the
shipping builds it is the residue of a guarded body whose contents were removed
before release: the guard survived, the guarded work did not.

## Status

Behavior recovered; not byte-matching.

The accepted profile (IDO 5.3, -O2) deletes an `if` statement whose body
becomes empty, and it deletes the guard's load and branch along with it, so no
source form of "test a bit and do nothing" reproduces these 24 bytes at -O2.
Twenty-odd source shapes were tried, including an empty body, an early return,
a `goto` to a trailing label, a `break` out of a `do/while(0)`, a dead local or
parameter assignment inside the body, a discarded expression statement, a
`volatile`-qualified object pointer, zero-trip loops, and a nested empty `if`.
Every one compiles to a bare return (8 bytes).

Two findings that narrow it down, both worth recording for the project:

- A body that survives optimisation as a single register move does keep the
  guard: a value-returning form (`return a->unk60;` inside the guard, no
  trailing return) yields the right load, mask and branch-to-fallthrough, but
  with the loaded value in the second scratch register plus a move into the
  return register - 28 bytes, four more than the target.
- Compiling the empty-guard form with the optimiser disabled (`-g`, or -O0 or
  -O1) does produce the load, mask and branch-to-fallthrough, but allocates the
  loaded value to a different scratch register and emits an extra return pair -
  32 bytes.

So the shape is reachable only if the guard's body leaves exactly zero
instructions after register allocation while still existing at the point where
empty blocks are pruned. Recommendation for the orchestrator: leave this one
non-matching for now rather than distorting the source, and revisit it if the
project ever adds a second compiler profile.

The committed C expresses the recovered behavior (read offset 0x60, test bit
0x80, do nothing) and compiles cleanly, but compiles to 8 bytes, not 24.
