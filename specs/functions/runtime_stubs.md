# Runtime stubs

Status: **byte-matching C; integrated into all four unique exact rebuilds**.

These ten directly called leaves return immediately and have no callees or
global dependencies. Their surrounding systems are not yet identified, so
address-based names are retained.

| Function | Behavior | USA return / delay slot | Japan / Europe VRAM |
|---|---|---|---|
| `func_80006FD4` | Return without changing observable state. | `80006FD4` / no operation | `80006FD4` / `80006FD4` |
| `func_80006FDC` | Return without changing observable state. | `80006FDC` / no operation | `80006FDC` / `80006FDC` |
| `func_80008530` | Return without changing observable state. | `80008530` / no operation | `80008530` / `80008530` |
| `func_80008540` | Consume one pointer argument and return; emitted ABI code homes the argument. | `80008540` / store `a0` at incoming stack offset zero | `80008540` / `80008540` |
| `func_8000C530` | Return without changing observable state. | `8000C530` / no operation | `8000C530` / `8000C530` |
| `func_80033DC4` | Return without changing observable state. | `80033DC4` / no operation | `80034824` / `80038734` |
| `func_8002F1E4` | Return without changing observable state. | `8002F1E4` / no operation | `8002FC44` / `80032784` |
| `func_800390A4` | Return without changing observable state. | `800390A4` / no operation | `80039B04` / `8003DA14` |
| `func_800827C0` | Consume one pointer argument and return; emitted ABI code homes the argument. | `800827C0` / store `a0` at incoming stack offset zero | `80083460` / `80087CA0` |

Every start is a direct `jal` target with one caller, follows a complete prior
return, and has a unique structural equivalent in Japan and Europe. Caller
setup confirms pointer-shaped first arguments for `func_80008540` and
`func_800827C0`; the other prototypes intentionally claim no argument
semantics. Each body is exactly eight bytes.

IDO 5.3 and IDO 7.1 `-O2` reproduce all 48 canonical USA bytes exactly.
Independent comparisons also prove the relocated Japan and Europe functions
and the same-address LRG functions. Their substitution preserves every complete
ROM SHA-1. The lack of game-state effects is an observed property of the
bodies; why these hooks exist is not yet known.
