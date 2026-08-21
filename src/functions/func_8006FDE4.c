/* Independently written from scratchpad spec specs/func_8006FDE4.md. */

#include "podcruise/types.h"

typedef struct Unk8006FDE4Sub {
    /* 0x0000 */ u8 pad0[0x18];
    /* 0x0018 */ s32 *unk18;
} Unk8006FDE4Sub;

typedef struct Unk8006FDE4 {
    /* 0x0000 */ u8 pad0[0x60];
    /* 0x0060 */ s32 unk60;
    /* 0x0064 */ s32 unk64;
    /* 0x0068 */ u8 pad68[0x1E70 - 0x68];
    /* 0x1E70 */ Unk8006FDE4Sub *unk1E70;
} Unk8006FDE4;

extern u32 D_80000318;

extern void func_800093B0(s32, s32, s32, s32, s32, s32, s32);
extern void func_80031B70(Unk8006FDE4 *, s32);
extern void func_8007134C(Unk8006FDE4 *, s32);

void func_8006FDE4(Unk8006FDE4 *arg0) {
    s32 value;

    if (arg0->unk60 & 0x1000) {
        arg0->unk64 &= ~0x1C000;
        arg0->unk60 &= ~0x1000;
        if ((arg0->unk60 & 0xF) == 2) {
            if (!(arg0->unk60 & 0x4000)) {
                func_8007134C(arg0, 0);
            }
            if (arg0->unk60 & 0x20) {
                func_80031B70(arg0, 0xC);
                if (D_80000318 >= 0x800000 || (arg0->unk60 & 0x120) != 0) {
                    value = arg0->unk1E70->unk18[0];
                } else {
                    value = -1;
                }
                func_800093B0(1, value, 0xE, 0xE, 0xE, 0xE, 0xE);
            }
        }
    }
}
