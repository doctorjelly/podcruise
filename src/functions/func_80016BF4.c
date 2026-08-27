/* Independently written from the specification specs/func_80016BF4.md. */

#include "podcruise/types.h"

void func_80016BF4(f32 *output, f32 *vector, f32 transform[4][4]) {
    f32 result[3];

    result[0] = transform[0][0] * vector[0] + transform[1][0] * vector[1] + transform[2][0] * vector[2];
    result[1] = transform[0][1] * vector[0] + transform[1][1] * vector[1] + transform[2][1] * vector[2];
    result[2] = transform[0][2] * vector[0] + transform[1][2] * vector[1] + transform[2][2] * vector[2];
    output[0] = result[0];
    output[1] = result[1];
    output[2] = result[2];
}
