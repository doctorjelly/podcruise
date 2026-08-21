/* Independently written from specs/functions/global_state.md. */

#include "podcruise/global_state.h"

extern s16 D_800A1CD0[2];

void func_80011ECC(s16 first, s16 second) {
    D_800A1CD0[0] = first;
    D_800A1CD0[1] = second;
}

void func_80011EE8(s16 *first, s16 *second) {
    *first = D_800A1CD0[0];
    *second = D_800A1CD0[1];
}
