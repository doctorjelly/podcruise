/* Independently written from scratchpad spec specs/func_8000097C.md. */

#include "podcruise/types.h"

extern f32 D_800A80F8;
extern f32 D_800AE8B0;
extern f32 D_800AE8B8[3];
extern f32 D_800AE8C8[3];
extern s32 D_800AE8D8;
extern s32 D_800AE938;
extern s32 D_800AEC7C;

void func_8000097C(f32 arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    f32 d[3];

    if (D_800AE8B0 - D_800A80F8 < arg0) {
        d[0] = arg1[0] - arg2[0];
        d[1] = arg1[1] - arg2[1];
        d[2] = arg1[2] - arg2[2];
        if (d[0] * arg3[0] + d[1] * arg3[1] + d[2] * arg3[2] >
            d[0] * D_800AE8C8[0] + d[1] * D_800AE8C8[1] + d[2] * D_800AE8C8[2]) {
            D_800AE8B0 = arg0;
            D_800AE8B8[0] = arg2[0];
            D_800AE8B8[1] = arg2[1];
            D_800AE8B8[2] = arg2[2];
            D_800AE8C8[0] = arg3[0];
            D_800AE8C8[1] = arg3[1];
            D_800AE8C8[2] = arg3[2];
            D_800AE8D8 = D_800AE938;
            D_800AEC7C = 1;
        }
    } else {
        D_800AE8B0 = arg0;
        D_800AE8B8[0] = arg2[0];
        D_800AE8B8[1] = arg2[1];
        D_800AE8B8[2] = arg2[2];
        D_800AE8C8[0] = arg3[0];
        D_800AE8C8[1] = arg3[1];
        D_800AE8C8[2] = arg3[2];
        D_800AE8D8 = D_800AE938;
        D_800AEC7C = 1;
    }
}
