/* Specification: specs/func_8008ED18.md (scratchpad) */
#include "podcruise/types.h"

f64 func_8008ED18(f64 value, s32 *exponent) {
    f64 fraction;
    f64 result;

    *exponent = 0;
    if (value == 0.0) {
        return value;
    }
    if (value > 0.0) {
        fraction = value;
    } else {
        fraction = -value;
    }
    while (fraction >= 1.0) {
        fraction *= 0.5;
        (*exponent)++;
    }
    while (fraction < 0.5) {
        fraction += fraction;
        (*exponent)--;
    }
    if (value > 0.0) {
        result = fraction;
    } else {
        result = -fraction;
    }
    return result;
}
