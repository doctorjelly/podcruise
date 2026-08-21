/* Independently written from scratchpad spec specs/func_80093A60.md. */

#include "podcruise/types.h"

s32 func_80093A60(void) {
    register u32 status;

    status = *(volatile u32 *)(unsigned long)0xA4040010U;
    if ((status & 0x1C) != 0) {
        return 1;
    }
    return 0;
}
