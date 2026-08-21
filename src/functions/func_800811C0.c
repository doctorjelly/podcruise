/* Independently written from specs/functions/global_state.md. */

#include "podcruise/global_state.h"

extern f64 D_800A6750;
extern s32 D_800A6758;

void func_800811C0(f64 value) {
    D_800A6750 = value;
}

void func_800811CC(void) {
    D_800A6758 = 1;
}
