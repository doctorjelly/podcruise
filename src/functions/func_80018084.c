/* Independently written from specs/functions/object_selector_accessors.md. */

#include "podcruise/object_accessors.h"

void func_80018084(void *object, s32 selector, f32 value) {
    switch (selector) {
        case 2:
            *(f32 *)((u8 *)object + 0x148) = value;
            break;
        case 3:
            *(f32 *)((u8 *)object + 0x14C) = value;
            break;
        case 5:
            *(f32 *)((u8 *)object + 0x150) = value;
            break;
    }
}

f32 func_800180C8(const void *object, s32 selector) {
    switch (selector) {
        case 2:
            return *(const f32 *)((const u8 *)object + 0x148);
        case 3:
            return *(const f32 *)((const u8 *)object + 0x14C);
        case 5:
            return *(const f32 *)((const u8 *)object + 0x150);
    }
    return -1.0f;
}
