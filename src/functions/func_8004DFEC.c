/* Independently written from the specification for the pending-slot table reset. */

#include "podcruise/types.h"

extern s32 D_800A4B94[4];
extern s32 D_800A4BA4[4];

void func_8004DFEC(void) {
    s16 i;

    for (i = 0; i < 4; i++) {
        D_800A4B94[i] = -1;
        D_800A4BA4[i] = 0;
    }
}
