# Remaining medium mismatch audit tranche

## Verified facts

| Function | USA ROM | Size | Return / delay slot | Direct callers |
| --- | ---: | ---: | --- | --- |
| `func_800941E0` | `0x094DE0` | 760 | `800944D0: jr ra` / `800944D4: nop` | `func_8008BC30`, `func_80092560` |
| `func_800857B0` | `0x0863B0` | 772 | `80085AAC: jr ra` / `80085AB0: nop` | no direct `jal` found |
| `func_800745AC` | `0x0751AC` | 568 | `800747DC: jr ra` / `800747E0: nop` | `func_80074CDC` |

For `func_800857B0`, the entry follows the preceding return and its own return
delay slot is immediately followed by the next function at `0x80085AB4`. The
boundary is therefore structurally verified despite the absence of a direct
USA call; the function may be reached indirectly.

`func_800941E0` calls `func_80088360` and accesses `D_800A7B7C`,
`D_800A7F50`, and `D_800A7F54`, as well as the fixed video-interface register
window. `func_800857B0` also calls `func_80088360` and accesses
`D_80120DF0`, `D_80114470`, `D_801217B0`, and `D_800D9DB4`.
`func_800745AC` calls `func_80017824` and accesses `D_800AD97C`,
`D_800AD980`, and `D_800AD984`.

Normalized regional searches map the three bodies to Japan `0x80094ED0`,
`0x800864A4`, and `0x800751DC`, and Europe `0x80099730`, `0x8008AC90`, and
`0x80079A8C`, respectively. These matches were used only as structural and
relocation evidence.

## Behavioral specifications

- `func_800941E0` chooses the active video field, derives origin and horizontal
  and vertical scaling from the pending context and mode, applies context
  overrides, writes the complete video-interface register set, rotates the two
  context pointers, and copies the newly active context.
- `func_800857B0` scales one configured rectangle to the current screen size,
  emits the image, fill-color, rectangle, and synchronization display-list
  commands, and selects either a packed 16-bit RGB fill or the fixed 32-bit
  fill from the current pixel depth.
- `func_800745AC` smooths an object level toward a state-dependent target,
  derives two clamped triangular animation factors, conditionally transforms
  two object parts, and advances each enabled part using its global rate.

## Compiler status

All three functions are independently expressed, behavior-recovered C. Exact
USA IDO 5.3 `-O2` comparisons give:

| Function | ROM bytes | IDO symbol bytes | Padded bytes | First difference | Differing overlap words |
| --- | ---: | ---: | ---: | ---: | ---: |
| `func_800941E0` | 760 | 760 | 768 | `0x05` | 138 |
| `func_800857B0` | 772 | 760 | 768 | `0x00` | 189 |
| `func_800745AC` | 568 | 552 | 560 | `0x03` | 137 |

None is byte-matching. Caching field-register accesses and reordering locals did
not improve `func_800941E0`. Swapping the two display-list pointer locals did
not improve `func_800857B0`. Replacing `func_800745AC`'s one-element part
pointer array with direct address expressions reduced its compiler body to 528
bytes, farther from the 568-byte ROM body, so it was restored. No exact match
is claimed.
