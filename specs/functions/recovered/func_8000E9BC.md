# func_8000E9BC

## Boundary

- USA VRAM range `0x8000E9BC`-`0x8000EA4B` inclusive, ROM `0xF5BC`, size 144
  bytes (36 instructions).
- Terminates with a return followed by an empty delay slot; every early exit
  branches to that return. The preceding function `func_8000E8C4` restores
  saved registers and returns at `0x8000E9B4`, so the assigned entry point is a
  true boundary.
- Leaf function: no frame is allocated, but the incoming argument home slots are
  used, both for the compiler's own spills of the narrow register arguments and
  to read the three stack arguments.

## Callers

Seven direct call sites. Observed sites obtain the first argument from an
allocation/lookup helper, guard against a null result, and pass six small
integers - commonly all `0` and `255`, or a mixture of zero and a sign-extended
16-bit variable.

## Callees and globals

None.

## Parameters

1. pointer to a record whose word at offset `0x0C` is itself a pointer
2. through 7. six signed 16-bit integers; arguments 5, 6 and 7 arrive on the
   stack

Returns nothing.

## Recovered behavior

The function pushes up to six small values into a block of six consecutive
single-byte fields hanging off a sub-object, skipping any value the caller
marked as "leave alone".

1. If the first argument is null, nothing happens.
2. The pointer stored at offset `0x0C` of that record is fetched; if it is
   null, nothing happens.
3. For each of the six 16-bit arguments in order, a negative value means "do
   not change this field" and is skipped; a value of zero or greater is
   narrowed to a single byte and stored into the sub-object at offsets `0x20`
   through `0x25` respectively.

The six fields are written independently, so any subset can be updated in one
call. Given the caller pattern of passing `255` and `0`, the block reads as a
six-component colour/intensity or channel-level record with a sentinel of `-1`
for "unchanged".

## Regional addresses

| Version | VRAM | ROM | Size |
| --- | --- | --- | --- |
| USA | 0x8000E9BC | 0xF5BC | 144 |
| Japan | 0x8000E9BC | 0x00F5BC | 144 |
| Europe | 0x8000EE1C | 0x00FA1C | 144 |

Both regional bodies were read independently and are structurally identical to
the USA body. The European copy sits 1120 bytes later; nothing inside the
function references a relocated symbol, so only the entry address differs.

## Status

Exact. USA, Japan, and Europe all verify byte-identical.
