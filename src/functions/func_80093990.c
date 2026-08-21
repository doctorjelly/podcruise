/* Independently written from scratchpad spec specs/func_80093990.md. */

#include "podcruise/types.h"

s32 func_80093990(u32 arg0) {
    register u32 status;

    status = *(volatile u32 *)(unsigned long)0xA4040010U;
    if ((status & 1) == 0) {
        return -1;
    }
    *(volatile u32 *)(unsigned long)0xA4080000U = arg0;
    return 0;
}
