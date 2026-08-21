/* Independently written from specs/functions/runtime_leaf_wrappers.md. */

#include "podcruise/runtime_leaves.h"

extern void func_80039768(s32 argument);

void func_80039890(void) {
    func_80039768(0);
    func_80039768(0x400);
}
