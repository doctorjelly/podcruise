# func_8008CAC0

## Boundary

- USA VRAM range: 0x8008CAC0 .. 0x8008CAFC inclusive (0x40 = 64 bytes, 16
  instructions).
- USA ROM offset: 0x8D6C0.
- Terminates with a return whose delay slot restores the stack pointer, so the
  frame teardown is the last instruction of the body.
- Assigned size 64 was correct; no boundary correction. The word before the
  entry is padding belonging to the previous function.
- Both internal labels are targets of this function's own branches, and the two
  direct call sites target the entry address.

## Callers and callees

- Two direct call sites in the USA build.
- Leaf: no callees.
- Two arguments, both pointers; nothing is returned.

## Globals and access widths

- None. Only caller-supplied memory is touched, always as 32-bit words, and
  only the link word at offset 0 of a record is read or written.

## Regional addresses

| version  | VRAM       | ROM     |
|----------|------------|---------|
| us       | 0x8008CAC0 | 0x8D6C0 |
| jp       | 0x8008D7B0 | 0x8E3B0 |
| eu       | 0x80092010 | 0x92C10 |
| lrg_rev1 | 0x8008CAC0 | 0x8D6C0 |

Each regional body was read independently; all three are instruction-for-
instruction identical to the USA body, and no symbol is referenced, so nothing
had to be relocated.

## Recovered behavior

Unlinks one record from a singly linked list. The first argument is the address
of the head cell, the second is the record to remove. The routine walks the
chain keeping a trailing cursor, which starts out aimed at the head cell itself
so that removing the first record needs no special case: at each step it
compares the record the cursor points at with the requested record, and on a
hit copies that record's successor into the cursor's link word and returns.
If the walk reaches the end of the chain without finding the record, the list
is left unchanged.

Two source-shape facts were needed for the byte-exact result. First, the
trailing cursor is a declared register-class local, which is what produces the
small unused stack frame the original reserves and gives the two working
pointers the argument registers rather than the return registers. Second, the
list pointer is always read back through the cursor (never from the head cell
argument directly), which is why the initial copy of the head address happens
before the first load and why the loop reloads through the freshly advanced
cursor rather than reusing the value it already held.

## Compiler profile

This body only reproduces at optimization level 1, not at the project's
accepted level 2. At level 2 the compiler converts both loop branches to the
branch-likely form and duplicates the target instructions into the delay slots,
which the original does not do; it also moves the two working pointers into the
return-value registers and drops the stack frame. Level 1 reproduces all 64
bytes exactly. The surrounding addresses look like a separately built support
library, so a dedicated level-1 profile for this translation unit is warranted.

## Status

Exact at optimization level 1, in USA, Japan, Europe and the large-cartridge
revision.
