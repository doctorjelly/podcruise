/* Independently written from scratchpad spec specs/func_800313D8.md. */

#include "podcruise/types.h"

u8 *func_800313D8(u8 *arg0, s32 arg1, u32 arg2) {
    u8 *p = arg0;

    while (arg2-- > 0) {
        *p = (u8)arg1;
        p++;
    }
    return arg0;
}
