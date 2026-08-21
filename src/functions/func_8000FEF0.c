/* Independently written from specs/functions/func_8000FEF0.md. */

#include "podcruise/types.h"

extern s32 D_800D5F80[];
extern s32 D_800D5FA8[];
extern u8 D_800D5C38[];

void func_8000FEF0(void) {
    s32 i;

    for (i = 0; i < 10; i++) {
        D_800D5F80[i] = -1;
        D_800D5FA8[i] = -1;
    }
    for (i = 0; i < 40; i++) {
        D_800D5C38[i] = 0;
    }
}
