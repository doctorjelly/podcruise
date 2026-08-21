/*
 * Independently written from specs/functions/bootstrap_state.md.
 * Status: byte-matching under ido53_o2; integrated in the exact USA rebuild.
 */

#include "podcruise/bootstrap_state.h"

extern s32 D_8009A270;
extern s32 D_8009A280;

void func_80000520(s32 value) {
    D_8009A270 = value;
}

void func_8000052C(void) {
    D_8009A280 = 0;
}

s32 func_80000538(void) {
    return D_8009A280;
}
