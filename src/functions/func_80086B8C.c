/* Independently written from scratchpad spec specs/func_80086B8C.md. */

#include "podcruise/vector_math.h"

extern f32 D_800ADD70;

extern void func_80038FE8(s32 index, s32 mode, s16 *position, s16 *heading);

void func_80086B8C(s32 index, s32 mode, PcVec3f *position, PcVec3f *direction) {
    s16 packed_position[3];
    s16 packed_heading[3];
    f32 heading[3];
    f32 length;
    f32 scale;

    if (mode != 0) {
        length = func_800153C0(direction);
        if (length < D_800ADD70) {
            heading[0] = 0.0f;
            heading[1] = 0.0f;
            heading[2] = -1.0f;
        } else {
            scale = 120.0f / length;
            heading[0] = direction->x * scale;
            heading[1] = direction->y * scale;
            heading[2] = direction->z * scale;
        }
        packed_position[0] = (s16)position->x;
        packed_position[1] = (s16)position->y;
        packed_position[2] = (s16)position->z;
        packed_heading[0] = (s16)heading[0];
        packed_heading[1] = (s16)heading[1];
        packed_heading[2] = (s16)heading[2];
    }
    func_80038FE8(index, mode, packed_position, packed_heading);
}
