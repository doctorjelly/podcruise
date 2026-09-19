# `func_8002E2FC` USA compiler audit

The current IDO 5.3 `-O2 -mips2` source compiles to 456 bytes against the
440-byte ROM body, with 108 differing comparable words, four extra words, and
a first byte difference at `0x05`. The canonical body saves and carries the
queue object and message pointer in `s3`/`s4` before the first receive; the C
build uses transient `a0`/`a1` and materializes more addresses after it.

An explicit initial receive followed by a bottom-tested `do` loop compiled
identically to the top-tested source. The source was restored. The next useful
test needs evidence for the persistent register lifetimes/address reuse; a
mere loop-spelling change does not recover this body.
