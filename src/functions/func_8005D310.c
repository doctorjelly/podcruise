/* Independently written from specs/functions/global_state.md. */

#include "podcruise/global_state.h"

extern s32 D_800A59FC;
extern s32 D_800A5A00;

void func_8005D310(s32 first, s32 second) {
    D_800A59FC = first;
    D_800A5A00 = second;
}
