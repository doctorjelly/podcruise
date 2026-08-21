/* Independently written from scratchpad spec specs/func_8003D49C.md. */

#include "podcruise/types.h"

extern s16 D_80114470[2];

void func_8003D49C(f32 *arg0, f32 *arg1) {
    *arg0 = D_80114470[0] / 320.0;
    *arg1 = D_80114470[1] / 240.0;
}
