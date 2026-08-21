/* Independently written from specs/functions/selector_state.md. */

#include "podcruise/selector_state.h"

extern s32 D_8009A290;
extern s32 D_8009A28C;

void func_80005B1C(s32 selector, s32 value) {
    if (selector == 3) {
        D_8009A290 = value;
    }
    if (selector == 5) {
        D_8009A28C = value;
    }
}

s32 func_80005B44(s32 selector) {
    if (selector == 3) {
        return D_8009A290;
    }
    if (selector == 5) {
        return D_8009A28C;
    }
    return -1;
}
