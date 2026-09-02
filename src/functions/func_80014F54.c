/* Independently written from specs/func_80014F54.md (worker specification). */
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
    f32 t;
    f32 t2;
    f32 t3;
    f32 t5;
    f32 t7;
    f32 s;
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
            t = ay / ax;
        } else {
            t = ax / ay;
        }
        if (t < D_800A87C0 && t >= D_800A87CC) {
            result = 0.0f;
        } else {
            t2 = t * t;
            t3 = t * t2;
            t5 = t3 * t2;
            t7 = t5 * t2;
            s = t - t3 * D_800A87D0 + t5 * D_800A87D4 - t7 * D_800A87D8 + t7 * t2 * D_800A87DC;
            result = (f32)((f64)(s * 180.0f) / D_800A87E0);
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
