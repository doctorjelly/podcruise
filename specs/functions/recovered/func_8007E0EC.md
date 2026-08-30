# func_8007E0EC

## Verified facts

- The USA body spans VRAM `0x8007E0EC` through `0x8007E987`, ROM `0x7ECEC`,
  2204 bytes. `jr ra` is at `0x8007E980`; its delay slot restores the
  120-byte stack frame. `func_8007E988` begins next.
- Its only direct caller is `func_8005EA70`. Its resource loading, node
  extraction, visibility, transform, queue-registration, cleanup, and optional
  setup helpers and globals are recorded in the matching unit.
- Japan and Europe equivalents begin at `0x8007ED8C` and `0x800835CC`.

## Behavior

The routine resets shared scene bookkeeping and selects one of eight resource
layouts. It loads each layout's model resources, publishes their nodes, enables
the required objects, registers them in the appropriate queue, applies one
layout-specific scale, and optionally runs the supplied follow-up setup. It
returns the common scene-initialization result.

## Status

Behavior recovered from the USA binary and independently expressed in C; not
byte-matching. IDO 5.3 `-O2` emits 2308 bytes for the 2204-byte target and first
differs at byte `0x3`; 527 instruction words differ across 18 blocks. Regional
binaries were used only for structural and relocation confirmation.
