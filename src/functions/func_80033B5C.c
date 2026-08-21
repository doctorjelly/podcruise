/* Specification: $S/specs/func_80033B5C.md (scratchpad) */
#include "podcruise/types.h"

f32 func_80033B5C(f32 **arg0) {
    if (arg0 == 0) {
        return 0.0f;
    }
    if (arg0[0] == 0) {
        return 0.0f;
    }
    return arg0[0][0x44];
}
