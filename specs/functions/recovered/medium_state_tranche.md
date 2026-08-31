# Medium state tranche

Status: **5 behavior-recovered functions measured in all four builds;
`func_80041D14` is byte-matching C for USA and LRG**.

## Verified facts

Each USA entry is a direct `jal` target with a conventional non-leaf prologue.
The return instruction and its executed delay slot were checked directly in
the canonical ROM.

| Function | ROM | Bytes | `jr ra` / delay slot | Direct USA callers |
| --- | ---: | ---: | --- | ---: |
| `func_80092050` | `0x092C50` | 512 | `80092244` / restore the 56-byte frame | 19 |
| `func_800509E8` | `0x0515E8` | 536 | `80050BF8` / `nop` | 1 |
| `func_80041D14` | `0x042914` | 556 | `80041F38` / restore the 160-byte frame | 1 |
| `func_800511B0` | `0x051DB0` | 560 | `800513D8` / restore the 64-byte frame | 3 |
| `func_80042970` | `0x043570` | 584 | `80042BB0` / `nop` | 1 |

`func_80092050` has one alignment `nop` after its return delay slot and before
the next entry at `80092250`. The other four entries end at their return delay
slot. The USA callers are `80089EFC`, `8008A028`, `8008A4CC`, `8008B494`,
`8008B500`, `80090CDC`, `80090D44`, `80090DB4`, `80090EB8`, `80091000`,
`80091118`, `80091250`, `800912DC`, `80091304`, `800914CC`, `80091558`,
`800916D8`, `800918E4`, and `80092740` for `func_80092050`; `8004AD9C` for
`func_800509E8`; `80043784` for `func_80041D14`; `8001F69C`, `80024424`, and
`80024498` for `func_800511B0`; and `800437A4` for `func_80042970`.

## Behavioral specification

| Function | Independently stated behavior |
| --- | --- |
| `func_80092050` | Acquire the shared device buffer, initialize it when its mode or channel changed, encode the requested selector, and submit the request. Repeatedly receive a reply, decode its status, validate the 32-byte payload checksum, and either copy the payload or invoke recovery. Retry recoverable checksum failures, release the device, and return the final status. |
| `func_800509E8` | Refresh a tracked endpoint when it changed and cap another endpoint to 500 units from its base. Run two state-update queries. When both succeed, publish the active flags, conditionally toggle a latch, copy two transform matrices, and invoke the final update helper when the global mode and latch conditions allow it. |
| `func_80041D14` | Return when the rider has no craft. Otherwise copy the craft transform, apply height and type-dependent offsets, optionally rotate it from the craft angles, and publish two rider transforms. Set the rider distance by type; a craft flag selects mirrored basis vectors and the opposite final offset. |
| `func_800511B0` | In update mode, extrapolate one shared position, blend the other position one-third toward it, and for owner kind 1 reset the positions while randomizing two accumulated angles and a duration before advancing the endpoint. In load mode, copy both positions from the owner's 32-byte table entry. Mark both shared state flags active. |
| `func_80042970` | Resolve a missing source once and return. Otherwise copy the source transform and nodes, derive a short probe transform, and project the source position onto the probe direction. Use the bounded projection to lower one node, rebuild the frame, apply fixed X and Z offsets, publish the view and result transforms, and reset the timer to 60. |

## Calls and addressed globals

| Function | Callees | Addressed globals |
| --- | --- | --- |
| `func_80092050` | `80087E80`, `800905F0`, `80090634`, `800907D0`, `80090880`, `80092250`, `80093A90`, `80093B60` | `D_800A7EE0`, `D_80149CB0`, `D_8014D720` |
| `func_800509E8` | `80015288`, `800152CC`, `8001535C`, `800153C0`, `800154D0`, `800155EC`, `800156DC`, `800469B4`, `80050C00` | `D_800A2198`, `D_800A219C`, `D_800A4BC0`, `D_800A4BC4`, `D_800A4BD0`, `D_800A4BDC`, `D_800A4BF8`, `D_800A5260`, `D_800A5264`, `D_800A5268`, `D_80118D60`, `D_80118D90`, `D_80118DA0`, `D_80118DD0`, `D_80118E10`, `D_80118E20`, `D_80118E50`, `D_80118E60`, `D_80118E90`, `D_80118ED0` |
| `func_80041D14` | `800155C0`, `800155EC`, `800156DC`, `80016F0C`, `80017824` | `D_800AAC5C`, `D_800AAC60` |
| `func_800511B0` | `80015288`, `80015328`, `8001535C`, `800155EC`, `80015630`, `80051934`, `80082BE0` | `D_800A2198`, `D_800A4BC0`, `D_800A4BD0`, `D_800A4C00`, `D_800A5148`, `D_800AB364`, `D_80118DE0`, `D_80118E10`, `D_80118E18`, `D_80118ED0` |
| `func_80042970` | `800156DC`, `8003B02C`, `8003B184`, `8003F714` | `D_800AAC98`, `D_800AACA0` |

## Regional evidence

| USA | Japan | Europe | Compared instructions |
| --- | --- | --- | ---: |
| `80092050` | `80092D40` | `800975A0` | 128 |
| `800509E8` | `80051654` | `80055690` | 134 |
| `80041D14` | `8004251C` | `800466B4` | 139 |
| `800511B0` | `80051E1C` | `80055E58` | 140 |
| `80042970` | `80043178` | `80047310` | 146 |

All ten regional entries have unique relocation-insensitive 32-instruction
matches. Comparing the complete configured span shows the same normalized
instruction sequence and instruction count as USA. The LRG build has the exact
USA bytes. Callee and addressed-global relocations were aligned instruction by
instruction before configuring the regional compiler checks.

## Compiler status

Exact IDO 5.3 `-O2 -mips2` comparisons place every function at its canonical
address. The table reports canonical USA results:

| Function | Target bytes | C bytes | First difference | Status |
| --- | ---: | ---: | ---: | --- |
| `func_80092050` | 512 | 508 | `0xB3` | behavior-recovered |
| `func_800509E8` | 536 | 536 | `0x1C5` | behavior-recovered |
| `func_80041D14` | 556 | 556 | none | **byte-matching** |
| `func_800511B0` | 560 | 556 | `0x03` | behavior-recovered |
| `func_80042970` | 584 | 588 | `0x33` | behavior-recovered |

The table-stride audit corrected `func_800511B0` from a 44-byte entry model to
the 32-byte stride used by the original shifts. `func_80041D14` is eligible for
USA and LRG hybrid-build substitution only after an exact linked-object
comparison; the other four functions remain behavior-recovered and no byte
match is claimed for them.
Address-based names remain because the subsystem semantics are not yet proven.
