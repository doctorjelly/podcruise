/* Independently written from specs/functions/func_80017580.md. */

#include "podcruise/types.h"

void func_80017580(f32 *matrix, f32 x, f32 y, f32 z) {
    matrix[0] = 1.0f;
    matrix[1] = 0.0f;
    matrix[2] = 0.0f;
    matrix[3] = 0.0f;
    matrix[4] = 0.0f;
    matrix[5] = 1.0f;
    matrix[6] = 0.0f;
    matrix[7] = 0.0f;
    matrix[8] = 0.0f;
    matrix[9] = 0.0f;
    matrix[10] = 1.0f;
    matrix[11] = 0.0f;
    matrix[12] = x;
    matrix[13] = y;
    matrix[14] = z;
    matrix[15] = 1.0f;
}
