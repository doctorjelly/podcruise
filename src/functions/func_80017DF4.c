/* Independently written from specs/functions/object_accessors.md. */

#include "podcruise/object_accessors.h"

void func_80017DF4(const void *object, s32 mode, s32 *first, s32 *second) {
    if (mode == 0) {
        *first = *(const s32 *)((const u8 *)object + 0x2C);
        *second = *(const s32 *)((const u8 *)object + 0x28);
    } else {
        *first = 0;
        *second = 0;
    }
}
