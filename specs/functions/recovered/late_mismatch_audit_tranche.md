# Late mismatch audit tranche

## Verified facts

| Function | USA ROM | Size | Return / delay slot | Direct caller functions |
| --- | ---: | ---: | --- | --- |
| `func_8004FFA8` | `0x050BA8` | 608 | `80050200: jr ra` / `80050204: nop` | `func_8004DC0C` |
| `func_800519C0` | `0x0525C0` | 704 | `80051C78: jr ra` / `80051C7C: nop` | `func_8001ADD4`, `func_8001F5AC`, `func_80021F84`, `func_80024070`, `func_8002D6EC` |
| `func_8003E59C` | `0x03F19C` | 724 | `8003E868: jr ra` / restore the 96-byte frame | `func_8003E9D0` |
| `func_80081360` | `0x081F60` | 456 | `80081520: jr ra` / increment the frame counter | `func_8002F750` |

`func_8004FFA8` calls `func_800174B8`, `func_80017918`, `func_80017BA8`,
`func_80015288`, `func_80014F54`, `func_80030298`, `func_8003FC94`,
`func_80046670`, `func_800517D8`, `func_80051898`, `func_80063084`, and
`func_8004B868`; it accesses `D_800A5248`, `D_800A4C00`, `D_800A508C`, and
`D_8011A508`. `func_800519C0` calls `func_80032F2C` and `func_800320E0` and
accesses the `D_800A31E0`, `D_800A368C`, `D_80113E60`, `D_80118F90` through
`D_80118FAC`, and `D_80119838` through `D_801198A6` state blocks.
`func_8003E59C` calls `func_8002F054`, `func_80082BE0`, `func_80011EA4`,
`func_80011F04`, `func_800141EC`, `func_80014568`, and `func_80014C98`; it
accesses `D_800A4984`, `D_800A59B0`, `D_800AAB90`, `D_800AAB94`,
`D_80118958`, and `D_80118C50`. `func_80081360` calls `func_80081260`,
`func_800811DC`, and `func_8008126C` and updates the timing globals declared in
its source.

Normalized regional searches locate the respective bodies at Japan
`0x80050C14`, `0x8005262C`, `0x8003EF1C`, and `0x80082000`, and Europe
`0x80054C50`, `0x80056668`, `0x80042EDC`, and `0x80086840`. These were used
only as structural and relocation evidence.

## Behavioral specifications

- `func_8004FFA8` copies and scales the camera transform, enables the scene
  state, obtains four indexed objects and applies that transform to each
  present object, positions and aims a fifth object from the fixed placement
  data, then restores the render state.
- `func_800519C0` initializes shared pointers and a copied settings block,
  loads seven mode/level pairs, applies each pair through the settings helpers,
  copies or clears derived values, optionally overrides one slot, and refreshes
  the output settings.
- `func_8003E59C` returns immediately when drawing is disabled. Otherwise it
  derives color and alpha parameters, emits commands selected by each recorded
  point's kind, plots every point, flushes the result, and clears the count.
- `func_80081360` initializes three clocks from the hardware counter on reset.
  Thereafter it either measures and clamps elapsed real time or advances a
  configured fixed timestep, updates current and previous timestamps, and
  increments the frame counter.

## Compiler status

All four functions are independently expressed, behavior-recovered C. Exact
USA IDO 5.3 `-O2` comparisons give:

| Function | ROM bytes | IDO symbol bytes | Padded bytes | First difference | Differing overlap words |
| --- | ---: | ---: | ---: | ---: | ---: |
| `func_8004FFA8` | 608 | 608 | 608 | `0xE5` | 11 |
| `func_800519C0` | 704 | 704 | 704 | `0x00` | 175 |
| `func_8003E59C` | 724 | 724 | 736 | `0x03` | 28 |
| `func_80081360` | 456 | 432 | 432 | `0x13` | 73 |

None is byte-matching. In `func_8004FFA8`, all 11 differences are temporary
register choices around five repeated object-field stores. Declaration order
and source-line grouping did not improve them. A validated, quiet 60-second
permutation pilot had zero stack, branch, ordering, insertion, and deletion
penalties; its score improved from 155 to 145 only by adding a dead always-true
block, which was rejected and not copied into the recovered source.

Swapping the two local arrays did not improve `func_800519C0`; removing the
volatile qualifier did not improve `func_8003E59C`. In `func_80081360`, the ROM
materializes two address bases while storing one 64-bit timestamp into three
globals. Expressing that operation as the observed right-to-left chained
assignment preserves behavior, reproduces the ROM's store order, and reduces
the differing overlap words from 81 to 73. Chaining the later floating-point
stores did not help and was restored. No exact match is claimed.
