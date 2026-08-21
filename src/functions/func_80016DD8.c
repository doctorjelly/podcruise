/* Independently written from specs/functions/func_80016DD8.md. */

#include "podcruise/types.h"

void func_80016DD8(f32 *output, const f32 *vector, const f32 matrix[4][4]) {
    f32 result[4];

    result[0] = matrix[0][0] * vector[0] + matrix[1][0] * vector[1] +
                matrix[2][0] * vector[2] + matrix[3][0] * vector[3];
    result[1] = matrix[0][1] * vector[0] + matrix[1][1] * vector[1] +
                matrix[2][1] * vector[2] + matrix[3][1] * vector[3];
    result[2] = matrix[0][2] * vector[0] + matrix[1][2] * vector[1] +
                matrix[2][2] * vector[2] + matrix[3][2] * vector[3];
    result[3] = matrix[0][3] * vector[0] + matrix[1][3] * vector[1] +
                matrix[2][3] * vector[2] + matrix[3][3] * vector[3];

    output[0] = result[0];
    output[1] = result[1];
    output[2] = result[2];
    output[3] = result[3];
}
