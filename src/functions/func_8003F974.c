/* Independently written from specs/functions/runtime_leaf_wrappers.md. */

#include "podcruise/runtime_leaves.h"

extern void func_8003F8FC(s32 first, s32 second, void *third);

void func_8003F974(s32 first, void *third) {
    func_8003F8FC(first, 0x416C6C21, third);
}
