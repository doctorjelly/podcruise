/* Independently written from scratchpad spec specs/func_8008E420.md. */

#include "podcruise/types.h"

/*
 * Packaging note.  The original translation unit that holds this body was
 * built one optimisation level above the rest of the ROM.  At that level the
 * compiler allocates registers across every function of a unit at once, so a
 * file-local routine whose call sites are all visible receives its arguments
 * in whatever registers the allocator happened to choose instead of the usual
 * argument registers, is free to destroy callee-saved registers that its
 * caller reloads afterwards, and is emitted with no ELF symbol at all.  This
 * routine is one of those: it takes all seven inputs in callee-saved
 * registers and overwrites four of them without saving them.  Reproducing
 * that requires the routine to stay file-local and to have a caller in the
 * same file; func_8008E420_call_context below is a minimal stand-in for that
 * caller.  The real caller is func_8008E54C, and once that function is
 * recovered the two belong in a single translation unit and the stand-in
 * should be deleted.
 *
 * The two macros below are load-bearing for the byte match, in two separate
 * ways.  FIELD keeps the width mask even where the following shift makes it
 * redundant; the redundant mask disappears from the emitted code but changes
 * the order in which the compiler evaluates the two halves of a packed word.
 * COMMAND expands to a single source line; the compiler orders statements
 * partly by source line, so the same four statements written out on four
 * lines schedule differently from the same four joined into one.
 */

typedef struct {
    u32 w0;
    u32 w1;
} Cmd;

typedef struct {
    u32 unk00[5];
    u32 unk14;
    u32 unk18;
    u32 unk1C[5];
    s32 (*unk30)(s32, s32, s32);
    s32 unk34;
    u32 unk38[2];
    s32 unk40;
    s32 unk44;
} Obj;

#define FIELD(value, shift, width) \
    ((u32)(((u32)(value) & ((0x01U << (width)) - 1)) << (shift)))

#define COMMAND(cursor, word0, word1) \
    { Cmd *cmd_ = (cursor); cmd_->w0 = (word0); cmd_->w1 = (word1); }

static Cmd *func_8008E420(Cmd *p, s32 nbytes, Obj *a, u32 flags, s16 outp,
                          s16 dmemIn, s32 nsam) {
    s32 addr;
    s32 off;

    if (nbytes > 0) {
        addr = a->unk30(a->unk44, nbytes, a->unk34);
        off = addr & 7;
        nbytes += off;
        COMMAND(p++, FIELD(8, 24, 8) | FIELD(0, 16, 8) | FIELD(dmemIn, 0, 16),
                FIELD(0, 16, 16) | FIELD((nbytes - (nbytes & 7)) + 8, 0, 16));
        COMMAND(p++, FIELD(4, 24, 8), (u32)(addr - off));
    } else {
        off = 0;
    }
    if (flags & 2) {
        COMMAND(p++, FIELD(15, 24, 8), (u32)a->unk18 & 0x1FFFFFFF);
    }
    COMMAND(p++, FIELD(8, 24, 8) | FIELD(0, 16, 8) | FIELD(dmemIn + off, 0, 16),
            FIELD(outp, 16, 16) | FIELD(nsam * 2, 0, 16));
    COMMAND(p++, FIELD(1, 24, 8) | FIELD(flags, 16, 8),
            (u32)a->unk14 & 0x1FFFFFFF);
    a->unk40 = 0;
    return p;
}

Cmd *func_8008E420_call_context(Cmd *p, Obj *a, s32 n, s16 o);

Cmd *func_8008E420_call_context(Cmd *p, Obj *a, s32 n, s16 o) {
    p = func_8008E420(p, n, a, 0u, o, (s16)0, n);
    p = func_8008E420(p, n + 1, a, 2u, o, (s16)1, n);
    p = func_8008E420(p, n + 2, a, 4u, o, (s16)2, n);
    return p;
}
