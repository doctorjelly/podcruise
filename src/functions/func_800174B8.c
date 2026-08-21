/* Independently written from specs/functions/matrix_from_euler.md. */

#include "podcruise/types.h"

extern void func_8001723C(f32 *matrix, f32 first, f32 second, f32 third);

void func_800174B8(f32 *matrix, f32 *source) {
    matrix[12] = source[0];
    matrix[13] = source[1];
    matrix[14] = source[2];
    matrix[3] = 0.0f;
    matrix[7] = 0.0f;
    matrix[11] = 0.0f;
    matrix[15] = 1.0f;
    func_8001723C(matrix, source[3], source[4], source[5]);
}
