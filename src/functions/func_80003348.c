/* Recovered per specification specs/func_80003348.md (worker scratchpad). */
#include "podcruise/types.h"

extern f32 D_800AE908[3];

extern s32 func_80002BD4(f32 *, f32 *, f32 *, f32 *);
extern s32 func_80002E2C(f32 *, f32 *, f32 *);
extern void func_800179EC(f32 *, f32 *, f32 *, f32 *);
extern void func_80001864(f32 *, f32 *, f32 *, f32 *, f32 *);

void func_80003348(arg0, arg1)
s16 *arg0;
s16 arg1;
{
    f32 plane[4];
    f32 d[3];
    f32 c[3];
    f32 b[3];
    f32 a[3];

    a[0] = arg0[0];
    a[1] = arg0[1];
    a[2] = arg0[2];
    b[0] = arg0[3];
    b[1] = arg0[4];
    b[2] = arg0[5];
    c[0] = arg0[6];
    c[1] = arg0[7];
    c[2] = arg0[8];

    if (arg1 == 2) {
        d[0] = arg0[9];
        d[1] = arg0[10];
        d[2] = arg0[11];
        if (func_80002BD4(a, b, c, d)) {
            func_800179EC(plane, a, b, d);
            func_80001864(plane, a, b, d, D_800AE908);
            func_800179EC(plane, b, c, d);
            func_80001864(plane, b, c, d, D_800AE908);
        }
    } else if (func_80002E2C(a, b, c)) {
        if (arg1 == 1) {
            func_800179EC(plane, a, c, b);
            func_80001864(plane, a, c, b, D_800AE908);
        } else {
            func_800179EC(plane, a, b, c);
            func_80001864(plane, a, b, c, D_800AE908);
        }
    }
}
