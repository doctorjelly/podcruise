/* Independently written from scratchpad spec specs/func_80036F7C.md. */

#include "podcruise/types.h"

extern u8 D_800DB930[];
extern u8 *D_800A3D30;
extern s32 D_800A3D38;

void func_80036F7C(void) {
    D_800A3D30 = D_800DB930;
    D_800A3D38 = 0;
}
