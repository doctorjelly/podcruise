# Medium system tranche

Status: **10 functions measured in all four builds: 3 byte-matching with IDO
5.3 and 7 behavior-recovered**.

## Verified facts

Every USA entry is a direct `jal` target with a conventional prologue. The
preceding function has a complete return, and the next accepted entry begins
immediately after the executed return delay slot shown below.

| Function | ROM | Bytes | `jr ra` / delay slot | Direct USA callers |
| --- | ---: | ---: | --- | ---: |
| `func_80005F54` | `0x006B54` | 460 | `80006118` / restore the 120-byte frame | 2 |
| `func_80007034` | `0x007C34` | 484 | `80007210` / restore the 56-byte frame | 1 |
| `func_80016A20` | `0x017620` | 468 | `80016BEC` / restore the 200-byte frame | 1 |
| `func_80031134` | `0x031D34` | 496 | `8003131C` / restore the 64-byte frame | 1 |
| `func_8007C64C` | `0x07D24C` | 460 | `8007C810` / `nop` | 1 |
| `func_8007DED8` | `0x07EAD8` | 468 | `8007E0A4` / restore the 168-byte frame | 9 |
| `func_8007F24C` | `0x07FE4C` | 484 | `8007F428` / restore the 160-byte frame | 1 |
| `func_80084148` | `0x084D48` | 476 | `8008431C` / restore the 160-byte frame | 1 |
| `func_80085FB0` | `0x086BB0` | 456 | `80086170` / restore the 104-byte frame | 3 |
| `func_80086EB4` | `0x087AB4` | 460 | `80087078` / `nop` | 1 |

## Behavioral specification

| Function | Independently stated behavior |
| --- | --- |
| `func_80005F54` | Sample a four-float pose track at a key interval. Copy the next or current endpoint when the time lies outside the interval; otherwise calculate the blend, convert both endpoint rotations to quaternions, interpolate them, and convert the result back. |
| `func_80007034` | Convert an object duration to frames, round it upward and then to a multiple of sixteen, and publish the resulting frame limits. Initialize the object, allocate the primary and secondary buffers, connect their records, publish a relocation delta, initialize a 64-byte subsystem, and clear its status halfword. |
| `func_80016A20` | Prepare transform state and leave the destination alone if preparation fails. On success, transform the three unit axes, transpose them into the output basis, fill the homogeneous entries, and set translation to the negative source position projected through that basis. |
| `func_80031134` | Reset a registration system and install ten built-in blocks at indices 0 through 9. Beginning at index 7, register up to 25 tagged records and their auxiliary data, zero six values on each, save the assigned index in the record, and finally select slot 8. |
| `func_8007C64C` | Detach a view's prior node, set its state flags, reserve registry slot 2, and construct a matrix at an offset from the view position. When the subject displacement is large enough, derive a planar orientation from it; copy the matrix to the global and newly acquired nodes, attach the global payload, and release the registry slot. |
| `func_8007DED8` | Dispatch by node type. A `0x3064` node may run a side effect and then propagate selector 2 through each usable child item. A type carrying `0x4000` recursively ORs child results, temporarily applies the `0x8000` recursion guard when present, optionally emits two notifications, and restores the saved guard. |
| `func_8007F24C` | Rebuild a track matrix while advancing its parameter by a positive step until the target crosses the track plane or floating-point progress stops. If no forward move occurred, search backward with the alternate step and then advance once to settle on the crossing. |
| `func_80084148` | Walk a display-command stream until opcode `0xDF`. Opcode `0x01` selects the vertex array, `0x05` submits one indexed triangle, and `0x06` submits two; opcode `0x03` and unrecognized commands have no effect. |
| `func_80085FB0` | Derive aspect and field of view from viewport parameters and a global threshold, calculate the frustum extents and near/far terms, populate the projection matrix, and pass the completed view to its finalizer. |
| `func_80086EB4` | Select an indexed viewport, emit its viewport command, scale its scissor rectangle from a 320-by-240 reference to the configured dimensions, emit scissor and perspective-normalization commands, and flush the display-list pointer. |

## Calls and addressed globals

| Function | Callees | Addressed globals |
| --- | --- | --- |
| `func_80005F54` | `80005CAC`, `800827E0`, `800829F4`, `80082B38` | none; reads the supplied track |
| `func_80007034` | `80006FE4`, `800880AC`, `800880E0` | `D_800980C0`, `func_80097FF0`, `D_8009A2D0`, `D_800A8180/8C/98`, `D_800AFA60/64/6C/70`, `D_800AFABC`, `D_800AFE8C/90/94`, `D_800B0498/B04B0` |
| `func_80016A20` | `80016260`, `800167E4` | none; reads source fields `0x30..0x38` |
| `func_80031134` | `8000ACC0`, `8000AEFC`, `8000AF4C`, `8000B02C`, `8000B1B0`, `8003F714`, `8003F7B8` | `D_800D69A0` through `D_800D6BE0` in 64-byte steps |
| `func_8007C64C` | `800151E0`, `80017874`, `80017BA8`, `800181BC`, `8007B6CC`, `8007B7BC`, `8007B9E4`, `8007BA9C` | `D_800ADB64`, `D_8011C918`, `D_8011C940` |
| `func_8007DED8` | `80017DA4`, `80017DAC`, `80017E54`, `80017E5C`, `800181BC`, `800182FC`, `800183A8`, `8007D3CC`, `8007DBA4`, and itself | `D_800A5B5C`, `D_800A66DC` |
| `func_8007F24C` | `8003B02C` | `D_800ADC54`, `D_800ADC58` |
| `func_80084148` | `80083EFC` | none |
| `func_80085FB0` | `80014D20`, `80014F54`, `80085F78` | `D_800ADD64` |
| `func_80086EB4` | `80038D5C` | `D_80114470`, `D_80120DF0`, `D_801217B0` |

## Regional evidence

| USA | Japan | Europe |
| --- | --- | --- |
| `80005F54` | `80005F54` | `80005F54` |
| `80007034` | `80007034` | `80007034` |
| `80016A20` | `80016B50` | `80016EB0` |
| `80031134` | `80031B94` | `800346F4` |
| `8007C64C` | `8007D2EC` | `80081B2C` |
| `8007DED8` | `8007EB78` | `800833B8` |
| `8007F24C` | `8007FEEC` | `8008472C` |
| `80084148` | `80084E28` | `80089628` |
| `80085FB0` | `80086CA4` | `8008B490` |
| `80086EB4` | `80087BA8` | `8008C394` |

Each regional entry has a unique relocation-insensitive 32-instruction match.
The complete Japan and Europe bodies have the same normalized instruction
sequence and instruction count as USA. LRG has the exact USA bytes.

## Compiler status

Exact IDO 5.3 `-O2 -mips2` comparisons place every function at its canonical
address. USA, Japan, Europe, and LRG produce the same result for this tranche:

| Function | Target bytes | C bytes | First difference | Status |
| --- | ---: | ---: | ---: | --- |
| `func_80005F54` | 460 | 460 | none | **byte-matching** |
| `func_80007034` | 484 | 484 | `0xD5` | behavior-recovered |
| `func_80016A20` | 468 | 468 | `0x03` | behavior-recovered |
| `func_80031134` | 496 | 496 | none | **byte-matching** |
| `func_8007C64C` | 460 | 460 | `0x03` | behavior-recovered |
| `func_8007DED8` | 468 | 468 | none | **byte-matching** |
| `func_8007F24C` | 484 | 484 | `0x1D` | behavior-recovered |
| `func_80084148` | 476 | 472 | `0x03` | behavior-recovered |
| `func_80085FB0` | 456 | 464 | `0x03` | behavior-recovered |
| `func_80086EB4` | 460 | 456 | `0x31` | behavior-recovered |

Only the three exact functions replace assembly in hybrid rebuilds. The seven
nonmatching sources remain behavioral recoveries. Address-based names remain
because subsystem semantics are not yet proven.
