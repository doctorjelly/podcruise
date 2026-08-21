# func_80016CAC

## Boundary

USA VRAM 0x80016CAC-0x80016D77 (204 bytes, ROM 0x178AC). The last instruction
pair is the return with a floating-point store in its delay slot, so the
labelled range is a complete function. Thirty-five direct call sites in the USA
build target 0x80016CAC itself; no branch from the preceding function reaches
into the range and no instruction precedes the first load. The assigned
boundary is correct.

## Callers

Thirty-five direct callers across the whole image (the assignment file counted
nineteen; the disassembly reader finds thirty-five). Typical call sites load a
destination pointer and a source pointer into the first two argument registers
and pass a stack-resident matrix as the third argument.

## Callees

None. Leaf function, no calls, no saved registers.

## Globals

None referenced. All three operands arrive as pointers.

## Regional addresses

| version | entry | ROM | size |
| --- | --- | --- | --- |
| us | 0x80016CAC | 0x178AC | 204 |
| jp | 0x80016DDC | 0x179DC | 204 |
| eu | 0x8001713C | 0x17D3C | 204 |
| lrg_rev1 | 0x80016CAC | 0x178AC | 204 |

All three regional bodies were read independently and are instruction-for-
instruction the same shape as the USA body (only the entry address moves).

## Recovered behavior

The function applies an affine transform to a three-component vector.

Arguments are, in order, a destination vector of three single-precision floats,
a source vector of three single-precision floats, and a four-by-four matrix of
single-precision floats whose fourth row holds the translation.

For each of the three output components the function forms the sum of three
products - the source component times the matching matrix entry from each of
the first three rows - and adds the translation entry from the fourth row of
the same column. The three results are computed into local temporaries before
any of them is written back, so the destination may safely be the same object
as the source: the second output never sees a partially updated input.

Only the first three columns of the matrix are read; the fourth column and the
fourth component of the vectors are untouched.

## Source shape notes

The translation term is the *last* addend of the expression, not the first.
Writing it as `translation + (a*b + c*d + e*f)` produces the same arithmetic but
reverses the operand order of the final two additions and of the third product,
and costs two scheduling gaps (208 bytes). Writing the four terms as one flat
left-to-right sum with the translation last is byte-exact.

## Status

exact - byte-identical in USA, Japan, Europe and lrg_rev1 under the accepted
ido53_o2 profile.
