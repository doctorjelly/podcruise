# How the parallel recovery workflow operated

Most of the recovered source in this repository was produced by many
independent workers running concurrently against the same ROM images, rather
than by one process working through functions in order. This file records how
that was organised, because the arrangement explains several conventions in the
repository that would otherwise look arbitrary.

The agent configuration itself is deliberately not committed: it is specific to
one operator's tooling, and the method below is the part worth keeping.

## Shape

An orchestrator holds no function-recovery work of its own. Each cycle it:

1. computes the set of functions that still lack matching C;
2. partitions them into small assignments, sized by function length;
3. dispatches one worker per assignment, all running concurrently;
4. merges the results, re-verifies every unit centrally, and rebuilds all four
   ROM images;
5. folds anything the workers proved about the compiler back into a shared
   brief, then repeats.

Workers never commit, never edit shared configuration, and never touch each
other's files. Each writes exactly three things: one C source, one behavioural
specification, and one result record describing what it verified.

## Why the orchestrator re-verifies everything

A worker reports its own result. That report is evidence, not proof. Every
cycle the orchestrator recompiles every configured unit with the identified
toolchain and compares the output against the ROM, so a worker's claim is only
ever accepted after being independently reproduced. `tools/verify_c_matches.py`
takes a `--build-root` for exactly this reason: an audit can run against a
private build tree without disturbing anything else.

This caught real problems. It is also why the headline counts in
`docs/DECOMP_STATUS.md` are generated rather than maintained by hand.

## Two kinds of assignment

Recovery work splits into two populations that need different instructions:

- **Fresh recovery** — no C exists yet. This is a search over *program shape*:
  what the function does, and which C expresses it.
- **Near-miss closing** — C exists and already compiles to the original's exact
  length, so the shape is right and only register allocation or scheduling
  differs. This is a search over *spelling*, with the shape held fixed.

Sending a near-miss through the fresh-recovery instructions invites a worker to
rewrite working logic and lose a size match it already had. Keeping the two
streams separate measurably improved yield.

## The shared brief is the compounding asset

Every worker reads one accumulated document of proved compiler behaviour before
starting. It grew past five hundred lines and is the reason later waves closed
functions faster than earlier ones: findings like *a local that is referenced
anywhere reserves a frame slot even when it lives in a register*, or *IDO
rewrites `x / 2.0f` into a multiply unless the constant is cast*, are expensive
to rediscover and cheap to write down.

Two rules kept it trustworthy. Every entry had to be proved against real bytes,
not inferred. And where two workers observed contradictory behaviour, the brief
records the contradiction rather than picking a side.

## Merges must be idempotent

Worker results are durable files, and the orchestrator's merge re-derives
configuration from them rather than mutating state in place. So re-running a
merge is harmless, and a result that fails to adopt in one cycle is simply
adopted in the next.

This property turned out to matter more than expected. For a period, two
orchestrators ran concurrently against this repository without either detecting
the other — they shared a scratch directory, a configuration set and a source
tree. A subsequent reconciliation found no lost or duplicated units. That
outcome is attributable to idempotent merges over durable inputs, not to
anything noticing the conflict, and it is the strongest argument for building
the pipeline this way.

## Failure classes worth designing against

Each of these appeared in practice and now has a guard:

- **A single malformed unit aborting all measurement.** The verifier now
  records a per-function failure and continues.
- **Substituting C for a function another assembly function branches *into*.**
  An alternate entry point cannot be expressed as a standalone C unit; the
  link fails, and the boundary is recorded as wrong rather than retried.
- **A C split beginning before the function its source defines**, which deletes
  the preceding function's assembly and replaces it with nothing.
- **Generated link stubs that only ever accumulate**, so recovering a function
  that was already stubbed becomes a duplicate definition.
- **Stale generated inputs inflating counts.** A classifier that globbed a
  directory rather than reading the split configuration double-counted bodies
  by a factor of two.

The first three can produce a wrong build; the last two produce wrong numbers.
Both categories are worth a gate.
