/* Independently written from specs/functions/leaf_state.md. */

#include "podcruise/leaf_state.h"

void func_80006EB4(void *object, f32 value) {
    f32 *field = (f32 *)((u8 *)object + 0x110);

    *field = value;
}
