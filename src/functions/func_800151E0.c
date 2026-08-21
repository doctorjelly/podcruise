/* Independently written from specs/functions/func_800151E0.md. */

#include "podcruise/types.h"

extern f32 func_800151C0(f32 *vector);
extern f32 D_800A87F0;

f32 func_800151E0(f32 *vector) {
    f32 length;

    length = func_800151C0(vector);
    if (D_800A87F0 <= length) {
        vector[0] = vector[0] / length;
        vector[1] = vector[1] / length;
    }
    return length;
}
