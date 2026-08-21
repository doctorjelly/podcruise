/* Independently written from specs/functions/runtime_leaves.md. */

#include "podcruise/runtime_leaves.h"

extern u32 D_800A48D4;

void func_8003D488(u16 value) {
    D_800A48D4 = value & 0xFFFF;
}
