/* Independently written from specs/functions/runtime_leaf_wrappers.md. */

#include "podcruise/runtime_leaves.h"

extern void func_80030174(s32 argument, s32 *output);

s32 func_80030274(s32 argument) {
    s32 output;

    func_80030174(argument, &output);
    return output;
}
