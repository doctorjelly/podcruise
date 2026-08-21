# Object runtime stubs

Status: **byte-matching C; integrated into all four unique exact rebuilds**.

`func_80018450` is a 12-byte leaf at USA `0x80018450`. It accepts two word
arguments and returns without changing game state. The emitted ABI code saves
the first argument to incoming stack offset zero, executes `jr ra`, and saves
the second argument to stack offset four in the return delay slot. The next
instruction at `0x8001845C` is alignment padding, not part of the function.

Its one direct caller passes constant `0xEE06` and a pointer to a stack-backed
record. There are no callees or global references. Unique Japan and Europe
equivalents occur at `0x80018580` and `0x800188E0` with the same instructions.
IDO 5.3 and IDO 7.1 `-O2` reproduce all 12 bytes exactly. Independent compiler
comparisons prove the relocated Japan and Europe equivalents and the
same-address LRG equivalent; substitution preserves every complete ROM hash.
The two-word prototype is inferred from the caller setup and ABI stores; the
arguments' semantics remain unknown.
