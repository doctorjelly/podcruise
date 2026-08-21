/* Independently written from the specification for the request-flag updater. */

#include "podcruise/types.h"

extern u32 D_800A4B94[4];
extern u32 D_800A4BA4[4];

void func_8004E488(s32 index, s32 enable, u32 mask) {
    if (enable != 0) {
        if ((D_800A4B94[index] & mask) == 0) {
            D_800A4BA4[index] |= mask;
        }
        D_800A4B94[index] |= mask;
    } else {
        D_800A4B94[index] &= ~mask;
    }
}
