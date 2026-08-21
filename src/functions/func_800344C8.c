/* Independently written from scratchpad spec specs/func_800344C8.md. */

#include "podcruise/types.h"

extern s32 D_800A3FF0;
extern s32 D_800A3FF4;

void func_800344C8(void) {
    D_800A3FF4 = 1;

    if (D_800A3FF0 > 0) {
        D_800A3FF0 -= 1;
    }
}
