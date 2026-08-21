# func_8002DBD8

## Boundary
USA VRAM 0x8002DBD8-0x8002DC7B (0xA4 = 164 bytes), ROM 0x2E7D8.
0x18-byte frame; the body ends with a return whose delay slot is empty, and the
frame teardown plus the result move sit just before it. The four direct call
sites all target 0x8002DBD8, and the single internal branch target is the shared
epilogue inside the body, so the label is a real entry.

## Callers / callees
Four direct callers; each tests the returned word against zero immediately after
the call, so the function really does return a value.

Calls `func_800152CC` up to three times. That helper is already recovered: it
compares two three-component float vectors and returns one when all three
components are equal.

## Object layout touched
The single argument is a record whose field at 0x34 is a signed index. The index
selects a 32-byte entry in the global table; two three-component float vectors
live in that entry, one at offset 0x00 and one at offset 0x0C.

## Globals
| symbol | use |
| ------ | --- |
| `D_800A4C00` | base of the 32-byte-per-entry table indexed by the record's field |
| `D_80118E50` | reference vector compared against the entry's second vector |
| `D_80118ED0` | second reference vector, also compared against the entry's second vector |
| `D_80118E10` | reference vector compared against the entry's first vector |

The indexed address is recomputed from scratch before each comparison, because
the record's index field is reloaded from the argument's home slot after every
call.

## Regional addresses
- JP 0x8002E63C, ROM 0x2F23C; helper 0x800153FC, table 0x800A7970, references
  0x8011C0C0, 0x8011C140 and 0x8011C080.
- EU 0x8003117C, ROM 0x31D7C; helper 0x8001575C, table 0x800A9F00, references
  0x80121AF0, 0x80121B70 and 0x80121AB0.
- lrg_rev1 shares the USA addresses and the USA symbol addresses.
Both regional bodies were read instruction by instruction; they are the same 164
bytes and differ from USA only in those six addresses.

## Recovered behavior
The function answers "has this record's table entry drifted away from its
expected state?". It looks up the entry named by the record's index and compares
its second vector with the first reference vector. If they differ the answer is
immediately yes. Otherwise it compares the same vector against the second
reference; again a difference answers yes at once. Only when both of those match
does it compare the entry's first vector with the third reference, and the
answer is whether that last comparison failed. Callers use a non-zero result as
"something changed, act on it".

## Notes on shape
The result has to be a single named local that the two early exits fall through
to, with the second and third comparisons nested inside `if (result == 0)`
blocks. Written as one short-circuit `||` expression the behaviour is identical
but IDO materialises the result into the return register at each exit, adding two
register moves and eight bytes. The nested form leaves the value in one register
and moves it once in the shared epilogue, which is what the original does.

## Status
exact - USA, JP, EU and lrg_rev1 all verified byte-identical.
