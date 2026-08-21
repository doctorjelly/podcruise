/* Independently written from scratchpad spec specs/func_80000D80.md. */

#include "podcruise/types.h"

extern f32 func_800154D0(f32 *);

void func_80000D80(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 arg4) {
    f32 dot1;
    f32 dot2;
    f32 t;
    f32 d[3];

    d[0] = arg2[0] - arg1[0];
    d[1] = arg2[1] - arg1[1];
    d[2] = arg2[2] - arg1[2];
    func_800154D0(d);
    dot1 = arg1[0] * arg3[0] + arg1[1] * arg3[1] + arg1[2] * arg3[2];
    dot2 = d[0] * arg3[0] + d[1] * arg3[1] + d[2] * arg3[2];
    t = (arg4 - dot1) / dot2;
    arg0[0] = d[0] * t;
    arg0[1] = d[1] * t;
    arg0[2] = d[2] * t;
    arg0[0] = arg1[0] + arg0[0];
    arg0[1] = arg1[1] + arg0[1];
    arg0[2] = arg1[2] + arg0[2];
}
