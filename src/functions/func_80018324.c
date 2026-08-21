/* Independently written from specs/functions/object_runtime_leaves.md. */

#include "podcruise/object_accessors.h"

void func_80018324(void *object, u32 flags) {
    u8 *bytes = object;

    *(u32 *)(bytes + 0x00) = flags;
    *(s32 *)(bytes + 0x04) = -1;
    *(s32 *)(bytes + 0x08) = -1;
    *(s16 *)(bytes + 0x0C) = 0;
    *(s16 *)(bytes + 0x0E) = 0;
    *(s32 *)(bytes + 0x10) = 0;

    if (flags & 0x4000) {
        *(s32 *)(bytes + 0x14) = 0;
        *(s32 *)(bytes + 0x18) = 0;
        if (flags == 0xD065) {
            *(f32 *)(bytes + 0x4C) = 0.0f;
            *(f32 *)(bytes + 0x50) = 0.0f;
            *(f32 *)(bytes + 0x54) = 0.0f;
            *(f32 *)(bytes + 0x20) = 0.0f;
            *(f32 *)(bytes + 0x24) = 0.0f;
            *(f32 *)(bytes + 0x28) = 0.0f;
            *(f32 *)(bytes + 0x30) = 0.0f;
            *(f32 *)(bytes + 0x34) = 0.0f;
            *(f32 *)(bytes + 0x38) = 0.0f;
            *(f32 *)(bytes + 0x40) = 0.0f;
            *(f32 *)(bytes + 0x44) = 0.0f;
            *(f32 *)(bytes + 0x48) = 0.0f;
            *(f32 *)(bytes + 0x1C) = 1.0f;
            *(f32 *)(bytes + 0x2C) = 1.0f;
            *(f32 *)(bytes + 0x3C) = 1.0f;
        }
    }
}
