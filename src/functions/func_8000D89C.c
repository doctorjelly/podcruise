/* Specification: scratchpad specs/func_8000D89C.md */
#include "podcruise/types.h"

extern s32 D_8009B800;
extern s32 func_8000D130();
extern s32 func_8000C77C();
extern s32 func_8000D4E8();

s32 func_8000D89C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 result;

    if (D_8009B800 == 0) {
        result = func_8000D130(arg0, arg1, arg2, arg3, arg4);
    } else if (D_8009B800 == 1) {
        result = func_8000C77C(arg0, arg1, arg2, arg3, arg4);
    } else if (D_8009B800 == 2) {
        result = func_8000D4E8(arg0, arg1, arg2, arg3, arg4);
    }
    return result;
}
