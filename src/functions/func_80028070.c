/* Independently written from scratchpad spec specs/func_80028070.md. */

#include "podcruise/types.h"

extern void func_80029A3C(s32, s32);

void func_80028070(s32 arg0) {
    s32 i;

    (void)arg0;

    for (i = 0; i < 12; i++) {
        func_80029A3C(0, i);
    }

    for (i = 0; i != 4; i++) {
        func_80029A3C(1, i);
    }
}
