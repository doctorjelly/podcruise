# func_8008EEE4

## Boundary

USA VRAM 0x8008EEE4-0x8008F0B4, ROM 0x8FAE4, 464 bytes (116 instructions).
The assigned boundary is correct. The body ends with a return whose delay slot
is empty, preceded by the stack-pointer release; the previous function ends
with its own complete return sequence immediately before this entry, and both
direct calls target 0x8008EEE4. Every branch inside the body stays inside the
range: the two early exits both jump forward to the shared epilogue at
0x8008F0A4, which is inside the function. Frame is 0xE8 bytes.

## Calling convention (the reason this looked hand-written)

Four inputs: a sample count in the first ordinary argument register, two
floating-point values in the second floating-point argument register and in the
first floating-point temporary pair after it (not the first argument pair), and
an output pointer in a callee-saved register. Three callee-saved integer
registers and two callee-saved floating-point registers are destroyed without
being saved. That is not the ordinary convention, which is why the body was
never attempted; it is the same whole-unit register allocation seen elsewhere
in this file, produced by building the translation unit one optimisation level
above the rest of the ROM. The interface agrees with what the worker on
func_8008F0B4 measured from the call sites.

Reproducing it needs the routine to stay file-local and to have a caller in the
same unit that calls it at least twice; with a single call site the compiler
inlines it away and emits no out-of-line body at all.

## Callers

Two direct calls, both inside func_8008F0B4 (0x8008F1BC and 0x8008F214). Each
site loads the sample count from a word of the object being serviced, converts
two 16-bit fields of that object to floating point for the two ratio terms,
points the output argument at a 16-bit field of the same object, and stores the
returned value into the neighbouring 16-bit field. The pair of stores is a
16.16 value split across two halfwords: this routine returns the integer part
and writes the fractional part through the pointer.

## Callees

One: func_8008ED18, an ordinary O32 routine taking a double in the first
floating-point argument register and a pointer in the third integer argument
register, returning a double. It splits its argument into a mantissa and a
power of two, writing the exponent through the pointer - the classic frexp
interface. The recovered code relies only on that contract.

## Globals and access widths

- D_800A7E80: sixty-four bytes, read as one whole-object copy into a local.
  Its eight doubles are the base-two logarithms of the midpoints of the eight
  mantissa buckets between one half and one, so it is the upper half of a
  sixteen-entry logarithm lookup table.
- D_800ADF30: one double, read once. Its value is the natural logarithm of two,
  used to turn a base-two logarithm into a natural one.
- D_800ADF38: one double, read once. Its value is 65535, the scale applied to
  the fractional part before it is stored.

The output pointer is written as a 16-bit halfword, three times on mutually
exclusive paths.

## Regional addresses

Japan 0x8008FBD4 (ROM 0x907D4), Europe 0x80094434 (ROM 0x95034),
lrg_rev1 0x8008EEE4 (ROM 0x8FAE4). All three bodies were read and compared word
by word against the USA body. lrg_rev1 is identical over all 464 bytes. Japan
and Europe differ in exactly five words, all of them relocated addresses:

- table base: Japan 0x800AACD0, Europe 0x800AD180
- splitting routine: Japan 0x8008FA08, Europe 0x80094268
- logarithm-of-two constant: Japan 0x800B1180, Europe 0x800B6BD0
- fractional scale constant: Japan 0x800B1188, Europe 0x800B6BD8

The structure is otherwise identical, so one source serves all four ROMs.

## Recovered behaviour

The routine computes, for a volume ramp, the per-step multiplier that carries a
current level to a target level over a given number of steps, and returns it as
a 16.16 fixed-point value split between the return value (integer part) and the
halfword written through the pointer (fractional part).

If the step count is zero there is no ramp to compute. The routine then reports
a saturated result when the level is rising or level - full integer part and
full fractional part - and zero in both places when it is falling.

Otherwise both terms are first made safe for a logarithm: a target below one is
raised to one, and a current level of zero or less is replaced by one.

The number of doublings is fixed by taking the reciprocal of the step count in
a fixed-point scale of 2^30, which gives how many times a multiplier of the
form one-plus-epsilon must be applied to reach the whole ramp.

The natural logarithm of the ratio between the two levels is then obtained from
the table: the ratio is split into a mantissa and a power of two, the top four
bits of the mantissa select a table entry holding the base-two logarithm of
that bucket, the power of two is added, and the sum is multiplied by the
logarithm of two. Dividing by the same fixed-point scale gives a very small
epsilon, so that one plus epsilon raised to the number of doublings
approximates the ratio raised to the reciprocal of the step count.

That power is evaluated by ordinary binary exponentiation: an accumulator
starts at one, the running factor is squared each round, and the accumulator is
multiplied by the factor whenever the corresponding bit of the exponent is set.

The result is then squared three times, giving the multiplier for a block of
eight samples rather than one, which is the granularity the mixer works at.

Finally the multiplier is split: its integer part, narrowed to sixteen bits, is
the return value, and the remainder above that integer part, scaled by 65535,
is written through the pointer.

## Status

Behaviour recovered and reviewed; not byte-exact. Built at the optimisation
level the unit needs, the recovered source produces 115 of the original's 116
instructions, in the same order, with the same frame size (0xE8), the same
stack offsets for both addressed locals (the table copy at sp+0x68 and the
exponent at sp+0xB0), the same three floating-point constant materialisations,
the same table copy, the same call, the same exponentiation loop and the same
final split. The first fifty-three instructions are byte-identical apart from
the naming of two registers.

The one remaining difference is a single register copy. The original truncates
the doubling count straight into the register it keeps it in and leaves the
call's delay slot empty; the rebuild truncates into a second callee-saved
register and copies it in the delay slot. That extra register pushes every
later callee-saved allocation up by one, which is what makes the output pointer
land one register above the original's, and shifts everything after the call by
one instruction. Thirty source shapes were tried against it - statement order
around the call, a separate loop variable, a named double for the truncated
expression, every declaration order, loop form and flag combination - and none
of them moves it.

Three findings that were needed to get this far, and that are reusable:

1. An integer constant that reaches a floating-point conversion from a
   different basic block is materialised into a register and converted at run
   time, rather than folded into a floating-point literal. Declaring the
   constant as an ordinary initialised local above an early return reproduces
   that exactly; writing the literal in place does not.
2. A float literal assigned to a double variable is materialised as a fresh
   double constant instead of being shared with the double literal of the same
   value already held in a register. That is what produces the second and third
   materialisations of one in the original, and it is also what stops the
   redundant multiplication by one in the scale expression from being folded
   away.
3. Locals reserve stack space in declaration order from the top of the frame
   downwards, each aligned to its own requirement, and the frame is the rounded
   total plus sixteen bytes. That makes the frame size and the two visible
   stack offsets a direct measurement of the original's declaration list: the
   original reserved 128 bytes for the table area while loading and addressing
   only the upper 64, which is consistent with a sixteen-entry table whose
   lower half is unreachable.
