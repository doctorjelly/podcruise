/* Independently written from $S/specs/func_800179EC.md. */

#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4f;

extern void func_800154D0(Vec4f *arg0);
extern void func_80015538(Vec4f *arg0, Vec3f *arg1, Vec3f *arg2);

void func_800179EC(Vec4f *arg0, Vec3f *arg1, Vec3f *arg2, Vec3f *arg3) {
    Vec3f edge0;
    Vec3f edge1;
    Vec4f scratch;

    (void)scratch;

    edge0.x = arg2->x - arg1->x;
    edge0.y = arg2->y - arg1->y;
    edge0.z = arg2->z - arg1->z;

    edge1.x = arg3->x - arg2->x;
    edge1.y = arg3->y - arg2->y;
    edge1.z = arg3->z - arg2->z;

    func_80015538(arg0, &edge0, &edge1);
    func_800154D0(arg0);

    arg0->w = arg1->z * arg0->z + (arg0->x * arg1->x + arg0->y * arg1->y);
}
