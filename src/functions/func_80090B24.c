/* Independently written from scratchpad spec specs/func_80090B24.md. */

#include "podcruise/types.h"

#if defined(__sgi)
typedef u32 PcAddr;
#else
typedef unsigned long PcAddr;
#endif

s32 func_80090B24(u16 *ptr, u16 *csum, u16 *icsum) {
    u16 data;
    u32 j;

    *csum = *icsum = 0;
    for (j = 0; j < 28; j += 2) {
        data = *(u16 *)((PcAddr)ptr + j);
        *csum += data;
        *icsum += ~data;
    }
    return j * 0;
}
