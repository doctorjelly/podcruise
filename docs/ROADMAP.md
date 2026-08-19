# Decompilation roadmap

## Definition of done

“100%” means that the canonical USA retail target can be rebuilt byte-for-byte
from reviewed source, data declarations, assets extracted from a user-supplied
ROM, and a reproducible toolchain. A mechanically recompiled executable or a
list of discovered functions does not count as source-decompilation progress.

Progress will eventually be reported separately for:

- matching code bytes;
- identified functions and symbols;
- typed data and reconstructed assets;
- regional build coverage;
- runtime behavior tests.

## Version policy

| Version | Purpose |
|---|---|
| USA retail (`NEPE`, revision 0) | canonical matching target |
| Japan retail (`NEPJ`, revision 0) | later-build code and boundary evidence |
| Europe retail (`NEPP`, revision 0) | PAL/localization code and boundary evidence |
| USA Limited Run Games (`NEPE`, revision 1) | post-link patch evidence only |

Japan and Europe are not automatically “newer and better” source. Differences
must be classified as relocation, compiler/code change, localization, timing,
asset, or post-link patch before being used.

## Phase 0: reproducible evidence

- [x] Hash and validate all supplied ROMs.
- [x] Detect duplicate filenames/images.
- [x] Establish a conservative USA executable interval.
- [x] Derive independent function candidates.
- [x] Map normalized candidate windows into Japan and Europe.
- [ ] Confirm executable/data boundaries with runtime DMA tables and splat.
- [x] Establish an IDO-family compiler hypothesis from control-flow lowering.
- [ ] Determine the exact IDO compiler version and optimization flags from
      multiple representative functions.
- [ ] Identify exact libultra/SDK variants by instruction fingerprints.

## Phase 1: matching build loop

- [x] Pin the Python splitter/disassembler environment by exact version.
- [ ] Pin a reproducible GNU MIPS binutils build rather than relying on the
      current Homebrew formula version.
- [ ] Identify and provenance-clear an exact compiler revision.
- [ ] Split USA into boot, code, data, and asset segments.
- [x] Reassemble the coarse untouched split to an exact USA ROM.
- [ ] Refine USA into verified boot, CPU code, data, RSP microcode, and asset
      segments while preserving the exact round trip.
- [ ] Add `make verify` with whole-ROM SHA-1 and first-difference diagnostics.
- [ ] Configure `asm-differ` for function-level iteration.

## Phase 2: source recovery

- [x] Write clean-room behavior specifications and source candidates for the
      three 12-byte bootstrap-state accessors.
- [ ] Name and type libultra functions first.
- [ ] Recover leaf utilities and string/memory routines.
- [ ] Reconstruct scheduler, DMA, controller, audio, and graphics boundaries.
- [ ] Decompile game systems in dependency order.
- [ ] Require byte match plus a short evidence note for every source conversion.

## Phase 3: regional builds

- [ ] Partition common and region-specific source.
- [ ] Build Japan and Europe from the shared tree.
- [ ] Reconstruct localization and PAL timing changes explicitly.
- [ ] Keep the LRG patch as a separate, documented binary transformation if
      supported at all.

## Evidence rules

1. ROM-derived generated files stay out of Git unless they are clearly lawful,
   compact metadata such as hashes and addresses.
2. A structural cross-version match supports a hypothesis; it does not prove a
   function boundary or semantic equivalence.
3. Imported names or addresses must have a provenance note.
4. Prior-art code with no explicit license is not copied.
5. Every claimed matching function is verified against the canonical ROM.
