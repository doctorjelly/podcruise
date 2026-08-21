/* Independently written from the specification for func_8008A690. */
#include "podcruise/types.h"

extern void *func_8008C2F0(void *destination, const void *source, u32 count);

void *func_8008A690(void *destination, const void *source, u32 count) {
    return (u8 *)func_8008C2F0(destination, source, count) + count;
}
