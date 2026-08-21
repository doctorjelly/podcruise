/* Independently written from scratchpad spec specs/func_8000550C.md. */

#include "podcruise/types.h"

extern s32 D_8009A29C;
extern f32 D_800AEC80[4][4];

void func_8000550C(void) {
    D_8009A29C = 0;

    D_800AEC80[3][3] = 1.0f;
    D_800AEC80[2][2] = 1.0f;
    D_800AEC80[1][1] = 1.0f;
    D_800AEC80[0][0] = 1.0f;

    D_800AEC80[0][1] = 0.0f;
    D_800AEC80[0][2] = 0.0f;
    D_800AEC80[0][3] = 0.0f;
    D_800AEC80[1][0] = 0.0f;
    D_800AEC80[1][2] = 0.0f;
    D_800AEC80[1][3] = 0.0f;
    D_800AEC80[2][0] = 0.0f;
    D_800AEC80[2][1] = 0.0f;
    D_800AEC80[2][3] = 0.0f;
    D_800AEC80[3][0] = 0.0f;
    D_800AEC80[3][1] = 0.0f;
    D_800AEC80[3][2] = 0.0f;
}
