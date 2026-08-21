/* Independently written from specs/functions/runtime_leaf_wrappers.md. */

#include "podcruise/runtime_leaves.h"

extern void func_80093980(s32 argument);

void func_8008B190(void) {
    func_80093980(0x400);
}
