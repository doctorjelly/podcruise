# Medium world-state tranche

Status: **6 behavior-recovered functions measured in all four builds; none is
byte-matching C**.

## Verified facts

Every USA entry is a direct `jal` target with a complete interval through its
executed return delay slot.

| Function | ROM | Bytes | `jr ra` / executed delay slot | Direct USA callers |
| --- | ---: | ---: | --- | --- |
| `func_80006848` | `0x007448` | 952 | `80006BF8` / `nop` | `80006790` at `80006830`; `80006C00` at `80006C68` |
| `func_8006AF48` | `0x06BB48` | 956 | `8006B2FC` / restore the 200-byte frame | `8006C0D4` at `8006C52C` |
| `func_80081FB0` | `0x082BB0` | 1,012 | `8008239C` / restore the 184-byte frame | `80083EFC` at `80084020` |
| `func_80037E9C` | `0x038A9C` | 1,016 | `8003828C` / restore the 192-byte frame | `80038388` at `800384CC` |
| `func_800049FC` | `0x0055FC` | 1,024 | `80004DF4` / restore the 200-byte frame | `80004DFC` at `80004E4C` |
| `func_8002963C` | `0x02A23C` | 1,024 | `80029A34` / restore the 40-byte frame | `8004BE90` at `8004C5DC`, `8004C64C` |

The next entries start at `80006C00`, `8006B304`, `800823A4`, `80038294`,
`80004DFC`, and `80029A3C`. These boundaries were checked independently of the
source candidates; no following-function bytes are included.

## Behavioral specification

| Function | Independently stated behavior |
| --- | --- |
| `func_80006848` | Advance an object's track parameter using elapsed time, playback rate, and a startup fraction. Resolve range-selection flags, then clamp, wrap, or reflect the parameter at the active range according to the object's control bits. Recalculate the current key interval after crossing a boundary, or walk the key-time array until the saved interval again contains the parameter. |
| `func_8006AF48` | Clamp a path look-ahead value, sample the path at its origin and look-ahead positions, and adjust that value according to the squared sample separation. Blend the sampled direction toward the object's current direction, update its lateral angle from control fields, construct and normalize an orthogonal basis, rotate that basis by three frame-scaled angles, copy the requested position, and clear one accumulator. |
| `func_80081FB0` | Construct the triangle plane, remember which side contains the query point, and project the point onto the plane. Reject it when the initial squared distance exceeds a positive limit. If the projection lies outside the triangle, project it onto all three edges and retain the closest result. Return that squared distance and output the plane normal facing the query side. |
| `func_80037E9C` | Build a node transform from the active environment and the node's orientation mode, scale its basis, and optionally replace its translation with the environment anchor. Push the transform while recursion depth permits. Visit child nodes whose two masks satisfy the environment filters, invoke their processing helper, then pop the transform if it was pushed and decrement the depth counter. |
| `func_800049FC` | Initialize a global query volume when requested, derive its opposite endpoint, and reject a missing node or a node whose bounds do not contain that volume. Walk contained child volumes, choose two global mode flags from each child's type unless a global override is active, and process the child. Finally flush a pending query state and clear its flag. |
| `func_8002963C` | Count enabled bits across four saved groups and copy seven current group selections into working records. In one owner mode, enumerate every unlocked alternate that is not currently selected; in another, copy seven saved selections. Create one object for every alternate and another for each current group selection. |

The C sources express these reviewed behaviors independently. Address-based
names remain because the surrounding structures and subsystem terminology are
not established strongly enough for authored names.

## Calls and addressed globals

| Function | Direct callees | Addressed globals |
| --- | --- | --- |
| `func_80006848` | `80006704`, `80006790` | `D_8009A2A4`, `D_80120BF0` |
| `func_8006AF48` | `80015288`, `8001535C`, `800154D0`, `80015538`, `800155EC`, `80017824`, `8003B184` | `D_800AD5BC`, `D_800AD5C4/C8/CC/D0/D8/E0`, `D_80120BF0` |
| `func_80081FB0` | `800179EC`, `800819A4`, `80081A2C`, `80081BE8` | none |
| `func_80037E9C` | `800153C0`, `800154D0`, `80015538`, `800155C0`, `800155EC`, `80017DAC`, `800182FC`, `80033EEC`, `8003423C`, `800344C8`, `80038388` | `D_800A3FD8`, `D_800A3FE8`, `D_80112C94` |
| `func_800049FC` | `800035BC`, `80003B44`, `80004704`, `800155EC`, `80017E54`, `80017E88`, `80017EDC` | `D_8009A270/74/78`, `D_800AE8B0`, `D_800AE8E8`, `D_800AE918`, `D_800AE928`, `D_800AEC78/7C` |
| `func_8002963C` | `80046670` | `D_800A21B4`, `D_800A2DE0`, `D_80113E60/68`, `D_801198A8`, `D_8011A050`, `D_8011A210`, `D_8011A240` |

No indirect call occurs in these bodies.

## Regional evidence

| USA | Japan | Europe | Compared instructions |
| --- | --- | --- | ---: |
| `800049FC` | `800049FC` | `800049FC` | 256 |
| `80006848` | `80006848` | `80006848` | 238 |
| `8002963C` | `80029EC4` | `8002BD18` | 256 |
| `80037E9C` | `800388FC` | `8003C80C` | 254 |
| `8006AF48` | `8006BAB8` | `80070428` | 239 |
| `80081FB0` | `80082C50` | `80087490` | 253 |

Each complete Japan and Europe body has the same relocation-normalized
instruction sequence as USA, including its return delay slot. Callee and global
relocations were aligned at their corresponding instructions. LRG has the exact
USA bytes. This is shared-source evidence, not a compiler-match claim.

## Exact compiler comparison

IDO 5.3 `-O2 -mips2` places every unit at its canonical regional address and
produces the same result in all four builds.

| Function | Target bytes | C bytes | First difference | Status |
| --- | ---: | ---: | ---: | --- |
| `func_80006848` | 952 | 948 | `0x119` | behavior-recovered |
| `func_8006AF48` | 956 | 964 | `0x19` | behavior-recovered |
| `func_80081FB0` | 1,012 | 1,028 | `0x05` | behavior-recovered |
| `func_80037E9C` | 1,016 | 1,016 | `0x2F` | behavior-recovered |
| `func_800049FC` | 1,024 | 1,024 | `0x93` | behavior-recovered |
| `func_8002963C` | 1,024 | 1,024 | `0x05` | behavior-recovered |

None is eligible for hybrid-build substitution, and no byte match is claimed.
