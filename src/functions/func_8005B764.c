/* Independently written from specs/functions/recovered/func_8005B764.md. */

#include "podcruise/types.h"

extern s32 func_80053220(s32 mask);
extern s32 func_8003F800(u32 tag, s32 index);

s32 func_8005B764(void) {
    s32 flags;
    s32 available;

    available = func_80053220(0x200);
    flags = ((u32 *)(unsigned long)func_8003F800(0x4A646765, 0))[2];

    if ((flags & 0x20) != 0) {
        return 0;
    }

    switch (flags & 0xF) {
    case 0:
        return available;
    case 1:
        return available;
    case 2:
        return 0;
    case 3:
        return available;
    case 4:
        return 0;
    case 5:
        return 0;
    case 6:
        return 0;
    default:
        return available;
    }
}
