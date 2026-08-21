/* Implements the specification in specs/func_80002BD4.md (axis-slab rejection test). */
#include "podcruise/types.h"

extern f32 D_800AE8E0;
extern f32 D_800AE908[3];

s32 func_80002BD4(f32 *p0, f32 *p1, f32 *p2, f32 *p3) {
    f32 a[3];
    f32 b[3];
    f32 c[3];
    f32 d[3];
    f32 r;
    f32 nr;

    r = D_800AE8E0;
    nr = -r;

    a[0] = p0[0] - D_800AE908[0];
    a[1] = p0[1] - D_800AE908[1];
    a[2] = p0[2] - D_800AE908[2];
    b[0] = p1[0] - D_800AE908[0];
    b[1] = p1[1] - D_800AE908[1];
    b[2] = p1[2] - D_800AE908[2];
    c[0] = p2[0] - D_800AE908[0];
    c[1] = p2[1] - D_800AE908[1];
    c[2] = p2[2] - D_800AE908[2];
    d[0] = p3[0] - D_800AE908[0];
    d[1] = p3[1] - D_800AE908[1];
    d[2] = p3[2] - D_800AE908[2];

    if ((a[0] < nr && b[0] < nr && c[0] < nr && d[0] < nr) ||
        (a[0] > r && b[0] > r && c[0] > r && d[0] > r) ||
        (a[1] < nr && b[1] < nr && c[1] < nr && d[1] < nr) ||
        (a[1] > r && b[1] > r && c[1] > r && d[1] > r) ||
        (a[2] < nr && b[2] < nr && c[2] < nr && d[2] < nr) ||
        (a[2] > r && b[2] > r && c[2] > r && d[2] > r)) {
        return 0;
    }
    return 1;
}
