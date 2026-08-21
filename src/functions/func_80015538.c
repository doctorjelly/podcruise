/* Independently written from specs/functions/vector_cross_product.md. */

#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} PcVec3f;

void func_80015538(PcVec3f *output, const PcVec3f *left, const PcVec3f *right) {
    f32 result[3];

    result[0] = left->y * right->z - right->y * left->z;
    result[1] = left->z * right->x - right->z * left->x;
    result[2] = left->x * right->y - right->x * left->y;
    output->x = result[0];
    output->y = result[1];
    output->z = result[2];
}
