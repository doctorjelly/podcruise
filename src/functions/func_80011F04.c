/* Independently written from the reviewed specification for func_80011F04. */

#include "podcruise/types.h"

extern u8 D_800A1CCC[4];
extern s32 D_800D6938;

void func_80011F04(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    D_800A1CCC[0] = arg0;
    D_800A1CCC[1] = arg1;
    D_800A1CCC[2] = arg2;
    D_800A1CCC[3] = arg3;
    D_800D6938 = 0;
}
