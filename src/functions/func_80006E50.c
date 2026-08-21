/* Independently written from specs/functions/leaf_state.md. */

#include "podcruise/leaf_state.h"

void func_80006E50(void *object, u32 mask) {
    u32 *flags = (u32 *)((u8 *)object + 0x100);

    *flags |= mask;
}

void func_80006E60(void *object, u32 mask) {
    u32 *flags = (u32 *)((u8 *)object + 0x100);

    *flags &= ~mask;
}
