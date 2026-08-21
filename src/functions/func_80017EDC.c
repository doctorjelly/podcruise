/* Independently written from specs/functions/object_accessors.md. */

#include "podcruise/object_accessors.h"

u32 func_80017EDC(const void *object) {
    return *(const u32 *)((const u8 *)object + 0x0);
}

s32 func_80017EE4(const void *object) {
    return *(const s32 *)((const u8 *)object + 0x4);
}

void func_80017EEC(void *object, s32 value) {
    *(s32 *)((u8 *)object + 0x4) = value;
}

u32 func_80017EF4(const void *object) {
    return *(const u32 *)((const u8 *)object + 0x0);
}
