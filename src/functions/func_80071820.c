/* Independently written from the specification for func_80071820. */

#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 pad000[0x60];
    /* 0x060 */ u32 unk060;
    /* 0x064 */ u32 unk064;
    /* 0x068 */ u8 pad068[0x38];
    /* 0x0A0 */ f32 unk0A0;
    /* 0x0A4 */ u8 pad0A4[0x1CC];
    /* 0x270 */ f32 unk270[6];
    /* 0x288 */ f32 unk288[6];
    /* 0x2A0 */ u32 unk2A0[6];
    /* 0x2B8 */ u8 pad2B8[0xC];
    /* 0x2C4 */ f32 unk2C4;
} Func80071820Target;

extern s32 D_800A52D4;

void func_80071820(Func80071820Target *arg0, s32 arg1, f32 arg2) {
    if (D_800A52D4 != 0) {
        return;
    }
    if (arg0->unk060 & 0x4000) {
        return;
    }
    if (arg0->unk060 & 0x2000) {
        return;
    }
    if (arg0->unk064 & 0x02000000) {
        return;
    }
    arg0->unk060 &= ~0x00800000;
    arg0->unk288[arg1] += arg2 * arg0->unk0A0;
    if (arg0->unk288[arg1] > 1.0f) {
        arg0->unk288[arg1] = 1.0f;
    }
    arg0->unk2A0[arg1] |= 1;
    if (arg0->unk270[arg1] < arg0->unk288[arg1]) {
        arg0->unk270[arg1] = arg0->unk288[arg1];
    }
    arg0->unk2C4 += arg2;
}
