/* Independently written from specs/functions/global_state.md. */

#include "podcruise/global_state.h"

extern s16 D_801488B8[3];

void func_80086CC8(s32 first, s32 second, s32 third) {
    D_801488B8[0] = (s16)first;
    D_801488B8[1] = (s16)second;
    D_801488B8[2] = (s16)third;
}
