/* Independently written from specs/functions/runtime_leaf_wrappers.md. */

#include "podcruise/runtime_leaves.h"

extern s32 D_800D9DBC;
extern s32 func_8002FAFC(void);

s32 func_8002FC58(void) {
    return D_800D9DBC - func_8002FAFC();
}
