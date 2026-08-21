/* Independently written from specs/functions/func_8000C724.md. */

#include "podcruise/types.h"

void func_8000C724(s32 *value, f32 rate, f32 scale, s32 lower, s32 upper) {
    s32 next;

    next = (s32)(*value + rate * scale);
    *value = next;
    if (next < lower) {
        *value = lower;
        next = lower;
    }
    if (upper < next) {
        *value = upper;
    }
}
