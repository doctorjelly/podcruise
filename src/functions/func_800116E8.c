/* Implements the specification in specs/func_800116E8.md */
#include "podcruise/types.h"

extern s32 D_800D6140[];
extern u8 D_800D68C0[];
extern void func_8000A920(s16, s32);

void func_800116E8(void) {
    s32 i;

    for (i = 0; i < 80; i++) {
        if (D_800D6140[i] != -1) {
            func_8000A920((s16)D_800D6140[i], 0);
        }
        D_800D68C0[i] = 0;
    }
}
