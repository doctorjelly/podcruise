/* Recovered per specification specs/func_80033140.md (worker scratchpad) */
#include "podcruise/types.h"

extern f32 D_800AA474;

extern f32 func_800153C0(f32 *);
extern f32 func_80004FB0(s32, f32 *, f32 *, f32 *);

s32 func_80033140(f32 *arg0, f32 *arg1, s32 arg2, f32 *arg3) {
    f32 ray[7];
    f32 hitNormal[3];
    f32 spare1[3];
    s32 result;
    f32 moved[3];
    f32 push;
    f32 spare2;
    f32 planeOffset;
    f32 hitPlane[3];

    result = 0;
    ray[3] = arg0[0] - arg1[0];
    ray[4] = arg0[1] - arg1[1];
    ray[5] = arg0[2] - arg1[2];
    ray[6] = func_800153C0(&ray[3]);
    if (D_800AA474 < ray[6]) {
        ray[0] = arg1[0];
        ray[1] = arg1[1];
        ray[2] = arg1[2];
        ray[3] = ray[3] * (1.0f / ray[6]);
        ray[4] = ray[4] * (1.0f / ray[6]);
        ray[5] = ray[5] * (1.0f / ray[6]);
        if (0.0f <= func_80004FB0(arg2, ray, hitNormal, hitPlane)) {
            planeOffset = hitPlane[2] * hitNormal[2] +
                          (hitNormal[0] * hitPlane[0] + hitNormal[1] * hitPlane[1]);
            push = (planeOffset -
                    (hitPlane[2] * arg0[2] +
                     (arg0[0] * hitPlane[0] + arg0[1] * hitPlane[1]))) + 2.0f;
            moved[0] = hitPlane[0] * push;
            moved[1] = hitPlane[1] * push;
            moved[2] = hitPlane[2] * push;
            moved[0] = moved[0] + arg0[0];
            moved[1] = moved[1] + arg0[1];
            moved[2] = moved[2] + arg0[2];
            arg0[0] = moved[0];
            arg0[1] = moved[1];
            arg0[2] = moved[2];
            arg3[0] = hitPlane[0];
            arg3[1] = hitPlane[1];
            arg3[2] = hitPlane[2];
            result = 1;
        }
    }
    (void)spare1; (void)spare2;
    return result;
}
