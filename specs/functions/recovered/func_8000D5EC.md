# func_8000D5EC

## Boundary and evidence

USA is VRAM `0x8000D5EC`, ROM `0x00E1EC`, 496 bytes, ending immediately before
`func_8000D7DC`. The return at `0x8000D7D4` has a `nop` delay slot. Its direct
caller is `func_8000D90C`; it calls only `func_8000C724` and `func_8000C6C8`.
Japan is unchanged at `0x8000D5EC`; Europe relocates to `0x8000D680` / ROM
`0x00E280`.

## Behavior

Dispatch selectors zero through eight. Selector zero adjusts a bounded integer
setting. Selectors two through five adjust four bounded float settings when
their feature bit is enabled. Selectors one and six toggle two global switches
under separate gates. Selector seven toggles bit `0x4000` in a shared record;
selector eight and out-of-range values do nothing. Case seven reads the shared
word once, retains that value through the bit test, and writes its masked or set result. No call or intervening write
requires refreshing the field. This follows the raw ROM single-read lifetime;
it does not establish a runtime defect in the earlier source.

## Status

**Behavior recovered only, not byte-matching.** The retained cached-field
source compiles under IDO 5.3 `-O2 -mips2` to a 504-byte function symbol
versus the canonical 496 bytes: 70 differing overlapping words and two extra
words. Both frames are `0x20`, and all five ordered direct calls match.
The linked symbol ends at `0x8000D7E4`; its 512-byte `.text` section includes
eight trailing padding bytes excluded from comparison.

The prior pointer/direct-global toggle audits produced 512/496 bytes with
71 and 68 differing words respectively. The later reviewed pool-anchor
correction established the accepted baseline at 512/496 with 69 differing
words. The new single-read field cache removes eight bytes from case seven
(76 to 68 bytes, versus ROM's 60), although aligned word differences rise
to 70. An explicit field-address pointer combined with the cache emitted
identical bytes and was not retained. No further address-forcing form was
tried.

The configured table starts at `0x800A863C` with alignment four. Its nine
entries occupy 36 bytes: eight match ROM, while entry eight targets
`0x8000D7D4` instead of `0x8000D7CC`. The emitted `.rodata` section is
48 bytes, including twelve trailing zero padding bytes; these are outside
the compared dispatch table and are not evidence of a canonical unit boundary.

A private six-profile check of this changed cached-field source set flags
at per-unit level and verified actual compile commands. O2/MIPS II reused
the preceding result with identical effective flags and source. No profile
matched:

| IDO 5.3 profile | Symbol bytes | Overlap word differences | Extra words |
| --- | ---: | ---: | ---: |
| O1 / MIPS II | 528 | 118 | 8 |
| O1 / MIPS III / 32-bit ABI | 528 | 118 | 8 |
| O2 / MIPS II | 504 | 70 | 2 |
| O2 / MIPS III / 32-bit ABI | 504 | 71 | 2 |
| O3 / MIPS II | 504 | 70 | 2 |
| O3 / MIPS III / 32-bit ABI | 504 | 71 | 2 |

Every profile linked the function at `0x8000D5EC` and had no missing words.
No configuration or USA assembly split changed. Private artifacts are under
`/tmp/us30-wrongsize-sol/cached-toggle/`; profile commands, flags, hashes and
results are in `profile-check/summary.json` there.
The frozen source SHA256 is
`5994e7d3f117a3351690794cc1b851684c50473bc612f1a5d126a0397bb5fca0`;
the O2/MIPS II function-slice SHA256 is
`5e627ef2704b65a2aa0ab0ab0e5a7b2958762940af6571088141af64d2386b96`.
