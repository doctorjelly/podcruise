/* Independently written from scratchpad spec specs/func_80038DF8.md. */

#include "podcruise/types.h"

extern s16 D_800A3D44[4];
extern s16 D_800A3D4C;
extern s16 D_800A3D50;

void func_80038DF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    if (arg0 >= 0) {
        D_800A3D4C = arg0;
    }
    if (arg1 >= 0) {
        D_800A3D50 = arg1;
    }
    if (arg2 >= 0) {
        D_800A3D44[0] = arg2;
    }
    if (arg3 >= 0) {
        D_800A3D44[1] = arg3;
    }
    if (arg4 >= 0) {
        D_800A3D44[2] = arg4;
    }
    if (arg5 >= 0) {
        D_800A3D44[3] = arg5;
    }
}
