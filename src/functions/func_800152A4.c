/* Independently written from specs/functions/vector_math.md. */

#include "podcruise/vector_math.h"

void func_800152A4(PcVec3f *output, const PcVec3f *source) {
    output->x = -source->x;
    output->y = -source->y;
    output->z = -source->z;
}
