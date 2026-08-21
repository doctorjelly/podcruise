/* Independently written from specs/functions/object_accessors.md. */

#include "podcruise/types.h"

u32 func_80017DA4(const void *object) {
    return *(const u32 *)((const u8 *)object + 0x0);
}

s32 func_80017DAC(const void *object) {
    return *(const s32 *)((const u8 *)object + 0x14);
}
