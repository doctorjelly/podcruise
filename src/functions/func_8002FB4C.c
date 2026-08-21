/* Specification: specs/func_8002FB4C.md (worker-authored) */
#include "podcruise/types.h"

extern s32 D_800A2868;
extern u32 D_800D9DD8[];

s32 func_8002FB4C(u32 value) {
    s32 i;

    for (i = D_800A2868 - 1; i > 0; i--) {
        if (value >= D_800D9DD8[i]) {
            break;
        }
    }
    return i + 1;
}
