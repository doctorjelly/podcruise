/* Specification: $S/specs/func_8008ECF0.md */
#include "podcruise/types.h"

f64 func_8008ECF0(f64 arg0, s32 arg1) {
    if (arg1 != 0) {
        arg0 *= (f64)(1 << arg1);
    }
    return arg0;
}
