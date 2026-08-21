/* Recovered from specs/functions/recovered/medium_spatial_tranche.md. */

#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

extern f32 D_800AE8B0;

extern void func_8000097C(f32 distance, Vec3f *probe, Vec3f *point, f32 *normal);
extern void func_80081A2C(Vec3f *point, Vec3f *segmentStart, Vec3f *segmentEnd, Vec3f *out);

void func_80000B00(Vec3f *point, Vec3f *cornerA, Vec3f *cornerB, Vec3f *cornerC, Vec3f *probe, f32 *normal) {
    Vec3f edgeA;
    Vec3f edgeB;
    Vec3f edgeC;
    Vec3f best;
    f32 bestDistance;
    f32 distance;
    f32 dz;
    f32 dx;
    f32 dy;

    edgeA.x = cornerB->x - cornerA->x;
    edgeA.y = cornerB->y - cornerA->y;
    edgeA.z = cornerB->z - cornerA->z;
    edgeB.x = cornerC->x - cornerB->x;
    edgeB.y = cornerC->y - cornerB->y;
    edgeB.z = cornerC->z - cornerB->z;
    edgeC.x = cornerA->x - cornerC->x;
    edgeC.y = cornerA->y - cornerC->y;
    edgeC.z = cornerA->z - cornerC->z;

    func_80081A2C(point, cornerA, cornerB, &edgeA);
    func_80081A2C(point, cornerB, cornerC, &edgeB);
    func_80081A2C(point, cornerC, cornerA, &edgeC);

    dz = probe->z - edgeA.z;
    dx = probe->x - edgeA.x;
    dy = probe->y - edgeA.y;
    best.x = edgeA.x;
    best.y = edgeA.y;
    best.z = edgeA.z;
    bestDistance = dz * dz + (dx * dx + dy * dy);

    dz = probe->z - edgeB.z;
    dx = probe->x - edgeB.x;
    dy = probe->y - edgeB.y;
    distance = dz * dz + (dx * dx + dy * dy);
    if (distance < bestDistance) {
        best.x = edgeB.x;
        best.y = edgeB.y;
        best.z = edgeB.z;
        bestDistance = distance;
    }

    dz = probe->z - edgeC.z;
    dx = probe->x - edgeC.x;
    dy = probe->y - edgeC.y;
    distance = dz * dz + (dx * dx + dy * dy);
    if (distance < bestDistance) {
        best.x = edgeC.x;
        best.y = edgeC.y;
        best.z = edgeC.z;
        bestDistance = distance;
    }

    if (bestDistance <= D_800AE8B0) {
        func_8000097C(bestDistance, probe, &best, normal);
    }
}
