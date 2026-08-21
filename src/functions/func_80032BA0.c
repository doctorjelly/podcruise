/* Specification: scratchpad specs/func_80032D68.md (boundary corrected to func_80032BA0) */
#include "podcruise/types.h"

typedef struct {
    u8 pad00[0x24];
    f32 rate;
    u8 pad28[0x4];
    f32 level;
} Obj80032BA0;

extern f32 D_800AA444;
extern f32 D_800AA448;
extern f32 D_800AA44C;
extern f32 D_800AA450;
extern f32 D_800AA454;
extern f32 D_800AA458;
extern f32 D_800AA45C;
extern f32 D_800AA460;
extern f32 D_800AA464;

void func_80032BA0(Obj80032BA0 *object, s32 unused, s32 channel, f32 step) {
    (void)unused;

    if (channel == 1) {
        object->rate += D_800AA444 * step;
        if (object->rate > 20.0f) {
            object->rate = 20.0f;
        }
        if (object->rate < 1.0f) {
            object->rate = 1.0f;
        }
    }
    if (channel == 2) {
        object->rate += D_800AA448 * step;
        if (object->rate > 20.0f) {
            object->rate = 20.0f;
        }
        if (object->rate < 1.0f) {
            object->rate = 1.0f;
        }
    }
    if (channel == 3) {
        object->rate += D_800AA44C * step;
        if (object->rate > 20.0f) {
            object->rate = 20.0f;
        }
        if (object->rate < 1.0f) {
            object->rate = 1.0f;
        }
    }
    if (channel == 4) {
        object->rate += D_800AA450 * step;
        if (object->rate > 20.0f) {
            object->rate = 20.0f;
        }
        if (object->rate < 1.0f) {
            object->rate = 1.0f;
        }
    }
    if (channel == 5) {
        object->rate += 8.0f * step;
        if (object->rate > 20.0f) {
            object->rate = 20.0f;
        }
        if (object->rate < 1.0f) {
            object->rate = 1.0f;
        }
    }
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
