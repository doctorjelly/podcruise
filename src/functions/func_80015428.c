/* Specification: specs/func_80015428.md (worker-authored) */
#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
} PcVec2f80015428;

extern f32 sqrtf(f32 value);
#if defined(__sgi)
#pragma intrinsic (sqrtf)
#endif

f32 func_80015428(const PcVec2f80015428 *from, const PcVec2f80015428 *to) {
    f32 delta[2];

    delta[0] = to->x - from->x;
    delta[1] = to->y - from->y;
    return sqrtf(delta[0] * delta[0] + delta[1] * delta[1]);
}
