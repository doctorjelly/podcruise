# Boundary and state tranche

Status: **23 newly measured USA functions plus regional completion for
`func_800862D8`; three functions are byte-matching C in every build**.

## Verified boundaries

The interval end is the next independently observed entry. Every return and
its executed delay slot is inside the interval. A direct-call count of zero
means no USA `jal` targets the entry; those boundaries instead have a preceding
return and/or a distinct prologue, plus complete JP/EU body evidence.

| USA entry | ROM | Bytes | `jr ra` / executed delay word | Direct USA callers |
| --- | ---: | ---: | --- | --- |
| `80008630` | `0x009230` | 100 | `8000868C` / `2C620001` | 0 |
| `80008694` | `0x009294` | 100 | `800086F0` / `2C620001` | 0 |
| `800823DC` | `0x082FDC` | 64 | `80082414` / `46107000` | 0 |
| `80089488` | `0x08A088` | 64 | `800894C0` / `nop` | 0 |
| `80012B5C` | `0x01375C` | 148 | `80012BE8` / restore 8-byte frame | 0 |
| `80062E14` | `0x063A14` | 180 | `80062EC0` / `nop` | 0 |
| `8004AE74` | `0x04BA74` | 236 | `8004AF58` / `nop` | 0 |
| `80089E50` | `0x08AA50` | 288 | `80089F68` / restore 88-byte frame | 0 |
| `8005163C` | `0x05223C` | 412 | `800517D0` / restore 80-byte frame | 2 |
| `800160BC` | `0x016CBC` | 420 | `80016258` / final matrix store | 2 |
| `8007FD98` | `0x080998` | 40 | `8007FDB8` / `nop` | 2 |
| `8002932C` | `0x029F2C` | 360 | `8002948C` / restore 80-byte frame | 1 |
| `8002FA00` | `0x030600` | 196 | `8002FABC` / restore 24-byte frame | 4 |
| `800454A8` | `0x0460A8` | 224 | `80045580` / `nop` | 1 |
| `800958D4` | `0x0964D4` | 188 | `80095988` / `nop` | 5 |
| `800862D8` | `0x086ED8` | 132 | `80086354` / `nop` | 21 |
| `8000D9A8` | `0x00E5A8` | 196 | `8000DA64` / final global store | 1 |
| `80028E78` | `0x029A78` | 556 | `8002909C` / `nop` | 1 |
| `800290A4` | `0x029CA4` | 500 | `80029290` / `nop` | 1 |
| `80029494` | `0x02A094` | 424 | `80029634` / `nop` | 1 |
| `8002DA0C` | `0x02E60C` | 196 | `8002DAC8` / `nop` | 6 |
| `80050F88` | `0x051B88` | 552 | `800511A8` / `nop` | 1 |
| `80082BE0` | `0x0837E0` | 160 | `80082C70` / `nop` | 286 |
| `8008AC78` | `0x08B878` | 96 | `8008ACD0` / `nop` | 0 |

For `func_80089488`, the words at `0x800894C8` and `0x800894CC` are
post-return alignment padding. The executed body ends with the `jr` delay slot
at `0x800894C4`; the independent next function begins at `0x800894D0`.

Seven prior source filenames began at an internal prologue rather than the real
entry. Review moved `80029330`, `8002FA0C`, `800454AC`, `8007FD9C`, and
`800958DC` to `8002932C`, `8002FA00`, `800454A8`, `8007FD98`, and `800958D4`.
The redundant `8004678C` and `800862E0` candidates were removed because the
complete functions already start at `80046764` and `800862D8`.

## Behavioral specifications

| Function | Independently stated behavior |
| --- | --- |
| `func_80008630` | Interpret requests 0, 1, and -1 as set, clear, and toggle operations on one global mode bit, then report whether that mode is clear. |
| `func_80008694` | Apply the same set/clear/toggle protocol to the adjacent global mode bit and report its cleared state. |
| `func_800823DC` | Evaluate a scalar plane-style expression from two float vectors, returning the second vector's third component plus the residual divided by the first vector's third component. |
| `func_80089488` | Add a signed delta to the word at offset 4 of each fixed-size entry, using the signed count stored in the first entry. The routine has no defined return value. |
| `func_80012B5C` | Seed nullable metric outputs with -1, locate a glyph when the font table and inclusive character range are valid, and publish its width and height. The original unconditionally reloads two stack locals at exit, so invalid glyph input leaves caller-visible indeterminate values; callers must satisfy the glyph precondition. |
| `func_80062E14` | Recognize five four-byte resource tags. Dispatch the Load and Reset tags to the resource helper and return true for every recognized tag, false otherwise. |
| `func_8004AE74` | When the object's enable bit and global thresholds permit, invoke state-transition helpers for state 8, an optional secondary flag, and an indexed owner record. |
| `func_80089E50` | Reject an inactive object, run its update helpers, scan its entry array, count entries with both required fields, and store the resulting totals. |
| `func_8005163C` | Initialize sixteen random slot records, then make bounded random placement attempts for up to seven active owners while maintaining both slot and owner-side state. |
| `func_800160BC` | Form a normalized transpose of a 3x3 basis, complete the homogeneous matrix, and derive its translated row from the input translation. |
| `func_8007FD98` | Adapt the integer-register float argument to the floating ABI register and forward all four arguments to `func_8007F914`. |
| `func_8002932C` | Initialize a zero point, configure resource modes, select one of two object indices from a flag, reconcile three resource entries with the global owner table, then clear the selection. |
| `func_8002FA00` | Initialize a subsystem when progression moves backward, copy the preceding limit entry into the new slot, notify two helpers, clear later slots, and clear the pending flag. Caller `func_80051898` forwards its own first argument unchanged in `$a0`; its C prototype and call were corrected accordingly. |
| `func_800454A8` | Starting from zero, scan a terminated entry list for its largest score, store that score and a derived ratio on the owner, then issue two reset/update calls. |
| `func_800958D4` | Read the global ring object, append the current global value when capacity remains, advance its count, and transfer a queued cell when the head has a successor. |
| `func_800862D8` | Select caller or forced viewport coordinates, write them into an indexed viewport record, then run its two refresh helpers. |
| `func_8000D9A8` | Normalize startup mode globals, query a tagged resource flag, choose the resulting mode, and publish it into the active global slot. |
| `func_80028E78` | Advance a fade-in value with frame time, drive its display alpha, and on completion perform either the selected transition sequence or the fallback cleanup sequence. |
| `func_800290A4` | Hold and then reduce a fade-out alpha with frame time; when its countdown completes, remove the display entry, reset transition globals, and report completion. |
| `func_80029494` | Query three owner resources and use their results to construct fallback vectors, copied bounds, midpoint values, and an adjusted vertical coordinate. |
| `func_8002DA0C` | Extract a two-bit lane phase, query its state helper, and report availability from the phase, slot index, and per-slot enable mask. |
| `func_80050F88` | Maintain a frame-scaled rotation, refresh cached transforms when their source vectors change, choose a new random angle during refresh, and update the rotated position. |
| `func_80082BE0` | Lazily seed a linear-congruential generator, advance its state, and return a nonnegative result with the signed minimum mapped to zero. Japan additionally clamps the 65 extreme values at each end to `0x7FFFFFBF`. |
| `func_8008AC78` | Divide one unsigned 64-bit value by a sign-extended 16-bit divisor and store both quotient and remainder; division by zero follows the original MIPS trap behavior. |

The addressed globals and direct callees in the C declarations were checked
against their instructions. Regional definitions use independently aligned
relocations; no semantic names were introduced.

## Regional evidence

| USA | Japan | Europe | Relationship |
| --- | --- | --- | --- |
| `80008630` | `80008630` | `80008630` | same complete normalized body |
| `80008694` | `80008694` | `80008694` | same complete normalized body |
| `800823DC` | `8008307C` | `800878BC` | same complete normalized body |
| `80089488` | `8008A178` | `8008E9D8` | same complete normalized body |
| `80012B5C` | `80012B68` | `80012FEC` | same complete normalized body |
| `80062E14` | `80063984` | `800682F4` | same complete normalized body |
| `8004AE74` | `8004BAB4` | `8004F994` | same complete normalized body |
| `80089E50` | `8008AB40` | `8008F3A0` | same complete normalized body |
| `8005163C` | `800522A8` | `800562E4` | same complete normalized body |
| `800160BC` | `800161EC` | `8001654C` | same complete normalized body |
| `8007FD98` | `80080A38` | `80085278` | same complete normalized body |
| `8002932C` | `80029BB4` | `8002BA08` | same complete normalized body |
| `8002FA00` | `80030460` | `80032FC0` | same complete normalized body |
| `800454A8` | `80045CB8` | `80049E48` | same complete normalized body |
| `800958D4` | `800965C4` | `8009AE24` | same complete normalized body |
| `800862D8` | `80086FCC` | `8008B7B8` | same complete normalized body |
| `8000D9A8` | `8000D9A8` | `8000DA3C` | same complete normalized body |
| `80028E78` | `80029700` | `8002B554` | same complete normalized body |
| `800290A4` | `8002992C` | `8002B780` | same complete normalized body |
| `80029494` | `80029D1C` | `8002BB70` | same complete normalized body |
| `8002DA0C` | `8002E470` | `80030FB0` | same complete normalized body |
| `80050F88` | `80051BF4` | `80055C30` | same complete normalized body |
| `80082BE0` | `80083880` | `800880C0` | Europe shares USA; Japan has the documented clamp |
| `8008AC78` | `8008B968` | `800901C8` | same complete normalized body |

LRG has the exact USA bytes for every row. “Same normalized body” is structural
and relocation evidence; it is not an exact compiler claim.

## Exact compiler comparison

IDO 5.3 `-O2 -mips2` was used except `func_8008AC78`, which requires the
neighboring unit's confirmed `-O1 -mips3 -o32` profile.

| Function | Target / C bytes | First difference | Status |
| --- | --- | --- | --- |
| `func_80008630` | 100 / 100 | `0x4` | behavior-recovered |
| `func_80008694` | 100 / 100 | `0x4` | behavior-recovered |
| `func_800823DC` | 64 / 64 | `0xD` | behavior-recovered |
| `func_80089488` | 64 / 64 | none | **byte-matching C: USA/JP/EU/LRG** |
| `func_80012B5C` | 148 / 148 | `0x4E` USA/EU; `0x2B` JP | behavior-recovered |
| `func_80062E14` | 180 / 180 | none (USA) | **byte-matching C: USA** |
| `func_8004AE74` | 236 / 236 | none | **byte-matching C: USA/JP/EU/LRG** |
| `func_80089E50` | 288 / 288 | none (USA) | **byte-matching C: USA** |
| `func_8005163C` | 412 / 404 | `0x18` | behavior-recovered |
| `func_800160BC` | 420 / 420 | `0x3B` | behavior-recovered |
| `func_8007FD98` | 40 / 40 | none | **byte-matching C: USA/JP/EU/LRG** |
| `func_8002932C` | 360 / 360 | none | **byte-matching C: USA** |
| `func_8002FA00` | 196 / 188 | `0x1` | behavior-recovered |
| `func_800454A8` | 224 / 224 | `0x26` | behavior-recovered |
| `func_800958D4` | 188 / 188 | `0x19` | behavior-recovered |
| `func_800862D8` | 132 / 132 | `0x50` | behavior-recovered |
| `func_8000D9A8` | 196 / 180 | `0x1` | behavior-recovered |
| `func_80028E78` | 556 / 560 | `0x1` | behavior-recovered |
| `func_800290A4` | 500 / 516 | `0x1` | behavior-recovered |
| `func_80029494` | 424 / 424 | `0x166` | behavior-recovered |
| `func_8002DA0C` | 196 / 196 | `0xA` | behavior-recovered |
| `func_80050F88` | 552 / 556 | `0x3B` | behavior-recovered |
| `func_80082BE0` | 160 / 152 USA/EU; 224 / 208 JP | `0x13` USA/EU; `0x3` JP | behavior-recovered |
| `func_8008AC78` | 96 / 88 | `0x14` | behavior-recovered |

For `func_80029494`, retaining `100.0f` in a named local restores four
canonical stack-spill words, but nine instruction words still differ from USA;
the byte-match claim therefore remains explicitly withheld.

For `func_80050F88`, the baseline already reproduces the ROM's 56-byte frame
and every local stack offset. Direct-global and separate-angle forms remove the
premature angle spill but disturb that proven layout or leave the function one
instruction short. Assignment-expression variants also remained nonmatching,
so the compact behavior-recovered source is retained.

For `func_80062E14`, the source retains the original's two redundant tests of
`D_800A4BE0` and routes every recognized tag through one shared true-result
tail. IDO 5.3 `-O2` then reproduces all 180 USA bytes, including both
branch-likely delay slots and the final return delay-slot `nop`.

For `func_8002932C`, retaining a behavior-neutral address expression after the
corresponding indexed global dereference reproduces the ROM's saved-register
allocation. Exact IDO 5.3 `-O2` comparison confirms all 360 USA bytes; no
regional compiler-match claim is made.

Only the build-specific bold claims are eligible for C substitution in the
corresponding hybrid build.
