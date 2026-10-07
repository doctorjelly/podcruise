# Medium control and math tranche

Status: **10 measured USA functions; five are byte-matching C for USA and LRG,
and three of those are also verified in Japan and Europe**.

## Verified facts

The interval end is the next independently observed entry. Direct caller
counts come from decoded USA `jal` targets. A zero count means the entry is
reached indirectly; those boundaries have a distinct prologue or preceding
return and an identical full normalized body in Japan and Europe.

| USA entry | ROM | Bytes | Return / executed delay slot | Direct callers |
| --- | ---: | ---: | --- | ---: |
| `80045F60` | `0x046B60` | 444 | `80046114` / restore 120-byte frame | 1 |
| `80033328` | `0x033F28` | 460 | `800334EC` / `nop` | 2 |
| `8008A420` | `0x08B020` | 472 | `8008A5F0` / restore 368-byte frame | 0 |
| `80014D4C` | `0x01594C` | 480 | `80014F24` / restore 8-byte frame | 12 |
| `80089F70` | `0x08AB70` | 468 | `8008A13C` / restore 352-byte frame | 0 |
| `80014F54` | `0x015B54` | 504 | `80015144` / move result into `$f0` | 36 |
| `8003594C` | `0x03654C` | 676 | `80035BE8` / restore 88-byte frame | 2 |
| `8008528C` | `0x085E8C` | 1,316 | `800857A8` / `nop` | 1 |
| `800321F0` | `0x032DF0` | 3,388 | seven audited returns; see below | 1 |
| `80044CD8` | `0x0458D8` | 812 | `80044FFC` / restore 304-byte frame | 1 |

`func_80089F70` ends at its return delay slot at `0x8008A140`; the three
`nop`s through `0x8008A14F` are alignment padding before `func_8008A150`, not
part of the function body.

`func_800321F0` is one switch routine, not three functions. Its returns and
executed delay slots are `800323C8` / store field `0x00`, `80032590` / store
field `0x04`, `800327B8` / store field `0x0C`, `80032980` / store field
`0x10`, `80032B98` / store field `0x14`, `80032D60` / store field `0x24`, and
`80032F24` / `nop`. The previously authored `func_80032BA0.c` and
`func_80032D68.c` represented internal case tails and were removed.

The addressed dependencies in the C were checked against the complete USA
intervals:

| Function | Direct callees | Addressed globals |
| --- | --- | --- |
| `func_80045F60` | `80083134` | none |
| `func_80033328` | none | `D_80120BF0` |
| `func_8008A420` | `8008A5F8`, `80091354`, `80091FD0`, `80092050`, `800926A0`, `80092850`, `800928F0` | none |
| `func_80014D4C` | none | coefficient block `D_800A8790`–`D_800A87B8` |
| `func_80089F70` | `80091280`, `80091354`, `80091FD0`, `80092050`, `80092250` | none |
| `func_80014F54` | none | coefficient block `D_800A87C0`–`D_800A87EC` |
| `func_8003594C` | none | `D_800A3D9C`, `D_800A3DA0`, `D_800A3DA4`, `D_800A3DA8`, `D_800A4740`, `D_800D697C` |
| `func_8008528C` | `800390AC`, `80088360` | `D_800A4740`, `D_800D9DB4`, `D_80114470`, `D_80114528`, `D_80120DF0`, `D_801217B0` |
| `func_800321F0` | none | jump table `800AA3AC` and coefficient block `D_800AA3C8`–`D_800AA464` |
| `func_80044CD8` | `80015268`, `80015288`, `8001535C`, `800154D0`, `80015538`, `80017580`, `80017918`, `80017BA8`, `80083190` | `D_800AAD0C` |

## Behavioral specifications

| Function | Independently stated behavior |
| --- | --- |
| `func_80045F60` | For each of six lanes, ask one helper to populate nine fixed destination blocks from a prescribed set of source pointers, using the object's common identifier and a count of twelve. |
| `func_80033328` | Move a scalar toward a requested target at a frame-scaled rate, increase the rate when crossing zero, prevent motion against a requested bias, integrate the result into an angle, and wrap that angle to the signed 180-degree range. |
| `func_8008A420` | Validate an insertion request, prepare and locate its encoded entry, walk link tables until a free terminator is found or an error occurs, mark the entry, and write it back while preserving the helper error codes. |
| `func_80014D4C` | Return signed endpoint angles for out-of-range input; otherwise evaluate a polynomial inverse-sine approximation in degrees, using a square-root complement for the outer part of the domain. |
| `func_80089F70` | Validate an active indexed entry, load its encoded link chain, count chain elements while refreshing per-page link data, copy its metadata into the output, and return the original error codes for invalid or unterminated chains. |
| `func_80014F54` | Compute a signed heading in degrees from two components by applying an odd polynomial to the smaller-to-larger absolute ratio, then reflect and negate it for the correct quadrant. |
| `func_8003594C` | Normalize two groups of material mode bytes when rendering features are unavailable, clear selected packed-word flags under global overrides, and optionally replace packed words and color bytes from forced global settings. |
| `func_8008528C` | Scale a viewport rectangle, emit display-list commands for optional auxiliary clearing and depth-buffer selection, fill either half with converted RGB5551 colors when requested, restore the render mode, and run the completion helper. |
| `func_800321F0` | Select one of seven float controls and apply a channel-specific, frame-scaled additive or multiplicative adjustment, clamping the chosen field to its own legal range. |
| `func_80044CD8` | For each enabled pair of joint endpoints, read their transforms, form an oriented frame spanning the endpoints, scale it by the measured length and global width, and store it in the corresponding paired output. |

## Regional evidence

Every complete interval below has the same normalized instruction shape in
USA, Japan, and Europe, including all branches and return delay slots. LRG has
the exact USA bytes.

| USA | Japan | Europe |
| --- | --- | --- |
| `80045F60` | `80046770` | `8004A900` |
| `80033328` | `80033D88` | `800368E8` |
| `8008A420` | `8008B110` | `8008F970` |
| `80014D4C` | `80014E7C` | `800151DC` |
| `80089F70` | `8008AC60` | `8008F4C0` |
| `80014F54` | `80015084` | `800153E4` |
| `8003594C` | `800363AC` | `8003A2BC` |
| `8008528C` | `80085F80` | `8008A76C` |
| `800321F0` | `80032C50` | `800357B0` |
| `80044CD8` | `800454E8` | `80049678` |

This is structural and relocation evidence, not a byte-match claim.

## Exact compiler comparison

The accepted comparison is IDO 5.3 with the repository's `ido53_o2` profile.
The target and C sizes below are the USA results; Japan and Europe produce the
same outcomes at their relocated addresses.

| Function | Target / C bytes | First difference | Status |
| --- | --- | --- | --- |
| `func_80045F60` | 444 / 444 | none | **byte-matching C: USA/JP/EU/LRG** |
| `func_80033328` | 460 / 460 | none | **byte-matching C: USA/JP/EU/LRG** |
| `func_8008A420` | 472 / 472 | none | **byte-matching C: USA/LRG** |
| `func_80014D4C` | 480 / 480 | none | **byte-matching C: USA/JP/EU/LRG** |
| `func_80089F70` | 468 / 468 | `0x26` | behavior-recovered |
| `func_80014F54` | 504 / 504 | none | **byte-matching C: USA** |
| `func_8003594C` | 676 / 676 | none | **byte-matching C: USA/LRG** |
| `func_8008528C` | 1,316 / 1,312 | `0x1` | behavior-recovered |
| `func_800321F0` | 3,388 / 3,356 | `0x0` | behavior-recovered |
| `func_80044CD8` | 812 / 812 | `0x5` | behavior-recovered |

The four earlier bold rows retain their recorded USA and LRG substitution
eligibility. The new `14F54` result is USA-only; no foreign-region match is
claimed.
The three rows explicitly marked USA/JP/EU/LRG are also verified for the Japan and
Europe hybrid builds; no Japan or Europe byte match is claimed here for
`func_8003594C`.

### US33 exact USA heading leaf

`func_80014F54` now expresses its eleven recovered constants as typed literals.
The accepted IDO53-O2 actual function is exactly 504 bytes at `0x80014F54`,
SHA256 `1b066b9a7b6e17e7c4b5388113e4fd4389a413b6f2c71c953339c2037ff78a90`.
All 48 literal-pool bytes at `0x800A87C0` match raw USA ROM: ten `f32`
values and one `f64`, with no alignment gap or padding. SHA256
`801e4166d7d3ea599175beef102633a8579090db7a6f52334821ce2d10e91273`.
The function remains a leaf with the same signed heading/quadrant behavior;
this is typed literal recovery, not a new runtime behavior claim.
Source SHA256:
`15255caba9bf054d5be016ae735b5eff7eb2d05fe186574548c1ba56ad3b45bb`.
USA C promotion begins ROM `0x15B54` and ends exactly at `0x15D4C`, where the
already configured C unit `func_8001514C` begins. No extra ASM resume or
adjacent promotion is needed. Only this unit's eleven obsolete absolute
aliases were removed; its rodata anchor is `0x800A87C0`, alignment 16.
The approved source's historical scratchpad comment names a nonretained path;
this existing tranche specification is the durable source specification.
Private exact/independent evidence: `/tmp/us33-14f54-literals/` and the
coordinator/root audits.

Full integration validation passes. The successful authoritative ledger is
`/tmp/us33-14f54-validation/ledger-fixed-schema.log` (exit zero), with all
1,348 source hashes and configuration current; exact coverage is 1,184
functions / 363,724 bytes, with 164 nonmatches. The initial missing required
empty `absolute_symbols` dictionary failure remains preserved as setup
evidence in `ledger.failed-schema.log`; it was fixed without source changes.
After `split-us` refresh, `roundtrip-fixed.log` and its canonical rebuild
report verify 1,184 substitutions and byte-identical USA ROM SHA1
`3542d5597c8a56ea8f5c63bceae97a24c4c08d58`. The stale-map first run is not
validation evidence. The actual C object/map places the 504-byte text at
`0x80014F54` through the next `0x8001514C` boundary. The hybrid packer
substitutes C text only: it retains the existing ROM pool bytes. The isolated
compiler's 48-byte pool is independently exact, rather than owned by a hybrid
C rodata object. All 32 tests, safety, strict manifest, USA-only inventory and
diff check pass; full logs are under `/tmp/us33-14f54-validation/`.
