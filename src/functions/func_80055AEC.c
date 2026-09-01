/* Independently written from specs/func_80055AEC.md (assigned as func_80055AF4). */

#include "podcruise/types.h"

extern u16 *func_8000ABD4(s16 index);

#define STEP(pixels, level) { scale = 492; bias = -242; value = *(pixels); if (((s32)(value & 0xF800) >> 8) > 0 && (((s32)(value & 0xF800) >> 8) - ((value & 0x3E) << 2)) < (s32)((f32)bias + (level) * (f32)scale)) { *(pixels) = value | 1; } else { *(pixels) = value & ~1; } (pixels)++; }

void func_80055AEC(s32 index, f32 level) {
    u16 *pixels;
    s32 i;
    s32 scale;
    s32 bias;
    u16 value;

    if (level < 0.0f) {
        level = 0.0f;
    } else if (level > 1.0f) {
        level = 1.0f;
    }

    pixels = func_8000ABD4(index);
    if (pixels != 0) {
        for (i = 0; i < 256; i += 4) {
            STEP(pixels, level)
            STEP(pixels, level)
            STEP(pixels, level)
            STEP(pixels, level)
        }
    }
}
