/* Independently written from scratchpad spec specs/func_80038DBC.md. */

#include "podcruise/types.h"

extern s32 D_800D6960[];

void func_80038DBC(s32 arg0) {
    if (arg0 != 0) {
        D_800D6960[7] &= ~0x40;
    } else {
        D_800D6960[7] |= 0x40;
    }
}
