/* Implements $S/specs/func_8006FEE8.md (per-frame racer state update). */
#include "podcruise/types.h"

typedef struct Vec3f8006FEE8 {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
} Vec3f8006FEE8;

typedef struct Sub8006FEE8 {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ s32 *unk18;
    /* 0x1C */ u8 pad1C[0x74 - 0x1C];
    /* 0x74 */ f32 unk74;
    /* 0x78 */ s32 unk78;
} Sub8006FEE8;

typedef struct Obj8006FEE8 {
    /* 0x0000 */ u8 pad0[0x4];
    /* 0x0004 */ s16 unk4;
    /* 0x0006 */ u8 pad6[0x20 - 0x6];
    /* 0x0020 */ f32 unk20;
    /* 0x0024 */ f32 unk24;
    /* 0x0028 */ f32 unk28;
    /* 0x002C */ u8 pad2C[0x50 - 0x2C];
    /* 0x0050 */ f32 unk50;
    /* 0x0054 */ f32 unk54;
    /* 0x0058 */ f32 unk58;
    /* 0x005C */ u8 pad5C[0x60 - 0x5C];
    /* 0x0060 */ s32 unk60;
    /* 0x0064 */ s32 unk64;
    /* 0x0068 */ u8 pad68[0x7C - 0x68];
    /* 0x007C */ f32 unk7C;
    /* 0x0080 */ u8 pad80[0xAC - 0x80];
    /* 0x00AC */ f32 unkAC;
    /* 0x00B0 */ u8 padB0[0x110 - 0xB0];
    /* 0x0110 */ f32 unk110;
    /* 0x0114 */ u8 pad114[0x1A0 - 0x114];
    /* 0x01A0 */ f32 unk1A0;
    /* 0x01A4 */ u8 pad1A4[0x1F0 - 0x1A4];
    /* 0x01F0 */ f32 unk1F0;
    /* 0x01F4 */ u8 pad1F4[0x264 - 0x1F4];
    /* 0x0264 */ f32 unk264;
    /* 0x0268 */ f32 unk268;
    /* 0x026C */ u8 pad26C[0x31C - 0x26C];
    /* 0x031C */ s32 unk31C;
    /* 0x0320 */ u8 pad320[0x1998 - 0x320];
    /* 0x1998 */ s32 unk1998;
    /* 0x199C */ u8 pad199C[0x1E70 - 0x199C];
    /* 0x1E70 */ Sub8006FEE8 *unk1E70;
} Obj8006FEE8;

typedef struct Report8006FEE8 {
    /* 0x00 */ u32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ u8 pad10[0x28 - 0x10];
} Report8006FEE8;

extern f64 D_80120BF0;

extern void func_8001535C(f32 *, f32 *, f32 *);
extern void func_8003B184(f32 *, f32 *, f32);
extern s32 func_8003FDCC(s32, f32 *, f32, Obj8006FEE8 *, s32, f32 *, f32 *, Obj8006FEE8 **);
extern void func_8006E034(Obj8006FEE8 *);
extern void func_8006FB00(Obj8006FEE8 *);
extern void func_8006FC80(Obj8006FEE8 *);
extern void func_8006FDE4(Obj8006FEE8 *);
extern void func_8006FED0(Obj8006FEE8 *);
extern void func_800704A8(Obj8006FEE8 *, f32);
extern f32 func_80085EB0(f32 *);

void func_8006FEE8(Obj8006FEE8 *arg0) {
    volatile Report8006FEE8 report;
    f32 matrix[20];
    Obj8006FEE8 *results[11];
    f32 distances[8];
    s32 count;
    f32 offsets[25];
    f32 origin[5];
    register Sub8006FEE8 *sub;
    f32 value;
    f32 dot;
    s32 sample;
    s32 index;

    if (arg0->unk60 & 0x80) {
        if (((arg0->unk60 & 0xF) != 2) || (arg0->unk60 & 0x6000)) {
            arg0->unk110 = 0.0f;
        } else if ((5.0f < arg0->unk110) ||
                   ((arg0->unk60 & 0x100) && (2.0f < arg0->unk110))) {
            arg0->unk60 |= 0x1000;
        }
    }
    if (arg0->unk60 & 0x20000) {
        func_800704A8(arg0, 0.5f);
        arg0->unk60 &= ~0x20000;
    }
    if (arg0->unk60 & 0x80) {
        sub = arg0->unk1E70;
        if ((sub->unk18[0] == 2) && (200.0f < arg0->unk1A0)) {
            if (sub->unk78 + 1 >= 3) {
                value = 100.0f;
                origin[0] = arg0->unk50;
                origin[1] = arg0->unk54;
                origin[2] = arg0->unk58;
                count = func_8003FDCC(0x54657374, origin, value * value, (Obj8006FEE8 *)0, 2,
                                      distances, offsets, results);
                for (index = 0; index < count; index++) {
                    if (results[index] != arg0) {
                        func_8001535C(origin, &results[index]->unk50, &arg0->unk50);
                        dot = origin[0] * arg0->unk20 + origin[1] * arg0->unk24 + origin[2] * arg0->unk28;
                        if (0.0f < dot) {
                            func_8006E034(arg0);
                        }
                    }
                }
            }
        }
    }
    sub = arg0->unk1E70;
    if (sub->unk74 < 10.0f) {
        arg0->unk268 = 5.0f;
    }
    if (arg0->unk31C != 0) {
        if (arg0->unk268 < 5.0f) {
            arg0->unk268 = 5.0f;
        }
    } else {
        arg0->unk268 = (f32)((f64)arg0->unk268 - D_80120BF0);
    }
    sample = (s32)func_80085EB0(&arg0->unk50);
    arg0->unk1998 = sample;
    value = ((f32)sample - 400.0f) / 600.0f;
    if (((f64)value < 1.0) || (arg0->unk60 & 0x20) || (arg0->unk64 & 0x4000000)) {
        if (arg0->unk64 & 2) {
            arg0->unk64 &= ~2;
            func_8003B184(&arg0->unkAC, matrix, 0.0f);
            arg0->unk50 = matrix[12];
            arg0->unk54 = matrix[13];
            arg0->unk58 = matrix[14];
            arg0->unk64 |= 0x10000000;
        }
    }
    arg0->unk60 &= ~0x80000;
    if (!(arg0->unk60 & 0x20)) {
        if (arg0->unk264 <= 0.0f) {
            arg0->unk60 |= 0x10;
        }
    }
    arg0->unk60 &= ~0x200000;
    if ((f64)arg0->unk7C * 0.75 < (f64)arg0->unk1A0) {
        if (!(arg0->unk60 & 0x7000) && !(arg0->unk64 & 0x4000)) {
            arg0->unk60 |= 0x200000;
        }
    }
    if (((f64)arg0->unk7C < (f64)arg0->unk1A0) && (arg0->unk60 & 0x800000)) {
        arg0->unk60 |= 0x40000000;
    } else {
        arg0->unk60 &= ~0x40000000;
    }
    func_8006FB00(arg0);
    if (0.0f < arg0->unk264) {
        arg0->unk264 = arg0->unk264 - (f32)D_80120BF0;
    }
    if (arg0->unk60 & 0x20) {
        report.unk0 = 0x526D5468;
        report.unk4 = arg0->unk4;
        report.unkC = arg0->unk1F0;
    }
    func_8006FED0(arg0);
    if (arg0->unk60 & 0x800) {
        func_8006FC80(arg0);
    }
    func_8006FDE4(arg0);
    (void)&report;
}
