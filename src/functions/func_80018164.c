/* Independently written from specs/functions/object_selector_accessors.md. */

#include "podcruise/object_accessors.h"

s32 func_80018164(const void *object, s32 selector) {
    if (selector == 4) {
        return *(const s32 *)((const u8 *)object + 0x15C);
    }
    if (selector == 3) {
        return *(const s32 *)((const u8 *)object + 0x164);
    }
    if (selector == 6) {
        return *(const s32 *)((const u8 *)object + 0x158);
    }
    if (selector == 5) {
        return *(const s32 *)((const u8 *)object + 0x160);
    }
    return -1;
}
