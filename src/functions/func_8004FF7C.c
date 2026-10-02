/* Independently written from the specification for the four-slot selection reset. */

#include "podcruise/types.h"

extern s32 D_800A4B6C;
extern u32 D_800A4B70;
extern u32 D_800A4B74;
extern u32 D_800A4B78;

void func_8004FF7C(void) {
    D_800A4B6C = -1;
    D_800A4B78 = -1;
    D_800A4B74 = -1;
    D_800A4B70 = -1;
}
