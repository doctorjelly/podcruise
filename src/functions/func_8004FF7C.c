/* Independently written from the specification for the four-slot selection reset. */

#include "podcruise/types.h"

extern s32 D_800A4B6C[4];

void func_8004FF7C(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_800A4B6C[i] = -1;
    }
}
