# func_8004DFEC — clear the four-slot request tables

## Boundary

* USA VRAM `0x8004DFEC` .. `0x8004E033` (72 bytes, 18 instructions), ROM `0x4EBEC`.
* Ends with the return instruction at `0x8004E02C` and an empty delay slot.
* Two direct callers target the entry; nothing branches into the middle. The
  assigned boundary is correct.

## Callers and callees

* Callers: 2.
* Callees: none — leaf.

## Globals and access widths

| symbol | shape | use |
| --- | --- | --- |
| `D_800A4B94` | four 32-bit words | per-slot request mask, cleared to all-ones |
| `D_800A4BA4` | four 32-bit words | per-slot acknowledgement mask, cleared to zero |

The two tables are adjacent: the second begins 16 bytes after the first.

## Regional addresses

| version | entry | ROM | request table | acknowledgement table |
| --- | --- | --- | --- | --- |
| usa | `0x8004DFEC` | `0x4EBEC` | `D_800A4B94` | `D_800A4BA4` |
| japan | `0x8004EC58` | `0x4F858` | `D_800A7904` | `D_800A7914` |
| europe | `0x80052B0C` | `0x5370C` | `D_800A9E94` | `D_800A9EA4` |
| lrg_rev1 | `0x8004DFEC` | `0x4EBEC` | same as usa | same as usa |

Each regional body was read independently; all are the same shape as USA.

## Recovered behaviour

Reset both per-slot tables for all four slots: every entry of the request table
is set to all-ones (the "nothing pending" marker used by the readers of that
table) and every entry of the acknowledgement table is set to zero.

The loop counter is a 16-bit signed quantity, which is why the count is
sign-extended back to 16 bits on each pass; that detail is visible in the
original and is reproduced by declaring the counter as a 16-bit signed local.

## Status

Exact. Byte-identical in USA, Japan, Europe and lrg_rev1.
