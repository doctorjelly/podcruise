/* Independently written from scratchpad spec specs/func_800636D0.md. */

#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} PcVec3f;

typedef struct {
    s32 unk00[2];
    s32 unk08;
    s32 unk0C[14];
    PcVec3f unk44;
    PcVec3f unk50;
    s32 unk5C[17];
    s32 unkA0;
} PcProximity;

extern f32 func_80015470(const PcVec3f *from, const PcVec3f *to);

s32 func_800636D0(PcProximity *entry) {
    f32 distance;
    s32 result;

    if (entry->unk08 == 2) {
        entry->unk50.z = entry->unk44.z;
    }
    distance = func_80015470(&entry->unk50, &entry->unk44);
    result = 0;
    if (distance <= 10.0f) {
        result = 1;
    }
    entry->unkA0 = result;
    return result;
}
