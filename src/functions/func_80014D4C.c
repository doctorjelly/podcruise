/* Independently written from specs/functions/recovered/medium_control_math_tranche.md. */

#include "podcruise/types.h"

extern f32 sqrtf(f32 value);
#if defined(__sgi)
#pragma intrinsic (sqrtf)
#endif

extern f32 D_800A8790;
extern f32 D_800A8794;
extern f32 D_800A8798;
extern f32 D_800A879C;
extern f32 D_800A87A0;
extern f32 D_800A87A4;
extern f32 D_800A87A8;
extern f32 D_800A87AC;
extern f32 D_800A87B0;
extern f32 D_800A87B4;
extern f64 D_800A87B8;

f32 func_80014D4C(f32 value) {
    f32 root;
    f32 original;
    f32 square;
    f32 cube;
    f32 fifth;
    f32 seventh;
    f32 result;
    s32 complement;

    if (D_800A8790 < value) {
        return 90.0f;
    }
    if (value < D_800A8794) {
        return -90.0f;
    }
    if (value < D_800A8798 && D_800A879C < value) {
        complement = 0;
    } else {
        complement = 1;
        original = value;
        if (value < 0.0f) {
            root = sqrtf(1.0f - value * value);
            value = -root;
        } else {
            root = sqrtf(1.0f - value * value);
            value = root;
        }
    }

    if (value < D_800A87A0 && D_800A87A4 < value) {
        result = value;
    } else {
        square = value * value;
        cube = value * square;
        fifth = cube * square;
        seventh = fifth * square;
        result = cube * D_800A87A8 + value + fifth * D_800A87AC +
                 seventh * D_800A87B0 + seventh * square * D_800A87B4;
    }

    result = (f32)((f64)(result * 180.0f) / D_800A87B8);
    if (complement != 0) {
        if (original < 0.0f) {
            result = -90.0f - result;
        } else {
            result = 90.0f - result;
        }
    }
    return result;
}
