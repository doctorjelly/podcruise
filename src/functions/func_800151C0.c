/* Independently written from specs/functions/vector_math.md. */

#include "podcruise/vector_math.h"

extern f32 sqrtf(f32 value);
#if defined(__sgi)
#pragma intrinsic (sqrtf)
#endif

f32 func_800151C0(const PcVec2f *vector) {
    f32 y = vector->y;
    f32 x = vector->x;
    f32 result;

    result = y * y;
    result += x * x;
    return sqrtf(result);
}
