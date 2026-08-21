# Per-function recovery specifications

One file per recovered function, written before its C was written. Each records
the verified boundary and return delay slot, the callers and callees that fix
the prototype, the globals and their access widths, the Japan/Europe addresses,
the behaviour in plain language, and the byte-match status.

These are original prose. They contain no instruction listings, no register
transcripts, and nothing copied from a disassembler, a decompiler, or a
prior-art repository; that is a hard requirement of `docs/IP_POLICY.md` and is
checked before anything lands here.

The older grouped specifications in the parent directory cover the first
tranche and remain authoritative for the functions they name.
