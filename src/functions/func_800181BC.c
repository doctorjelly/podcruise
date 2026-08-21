/* Independently written from specs/func_800181BC.md. */

#include "podcruise/types.h"

extern u32 func_80017DA4(const void *object);
extern s32 func_80017DAC(const void *object);
extern u32 func_80017DB4(const void *object, s32 index);

s32 func_800181BC(void *object, s32 which, u32 value, s32 flags, s32 mode) {
    u32 *target;
    s32 masked;
    s32 index;

    if (object == 0) {
        return 0;
    }

    masked = flags & 0x10;

    if (which == 0) {
        target = (u32 *)((u8 *)object + 8);
    } else if (which == 2) {
        target = (u32 *)((u8 *)object + 4);
    } else {
        return 0;
    }

    if (masked != 0) {
        if (mode == 2) {
            *target |= value;
        } else if (mode == 3) {
            *target &= value;
        } else if (mode == 1) {
            *target = value;
        }
    }

    if ((flags & 0x20) != 0) {
        if ((func_80017DA4(object) & 0x4000) != 0) {
            for (index = 0; index < func_80017DAC(object); index++) {
                func_800181BC((void *)(unsigned long)func_80017DB4(object, index), which, value,
                              masked, mode);
            }
        }
    }

    /*
     * The original body has no final return: the value in the result register
     * on this path is whatever the last helper left there.  The host build
     * needs a return statement to compile clean, so one is supplied only when
     * the target compiler is not in use.
     */
#if !defined(__sgi)
    return 0;
#endif
}
