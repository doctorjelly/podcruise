/* Independently written from specs/functions/recovered/boundary_state_tranche.md. */
#include "podcruise/types.h"

f32 func_800823DC(f32 *a0, f32 *a1) {
    return (a0[3] - (a0[2] * a1[2] + (a1[0] * a0[0] + a1[1] * a0[1]))) / a0[2] + a1[2];
}
