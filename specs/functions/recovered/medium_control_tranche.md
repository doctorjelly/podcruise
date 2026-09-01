# Medium control tranche

Status: **3 byte-matching and 7 behavior-recovered functions in canonical
USA**.

## Verified facts

Each USA entry is a direct `jal` target with a conventional prologue. Its
preceding function has a complete return, and the next accepted entry starts
immediately after the return delay slot shown here.

| Function | ROM | Bytes | `jr ra` / delay slot | Direct USA callers |
| --- | ---: | ---: | --- | ---: |
| `func_8002E2FC` | `0x02EEFC` | 440 | `8002E4AC` / restore the 80-byte frame | 7 |
| `func_80039B70` | `0x03A770` | 360 | `80039CD0` / restore the 48-byte frame | 6 |
| `func_8005F33C` | `0x05FF3C` | 412 | `8005F4D0` / restore the 120-byte frame | 1 |
| `func_80062EC8` | `0x063AC8` | 444 | `8006307C` / restore the 48-byte frame | 1 |
| `func_8006E034` | `0x06EC34` | 408 | `8006E1C4` / `nop` | 2 |
| `func_8006FB00` | `0x070700` | 384 | `8006FC78` / `nop` | 1 |
| `func_800801B8` | `0x080DB8` | 408 | `80080348` / restore the 568-byte frame | 1 |
| `func_80089870` | `0x08A470` | 368 | `800899D8` / `nop` | 1 |
| `func_800910D4` | `0x091CD4` | 428 | `80091278` / restore the 112-byte frame | 2 |
| `func_80091E34` | `0x092A34` | 412 | `80091FC8` / restore the 56-byte frame | 1 |

## Behavioral specification

| Function | Independently stated behavior |
| --- | --- |
| `func_8002E2FC` | Drain a fixed message queue without blocking. Messages 1 and 4 select one of several global-state transitions and schedule a corresponding numeric action; message 2 runs a reset-like helper and schedules action 2000. Other messages are ignored. |
| `func_80039B70` | Run two setup helpers, then visit each pointer in a fixed buffer table. For every buffer, call the range helper on a region whose guard, stride, pixel size, and total length depend on whether installed memory is at least eight MiB. |
| `func_8005F33C` | Copy ten global band widths, obtain a mover basis, and move its position 100 units opposite one basis vector. Locate a scalar position within the width bands, then rotate the result by a band-dependent angle and a centered within-band angle. |
| `func_80062EC8` | If the object exists, clear one flag and initialize its identifiers, vectors, timers, sentinels, scales, and limits. Two duration-like fields receive independent pseudo-random values in the ranges implied by `3 + random * 5` and `3 + random * 2`. |
| `func_8006E034` | When two state flags and an owned pointer are all clear, submit two randomized effects, set a fifteen-unit timer, copy a position into temporary storage, allocate a child object, and register the address of the owning pointer with that child. |
| `func_8006FB00` | Reset two output values, dispatch state-specific update helpers from flag fields, optionally apply another common update, scale one output, suppress another while a timer is positive, and clamp the scaled output to a symmetric limit. |
| `func_800801B8` | Reject a null or oversized graph after resetting the status global. Visit every graph node, initializing empty nodes under one of two status policies, build a temporary result array, run the primary graph traversal callback, and optionally run a second callback pass when a global mode is enabled. |
| `func_80089870` | Refuse startup while the shared busy flag is set. Otherwise mark it busy, wait out a fixed startup deadline through a temporary queue and timer, perform two device operations separated by blocking receives, run the remaining initialization helpers, clear the state byte, create a final queue, and return the second device result. |
| `func_800910D4` | Optionally reset a device, fetch and validate a primary descriptor, substitute a secondary descriptor when required, reject a descriptor that still lacks the required flag, copy the chosen descriptor into the device, derive several sizes from one descriptor byte, and fetch a final mode-7 block. Return the first error code encountered. |
| `func_80091E34` | Derive a mask slot from a two-byte key, scan the object's selectable entries, load an entry when its index changes, and count occurrences of the key in each eligible halfword table. Stop and return 2 after the second occurrence; otherwise return the final count or a loader error. |

## Calls and addressed globals

| Function | Callees | Addressed globals |
| --- | --- | --- |
| `func_8002E2FC` | `8002DFB0`, `8002E028`, `8002E0A8`, `80087E80`, `8008ADB0` | `D_800A2670` through `D_800A2688`, `D_800D7420`, `D_801488C0` |
| `func_80039B70` | `80007A44`, `8003140C`, `80039A30` | `D_80000318`, `D_80114530`, `D_8011453C` |
| `func_8005F33C` | `800155EC`, `8003B184` | `D_800A5A04` |
| `func_80062EC8` | `80015268`, `80082BE0` | none |
| `func_8006E034` | `80008BC4`, `80015288`, `80065810`, `80065CB0`, `80082BE0` | `D_800AD708`, `D_800AD710`, `D_800AD718`, `D_800AD720` |
| `func_8006FB00` | `8006CA2C`, `8006D7F0`, `8006E1CC`, `8006E6F8`, `8006FA08` | none |
| `func_800801B8` | `80008F28`, `8007F098`, `8007F430`, `8007F560`, `8007FDC0`, `80080148` | `D_800A6704`, `D_8011DCB0` |
| `func_80089870` | `80087E80`, `800880E0`, `800899E0`, `80089AB0`, `800905A0`, `80090660`, `800906F0`, `800907D0` | `D_800A69B0`, `D_80149C70`, `D_80149CB0`, `D_80149CB1`, `D_80149CD8`, `D_80149CF0` |
| `func_800910D4` | `80090B24`, `80090C20`, `80090F70`, `80091FD0`, `80092050`, `80092250` | none |
| `func_80091E34` | `80091354` | none |

## Regional evidence

| USA | Japan | Europe |
| --- | --- | --- |
| `8002E2FC` | `8002ED5C` | `8003189C` |
| `80039B70` | `8003A520` | `8003E440` |
| `8005F33C` | `8005FEA4` | `80064820` |
| `80062EC8` | `80063A38` | `800683A8` |
| `8006E034` | `8006EBA4` | `80073514` |
| `8006FB00` | `80070670` | `80074FE0` |
| `800801B8` | `80080E58` | `80085698` |
| `80089870` | `8008A560` | `8008EDC0` |
| `800910D4` | `80091DC4` | `80096624` |
| `80091E34` | `80092B24` | `80097384` |

All twenty regional entries are unique 32-instruction matches. The complete
Japan and Europe bodies also have the same normalized instruction sequence and
instruction count as USA. LRG has the exact USA bytes.

## Compiler status

IDO 5.3 under `ido53_o2` places every C function at its canonical USA address.
Exact comparison against the canonical USA ROM reports:

| Function | Target bytes | C bytes | First difference | Status |
| --- | ---: | ---: | ---: | --- |
| `func_8002E2FC` | 440 | 456 | `0x05` | behavior-recovered |
| `func_80039B70` | 360 | 356 | `0x35` | behavior-recovered |
| `func_8005F33C` | 412 | 424 | `0x09` | behavior-recovered |
| `func_80062EC8` | 444 | 444 | none | **byte-matching** |
| `func_8006E034` | 408 | 408 | none | byte-matching |
| `func_8006FB00` | 384 | 388 | `0x5F` | behavior-recovered |
| `func_800801B8` | 408 | 408 | `0x0C` | behavior-recovered |
| `func_80089870` | 368 | 364 | `0x00` | behavior-recovered |
| `func_800910D4` | 428 | 428 | `0x81` | behavior-recovered |
| `func_80091E34` | 412 | 412 | none | byte-matching |

IDO 5.3 under `ido53_o2` reproduces all bytes of `func_8006E034` and
`func_80091E34` exactly in USA retail, the USA LRG revision, Japan, and Europe.
`func_80062EC8` is now exact in canonical USA after expressing two initialization
groups in their evidenced order around the random helper calls. No regional
compiler-match claim is added for it. The other seven units remain assembly in
the USA hybrid rebuild and no byte match is claimed for them. Address-based
names remain until subsystem semantics are proven.
