/* Recovered from specification $S/specs/func_80033010.md */
#include "podcruise/types.h"

extern f32 D_800AA470;
extern f32 func_800153C0(f32 *);
extern f32 func_80004FB0(void *, f32 *, f32 *, void *);
s32 func_80033010(f32 *arg0, f32 *arg1, void *arg2, void *arg3);

s32 func_80033010(f32 *arg0, f32 *arg1, void *arg2, void *arg3) {
    f32 delta[4];
    f32 point[3];
    f32 hit[4];
    f32 r0;
    f32 r1;
    f32 r2;
    s32 result;

    result = 0;
    delta[0] = arg0[0] - arg1[0];
    delta[1] = arg0[1] - arg1[1];
    delta[2] = arg0[2] - arg1[2];
    delta[3] = func_800153C0(delta);
    if (delta[3] > D_800AA470) {
        point[0] = arg1[0];
        point[1] = arg1[1];
        point[2] = arg1[2];
        r0 = 1.0f / delta[3];
        delta[0] = delta[0] * r0;
        r1 = 1.0f / delta[3];
        delta[1] = delta[1] * r1;
        r2 = 1.0f / delta[3];
        delta[2] = delta[2] * r2;
        if (func_80004FB0(arg2, point, hit, arg3) >= 0.0f) {
            arg0[0] = arg1[0];
            arg0[1] = arg1[1];
            arg0[2] = arg1[2];
            result = 1;
        }
    }
    return result;
}
