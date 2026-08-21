/* Independently written from scratchpad spec specs/func_800941B0.md. */

#include "podcruise/types.h"

extern s32 *D_800A7BC0;

s32 func_800941B0(s32 *arg0) {
    if (arg0 == 0) {
        arg0 = D_800A7BC0;
    }
    return arg0[1];
}
