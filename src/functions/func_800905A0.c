/* Implements the specification in specs/func_800905A0.md */
#include "podcruise/types.h"

extern s32 D_800A7EC0;
extern u8 D_8014C3B0[];
extern u8 D_8014C3B8[];
extern void func_800880E0(void *, void *, s32);
extern s32 func_8008C930(void *, s32, s32);

void func_800905A0(void) {
    D_800A7EC0 = 1;
    func_800880E0(D_8014C3B8, D_8014C3B0, 1);
    func_8008C930(D_8014C3B8, 0, 0);
}
