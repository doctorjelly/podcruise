/* Independently written from specs/functions/leaf_state.md. */

#include "podcruise/leaf_state.h"

void func_80006F28(void *object, f32 value) {
    f32 *field = (f32 *)((u8 *)object + 0xDC);

    *field = value;
}
