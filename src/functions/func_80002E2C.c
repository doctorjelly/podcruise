/* Recovered per specification specs/func_80002E2C.md (worker scratchpad) */
#include "podcruise/types.h"

extern f32 D_800AE8E0;
extern f32 D_800AE908[3];

s32 func_80002E2C(f32 *arg0, f32 *arg1, f32 *arg2) {
    f32 a[3];
    f32 b[3];
    f32 c[3];

    a[0] = arg0[0] - D_800AE908[0];
    a[1] = arg0[1] - D_800AE908[1];
    a[2] = arg0[2] - D_800AE908[2];
    b[0] = arg1[0] - D_800AE908[0];
    b[1] = arg1[1] - D_800AE908[1];
    b[2] = arg1[2] - D_800AE908[2];
    c[0] = arg2[0] - D_800AE908[0];
    c[1] = arg2[1] - D_800AE908[1];
    c[2] = arg2[2] - D_800AE908[2];

    if ((a[0] < -D_800AE8E0 && b[0] < -D_800AE8E0 && c[0] < -D_800AE8E0) ||
        (a[0] > D_800AE8E0 && b[0] > D_800AE8E0 && c[0] > D_800AE8E0) ||
        (a[1] < -D_800AE8E0 && b[1] < -D_800AE8E0 && c[1] < -D_800AE8E0) ||
        (a[1] > D_800AE8E0 && b[1] > D_800AE8E0 && c[1] > D_800AE8E0) ||
        (a[2] < -D_800AE8E0 && b[2] < -D_800AE8E0 && c[2] < -D_800AE8E0) ||
        (a[2] > D_800AE8E0 && b[2] > D_800AE8E0 && c[2] > D_800AE8E0)) {
        return 0;
    }
    return 1;
}
