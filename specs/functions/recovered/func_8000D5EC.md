# func_8000D5EC

## Boundary and evidence

USA is VRAM `0x8000D5EC`, ROM `0x00E1EC`, 496 bytes, ending immediately before
`func_8000D7DC`. The return at `0x8000D7D4` has a `nop` delay slot. Its direct
caller is `func_8000D90C`; it calls only `func_8000C724` and `func_8000C6C8`.
Japan is unchanged at `0x8000D5EC`; Europe relocates to `0x8000D680` / ROM
`0x00E280`.

## Behavior

Dispatch selectors zero through eight. Selector zero adjusts a bounded integer
setting. Selectors two through five adjust four bounded float settings when
their feature bit is enabled. Selectors one and six toggle two global switches
under separate gates. Selector seven toggles bit `0x4000` in a shared record;
selector eight and out-of-range values do nothing. The isolated source keeps a
three-word constant-pool placeholder so its jump table can be tested at the
original position.

## Status

Behavior recovered only; the current IDO 5.3 `-O2` comparison does not match
the USA bytes.
