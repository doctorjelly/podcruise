# func_8008ADB0

## Boundary

- USA VRAM `0x8008ADB0`..`0x8008AE30`, ROM `0x8B9B0`, size 128 bytes (32 instructions).
- Ends with a return whose delay slot is empty. The three labels inside the
  range are internal branch targets of this body only. The single direct call
  site targets `0x8008ADB0`. Boundary confirmed, not changed.
- Frame is 32 bytes: saved return address plus two four-byte scratch slots and
  the incoming argument's home slot.

## Callers

One direct call site, near `0x8002E3D0`. The caller passes a pointer read out
of the global `D_801488C0` and immediately compares the returned word against
a held value, so this function genuinely returns a value rather than being
`void`.

## Callees

`func_800938F0` — an argument-less accessor that reads a hardware status word
(the signal-processor status register at physical `0x04040010`). Its result is
therefore a bit mask, not a pointer or count.

## Globals and access widths

None referenced directly. The one pointer argument is dereferenced at offset
`0x04` only, as a full 32-bit word, read-modify-written twice.

## Regional addresses

| version | entry | ROM | callee |
| --- | --- | --- | --- |
| USA | `0x8008ADB0` | `0x8B9B0` | `func_800938F0` |
| Japan | `0x8008BAA0` | `0x8C6A0` | `func_800945E0` |
| Europe | `0x80090300` | `0x90F00` | `func_80098E40` |
| lrg_rev1 | same as USA | same as USA | same as USA |

Both regional bodies were read directly; they are the same 32 instructions with
only the entry point and the callee address moved.

## Recovered behavior

Reads the signal-processor status word once. Derives a one-or-zero result from
status bit 8 (mask `0x100`): one when the bit is set, zero when it is clear.
Then, only if status bit 7 (mask `0x80`) is also set, it updates the flag word
at offset `0x04` of the object it was handed: it first sets the low bit of that
word when the derived result was one (an OR of the zero-or-one value, so a
result of zero leaves the word untouched), and then, as a separate
read-modify-write of the same word, clears bit 1. Finally it returns the
derived zero-or-one value regardless of whether the object was updated.

In plain terms: sample a co-processor's status, report one status bit back to
the caller as a boolean, and when a second status bit says the object is in a
state that may be edited, fold that boolean into the object's low flag bit
while clearing a second, now-stale flag bit.

The two updates of the same word are deliberately separate read-modify-write
sequences in the original, not one fused expression; the word is written and
then read back before the second update.

## Compiler profile

This body carries the project's `-O1` fingerprint: every local occupies a stack
slot and is reloaded at the start of each basic block, no callee-saved
registers are used, the status word is stored and re-read one instruction
later, and the zero-or-one value is materialised through memory rather than a
compare instruction. Compiled with the accepted `-O2` flags the same source
produces a correct but 96-byte body that keeps everything in registers.
Swapping `-O2` for `-O1` and changing nothing else reproduces all 128 bytes.

Flag list proven by scratch config:
`-G 0 -O1 -mips2 -non_shared -Xcpluscomm -signed -Wab,-r4300_mul`.

This extends the known `-O1` cluster (previously `0x8008C900`, `0x8008D420`,
`0x80093990`, `0x80097950`) downward to `0x8008ADB0`.

## Status

Exact. Byte-identical in USA, Japan, Europe and lrg_rev1 under the `-O1`
profile above.
