/* Independently written from specs/functions/object_runtime_leaves.md. */

#include "podcruise/object_accessors.h"

u32 func_800183A8(const void *object) {
    return *(const u32 *)((const u8 *)object + 0x04);
}

void func_800183B0(void *object, u32 value) {
    *(u32 *)((u8 *)object + 0x04) = value;
}
