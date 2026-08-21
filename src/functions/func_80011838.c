/* Independently written from specs/functions/global_state.md. */

#include "podcruise/global_state.h"

extern s32 D_800D6140[];
extern u8 D_800D68C0[];
extern u8 D_800D6910[];

void func_80011838(void) {
    s32 i;
    for (i = 0; i < 20; i++) {
        D_800D6140[i * 4 + 0] = -1;
        D_800D6140[i * 4 + 1] = -1;
        D_800D6140[i * 4 + 2] = -1;
        D_800D6140[i * 4 + 3] = -1;
        D_800D68C0[i * 4 + 0] = 0;
        D_800D68C0[i * 4 + 1] = 0;
        D_800D68C0[i * 4 + 2] = 0;
        D_800D68C0[i * 4 + 3] = 0;
    }
}
