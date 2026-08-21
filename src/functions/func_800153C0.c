/* Independently written from specs/functions/vector_math.md. */

#include "podcruise/vector_math.h"

extern f32 sqrtf(f32 value);
#if defined(__sgi)
#pragma intrinsic (sqrtf)
#endif

f32 func_800153C0(const PcVec3f *vector) {
    return sqrtf(vector->z * vector->z +
                 (vector->x * vector->x + vector->y * vector->y));
}

f32 func_800153EC(const PcVec3f *left, const PcVec3f *right) {
    f32 x = left->x - right->x;
    f32 y = left->y - right->y;
    f32 z = left->z - right->z;
    f32 result;

    result = x * x;
    result += y * y;
    result += z * z;
    return result;
}
