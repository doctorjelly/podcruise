/* Specification: specs/func_8002F144.md (worker-authored) */
#include "podcruise/types.h"

extern s32 D_800A26F8;
extern s32 D_800A26F4;
extern void func_80008B14(s32 arg0, s16 arg1, f32 arg2, f32 arg3, s32 arg4);

void func_8002F144(void) {
    if (D_800A26F8 == 0) {
        func_80008B14(0x4D, 6, 0.25f, 1.0f, 0);
        D_800A26F4 = 3;
    }
}
