/* Independently written from specs/functions/runtime_leaf_wrappers.md. */

#include "podcruise/runtime_leaves.h"

extern u32 func_80039178(u8 *argument, s32 size);

u32 func_8003931C(u8 *argument) {
    return func_80039178(argument + 4, 0x3EC);
}
