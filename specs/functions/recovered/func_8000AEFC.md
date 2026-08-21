# func_8000AEFC — entry-table field writer

## Boundary

- USA VRAM range: `0x8000AEFC` .. `0x8000AF4B`, **size 80 bytes**,
  20 instructions, ROM `0xBAFC`.
- Single return point at `0x8000AF44`; its delay slot holds the final word
  store, which is therefore part of the function.
- Boundary confirmed correct: 37 direct call sites target `0x8000AEFC`, the
  preceding function (`func_8000AED4`) closes with its own return plus store
  in the delay slot at `0x8000AEF8`, and nothing branches into this range from
  outside. The next function begins at `0x8000AF4C`.

## Callers

37 direct call sites. Four arguments.

## Callees

None; leaf, no stack frame. Arguments one, two and four are written to their
incoming home slots, which is the compiler's signature for sub-word parameter
types; argument three is not spilled, so it is a full 32-bit value. Consistent
with this, arguments two and four are stored with 16-bit stores while argument
three is stored with a 32-bit store.

## Globals and access widths

| symbol | access | note |
|---|---|---|
| `D_8009B790` | address materialised once, then re-loaded as a 32-bit pointer before each of the three stores; 16-bit stores at element offsets +0x06 and +0x04, 32-bit store at +0x08 | same 124-byte-stride table as `func_8000AED4` |

The base pointer is deliberately re-read between stores because each store may
alias the pointer variable itself; only the scaled element offset is computed
once and reused. The stride is index x 31 x 4 = 124 bytes.

## Regional addresses

| version | vram | rom | `D_8009B790` |
|---|---|---|---|
| us | 0x8000AEFC | 0xBAFC | 0x8009B790 |
| jp | 0x8000AEFC | 0xBAFC | 0x8009C480 |
| eu | 0x8000AEFC | 0xBAFC | 0x800A0CE0 |
| lrg_rev1 | 0x8000AEFC | 0xBAFC | 0x8009B790 |

Each regional body was read independently and is otherwise identical to the
USA body.

## Recovered behaviour

Writes three fields of one entry in the 124-byte-stride table addressed by the
pointer `D_8009B790`. The entry is selected by a signed 16-bit index in the
first argument.

The three writes happen in this order, and the order is observable because the
base pointer is re-read from memory before each one:

1. the 16-bit field at entry offset 0x06 receives the fourth argument;
2. the 16-bit field at entry offset 0x04 receives the second argument;
3. the 32-bit field at entry offset 0x08 receives the third argument.

That the second and fourth arguments land in fields at offsets 0x04 and 0x06
respectively — i.e. reversed with respect to the argument order — is a real
property of the original source and not an artefact of scheduling.

No bounds check, no null check, no return value.

## Status

Exact. Byte-identical against USA, Japan, Europe and lrg_rev1 at 80 bytes,
first attempt.
