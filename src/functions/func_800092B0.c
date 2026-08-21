/* Independently written from scratchpad spec specs/func_800092B0.md. */

#include "podcruise/types.h"

extern s16 D_8009ADF4[3];

s32 func_800092B0(s32 arg0) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (arg0 == D_8009ADF4[i]) {
            return 1;
        }
    }
    return 0;
}
