/* Independently written from specs/func_8000FEAC.md. */

#include "podcruise/types.h"

extern f32 D_800D59B8[20][3];
extern s32 D_800D5AA8[20];

void func_8000FEAC(s32 arg0, f32 *arg1, s32 arg2) {
    D_800D5AA8[arg0] = arg2;
    D_800D59B8[arg0][0] = arg1[0];
    D_800D59B8[arg0][1] = arg1[1];
    D_800D59B8[arg0][2] = arg1[2];
}
