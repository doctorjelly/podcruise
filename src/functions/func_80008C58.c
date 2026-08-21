/* Recovered from specs/functions/recovered/medium_pipeline_tranche.md. */
#include "podcruise/types.h"

extern f32 sqrtf(f32 value);
#if defined(__sgi)
#pragma intrinsic (sqrtf)
#endif

extern void func_8000B98C(void *matrix, f32 *point);
extern void func_80017AC0(f32 *plane, f32 *axis, f32 *origin);
extern void func_800819A4(f32 *plane, f32 *point, f32 *result);
extern f32 func_800154D0(f32 *vector);
extern void func_80015538(f32 *out, f32 *left, f32 *right);
extern f32 func_800153C0(f32 *vector);
extern void func_80008760(s32 arg0, s16 arg1, f32 arg2, f32 arg3, s16 arg4, s32 arg5);

extern f32 D_8009AD08;
extern f32 D_8009AD0C;
extern f64 D_800A81E8;
extern f32 D_800A81F0;
extern f64 D_800A81F8;
extern s32 D_800D697C;

void func_80008C58(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 *point, s32 arg5) {
    f32 matrix[4][4];
    f32 plane[4];
    f32 delta[3];
    f32 offset[3];
    f32 cross[3];
    f32 length;
    f32 level;
    f32 fade;
    f32 side;
    f32 lengthSquared;
    f32 distance;

    func_8000B98C(matrix, point);
    func_80017AC0(plane, matrix[2], matrix[3]);

    delta[0] = point[0] - matrix[3][0];
    delta[1] = point[1] - matrix[3][1];
    delta[2] = point[2] - matrix[3][2];
    lengthSquared = (delta[0] * delta[0] + delta[1] * delta[1]) + delta[2] * delta[2];

    if (D_8009AD0C * D_8009AD0C <= lengthSquared) {
        return;
    }

    if (lengthSquared <= D_8009AD08 * D_8009AD08) {
        fade = 1.0f;
    } else {
        distance = sqrtf(lengthSquared);
        fade = 1.0 - (distance - D_8009AD08) / (D_8009AD0C - D_8009AD08);
        if (fade < D_800A81E8) {
            return;
        }
        if (1.0 < fade) {
            fade = 1.0f;
        }
    }

    if (!(D_800D697C & 8)) {
        side = 0;
    } else {
        func_800819A4(plane, point, offset);
        offset[0] = offset[0] - matrix[3][0];
        offset[1] = offset[1] - matrix[3][1];
        offset[2] = offset[2] - matrix[3][2];
        if (offset[0] < D_800A81F0 && -offset[0] < D_800A81F0 &&
            offset[1] < D_800A81F8 && -offset[1] < D_800A81F8) {
            side = 0;
        } else {
            func_800154D0(offset);
            func_80015538(cross, offset, matrix[1]);
            length = func_800153C0(cross);
            side = length;
            if ((cross[0] * matrix[2][0] + cross[1] * matrix[2][1]) +
                cross[2] * matrix[2][2] < 0.0f) {
                side = -length;
            }
        }
    }

    level = fade * arg3;
    if (0.0f < level) {
        func_80008760(arg0, (s16)arg1, arg2, level,
                      (s16)(side * 45.0f + 64.0f), arg5);
    }
}
