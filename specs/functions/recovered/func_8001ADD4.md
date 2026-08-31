# func_8001ADD4

## Verified facts

- The canonical USA body begins at VRAM `0x8001ADD4`, ROM `0x1B9D4`, and
  ends after the `jr ra` delay slot at `0x8001C400`. Its size is `0x1630`
  (5,680) bytes; `func_8001C404` begins immediately afterward. The delay slot
  restores the `0x1E8`-byte stack frame.
- Its recovered caller is `func_8004A880`, which dispatches here for object
  state 9. The argument layout is corroborated by that dispatcher and nearby
  controllers: the routine reads the mode and substate at `0x0C/0x10`, flags
  at `0x14`, stage metadata at `0x50..0x70`, and writes per-stage choices
  beginning at `0x72`.
- All USA branches and their delay slots were reviewed in three nonoverlapping
  address windows. There are no computed jumps or jump tables. The terminal
  boundary, the conditional branch-likely stores, and the outgoing stack
  arguments at `sp+0x10..0x24` were checked directly.
- The routine has 72 static calls. The IDO 5.3 candidate emits the same 72
  targets in exactly the same order, covering initialization, entry lookup,
  UI formatting, model replacement, transform construction, input handling,
  and final state dispatch.
- Important data are the five-option records at `D_80113680`, stage records
  at `D_80113E60`, indexed entries at `D_800D6CD8`, resource records at
  `D_800A31E0`, session fields at `D_8011A240`, and the active display object
  at `D_8011A544`. The address labels `D_80113E65`, `D_80113E67`,
  `D_80113694`, and `D_800A3200` are fields or aliases within those tables.
- The caller mappings identify the structural equivalents at JP
  `0x8001B004` and EU `0x8001B74C`. They were used only to confirm relocation
  and dispatch correspondence; USA remains canonical.

## Behavioral specification

This routine is the per-frame controller for a staged entry-selection screen.
On first entry it resets the shared transition state, derives the initial
screen from the controller mode and current stage, restores the previously
chosen option and entry, and establishes the active display model.

While active, it advances panel fades, formats the option labels and selected
entry name, updates the controller's validity flag, and rebuilds the displayed
object whenever the selected entry changes. It rotates that object through a
four-part 1,800-degree presentation cycle, blends its translation between two
shared vectors, and forwards the resulting matrix and animation flags to
`func_80018480`.

When transitions are idle, it consumes the current stage's input bits. The
confirm and cancel paths update stage records and move between option and entry
selection; directional bits wrap the option index; a completion input enters
the confirmation substate. Once a transition commits, the selected entry is
copied into both the controller and shared stage record, special-option
metadata is updated, and the routine either advances to the next stage or
selects the next outer screen.

## Recovery notes

- The mechanical control-flow draft incorrectly suggested that the late
  record loop could span multiple stages. The USA comparison is against the
  current stage on both sides, so that path executes exactly once.
- `func_80029298` takes one floating-point argument at both call sites; an
  unrelated live integer register was not a second argument.
- `sp+0xA0` is a 4-by-4 transform. `sp+0xD0` aliases its translation row,
  while `sp+0xE0` begins a separate 256-byte text buffer. Treating those stack
  ranges as unrelated mechanical temporaries obscures the model-update path.
- Input words are reloaded after helpers that may update shared controller
  state. The recovered C preserves those reload points rather than caching one
  value for the entire frame.

## Status

**Behavior-recovered C, not byte-matching.** With the recorded IDO 5.3 `-O2`
profile, the candidate is `0x1508` (5,384) bytes versus the canonical `0x1630`
(5,680), and the first instruction word differs at byte 0. Equal call count
and order plus the reviewed control flow support the behavioral recovery, but
the function must remain assembly in the USA split until an exact compiler
comparison succeeds.
