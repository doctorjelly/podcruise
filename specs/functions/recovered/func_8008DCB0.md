# func_8008DCB0

## Boundary

USA VRAM `0x8008DCB0` through `0x8008DD47`, ROM `0x8E8B0`, is a
152-byte function. The return is at `0x8008DD40`; its delay slot at
`0x8008DD44` adds `0x20` to the result and therefore belongs to the function.
The two zero words before the next function at `0x8008DD50` are alignment
padding, not part of this body. The preceding label at `0x8008DCAC` is a
separate single no-op.

## Callers, callees, and data

The only direct USA caller is at `0x8008891C` in `func_800887D0`. It passes an
owner pointer, index zero, a configuration pointer, and an allocation-region
pointer; it ignores the returned pointer.

The function calls `func_8008D870`, `func_800963B4`, and `func_8008DD50`. It
does not address any global directly. From its owner argument it reads pointers
at offsets `0x30` and `0x34`. The latter points to `0x4C`-byte elements, whose
subobject at offset `0x20` is supplied to all three callees and returned.

## Regional equivalents

| Build | VRAM | ROM | Size |
|---|---:|---:|---:|
| USA / LRG | `0x8008DCB0` | `0x8E8B0` | 152 |
| Japan | `0x8008E9A0` | `0x8F5A0` | 152 |
| Europe | `0x80093200` | `0x93E00` | 152 |

The regional units use the same source and compiler mode with relocated callee
symbols. Japan and Europe were already exact under those mappings; LRG shares
the USA body.

## Behavior

The signed 16-bit index selects one element from the owner's array. The
function passes the element's subobject at `0x20` and the final two arguments
to `func_8008D870`. It then calls `func_800963B4` with that subobject, mode one,
and the containing element. Finally it calls `func_8008DD50` with the owner's
pointer at `0x30`, mode two, and the subobject, then returns the subobject.

## Inference

The call pattern suggests that the first call prepares the subobject and the
next two calls register or attach it to its containers. The surrounding
semantics are not yet strong enough to rename this function or its callees.

## Status

Byte-matching C. IDO 5.3 with this unit compiled at `-O3` reproduces all 152
USA bytes exactly, including the result-producing return delay slot. The
project-wide `-O2` default does not match this function; it reloads the narrow
index from its argument home instead of emitting the original shift pair.
