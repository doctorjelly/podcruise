/* Independently written from specs/functions/runtime_leaf_wrappers.md. */

#include "podcruise/runtime_leaves.h"

extern u8 D_8014C3B8[];
extern s32 func_8008C930(void *argument, s32 second, s32 third);

void func_80090634(void) {
    func_8008C930(D_8014C3B8, 0, 0);
}
