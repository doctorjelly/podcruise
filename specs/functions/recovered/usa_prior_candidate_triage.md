# Prior USA source-shape triage: unchanged candidates

These 22 C units are still assembly-backed in USA. Astra identified them as
previously audited rather than fresh work; no source experiment was repeated
in this tranche. Their source files have no tracked changes from `074d9f7`
through `aa97eca` and no current worktree edits. This is a historical
classification, not a new exact comparison or claim that compiler blockers
are permanent. Reopen a candidate only with new ROM or source evidence.

| Function | Prior finding |
| --- | --- |
| `func_80005240` | Frame and scheduling differences; no bounded lever. |
| `func_80053C08` | Typed-owner alias and declaration variants exhausted. |
| `func_80091630` | Broad allocation differences. |
| `func_80044A7C` | Broad allocation differences. |
| `func_80027A0C` | Broad allocation differences. |
| `func_800316A8` | Control/register differences without a source distinction. |
| `func_800175E0` | FP spills and allocation account for the shape gap. |
| `func_8002AD70` | Global-address reuse and allocation differences. |
| `func_80096BF0` | Earlier six-candidate tranche found no bounded lever. |
| `func_8005065C` | Two earlier tranches found no retained lever. |
| `func_80038950` | Boundary and calls revalidated; no supported omitted operation. |
| `func_8002963C` | Earlier six-candidate tranche found no bounded lever. |
| `func_80010B34` | Conditional-argument experiment was byte-neutral. |
| `func_80081FB0` | Two earlier tranches found no retained lever. |
| `func_80084EB8` | Earlier triage found no retained lever. |
| `func_80036314` | Repeated audits found no new semantic distinction. |
| `func_80028498` | Earlier eight-function tranche found no localized lever. |
| `func_80004160` | Boundary and calls validated; no justified layout change. |
| `func_8001C404` | Multiple tranches found no new semantic distinction. |
| `func_8004F358` | Focused wrong-size audit found no retained correction. |
| `func_8008E54C` | Earlier eight-function tranche found no localized lever. |
| `func_8000F0DC` | Earlier wrong-size tranche found no bounded hypothesis. |

## Bounded follow-up after e2724c4

The following isolated USA audits retained no source changes. Sizes are C/ROM;
word differences compare aligned instructions in the overlapping span.

| Function | Verified baseline and rejected variants |
| --- | --- |
| `func_80006C00` | 324/348 bytes, 75 words differ. Direct switch expression with type reread: 328 bytes/79 words; separate 11/12 cases: 308/66; volatile count: unchanged. ROM repeats global-count address/load work that C shares. No omitted handler or count-refresh behavior established. |
| `func_800125E4` | 948/980 bytes, 229 words differ. Consistent local alias and removal of `register`: unchanged; mode switch: 944/232. ROM's frame/save/index-home overhead remains unexplained; fabricated volatile or address-taking semantics were not retained. |
| `func_80027D24` | 836/844 bytes, 92 words differ. Pointer alias for the four cap-sufficient writes compiled identically. Two prior low-worker attempts also found no match; no register-only retry retained. |

## Follow-up after 73ecea8

| Function | Verified baseline and rejected variants |
| --- | --- |
| `func_80021F84` | 2068/2068 bytes, 16 words differ. Replacing the flag increment with constant assignments regressed to 180 words; swapping `kind`/`value` declarations stayed at 16. The two final stack accesses use +0x28 instead of +0x2C. |
| `func_80073CD0` | 1956/1956 bytes, 38 words differ. Removing `pi` or scalarizing the two index halfwords grew to 1976 bytes; splitting chained band updates shrank to 1948 with broad differences. All restored. |
| `func_8000F5A0` | 1224/1164 bytes, 287 words differ. Pointer/byte-offset loop: 1220/289; positive in-bounds predicate: 1208/288; signed-halfword height: unchanged. None retained. |
| `func_80088BFC` | 1352/1352 bytes, 20 words differ. Two are calls to its exact private helper at +0x10 from canonical, because the source omits intervening empty functions `80088BEC`/`80088BF4`. Adding those functions before the driver places them after it under O3 (driver at -0x10, 18 word differences); adding them after the driver places them before the helper (canonical driver but same 20 differences). The helper must stay at 80088B70, empty functions at 80088BEC/80088BF4, driver at 80088BFC. Assigning both clamped durations inside call arguments regressed to 82 differences. All experiments stayed in /tmp; no configuration retained. |

The subsequent behavioral review of `func_8001A408` found no omitted effect in
the timer nesting (8001A590–8001A688), startup list (8001A478–8001A560), confirm
writes (8001AB04–8001AC14), selection wrapping (8001AC6C–8001AD74), or final
chord (8001AD78–8001ADB8). Timer 2 starts only after timer 1 reaches zero;
timer 3 starts at timer 2 <= 0.5. Both vertical directions can apply in
sequence, and the two controller words are tested separately.

A prelude audit of `func_80079824` also retained no correction (4688/5320
bytes, 1123 differing words, 158 missing). The ROM's controller-axis
computations at 800798BC–80079928 write stack slots that 8007994C–800799D8
subsequently overwrite with object steering before a helper consumes them.
The C contains that dead computation; its elimination does not establish a
missing observable update. The early branch delay slots carry loads/arithmetic,
not an omitted field store. Further work needs source-shape evidence rather
than another speculative behavior fix to this prelude.

The `func_8001DDA8` behavioral audit reproduced 2220/2328 bytes, 551 differing
words, 27 missing. It confirmed the normalization call at 8001DE24, yaw
wrap by 360, pitch adjustments +90/-180, movement deadzones +/-0.1,
70*dt*axis*-1.5 and 45*dt*axis*1.5 factors, +/-45 clamps, and menu cases
6/7 writing fields 0x6F/0x10. No additional semantic correction was found.
