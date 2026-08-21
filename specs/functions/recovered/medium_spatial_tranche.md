# Medium spatial tranche

Status: **5 behavior-recovered functions measured in all four builds; none is
byte-matching C**.

## Verified facts

Each USA entry is a direct `jal` target with a high-confidence boundary. The
return and its executed delay slot were checked directly in the canonical ROM.

| Function | ROM | Bytes | `jr ra` / delay slot | Direct USA callers |
| --- | ---: | ---: | --- | ---: |
| `func_8004A36C` | `0x04AF6C` | 584 | `8004A5AC` / restore the 224-byte frame | 3 |
| `func_80003BF8` | `0x0047F8` | 596 | `80003E44` / restore the 120-byte frame | 1 |
| `func_80000B00` | `0x001700` | 640 | `80000D78` / restore the 136-byte frame | 14 |
| `func_8003FDCC` | `0x0409CC` | 644 | `80040048` / move the result count to `v0` | 6 |
| `func_8002AD70` | `0x02B970` | 652 | `8002AFF4` / restore the 72-byte frame | 1 |

The next entry begins immediately after each listed delay slot. The callers are
`80023E24`, `8002A670`, and `8002AC18` for `func_8004A36C`; `80003E9C` for
`func_80003BF8`; `800010E0`, `80001100`, `8000116C`, `8000118C`, `800011EC`,
`80001208`, `80001274`, `800012E0`, `80001340`, `8000163C`, `80001658`,
`80001674`, `80001820`, and `80001840` for `func_80000B00`; `8006ACF4`,
`8006BCD8`, `8006D844`, `80070040`, `80070D60`, and `80076F00` for
`func_8003FDCC`; and `8004AEC8` for `func_8002AD70`.

## Behavioral specification

| Function | Independently stated behavior |
| --- | --- |
| `func_8004A36C` | Resolve an indexed target and return if it is absent. Put the target in an initial mode, refresh the shared transform, and offset its shared position along three copied basis vectors. Build a transform at that point, rotate it around two basis axes using the index and shared phase, scale it uniformly, attach it to the target, and put the target in its final mode. |
| `func_80003BF8` | On the first requested pass, refresh the shared probe state. Form an axis-aligned cube from the probe center and radius, reject a node whose bounds do not overlap it, then test every child bounds record and submit each overlapping child. Run and clear the deferred finalizer when requested. |
| `func_80000B00` | Project a point onto each of a triangle's three edge segments. Select the projected point nearest a separate probe and, when its squared distance is within the shared threshold, pass that distance, point, probe, and normal to the response helper. |
| `func_8003FDCC` | Walk the global null-terminated group list. For matching active groups, test every eligible non-excluded entity against a squared-distance limit. Insert accepted entities, distances, and offsets into ascending-distance output arrays, truncate them to the caller's capacity, and return the number retained. |
| `func_8002AD70` | Initialize a random change interval when needed and run the actor update helper. While the global gate is open, advance a timer; when it expires, choose a different random state subject to actor-kind and progress restrictions. Publish the gate, invoke the transition helper when the state changed, and store the new state. |

## Calls and addressed globals

| Function | Callees | Addressed globals |
| --- | --- | --- |
| `func_8004A36C` | `80015268`, `80015288`, `800155EC`, `800156DC`, `800174B8`, `800178C4`, `80017918`, `80017BA8`, `800181BC`, `80028D60` | `D_800A4B50`, `D_800AB0D0`, `D_80118D60`, `D_80118D70`, `D_80118D80`, `D_80118D90`, `D_8011A654` |
| `func_80003BF8` | `800035BC`, `800038E8`, `80003B44`, `80017E54` | `D_800AE8E0`, `D_800AE908`, `D_800AE948`, `D_800AE960`, `D_800AEC78`, `D_800AEC7C` |
| `func_80000B00` | `8000097C`, `80081A2C` | `D_800AE8B0` |
| `func_8003FDCC` | none | `D_800A2170` |
| `func_8002AD70` | `8002AFFC`, `8002B3C8`, `80082BE0` | `D_800A2610`, `D_800A2614`, `D_800A31E0`, `D_800A4BC0`, `D_80113E60`, `D_80120BF8` |

## Regional evidence

| USA | Japan | Europe | Compared instructions |
| --- | --- | --- | ---: |
| `8004A36C` | `8004AFA4` | `8004EE8C` | 146 |
| `80003BF8` | `80003BF8` | `80003BF8` | 149 |
| `80000B00` | `80000B00` | `80000B00` | 160 |
| `8003FDCC` | `8004075C` | `8004476C` | 161 |
| `8002AD70` | `8002B7B4` | `8002DC24` | 163 |

All ten regional entries have unique relocation-insensitive 32-instruction
matches. The complete spans have the same normalized instruction sequence and
count as USA, and the LRG spans have the exact USA bytes. Callee and global
relocations were aligned at their corresponding instructions before the
regional compiler checks were configured.

## Compiler status

Exact IDO 5.3 `-O2 -mips2` comparisons place every function at its canonical
address. USA, Japan, Europe, and LRG give the same measurements:

| Function | Target bytes | C bytes | First difference | Status |
| --- | ---: | ---: | ---: | --- |
| `func_8004A36C` | 584 | 584 | `0xD7` | behavior-recovered |
| `func_80003BF8` | 596 | 600 | `0x03` | behavior-recovered |
| `func_80000B00` | 640 | 580 | `0x03` | behavior-recovered |
| `func_8003FDCC` | 644 | 620 | `0x03` | behavior-recovered |
| `func_8002AD70` | 652 | 632 | `0x04` | behavior-recovered |

`func_8004A36C` has the correct length and differs in only three instruction
words, all stack-address operands. Several direct local-layout expressions were
tested with the exact verifier, but none matched, so the clear behavior source
is retained. No function in this tranche is eligible for hybrid-build
substitution, and no byte match is claimed. Address-based names remain because
the wider subsystem semantics are not yet established.
