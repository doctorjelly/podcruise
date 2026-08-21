/* Independently written from specs/functions/runtime_leaf_wrappers.md. */

#include "podcruise/runtime_leaves.h"

extern s32 func_8002FAFC(void);

s32 func_8002FB18(u32 argument) {
    if (argument < (u32)func_8002FAFC()) {
        return 1;
    }
    return 0;
}
