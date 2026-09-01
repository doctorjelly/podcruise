# Token-efficient agent workflow

These instructions apply repository-wide. Token conservation never overrides
correctness, provenance, IP policy, exact-match evidence, or required tests.

## General rules

- Read the smallest useful slice. Start with precise `rg` queries, then bounded
  `sed`, `head`, or `tail`; do not dump whole generated files or reports.
- Keep command output quiet and bounded. Prefer `make -s`, focused test targets,
  compact JSON summaries, and low tool-output limits. Report failures by the
  decisive lines, not the entire log.
- After `file` identifies binary data, never pass it to a text viewer; use a
  narrowly filtered `strings`, `readelf`, or `objdump` query instead.
- Filter downloaded HTML before it reaches the transcript and cap the result;
  never print an entire search or documentation page just to find one detail.
- Redirect full round-trip output to a temporary log; the generated build
  prints hundreds of commands even under `make -s`. Extract only decisive
  success/error lines with `rg` because even the final linker line is enormous.
  Do not use `tail` on that log: the linker command is commonly one giant line.
  Preserve the command's exit status and retain the log on failure.
- Batch deterministic work. Rank, filter, compare, or aggregate several
  candidates in one local operation and return a short table.
- Minimize model turns. Group independent read-only checks, avoid reopening
  unchanged files, and do not narrate routine steps.
- Preserve durable facts in the appropriate spec/status file. Do not repeatedly
  restate history that the repository already records.
- At a clean commit boundary, prefer a fresh session seeded with the commit,
  goal, and relevant repository documents over carrying a very long chat.
- Keep user updates and final answers concise: outcome, evidence, caveat, next
  action. Omit repeated background and full command transcripts.

## Codex and ChatGPT usage

- Use the least expensive model and reasoning effort that succeeds on a
  representative task. For this project's high-volume triage and brute-force
  work, use GPT-5.6 Luna Low. Escalate only a bounded hard case after lower-cost
  work has produced a precise blocker.
- Give each subagent a compact, self-contained batch with exact paths, evidence,
  stopping criteria, and output schema. Avoid full-history forks and one-agent-
  per-candidate churn. Do not assign overlapping candidates.
- Require subagents to return a compact result table. They must revert failed
  experiments and leave edits only for a verified success; the parent reviews
  all retained work.
- Use code/programmatic tool orchestration for predictable filtering, ranking,
  and comparison so large intermediate results are reduced before the model
  sees them. Keep semantic judgment and final verification with the agent.
- Redirect deterministic full-build output to a temporary log, then surface
  only explicit success/failure lines. One LRG round trip emitted 2,280 lines
  (419 KB) even though the only decision-bearing line was the final exact-hash
  result; filtering that output materially reduces transcript tokens.
- Do not paste stable instructions repeatedly. In API-backed workflows, keep
  reusable prompt prefixes stable for caching, use prior-response state or
  compaction, and select current-turn reasoning context when old reasoning is no
  longer relevant. Measure cached, reasoning, and total tokens when available.
- Avoid Pro mode and high reasoning for routine work. Increase effort only when
  a measured quality gain justifies the additional tokens.
- When cumulative goal usage is available, record it before and after an
  isolated function attempt in `docs/function_token_log.tsv`. Never divide a
  concurrent or batched token total among functions as though it were measured;
  use a tranche row or leave the function total blank.
- Codex rollout `token_count` events can provide the raw per-turn split. Record
  input, cached input, cache-write input, output, and reasoning-output deltas
  across that task's `task_started`/`task_complete` interval. Extract only the
  numeric fields; never commit session transcripts. `output_tokens` already
  includes its reasoning-token subset, and cached input must remain separate
  from uncached input when applying prices.
- Run `make progress-chart` whenever exact USA coverage changes so the README
  plot and its tracked milestone TSV stay reproducible from Git history.

Official basis: [OpenAI model guidance](https://developers.openai.com/api/docs/guides/latest-model).

## Podcruise decompilation loop

- Triage 5-10 USA candidates at once. Prefer verified boundaries, compact
  behavior, and localized compiler differences.
- Before delegating, subtract every recovered ROM interval from the candidate
  list and resolve each surviving label to an exact assembly file and line
  span. This avoids spending model tokens on interior labels. Merge adjacent
  prefix fragments when live registers prove that the later prologue is a
  false split.
- For one function, inspect only its USA assembly slice, callers/callees,
  globals, spec, source, and exact compiler summary. Use JP/EU only when the USA
  evidence is ambiguous; ignore LRG unless the user restores it to scope.
- Before reshaping a USA source that is already exact in Japan or Europe,
  compare the regional unit flags. An identical normalized body may expose a
  missing per-file optimization level; this recovered `func_80090450` by
  copying its proven `-O3` setting instead of spending more variants on C.
- When per-file optimization is uncertain, run one temporary whole-ledger
  IDO 5.3 `-O1`/`-O3` sweep and diff its exact set against the accepted report.
  This is cheaper than asking agents to retry every function; the first sweep
  isolated `func_8008C390` as an exact `-O1` unit and ruled out all `-O3`
  nonmatches at once.
- The corresponding full unresolved-unit MIPS III/ABI sweep found only
  `func_8008C638`, exact under `-O1 -mips3 -32`; do not repeat that sweep on
  unchanged sources. Reuse the result and reserve new flag sweeps for newly
  recovered units or genuinely new compiler evidence.
- A full IDO 7.1 sweep of all unresolved units across eight O1/O2/O3,
  MIPS II/MIPS III, and ABI combinations produced no exact matches. Do not
  repeat it on unchanged sources; spend those tokens on source recovery.
- Before treating a runtime layout as opaque, search recovered callers and
  neighboring routines for the same callback, global, or hardware register
  block. Reusing already-proven local structure offsets is cheaper and more
  reliable than decoding an isolated body from scratch.
- For adjacent command-handler dispatchers, compare when the attached callback
  target is loaded and the emitted case-block order before trying register
  tweaks. A typed owner alias, case-local callback loads, and source cases in
  canonical block order recovered two exact handlers with only two variants.
- For a large branch-heavy routine, use a local open-source control-flow aid
  such as `m2c` from an ignored virtual environment before spending model
  tokens narrating every instruction. Supply missing jump tables only in
  `/tmp`, treat the output as an untrusted mechanical draft, and independently
  check its delay slots, types, helper contracts, and every retained branch;
  never commit the generated draft.
- When a control-flow aid reports a missing jump table, read only the bounded
  table words from the local canonical ROM and synthesize labels in `/tmp`.
  Avoid dumping the surrounding data segment: a compact index-to-target list
  is enough to recover the switch and is much cheaper to review.
- Run the isolated matching-object comparison during iteration. Do not run a
  full regional match or ROM round trip after every failed variant.
- Keep behavior-only units in the compiler-test manifest but leave their USA
  split as assembly. Change the split to C only after an exact comparison;
  otherwise the integration guard will reject the unit after an expensive
  rebuild.
- For large routines, compare the canonical and compiled `jal` target lists
  programmatically before asking for another prose audit. Equal call order and
  count cheaply exposes missing, duplicated, or invented helper operations.
- Give low-cost agents narrow address windows or concrete tables to verify;
  asking one to wrap an entire `m2c` draft usually saves no review tokens. For
  stack temporaries, derive overlapping matrix/vector aliases from helper
  argument ranges before accepting an inferred scalar layout.
- Stop blind reshaping when differences are broad register allocation or
  scheduling. Record the blocker briefly and move to actual source recovery or
  another high-probability candidate.
- Confirm the true function body through the `jr` delay slot before shaping C;
  do not try to make the compiler emit post-return alignment padding.
- When an uncalled body ends with a value in `$v0`, do not infer a C return type
  from that register alone. Test `void` after excluding post-return padding;
  this two-check audit recovered `func_80089488` exactly and was cheaper than
  trying to recolor its counter and cursor locals.
- As a default token cap, stop after three evidence-driven source variants when
  the remaining difference is only register coloring or scheduling.
- Rank same-size candidates by differing instruction words and check their
  recovery notes before trying variants. Skip documented register-only dead
  ends; pilot any automated permutation search on one representative function
  with a fixed time limit before scaling it to a batch.
- Three isolated Luna Low re-audits of documented late mismatches cost
  2,050-3,998 tokens each and recovered nothing; one also misstated compiled
  size until the parent reran the verifier. Exclude already-recorded scheduler
  or register-allocation blockers before delegation, and keep parent compiler
  verification mandatory. Measurements live in `docs/function_token_log.tsv`.
- When every mismatch is a local stack offset, exhaustively test only the small
  declaration-order space in `/tmp` before changing behavior or invoking the
  general permuter. Keep the simplest exact ordering and independently rerun
  the linked-object verifier; this recovered two matches in seconds while
  scheduler-only cases showed no benefit.
- When only adjacent independent copies have swapped IDO registers, test the
  small statement-order space and same-line grouping before a random search.
  Source line grouping is codegen-significant for IDO; one order plus one
  same-line pair recovered `func_8007ACEC` exactly without broad permutation.
- Treat source-line grouping as a small, measured search dimension for IDO
  scheduling: separating independent short-circuit assignments can stop work
  from being hoisted across the first branch, while grouping a conditional
  selection with its next constant load can reverse two otherwise-independent
  instructions. Together these changes recovered `func_8006E42C` exactly.
- For a mixed aggregate/scalar frame, first sweep one local through the existing
  declaration order and count differing words; do not permute the full factorial
  space. Once stack offsets match, split only the remaining compound expression
  into sequential assignments. This bounded two-stage search recovered
  `func_8007B06C` while keeping compiler experiments small.
- Run `decomp-permuter` without a pseudo-terminal, use `--quiet`, and redirect
  its full progress stream to `/tmp`. Its carriage-return status line can
  otherwise expand into tens of thousands of useless transcript tokens; only
  surface the base score, improved candidates, and final result.
- Use `--stack-diffs` from the start for functions with stack locals or arrays.
  The default scorer ignores stack offsets and can report a misleading zero;
  catching that before integration avoids an entire failed ROM rebuild.
- Make permuter inputs self-contained instead of depending on project headers;
  its preprocessing pass uses `cpp -nostdinc`. A few local typedefs avoid a
  failed run and keep the search setup cheap. Treat zero-score output as a hint,
  then independently verify the readable minimal change through the project
  compiler harness.
- Before a permutation run, disassemble the temporary target and compare its
  `.text` size and first/last words with the ROM slice. This binutils build can
  zero section contents when rename and flag changes are combined; a malformed
  target wastes the whole search and can produce meaningless scores.
- If a semantically preferred branch fixes the last opcode but changes register
  allocation, seed the permuter from that form. A behavior-neutral redundant
  expression after an already-proven dereference can reproduce IDO's original
  register allocation; independently verify the smallest readable winner.
- When a loop differs only in loads scheduled around its back edge or break
  delay slot, make the next iteration's non-volatile bound an explicit local
  and refresh it once per completed iteration. This small source-shape test
  recovered `func_8008A420`; it is cheaper than a broad permutation run and
  still preserves helper-visible bound changes.
- When a nested helper call leaves only stack-argument stores and reloads out
  of order, first assign the helper result to a naturally typed local and use
  that local in the outer call. This preserved the code shape while recovering
  repeated schedules in `func_8007134C`, `func_80070E98`, and `func_80070764`.
  For the latter two, sweeping only the spilled scalar through the declaration
  order then recovered the final stack offset.
- Batch successful functions into one tranche. Then run the canonical USA round
  trip, `make -s test`, `make -s safety`, ROM inventory, and
  `git diff --check` once before committing.
- Never claim byte-matching C without the exact compiler comparison and
  byte-identical canonical USA integration evidence.
- After a new exact match, confirm the USA split names the C subsegment, the
  rebuild substitution count increases, and the linker map uses its C object.
  A byte-identical ROM alone can hide a stale split that still assembled the
  original body; checking the count and map avoids a second full rebuild.
- When a new C subsegment interrupts a larger assembly segment, add an assembly
  resume boundary at the function's exact end. Without it, splat silently omits
  the remaining assembly range and wastes a full rebuild on a linker failure.
