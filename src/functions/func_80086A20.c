/* Specification: $S/specs/func_80086A20.md */
#include "podcruise/types.h"
#include "podcruise/vector_math.h"

extern f32 D_800ADD6C;
extern void func_80038E58(s16 *ambient, s16 *diffuse, s16 *direction);
extern void func_80038ED0(s32 slot, s16 *ambient, s16 *diffuse, s16 *direction);

void func_80086A20(s32 slot, PcVec3f *ambient, PcVec3f *diffuse, PcVec3f *direction) {
    s16 ambientParts[3];
    s16 diffuseParts[3];
    s16 directionParts[3];
    f32 scaled[3];
    f32 length;
    f32 scale;

    length = func_800153C0(direction);
    if (length < D_800ADD6C) {
        scaled[0] = 0.0f;
        scaled[1] = 0.0f;
        scaled[2] = -1.0f;
    } else {
        scale = 120.0f / length;
        scaled[0] = direction->x * scale;
        scaled[1] = direction->y * scale;
        scaled[2] = direction->z * scale;
    }

    ambientParts[0] = (s16)ambient->x;
    ambientParts[1] = (s16)ambient->y;
    ambientParts[2] = (s16)ambient->z;
    diffuseParts[0] = (s16)diffuse->x;
    diffuseParts[1] = (s16)diffuse->y;
    diffuseParts[2] = (s16)diffuse->z;
    directionParts[0] = (s16)scaled[0];
    directionParts[1] = (s16)scaled[1];
    directionParts[2] = (s16)scaled[2];

    if (slot == -1) {
        func_80038E58(ambientParts, diffuseParts, directionParts);
    } else {
        func_80038ED0(slot, ambientParts, diffuseParts, directionParts);
    }
}
