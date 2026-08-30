# Token-efficient agent workflow

These instructions apply repository-wide. Token conservation never overrides
correctness, provenance, IP policy, exact-match evidence, or required tests.

## General rules

- Read the smallest useful slice. Start with precise `rg` queries, then bounded
  `sed`, `head`, or `tail`; do not dump whole generated files or reports.
- Keep command output quiet and bounded. Prefer `make -s`, focused test targets,
  compact JSON summaries, and low tool-output limits. Report failures by the
  decisive lines, not the entire log.
- Redirect full round-trip output to a temporary log; the generated build
  prints hundreds of commands even under `make -s`. Extract only decisive
  success/error lines with `rg` because even the final linker line is enormous.
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
- Do not paste stable instructions repeatedly. In API-backed workflows, keep
  reusable prompt prefixes stable for caching, use prior-response state or
  compaction, and select current-turn reasoning context when old reasoning is no
  longer relevant. Measure cached, reasoning, and total tokens when available.
- Avoid Pro mode and high reasoning for routine work. Increase effort only when
  a measured quality gain justifies the additional tokens.

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
- Before treating a runtime layout as opaque, search recovered callers and
  neighboring routines for the same callback, global, or hardware register
  block. Reusing already-proven local structure offsets is cheaper and more
  reliable than decoding an isolated body from scratch.
- Run the isolated matching-object comparison during iteration. Do not run a
  full regional match or ROM round trip after every failed variant.
- Stop blind reshaping when differences are broad register allocation or
  scheduling. Record the blocker briefly and move to actual source recovery or
  another high-probability candidate.
- Confirm the true function body through the `jr` delay slot before shaping C;
  do not try to make the compiler emit post-return alignment padding.
- As a default token cap, stop after three evidence-driven source variants when
  the remaining difference is only register coloring or scheduling.
- Batch successful functions into one tranche. Then run the canonical USA round
  trip, `make -s test`, `make -s safety`, ROM inventory, and
  `git diff --check` once before committing.
- Never claim byte-matching C without the exact compiler comparison and
  byte-identical canonical USA integration evidence.
- After a new exact match, confirm the USA split names the C subsegment, the
  rebuild substitution count increases, and the linker map uses its C object.
  A byte-identical ROM alone can hide a stale split that still assembled the
  original body; checking the count and map avoids a second full rebuild.
