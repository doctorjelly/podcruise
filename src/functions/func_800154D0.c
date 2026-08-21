/* Recovered from specification specs/func_800154D0.md (worker tier2_18). */
#include "podcruise/types.h"

extern f32 func_800153C0(f32 *vector);
extern f32 D_800A87F4;

f32 func_800154D0(f32 *vector) {
    f32 length;

    length = func_800153C0(vector);
    if (D_800A87F4 <= length) {
        vector[0] /= length;
        vector[1] /= length;
        vector[2] /= length;
    }
    return length;
}
