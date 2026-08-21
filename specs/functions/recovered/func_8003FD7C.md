# func_8003FD7C — release notification for one object

## Boundary

* USA VRAM `0x8003FD7C`–`0x8003FDCB`, ROM `0x4097C`, 80 bytes.
* Closes with the standard return sequence and an empty delay slot; the frame
  is 0x38 bytes (0x20 of which is one local notification record).
* The preceding function ends its own return before this entry, the label is
  reached only by direct calls, and both internal branches land on this
  function's own epilogue. Boundary as assigned is correct.

## Callers

20 direct call sites in USA (the assignment counted 18). Every site passes a
single object pointer and ignores the result; several sites clear an adjacent
object field immediately before or after the call.

## Callees

* `func_8003F99C` — generic "deliver a notification record to an object's
  handler table" helper. It takes the object pointer and a pointer to a
  notification record whose first word is a four-character tag, walks a global
  registry, and invokes the matching handler with the same two pointers.

## Globals

None referenced directly.

## Access widths

* Object field at byte offset 6: read and written as a signed 16-bit value; it
  carries bit `0x100` as an "already released" marker.
* Notification record field at byte offset 0: written as a 32-bit value.
* The notification record occupies 32 bytes of stack; only its first word is
  initialised, the rest is left untouched for the handler to ignore.

## Regional addresses

| version | vram | rom | notification helper |
| --- | --- | --- | --- |
| us | 0x8003FD7C | 0x4097C | func_8003F99C |
| jp | 0x8004070C | 0x4130C | func_8004032C |
| eu | 0x8004471C | 0x4531C | func_8004433C |
| lrg_rev1 | 0x8003FD7C | 0x4097C | func_8003F99C |

All three regional bodies were read independently and are instruction-for-
instruction the same shape as USA, differing only in the call target.

## Recovered behavior

Given one object pointer the routine does nothing at all when the pointer is
null, and nothing when the object's status halfword already has the
"already released" bit set. Otherwise it builds a one-word notification record
on the stack whose tag is the four characters `Free`, hands the object and that
record to the notification helper, and then sets the "already released" bit in
the object's status halfword so that a second call is a no-op. The object
pointer is reloaded after the helper returns, so the helper is free to clobber
the caller-saved registers but must not move the object.

## Status

Exact in USA, Japan, Europe and lrg_rev1 under the accepted IDO 5.3 -O2
profile.
