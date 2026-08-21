/* Specification: $S/specs/func_80032D68.md */
#include "podcruise/types.h"

typedef struct {
    u8 pad00[0x2C];
    f32 level;
} Obj80032D68;

extern f32 D_800AA454;
extern f32 D_800AA458;
extern f32 D_800AA45C;
extern f32 D_800AA460;
extern f32 D_800AA464;

void func_80032D68(object, unused, channel, step)
Obj80032D68 *object;
s32 unused;
s32 channel;
f32 step;
{
    (void)unused;

    if (channel == 1) {
        object->level += D_800AA454 * step;
        if (object->level > 1.0f) {
            object->level = 1.0f;
        }
        if (object->level < 0.0f) {
            object->level = 0.0f;
        }
    }
    if (channel == 2) {
        object->level += D_800AA458 * step;
        if (object->level > 1.0f) {
            object->level = 1.0f;
        }
        if (object->level < 0.0f) {
            object->level = 0.0f;
        }
    }
    if (channel == 3) {
        object->level += D_800AA45C * step;
        if (object->level > 1.0f) {
            object->level = 1.0f;
        }
        if (object->level < 0.0f) {
            object->level = 0.0f;
        }
    }
    if (channel == 4) {
        object->level += D_800AA460 * step;
        if (object->level > 1.0f) {
            object->level = 1.0f;
        }
        if (object->level < 0.0f) {
            object->level = 0.0f;
        }
    }
    if (channel == 5) {
        object->level += D_800AA464 * step;
        if (object->level > 1.0f) {
            object->level = 1.0f;
        }
        if (object->level < 0.0f) {
            object->level = 0.0f;
        }
    }
}
