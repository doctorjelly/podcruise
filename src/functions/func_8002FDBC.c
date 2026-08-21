/* Independently written from specs/functions/runtime_leaf_wrappers.md. */

#include "podcruise/runtime_leaves.h"

extern u8 D_800D9C70[];
extern s32 func_80087E80(void *argument, s32 second, s32 third);

s32 func_8002FDBC(void) {
    if (func_80087E80(D_800D9C70, 0, 0) != -1) {
        return 1;
    }
    return 0;
}
