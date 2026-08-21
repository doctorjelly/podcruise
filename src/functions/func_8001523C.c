/* Specification: $S/specs/func_8001523C.md */
#include "podcruise/types.h"

f32 func_8001523C(f32 *arg0, f32 *arg1) {
    f32 dx;
    f32 dy;

    dx = arg0[0] - arg1[0];
    dy = arg0[1] - arg1[1];
    return (dx * dx) + (dy * dy);
}
