/* Independently written from scratchpad spec specs/func_80085EB0.md. */

#include "podcruise/types.h"

extern f32 sqrtf(f32 value);
#if defined(__sgi)
#pragma intrinsic (sqrtf)
#endif

extern f32 func_800153EC(f32 *a, f32 *b);
extern s32 D_800A694C;
extern f32 D_801489C8[][3];

f32 func_80085EB0(f32 *point) {
    f32 nearest;
    s32 index;

    if (D_800A694C <= 0) {
        return -1.0f;
    }

    nearest = func_800153EC(point, D_801489C8[0]);
    for (index = 1; index < D_800A694C; index++) {
        f32 distance = func_800153EC(point, D_801489C8[index]);

        if (distance < nearest) {
            nearest = distance;
        }
    }
    return sqrtf(nearest);
}
