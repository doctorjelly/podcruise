# Medium resource and control tranche

Status: **6 behavior-recovered USA functions; none is byte-matching C**. Five
also have reviewed Japan and Europe equivalents. The sixth is configured only
for USA and the byte-identical LRG revision because the regional evidence does
not support a shared body.

## Verified facts

Each USA entry is a direct `jal` target. The complete interval, return, and
executed MIPS delay slot were checked against the canonical ROM.

| Function | ROM | Bytes | `jr ra` / executed delay slot | Direct USA callers |
| --- | ---: | ---: | --- | --- |
| `func_800305E8` | `0x0311E8` | 892 | `8003095C` / restore the 136-byte frame | 60 sites in twelve functions |
| `func_800738D4` | `0x0744D4` | 900 | `80073C50` / `nop` | `800784F8` at `8007869C`, `800787A4` |
| `func_80050C00` | `0x051800` | 904 | `80050F80` / `nop` | `800509E8` at `80050AB0`, `80050AEC` |
| `func_8005065C` | `0x05125C` | 908 | `800509E0` / `nop` | `8004A880` at `8004AD8C` |
| `func_8004F358` | `0x04FF58` | 912 | `8004F6E0` / restore the 120-byte frame | `8004A6A4` at `8004A70C` |
| `func_8001CCC4` | `0x01D8C4` | 920 | `8001D054` / `nop` | `8001ADD4` at `8001BC74` |

The next entries start at `80030964`, `80073C58`, `80050F88`, `800509E8`,
`8004F6E8`, and `8001D05C`; the measured sizes therefore include each return
delay slot and no following function bytes. The `func_800305E8` callers are
`80030CA0`, `80045694`, `80045C88`, `8004611C`, `80046670`, `8005EA0C`,
`8005EAC0`, `8005EC18`, `8005ED70`, `8005EF08`, `800600A0`, and `8007E0EC`.

## Behavioral specification

| Function | Independently stated behavior |
| --- | --- |
| `func_800305E8` | Validate a resource index, copy its relocation bitmap and data interval, and reserve an aligned destination. Expand a compressed payload when its header requests it, rejecting either representation when allocator space is insufficient. Relocate marked words, resolve special references through a helper, accept a fixed set of object tags by returning the payload after the tag, report an unknown tag otherwise, and publish allocation statistics. |
| `func_800738D4` | Choose one of two effect-slot pairs from the mode and derive an intensity from the craft state. Below the threshold, notify and hide the first slot while resetting the second transform. Otherwise build an oriented frame between the two supplied points, place it at their midpoint, derive scaled transforms for both slots, and pass those transforms to the attached objects that exist. |
| `func_80050C00` | Select movement limits from the actor mode, frame scale, and global modifiers. Measure the supplied point spans, accelerate or decelerate the saved step as the destination approaches, then move the second point toward the first. Clamp an overshoot to the destination and report completion; otherwise preserve the updated step and report that movement remains. |
| `func_8005065C` | Snapshot two global positions and, when requested, calculate translation deltas and select a short or long interpolation duration. Advance the interpolation by the frame scale and blend the global transforms. At completion, update mode flags, optionally toggle a state bit, copy the completed matrices, and clear that bit under the active-object condition. |
| `func_8004F358` | Reset the owner's prior selection state, optionally choose a usable random table entry, and apply a forced global selection when enabled. Assemble a tagged message from the selected entry, owner fields, and table values, falling back to entry sixteen for invalid record identifiers. Dispatch either the judge path with cleanup or the scene path with the requested scene identifier. |
| `func_8001CCC4` | Draw the current three-character selection or the special label, optional prompt lines, and two choices. Process accept and cancel bits from the selected input record: accept advances or confirms the two-stage choice and invokes the corresponding updates, while cancel clears the selection state. Two additional input bits toggle the first-stage choice and play its cue. |

The reviewed C expresses these behaviors independently and retains address-based
names because the surrounding data types and subsystem vocabulary are not yet
secure.

## Calls and addressed globals

| Function | Direct callees | Addressed globals |
| --- | --- | --- |
| `func_800305E8` | `80011940`, `80011CDC`, `80011D60`, `8002FAC4`, `8002FAFC`, `8002FC58`, `800304AC`, `800827C0` | `D_800A2848`, `D_800A2864`, `D_800D9DBC` through `D_800D9DD0`, `D_80114528`, `D_141E200` |
| `func_800738D4` | `80015288`, `800153C0`, `800154D0`, `80015538`, `800155C0`, `800155EC`, `800156DC`, `80017520`, `80017580`, `80017874`, `80017BA8`, `800181BC` | `D_800A6664`, `D_800AD930`, `D_800AD938`, `D_800AD940` |
| `func_80050C00` | `80015288`, `8001535C`, `80015390`, `800153C0`, `800154D0`, `800155EC`; `sqrtf` is compiled as an intrinsic | `D_800A2198`, `D_800A4BDC`, `D_800A4BF4`, `D_800A5274`, `D_800AB354` through `D_800AB360`, `D_80120BF8` |
| `func_8005065C` | `80015288`, `800156DC` | `D_800A2198/9C`, `D_800A4BC0/C4/D0/D4`, `D_800AB350`, `D_80118D60` through `D_80118ED8`, `D_8011AC24` through `D_8011AC40`, `D_80120BF8` |
| `func_8004F358` | `8002FA00`, `80030298`, `80039EC0`, `8003FA24`, `8004F254`, `8004F6E8`, `8004F790`, `8004FF7C`, `80082BE0` | `D_800A21B8`, `D_800A4BFC`, `D_800A5998`, `D_80113680`, `D_80119668` |
| `func_8001CCC4` | `80029A3C`, `8002BBA4`, `8002D4C4`, `8003964C`, `800399F0`, `8003EC40`, `8008A6B4` | `D_800A23BC/C0`, `D_800A4B94/A4`, `D_800A8B54/74/88/A0/B8/D4/E4`, `D_80113680` |

No indirect call occurs in these bodies.

## Regional evidence and inference

| USA | Japan | Europe | Compared instructions |
| --- | --- | --- | ---: |
| `800305E8` | `80031048` | `80033BA8` | 223 |
| `800738D4` | `80074504` | `80078DB4` | 225 |
| `80050C00` | `8005186C` | `800558A8` | 226 |
| `8005065C` | `800512C8` | `80055304` | 227 |
| `8004F358` | `8004FFC4` | `80054000` | 228 |

For these five rows, the complete Japan and Europe spans have the same
relocation-normalized instruction sequence as USA, including the return delay
slot. Callees and addressed globals were mapped at their corresponding
instructions. This supports a shared-source inference; it does not prove a
compiler match. LRG carries the exact USA bytes.

`func_8001CCC4` is deliberately different. The mapper's short 32-instruction
window proposed Japan `8001CDF0`, but the complete normalized bodies first
diverge at instruction index 37 and then implement different work. Europe has
no unique mapping. No Japan or Europe unit is configured for this function;
only USA and byte-identical LRG are claimed.

## Exact compiler comparison

IDO 5.3 `-O2 -mips2` placed every configured function at its regional canonical
address. The five shared bodies produced the same result in USA, Japan, Europe,
and LRG; `func_8001CCC4` produced the same result in USA and LRG.

| Function | Target bytes | C bytes | First difference | Status |
| --- | ---: | ---: | ---: | --- |
| `func_800305E8` | 892 | 888 | `0x21` | behavior-recovered |
| `func_800738D4` | 900 | 896 | `0x1B` | behavior-recovered |
| `func_80050C00` | 904 | 904 | `0x21` | behavior-recovered |
| `func_8005065C` | 908 | 908 | `0x03` | behavior-recovered |
| `func_8004F358` | 912 | 936 | `0x03` | behavior-recovered |
| `func_8001CCC4` | 920 | 932 | `0x51` | behavior-recovered |

None is eligible for hybrid-build substitution, and no byte match is claimed.
