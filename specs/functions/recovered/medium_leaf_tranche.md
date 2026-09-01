# Medium leaf tranche

Status: **1 byte-matching and 9 behavior-recovered functions in canonical
USA; all 10 are measured in all four builds**.

## Verified facts

Every USA entry below is a direct `jal` target, follows a completed preceding
function, and ends at the return and executed delay slot shown. The next
accepted entry begins immediately afterward, except for `func_8008FF98`: its
two following `nop` words are alignment padding, not part of the function.
That makes its verified size 320 bytes rather than the automated 328-byte
candidate.

| Function | ROM | Bytes | `jr ra` / delay slot | Direct USA callers |
| --- | ---: | ---: | --- | ---: |
| `func_8000630C` | `0x006F0C` | 352 | `80006464` / `nop` | 1 |
| `func_80007488` | `0x008088` | 260 | `80007584` / `nop` | 1 |
| `func_80007728` | `0x008328` | 240 | `80007810` / restore the 72-byte frame | 1 |
| `func_800280D8` | `0x028CD8` | 280 | `800281E8` / `nop` | 1 |
| `func_80030964` | `0x031564` | 280 | `80030A74` / restore the 40-byte frame | 32 |
| `func_80045004` | `0x045C04` | 320 | `8004513C` / restore the 200-byte frame | 1 |
| `func_8004F254` | `0x04FE54` | 260 | `8004F350` / restore the 128-byte frame | 1 |
| `func_8005B2D0` | `0x05BED0` | 288 | `8005B3E8` / `nop` | 1 |
| `func_8005EAC0` | `0x05F6C0` | 344 | `8005EC10` / restore the 72-byte frame | 1 |
| `func_8008FF98` | `0x090B98` | 320 | `800900D0` / restore the 48-byte frame | 1 |

## Behavioral specification

| Function | Independently stated behavior |
| --- | --- |
| `func_8000630C` | Sample an object's current four-float rotation. In the interpolation mode, sample a second rotation, convert both to quaternions, blend them, and convert back. If an attached node exists, either clear its rotation when the angle is near zero or decompose its transform, replace the rotation, recompose it, and write it back. |
| `func_80007488` | Reset the transfer subsystem, translate a task buffer to a physical address, calculate a sixteen-byte-aligned height clamped to a global minimum, and build a transfer list. Deliberately hang if the produced count reaches 3001, otherwise record the pool start and eight-byte-aligned used length, then run two finalizers. |
| `func_80007728` | Perform a requested number of receives against a fixed queue. Then walk the active linked list and move every node whose generation is older than the global threshold to the list tail, preserving the next pointer before unlinking it. |
| `func_800280D8` | Display a fixed message for three seconds. On the first invocation, mark a global block initialized, fill its summary record with sentinel values, find the last unused one of four slots, give that slot the default `DBG` record, and persist the change. |
| `func_80030964` | Scan a word stream through its `-1` sentinel, skip an optional counted `Data` chunk, then process the pointers in an optional null-terminated `Anim` chunk. Initialize each pointed-to entity, retain the lowest address encountered, and use it to update two global relocation values. Return the animation pointer list or null. |
| `func_80045004` | Play one fixed sound, run a work-buffer helper for each of six nonempty session slots, then play two more fixed sounds. The binary also performs a float read and comparison after each helper whose two paths have the same observable effect. |
| `func_8004F254` | Walk the number of records named by the owner's signed byte. For each `Locl` record or record with flag `0x20`, send a three-word `NAsn` message to the next `cMan` slot, carrying a one-based ordinal and the record's value. The binary materializes one unused global address; the C omits that dead operation. |
| `func_8005B2D0` | Reject a special actor/state combination when its position lies inside four global bounds and its referenced entry has flag 8. Otherwise approve only when state flag `0x02000000` is clear and either the counter is at least five or the timer is below 60.0. |
| `func_8005EAC0` | Reserve a sixteen-entry resource family, initialize each available 88-byte slot, attach one copied resource word, and store its pointer in a global table. Then initialize a root slot that owns that table, publish it globally, and pass the table to the final setup routine. |
| `func_8008FF98` | Clear and populate a link from a five-byte request, look up its owner entry, and, for a newly activated entry, send initialization commands through its callback. Attach the entry and link in both directions and return whether an entry was found. |

## Callees and globals

The call and data dependencies were read from each complete body, not inferred
from source spelling.

| Function | Callees | Addressed globals |
| --- | --- | --- |
| `func_8000630C` | `80005F54`, `800175E0`, `80017B34`, `80017BA8`, `80017C18`, `80081814`, `80081948`, `800827E0`, `800829F4`, `80082B38` | `D_800A8140`, `D_800A8148` |
| `func_80007488` | `80006FDC`, `8002E5D4`, `80088360`, `800883E0`, `80088538`, `80088AD0` | `D_8009A2CC`, `D_8009A310`, `D_800AFA60`, `D_800AFE8C`, `D_800AFE90` |
| `func_80007728` | `80087E80`, `80088020`, `80088050` | `D_800AFAC0`, `D_800AFE88`, `D_800B0498` |
| `func_800280D8` | `800399F0`, `8003E1EC` | `D_800A25F4`, `D_800A969C`, `D_80113680`, `D_80113E60` |
| `func_80030964` | `80005BB8` | `D_800D9DC4`, `D_800D9DC8`, `D_800D9DD0` |
| `func_80045004` | `80008B14`, `80083190` | none |
| `func_8004F254` | `8003F714`, `8003F99C` | `D_80118F90`; dead address formation for `D_800A4BE0` |
| `func_8005B2D0` | `800183A8` | `D_800ACFA0`, `D_800ACFA4`, `D_800ACFA8`, `D_800ACFAC` |
| `func_8005EAC0` | `800181BC`, `80018324`, `80030298`, `800305E8`, `8003FC94`, `8007B41C` | `D_8011AC98`, `D_8011B260`, `D_8011B280`, `D_8011B2C0`, `D_8011B840` |
| `func_8008FF98` | `80088500`, `8008FEB0`, plus the entry's callback | none |

## Regional evidence

| USA | Japan | Europe |
| --- | --- | --- |
| `8000630C` | `8000630C` | `8000630C` |
| `80007488` | `80007488` | `80007488` |
| `80007728` | `80007728` | `80007728` |
| `800280D8` | `80028960` | `8002A7B4` |
| `80030964` | `800313C4` | `80033F24` |
| `80045004` | `80045814` | `800499A4` |
| `8004F254` | `8004FEC0` | `80053EFC` |
| `8005B2D0` | `8005BE7C` | `80060718` |
| `8005EAC0` | `8005F628` | `80063FA4` |
| `8008FF98` | `80090C88` | `800954E8` |

For every row, the complete Japan and Europe spans have the same normalized
instruction sequence as USA, and LRG has the exact USA bytes. Nine regional
entries also have unique 32-instruction relocation-insensitive matches.
`func_8005EAC0` is the one structural inference: it was first located by the
constant relocation delta shared by both neighboring functions, then verified
over all 86 instructions and every callee/global relocation.

## Compiler status

IDO 5.3 under the accepted `ido53_o2` profile places all ten C functions at
their canonical address in USA, Japan, Europe, and LRG. The comparison result
is the same in each build:

| Function | Target bytes | C bytes | First difference | Status |
| --- | ---: | ---: | ---: | --- |
| `func_8000630C` | 352 | 352 | `0xD8` | behavior-recovered |
| `func_80007488` | 260 | 260 | `0x2E` | behavior-recovered |
| `func_80007728` | 240 | 232 | `0x03` | behavior-recovered |
| `func_800280D8` | 280 | 280 | `0x1D` | behavior-recovered |
| `func_80030964` | 280 | 280 | `0x15` | behavior-recovered |
| `func_80045004` | 320 | 232 | `0x03` | behavior-recovered |
| `func_8004F254` | 260 | 248 | `0x03` | behavior-recovered |
| `func_8005B2D0` | 288 | 288 | `0xC6` | behavior-recovered |
| `func_8005EAC0` | 344 | 344 | none | **byte-matching C: USA** |
| `func_8008FF98` | 320 | 320 | `0x18` | behavior-recovered |

`func_8005EAC0` reproduces all 344 USA bytes after retaining the exhausted-loop
invariant expression that selects the ROM's saved-register allocation. No
regional compiler-match claim is made. The other nine units remain assembly in
the USA hybrid rebuild. Address-based names remain because the subsystem
identities are not yet proven.

For `func_80007728`, explicit queue and message-pointer locals reproduce the
canonical 72-byte frame but still use only `$s0`-`$s3`; the ROM preserves the
receive count in `$s4` and uses `$s1`/`$s2` for those two locals. Qualifier and
declaration-order variants did not change that allocation and were reverted.
