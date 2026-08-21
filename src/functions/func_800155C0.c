/* Independently written from specs/functions/vector_math.md. */

#include "podcruise/vector_math.h"

void func_800155C0(PcVec3f *output, f32 scale, const PcVec3f *source) {
    output->x = source->x * scale;
    output->y = source->y * scale;
    output->z = source->z * scale;
}

void func_800155EC(PcVec3f *output, const PcVec3f *base, f32 scale,
                   const PcVec3f *offset) {
    output->x = offset->x * scale + base->x;
    output->y = offset->y * scale + base->y;
    output->z = offset->z * scale + base->z;
}
