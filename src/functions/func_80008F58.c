/* Independently written from specs/functions/global_state.md. */

#include "podcruise/global_state.h"

extern f32 D_8009AD08;
extern f32 D_8009AD0C;

void func_80008F58(f32 first, f32 second) {
    D_8009AD08 = first;
    D_8009AD0C = second;
}
