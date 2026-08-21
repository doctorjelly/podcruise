/* Independently written from specs/functions/runtime_leaf_wrappers.md. */

#include "podcruise/types.h"

extern void func_80031BBC(s32 index);

void func_80031924(s32 index) {
    func_80031BBC(index);
}
