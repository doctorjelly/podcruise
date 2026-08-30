# func_8000ABD4

## Verified facts

- The canonical USA entry is VRAM `0x8000ABD4`, ROM `0xB7D4`.
- The null path returns at `0x8000ABF8`; its delay slot sets the result to
  zero at `0x8000ABFC`.
- The non-null branch executes the load at `0x8000ABF4`, then returns through
  `jr $ra` at `0x8000AC04` and its `nop` delay slot at `0x8000AC08`.
- The load at `0x8000AC00` is unreachable from both paths. IDO emits it as
  part of this source, so the matching translation-unit span is 56 bytes even
  though the last reachable instruction of the function is at `0x8000AC08`.
- The only direct USA caller is `func_80055AEC`. There are no callees. The only
  global referenced is the 32-byte-stride table `D_800D21AC`.
- Japan and Europe have the same instruction/control-flow structure at the
  same address; only the relocated table address differs.

## Behavior

The signed 16-bit argument selects a slot from `D_800D21AC`. If the resource
pointer in that slot is null, the function returns null. Otherwise it returns
the 16-bit data pointer stored eight bytes into the resource.

## Status

Byte-matching C for canonical USA. The independently written source compiled
with IDO 5.3 `-O2` reproduces all 56 bytes of the original split, including
the compiler-generated unreachable load. The isolated exact comparison passed,
and the canonical round trip reproduced SHA-1
`3542d5597c8a56ea8f5c63bceae97a24c4c08d58`.
