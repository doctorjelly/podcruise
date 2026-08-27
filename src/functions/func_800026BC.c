/* Recovered from specs/func_800026BC.md (bounding-box reject then polygon submit) */
#include "podcruise/types.h"

extern f32 D_800AE8E8[7];
extern f32 D_800AE918[3];
extern f32 D_800AE928[3];

extern void func_800179EC(f32 *, f32 *, f32 *, f32 *);
extern void func_80001E80(f32 *, f32 *, f32 *, f32 *, f32 *);

void func_800026BC(points, mode)
s16 *points;
s16 mode;
{
    f32 plane[4];
    f32 d[3];
    f32 c[3];
    f32 b[3];
    f32 a[3];

    a[0] = points[0];
    a[1] = points[1];
    a[2] = points[2];
    b[0] = points[3];
    b[1] = points[4];
    b[2] = points[5];
    c[0] = points[6];
    c[1] = points[7];
    c[2] = points[8];

    if (mode == 2) {
        d[0] = points[9];
        d[1] = points[10];
        d[2] = points[11];

        if (a[0] < D_800AE928[0] && b[0] < D_800AE928[0] && c[0] < D_800AE928[0] && d[0] < D_800AE928[0]) {
            return;
        }
        if (D_800AE918[0] < a[0] && D_800AE918[0] < b[0] && D_800AE918[0] < c[0] && D_800AE918[0] < d[0]) {
            return;
        }
        if (a[1] < D_800AE928[1] && b[1] < D_800AE928[1] && c[1] < D_800AE928[1] && d[1] < D_800AE928[1]) {
            return;
        }
        if (D_800AE918[1] < a[1] && D_800AE918[1] < b[1] && D_800AE918[1] < c[1] && D_800AE918[1] < d[1]) {
            return;
        }
        if (a[2] < D_800AE928[2] && b[2] < D_800AE928[2] && c[2] < D_800AE928[2] && d[2] < D_800AE928[2]) {
            return;
        }
        if (D_800AE918[2] < a[2] && D_800AE918[2] < b[2] && D_800AE918[2] < c[2] && D_800AE918[2] < d[2]) {
            return;
        }
        func_800179EC(plane, a, b, d);
        func_80001E80(plane, a, b, d, D_800AE8E8);
        func_800179EC(plane, b, c, d);
        func_80001E80(plane, b, c, d, D_800AE8E8);
    } else {
        if ((a[0] < D_800AE928[0] && b[0] < D_800AE928[0] && c[0] < D_800AE928[0]) ||
            (D_800AE918[0] < a[0] && D_800AE918[0] < b[0] && D_800AE918[0] < c[0])) {
            return;
        }
        if ((a[1] < D_800AE928[1] && b[1] < D_800AE928[1] && c[1] < D_800AE928[1]) ||
            (D_800AE918[1] < a[1] && D_800AE918[1] < b[1] && D_800AE918[1] < c[1])) {
            return;
        }
        if ((a[2] < D_800AE928[2] && b[2] < D_800AE928[2] && c[2] < D_800AE928[2]) ||
            (D_800AE918[2] < a[2] && D_800AE918[2] < b[2] && D_800AE918[2] < c[2])) {
            return;
        }
        if (mode == 1) {
            func_800179EC(plane, a, c, b);
            func_80001E80(plane, a, c, b, D_800AE8E8);
        } else {
            func_800179EC(plane, a, b, c);
            func_80001E80(plane, a, b, c, D_800AE8E8);
        }
    }
}
