# Small global-state leaves

Status: **byte-matching C; integrated into exact USA and LRG rebuilds**.

The descriptions below are original behavioral specifications derived from the
three supplied retail binaries. They intentionally record compact facts rather
than generated disassembly.

## Shared boundary and regional evidence

- Every USA start is a direct call target and follows the return sequence of
  the preceding function. `func_8007EE40` additionally has one alignment word
  between that preceding delay slot and its start.
- Every body is a leaf with no call instruction. The listed terminal return and
  its executed delay slot account for the end of each function.
- Each Japan and Europe location is a unique normalized structural match. Each
  is also a direct call target in that build, with the same number of direct
  callers as USA, and preserves the USA control-flow and delay-slot roles.
- Changed upper/lower address operands resolve to relocated regional globals;
  they are not behavioral differences.

| Function | Bytes | USA / Japan / Europe VRAM | Terminal return | Executed delay slot |
|---|---:|---|---|---|
| `func_80005AFC` | 32 | `80005AFC` / `80005AFC` / `80005AFC` | `80005B14` | no operation |
| `func_80008750` | 16 | `80008750` / `80008750` / `80008750` | `80008758` | store the low input byte |
| `func_80008F58` | 20 | `80008F58` / `80008F58` / `80008F58` | `80008F64` | store the second float |
| `func_800117E4` | 12 | `800117E4` / `800117E4` / `80011C74` | `800117E8` | store the input float |
| `func_80011814` | 16 | `80011814` / `80011814` / `80011CA4` | `8001181C` | store byte value one |
| `func_80011918` | 16 | `80011918` / `80011918` / `80011DA8` | `80011920` | store word value one |
| `func_80011ECC` | 28 | `80011ECC` / `80011F14` / `8001235C` | `80011EE0` | store the second halfword |
| `func_80011EE8` | 28 | `80011EE8` / `80011F30` / `80012378` | `80011EFC` | copy the second halfword to its output |
| `func_8005D310` | 20 | `8005D310` / `8005DEB8` / `800627F4` | `8005D31C` | store the second word |
| `func_80065804` | 12 | `80065804` / `80066374` / `8006ACE4` | `80065808` | store the input word |
| `func_8007EE40` | 12 | `8007EE40` / `8007FAE0` / `80084320` | `8007EE44` | load the returned float |
| `func_800811C0` | 12 | `800811C0` / `80081E60` / `800866A0` | `800811C4` | store the input double |
| `func_800811CC` | 16 | `800811CC` / `80081E6C` / `800866AC` | `800811D4` | store word value one |
| `func_80081260` | 12 | `80081260` / `80081F00` / `80086740` | `80081264` | clear one word |
| `func_80086CC8` | 24 | `80086CC8` / `800879BC` / `8008C1A8` | `80086CD8` | store the third halfword |

The return addresses in that table are USA addresses. The Japan and Europe
equivalents have the same instruction offsets within their respective bodies.

## Behavior and global evidence

| Function | Compact behavioral specification | USA / Japan / Europe global address |
|---|---|---|
| `func_80005AFC` | If the signed word is positive, subtract one; otherwise leave it unchanged. | `8009A29C` / `8009AF8C` / `8009F7EC` |
| `func_80008750` | Replace one byte with the low eight bits of the first integer argument. | `8009A324` / `8009B014` / `8009F874` |
| `func_80008F58` | Store two float arguments into two adjacent float locations in argument order. | `8009AD08` / `8009B9F8` / `800A0258` |
| `func_800117E4` | Store the float argument. | `8009B880` / `8009C570` / `800A0DD0` |
| `func_800117A4` | Clamp a signed value at 0x50 when it is at least 0x51, store it, then refresh the related state through `func_800116E8`. | `8009B884` / `8009C574` / `800A0DD4` |
| `func_80011838` | Initialize twenty records: clear four bytes and set four words to -1 per record. | `800D6140`, `800D68C0`, `800D6910` |
| `func_80011814` | Set one byte to one. | `8009B870` / `8009C560` / `800A0DC0` |
| `func_80011918` | Set one 32-bit word to one. | `8009B810` / `8009C500` / `800A0D60` |
| `func_80011ECC` | Store the low 16 bits of two arguments into adjacent signed-halfword locations. | `800A1CD0` / `800A4A3C` / `800A7220` |
| `func_80011EE8` | Copy those two signed halfwords to the two output pointers. | `800A1CD0` / `800A4A3C` / `800A7220` |
| `func_8005D310` | Store two 32-bit arguments into adjacent word locations in argument order. | `800A59FC` / `800A8844` / `800AACFC` |
| `func_80065804` | Store the first 32-bit argument unchanged. | `8011C840` / `8011FAB0` / `801254E0` |
| `func_8007EE40` | Return one float without changing memory. | `800A6700` / `800A9550` / `800ABA00` |
| `func_800811C0` | Store the double argument. | `800A6750` / `800A95A0` / `800ABA50` |
| `func_800811CC` | Set one 32-bit word to one. | `800A6758` / `800A95A8` / `800ABA58` |
| `func_80081260` | Clear one 32-bit word. | `800A675C` / `800A95AC` / `800ABA5C` |
| `func_80086CC8` | Store the low 16 bits of three arguments into adjacent signed-halfword locations. | `801488B8` / `8014BB28` / `80151558` |

For a row describing adjacent values, the table gives the address of the first
element. The subsequent elements follow at their natural 2- or 4-byte stride.

## Caller and callee review

The USA direct call sites were inspected with their argument-producing and
delay-slot instructions. No body above calls another function.

| Function | USA direct callers | Relevant caller observation |
|---|---|---|
| `func_80005AFC` | `80003FBC`, `80004F6C` | Both calls are conditional on the same tested flag bit and ignore a return value. |
| `func_80008750` | `80040DFC`, `80040E1C`, `80044384`, `80052F60` | Observed inputs include zero and `0x7F`; no caller consumes a return value. |
| `func_80008F58` | `80030EB8` | The call passes floating-point arguments; the second is loaded as `300.0f`. |
| `func_800117E4` | `80054240`, `800542CC`, `8005D854`, `8005DA24` | Observed values are `1.0f` and `7.0f`; no return value is consumed. |
| `func_80011814` | `80043898`, `8005D844` | Both are argument-free state-setting calls. |
| `func_80011918` | `80052F8C` | The call occurs beside other global clears and takes no argument. |
| `func_80011ECC` | `8003E414`, `8003E490`, `8003E8D0`, `8003E980` | Callers sign-extend or load both arguments as halfwords. |
| `func_80011EE8` | `8003E478` | The caller passes two stack halfword addresses, then reads both results. |
| `func_8005D310` | `8005E184` | The same two word arguments are also passed to the neighboring routine immediately beforehand. |
| `func_80065804` | `8005ED38` | The existing first integer argument is forwarded unchanged. |
| `func_8007EE40` | `800548FC`, `8006DBAC`, `8006FA6C` | Each caller uses the floating-point return path and passes no argument. |
| `func_800811C0` | `800313B4` | The caller constructs a double in the first floating-point argument pair. |
| `func_800811CC` | `8004547C`, `8005303C`, `8005D020` | All are argument-free state-setting calls. |
| `func_80081260` | `80081378` | The argument-free call precedes another routine in the same subsystem. |
| `func_80086CC8` | `80030F48`, `8004345C`, `8004AFA4`, `8005E9CC`, `80060D54` | Callers pass either three zeroes or three word values; only the low halfwords are stored. |

## Facts, inferences, and matching status

Facts are the addresses, access widths, control flow, call sites, and regional
instruction-shape agreement recorded above. The signed comparison in
`func_80005AFC` and the floating-point load/store classes directly constrain
those C types.

Exact compilation showed that `D_8009AD08`/`D_8009AD0C` and
`D_800A59FC`/`D_800A5A00` must remain distinct declarations: array expressions
produce different address construction. The halfword pairs and triple retain
array declarations because those expressions match. No broader purpose is yet
established, so address-based names remain.

The independently written functions described above match all 276 canonical
USA bytes under IDO 5.3 `-O2`, including every delay slot. The same-address LRG
bytes pass an independent exact comparison. They are substituted along with the
bootstrap functions in both byte-identical rebuilds.
