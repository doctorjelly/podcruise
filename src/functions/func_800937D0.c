/* Implements the specification in specs/func_800937D0.md */
#include "podcruise/types.h"

extern s32 D_800A7FB0;
extern u8 D_8014C4D0[];
extern u8 D_8014C4D8[];
extern void func_800880E0(void *, void *, s32);
extern s32 func_8008C930(void *, s32, s32);

void func_800937D0(void) {
    D_800A7FB0 = 1;
    func_800880E0(D_8014C4D8, D_8014C4D0, 1);
    func_8008C930(D_8014C4D8, 0, 0);
}
