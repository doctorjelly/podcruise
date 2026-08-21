/* Independently written from specs/functions/vector_distance.md. */

#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} PcVec3f;

extern f32 sqrtf(f32 value);
#if defined(__sgi)
#pragma intrinsic (sqrtf)
#endif

f32 func_80015470(const PcVec3f *from, const PcVec3f *to) {
    f32 delta[3];

    delta[0] = to->x - from->x;
    delta[1] = to->y - from->y;
    delta[2] = to->z - from->z;
    return sqrtf(delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2]);
}
