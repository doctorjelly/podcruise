/* Specification: scratchpad/specs/func_8006B9C8.md */
#include "podcruise/types.h"

extern f32 D_800AD5E8;
extern void func_80015190(f32 *, f32 *, f32, f32 *);

f32 func_8006B9C8(f32 *a, f32 *b, f32 *c, f32 *d, f32 *outA, f32 *outB, f32 *dirA, f32 *dirB) {
    f32 rel[3];
    f32 diff[3];
    f32 denom;
    f32 t;

    dirA[0] = b[0] - a[0];
    dirA[1] = b[1] - a[1];
    dirB[0] = d[0] - c[0];
    dirB[1] = d[1] - c[1];
    rel[0] = a[0] - c[0];
    rel[1] = a[1] - c[1];
    diff[0] = dirA[0] - dirB[0];
    diff[1] = dirA[1] - dirB[1];
    denom = diff[0] * diff[0] + diff[1] * diff[1];
    if (denom < D_800AD5E8) {
        if (-denom < D_800AD5E8) {
            return -1.0f;
        }
    }
    t = -(rel[0] * diff[0] + rel[1] * diff[1]) / denom;
    if (t < 0.0f) {
        t = 0.0f;
    }
    if (1.0f < t) {
        t = 1.0f;
    }
    func_80015190(outA, a, t, dirA);
    func_80015190(outB, c, t, dirB);
    return t;
}
