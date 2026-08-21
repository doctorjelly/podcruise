/* Independently written from scratchpad spec specs/func_80093C80.md. */

#include "podcruise/types.h"

extern s32 func_80097950(void);

s32 func_80093C80(u32 arg0, u32 arg1) {
    if (func_80097950() != 0) {
        return -1;
    }

    *(volatile u32 *)(unsigned long)(arg0 | 0xA0000000U) = arg1;
    return 0;
}
