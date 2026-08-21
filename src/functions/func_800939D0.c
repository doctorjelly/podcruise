/* Implements the specification in specs/func_800939D0.md */
#include "podcruise/types.h"

extern s32 func_80093A60(void);
extern s32 func_80088360(s32);

#define D_A4040000 (*(volatile u32 *)0xA4040000)
#define D_A4040004 (*(volatile u32 *)0xA4040004)
#define D_A4040008 (*(volatile u32 *)0xA4040008)
#define D_A404000C (*(volatile u32 *)0xA404000C)

s32 func_800939D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (func_80093A60() != 0) {
        return -1;
    }
    D_A4040000 = arg1;
    D_A4040004 = func_80088360(arg2);
    if (arg0 == 0) {
        D_A404000C = arg3 - 1;
    } else {
        D_A4040008 = arg3 - 1;
    }
    return 0;
}
