/* Independently written from scratchpad spec specs/func_800877AC.md. */

#include "podcruise/types.h"

extern u8 D_80120DF0[4][0x170];

extern void func_8001811C(void *entry, s32 selector, s32 value);

void func_800877AC(s32 selector, s32 value) {
    s32 index;

    for (index = 0; index < 4; index++) {
        func_8001811C(D_80120DF0[index], selector, value);
    }
}
