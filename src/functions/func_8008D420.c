/* Independently written from the specification for func_8008D420. */

#include "podcruise/types.h"

#define D_A450000C (*(volatile u32 *)0xA450000CUL)

s32 func_8008D420(void) {
    register u32 status;

    status = D_A450000C;
    if (status & 0x80000000) {
        return 1;
    }
    return 0;
}
