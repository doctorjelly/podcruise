# Medium pipeline tranche

Status: **5 behavior-recovered functions measured in all four builds; none is
byte-matching C**.

## Verified facts

Each USA entry is a direct `jal` target. Its return and executed delay slot were
checked in the canonical ROM.

| Function | ROM | Candidate bytes | `jr ra` / delay slot | Direct USA callers |
| --- | ---: | ---: | --- | ---: |
| `func_80005240` | `0x005E40` | 716 | `80005504` / restore the 64-byte frame | 1 |
| `func_80008C58` | `0x009858` | 720 | `80008F20` / `nop` | 1 |
| `func_80051D2C` | `0x05292C` | 712 | `80051FEC` / restore the 384-byte frame | 1 |
| `func_80088538` | `0x089138` | 664 | `800887C8` / restore the 184-byte frame | 1 |
| `func_80096BF0` | `0x0977F0` | 672 | `80096E80` / restore the 144-byte frame | 3 |

The next entries begin at `8000550C`, `80008F28`, `80051FF4`, `800887D0`, and
`80096E90`. The final `func_80096BF0` interval includes two alignment nops after
its return delay slot. The direct call instructions are `8006719C`, `80008C2C`,
`8005C3B4`, `80007508`, and `80092D18`/`80092E68`/`800930E4`, respectively.

## Behavioral specification

| Function | Independently stated behavior |
| --- | --- |
| `func_80005240` | Mark the shared range invalid when no object is supplied. Otherwise snapshot the supplied view, install two callbacks, derive a second endpoint, and order the two endpoints into per-axis lower and upper bounds. Set two shared state flags from an object query unless the global override is active, service the object, and return either an invalid marker or the shared output vectors and range value. Propagate the shared terminal state when present. |
| `func_80008C58` | Build the point's transform and reference plane, then reject points outside the outer distance or below the shell fade threshold. Optionally project the point onto the plane and derive a signed side value from a normalized offset and cross product. Scale the requested level by the distance fade and emit the effect only when that level is positive. |
| `func_80051D2C` | Advance a shared vertical phase, choose one of five pointer tables and its region-specific bound, and walk adjacent entries. Update the row by the current entry marker, format and draw visible rows with marker-dependent brightness, and notify the owner with one of two tags after the final row scrolls past the top. |
| `func_80088538` | Find the pending list node with the earliest sample position. While an event falls inside the requested window, align the position, invoke that node's step callback, advance its next position, and select the new earliest node. Then process the requested samples in driver-sized chunks, append the command prefix and driver output, advance mixer and state cursors, report the emitted command count, and finalize the mixer. |
| `func_80096BF0` | Select decimal, octal, or upper/lower hexadecimal digits; take the magnitude for signed decimal conversions; and generate a 64-bit value's digits backward into a local buffer. Send the resulting digit span to the configured sink, record its length, and update the leading-padding count from the requested width and remaining field space. |

## Calls and addressed globals

| Function | Callees | Addressed globals |
| --- | --- | --- |
| `func_80005240` | `800155EC`, `80017EDC`, `80017E88`, `800035BC`; callback addresses `800026BC`, `800020D8` | `D_8009A270`, `D_8009A274`, `D_8009A278`, `D_8009A280`, `D_800AE8B0`, `D_800AE8B8`, `D_800AE8C8`, `D_800AE8D8`, `D_800AE8E8`, `D_800AE918`, `D_800AE928`, `D_800AE934`, `D_800AE93C`, `D_800AE940` |
| `func_80008C58` | `8000B98C`, `80017AC0`, `800819A4`, `800154D0`, `80015538`, `800153C0`, `80008760` | `D_8009AD08`, `D_8009AD0C`, `D_800A81E8`, `D_800A81F0`, `D_800A81F8`, `D_800D697C` |
| `func_80051D2C` | `8008A6B4`, `8003EC40`, `80051C80` | `D_800A5344`, `D_800A53D4`, `D_800A54AC`, `D_800A55E8`, `D_800A5828`, `D_800A599C`, `D_800A59A0`, `D_800A59A4`, `D_800ACC24`, `D_800ACC30`, `D_80120BF0` |
| `func_80088538` | `80088488`; indirect node-step and driver setup/emit calls | `D_800A6990`, `D_800ADD88` |
| `func_80096BF0` | `8008AB0C`, `8008AB48`, `80097E60`, `8008C2F0` | `D_800A80C0`, `D_800A80D4` |

## Regional evidence

| USA | Japan | Europe | Compared instructions |
| --- | --- | --- | ---: |
| `80005240` | `80005240` | `80005240` | 179 |
| `80008C58` | `80008C58` | `80008C58` | 180 |
| `80051D2C` | `8005299C` | `800569DC` | 178 |
| `80088538` | `80089228` | `8008DA88` | 166 |
| `80096BF0` | `800978E0` | `8009C140` | 168 |

Every Japan and Europe entry has a unique relocation-insensitive 32-instruction
match. The complete candidate intervals have the same normalized instruction
shape, including return delay slots and padding, and LRG has the exact USA
bytes. Callee and addressed-global relocations were aligned at their
corresponding instructions. `func_80051D2C` has a real Japan-only data-layout
difference: its mode 3, 4, and 5 bounds are `0x56`, `0x89`, and `0x90`, versus
`0x4F`, `0x90`, and `0x5B` in USA and Europe. The shared C expresses those
bounds as named build constants rather than treating them as relocations.

## Compiler status

Exact IDO 5.3 `-O2 -mips2` comparisons place every function at its canonical
address. The current USA measurements are:

| Function | Target bytes | C bytes | First difference | Status |
| --- | ---: | ---: | ---: | --- |
| `func_80005240` | 716 | 716 | `0x03` | behavior-recovered |
| `func_80008C58` | 720 | 720 | `0x165` | behavior-recovered |
| `func_80051D2C` | 712 | 712 | `0x61` | behavior-recovered |
| `func_80088538` | 664 | 668 | `0x03` | behavior-recovered |
| `func_80096BF0` | 672 | 628 | `0x03` | behavior-recovered |

The formatter's target span includes eight padding bytes, but its executable C
body is still 36 bytes shorter than the original executable span. No function
in this tranche is eligible for hybrid-build substitution, and no byte match is
claimed. Address-based names remain because the wider subsystem semantics are
not yet established.
