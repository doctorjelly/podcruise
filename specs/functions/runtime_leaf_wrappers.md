# Runtime leaf-wrapper tranche

Status: **eight byte-matching functions**.

Each is a high-confidence direct USA `jal` target. The listed `jr ra` and
delay slot establish its boundary; callers are direct USA `jal` references.

| Function | Bytes | Return / delay slot | Caller count | Compact behavioral specification |
|---|---:|---|---:|---|
| `func_80014F2C` | 40 | `80014F4C` / subtract | 8 | Return 90.0 minus the float returned by `func_80014D4C`. |
| `func_8002FC58` | 40 | `8002FC78` / subtract | 5 | Return word `D_800D9DBC` minus the signed result of `func_8002FAFC`. |
| `func_80030154` | 32 | `8003016C` / `nop` | 104 | Invoke `func_8002FF38`, then return. |
| `func_80031924` | 32 | `8003193C` / `nop` | 2 | Invoke `func_80031BBC`, then return. |

Japan maps these bodies uniquely to `8001505C`, `800306B8`, `80030BB4`, and
`80032384`; Europe maps them to `800153BC`, `80033218`, `80033714`, and
`80034EE4`. The respective callees relocate consistently: `14D4C` to
`14E7C`/`151DC`, `2FAFC` to `3055C`/`330BC`, `2FF38` to `30998`/`334F8`, and
`31BBC` to `3261C`/`3517C`. The subtraction global relocates to
`800DD02C` in Japan and `800E2A5C` in Europe. These are structural facts,
not semantic naming claims.

The C is independently expressed from these specifications. Direct IDO 5.3
`-O2` comparison reproduces all eight functions byte-for-byte in USA, Japan,
Europe, and LRG with their observed regional relocations.

## Adjacent control-flow leaves

| Function | Bytes | Return / delay slot | Caller count | Compact behavioral specification |
|---|---:|---|---:|---|
| `func_80030274` | 36 | `80030290` / `nop` | 3 | Invoke `func_80030174` with the argument and an address for one local word, then return that word. |
| `func_80030304` | 36 | `80030320` / `nop` | 7 | Invoke `func_8003FB78` with the supplied word and two zero words. |
| `func_800319CC` | 40 | `800319EC` / `nop` | 1 | Invoke `func_80031BBC`, then invoke `func_80031924` with the supplied word. |

Japan maps these three bodies uniquely to `80030CD4`, `80030D64`, and
`8003242C`; Europe maps them to `80033834`, `800338C4`, and `80034F8C`.
Their callees relocate consistently: `30174` to `30BD4`/`33734`, `3FB78` to
`40508`/`44518`, and `31BBC` to `3261C`/`3517C`. `func_80031924` is the
already verified preceding leaf at the corresponding regional address.

## Guarded record and call leaves

| Function | Bytes | Return / delay slot | Caller count | Compact behavioral specification |
|---|---:|---|---:|---|
| `func_80065C50` | 36 | `80065C6C` / `nop` | 2 | If the first pointer is non-null, copy the supplied three-float vector into its offset-0x50 field. |
| `func_80065C74` | 36 | `80065C90` / `nop` | 2 | If the first pointer is non-null, copy the supplied three-float vector into its offset-0x74 field. |
| `func_80086CA0` | 40 | `80086CC0` / `nop` | 1 | Call `func_80038F68` unless the supplied signed word is -1. |
| `func_8008B190` | 32 | `8008B1A8` / `nop` | 1 | Call `func_80093980` with 0x400. |

The first two are called by `func_80076B34`; their conditional branch delay
slots save the return address, and their call delay slots form the respective
field addresses. The last two are called by `func_8005F4D8` and
`func_8002E644`. No globals are accessed. Japan maps the four bodies uniquely
to `800667C0`, `800667E4`, `80087994`, and `8008BE80`; Europe maps them to
`8006B130`, `8006B154`, `8008C180`, and `800906E0`. Callees relocate
consistently in each counterpart.

The C is independently expressed from those observed contracts. Direct IDO
5.3 `-O2` comparison proves all four functions byte-for-byte in USA, Japan,
Europe, and LRG.

## Allocation and dispatch leaves

| Function | Bytes | Return / delay slot | Caller count | Compact behavioral specification |
|---|---:|---|---:|---|
| `func_8002FB18` | 52 | `8002FB40` / restore stack pointer | 2 | Return whether the unsigned supplied word is lower than the current result of `func_8002FAFC`. |
| `func_8002FDBC` | 60 | `8002FDF0` / restore stack pointer | 5 | Call `func_80087E80` on `D_800D9C70` with two zero words, then return whether its result is not -1. |
| `func_8003931C` | 36 | `80039334` / `nop` | 3 | Invoke `func_80039178` on the first argument plus four bytes, with 0x3EC. |
| `func_80039890` | 40 | `800398A8` / `nop` | 1 | Invoke `func_80039768` first with zero and then with 0x400. |

All four are direct USA `jal` targets. The first two retain their callee return
value through the comparison; the last two have the `jr $ra` delay-slot nop.
Japan maps them uniquely to `80030578`, `8003081C`, `80039CC0`, and
`8003A234`; Europe maps them to `800330D8`, `8003337C`, `8003DBD0`, and
`8003E154`. The counterpart callees and the one global relocate consistently.

Direct IDO 5.3 `-O2` comparison proves `func_8002FB18`, `func_8002FDBC`,
`func_8003931C`, `func_80039890`, `func_8000AC90`, and `func_80011EA4`
byte-for-byte in USA, Japan, Europe, and LRG.

## Narrowing and global-dispatch leaves

| Function | Bytes | Return / delay slot | Caller count | Compact behavioral specification |
|---|---:|---|---:|---|
| `func_8000AC90` | 40 | `8000ACB0` / `nop` | 2 | Forward the low 16 bits of the supplied word to `func_8003D488`. |
| `func_80011EA4` | 40 | `80011EC4` / `nop` | 1 | Forward the supplied word narrowed to a signed 16-bit value to `func_80011E54`. |
| `func_80090634` | 44 | `80090658` / `nop` | 12 | Invoke `func_8008C930` on `D_8014C3B8` with two zero words. |
| `func_80093864` | 44 | `80093888` / `nop` | 1 | Invoke `func_8008C930` on `D_8014C4D8` with two zero words. |

All four boundaries are direct USA call targets with a standard non-leaf
return; the branch-free dispatch bodies access no other globals. Japan maps
them to `8000AC90`, `80011EEC`, `80091324`, and `80094554`; Europe maps them
to `8000AC90`, `80012334`, `80095B84`, and `80098DB4`. The wrapper callees
and dispatch globals relocate consistently in each build.

Direct IDO 5.3 `-O2` comparison proves `func_80090634` and
`func_80093864` byte-for-byte in USA, Japan, Europe, and LRG.

## Float quotient leaf

| Function | Bytes | Return / delay slot | Caller count | Compact behavioral specification |
|---|---:|---|---:|---|
| `func_80014D20` | 44 | `80014D44` / `div.s` | 2 | Ask `func_80014CC0` to fill two temporary floats, then return the first divided by the second. |

The boundary is the `jr ra` at `80014D44`; its division is the delay-slot
return value. The USA body allocates a 0x28-byte frame, passes local offsets
0x20 and 0x1C as the two output pointers, and has no other global access.
Japan maps it to `80014E50` (callee `80014DF0`) and Europe to `800151B0`
(callee `80015150`). Direct IDO 5.3 `-O2` comparison proves the independently
written C byte-for-byte in USA, Japan, Europe, and LRG.

## Fixed-tag forwarding leaf

| Function | Bytes | Return / delay slot | Caller count | Compact behavioral specification |
|---|---:|---|---:|---|
| `func_8003F974` | 40 | `8003F994` / `nop` | 1 | Forward the first word, fixed tag `0x416C6C21`, and the second pointer to `func_8003F8FC`. |

The body moves its second incoming argument to the callee's third argument,
loads the fixed 32-bit tag into the second argument, and returns after the
callee. The USA caller is `func_8005C36C` at its `8005CE00` call site; the
boundary and delay slot are directly verified. Japan maps the body to
`80040304` with callee `8004028C`; Europe maps it to `80044314` with callee
`8004429C`. Direct IDO 5.3 `-O2` comparison proves the independently written
C byte-for-byte in all four unique images.
