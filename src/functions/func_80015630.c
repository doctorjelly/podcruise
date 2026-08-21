/* Independently written from specs/functions/vector_math.md. */

#include "podcruise/vector_math.h"

void func_80015630(PcVec3f *output, f32 first_scale, const PcVec3f *second,
                   f32 second_scale, const PcVec3f *first) {
    output->x = first->x * second_scale + second->x * first_scale;
    output->y = first->y * second_scale + second->y * first_scale;
    output->z = first->z * second_scale + second->z * first_scale;
}
