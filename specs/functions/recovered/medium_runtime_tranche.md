# Medium runtime tranche

Status: **5 functions measured: canonical USA has 3 byte-matching and 2
behavior-recovered**.

## Verified facts

Each USA entry is a direct `jal` target with a conventional prologue. The
return and its executed delay slot determine the true end. In particular,
`func_8008C390` has two following padding `nop` words and `func_800950F4` has
one; those words are not included in the sizes below.

| Function | ROM | Bytes | `jr ra` / delay slot | USA call sites |
| --- | ---: | ---: | --- | ---: |
| `func_80067AB4` | `0x0686B4` | 444 | `80067C68` / restore the 72-byte frame | 1 |
| `func_80075FC4` | `0x076BC4` | 444 | `80076178` / `nop` | 4 |
| `func_8007B828` | `0x07C428` | 444 | `8007B9DC` / `nop` | 9 |
| `func_8008C390` | `0x08CF90` | 440 | `8008C540` / `nop` | 8 |
| `func_800950F4` | `0x095CF4` | 424 | `80095294` / `nop` | 5 |

## Behavioral specification

| Function | Independently stated behavior |
| --- | --- |
| `func_80067AB4` | Derive two vertical parameters and run the core body-adjustment helper. Unless flag `0x400` is set, temporarily remove the prior offset, update that offset with a 70-or-300 ceiling, apply a global correction to the result, and optionally blend it toward `unk208 * 80`; always save the final vertical value. |
| `func_80075FC4` | Copy two transform positions, add table-derived endpoint offsets after transforming them, and calculate the normalized direction and distance between the endpoints. Build an orientation frame at the first endpoint, scale it by the global lateral factor and distance divided by 100, and copy the frame to the output. |
| `func_8007B828` | Map selected object kinds to shared groups and update the object's record-state bit. For mapped kinds, notify the shared group object, clear object flag bit 0, and run cleanup. Kind `0x6C` performs the corresponding group-2 and display notifications before the same cleanup. |
| `func_8008C390` | Enter an interrupt-protected section and interpret argument bits as independent requests to set or clear three state bits. Bit 6 enables `0x10000` while clearing `0x300`; bit 7 reverses that and restores `0x300` from a referenced object. Mark the global object changed and restore interrupt state. |
| `func_800950F4` | Clear a 64-byte global command area, construct and submit a fixed command, wait, submit a second command, and wait again. Return a transport error if present; otherwise clear packet header bytes, decode a status nibble, a big-endian halfword, and one byte into the output, and return the decoded status. |

## Calls and addressed globals

| Function | Callees | Addressed globals |
| --- | --- | --- |
| `func_80067AB4` | `800334F4`, `80065E54` | `D_800AD4E0` |
| `func_80075FC4` | `80015268`, `80015288`, `80015328`, `8001535C`, `800153C0`, `800154D0`, `80015538`, `800156DC`, `80016BF4`, `80017580`, `80017918` | `D_800A5CA0`, `D_800AD9D4` |
| `func_8007B828` | `800181BC`, `8003FD7C`, `8007B744` | `D_8011C910`, `D_8011C918` |
| `func_8008C390` | `8008CA80`, `8008CAA0` | `D_800A7F54` |
| `func_800950F4` | `80087E80`, `800907D0` | `D_80149CB0`, `D_8014C530`, `D_8014C531`, `D_8014C570` |

## Regional evidence

| USA | Japan | Europe |
| --- | --- | --- |
| `80067AB4` | `80068624` | `8006CF94` |
| `80075FC4` | `80076BF4` | `8007B4A4` |
| `8007B828` | `8007C4C8` | `80080D08` |
| `8008C390` | `8008D080` | `800918E0` |
| `800950F4` | `80095DE4` | `8009A644` |

All regional locations have unique 32-instruction matches. The complete true
bodies contain 111, 111, 111, 110, and 106 instructions respectively, with
the same normalized sequence and relocation roles in Japan and Europe. LRG
has the exact USA bytes.

## Compiler status

Exact compiler comparisons place all five sources at their canonical address.
The table records the canonical USA result:

| Function | Target bytes | C bytes | First difference | Status |
| --- | ---: | ---: | ---: | --- |
| `func_80067AB4` | 444 | 440 | `0x03` | behavior-recovered |
| `func_80075FC4` | 444 | 444 | none | **byte-matching** |
| `func_8007B828` | 444 | 444 | none | **byte-matching** |
| `func_8008C390` | 440 | 440 | none | **byte-matching (`-O1`)** |
| `func_800950F4` | 424 | 436 | `0x03` | behavior-recovered |

The three exact USA functions are eligible to replace assembly. Japan and
Europe still measure `func_8008C390` under their default `-O2` units and are
not claimed exact. The later USA revision inherits the same verified `-O1`
match. The other two USA functions remain behavioral recoveries. Address-based
names remain until subsystem semantics justify replacements.

For `func_80067AB4`, writing the nonzero test as a scalar condition restores
the canonical 444-byte instruction count and separate zero materializations.
The frame remains 64 rather than 72 bytes and 16 instruction words still
differ through floating-point register allocation, so that form is not an
exact match and was reverted.
