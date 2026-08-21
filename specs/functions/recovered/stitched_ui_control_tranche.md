# Stitched UI-control tranche

Status: **four USA functions are behavior-recovered; none is byte-matching C**.

## Verified USA boundaries

The entry of each routine is a direct `jal` target. In each case, the function
finder incorrectly treated early instructions scheduled before the stack-frame
allocation as a tiny function and the allocation as a second prologue. Scanning
the complete control flow finds no return at that internal point.

| Entry | ROM | Bytes | Misidentified internal point | Return / executed delay slot |
| --- | ---: | ---: | --- | --- |
| `80024954` | `0x025554` | 2,036 | `80024960` | `80025140` / restore 360-byte frame |
| `8002A7D4` | `0x02B3D4` | 1,436 | `8002A7E4` | `8002AD68` / restore 168-byte frame |
| `8002C780` | `0x02D380` | 1,192 | `8002C78C` | `8002CC20` / `nop` |
| `8002CC28` | `0x02D828` | 1,056 | `8002CC34` | `8002D040` / `nop` |

The next independently observed entries are `80025148`, `8002AD70`,
`8002CC28`, and `8002D048`, respectively. Those entries begin new frames after
the listed return and delay slot.

## Call and data evidence

| Function | Direct caller sites | Direct callees |
| --- | --- | --- |
| `func_80024954` | `8004ABDC` | `800503E8`, `80024704`, `8002DA0C`, `80024874`, `8004BAC8`, `80064A88`, `8002DB20`, `800494D0`, `8008A6B4`, `80082BE0`, `8003EC40`, `8002D598`, `800129B8`, `8002CC28`, `8001C404`, `8000A920`, `8000AA04`, `8000AAC0`, `8000AB24`, `8002C780`, `80064B44`, `8002D4C4`, `800469B4` |
| `func_8002A7D4` | `8001F8A4` | `8000AB24`, `8000A920`, `8000AA04`, `8003EC40`, `8008A6B4`, `8002BBA4`, `8004A36C`, `8002D4C4` |
| `func_8002C780` | `80023DD8`, `80024FB8` | `8000A920`, `8000AA04`, `8000AB24`, `8000AAC0` |
| `func_8002CC28` | `8001B67C`, `8001F9AC`, `80024360`, `80024CF4`, `80025C3C` | `8000A920`, `8000AA04`, `8000AB24`, `8000AAC0` |

Addressed data was checked over each complete interval:

| Function | Globals |
| --- | --- |
| `func_80024954` | `D_800A21B8`, `D_800A21C1`, `D_800A22E8`, `D_800A256C`, `D_800A4BA4`, `D_800A4BBC`, strings `D_800A8F38`–`D_800A9024`, `D_800A9D10`, `D_800A9D14`, `D_800D6DD8`, `D_800D73E4`, `D_800D73E5`, `D_80119658`, `D_8011A240` |
| `func_8002A7D4` | `D_800A4BA4`, `D_800A4BC0`, strings `D_800A975C`–`D_800A9814`, `D_800A9E20`, `D_800D6CC0`, `D_800D6CC4`, `D_80113E60` |
| `func_8002C780` | `D_800A2654`, `D_800A2658`, `D_800A4B94`, `D_800A9ED8`, `D_800A9EDC`, `D_8011A240`, `D_80120BF8` |
| `func_8002CC28` | `D_800A265C`, `D_800A2660`, `D_800A9EE0`, `D_800A9EE4`, `D_8011A240`, `D_80120BF8` |

## Independent behavioral specifications

| Function | Behavior |
| --- | --- |
| `func_80024954` | Initialize and update a selection panel, animate the selected item, render its label, status, icon, and two gauges, then process confirm, cancel, and directional input to transition or change the selection with the corresponding feedback sounds. |
| `func_8002A7D4` | Draw a multi-line settings/status panel, format its numeric values and labels, update a two-choice selector from directional input when the required score is available, and force the locked choice otherwise. |
| `func_8002C780` | Move two gauge alpha values toward visible or hidden according to two option flags, clamp them to the byte-alpha range, draw the paired gauge decorations and fill, and show directional hints when their inputs are active. |
| `func_8002CC28` | Animate and draw a horizontally arranged pair of option gauges, including their decorations, fill scale, and enabled left/right hints, with independently clamped alpha values. |

The C in the four address-named source files expresses these behaviors without
using authored source or symbols from another decompilation.

## Regional evidence and limits

`func_8002C780` maps to Japan `8002D1E4` and Europe `8002F79C`;
`func_8002CC28` maps to Japan `8002D68C` and Europe `8002FC44`. Each mapped
interval has the same size and the complete normalized instruction sequence is
identical, including its return delay slot. Their data references were relocated
from the corresponding aligned loads rather than assumed from a single delta.

The likely regional counterparts of `func_80024954` are Japan `80025090`
(2,036 bytes) and Europe `80026164` (2,632 bytes). The likely counterparts of
`func_8002A7D4` are Japan `8002B178` (1,596 bytes) and Europe `8002D284`
(2,464 bytes). These mappings follow the aligned unique caller sites and their
complete return-delimited intervals. They are inferences: localized rendering
changes their control flow, so the USA C is not configured as their regional C.
Even the equal-length Japanese `80025090` body has 20 normalized instruction
differences. LRG has the USA code bytes.

## Exact compiler comparison

The accepted comparison uses IDO 5.3 and the repository's `ido53_o2` profile.

| Function | Target / C bytes | First difference | Classification |
| --- | ---: | ---: | --- |
| `func_80024954` | 2,036 / 2,040 | `0x23` | behavior-recovered |
| `func_8002A7D4` | 1,436 / 1,436 | `0x13` | behavior-recovered |
| `func_8002C780` | 1,192 / 1,192 | `0x1` | behavior-recovered in USA/JP/EU/LRG |
| `func_8002CC28` | 1,056 / 1,056 | `0x0` | behavior-recovered in USA/JP/EU/LRG |

No row is eligible for exact-C substitution.
