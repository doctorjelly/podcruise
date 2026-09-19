# func_80055AEC — matching blocker

- USA ROM `0x566EC..0x56937` is a 588-byte body. The reviewed C candidate
  links at the canonical address and has the correct symbol size, but differs
  in 26 instruction words, first at byte `0x75`.
- A declaration reorder and block-local value left the same mismatch. A
  direct-dereference form shrank the symbol to 572 bytes and was discarded.
  The residual issue begins in the first pixel-processing block and appears
  to be register allocation or scheduling. Keep the USA split as assembly.
