# func_8007BA9C

## Boundary correction

The assignment listed 132 bytes ending at 0x8007BB1B. That is wrong. The
function contains an early exit that branches *past* its own return into the
heuristic label `func_8007BB20`, which is a bare return with an empty delay
slot and has no direct callers anywhere in the ROM. It is this function's
second return point, not a function of its own.

- Corrected USA VRAM range: 0x8007BA9C .. 0x8007BB27 inclusive
  (0x8C = 140 bytes, 35 instructions).
- USA ROM offset: 0x7C69C.
- The next real function starts at 0x8007BB28: it is reached by a genuine call
  from 0x8007D31C, so the corrected body stops just before it.
- The same correction applies in Japan and Europe: their equivalent tail labels
  (0x8007C7C0 and 0x80081000) also have no callers, and their next real
  functions start eight bytes later.

## Callers and callees

- One direct call site in the USA build. It passes a pointer read out of a
  live object, stores the result both to a stack slot and into the object, and
  branches away when the result is null.
- No callees (leaf function).

## Arguments and return

One pointer argument; returns a pointer, or null when the lookup fails.

## Globals and access widths

- `D_8011CA58` — an array of at least fifty 32-bit pointer-sized slots, read
  only. A zero slot terminates the occupied prefix.
- `D_8011CB20` — a parallel array of fixed-size records, 88 bytes each. Only
  its address is taken; nothing is read or written through it here.

## Regional addresses

The body is instruction-for-instruction identical in every version; only the
two global addresses move.

| version  | VRAM       | ROM     | key array    | record array |
|----------|------------|---------|--------------|--------------|
| us       | 0x8007BA9C | 0x7C69C | D_8011CA58   | D_8011CB20   |
| jp       | 0x8007C73C | 0x7D33C | D_8011FCC8   | D_8011FD90   |
| eu       | 0x80080F7C | 0x81B7C | D_801256F8   | D_801257C0   |
| lrg_rev1 | 0x8007BA9C | 0x7C69C | D_8011CA58   | D_8011CB20   |

## Recovered behavior

Looks up the record that belongs to a given key object. It scans the key array
from the start, stopping as soon as it reaches the fifty-slot limit, an empty
slot, or a slot holding the requested key. It then re-reads the slot it stopped
on: if that slot is empty — because the key was absent, or because the table is
full and the key is not in it — the lookup fails and null is returned.
Otherwise the index it stopped on selects the matching record in the parallel
record array, and the address of that record is returned.

Note that the search stops at the first empty slot rather than continuing, so
the array is treated as a densely packed prefix; and that the failing case is
detected by re-reading the key slot rather than by remembering the value the
loop last looked at, which is forced by the limit-reached exit path where no
slot was read at all.

Two source-shape facts were needed to reproduce the original bytes:

- The scan is written as a single top-tested loop whose continuation condition
  short-circuits over all three tests (limit, empty, match). Writing it as a
  counted loop with two `break` statements in the body lets the compiler rotate
  the test to the bottom and strength-reduce the subscript into a walking
  pointer, which is thirty-two bytes shorter and does not match.
- The final test is written so that the success path returns first and the null
  return is the fall-through at the end of the function. Written the other way
  round the compiler places the null return inline in the middle and the tail
  return disappears.

## Status

Exact, with the boundary corrected to 140 bytes. Byte-identical in USA, Japan,
Europe and the large-cartridge revision.
