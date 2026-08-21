/* Independently written from scratchpad spec specs/func_8008F0B4.md. */

/*
 * Packaging note.  The translation unit that holds this body was built one
 * optimisation level above the rest of the ROM.  At that level the compiler
 * allocates registers across every function of a unit at once, so a file-local
 * routine whose call sites are all visible receives its arguments in whatever
 * registers the allocator chose, may destroy callee-saved registers its caller
 * reloads afterwards, and is emitted with no symbol of its own.  This routine
 * is one of those: its six inputs arrive in five callee-saved registers plus a
 * scratch register that all four of its call sites hold live across the call,
 * which no ordinary calling convention produces.  Reproducing that requires the
 * routine to stay file-local and to be surrounded, in one unit, by a caller and
 * by the file-local routine it calls, because the register choice depends on
 * what that callee clobbers.
 *
 * Two placeholders below serve that purpose and are not recovered code:
 *
 *   func_8008EEE4_stand_in - stands in for the file-local routine at
 *       0x8008EEE4, which this routine calls twice.  Only its interface
 *       matters here: one integer input, two doubles, one pointer written
 *       through, an integer result, and the set of callee-saved registers it
 *       destroys.  Its body is shaped to produce exactly that interface and is
 *       deliberately not a behavioural recovery of 0x8008EEE4; the store
 *       through the pointer inside its loop exists only to steer the register
 *       choice.  When 0x8008EEE4 is recovered for real it belongs in this unit
 *       in place of the stand-in.
 *
 *   func_8008F0B4_call_context - a minimal visible caller, needed for the same
 *       reason as in func_8008E420.c.  The real callers are the four call sites
 *       inside the large routine that begins at 0x8008F34C.
 */

#include "podcruise/types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Acmd;

struct Chan;

typedef struct Chan {
    /*0x00*/ u32 unk00;
    /*0x04*/ Acmd *(*unk04)(struct Chan *, s16 *, s32, s32, Acmd *);
} Chan;

typedef struct {
    /*0x00*/ Chan *unk00;
    /*0x04*/ u32 pad04[4];
    /*0x14*/ u32 unk14;
    /*0x18*/ s16 unk18;
    /*0x1A*/ s16 unk1A;
    /*0x1C*/ s16 unk1C;
    /*0x1E*/ s16 unk1E;
    /*0x20*/ s16 unk20;
    /*0x22*/ s16 unk22;
    /*0x24*/ s16 unk24;
    /*0x26*/ s16 unk26;
    /*0x28*/ s16 unk28;
    /*0x2A*/ s16 unk2A;
    /*0x2C*/ s16 unk2C;
    /*0x2E*/ s16 unk2E;
    /*0x30*/ s32 unk30;
    /*0x34*/ s32 unk34;
    /*0x38*/ s32 unk38;
    /*0x3C*/ u32 pad3C[3];
    /*0x48*/ s32 unk48;
} Obj;

typedef struct {
    f64 v[8];
} Blk;

extern s16 D_800A7D80[];
extern Blk D_800A7E80;
extern u32 func_80088360(u32);
extern void func_8008ED18(f64, f64 *);

static s32 func_8008EEE4_stand_in(f64 c, f64 b, s32 a, s16 *d);
static Acmd *func_8008F0B4(Obj *obj, s16 *dmemIn, s16 *dmemBase, s32 count,
                           s32 arg5, Acmd *cmd);

/* Placeholder for the file-local routine at 0x8008EEE4; see the note above. */
static s32 func_8008EEE4_stand_in(f64 c, f64 b, s32 a, s16 *d) {
    f64 tab[16];
    f64 z;
    f64 x;
    f64 y;
    s32 n;
    s32 i;

    if (a == 0) {
        if (c <= b) {
            *d = -1;
            return 0x7FFF;
        }
        *d = 0;
        return 0;
    }
    if (b < 1.0) {
        b = 1.0;
    }
    if (c <= 0.0) {
        c = 1.0;
    }
    *(Blk *)&tab[8] = D_800A7E80;
    n = (s32)((1.0 / (f64)a) * (f64)0x40000000);
    func_8008ED18(b / c, &z);
    i = (s32)(z * 16.0);
    x = tab[i] + z;
    y = 1.0;
    while (n != 0) {
        if (n & 1) {
            y = y * x;
            *d = (s16)n;
        }
        n = n >> 1;
        x = x * x;
    }
    *d = (s16)(s32)(y * y);
    return (s16)(s32)(y * y);
}

static Acmd *func_8008F0B4(Obj *obj, s16 *dmemIn, s16 *dmemBase, s32 count,
                           s32 arg5, Acmd *cmd) {
    Acmd *p;
    Acmd *q;
    Chan *ch;

    ch = obj->unk00;
    if (obj->unk48 != 1 || count == 0) {
        return cmd;
    }

    q = ch->unk04(ch, dmemIn, count, arg5, cmd);
    p = q + 2;
    q[0].w0 = ((u32)*dmemIn & 0xFFFF) | 0x08000000;
    q[0].w1 = ((u32)(count * 2) & 0xFFFF)
              | (((u32)(*dmemBase + 0x440) & 0xFFFF) << 16);
    q[1].w0 = ((u32)(*dmemBase + 0x580) & 0xFFFF) | 0x08080000;
    q[1].w1 = (((u32)(*dmemBase + 0x6C0) & 0xFFFF) << 16)
              | ((u32)(*dmemBase + 0x800) & 0xFFFF);

    if (obj->unk38 != 0) {
        obj->unk38 = 0;
        obj->unk28 = (s16)((D_800A7D80[obj->unk18] * obj->unk1A) >> 15);
        obj->unk26 = (s16)func_8008EEE4_stand_in((f64)obj->unk1C,
                                                 (f64)obj->unk28,
                                                 obj->unk34, &obj->unk24);
        obj->unk2E = (s16)((D_800A7D80[127 - obj->unk18] * obj->unk1A) >> 15);
        obj->unk2C = (s16)func_8008EEE4_stand_in((f64)obj->unk1E,
                                                 (f64)obj->unk2E,
                                                 obj->unk34, &obj->unk2A);
        {
            Acmd *c = p++;
            c->w0 = ((u32)obj->unk1C & 0xFFFF) | 0x09060000;
            c->w1 = 0;
        }
        {
            Acmd *c = p++;
            c->w0 = ((u32)obj->unk1E & 0xFFFF) | 0x09040000;
            c->w1 = 0;
        }
        {
            Acmd *c = p++;
            c->w0 = ((u32)obj->unk28 & 0xFFFF) | 0x09020000;
            c->w1 = ((u32)obj->unk26 << 16) | (u32)(u16)obj->unk24;
        }
        {
            Acmd *c = p++;
            c->w0 = ((u32)obj->unk2E & 0xFFFF) | 0x09000000;
            c->w1 = ((u32)obj->unk2C << 16) | (u32)(u16)obj->unk2A;
        }
        {
            Acmd *c = p++;
            c->w0 = ((u32)obj->unk20 & 0xFFFF) | 0x09080000;
            c->w1 = (u32)obj->unk22 & 0xFFFF;
        }
        {
            Acmd *c = p++;
            c->w0 = 0x03090000;
            c->w1 = func_80088360(obj->unk14);
        }
    } else {
        {
            Acmd *c = p++;
            c->w0 = 0x03080000;
            c->w1 = func_80088360(obj->unk14);
        }
    }

    *dmemIn += count * 2;
    obj->unk30 += count;
    return p;
}

/* Minimal visible caller; see the note above. */
Acmd *func_8008F0B4_call_context(Obj *obj, s32 arg5, s32 count, Acmd *cmd);

Acmd *func_8008F0B4_call_context(Obj *obj, s32 arg5, s32 count, Acmd *cmd) {
    s16 in;
    s16 base;

    in = 0;
    base = 0;
    cmd = func_8008F0B4(obj, &in, &base, count, arg5, cmd);
    cmd = func_8008F0B4(obj, &in, &base, count + 1, arg5, cmd);
    return cmd;
}
