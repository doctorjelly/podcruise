# Source-recovery execution plan

This replaces the earlier per-function plan, which is now spent: the leaf
tranche it described is finished and its counting conventions have been
retired in favour of generated ledgers.

## Where the project actually stands

Read these before anything else; all three are generated, so they cannot drift
from what was proved:

- `analysis/source_manifest.json` (`make manifest`) — every function with
  reviewed C, and which builds reproduce it exactly.
- `analysis/c_matches.*.json` (`make match-c`) — the per-version byte
  comparison behind those claims.
- `analysis/non_c_functions.json` (`make classify`) — the bodies no C input can
  produce, each with its decisive instruction class.

The definition of progress is unchanged: reviewed C that rebuilds the canonical
USA ROM byte-for-byte, with Japan, Europe and the LRG revision independently
verified rather than inferred. An exact assembly round trip is infrastructure,
not decompilation.

## What the last tranche established about the compiler

The accepted profile is IDO 5.3 with
`-G 0 -O2 -mips2 -non_shared -Xcpluscomm -signed -Wab,-r4300_mul`.

Two facts changed how everything else is read.

**The multiply workaround is part of the original build.** The USA image
contains no adjacent floating-point multiply pair and 218 nop-separated pairs.
Adding `-Wab,-r4300_mul` cost nothing and dissolved an entire class of
near-misses that had previously been recorded as unexplained.

**Objects were not all built the same way.** A matching unit may carry its own
`flags`, replacing the profile flags for that translation unit, and its own
`rodata_vram` when the original object had a floating-point constant pool. The
recovered set already contains objects built at `-O1`, at `-O3`, with
`-Wo,-loopunroll,0`, and for MIPS III. When a body is behaviourally right but
structurally wrong in a way no source shape fixes, the flags are the next
hypothesis, not the last.

## The commonest wrong verdict: `-O3` mistaken for assembly

Compiled at `-O3`, IDO allocates registers across a whole translation unit. A
**file-local** function then takes its arguments in whatever registers suit —
`$s0` onwards, sometimes a scratch register the caller holds live across the
call — clobbers callee-saved registers the caller reloads anyway, and is
emitted with **no ELF symbol**. Every one of those looks like hand-written
assembly and none of it is.

`func_8008E420` was retired as "does not use the calling convention at all" and
turned out to be an ordinary seven-parameter `static` function: written that way
beside a caller and compiled at `-O3`, it reproduces the register assignment,
the dead home stores, the frame and the length on the first attempt, while the
same source at `-O2` produces a plain O32 function. A scan for callee-saved
live-ins finds thirteen such bodies, so this is a category rather than a
curiosity.

Scanning for the signature — a callee-saved register read before it is
written, ignoring the ordinary prologue save — finds five candidates that are
called at least once, end in a return, and are not yet recovered:
`func_80088B70` (124 bytes), `func_8008EEE4` (464), `func_8008F0B4` (664),
`func_80096E90` (1,384) and `func_80092B10` (1,648). The scan also produces a
long tail of bodies with no callers whose live-in is a temporary register;
those are mis-split blob interiors where the label starts mid-function, not
evidence of anything, and they are why the scan is a prompt to look rather than
a verdict.

### An `-O3` unit cannot be recovered one function at a time

This is the method change the finding forces. Under interprocedural allocation
a file-local function's register interface is a property of the *whole
translation unit*, not of the function. Three results make that concrete:

- `func_8008E420` matched only as a `static` function beside a stand-in caller.
- `func_80096E90` needed a caller with **two or more** call sites: with exactly
  one, the compiler inlines the body and emits no out-of-line copy at all. The
  corollary is a trap — a tiny body that does nothing and has no callers is
  often the *residue* of a routine that was inlined away, not a function.
  `func_800973F8` is one, and the classification already excludes it.
- `func_8008F0B4` needed three things in one unit: itself `static`, a stand-in
  caller, and a stand-in for the sibling it calls, shaped to clobber exactly
  the registers the real sibling clobbers. It avoids three registers across
  calls *because of what its neighbour destroys*.

So these should be worked as objects, not as functions: identify the unit's
members from the alignment padding around them, recover them together, and
delete the stand-ins as the real neighbours arrive. Each stand-in removal
changes the body's `text_offset`, which is expected.

Two consequences for the tooling, both now in place: a unit may carry its own
`flags` to select `-O3`, and a unit whose function has no symbol states
`text_offset` so the verifier can locate the body without a name. That
comparison is byte-for-byte as usual, but it cannot independently confirm the
compiled length, so each result records whether its size came from a symbol.

## What is genuinely not C, and why that list must stay short

The accepted compiler has **no inline assembly** in any spelling: `asm`,
`__asm` and `__asm__` are parsed as calls to an undeclared function and emit no
instruction, `asm volatile` is a syntax error, and `#pragma asm` / `#pragma
endasm` is accepted but produces nothing. So a body that transfers a
coprocessor-0 register, performs cache maintenance, or touches `$k0`/`$k1`
cannot be the output of any C translation unit. That is a capability limit, not
an optimisation the compiler declined to make, and `make classify` records it
per function.

Trapping arithmetic is decisive for a different reason. C addition may not
trap, so the compiler emits only `addu`/`addiu`/`subu`; the whole USA text
contains a handful of trapping forms and every one of them is in a body that is
hand-written on independent grounds. The clearest single proof found so far is
a block-copy routine that forms one address with a trapping `add` and the same
address elsewhere with `addu` — no one C source produces both.

Everything else is recoverable. These were each checked against the compiler
and are **not** grounds for retiring a function:

| Signal | What it actually means |
|---|---|
| `lwl` / `lwr` / `swl` / `swr` | a word moved through a byte-aligned type |
| `cfc1` / `ctc1` | a plain `(unsigned)float` cast, saving the rounding mode |
| `ld` / `sd` / `dsll` | a translation unit built for MIPS III |
| `break` | the divide-by-zero trap |
| the listing's "Handwritten function" note | a heuristic, wrong in both directions |

This matters because the previous tranche retired several recoverable functions
on exactly these signals. Treat the disassembler's marker as a prompt to look,
never as an answer.

## Work remaining, by shape

`make classify` separates the remaining assembly into work of different kinds.
They are not one queue, and treating them as one wasted effort in an earlier
tranche:

1. **Genuine C still to recover.** 163 functions / 44,312 bytes in the 8-400
   byte band with a confirmed return, a direct caller and no branch entering
   from outside. Staged as `batch_01`..`batch_41`, four per worker. This is the
   default work.
2. **Behaviour-only units already measured.** 56 functions /
   12,168 bytes have reviewed C that does not
   yet reproduce the bytes. **29 of them are already the correct
   size**, differing only in register allocation or scheduling — these are the
   cheapest remaining wins, and several have a documented near-miss recording
   what was already ruled out. Prefer them over fresh functions when a worker
   has budget.
3. **Boundary errors, not functions.** 84
   bodies reached only by a branch from a neighbour and never called. Half are
   already inside a recovered unit, the stale label simply persisting. The rest
   are absorbed by correcting a parent's extent.
4. **Not main-processor code at all.** 453
   bodies / 209,784 bytes are never called, never
   branched to, and never have their address taken. Nothing reaches them as
   functions: they are data, signal-processor programs and asset payloads that
   the coarse interval swept up. **This is now the largest single category by
   bytes** and none of it is decompilation work.
5. **Proven non-C.** 27 bodies / 4,608 bytes
   that no C input can produce, each with a decisive instruction class. Finished
   work, not backlog.

Item 4 is the one that changes the shape of the project rather than adding to
the count. Until the interval is segmented, bodies from those regions keep
arriving on the C queue, and no honest total percentage exists because the
denominator is not yet code.

### The `0x80088000` library boundary: not supported by the evidence

I proposed this boundary earlier from a coarse reading of where the
differently-built units sat, and suggested the code above it might be a
prebuilt third-party library that should stay as assembly. Measuring it
properly does not support that, and the idea should be dropped rather than
carried forward.

Two facts settle it. First, **73 units at or above `0x80088000` are built with
the ordinary default profile**, starting at `0x80088020` — if that region were
a separately supplied library, its own build settings would not coincide with
the game's for three quarters of its units. Second, the differently-built units
do not form one block above a line; they form **four separated clusters**
(`0x80088150`-`0x8008AE30`, `0x8008C090`-`0x8008F0B4`,
`0x80092850`-`0x80093FB4`, `0x80096930`-`0x80097D70`) with default-built code
between them, plus **one outlier far below at `0x80009B8C`**. That is the
signature of individual object files compiled with individual settings, which
is ordinary for any large program, not of a boundary between two suppliers.

The runtime and platform code up there is still recognisably a distinct layer
by *content* — exception vectors, cache maintenance, threads, formatted output.
But content is not provenance, and no address in the image marks a supplier
change. So there is no defensible line to draw, and the recovered functions
above `0x80088000` should stay.

The only material that genuinely is not the game's own code is what
`make classify` already isolates on instruction evidence, and the signal
processor's program identified below.

### The first segmentation target, already established

The block at `0x80097FF0`-`0x800980C0` (208 bytes) is the signal processor's
boot loader, and the evidence is link-time rather than stylistic: main-processor
code at `0x80007140` and at `0x80084C3C` forms the addresses of both ends with
`%hi`/`%lo` pairs and *subtracts* them to get the length, then stores the start
and the length into a task descriptor; a statically initialised descriptor at
`0x8009A2D0` holds the same start address, and it is the only stored copy of
that address in the image. Nothing branches to it or calls it. It should be
carried as transferred data with symbols at **both** ends, because the end
symbol is load-bearing for those subtractions.

A second and much larger image begins immediately at `0x800980C0`, encoded with
that processor's vector instructions, which the main-processor disassembler
renders as invalid words. It runs past the end of the current `main` code
segment at ROM `0x99000` and continues inside the `remainder` binary segment,
ending near `0x800990CC`. **The present segment boundary cuts a microcode image
in half.** Fixing that is the concrete first step of the segmentation work, and
it also answers the standing comment in `config/us.yaml` about material still
to classify.

Item 2 is the one that changes the shape of the project rather than adding to
the count. Until the interval is segmented, bodies from those regions keep
arriving on the C queue, and no honest total percentage exists because the
denominator is not yet code.

## Audit findings, and the gate they produced

Two full waves of parallel recovery were audited afterwards. Every one of the
506 claimed USA matches was re-derived independently from the ROM bytes rather
than trusted from the report: **zero false claims**, and the configs hold every
structural invariant. The C the workers wrote is sound.

The defects were all in the *connective tissue*, and they clustered into two
kinds worth knowing about in advance.

**Prototype disagreements, which the byte comparison structurally cannot
catch.** A caller that declares the wrong arity still reproduces the original
bytes whenever the value it should have passed already sits in the right
register. Five were found *after* their functions had been verified exact:
`func_80007CE4`, `func_8003931C`, `func_80088500` (callers declared the wrong
arity), and `func_80031BBC`, `func_8003FA24`. `make prototypes` now checks
this on every run and is wired into `make test`; the check was mutation-tested
to confirm it actually fires.

Two of those five are *not* defects and are recorded as accepted: the original
was built from unprototyped C, so a caller could legitimately pass more
arguments than the callee accepted. Where the caller's own bytes prove it did —
the register is genuinely set before the call — reproducing the disagreement is
faithful and forcing agreement would be wrong. The allowlist is keyed on
callee, declaring file *and* arity, so any other disagreement still fails.

**Worker-invented configuration keys.** Workers reported "this unit was built at
a different optimisation level" under at least four different key names, none
of which the verifier honours. Each one silently rebuilt the unit with the
default profile and reported a spurious mismatch. The merge now normalises all
of them and back-fills units already adopted. Regional units also arrived
missing their `defines` name remaps — the object exported the USA name while
the linker script defined the regional one, which crashes `ld` outright rather
than failing quietly.

The lesson for future waves: **a worker's result is a proposal, and the failure
modes are in the metadata, not the C.** Re-prove centrally, and be suspicious of
any key you did not ask for.

## How to run a tranche

The parallel method from the last tranche works and should be reused. Its rules
matter more than its speed:

- Workers own only `src/functions/<name>.c` and their own scratchpad files.
  Every shared file — configs, headers, specs, tests, the Makefile — is merged
  centrally, because concurrent edits to them silently clobber.
- Every claim is re-proved centrally before it lands. A worker reporting an
  exact match is a proposal; `make match-c` against the version's own ROM is
  the decision.
- Boundaries from the label scan are wrong often enough that the brief now
  tells workers to distrust them. Roughly a third of the last tranche's bodies
  were larger than assigned, almost always because a conditional branch jumped
  past the apparent return into a label with no callers.
- Regional units must export the regional symbol name. A unit that verifies
  while exporting the USA name will still break that version's link.

## Standing invariants

Checked mechanically; a change that breaks one is wrong even if it looks like
progress:

- every unit's `rom` equals `vram - 0x7FFFF400`;
- every function's compiled symbol name is `func_<vram>`;
- no two units claim overlapping ROM ranges, and no source has two units in one
  version;
- `make manifest` fails if a source under `src/` is measured by no unit;
- all four ROMs rebuild byte-identically after any split change.

## Gates

```sh
make match-c && make roundtrip-all && make manifest && make classify
make test && make safety && git diff --check
python3 tools/rom_inventory.py --config config/versions.json \
    --output analysis/roms.json --check
```

The host test links every recovered source, so each tranche retires the
hand-written doubles for the functions it recovers. A double and a real
implementation cannot both define a symbol; where the real function reaches
memory-mapped hardware, the host test cannot drive it at all and the byte-match
verifier is the right check instead.
