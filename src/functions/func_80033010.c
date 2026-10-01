/* Recovered from specification $S/specs/func_80033010.md */
#include "podcruise/types.h"

extern f32 D_800AA470;
extern f32 func_800153C0(f32 *);
extern f32 func_80004FB0(void *, f32 *, f32 *, void *);
s32 func_80033010(f32 *arg0, f32 *arg1, void *arg2, void *arg3);

s32 func_80033010(f32 *arg0, f32 *arg1, void *arg2, void *arg3) {
    f32 ray[7];
    f32 hit[4];
    f32 *dir;
    f32 spare[2];
    s32 result;

    result = 0;
    dir = &ray[3];
    dir[0] = arg0[0] - arg1[0];
    dir[1] = arg0[1] - arg1[1];
    dir[2] = arg0[2] - arg1[2];
    ray[6] = func_800153C0(dir);
    if (D_800AA470 < ray[6]) {
        ray[0] = arg1[0];
        ray[1] = arg1[1];
        ray[2] = arg1[2];
        dir[0] = (1.0f / ray[6]) * dir[0];
        dir[1] = (1.0f / ray[6]) * dir[1];
        dir[2] = (1.0f / ray[6]) * dir[2];
        if (0.0f <= func_80004FB0(arg2, ray, hit, arg3)) {
            arg0[0] = arg1[0];
            arg0[1] = arg1[1];
            arg0[2] = arg1[2];
            result = 1;
        }
    }
    (void)spare;
    return result;
}
