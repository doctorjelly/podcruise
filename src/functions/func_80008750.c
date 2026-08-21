/* Independently written from specs/functions/global_state.md. */

#include "podcruise/global_state.h"

extern u8 D_8009A324;

void func_80008750(u8 value) {
    D_8009A324 = value;
}
