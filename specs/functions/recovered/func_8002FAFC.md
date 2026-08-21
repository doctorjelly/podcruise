# func_8002FAFC

## Boundary

- USA VRAM range 0x8002FAFC .. 0x8002FB17 inclusive, ROM 0x306FC, **28 bytes**
  (7 instructions).
- The assignment file gave 56 bytes. **Boundary corrected**: the inventory
  merged this function with the one that follows. The body ends with the return
  at 0x8002FB10 whose delay slot at 0x8002FB14 performs the final load; the
  next function begins at 0x8002FB18 with a stack-frame prologue and is a
  caller of this one.
- No stack frame.

## Callers and callees

- Forty direct call sites in the USA build. Callees: none (leaf).
- The immediately following function compares its own unsigned argument
  against this function's result, so the result is used as an unsigned 32-bit
  quantity.

## Globals and access widths

- `D_800A2868` - 32-bit signed integer, read with a word load. Used as an
  index.
- `D_800D9DD8` - array of 32-bit words, read with a word load at the scaled
  index. Read only.

## Arguments and result

No arguments. Result is one 32-bit word from the table.

## Recovered behavior

A table accessor: it reads a global index and returns the entry of a global
word table that the index selects. There is no bounds check and no other
effect.

## Regional forms

- Japan: 0x8003055C, ROM 0x3115C, 28 bytes - identical sequence with the index
  variable at 0x800A55D8 and the table at 0x800DD048.
- Europe: 0x800330BC, ROM 0x33CBC, 28 bytes - identical sequence with the index
  variable at 0x800A7E68 and the table at 0x800E2A78.
- lrg_rev1 shares the USA addresses and symbol addresses and matches there too.

## Status

exact - byte identical in USA, Japan, Europe and lrg_rev1.
