# func_80033EEC — push a twelve-float record onto a bounded capture buffer

## Boundary

- USA VRAM range 0x80033EEC .. 0x80033F93 inclusive, 168 bytes (0xA8).
- The body has one forward branch that skips the copy and lands on the return
  jump; the return jump plus its no-op delay slot close the range. The next
  label, func_80033F94, is a separate 680-byte function that begins by
  re-materialising the same counter address, and it is reached by its own direct
  calls, so it is not a continuation of this one.
- Boundary as assigned is correct; no correction needed.

## Callers

One call site (VRAM 0x800381C0 in the USA build), reached from a branch arm that
clears a stack flag in the delay slot. The single argument is a pointer.

## Callees

None. The function is a leaf.

## Globals and access widths

- `D_800A3FF0` — one signed 32-bit counter, read once and written once.
- `D_800A3FF4` — one 32-bit word, unconditionally set to 1.
- `D_80112EA0` — an array of 48-byte records, each holding twelve consecutive
  32-bit floats. Only one record is written per call.

## Signature

`void func_80033EEC(f32 *record)`

## Regional addresses

| version | entry VRAM | ROM | size |
| --- | --- | --- | --- |
| us | 0x80033EEC | 0x34AEC | 168 |
| jp | 0x8003494C | 0x3554C | 168 |
| eu | 0x8003885C | 0x3945C | 168 |
| lrg_rev1 | 0x80033EEC | 0x34AEC | 168 |

Symbol correspondence: D_800A3FF0 -> D_800A6D60 (jp) / D_800A95F0 (eu);
D_800A3FF4 -> D_800A6D64 (jp) / D_800A95F4 (eu);
D_80112EA0 -> D_80116110 (jp) / D_8011BB40 (eu). All four bodies are
structurally identical.

## Recovered behaviour

The function appends one twelve-float record to a shared capture buffer and
raises a "buffer is dirty" marker.

The marker is set to one first and unconditionally, before the capacity test, so
it records that an append was attempted rather than that one succeeded.

The counter is then compared against 32 as a signed value. When it is already 32
or more the function does nothing further and returns; the buffer is full and
the record is dropped silently. Otherwise the counter is incremented and the new
value is used as the index of the record to fill. Because the increment happens
before the index is taken, index zero is never written by this function and the
counter names the last slot used rather than the next free one; the highest slot
this path can reach is 32.

The address of the target record is formed by scaling the index by the 48-byte
record stride and adding the buffer base, which the compiler builds once outside
the conditional. The twelve floats the argument points at are then copied into
the record in ascending order, unrolled, with no arithmetic applied.

Nothing is returned.

## Status

Exact. Byte-identical in usa, japan, europe and lrg_rev1.
