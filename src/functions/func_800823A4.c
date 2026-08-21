/* Specification: specs/func_800823A4.md */
#include "podcruise/types.h"

f32 func_800823A4(f32 *a, f32 *b) {
    f32 d;

    d = b[0] * a[0] + b[1] * a[1] + b[2] * a[2];
    return a[3] - d;
}
