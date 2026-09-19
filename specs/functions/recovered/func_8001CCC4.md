# `func_8001CCC4` USA buffer-order audit

The behavior-recovered C compiles at the canonical address with a 0x140-byte
frame, but its 932-byte symbol exceeds the ROM's 920 bytes by three words;
180 comparable words differ, first at `+0x51`. The `letters[3]` and
`text[0x100]` buffers occupy the opposite stack order from the ROM.

Swapping only their declaration order kept the 932-byte size and three-word
excess, reducing comparable differences to 175 but not producing a match.
The source was restored and the parent reran the original comparison. This
single declaration swap is exhausted; further work should address the
accept-path block order and extra instructions with specific ROM evidence.
