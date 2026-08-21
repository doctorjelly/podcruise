# Object selector accessors

Status: **byte-matching C; integrated into all four unique exact rebuilds**.

`func_8001811C` is a newly recovered neighboring setter; it is behavior-
recovered pending isolated compiler verification.

These original behavioral descriptions come from the supplied USA, Japan,
and Europe binaries. The containing object and selector meanings remain
unknown, so address-based names and offset-based fields are retained.

## Boundaries, delay slots, and behavior

`func_8001811C` spans 72 bytes from `8001811C` through the return delay slot at
`80018160`. It tests the selector independently: selector 4 writes the
supplied value at offset `0x15C`, selector 3 at `0x164`, selector 6 at
`0x158`, and selector 5 at `0x160`.

| Function | Bytes | Behavior | USA terminal return / delay slot |
|---|---:|---|---|
| `func_80018084` | 68 | For selectors two, three, and five, store the float argument at offsets `0x148`, `0x14C`, and `0x150`, respectively; otherwise do nothing. | `800180A4`, `800180AC`, or `800180B4` / selected store; otherwise `800180C0` / no operation |
| `func_800180C8` | 76 | For selectors two, three, and five, return the float at offsets `0x148`, `0x14C`, and `0x150`; otherwise return negative one. | `800180EC`, `800180F4`, or `800180FC` / selected load; default `8001810C` / no operation |
| `func_80018164` | 88 | Map selectors four, three, six, and five to signed words at offsets `0x15C`, `0x164`, `0x158`, and `0x160`; return negative one otherwise. | `80018170`, `80018184`, `80018198`, or `800181AC` / selected load; default `800181B4` / no operation |

Each full span starts after a complete preceding return and ends before the
next established entry. The analyzer labels at `800180AC`, `800180B4`,
`800180BC`, `800180F4`, `800180FC`, `80018104`, `80018178`, `8001818C`,
`800181A0`, and `800181B4` are shared/internal return tails. None has a direct
caller. IDO emits the observed branch layout from the independently written C
`switch` statements, including all branch and return delay slots.

## Call and regional evidence

No direct `jal` references to these three entries occur in the scanned main
code, and none calls another function. Indirect use remains an inference. The
complete spans are byte-identical in all three retail builds:

| Function | Japan VRAM | Europe VRAM |
|---|---|---|
| `func_80018084` | `800181B4` | `80018514` |
| `func_800180C8` | `800181F8` | `80018558` |
| `func_80018164` | `80018294` | `800185F4` |

IDO 5.3 and IDO 7.1 with the recorded `-O2` profile both reproduce all 232
canonical USA bytes exactly. Independent comparisons also prove the relocated
Japan and Europe bytes and the same-address LRG bytes. Every hybrid build
substitutes these functions and retains its complete ROM SHA-1.
