# Selector-state leaf tranche

Status: **three behavior-recovered functions; two byte-matching and one behavior-only**.

The address-based names are retained: selector values `3` and `5` are observed,
but the subsystem that owns these state words is not yet established.

## Boundary and behavioral evidence

Each entry is a direct USA `jal` target and has no callee. `func_80005B1C`
ends at `80005B3C` with a `nop` return delay slot; `func_80005B44` uses early
returns and its non-selected path ends at `80005B70` with a `nop` delay slot;
`func_80005B80` ends at `80005BB0` with a `nop` delay slot. The next
established function begins after the associated delay slot and alignment.

| Function | Bytes | Compact behavioral specification |
|---|---:|---|
| `func_80005B1C` | 40 | For selector 3 or 5, store the supplied signed word in its corresponding state word; ignore other selectors. |
| `func_80005B44` | 52 | Return the state word for selector 3 or 5; return -1 for every other selector. |
| `func_80005B80` | 56 | Clear the state counter and all 75 contiguous four-word records. |

## Caller, global, and regional evidence

The USA direct-call counts are 11, 4, and 10 respectively. Representative
callers at `8006B578` through `8006B5D4` read and update the selector-3 and
selector-5 values; callers at `8001B7A0` and `800443B0` reset the record area.

| USA global | Japan equivalent | Europe equivalent |
|---|---|---|
| selector 3 word `8009A290` | `8009AF80` | `8009F7E0` |
| selector 5 word `8009A28C` | `8009AF7C` | `8009F7DC` |
| record counter `8009A2A0` | `8009AF90` | `8009F7F0` |
| record area `800AF4C0` | `800B2710` | `800B8160` |

All three bodies have a unique normalized Japan and Europe match at the same
ROM and VRAM addresses. The differences are only relocated data addresses;
LRG retains the USA forms. These are structural and relocation facts, not
source-name evidence.

## Exact compiler status

Direct IDO 5.3 `-O2` comparison reproduces `func_80005B1C` and
`func_80005B44` byte-for-byte in USA, Japan, Europe, and LRG after the observed
regional data relocations are supplied. They are integrated into all four
unique hybrid builds.

`func_80005B80` is behavior-recovered only. The current C now preserves the
observed separate record-start and record-end globals and compiles to a
56-byte loop, but its register allocation, pointer update order, and store
offset scheduling still differ from the original; it is not substituted or
counted as a byte match.
