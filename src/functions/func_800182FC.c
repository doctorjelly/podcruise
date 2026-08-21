/* Independently written from specs/functions/object_runtime_leaves.md. */

#include "podcruise/object_accessors.h"

u32 func_800182FC(const void *object, s32 selector) {
    if (selector == 0) {
        return *(const u32 *)((const u8 *)object + 0x08);
    }
    if (selector == 2) {
        return *(const u32 *)((const u8 *)object + 0x04);
    }
    return 0;
}
