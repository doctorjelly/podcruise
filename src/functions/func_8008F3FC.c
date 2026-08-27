/* Independently written from scratchpad spec specs/func_8008F3FC.md.
 *
 * Packaging note.  This translation unit was built one optimisation level
 * above the rest of the ROM.  At that level the compiler allocates registers
 * across the whole unit, so the two file-local routines this body calls receive
 * their arguments in registers no ordinary calling convention would choose.
 * Reproducing the call sites therefore requires those routines to sit in the
 * same unit, file-local, exactly as they do in src/functions/func_8008F0B4.c
 * and src/functions/func_8008F34C.c.  The two placeholders reproduced below
 * (func_8008EEE4_stand_in and the local copies of the two routines) are carried
 * over from those recoveries for that purpose and are not new recovered code.
 */

#include "podcruise/types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Acmd;

struct Obj;

typedef struct Obj {
    /*0x00*/ struct Obj *unk00;
    /*0x04*/ Acmd *(*unk04)(struct Obj *, s16 *, s32, s32, Acmd *);
    /*0x08*/ void (*unk08)(struct Obj *, s32, s32);
    /*0x0C*/ u32 pad0C[2];
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
    /*0x3C*/ struct Event *unk3C;
    /*0x40*/ s32 unk40;
    /*0x44*/ s32 pad44;
    /*0x48*/ s32 unk48;
} Obj;

typedef struct Event {
    /*0x00*/ struct Event *next;
    /*0x04*/ s32 time;
    /*0x08*/ u16 type;
    /*0x0A*/ s16 flag;
    /*0x0C*/ union {
        s32 i;
        f32 f;
        u8 *p;
    } arg0C;
    /*0x10*/ union {
        s32 w;
        struct {
            s16 h;
            u8 b2;
            u8 b3;
        } b;
    } arg10;
    /*0x14*/ s32 arg14;
    /*0x18*/ s32 arg18;
} Event;

typedef struct {
    f64 v[8];
} Blk;

extern s16 D_800A7D80[];
extern Blk D_800A7E80;
extern void *D_800A6990;
extern u32 func_80088360(u32);
extern void func_8008ED18(f64, f64 *);
extern void func_80088450(void *, void *);
extern void func_800884E8(Event *);

static s32 func_8008EEE4_stand_in(f64 c, f64 b, s32 a, s16 *d);
static Acmd *func_8008F0B4(Obj *obj, s16 *dmemIn, s16 *dmemBase, s32 count,
                           s32 arg5, Acmd *cmd);
static f32 func_8008F34C(f32 value, s32 exponent, s16 rateHigh, u16 rateLow);
Acmd *func_8008F3FC(Obj *obj, s32 arg1, s32 count, s32 time, Acmd *cmd);

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
    Obj *ch;

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

static f32 func_8008F34C(f32 value, s32 exponent, s16 rateHigh, u16 rateLow) {
    f32 factor;
    f32 accumulated;
    s32 step;

    exponent = exponent >> 3;
    if (exponent == 0) {
        return value;
    }
    factor = ((f32)(rateHigh << 16) + (f32)rateLow) / 65536.0f;
    accumulated = 1.0f;
    for (step = 0; step < 32; step++) {
        if (exponent & 1) {
            accumulated = accumulated * factor;
        }
        exponent = exponent >> 1;
        if (exponent == 0) {
            break;
        }
        factor = factor * factor;
    }
    return value * accumulated;
}

Acmd *func_8008F3FC(Obj *obj, s32 arg1, s32 count, s32 time, Acmd *cmd) {
    union {
        f32 f;
        s32 i;
    } bits;
    s16 dmemIn;
    s16 dmemBase;
    Event *event;
    Event *note;
    Event *done;
    s32 delta;
    s32 cur;
    Acmd *out;
    Obj *o;

    (void)arg1;
    o = obj;
    out = cmd;
    cur = time;
    dmemIn = 0;
    dmemBase = 0;

    while (obj->unk3C != 0) {
        event = o->unk3C;
        delta = event->time - cur;
        if (count < delta) {
            break;
        }
        cur = event->time;

        switch (event->type) {
        case 0:
            *(s32 *)(event->arg0C.p + 0xD8) = 0;
            func_80088450(D_800A6990, event->arg0C.p);
            break;

        case 11:
        case 12:
        case 16:
            out = func_8008F0B4(o, &dmemIn, &dmemBase, delta, time, out);
            if (o->unk30 >= o->unk34) {
                o->unk28 = (s16)((D_800A7D80[o->unk18] * o->unk1A) >> 15);
                o->unk30 = o->unk34;
                o->unk1C = o->unk28;
                o->unk2E =
                    (s16)((D_800A7D80[127 - o->unk18] * o->unk1A) >> 15);
                o->unk1E = o->unk2E;
            } else {
                o->unk1C = (s16)func_8008F34C((f32)o->unk1C, o->unk30,
                                                o->unk26, (u16)o->unk24);
                o->unk1E = (s16)func_8008F34C((f32)o->unk1E, o->unk30,
                                                o->unk2C, (u16)o->unk2A);
            }
            if (o->unk1C == 0) {
                o->unk1C = 1;
            }
            if (o->unk1E == 0) {
                o->unk1E = 1;
            }
            if ((s16)o->unk3C->type == 12) {
                o->unk18 = (s16)o->unk3C->arg0C.i;
            }
            if ((s16)o->unk3C->type == 11) {
                o->unk30 = 0;
                o->unk1A = (s16)((o->unk3C->arg0C.i * o->unk3C->arg0C.i)
                                   >> 15);
                o->unk34 = o->unk3C->arg10.w;
            }
            if ((s16)o->unk3C->type == 16) {
                o->unk20 = D_800A7D80[o->unk3C->arg0C.i];
                o->unk22 = D_800A7D80[127 - o->unk3C->arg0C.i];
            }
            o->unk38 = 1;
            break;

        case 13:
            note = event;
            if (note->flag != 0) {
                o->unk08(o, 8, 0);
            }
            o->unk08(o, 5, note->arg18);
            o->unk08(o, 9, 0);
            o->unk38 = 1;
            o->unk30 = 0;
            o->unk34 = note->arg14;
            o->unk1A = (s16)((note->arg10.b.h * note->arg10.b.h) >> 15);
            o->unk18 = note->arg10.b.b2;
            o->unk20 = D_800A7D80[note->arg10.b.b3];
            o->unk22 = D_800A7D80[127 - note->arg10.b.b3];
            if (note->arg14 != 0) {
                o->unk1C = 1;
                o->unk1E = 1;
            } else {
                o->unk1C =
                    (s16)((D_800A7D80[o->unk18] * o->unk1A) >> 15);
                o->unk1E =
                    (s16)((D_800A7D80[127 - o->unk18] * o->unk1A) >> 15);
            }
            if (o->unk00 != 0) {
                bits.f = note->arg0C.f;
                o->unk00->unk08(o->unk00, 7, bits.i);
            }
            break;

        case 14:
            note = event;
            if (note->flag != 0) {
                o->unk08(o, 8, 0);
            }
            o->unk08(o, 5, note->arg0C.i);
            o->unk08(o, 9, 0);
            break;

        case 15:
            out = func_8008F0B4(o, &dmemIn, &dmemBase, delta, time, out);
            o->unk08(o, 4, 0);
            break;

        default:
            out = func_8008F0B4(o, &dmemIn, &dmemBase, delta, time, out);
            o->unk08(o, (s16)o->unk3C->type, o->unk3C->arg0C.i);
            break;
        }

        dmemIn += delta * 2;
        count -= delta;
        done = o->unk3C;
        o->unk3C = done->next;
        if (done->next == 0) {
            o->unk40 = 0;
        }
        func_800884E8(done);
    }

    out = func_8008F0B4(o, &dmemIn, &dmemBase, count, time, out);
    if (o->unk34 < o->unk30) {
        o->unk30 = o->unk34;
    }
    return out;
}
