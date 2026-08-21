/* Independently written from scratchpad spec specs/func_80093890.md. */

#include "podcruise/types.h"

extern u32 D_80000308;

s32 func_80093890(u32 arg0, u32 *arg1) {
    register u32 stat;

    stat = *(volatile u32 *)(unsigned long)0xA4600010U;
    while ((stat & 3) != 0) {
        stat = *(volatile u32 *)(unsigned long)0xA4600010U;
    }

    *arg1 = *(volatile u32 *)(unsigned long)((D_80000308 | arg0) | 0xA0000000U);
    return 0;
}
