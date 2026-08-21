# Runtime-wrapper leaf tranche

Status: **four behavior-recovered candidates; exact status pending compiler comparison**.

All are direct USA `jal` targets with no local callee other than the one target
shown below. The listed return `jr ra` and `nop` delay slot establish each end.

| Function | Bytes | Return / delay slot | Compact behavioral specification |
|---|---:|---|---|
| `func_80008610` | 32 | `80008628` / `8000862C` | Invoke `func_80007218`, then return. |
| `func_800086F8` | 32 | `80008710` / `80008714` | Invoke `func_80007A44`, then return. |
| `func_800117F0` | 36 | `8001180C` / `80011810` | Clear byte `D_8009B870`, invoke `func_800116E8`, then return. |
| `func_800118F8` | 32 | `80011910` / `80011914` | Invoke `func_8000F5A0`, then return. |

USA direct-call counts are 1, 2, 2, and 1. The Japan and Europe bodies uniquely
normalize to the first two at their USA addresses. The latter pair map uniquely
to Japan `800117F0`/`800118F8`; Europe relocates them to
`80011C80`/`80011D88`. Japan relocates the cleared byte to `8009C560`; Europe
relocates it to `800A0DC0`. These observations establish structure and data
relocation, not semantic names.

The C is independently expressed from this specification. Its exact status is
recorded only by the per-version compiler verifier.
