/* Independently written from scratchpad spec specs/func_80097950.md. */

#include "podcruise/types.h"

#define D_A4800018 (*(volatile u32 *)0xA4800018UL)

s32 func_80097950(void) {
    register u32 status;

    status = D_A4800018;
    if (status & 3) {
        return 1;
    }
    return 0;
}
