# func_8008EADC

## Boundary and evidence

USA is VRAM `0x8008EADC`, ROM `0x08F6DC`, 520 bytes ending before `0x8008ECE4`.
`jr $ra` at `0x8008ECDC` has a `nop` delay slot, followed by three alignment
`nop`s. `func_8008D5FC` installs this routine as a callback. The unique
equivalents are Japan `0x8008F7CC` / ROM `0x0903CC` and Europe `0x8009402C` /
ROM `0x094C2C`.

## Behavior

Return the existing command cursor for a zero request. In direct mode, ask the
source callback for the requested sample count and append one command describing
that result. Otherwise clamp and quantize the stream ratio, carry its fractional
sample remainder across calls, request the resulting integral count, append two
audio commands using the produced count, ratio, selector, and translated source
address, clear the one-shot selector byte, and return the advanced cursor.

## Status

Behavior recovered only; the current IDO 5.3 `-O2` comparison does not match
the USA bytes.

The final ratio is now quantized immediately after the source callback,
before either command is stored. The canonical ratio load at 8008EC44
precedes the first command store at 8008EC58. The parent audit emits
504/520 bytes with 126 differing words, versus 508/520 and 127 before;
the size gap grows despite recovering this operation order. Shared-return
and typed-command variants added no benefit and were reverted. Caller-saved
versus callee-saved allocation and an 80/88-byte frame difference remain.
