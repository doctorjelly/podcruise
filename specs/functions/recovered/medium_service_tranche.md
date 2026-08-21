# Medium service tranche

Status: **5 behavior-recovered functions measured in all four builds; none is
byte-matching C**.

## Verified facts

Each USA entry is a direct `jal` target. Its return and executed delay slot were
checked in the canonical ROM.

| Function | ROM | Candidate bytes | `jr ra` / delay slot | Direct USA callers |
| --- | ---: | ---: | --- | ---: |
| `func_8002DD7C` | `0x02E97C` | 564 | `8002DFA0` / restore the 80-byte frame | 2 |
| `func_8003B860` | `0x03C460` | 592 | `8003BAA8` / store the advanced display-list pointer | 1 |
| `func_80044A7C` | `0x04567C` | 604 | `80044CD0` / restore the 320-byte frame | 1 |
| `func_800316A8` | `0x0322A8` | 636 | `8003191C` / restore the 56-byte frame | 1 |
| `func_80085AB4` | `0x0866B4` | 656 | `80085D3C` / `nop` | 1 |

The next entries begin at `8002DFB0`, `8003BAB0`, `80044CD8`, `80031924`, and
`80085D44`. The USA interval after `func_8002DD7C` contains two alignment nops;
Japan and Europe contain one, making their corresponding candidate interval
four bytes shorter. The USA callers are `8001E57C` and `800235C4` for
`func_8002DD7C`; `8003CFDC` for `func_8003B860`; `800452E0` for
`func_80044A7C`; `8002E0F8` for `func_800316A8`; and `80085DC8` for
`func_80085AB4`.

## Behavioral specification

| Function | Independently stated behavior |
| --- | --- |
| `func_8002DD7C` | Enable the shared selection mode and set flags on the supplied object and shared context. Optionally seed the result list from the object when the context test and mode bit permit it. Repeatedly choose a random category and entry, select the applicable availability mask, reject unavailable or duplicate identifiers, and append identifiers until the list contains five. |
| `func_8003B860` | Append a self-contained display-list block. Bind shared vertex state, clear four slots, choose each rectangle corner or the supplied point according to the point's quadrant, write four texture-coordinate pairs, emit the draw command, and publish the advanced list pointer. |
| `func_80044A7C` | For each of six enabled links whose two endpoint joints exist, query both joint transforms and form the endpoint displacement. Build an orthonormal frame along that displacement, place it at the midpoint, copy it to one output joint, then scale it by the shared width and one twentieth of the link length and copy it to the paired output joint. |
| `func_800316A8` | Service four controller slots. Process pending resets and the shared presence transition, then either drain and count down an unavailable slot or advance its repeat trigger using a shifting button mask or phase accumulator. Send the helper's off/on updates and maintain the per-slot phase and shared state values. |
| `func_80085AB4` | Clear two paired 32-bin histograms, tally two five-bit fields from every 16-bit sample in the configured width-by-height buffer, and return the weighted contribution of upper-field bins 2 through 15 after quarter-count and 19,200-unit scaling. |

## Calls and addressed globals

| Function | Callees | Addressed globals |
| --- | --- | --- |
| `func_8002DD7C` | `8002D968`, `80082BE0` | `D_800A5998`, `D_800A4B94`, `D_800A9ACC`, `D_800A21B4`, `D_800A22E8`, `D_80119668`, `D_80113E60`, `D_80113680` |
| `func_8003B860` | none | `D_800A4920` |
| `func_80044A7C` | `80083190`, `800154D0`, `80015288`, `80015538`, `800155C0`, `800155EC`, `80017520`, `80017BA8` | `D_800AAD08` |
| `func_800316A8` | `8002E82C`, `8002F054`, `8008B1B0` | `D_800DB8A0`, `D_800DB910`, `D_800A290C`, `D_800A291C` |
| `func_80085AB4` | none | `D_800A68B0`, `D_80114470`, `D_801488C8`, `D_80148948`, `D_801489C8` |

## Regional evidence

| USA | Japan | Europe | Compared instructions |
| --- | --- | --- | ---: |
| `8002DD7C` | `8002E7E0` | `80031320` | 140 |
| `8003B860` | `8003C1E0` | `800401A0` | 148 |
| `80044A7C` | `8004528C` | `8004941C` | 151 |
| `800316A8` | `80032108` | `80034C68` | 159 |
| `80085AB4` | `800867A8` | `8008AF94` | 164 |

All ten regional entries have unique relocation-insensitive 32-instruction
matches. Their complete executable spans have the same normalized instruction
sequence as USA; the `func_8002DD7C` comparison stops before USA's second
alignment nop. LRG has the exact USA bytes. Callee and addressed-global
relocations were aligned at their corresponding instructions before the
regional compiler checks were configured.

## Compiler status

Exact IDO 5.3 `-O2 -mips2` comparisons place every function at its canonical
address. The results are identical across builds except for the documented
regional padding after `func_8002DD7C`:

| Function | USA/LRG target | JP/EU target | C bytes | First difference | Status |
| --- | ---: | ---: | ---: | ---: | --- |
| `func_8002DD7C` | 564 | 560 | 560 | `0x58` | behavior-recovered |
| `func_8003B860` | 592 | 592 | 592 | `0xBE` | behavior-recovered |
| `func_80044A7C` | 604 | 604 | 604 | `0x0A` | behavior-recovered |
| `func_800316A8` | 636 | 636 | 636 | `0x05` | behavior-recovered |
| `func_80085AB4` | 656 | 656 | 656 | `0x49` | behavior-recovered |

The histogram-clear loop in `func_80085AB4` uses an independently expressed
preincrement form that reproduces the original loop scheduling, but later
register allocation still differs. No function in this tranche is eligible
for hybrid-build substitution, and no byte match is claimed. Address-based
names remain because the wider subsystem semantics are not yet established.
