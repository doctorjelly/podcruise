/* Independently written from scratchpad spec specs/func_80031640.md. */

#include "podcruise/types.h"

extern s16 D_800DB8A8[][14];

void func_80031640(s32 arg0) {
    s32 i;

    if (arg0 == -1) {
        for (i = 0; i != 4; i++) {
            func_80031640(i);
        }
    } else {
        D_800DB8A8[arg0][0] = 0;
    }
}
