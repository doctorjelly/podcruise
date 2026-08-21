/* Independently written from specs/functions/matrix_rotate_vector.md. */

#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} PcVec3f;

typedef struct {
    f32 m[4][4];
} PcMatrix4f;

void func_80016BF4(PcVec3f *output, const PcVec3f *vector, const PcMatrix4f *matrix) {
    f32 result[3];

    result[0] = matrix->m[0][0] * vector->x + matrix->m[1][0] * vector->y
                + matrix->m[2][0] * vector->z;
    result[1] = matrix->m[0][1] * vector->x + matrix->m[1][1] * vector->y
                + matrix->m[2][1] * vector->z;
    result[2] = matrix->m[0][2] * vector->x + matrix->m[1][2] * vector->y
                + matrix->m[2][2] * vector->z;
    output->x = result[0];
    output->y = result[1];
    output->z = result[2];
}
