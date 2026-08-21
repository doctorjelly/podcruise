# Object runtime leaves

Status: **15 byte-matching C functions integrated into exact USA/LRG rebuilds;
five additional functions are behavior-recovered only**.

These are original descriptions derived from the supplied USA, Japan, and
Europe binaries. Address-based names and offset-based fields remain because
the containing types and gameplay meanings are not yet established.

## Boundaries, delay slots, and behavior

`func_80017B7C` is a 44-byte leaf from `80017B7C` through the store in the
return delay slot at `80017BA4`. It stores two float arguments at object
offsets `0x40` and `0x44`, sets bits 0 and 1 in the halfword at offset `0x0C`,
and stores a third float argument at offset `0x48`.

`func_80017BA8` spans 112 bytes through its return delay slot at `80017C14`.
It copies twelve source floats at offsets `0x00`, `0x04`, `0x08`, `0x10`,
`0x14`, `0x18`, `0x20`, `0x24`, `0x28`, `0x30`, `0x34`, and `0x38` to
destination offsets `0x1C` through `0x48` with the same gaps, then sets bits 0
and 1 in the destination halfword at offset `0x0C`.

`func_80017C18` spans 128 bytes through its return delay slot at `80017C94`.
It builds a sixteen-float output from the source object's offsets `0x1C`
through `0x48`, placing the source value at offset `0x1C` in output element 0,
inserting `0.0` at elements 3, 7, and 11, and inserting `1.0` as the final
element.

`func_80017C98` is the same 128-byte object-to-float layout copy at the
relocated neighboring entry, ending at `80017D14`; its regional bodies confirm
the same field offsets and constants.

`func_80017B3C` spans 64 bytes through the return delay slot at `80017B78`.
It forwards two float arguments and a fourth word to `func_8001734C` using the
object substructure at offset `0x1C`, then sets bits 0 and 1 in the object's
halfword at offset `0x0C`.

Each listed start is preserved across all three regions. Direct callers and
complete preceding returns establish the externally called entries. Shared
tails have no direct callers and occur at the same relative offsets in Japan
and Europe.

| Function | Bytes | Behavior | USA return and delay slot | Status |
|---|---:|---|---|---|
| `func_80017B3C` | 64 | Forward two floats and one word to `func_8001734C` using the substructure at `0x1C`, then set low flag bits zero and one. | `80017B74` / no operation | behavior-recovered |
| `func_80017B7C` | 44 | Store three floats into the object and set low flag bits zero and one. | `80017BA0` / store the third float | behavior-recovered |
| `func_80017BA8` | 112 | Copy twelve selected floats into the object substructure and set low flag bits zero and one. | `80017C10` / store the updated flags | byte-matching |
| `func_80017C18` | 128 | Build a sixteen-float output from object fields and fixed zero/one values. | `80017C90` / store source `+0x48` to output element 14 | behavior-recovered |
| `func_80017C98` | 128 | Build the same sixteen-float layout at the neighboring entry. | `80017D10` / store source `+0x48` to output element 14 | behavior-recovered |
| `func_80017DB4` | 40 | Return zero for a null object; otherwise return indexed word data through the pointer at offset `0x18`. | `80017DBC` / form zero, or `80017DD4` / no operation | byte-matching |
| `func_80017F64` | 108 | Ask `func_80016F0C` to fill six floats from the object substructure at offset `0xB0`, then copy the first three floats to one output and the last three to the other. | `80017FC8` / restore stack, or `80017FCC` / no operation | byte-matching |
| `func_80017E88` | 84 | For selector one, classify flag bits `0x08` and `0x40` as zero, one, two, or three; return negative one for a null object or another selector. | `80017EC8` / form two, or `80017ED4` / move the result | behavior-recovered |
| `func_80017EFC` | 16 | Set the supplied bits in the word at offset zero. | `80017F04` / store the result | byte-matching |
| `func_80017F0C` | 20 | Clear the supplied bits in the word at offset zero. | `80017F18` / store the result | byte-matching |
| `func_80017F28` | 60 | Return one of four `0x170`-byte slots rooted at `D_80120DF0`; return null for an index outside zero through three. | `80017F38` / form null, or `80017F5C` / no operation | byte-matching |
| `func_80018114` | 8 | Store a word at offset `0x168`. | `80018114` / store the word | byte-matching |
| `func_8001811C` | 72 | Map selectors four, three, six, and five to word offsets `0x15C`, `0x164`, `0x158`, and `0x160`; other selectors do nothing. | `8001815C` / no operation | byte-matching |
| `func_800182FC` | 40 | Return the word at offset `0x08` for selector zero, the word at `0x04` for selector two, and zero otherwise. | `80018304` / load `0x08`, `80018314` / load `0x04`, or `8001831C` / no operation | byte-matching |
| `func_80018324` | 132 | Initialize flags, two sentinel words, two halfwords, and a word. If bit `0x4000` is set, clear two more words; for flags exactly `0xD065`, also initialize three unit floats and twelve zero floats. | `800183A0` / no operation | byte-matching |
| `func_800183A8` | 8 | Return the word at offset `0x04`. | `800183A8` / load the word | byte-matching |
| `func_800183B0` | 8 | Store a word at offset `0x04`. | `800183B0` / store the word | byte-matching |
| `func_80018440` | 8 | Return without changing observable state. | `80018440` / no operation | byte-matching |
| `func_80018448` | 8 | Return without changing observable state. | `80018448` / no operation | byte-matching |
| `func_80018470` | 16 | Store five in `D_800A21AC`. | `80018478` / store five | byte-matching |

The analyzer's entries at `80017DC4`, `80017ED0`, `80017F40`, `8001830C`, and
`8001831C` are shared/internal tails, not separately recovered C functions.
The byte spans above include those tails. Padding at `800183B8` and after
`func_80018448` is not attributed to either neighboring function.

## Call and regional evidence

The small accessors are leaves, while `func_80017B3C` and `func_80017F64` call
established address-named helpers. `func_80017EFC` and `func_80017F0C` have no
direct `jal` callers in the scanned main code; the older island entries' direct
call counts are shown below. The two globals named above are the only globals
observed in that older subset.

| Function | USA direct callers | Japan / Europe VRAM |
|---|---:|---|
| `func_80017DB4` | 1 | `80017EE4` / `80018244` |
| `func_80017F64` | 2 | `80018094` / `800183F4` |
| `func_80017E88` | 2 | `80017FB8` / `80018318` |
| `func_80017EFC` | 0 | `8001802C` / `8001838C` |
| `func_80017F0C` | 0 | `8001803C` / `8001839C` |
| `func_80017F28` | 10 | `80018058` / `800183B8` |
| `func_80018114` | 1 | `80018244` / `800185A4` |
| `func_8001811C` | 4 | `8001824C` / `800185AC` |
| `func_800182FC` | 20 | `8001842C` / `8001878C` |
| `func_80018324` | 20 | `80018454` / `800187B4` |
| `func_800183A8` | 10 | `800184D8` / `80018838` |
| `func_800183B0` | 1 | `800184E0` / `80018840` |
| `func_80018440` | 1 | `80018570` / `800188D0` |
| `func_80018448` | 1 | `80018578` / `800188D8` |
| `func_80018470` | 2 | `800185A0` / `80018900` |

## Match record

IDO 5.3 with the accepted `-O2` profile reproduces all 656 bytes belonging to
the 15 matching functions exactly. Their same-address LRG bytes also pass an
independent exact comparison, and substitution preserves both full ROM SHA-1
values. The current `func_80017E88` C passes behavioral tests but compiles to
88 bytes and first differs from the 84-byte USA body at offset `0x0C`; it is
not substituted and is not counted as byte-matching. The four other
behavior-recovered entries above are likewise kept out of the split YAMLs.

Observed facts are the instruction boundaries, delay slots, loads and stores,
branch outcomes, callers, globals, and three-region control-flow agreement.
Descriptions such as "slot" and "classify" are behavioral inferences only;
no authored symbol or structure identity is claimed.
