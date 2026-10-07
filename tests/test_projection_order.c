#include <assert.h>
#include <string.h>
/* Captured helper outputs isolate read/write ordering, not real geometry. */
#include "../src/functions/func_80081FB0.c"

static int edge_calls;
void func_800179EC(Vec4f *p, Vec3f *a, Vec3f *b, Vec3f *c) {
    (void)a; (void)b; (void)c;
    p->x=0.0f; p->y=0.0f; p->z=1.0f; p->w=0.0f;
}
void func_800819A4(f32 *plane, f32 *point, f32 *result) {
    (void)plane;
    memmove(result, point, sizeof(Vec3f));
}
s32 func_80081BE8(Vec3f *p0, Vec3f *p1, Vec3f *p2, Vec3f *p3, Vec3f *u, Vec3f *v, Vec3f *w) {
    (void)p0;(void)p1;(void)p2;(void)p3;(void)u;(void)v;(void)w;
    return 0;
}
void func_80081A2C(Vec3f *point, Vec3f *start, Vec3f *end, Vec3f *out) {
    (void)point;(void)start;(void)end;
    switch (edge_calls++) {
    case 0: out->x=1.0f;out->y=2.0f;out->z=3.0f;break;
    case 1: out->x=100.0f;out->y=200.0f;out->z=300.0f;break;
    case 2: out->x=200.0f;out->y=300.0f;out->z=400.0f;break;
    default: assert(0);
    }
}
static void run(int alias) {
    Vec3f point={10.0f,20.0f,30.0f},out={-9.0f,-9.0f,-9.0f};
    Vec3f a={0.0f,0.0f,0.0f},b={1.0f,0.0f,0.0f},c={0.0f,1.0f,0.0f};
    Vec3f normal={-9.0f,-9.0f,-9.0f};
    Vec3f *dest=alias?&point:&out;
    edge_calls=0;
    f32 got=func_80081FB0(&point,&a,&b,&c,0.0f,dest,&normal);
    /* Independent squared distance: 9*9 + 18*18 + 27*27 = 1134. */
    assert(got == 1134.0f);
    assert(edge_calls==3);
    assert(dest->x==1.0f && dest->y==2.0f && dest->z==3.0f);
    assert(normal.x==0.0f && normal.y==0.0f && normal.z==1.0f);
    if(!alias) assert(point.x==10.0f && point.y==20.0f && point.z==30.0f);
}
int main(void){run(0);run(1);return 0;}
