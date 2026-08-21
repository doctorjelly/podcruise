/* Independently written from specs/functions/object_runtime_leaves.md. */

#include "podcruise/object_accessors.h"

void func_80018114(void *object, s32 value) {
    *(s32 *)((u8 *)object + 0x168) = value;
}

void func_8001811C(void *object, s32 selector, s32 value) {
    if (selector == 4) {
        *(s32 *)((u8 *)object + 0x15C) = value;
    }
    if (selector == 3) {
        *(s32 *)((u8 *)object + 0x164) = value;
    }
    if (selector == 6) {
        *(s32 *)((u8 *)object + 0x158) = value;
    }
    if (selector == 5) {
        *(s32 *)((u8 *)object + 0x160) = value;
    }
}
