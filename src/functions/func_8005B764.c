/* Independently written from specs/functions/recovered/func_8005B764.md. */

#include "podcruise/types.h"

extern s32 func_80053220(s32 mask);
extern s32 func_8003F800(u32 tag, s32 index);

s32 func_8005B764(void) {
    s32 result;
    s32 available;
    s32 flags;

    available = func_80053220(0x200);
    flags = ((u32 *)(unsigned long)func_8003F800(0x4A646765, 0))[2];

    if ((flags & 0x20) != 0) {
        result = 0;
    } else {
        switch (flags & 0xF) {
        case 0:
            result = available;
            break;
        case 1:
            result = available;
            break;
        case 2:
            result = 0;
            break;
        case 3:
            result = available;
            break;
        case 4:
            result = 0;
            break;
        case 5:
            result = 0;
            break;
        case 6:
            result = 0;
            break;
        default:
            result = available;
            break;
        }
    }
    return result;
}
