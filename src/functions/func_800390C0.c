/* Independently written from scratchpad spec specs/func_800390C0.md. */

#include "podcruise/types.h"

extern u32 D_80114070[256];

void func_800390C0(void) {
    s32 i;
    s32 bit;
    u32 acc;

    for (i = 0; i < 256; i++) {
        acc = (u32)i << 24;
        for (bit = 8; bit != 0; bit--) {
            if ((acc & 0x80000000) != 0) {
                acc = (acc << 1) ^ 0x04C11DB7;
            } else {
                acc = acc << 1;
            }
        }
        D_80114070[i] = acc;
    }
}
