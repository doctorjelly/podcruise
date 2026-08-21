/* Independently written from the reviewed specification for func_80011DF0. */

#include "podcruise/types.h"

extern u8 D_800A1AB0[];
extern u8 D_800A1B14[];
extern u8 D_800A1B78[];
extern u8 D_800A1BDC[];
extern u8 D_800A1C40[];
extern s32 D_800A1D88;
extern void *D_800A1D8C;
extern void *D_800D6940[];

void func_80011DF0(void) {
    D_800A1D88 = 7;
    D_800D6940[0] = D_800A1BDC;
    D_800D6940[1] = D_800A1B78;
    D_800D6940[2] = D_800A1B14;
    D_800D6940[3] = D_800A1B78;
    D_800D6940[4] = D_800A1C40;
    D_800D6940[5] = D_800A1BDC;
    D_800D6940[6] = D_800A1AB0;
    D_800A1D8C = D_800A1BDC;
}
