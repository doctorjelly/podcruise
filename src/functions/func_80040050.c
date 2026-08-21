/* Recovered per specs/func_80040050.md (worker specification). */
#include "podcruise/types.h"

typedef struct Sub80040050 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 *unk18;
} Sub80040050;

typedef struct Actor80040050 {
    s32 unk0[0x18];
    s32 unk60;
    s32 pad64[0x783];
    Sub80040050 *unk1E70;
} Actor80040050;

typedef struct Owner80040050 {
    s32 unk0[0x3D];
    Actor80040050 *unkF4;
} Owner80040050;

extern f32 D_800A4AD4;
extern f32 D_800A6664;
extern f64 D_80120BF0;
extern void func_80008B14(s32, s16, f32, f32, s32);

void func_80040050(Owner80040050 *arg0, f32 arg1) {
    Actor80040050 *actor;
    f32 previous;

    previous = D_800A4AD4;
    actor = arg0->unkF4;
    if (arg1 == -1.0f) {
        D_800A4AD4 = arg1;
    }
    if (arg1 == -2.0f) {
        if (D_800A4AD4 != -1.0f) {
            D_800A4AD4 = D_800A4AD4 + D_80120BF0;
        }
    } else if (D_800A4AD4 < arg1) {
        D_800A4AD4 = arg1;
    }
    if (D_800A4AD4 != -1.0f) {
        if (D_800A4AD4 >= 6.0f && previous < 6.0f && arg1 < 100.0f && actor != 0 &&
            *actor->unk1E70->unk18 != 0xE) {
            func_80008B14(0x74, 6, 0.25f, 0.5f, 0);
        }
        if (D_800A4AD4 < 6.0f) {
            D_800A6664 = 0.0f;
        } else if (actor != 0 && (actor->unk60 & 0x20)) {
            D_800A6664 = D_800A6664 + D_80120BF0;
        }
    }
}
