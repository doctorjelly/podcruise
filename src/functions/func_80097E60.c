/* Independently written from scratchpad spec specs/func_80097E60.md. */

#include "podcruise/types.h"

typedef struct {
    long long quotient;
    long long remainder;
} Div80097E60;

Div80097E60 func_80097E60(long long numerator, long long denominator) {
    Div80097E60 result;

    result.quotient = numerator / denominator;
    result.remainder = numerator - denominator * result.quotient;
    if (result.quotient < 0 && result.remainder > 0) {
        result.quotient++;
        result.remainder -= denominator;
    }
    return result;
}
