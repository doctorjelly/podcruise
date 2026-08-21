/* Independently written from specs/functions/leaf_state.md. */

#include "podcruise/leaf_state.h"

extern u32 D_800D2140[];

u32 func_80009524(s32 index, u32 mask) {
    return D_800D2140[index] & mask;
}

void func_8000953C(s32 index, u32 mask) {
    D_800D2140[index] |= mask;
}

void func_8000955C(s32 index, u32 mask) {
    D_800D2140[index] &= ~mask;
}
