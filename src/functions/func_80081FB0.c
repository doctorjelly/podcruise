/* Independently written from specs/functions/recovered/medium_world_tranche.md. */

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

extern void func_800179EC(Vec4f *arg0, Vec3f *arg1, Vec3f *arg2, Vec3f *arg3);
extern void func_800819A4(f32 *plane, f32 *point, f32 *result);
extern void func_80081A2C(Vec3f *point, Vec3f *segmentStart, Vec3f *segmentEnd, Vec3f *out);
extern s32 func_80081BE8(Vec3f *p0, Vec3f *p1, Vec3f *p2, Vec3f *p3, Vec3f *u, Vec3f *v, Vec3f *w);

f32 func_80081FB0(Vec3f *point, Vec3f *a, Vec3f *b, Vec3f *c, f32 radius, Vec3f *out, Vec3f *outNormal) {
    Vec3f edgeA;
    Vec3f edgeB;
    Vec3f edgeC;
    f32 delta[3];
    f32 d;
    f32 u1;
    f32 u2;
    f32 plane[4];
    f32 side;
    f32 best;
    s32 flipped;

    (void)side;
    (void)u1;
    (void)u2;
    func_800179EC((Vec4f *)plane, a, b, c);

    delta[0] = point->x - a->x;
    delta[1] = point->y - a->y;
    delta[2] = point->z - a->z;
    if (delta[0] * plane[0] + delta[1] * plane[1] + delta[2] * plane[2] < 0.0f) {
        flipped = 1;
    } else {
        flipped = 0;
    }

    func_800819A4((f32 *)plane, (f32 *)point, (f32 *)out);

    best = (point->z - out->z) * (point->z - out->z) + ((point->x - out->x) * (point->x - out->x) + (point->y - out->y) * (point->y - out->y));
    if (radius > 0.0f && best > radius) {
        return -1.0f;
    }

    edgeA.x = b->x - a->x;
    edgeA.y = b->y - a->y;
    edgeA.z = b->z - a->z;
    edgeB.x = c->x - b->x;
    edgeB.y = c->y - b->y;
    edgeB.z = c->z - b->z;
    edgeC.x = a->x - c->x;
    edgeC.y = a->y - c->y;
    edgeC.z = a->z - c->z;

    if (func_80081BE8(out, a, b, c, &edgeA, &edgeB, &edgeC) == 0) {
        func_80081A2C(out, a, b, &edgeA);
        func_80081A2C(out, b, c, &edgeB);
        func_80081A2C(out, c, a, &edgeC);

        best = (point->z - edgeA.z) * (point->z - edgeA.z) + ((point->x - edgeA.x) * (point->x - edgeA.x) + (point->y - edgeA.y) * (point->y - edgeA.y));
        out->x = edgeA.x;
        out->y = edgeA.y;
        out->z = edgeA.z;

        d = (point->z - edgeB.z) * (point->z - edgeB.z) + ((point->x - edgeB.x) * (point->x - edgeB.x) + (point->y - edgeB.y) * (point->y - edgeB.y));
        if (d < best) {
            out->x = edgeB.x;
            best = d;
            out->y = edgeB.y;
            out->z = edgeB.z;
        }

        d = (point->z - edgeC.z) * (point->z - edgeC.z) + ((point->x - edgeC.x) * (point->x - edgeC.x) + (point->y - edgeC.y) * (point->y - edgeC.y));
        if (d < best) {
            out->x = edgeC.x;
            best = d;
            out->y = edgeC.y;
            out->z = edgeC.z;
        }
    }

    if (flipped != 0) {
        outNormal->x = -plane[0];
        outNormal->y = -plane[1];
        outNormal->z = -plane[2];
    } else {
        outNormal->x = plane[0];
        outNormal->y = plane[1];
        outNormal->z = plane[2];
    }
    return best;
}
