/* Independently written from specs/functions/object_accessors.md. */

#include "podcruise/object_accessors.h"

void func_80017E20(const void *object, f32 *output) {
    output[0] = *(const f32 *)((const u8 *)object + 0x08);
    output[1] = *(const f32 *)((const u8 *)object + 0x0C);
    output[2] = *(const f32 *)((const u8 *)object + 0x10);
    output[3] = *(const f32 *)((const u8 *)object + 0x14);
    output[4] = *(const f32 *)((const u8 *)object + 0x18);
    output[5] = *(const f32 *)((const u8 *)object + 0x1C);
}

s32 func_80017E54(const void *object) {
    return *(const s32 *)((const u8 *)object + 0x14);
}

u32 func_80017E5C(const void *object, s32 index) {
    return (*(u32 *const *)((const u8 *)object + 0x18))[index];
}

void func_80017E70(void *object, s32 selector, s32 value) {
    if (selector == 2) {
        *(s32 *)((u8 *)object + 0x08) = value;
    }
}
