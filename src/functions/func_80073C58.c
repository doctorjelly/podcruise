/* Independently written from scratchpad spec specs/func_80073C58.md. */

#include "podcruise/types.h"

f32 func_80073C58(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    if (arg1 + arg4 < arg0) {
        arg0 = arg1 + arg4;
    }
    if (arg0 < arg1 - arg5) {
        arg0 = arg1 - arg5;
    }
    if (arg0 < arg2) {
        arg0 = arg2;
    }
    if (arg3 < arg0) {
        arg0 = arg3;
    }
    return arg0;
}
