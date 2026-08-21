/* Independently written from the reviewed specification for func_80011E54. */

#include "podcruise/types.h"

extern s32 D_800A1D88;
extern void *D_800A1D8C;
extern void *D_800D6940[];

void func_80011E54(s16 arg0) {
    if (arg0 >= D_800A1D88) {
        arg0 = D_800A1D88 - 1;
    }
    if (arg0 < 0) {
        arg0 = 0;
    }
    D_800A1D8C = D_800D6940[arg0];
}
