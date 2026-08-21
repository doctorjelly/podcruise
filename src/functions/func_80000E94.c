/* Independently written from $S/specs/func_80000E94.md (triangle clipped to a slab). */

#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

extern f32 D_800AE948[3];
extern f32 D_800AE954;
extern f32 D_800AE958;

#define DOT(v) ((v)[0] * D_800AE948[0] + (v)[1] * D_800AE948[1] + (v)[2] * D_800AE948[2])

const f32 D_800A80F0[3] = {0.0f, 0.0f, 0.0f};

extern void func_8000097C(f32 distance, Vec3f *probe, Vec3f *point, f32 *normal);
extern void func_80000B00(Vec3f *point, Vec3f *cornerA, Vec3f *cornerB, Vec3f *cornerC, Vec3f *probe, f32 *normal);
extern void func_80000D80(f32 *out, f32 *from, f32 *to, f32 *normal, f32 plane);

void func_80000E94(f32 *point, f32 *v1, f32 *v2, f32 *v3, f32 *probe, f32 distance, f32 *normal) {
    f32 t1;
    f32 t2;
    f32 t3;
    s16 k1;
    s16 k2;
    s16 k3;
    f32 p0[3];
    f32 p1[3];
    f32 p2[3];
    f32 p3[3];
    f32 p4[3];
    f32 plane;
    f32 t0;

    t0 = DOT(point);
    if (D_800AE958 < t0 && t0 < D_800AE954) {
        func_8000097C(distance, (Vec3f *)probe, (Vec3f *)point, normal);
        return;
    }

    k1 = 0;
    k2 = 0;
    k3 = 0;
    t1 = DOT(v1);
    t2 = DOT(v2);
    t3 = DOT(v3);
    if (t1 < D_800AE958) {
        k1 = -1;
    } else if (D_800AE954 < t1) {
        k1 = 2;
    }
    if (t2 < D_800AE958) {
        k2 = -1;
    } else if (D_800AE954 < t2) {
        k2 = 2;
    }
    if (t3 < D_800AE958) {
        k3 = -1;
    } else if (D_800AE954 < t3) {
        k3 = 2;
    }

    plane = D_800AE954;
    switch (k1 + k2 + k3) {
    case -3:
    case 5:
    case 6:
        break;
    case -1:
        plane = D_800AE958;
        /* fallthrough */
    case 2:
        if (k1 != 0) {
            func_80000D80(p0, v1, v2, D_800AE948, plane);
            func_80000D80(p1, v1, v3, D_800AE948, plane);
            func_80000B00((Vec3f *)point, (Vec3f *)p0, (Vec3f *)v2, (Vec3f *)p1, (Vec3f *)probe, normal);
            func_80000B00((Vec3f *)point, (Vec3f *)p1, (Vec3f *)v2, (Vec3f *)v3, (Vec3f *)probe, normal);
        } else if (k2 != 0) {
            func_80000D80(p0, v2, v3, D_800AE948, plane);
            func_80000D80(p1, v2, v1, D_800AE948, plane);
            func_80000B00((Vec3f *)point, (Vec3f *)p0, (Vec3f *)v3, (Vec3f *)p1, (Vec3f *)probe, normal);
            func_80000B00((Vec3f *)point, (Vec3f *)p1, (Vec3f *)v3, (Vec3f *)v1, (Vec3f *)probe, normal);
        } else {
            func_80000D80(p0, v3, v1, D_800AE948, plane);
            func_80000D80(p1, v3, v2, D_800AE948, plane);
            func_80000B00((Vec3f *)point, (Vec3f *)p0, (Vec3f *)v1, (Vec3f *)p1, (Vec3f *)probe, normal);
            func_80000B00((Vec3f *)point, (Vec3f *)p1, (Vec3f *)v1, (Vec3f *)v2, (Vec3f *)probe, normal);
        }
        break;
    case -2:
        plane = D_800AE958;
        /* fallthrough */
    case 4:
        if (k1 == 0) {
            func_80000D80(p0, v1, v2, D_800AE948, plane);
            func_80000D80(p1, v1, v3, D_800AE948, plane);
            func_80000B00((Vec3f *)point, (Vec3f *)v1, (Vec3f *)p0, (Vec3f *)p1, (Vec3f *)probe, normal);
        } else if (k2 == 0) {
            func_80000D80(p0, v2, v3, D_800AE948, plane);
            func_80000D80(p1, v2, v1, D_800AE948, plane);
            func_80000B00((Vec3f *)point, (Vec3f *)v2, (Vec3f *)p0, (Vec3f *)p1, (Vec3f *)probe, normal);
        } else {
            func_80000D80(p0, v3, v1, D_800AE948, plane);
            func_80000D80(p1, v3, v2, D_800AE948, plane);
            func_80000B00((Vec3f *)point, (Vec3f *)v3, (Vec3f *)p0, (Vec3f *)p1, (Vec3f *)probe, normal);
        }
        break;
    case 1:
        if (k1 == 0) {
            p2[0] = v1[0];
            p2[1] = v1[1];
            p2[2] = v1[2];
            func_80000D80(p0, v2, v3, D_800AE948, D_800AE954);
            func_80000D80(p4, v2, v3, D_800AE948, D_800AE958);
            if (k2 == 2) {
                func_80000D80(p1, v1, v2, D_800AE948, D_800AE954);
                func_80000D80(p3, v1, v3, D_800AE948, D_800AE958);
            } else {
                func_80000D80(p1, v1, v3, D_800AE948, D_800AE954);
                func_80000D80(p3, v1, v2, D_800AE948, D_800AE958);
            }
        } else if (k2 == 0) {
            p2[0] = v2[0];
            p2[1] = v2[1];
            p2[2] = v2[2];
            func_80000D80(p0, v3, v1, D_800AE948, D_800AE954);
            func_80000D80(p4, v3, v1, D_800AE948, D_800AE958);
            if (k3 == 2) {
                func_80000D80(p1, v2, v3, D_800AE948, D_800AE954);
                func_80000D80(p3, v2, v1, D_800AE948, D_800AE958);
            } else {
                func_80000D80(p1, v2, v1, D_800AE948, D_800AE954);
                func_80000D80(p3, v2, v3, D_800AE948, D_800AE958);
            }
        } else {
            p2[0] = v3[0];
            p2[1] = v3[1];
            p2[2] = v3[2];
            func_80000D80(p0, v1, v2, D_800AE948, D_800AE954);
            func_80000D80(p4, v1, v2, D_800AE948, D_800AE958);
            if (k1 == 2) {
                func_80000D80(p1, v3, v1, D_800AE948, D_800AE954);
                func_80000D80(p3, v3, v2, D_800AE948, D_800AE958);
            } else {
                func_80000D80(p1, v3, v2, D_800AE948, D_800AE954);
                func_80000D80(p3, v3, v1, D_800AE948, D_800AE958);
            }
        }
        func_80000B00((Vec3f *)point, (Vec3f *)p0, (Vec3f *)p1, (Vec3f *)p2, (Vec3f *)probe, normal);
        func_80000B00((Vec3f *)point, (Vec3f *)p0, (Vec3f *)p2, (Vec3f *)p4, (Vec3f *)probe, normal);
        func_80000B00((Vec3f *)point, (Vec3f *)p2, (Vec3f *)p3, (Vec3f *)p4, (Vec3f *)probe, normal);
        break;
    case 0:
    case 3:
        if (k2 == k3) {
            func_80000D80(p0, v1, v2, D_800AE948, D_800AE954);
            func_80000D80(p1, v1, v3, D_800AE948, D_800AE954);
            func_80000D80(p2, v1, v3, D_800AE948, D_800AE958);
            func_80000D80(p3, v1, v2, D_800AE948, D_800AE958);
        } else if (k3 == k1) {
            func_80000D80(p0, v2, v3, D_800AE948, D_800AE954);
            func_80000D80(p1, v2, v1, D_800AE948, D_800AE954);
            func_80000D80(p2, v2, v1, D_800AE948, D_800AE958);
            func_80000D80(p3, v2, v3, D_800AE948, D_800AE958);
        } else {
            func_80000D80(p0, v3, v1, D_800AE948, D_800AE954);
            func_80000D80(p1, v3, v2, D_800AE948, D_800AE954);
            func_80000D80(p2, v3, v2, D_800AE948, D_800AE958);
            func_80000D80(p3, v3, v1, D_800AE948, D_800AE958);
        }
        func_80000B00((Vec3f *)point, (Vec3f *)p0, (Vec3f *)p1, (Vec3f *)p2, (Vec3f *)probe, normal);
        func_80000B00((Vec3f *)point, (Vec3f *)p0, (Vec3f *)p2, (Vec3f *)p3, (Vec3f *)probe, normal);
        break;
    }
}
