/* Independently written from specs/func_80081730.md. */

#include "podcruise/types.h"

void func_80081730(f32 result[4], f32 point[3], f32 matrix[4][4]) {
    s32 i;

    for (i = 0; i < 4; i++) {
        result[i] = (matrix[0][i] * point[0] + matrix[1][i] * point[1] +
                     matrix[2][i] * point[2]) + matrix[3][i];
    }
}
