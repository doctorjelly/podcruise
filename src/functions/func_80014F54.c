/* Independently written from specs/func_80014F54.md (worker specification). */
#include "podcruise/types.h"


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

    if (y < 0.0001f && y >= -0.0001f) {
        result = 90.0f;
    } else if (x < 0.0001f && x >= -0.0001f) {
        result = 0.0f;
    } else {
        swapped = 0;
        ax = (x < 0) ? -x : x;
        ay = (y < 0) ? -y : y;
        if (ay < ax) {
            swapped = 1;
            t = ay / ax;
        } else {
            t = ax / ay;
        }
        if (t < 0.0001f && t >= -0.0001f) {
            result = 0.0f;
        } else {
            t2 = t * t;
            t3 = t * t2;
            t5 = t3 * t2;
            t7 = t5 * t2;
            s = t - t3 * 0.33333334f + t5 * 0.2f - t7 * 0.14285715f + t7 * t2 * 0.063235f;
            result = (f32)((f64)(s * 180.0f) / 3.141592653589793);
        }
        if (swapped != 0) {
            result = 90.0f - result;
        }
    }
    if (y < -0.0001f) {
        result = 180.0f - result;
    }
    if (x < -0.0001f) {
        result = -result;
    }
    return result;
}
