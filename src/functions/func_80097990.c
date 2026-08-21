/* Specification: scratchpad specs/func_80097990.md */
#include "podcruise/types.h"

extern s32 func_8008CA80(void);
extern void func_8008CAA0(s32 arg0);

extern u32 D_800A7B50;

void func_80097990(u32 arg0) {
    register s32 temp;

    temp = func_8008CA80();
    D_800A7B50 &= ~(arg0 & ~0x401);
    func_8008CAA0(temp);
}
