/* Independently written from specs/functions/vector_math.md. */

#include "podcruise/vector_math.h"

void func_80015328(PcVec3f *output, const PcVec3f *left, const PcVec3f *right) {
    output->x = right->x + left->x;
    output->y = right->y + left->y;
    output->z = right->z + left->z;
}

void func_8001535C(PcVec3f *output, const PcVec3f *left, const PcVec3f *right) {
    output->x = left->x - right->x;
    output->y = left->y - right->y;
    output->z = left->z - right->z;
}

f32 func_80015390(const PcVec3f *left, const PcVec3f *right) {
    return right->z * left->z
           + (left->x * right->x + left->y * right->y);
}
