/* Independently written from specs/functions/recovered/func_80081680.md. */

#include "podcruise/types.h"

f32 func_80081680(f32 value, s32 exponent, f32 scale, f32 limit) {
    s32 nonpositive;
    f32 result;

    if (0.0f < value) {
        nonpositive = 0;
    } else {
        nonpositive = 1;
        value = -value;
    }

    result = value;
    if (exponent >= 2) {
        do {
            result *= value;
            exponent--;
        } while (exponent >= 2);
    }

    result *= scale;
    if (limit < result) {
        result = limit;
    }

    if (nonpositive != 0) {
        return -result;
    }
    return result;
}
