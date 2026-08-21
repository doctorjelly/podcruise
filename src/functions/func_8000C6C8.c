/* Independently written from specs/functions/func_8000C6C8.md. */

#include "podcruise/types.h"

void func_8000C6C8(f32 *value, f32 rate, f32 scale, f32 lower, f32 upper) {
    *value = *value + rate * scale;
    if (*value < lower) {
        *value = lower;
    }
    if (upper < *value) {
        *value = upper;
    }
}
