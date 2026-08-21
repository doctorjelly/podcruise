/* Independently written from specs/functions/camera_matrix_fetch.md. */

#include "podcruise/types.h"

extern s32 D_8009A29C;
extern f32 D_800AEC80[][16];

void func_800059A8(f32 *arg0) {
    arg0[0] = D_800AEC80[D_8009A29C][0];
    arg0[1] = D_800AEC80[D_8009A29C][1];
    arg0[2] = D_800AEC80[D_8009A29C][2];
    arg0[3] = D_800AEC80[D_8009A29C][3];
    arg0[4] = D_800AEC80[D_8009A29C][4];
    arg0[5] = D_800AEC80[D_8009A29C][5];
    arg0[6] = D_800AEC80[D_8009A29C][6];
    arg0[7] = D_800AEC80[D_8009A29C][7];
    arg0[8] = D_800AEC80[D_8009A29C][8];
    arg0[9] = D_800AEC80[D_8009A29C][9];
    arg0[10] = D_800AEC80[D_8009A29C][10];
    arg0[11] = D_800AEC80[D_8009A29C][11];
    arg0[12] = D_800AEC80[D_8009A29C][12];
    arg0[13] = D_800AEC80[D_8009A29C][13];
    arg0[14] = D_800AEC80[D_8009A29C][14];
    arg0[15] = D_800AEC80[D_8009A29C][15];
}
