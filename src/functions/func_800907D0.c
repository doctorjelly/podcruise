/* Implements the specification in specs/func_800907D0.md */
#include "podcruise/types.h"

#define D_A4800000 (*(volatile u32 *)0xA4800000)
#define D_A4800004 (*(volatile u32 *)0xA4800004)
#define D_A4800010 (*(volatile u32 *)0xA4800010)
#define D_A4800018 (*(volatile u32 *)0xA4800018)

extern void func_80087CC0(void *buffer, s32 size);
extern u32 func_80088360(void *buffer);
extern void func_80093900(void *buffer, s32 size);

s32 func_800907D0(s32 direction, void *buffer) {
    if ((D_A4800018 & 3) != 0) {
        return -1;
    }
    if (direction == 1) {
        func_80093900(buffer, 0x40);
    }
    D_A4800000 = func_80088360(buffer);
    if (direction == 0) {
        D_A4800004 = 0x1FC007C0;
    } else {
        D_A4800010 = 0x1FC007C0;
    }
    if (direction == 0) {
        func_80087CC0(buffer, 0x40);
    }
    return 0;
}
