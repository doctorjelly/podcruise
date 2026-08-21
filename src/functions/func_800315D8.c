/* Independently written from scratchpad spec specs/func_800315D8.md. */

#include "podcruise/types.h"

extern s32 D_800DB8AC[][7];

void func_800315D8(s32 arg0) {
    s32 i;

    if (arg0 == -1) {
        for (i = 0; i != 4; i++) {
            func_800315D8(i);
        }
    } else {
        D_800DB8AC[arg0][0] = 0;
    }
}
