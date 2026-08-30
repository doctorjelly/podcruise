/* Independently written from specs/functions/recovered/func_80063D0C.md. */

#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} PcVec3f80063D0C;

typedef struct {
    u8 pad00[0x50];
    PcVec3f80063D0C position;
} PcObject80063D0C;

extern PcVec3f80063D0C D_800A5100[16];

s32 func_80063D0C(PcObject80063D0C *object) {
    s32 index;

    for (index = 0; index < 16; index += 4) {
        if ((object->position.x == D_800A5100[index].x) &&
            (object->position.y == D_800A5100[index].y)) {
            return index;
        }
        if ((object->position.x == D_800A5100[index + 1].x) &&
            (object->position.y == D_800A5100[index + 1].y)) {
            return index + 1;
        }
        if ((object->position.x == D_800A5100[index + 2].x) &&
            (object->position.y == D_800A5100[index + 2].y)) {
            return index + 2;
        }
        if ((object->position.x == D_800A5100[index + 3].x) &&
            (object->position.y == D_800A5100[index + 3].y)) {
            return index + 3;
        }
    }
    return -1;
}
