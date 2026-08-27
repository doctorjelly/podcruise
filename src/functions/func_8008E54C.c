/* Recovered per specification specs/func_8008E54C.md.
 *
 * Packaging note.  This body is the real caller of the file-local routine at
 * 0x8008E420, and the two share one translation unit built one optimisation
 * level above the rest of the ROM.  At that level the compiler allocates
 * registers across the whole unit, so the file-local routine receives its
 * arguments in callee-saved registers, destroys several of them, and is
 * emitted with no symbol of its own.  The routine below is therefore repeated
 * here, byte-identical in behaviour to src/functions/func_8008E420.c; when the
 * orchestrator merges the unit the stand-in caller in that file should be
 * dropped and the two definitions collapsed into this single unit.
 */

#include "podcruise/types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Cmd;

typedef struct {
    u32 w0;
    u32 w4;
    u32 w8;
    u32 wC;
    u32 w10;
} Buf;

typedef struct {
    u32 unk00[5];
    u32 unk14;
    u32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    Buf *unk28;
    u32 unk2C;
    s32 (*unk30)(s32, s32, s32);
    s32 unk34;
    s32 unk38;
    s32 unk3C;
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

Cmd *func_8008E54C(Obj *a, s16 *b, s32 n, s32 unused, Cmd *out);

Cmd *func_8008E54C(Obj *a, s16 *b, s32 n, s32 unused, Cmd *out) {
    Cmd *cursor;
    s32 len;
    s32 pad;
    s32 avail;
    s32 blocks;
    s32 blocks9;
    s32 sample;
    s32 aligned;
    s32 total;
    s32 excess;
    s32 limit;
    s32 bytes;
    s32 delta;
    s32 flag;
    s32 cond;

    (void)unused;
    flag = 0;
    if (n == 0) {
        return out;
    }

    out->w0 = FIELD(11, 24, 8) | FIELD(a->unk2C, 0, 24);
    out->w1 = (u32)(a->unk28->w10 + 8) & 0x1FFFFFFF;
    cursor = out + 1;

    cond = ((u32)a->unk20 < (u32)(a->unk38 + n)) && (a->unk24 != 0);
    len = cond ? (a->unk20 - a->unk38) : n;
    pad = (a->unk3C != 0) ? (16 - a->unk3C) : 0;
    avail = len - pad;
    if (avail < 0) {
        avail = 0;
    }
    blocks = (avail + 15) >> 4;
    blocks9 = blocks * 9;

    if (cond) {
        cursor = func_8008E420(cursor, blocks9, a, (u32)a->unk40, (s16)*b, 0,
                               avail);
        if (a->unk3C != 0) {
            *b = (s16)(*b + a->unk3C * 2);
        } else {
            *b = (s16)(*b + 0x20);
        }
        bytes = a->unk1C;
        a->unk3C = bytes & 0xF;
        a->unk44 = (a->unk28->w0 + ((u32)bytes >> 4) * 9) + 9;
        a->unk38 = bytes;
        sample = *b;
        delta = len * 2;
        while (len < n) {
            aligned = (((blocks + 1) << 5) + sample) & -32;
            n -= len;
            if (a->unk24 != -1 && a->unk24 != 0) {
                a->unk24 = a->unk24 - 1;
            }
            sample += delta;
            limit = a->unk20 - a->unk1C;
            len = ((u32)n < (u32)limit) ? n : limit;
            avail = len + a->unk3C - 16;
            if (avail < 0) {
                avail = 0;
            }
            blocks = (avail + 15) >> 4;
            blocks9 = blocks * 9;
            cursor = func_8008E420(cursor, blocks9, a, (u32)a->unk40 | 2,
                                   (s16)aligned, 0, avail);
            delta = len * 2;
            COMMAND(cursor, FIELD(10, 24, 8) | FIELD(a->unk3C * 2 + aligned, 0, 24),
                    FIELD(sample, 16, 16) | FIELD(delta, 0, 16));
            cursor++;
        }
        a->unk3C = (a->unk3C + n) & 0xF;
        a->unk38 = a->unk38 + n;
        a->unk44 = a->unk44 + blocks9;
        return cursor;
    }

    total = a->unk44 + blocks9;
    excess = (total - (s32)a->unk28->w0) - (s32)a->unk28->w4;
    if (excess < 0) {
        excess = 0;
    }
    limit = (excess / 9) * 16;
    bytes = blocks * 16 + pad;
    if (bytes < limit) {
        limit = bytes;
    }
    pad = blocks9 - excess;
    if ((limit - (limit & 0xF)) < n) {
        flag = 1;
        cursor = func_8008E420(cursor, pad, a, (u32)a->unk40,
                               (s16)*b, 0, blocks * 16 - limit);
        if (a->unk3C != 0) {
            *b = (s16)(*b + a->unk3C * 2);
        } else {
            *b = (s16)(*b + 0x20);
        }
        a->unk3C = (a->unk3C + n) & 0xF;
        a->unk38 = a->unk38 + n;
        a->unk44 = a->unk44 + blocks9;
    } else {
        a->unk3C = 0;
        a->unk44 = total;
    }

    if (limit != 0) {
        a->unk3C = 0;
        if (flag) {
            delta = (bytes - limit) * 2;
        } else {
            delta = 0;
        }
        cursor->w1 = (u32)(limit * 2);
        cursor->w0 = FIELD(2, 24, 8) | FIELD(*b + delta, 0, 24);
        cursor++;
        return cursor;
    }
    return cursor;
}
