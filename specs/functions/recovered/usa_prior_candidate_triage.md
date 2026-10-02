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
