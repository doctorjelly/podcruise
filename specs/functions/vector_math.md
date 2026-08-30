# Vector-math leaf tranche

Status: **19 behavior-recovered functions; 16 byte-matching and 3 behavior-only**.

These specifications were independently derived from the supplied binaries.
The address-based function names remain because the original authored names are
not established. The repeated two- and three-float layouts and their arithmetic
uses justify the local `PcVec2f` and `PcVec3f` type names.

## Boundary and behavioral evidence

Each entry is a direct USA `jal` target immediately following a complete prior
function. Every body is call-free, has no global access, and terminates with
`jr $ra` followed by the listed executed delay-slot instruction. The next
established entry starts immediately after that delay slot.

| Function | Bytes | Compact behavioral specification | Return / delay slot |
|---|---:|---|---|
| `func_8001514C` | 36 | Add two two-float vectors component by component. | `80015168` / store output component 1 |
| `func_80015170` | 32 | Multiply both components of a two-float vector by a scalar. | `80015188` / store output component 1 |
| `func_80015190` | 48 | Add a scaled two-float offset to a two-float base. | `800151B8` / store output component 1 |
| `func_800152A4` | 40 | Negate all three components of a three-float vector into an output vector. | `800152C4` / store output component 2 |
| `func_800151C0` | 32 | Return the Euclidean length of a two-float vector. | `800151D8` / square-root the accumulated sum |
| `func_80015268` | 32 | Set all three components of a three-float vector from scalar arguments. | `80015280` / store component 2 |
| `func_80015288` | 28 | Copy all three components of a three-float vector. | `8001529C` / store component 2 |
| `func_80015328` | 52 | Add two three-float vectors component by component. | `80015354` / store output component 2 |
| `func_8001535C` | 52 | Subtract the second three-float vector from the first. | `80015388` / store output component 2 |
| `func_80015390` | 48 | Return the dot product of two three-float vectors. | `800153B8` / add the final product |
| `func_800153C0` | 44 | Return the Euclidean length of a three-float vector. | `800153E4` / square-root the accumulated sum |
| `func_800153EC` | 60 | Return the squared distance between two three-float vectors. | `80015420` / add the final squared difference |
| `func_800155C0` | 44 | Multiply all components of a three-float vector by a scalar. | `800155E4` / store output component 2 |
| `func_800155EC` | 68 | Add a scaled three-float offset to a three-float base. | `80015628` / store output component 2 |
| `func_80015694` | 36 | Copy a three-float vector into an indexed record with a 16-byte stride. | `800156B0` / store record component 2 |
| `func_800156B8` | 36 | Copy a three-float vector out of an indexed record with a 16-byte stride. | `800156D4` / store output component 2 |
| `func_800156DC` | 72 | Copy four consecutive 16-byte float records, including each fourth field. | `8001571C` / no-op |
| `func_80015630` | 100 | Form each output component as the weighted sum of corresponding components from two input vectors. | `8001568C` / store output component 2 |
| `func_800152CC` | 92 | Return one only when all three corresponding float components compare equal, otherwise zero. | `80015318` / set result to one |

The apparent entry at `0x80015320` was deliberately excluded: branches from
`func_800152CC` target it as that function's false-return tail, so treating it
as an independent leaf would not meet the boundary standard.

## Caller, callee, and regional evidence

The complete USA `jal` scan found 2, 5, 6, 4, 172, 260, 34, 47, 3, 47, 4,
48, 138, 4, and 1 calls respectively in table order. Representative callers
pass stack or object addresses for vector operands. Calls at
`0x8006BDCC`–`0x8006BF34` confirm the pointer/scalar argument ordering for the
two-float operations. Calls at `0x8003B128`–`0x8003B168` use record indices zero
through three and confirm the 16-byte stride operations. None of the bodies has
a callee; the two lengths use the MIPS `sqrt.s` instruction directly.

Japan and Europe each contain one unique normalized match for every full body,
and the full function bytes are identical in all three retail ROMs. LRG uses
the USA addresses and the same bytes.

| USA | Japan | Europe |
|---|---|---|
| `8001514C` | `8001527C` | `800155DC` |
| `80015170` | `800152A0` | `80015600` |
| `80015190` | `800152C0` | `80015620` |
| `800151C0` | `800152F0` | `80015650` |
| `800152A4` | `800153D4` | `80015734` |
| `80015268` | `80015398` | `800156F8` |
| `80015288` | `800153B8` | `80015718` |
| `80015328` | `80015458` | `800157B8` |
| `8001535C` | `8001548C` | `800157EC` |
| `80015390` | `800154C0` | `80015820` |
| `800153C0` | `800154F0` | `80015850` |
| `800153EC` | `8001551C` | `8001587C` |
| `800155C0` | `800156F0` | `80015A50` |
| `800155EC` | `8001571C` | `80015A7C` |
| `80015694` | `800157C4` | `80015B24` |
| `800156B8` | `800157E8` | `80015B48` |

## Exact compiler status

Direct comparison with the locally installed IDO 5.3 `-O2` profile proves
exact matches for `func_8001514C`, `func_80015170`, `func_80015190`,
`func_800152A4`,
`func_80015268`, `func_80015288`, `func_80015328`, `func_8001535C`,
`func_80015390`, `func_800155C0`, `func_800155EC`, `func_80015694`, and
`func_800156B8`. These 13 functions total 552 bytes. Their independently
mapped Japan and Europe equivalents also compare exactly; LRG uses the same
addresses and bytes as USA. They are substituted into all four unique hybrid
builds.

`func_800151C0`, `func_800153C0`, and `func_800153EC` remain
behavior-recovered only and stay as local assembly in matching builds. The
first two compile four bytes shorter because the recovered source does not
induce an original pipeline `nop`; the third has the expected 60-byte size but
uses a different floating-point schedule. These are direct compiler-comparison
facts, not byte-match claims.

`func_800152CC` is now exact in canonical USA. Its previous 84-byte matcher
range stopped before the shared false-return tail even though the reviewed
boundary table above already recorded the full 92-byte body. Comparing that
full span proves that the existing C emits every original byte. The USA hybrid
build now substitutes it; the comparison builds remain out of scope here.

`func_80015630` is also exact in all four builds.

`func_800156DC` is now exact in all four builds. The recovered source is a
nested pair of counted loops over a four-by-four single-precision array, and
the copy visits every element in row order. The earlier single flat loop over
four 16-byte records was behaviourally equivalent but compiled to an unrolled
140-byte body; the original 72-byte body keeps one outer loop because only the
inner four-element loop was unrolled. This is a general property of the
identified compiler at this optimisation level: a loop whose trip count is a
small literal is unrolled, so a surviving loop that materialises its bound in a
register is evidence of an outer loop in the original source.
