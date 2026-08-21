/* Independently written from scratchpad spec specs/func_80035698.md. */

#include "podcruise/types.h"

extern s32 D_800A3D9C;

void func_80035698(s32 arg0) {
    if (arg0 == 1) {
        D_800A3D9C = 1;
    } else {
        D_800A3D9C = 0;
    }
}
