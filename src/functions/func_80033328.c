/* Independently written from specs/functions/recovered/medium_control_math_tranche.md. */
#include "podcruise/types.h"

extern f64 D_80120BF0;

void func_80033328(f32 *arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    if (arg2 < *arg0) {
        if (0.0f < *arg0) {
            arg3 = arg3 * 5.0f;
        }
        *arg0 = *arg0 - D_80120BF0 * arg3;
        if (*arg0 < arg2) {
            *arg0 = arg2;
        }
    } else {
        if (*arg0 < 0.0f) {
            arg3 = arg3 * 5.0f;
        }
        *arg0 = *arg0 + D_80120BF0 * arg3;
        if (arg2 < *arg0) {
            *arg0 = arg2;
        }
    }
    if (0.0f < arg4) {
        if (*arg0 < 0.0f) {
            *arg0 = 0.0f;
        }
    }
    if (arg4 < 0.0f) {
        if (0.0f < *arg0) {
            *arg0 = 0.0f;
        }
    }
    *arg1 = (*arg0 + arg4 + arg5) * D_80120BF0 + *arg1;
    if (*arg1 > 180.0f) {
        *arg1 = *arg1 - 360.0f;
    }
    if (*arg1 < -180.0f) {
        *arg1 = *arg1 + 360.0f;
    }
}
