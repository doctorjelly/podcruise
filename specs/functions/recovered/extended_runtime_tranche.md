# Extended runtime tranche

Status: **6 behavior-recovered functions measured in all four builds; none is
byte-matching C**.

## Verified facts

Each USA entry is a direct `jal` target. Its complete interval, return, and
executed MIPS delay slot were checked in the canonical ROM.

| Function | ROM | Bytes | `jr ra` / executed delay slot | Direct USA callers |
| --- | ---: | ---: | --- | --- |
| `func_80009C0C` | `0x00A80C` | 864 | `80009F64` / restore the 88-byte frame | `80073CD0` at `80073D78` |
| `func_80010B34` | `0x011734` | 876 | `80010E98` / restore the 224-byte frame | reviewed `80011888` unit at `800118B8` |
| `func_80016F0C` | `0x017B0C` | 816 | `80017234` / `nop` | 16 sites in ten functions |
| `func_800419EC` | `0x0425EC` | 808 | `80041D0C` / `nop` | `80043598` at `800437C4` |
| `func_80068D04` | `0x069904` | 888 | `80069074` / `nop` | `8006907C` at `800690C8` |
| `func_800747E4` | `0x0753E4` | 804 | `80074B00` / `nop` | `80074CDC` at `800751F4` |

The following entries begin at `80009F6C`, `80010EA0`, `8001723C`,
`80041D14`, `8006907C`, and `80074B08`. None of these candidate intervals has
trailing alignment padding. The sixteen `func_80016F0C` calls are in
`func_8000B318` (three), `func_8000BC10`, `func_80017F64`, `func_80041D14`,
`func_80041F40`, `func_80043598`, `func_8004CA50` (three), `func_8005FA38`
(three), `func_800704A8`, and `func_80072AD0`.

## Behavioral specification

| Function | Independently stated behavior |
| --- | --- |
| `func_80009C0C` | Service a periodic cue table for the requested mode and phase. Occasionally emit a randomized cue under one mode gate; otherwise locate the interval containing the phase, handle intervals that wrap at one, derive an edge-faded level, apply the special global scale to cue five, and submit a positive cue level. Flagged entries instead use a separate randomized cooldown. |
| `func_80010B34` | For every configured marker, clear its saved screen coordinates, reject markers beyond the distance cutoff, project the remaining world positions, and retain coordinates inside the screen bounds. Compare the projected depth with the stored scene depth; when visible and backed by a sprite, enable and position that sprite and update its scale, rotation, and white alpha. |
| `func_80016F0C` | Copy a matrix translation into the first three outputs and derive three orientation angles from its basis rows. Use length thresholds and clamped inverse-trigonometric inputs to handle near-singular horizontal axes, then choose signs from the remaining components so the angles preserve the matrix orientation. |
| `func_800419EC` | Advance a linked object's phase timer. On the first transition, snapshot and adjust the linked pose and blend an offset from the current basis; on the next phase, update that pose and take the linked position; on the final phase, change the linked flags and reset it. Rebuild two identity transforms and install the selected offset and base position. |
| `func_80068D04` | Orient an input axis with the sign of the requested amount and remove any opposing component from the body's current vector. Build and blend a requested velocity with that vector using the body's scalar factors and frame scale, normalize it to the requested magnitude, then move a body factor toward the limit selected by two flags unless a third flag freezes it. |
| `func_800747E4` | Ignore objects without an active steering request. Choose a direction from two control flags, accelerate a shared turn factor, and accumulate two signed angles. For the selected side part and a second fixed part, derive an axis from the current transform, rotate around it without moving the stored origin, and copy the result to an attached transform when present. |

The C sources were written independently from the reviewed behavior and retain
address-based names because broader subsystem semantics are not yet secure.
`func_80010B34` deliberately retains an odd same-result conditional: both ROM
branches pass the same stack output address, and simplifying the source would
erase observed control flow.

## Calls and addressed globals

| Function | Direct callees | Addressed globals |
| --- | --- | --- |
| `func_80009C0C` | `80008B14`, `80082BE0` | `D_8009AF28`, `D_8009AF2C`, `D_8009B0B8`, `D_8009B43C`, `D_8009B70C`, `D_800A8230`, `D_80120BF0` |
| `func_80010B34` | `80015470`, `8000EBE8`, `8001004C`, `8000A920`, `8000E680`, `8000AAF8`, `8000AAC0`, `8000AB24` | `D_8009B86C`, `D_800A3FDC`, `D_800A86AC`, `D_800D5898`, `D_800D5958`, `D_800D5988`, `D_800D5F80`, `D_800D6070`, `D_80114470`, `D_80114472` |
| `func_80016F0C` | `800153C0`, `80014F2C` | `D_800A87F8`, `D_800A8800`, `D_800A8808` |
| `func_800419EC` | `80041214`, `8003B02C`, `8001535C`, `800154D0`, `800155EC`, `80015288` | `D_800AAC50`, `D_800AAC58`, `D_80120BF0` |
| `func_80068D04` | `800155C0`, `800154D0` | `D_800AD528`, `D_800AD52C`, `D_800AD530`, `D_80120BF0` |
| `func_800747E4` | `800156DC`, `800155EC`, `80015288`, `80015268`, `800154D0`, `80017824`, `80017BA8` | `D_800AD988`, `D_800AD990`, `D_80120BF0` |

No indirect calls occur in these six bodies.

## Regional evidence

| USA | Japan | Europe | Compared instructions |
| --- | --- | --- | ---: |
| `80009C0C` | `80009C0C` | `80009C0C` | 216 |
| `80010B34` | `80010B34` | `80010FC4` | 219 |
| `80016F0C` | `8001703C` | `8001739C` | 204 |
| `800419EC` | `800421F4` | `8004638C` | 202 |
| `80068D04` | `80069874` | `8006E1E4` | 222 |
| `800747E4` | `80075414` | `80079CC4` | 201 |

Every regional start has a unique relocation-insensitive 32-instruction match.
The complete intervals have identical normalized instruction structure,
including their return delay slots, and every callee and addressed global was
aligned at the corresponding instruction. LRG has the exact USA bytes. This is
strong evidence for a shared source shape, but it is not by itself a semantic
or compiler-match proof.

## Compiler status

Exact IDO 5.3 `-O2 -mips2` comparisons place every function at its canonical
address. Japan and Europe produce the same size and first-difference offset as
USA after their symbol relocations.

| Function | Target bytes | C bytes | First difference | Status |
| --- | ---: | ---: | ---: | --- |
| `func_80009C0C` | 864 | 864 | `0x169` | behavior-recovered |
| `func_80010B34` | 876 | 840 | `0x53` | behavior-recovered |
| `func_80016F0C` | 816 | 816 | `0xB9` | behavior-recovered |
| `func_800419EC` | 808 | 800 | `0x07` | behavior-recovered |
| `func_80068D04` | 888 | 888 | `0x91` | behavior-recovered |
| `func_800747E4` | 804 | 796 | `0x2B` | behavior-recovered |

No function in this tranche is eligible for hybrid-build substitution, and no
byte match is claimed.
