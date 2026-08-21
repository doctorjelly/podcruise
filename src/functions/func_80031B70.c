/* Implements the specification in specs/func_80031B70.md */
#include "podcruise/types.h"

extern void func_800319F4(u8, s32);
extern void func_80031BBC(u8, s32);

typedef struct Unk80031B70 {
    /* 0x0000 */ u8 pad0[0x64];
    /* 0x0064 */ s32 unk64;
    /* 0x0068 */ u8 pad68[0x1E70 - 0x68];
    /* 0x1E70 */ u8 *unk1E70;
} Unk80031B70;

void func_80031B70(Unk80031B70 *arg0, s32 arg1) {
    if (arg0->unk64 & 0x4000000) {
        func_80031BBC(arg0->unk1E70[0x10], arg1);
    } else {
        func_800319F4(arg0->unk1E70[0x10], arg1);
    }
}
