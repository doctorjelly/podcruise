/* Independently written from specs/functions/runtime_leaf_wrappers.md. */

#include "podcruise/types.h"

extern f32 func_80014D4C(f32 value);

f32 func_80014F2C(f32 value) {
    return 90.0f - func_80014D4C(value);
}
