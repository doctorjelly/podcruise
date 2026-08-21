/* Independently written from specs/functions/runtime_leaf_wrappers.md. */

#include "podcruise/runtime_leaves.h"

extern void func_80038F68(s32 argument);

void func_80086CA0(s32 argument) {
    if (argument != -1) {
        func_80038F68(argument);
    }
}
