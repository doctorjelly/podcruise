/* Independently written from specs/func_8000FCBC.md. */

#include "podcruise/types.h"

extern s32 D_8009B814[2];
extern f32 D_8009B81C[2];
extern u8 D_8009B824[2][4];
extern s32 D_800D5790[2];
extern s32 D_800D57A0[2];
extern s32 D_800D57B0[2];
extern f32 D_800D57D0[2][3];

void func_8000FCBC(s32 arg0, s32 arg1, f32 *arg2, f32 arg3, u8 arg4, u8 arg5,
                   u8 arg6, u8 arg7) {
    if (arg0 < 0 || arg0 >= 2) {
        return;
    }

    D_8009B814[arg0] = arg1;
    D_800D57D0[arg0][0] = arg2[0];
    D_800D57D0[arg0][1] = arg2[1];
    D_800D57D0[arg0][2] = arg2[2];
    D_800D57B0[arg0] = -1000;
    D_800D57A0[arg0] = -1000;
    D_800D5790[arg0] = -1000;
    D_8009B81C[arg0] = arg3;
    D_8009B824[arg0][0] = arg4;
    D_8009B824[arg0][1] = arg5;
    D_8009B824[arg0][2] = arg6;
    D_8009B824[arg0][3] = arg7;
}
