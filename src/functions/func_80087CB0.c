/* Independently written from specs/functions/recovered/func_80087CB0.md. */

#include "podcruise/types.h"

extern f32 sqrtf(f32 value);
#if defined(__sgi)
#pragma intrinsic(sqrtf)
#endif

f32 func_80087CB0(f32 value) {
    return sqrtf(value);
}
