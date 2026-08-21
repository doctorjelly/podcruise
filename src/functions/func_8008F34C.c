/* Independently written from the specification for func_8008F34C. */

#include "podcruise/types.h"

f32 func_8008F34C(f32 value, s32 exponent, s16 rateHigh, u16 rateLow) {
    f32 factor;
    f32 accumulated;
    s32 step;

    exponent = exponent >> 3;
    if (exponent == 0) {
        return value;
    }
    factor = ((f32)(rateHigh << 16) + (f32)rateLow) / 65536.0f;
    accumulated = 1.0f;
    for (step = 0; step < 32; step++) {
        if (exponent & 1) {
            accumulated = accumulated * factor;
        }
        exponent = exponent >> 1;
        if (exponent == 0) {
            break;
        }
        factor = factor * factor;
    }
    return value * accumulated;
}
