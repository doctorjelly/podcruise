/* Independently written from specs/functions/matrix_from_euler.md. */

#include "podcruise/types.h"

extern void func_8001723C(f32 *matrix, f32 first, f32 second, f32 third);

void func_8001745C(f32 *matrix, f32 first, f32 second, f32 third) {
    matrix[12] = 0.0f;
    matrix[13] = 0.0f;
    matrix[14] = 0.0f;
    matrix[3] = 0.0f;
    matrix[7] = 0.0f;
    matrix[11] = 0.0f;
    matrix[15] = 1.0f;
    func_8001723C(matrix, first, second, third);
}
