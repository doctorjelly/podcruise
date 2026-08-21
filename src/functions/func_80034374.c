/* Independently written from scratchpad spec specs/func_80034374.md. */

#include "podcruise/types.h"

extern s32 D_800A3FF0;
extern f32 D_80112EA0[][12];

void func_80034374(f32 dest[4][4]) {
    dest[0][0] = D_80112EA0[D_800A3FF0][0];
    dest[0][1] = D_80112EA0[D_800A3FF0][1];
    dest[0][2] = D_80112EA0[D_800A3FF0][2];
    dest[1][0] = D_80112EA0[D_800A3FF0][3];
    dest[1][1] = D_80112EA0[D_800A3FF0][4];
    dest[1][2] = D_80112EA0[D_800A3FF0][5];
    dest[2][0] = D_80112EA0[D_800A3FF0][6];
    dest[2][1] = D_80112EA0[D_800A3FF0][7];
    dest[2][2] = D_80112EA0[D_800A3FF0][8];
    dest[3][0] = D_80112EA0[D_800A3FF0][9];
    dest[3][1] = D_80112EA0[D_800A3FF0][10];
    dest[3][2] = D_80112EA0[D_800A3FF0][11];

    dest[0][3] = 0.0f;
    dest[1][3] = 0.0f;
    dest[2][3] = 0.0f;
    dest[3][3] = 1.0f;
}
