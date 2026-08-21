/* Independently written from scratchpad spec specs/func_80009278.md. */

#include "podcruise/types.h"

extern s16 D_8009ADF4[3];
extern s16 D_8009ADFC;

void func_80009278(s32 arg0) {
    s16 head;

    head = D_8009ADFC;
    D_8009ADF4[head] = arg0;
    D_8009ADFC = (head + 1) % 3;
}
