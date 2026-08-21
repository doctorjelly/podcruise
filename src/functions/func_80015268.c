/* Independently written from specs/functions/vector_math.md. */

#include "podcruise/vector_math.h"

void func_80015268(PcVec3f *output, f32 x, f32 y, f32 z) {
    output->x = x;
    output->y = y;
    output->z = z;
}

void func_80015288(PcVec3f *output, const PcVec3f *source) {
    output->x = source->x;
    output->y = source->y;
    output->z = source->z;
}
