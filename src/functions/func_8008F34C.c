/* Specification: specs/func_8008F34C.md (worker-authored).
   The unit is -O3 with this routine file-local; the two stand-in callers below
   exist only to keep it out of line (a single call site is inlined away). */
#include "podcruise/types.h"

static f32 func_8008F34C(f32 value, s32 exponent, s16 rateHigh, u16 rateLow) {
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

f32 caller_a(f32 v, s32 e, s16 h, u16 l) { return func_8008F34C(v, e, h, l); }
f32 caller_b(f32 v, s32 e, s16 h, u16 l) { return func_8008F34C(v, e, h, l) + func_8008F34C(v, e + 1, h, l); }
