/* Independently written from specs/func_8000FD74.md. */

#include "podcruise/types.h"

extern s32 D_8009B82C[2][8];
extern f32 D_800D57E8[2][8];
extern f32 D_800D5828[2][8];
extern u8 D_800D5868[2][8][3];

void func_8000FD74(s32 arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4, u8 arg5,
                   u8 arg6, u8 arg7) {
    if (arg0 < 0 || arg0 >= 2) {
        return;
    }
    if (arg1 < 0 || arg1 >= 8) {
        return;
    }

    D_8009B82C[arg0][arg1] = arg2;
    D_800D57E8[arg0][arg1] = arg4;
    D_800D5828[arg0][arg1] = arg3;
    D_800D5868[arg0][arg1][0] = arg5;
    D_800D5868[arg0][arg1][1] = arg6;
    D_800D5868[arg0][arg1][2] = arg7;
}
