/* Independently written from the specification for func_800823DC. */
#include "podcruise/types.h"

/* Signed distance of a plane-like record's fourth term, scaled by the third
 * component, offset back by the second vector's third component. */
f32 func_800823DC(f32 *a0, f32 *a1) {
    f32 t = (a1[0] * a0[0] + a1[1] * a0[1]) + a1[2] * a0[2];
    f32 q = (a0[3] - t) / a0[2];
    return q + a1[2];
}
