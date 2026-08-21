# Object global initializer

Status: **behavior-recovered C; not byte-matching and not integrated**.

`func_800183C0` is a 120-byte leaf at USA `0x800183C0`. Its only direct caller
is `func_8002F4D0`, and its only global dependency is the object rooted at
`D_800D6960`. Japan and Europe contain unique equivalents at `0x800184F0` and
`0x80018850` with the same field operations.

The function clears six floats at offsets `0x00` through `0x14`, clears the
word at `0x18`, builds the word at `0x1C` to the final value nine, writes zero
and two to halfwords `0x20` and `0x22`, writes unit floats at `0x24` and
`0x28`, clears the word at `0x2C`, writes one at `0x30`, writes 30 and zero to
halfwords `0x34` and `0x36`, and clears the word at `0x38`.

The terminal `jr` is at `0x80018430`; its delay slot stores the unit float at
offset `0x24`. The following two no-operations are padding and are not part of
the function. The independently written C compiles to the correct 120-byte
size and behavior, but IDO 5.3 first differs at function offset `0x15` because
of temporary-register allocation and instruction scheduling. Assembly remains
in the matching build, and this function is not counted as matching C.

The offsets, widths, constants, caller, regional correspondence, and delay slot
are observed facts. Treating the storage as one structured global is an
inference pending wider type recovery.
