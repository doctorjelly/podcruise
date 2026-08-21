/* Implements the specification in specs/func_80097D20.md */
#include "podcruise/types.h"

extern s32 func_8008CA80(void);
extern void func_8008CAA0(s32);
extern u32 D_800A7B50;

void func_80097D20(u32 arg0) {
    register s32 temp;

    temp = func_8008CA80();
    D_800A7B50 |= arg0;
    func_8008CAA0(temp);
}
