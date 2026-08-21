/* Independently written from specs/functions/runtime_leaf_wrappers.md. */

#include "podcruise/types.h"

extern void func_80031BBC(s32 index);
extern void func_80031924(s32 argument);

void func_800319CC(s32 argument) {
    func_80031BBC(argument);
    func_80031924(argument);
}
