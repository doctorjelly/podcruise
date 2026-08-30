/* Independently written from specs/functions/recovered/func_8008ACD8.md. */

#include "podcruise/types.h"

s64 func_8008ACD8(s64 dividend, s64 divisor) {
    s64 remainder;

    remainder = dividend % divisor;
    if (((remainder < 0) && (divisor > 0)) ||
        ((remainder > 0) && (divisor < 0))) {
        remainder += divisor;
    }
    return remainder;
}
