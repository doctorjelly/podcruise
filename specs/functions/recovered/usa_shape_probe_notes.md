# USA source-shape probe notes

These candidates remain behavior-recovered C with USA assembly splits. The
measurements below are from the isolated, linked IDO 5.3 verifier; no exact
match or C substitution is claimed.

| Function | ROM/C bytes | Baseline differing words | Bounded result |
| --- | ---: | ---: | --- |
| `func_80053C08` | 1088/1088 | 99 | Explicit typed owner alias reduced differences to 89; declaration-order variants remained nonexact. Source restored. |
| `func_8002D048` | 1148/1128 | 248, plus 5 missing | Replacing the default switch `break` with an explicit outgoing `goto` compiled identically. Source restored. |
| `func_8008E074` | 940/920 | 229, plus 5 missing | Advancing the command pointer after each of the first two packets compiled identically. Source restored. |
| `func_800125E4` | 980/948 | 229, plus 8 missing | No source experiment: a forced volatile or address-taken index lacks ROM evidence. |
| `func_8000F5A0` | 1164/1224 | 287, plus 15 extra | Scalar framebuffer-end pointer worsened the C body to 1268 bytes (26 extra words); source shape restored. |

In `func_8002D048`, the ROM's default unsigned-float conversion has three
distinct exits to `0x8002D2C4`; IDO merges them in the current C at
`0x8002D100`. The `goto` did not recover any exit. Do not retry the same-edge
spelling without new control-flow evidence.

For `func_800125E4`, the ROM's eight-byte frame saves `$s0` at `sp+4` and
homes incoming `$a1` at `sp+0xC`, outside the allocated frame. Its three
reloads occur on mutually exclusive paths; nothing takes the index's address
or passes a stack pointer onward. Those accesses do not justify volatile
semantics or a fabricated local array.

In `func_8000F5A0`, the ROM computes the framebuffer end into `$t1` at
`0x8000F608` and compares against it in the sampling loop. The `sp+0x2C`
slot instead holds height, reloaded at `0x8000F658`. The existing C's
single-element end array is only a nonmatching source-shape attempt, not a
recovered original stack layout. Its misleading comment was removed; a
behavior-equivalent scalar-end test was reverted after the isolated verifier
showed a larger mismatch.

A same-source regional comparison found no currently nonmatching USA unit
that is exact in Japan or Europe. A programmatic scan of the first 25 ranked
USA candidates found no predominantly stack-offset-only equal-size miss
(highest was 7 such words among 77 differences), so a broad declaration-order
sweep has no current evidence basis.
