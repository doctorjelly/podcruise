# func_8002DCF4

## Boundary

- USA VRAM `0x8002DCF4`..`0x8002DD7C`, ROM `0x2E8F4`, size 136 bytes (34 instructions).
- Terminates with a return instruction whose delay slot is empty; the two
  labels inside the range are internal branch targets with no direct callers,
  so the assigned boundary is correct and was not changed.
- Frame is 24 bytes, holding only the saved return address.

## Callers

One direct call site in the USA build. The caller consumes the returned word.

## Callees

`func_8002D968` — a three-byte comparison helper that is gated on a global
enable bit and returns a boolean.

## Globals and access widths

Eight addresses, all used only as the target of an address-of, never loaded or
stored here, so this function imposes no width on them:

| symbol | role |
| --- | --- |
| `D_80113694`, `D_801136C0`, `D_801136EC`, `D_80113718` | first operand of each comparison; 0x2C apart, so each is one record of a 44-byte table |
| `D_800A9ABC`, `D_800A9AC0`, `D_800A9AC4`, `D_800A9AC8` | second operand of each comparison; 4 bytes apart |

Because the four table addresses are each materialised with their own
high/low pair rather than indexed off one base, the source names four separate
objects; it is not an indexed loop over an array.

## Regional addresses

| version | entry | ROM | callee |
| --- | --- | --- | --- |
| USA | `0x8002DCF4` | `0x2E8F4` | `func_8002D968` |
| Japan | `0x8002E758` | `0x2F358` | `func_8002E3CC` |
| Europe | `0x80031298` | `0x31E98` | `func_80030F0C` |
| lrg_rev1 | same as USA | same as USA | same as USA |

Regional operand symbols: Japan `D_80116904`/`D_80116930`/`D_8011695C`/
`D_80116988` against `D_800ACA60`/`D_800ACA64`/`D_800ACA68`/`D_800ACA6C`;
Europe `D_8011C334`/`D_8011C360`/`D_8011C38C`/`D_8011C3B8` against
`D_800B1704`/`D_800B1708`/`D_800B170C`/`D_800B1710`. Both regional bodies were
read directly and are instruction-for-instruction the same shape as USA.

## Recovered behavior

Takes no arguments. Compares four fixed pairs of small byte records in a fixed
order, stopping at the first pair that does not compare equal. Returns one when
all four pairs matched and zero otherwise. The four comparisons are ordinary
short-circuit conjunction: each later comparison is only performed if every
earlier one succeeded, which matters because the helper itself is gated on a
global mode bit and would otherwise be called needlessly.

The pairing of a 44-byte-strided table against a 4-byte-strided table suggests
each record carries a stored three-byte value that is being checked against a
live three-byte value held elsewhere, and the function answers "are all four
still in agreement".

## Status

Exact. Byte-identical in USA, Japan, Europe and lrg_rev1 under the accepted
`ido53_o2` profile. No per-unit flags needed.
