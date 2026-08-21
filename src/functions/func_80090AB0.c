/* Independently written from scratchpad spec specs/func_80090AB0.md. */

#include "podcruise/types.h"

u16 func_80090AB0(u8 *bytes, s32 count) {
    s32 total;
    u8 *p;
    s32 i;

    total = 0;
    p = bytes;
    for (i = 0; i < count; i++) {
        total += *p;
        p++;
    }
    return total & 0xFFFF;
}
