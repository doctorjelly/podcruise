/* Independently written from specs/functions/func_8003423C.md. */

#include "podcruise/types.h"

extern s32 D_800A3FF0;
extern f32 D_80112EA0[][12];

void func_8003423C(f32 *output) {
    output[0] = D_80112EA0[D_800A3FF0][0];
    output[1] = D_80112EA0[D_800A3FF0][1];
    output[2] = D_80112EA0[D_800A3FF0][2];
    output[3] = D_80112EA0[D_800A3FF0][3];
    output[4] = D_80112EA0[D_800A3FF0][4];
    output[5] = D_80112EA0[D_800A3FF0][5];
    output[6] = D_80112EA0[D_800A3FF0][6];
    output[7] = D_80112EA0[D_800A3FF0][7];
    output[8] = D_80112EA0[D_800A3FF0][8];
    output[9] = D_80112EA0[D_800A3FF0][9];
    output[10] = D_80112EA0[D_800A3FF0][10];
    output[11] = D_80112EA0[D_800A3FF0][11];
}
