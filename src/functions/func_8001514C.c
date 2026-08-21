/* Independently written from specs/functions/vector_math.md. */

#include "podcruise/vector_math.h"

void func_8001514C(PcVec2f *output, const PcVec2f *left, const PcVec2f *right) {
    output->x = right->x + left->x;
    output->y = right->y + left->y;
}

void func_80015170(PcVec2f *output, f32 scale, const PcVec2f *source) {
    output->x = source->x * scale;
    output->y = source->y * scale;
}

void func_80015190(PcVec2f *output, const PcVec2f *base, f32 scale,
                   const PcVec2f *offset) {
    output->x = offset->x * scale + base->x;
    output->y = offset->y * scale + base->y;
}
