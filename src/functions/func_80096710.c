/* Independently written from scratchpad spec specs/func_80096710.md. */

#include "podcruise/types.h"

void func_80096710(u8 *source, u8 *destination, s32 count) {
    u8 *in = source;
    u8 *out = destination;
    s32 index;

    for (index = 0; index < count; index++) {
        *out++ = *in++;
    }
}
