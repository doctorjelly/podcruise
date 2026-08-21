# func_8008AB0C

## Boundary

- USA VRAM range: 0x8008AB0C .. 0x8008AB44 inclusive (0x3C = 60 bytes, 15 instructions).
- USA ROM offset: 0x8B70C.
- Ends with a return whose delay slot produces the high half of the result, so
  that instruction belongs to the function.
- Self-contained: no branch from the previous function enters the range, and the
  one internal branch target is inside it. Assigned size 60 was correct.

## Callers and callees

- One direct call site. Leaf function.
- Two 64-bit unsigned arguments, each arriving as a register pair; returns a
  64-bit unsigned value as a register pair. No stack frame is created: the four
  argument registers are written into the caller-provided home slots and read
  back as two 64-bit quantities, which is how a 32-bit ABI reassembles 64-bit
  arguments.

## Globals and access widths

None.

## Regional addresses

Body is instruction-for-instruction identical in all four versions.

| version  | VRAM       | ROM     |
|----------|------------|---------|
| us       | 0x8008AB0C | 0x8B70C |
| jp       | 0x8008B7FC | 0x8C3FC |
| eu       | 0x8009005C | 0x90C5C |
| lrg_rev1 | 0x8008AB0C | 0x8B70C |

## Recovered behavior

The 64-bit unsigned remainder helper. It divides the first argument by the
second and returns the remainder. The divide-by-zero trap that follows the
divide instruction is the assembler's standard guard, not source-level code.

Its sibling at 0x8008AB48 is the matching quotient helper: same body, but it
takes the quotient half of the divide result.

## Toolchain note (important for the orchestrator)

This unit cannot be built with the shared `ido53_o2` flag list. Under `-mips2`
the compiler lowers a 64-bit remainder into a call to this very routine, so the
translation unit that defines it must have been built with the 64-bit
instruction set enabled. The flags that reproduce it byte-for-byte are the
profile flags with `-mips2` replaced by `-mips3 -32`:

    -G 0 -O2 -mips3 -32 -non_shared -Xcpluscomm -signed -Wab,-r4300_mul

`tools/verify_c_matches.py` already supports a per-unit `flags` override for
exactly this case, and the result JSON carries that list in every unit. The
compiler prints one warning ("-mips3 should not be used for ucode 32-bit
compiles") and exits successfully.

## Status

Exact. Byte-identical in USA, Japan, Europe and the large-cartridge revision,
with the per-unit MIPS III flag override.
