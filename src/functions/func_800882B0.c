/* Independently written from scratchpad spec specs/func_800882B0.md. */

#include "podcruise/types.h"

extern u8 D_800A69A0;

extern u32 func_80088360(u32 address);
extern s32 func_8008D420(void);

s32 func_800882B0(u32 address, u32 length) {
    u32 start;

    start = address;
    if (D_800A69A0 != 0) {
        start = address - 0x2000;
    }
    if (((address + length) & 0x1FFF) == 0) {
        D_800A69A0 = 1;
    } else {
        D_800A69A0 = 0;
    }
    if (func_8008D420() != 0) {
        return -1;
    }
    *(volatile u32 *)0xA4500000 = func_80088360(start);
    *(volatile u32 *)0xA4500004 = length;
    return 0;
}
