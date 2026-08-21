/* Independently written from specs/func_8000FE78.md. */

#include "podcruise/types.h"

extern s32 D_800D5AA8[20];

void func_8000FE78(void) {
    s32 i;

    for (i = 0; i < 20; i++) {
        D_800D5AA8[i] = -9999;
    }
}
