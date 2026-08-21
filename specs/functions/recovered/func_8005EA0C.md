# func_8005EA0C

## Boundary
USA VRAM 0x8005EA0C-0x8005EA70, 100 bytes, ROM 0x5F60C. Ends with the return
jump whose delay slot performs the final global store. One direct caller,
which passes no arguments.

## Callers
One call site in the USA build.

## Callees
- func_800305E8 (one integer selector, returns a pointer to a handle record)
- func_80030964 (one pointer argument, prepares the record in place)

## Globals
- D_8011B1B0 — one 32-bit word, written.
- D_8011B1B4 — one 32-bit word, written.

## Regional addresses
- jp 0x8005F574 (ROM 0x60174)
- eu 0x80063EF0 (ROM 0x64AF0)

## Behavior
The routine caches two values that are needed elsewhere. It first looks up the
record for selector 0x92, has that record prepared, and stores the first word
the record points at into the first cache slot. It then looks up the record for
selector 0x31, has it prepared as well, follows the pointer that record holds,
reads the pointer stored 0x18 bytes into the referenced object, and stores the
word that pointer addresses into the second cache slot.

## Status
Behavior-recovered. The compiled body is the correct 100 bytes and differs from
the original only in one register choice: the original places the intermediate
pointer of the second lookup in the second result register while the rebuilt
code uses the first. Eight source-shape experiments (single vs. two locals,
declaration order, void-pointer local, register storage class, extra
intermediate locals, non-void return type, mirroring the local into the first
block) moved the stack-slot assignment onto the original but never freed the
first result register, which implies a further declared object in the original
translation unit that this isolated unit cannot express.
