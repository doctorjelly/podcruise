/* Independently written from specs/functions/runtime_leaves.md. */

#include "podcruise/runtime_leaves.h"

extern s32 D_800DB910[];

void func_80031BEC(s32 index) {
    D_800DB910[index] = 1;
}
