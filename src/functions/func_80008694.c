/* Independently written from specs/functions/recovered/boundary_state_tranche.md. */

#include "podcruise/types.h"

extern s32 D_8009A2C0;

s32 func_80008694(s32 request) {
    s32 result;

    if (request == 0) {
        D_8009A2C0 = 1;
    } else if (request == 1) {
        D_8009A2C0 = 0;
    } else if (request == -1) {
        D_8009A2C0 = !D_8009A2C0;
    }

    result = !D_8009A2C0;
    return result;
}
