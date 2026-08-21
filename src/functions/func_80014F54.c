/* Implements the specification in specs/func_80014F54.md (arc-tangent of a ratio, in degrees). */
#include "podcruise/types.h"

extern f32 D_800A87C0;
extern f32 D_800A87C4;
extern f32 D_800A87C8;
extern f32 D_800A87CC;
extern f32 D_800A87D0;
extern f32 D_800A87D4;
extern f32 D_800A87D8;
extern f32 D_800A87DC;
extern f64 D_800A87E0;
extern f32 D_800A87E8;
extern f32 D_800A87EC;

f32 func_80014F54(f32 x, f32 y) {
    f32 ax;
    f32 ay;
    f32 ratio;
    f32 r2;
    f32 r3;
    f32 r5;
    f32 r7;
    f32 r9;
    f32 result;
    s32 swapped;

    if (y < D_800A87C0 && y >= D_800A87C4) {
        result = 90.0f;
    } else if (x < D_800A87C0 && x >= D_800A87C8) {
        result = 0.0f;
    } else {
        swapped = 0;
        ax = (x < 0.0f) ? -x : x;
        ay = (y < 0.0f) ? -y : y;
        if (ay < ax) {
            swapped = 1;
            ratio = ay / ax;
        } else {
            ratio = ax / ay;
        }
        if (ratio < D_800A87C0 && ratio >= D_800A87CC) {
            result = 0.0f;
        } else {
            r2 = ratio * ratio;
            r3 = ratio * r2;
            r5 = r3 * r2;
            r7 = r5 * r2;
            r9 = r7 * r2;
            result = (f32)((f64)((ratio - r3 * D_800A87D0 + r5 * D_800A87D4 - r7 * D_800A87D8 + r9 * D_800A87DC) * 180.0f) / D_800A87E0);
        }
        if (swapped != 0) {
            result = 90.0f - result;
        }
    }
    if (y < D_800A87E8) {
        result = 180.0f - result;
    }
    if (x < D_800A87EC) {
        result = -result;
    }
    return result;
}
