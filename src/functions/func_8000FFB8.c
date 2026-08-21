/* Independently written from scratchpad spec specs/func_8000FFB8.md. */
#include "podcruise/types.h"

extern f32 D_800D5C60[40][3];

void func_8000FFB8(s32 arg0, f32 *arg1) {
    f32 *dst;

    if (arg0 < 40) {
        dst = D_800D5C60[arg0];
        dst[0] = arg1[0];
        dst[1] = arg1[1];
        dst[2] = arg1[2];
    }
}
