/* Independently written from the specification for func_8008C2F0. */

#include "podcruise/types.h"

void *func_8008C2F0(void *destination, const void *source, u32 count) {
    u8 *out = (u8 *)destination;
    const u8 *in = (const u8 *)source;

    while (count != 0) {
        *out++ = *in++;
        count--;
    }
    return destination;
}
