/* Independently written from scratchpad spec specs/func_80016CAC.md. */

#include "podcruise/types.h"

void func_80016CAC(f32 *destination, f32 *source, f32 (*transform)[4]) {
    f32 result[3];

    result[0] = transform[0][0] * source[0] + transform[1][0] * source[1] +
                transform[2][0] * source[2] + transform[3][0];
    result[1] = transform[0][1] * source[0] + transform[1][1] * source[1] +
                transform[2][1] * source[2] + transform[3][1];
    result[2] = transform[0][2] * source[0] + transform[1][2] * source[1] +
                transform[2][2] * source[2] + transform[3][2];

    destination[0] = result[0];
    destination[1] = result[1];
    destination[2] = result[2];
}
