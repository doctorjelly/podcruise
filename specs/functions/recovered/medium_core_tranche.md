# Medium core tranche

Status: **5 behavior-recovered functions measured in all four builds; none is
byte-matching**.

## Verified facts

Every USA entry is a direct `jal` target with a conventional prologue. The
true boundary ends after the executed return delay slot shown below; the next
accepted function begins immediately afterward.

| Function | ROM | Bytes | `jr ra` / delay slot | Direct USA callers |
| --- | ---: | ---: | --- | ---: |
| `func_8002FF38` | `0x030B38` | 504 | `80030128` / restore the 112-byte frame | 2 |
| `func_80037C8C` | `0x03888C` | 528 | `80037E94` / restore the 72-byte frame | 3 |
| `func_800678A8` | `0x0684A8` | 524 | `80067AAC` / `nop` | 2 |
| `func_8006A9D4` | `0x06B5D4` | 508 | `8006ABC8` / restore the 144-byte frame | 1 |
| `func_8007E988` | `0x07F588` | 500 | `8007EB74` / restore the 272-byte frame | 2 |

The callers are `80030130` and `80030154` for `8002FF38`; three sites in
`80038388` for `80037C8C`; `8006A49C` and `8006A9D4` for `800678A8`;
`8006C0D4` for `8006A9D4`; and two sites in `8007CD50` for `8007E988`.

## Behavioral specification

| Function | Independently stated behavior |
| --- | --- |
| `func_8002FF38` | Reserve an output area, read the packed resource count, and reject an out-of-range index. Copy the selected 20-byte header, then copy its entry table and any referenced header payload. Copy every entry payload into a 16-byte-aligned destination, replace stored offsets with destination pointers, finalize the allocation cursor, and return the new object. |
| `func_80037C8C` | In display-list mode, allocate a matrix slot and refresh a dirty node matrix. Increment the traversal depth and, while it is within 32, push or emit that matrix. Visit non-null children whose selector-2 bits contain the required mask and overlap the wanted mask. Pop or emit the matching restore command when one was pushed, then decrement the depth. |
| `func_800678A8` | Derive a collision radius from the absolute field at `0x208`, reducing it by up to 75 percent and clamping it to 1.5. Run one or two collision queries and count their successes. For a sufficiently fast object with a nearly perpendicular hit vector, invoke the response helper. Always finish by reconciling the two supplied positions through the object's context. |
| `func_8006A9D4` | Save the supplied position and clear state bit `0x200`. When the normalized counter is not below one and neither exclusion flag is set, force a planar result, publish the unit-Z normal, and return 2. Otherwise, flag `0x20` selects collision displacement processing and the remaining path performs a direct position query; these paths return zero. |
| `func_8007E988` | Run two initial random-generator side effects, then examine eight timers. For each expired timer, choose a new duration from two to eight, invoke the transform helpers using object fields `0x20`, `0xAC`, and `0x1A0`, publish the resulting point with Z lowered by eight, and add independent random X and Y offsets in the range from -100 to 100. |

## Calls and addressed globals

| Function | Callees | Addressed globals |
| --- | --- | --- |
| `func_8002FF38` | `80011D60`, `8002FAC4`, `8002FAFC` | packed resource base `D_13307F0` |
| `func_80037C8C` | `80017DAC`, `800182FC`, `80033E08`, `80033F94`, `800344C8`, `80034650`, `80038388` | `D_800A3FD8`, `D_800A3FE8`, `D_800D9DB1`, `D_80112C90`, `D_80112C94` |
| `func_800678A8` | `80000538`, `80004670`, `80033010`, `80067718` | `D_800AD4DC` |
| `func_8006A9D4` | `80033010`, `8003B184`, `800678A8`, `80069EC0` | none |
| `func_8007E988` | `800156DC`, `8003B184`, `80082BE0` | `D_800A66E0`, `D_800ADC34`, `D_8011DC50` |

## Regional evidence

| USA | Japan | Europe | Instructions |
| --- | --- | --- | ---: |
| `8002FF38` | `80030998` | `800334F8` | 126 |
| `80037C8C` | `800386EC` | `8003C5FC` | 132 |
| `800678A8` | `80068418` | `8006CD88` | 131 |
| `8006A9D4` | `8006B544` | `8006FEB4` | 127 |
| `8007E988` | `8007F628` | `80083E68` | 125 |

Each Japan and Europe entry has a unique relocation-insensitive 32-instruction
match. Independent comparison of every instruction through the return delay
slot shows the same normalized instruction sequence and count as USA. LRG has
the exact USA function bytes.

## Compiler status

Exact IDO 5.3 `-O2 -mips2` comparisons place each C function at its canonical
address. The USA measurements are:

| Function | Target bytes | C bytes | First difference | Status |
| --- | ---: | ---: | ---: | --- |
| `func_8002FF38` | 504 | 504 | `0x64` | behavior-recovered |
| `func_80037C8C` | 528 | 528 | `0x8D` | behavior-recovered |
| `func_800678A8` | 524 | 524 | `0x22` | behavior-recovered |
| `func_8006A9D4` | 508 | 512 | `0x10` | behavior-recovered |
| `func_8007E988` | 500 | 500 | `0x4C` | behavior-recovered |

Japan, Europe, and LRG also fail their exact compiler comparisons. These units
therefore remain assembly-backed in every hybrid build. Their source describes
reviewed behavior, but no byte-match claim or assembly substitution is made.
Address-based names remain because subsystem semantics are not yet strong
enough to justify authored replacements.
