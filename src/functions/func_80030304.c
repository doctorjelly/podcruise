/* Independently written from specs/functions/runtime_leaf_wrappers.md. */

#include "podcruise/runtime_leaves.h"

extern void func_8003FB78(s32 argument, s32 second, s32 third);

void func_80030304(s32 argument) {
    func_8003FB78(argument, 0, 0);
}
