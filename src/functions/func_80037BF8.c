/* Recovered from the specification in worker notes specs/func_80037BF8.md. */
#include "podcruise/types.h"

void func_80037BF8(f32 *arg0, f32 *arg1, f32 *arg2) {
    s32 i;

    for (i = 0; i < 3; i++) {
        arg0[9 + i] += -arg2[0] * arg1[i];
        arg0[9 + i] += -arg2[1] * arg1[i + 3];
        arg0[9 + i] += -arg2[2] * arg1[i + 6];
        arg0[9 + i] += arg2[i];
    }
}
