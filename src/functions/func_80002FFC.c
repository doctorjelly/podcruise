/* Recovered per specification specs/func_80002FFC.md (indexed polygon cull and submit). */
#include "podcruise/types.h"

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vtx3s;

extern f32 D_800AE908[3];

extern s32 func_80002BD4(f32 *, f32 *, f32 *, f32 *);
extern s32 func_80002E2C(f32 *, f32 *, f32 *);
extern void func_800179EC(f32 *, f32 *, f32 *, f32 *);
extern void func_80001864(f32 *, f32 *, f32 *, f32 *, f32 *);

void func_80002FFC(verts, mode, indices)
Vtx3s *verts;
s16 mode;
u16 *indices;
{
    f32 plane[4];
    f32 d[3];
    f32 c[3];
    f32 b[3];
    f32 a[3];

    a[0] = verts[indices[0]].x;
    a[1] = verts[indices[0]].y;
    a[2] = verts[indices[0]].z;
    b[0] = verts[indices[1]].x;
    b[1] = verts[indices[1]].y;
    b[2] = verts[indices[1]].z;
    c[0] = verts[indices[2]].x;
    c[1] = verts[indices[2]].y;
    c[2] = verts[indices[2]].z;

    if (mode == 2) {
        d[0] = verts[indices[3]].x;
        d[1] = verts[indices[3]].y;
        d[2] = verts[indices[3]].z;

        if (func_80002BD4(a, b, c, d)) {
            func_800179EC(plane, a, b, d);
            func_80001864(plane, a, b, d, D_800AE908);
            func_800179EC(plane, b, c, d);
            func_80001864(plane, b, c, d, D_800AE908);
        }
    } else {
        if (func_80002E2C(a, b, c)) {
            if (mode == 1) {
                func_800179EC(plane, a, c, b);
                func_80001864(plane, a, c, b, D_800AE908);
            } else {
                func_800179EC(plane, a, b, c);
                func_80001864(plane, a, b, c, D_800AE908);
            }
        }
    }
}
