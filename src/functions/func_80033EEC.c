/* Independently written from scratchpad spec specs/func_80033EEC.md. */

#include "podcruise/types.h"

extern s32 D_800A3FF0;
extern s32 D_800A3FF4;
extern f32 D_80112EA0[][12];

void func_80033EEC(f32 *arg0) {
    f32 *dst;

    D_800A3FF4 = 1;
    if (D_800A3FF0 < 32) {
        D_800A3FF0 = D_800A3FF0 + 1;
        dst = D_80112EA0[D_800A3FF0];
        dst[0] = arg0[0];
        dst[1] = arg0[1];
        dst[2] = arg0[2];
        dst[3] = arg0[3];
        dst[4] = arg0[4];
        dst[5] = arg0[5];
        dst[6] = arg0[6];
        dst[7] = arg0[7];
        dst[8] = arg0[8];
        dst[9] = arg0[9];
        dst[10] = arg0[10];
        dst[11] = arg0[11];
    }
}
