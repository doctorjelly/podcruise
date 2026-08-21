/* Independently written from specs/functions/vector_math.md. */

#include "podcruise/vector_math.h"

void func_80015694(PcVec3fSlot *slots, s32 index, const PcVec3f *source) {
    slots[index].value.x = source->x;
    slots[index].value.y = source->y;
    slots[index].value.z = source->z;
}

void func_800156B8(const PcVec3fSlot *slots, s32 index, PcVec3f *output) {
    output->x = slots[index].value.x;
    output->y = slots[index].value.y;
    output->z = slots[index].value.z;
}
