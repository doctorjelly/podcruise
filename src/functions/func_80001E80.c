/* Independently written from scratchpad spec specs/func_80001E80.md. */

#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} PcVec3f;

extern f32 func_80001D34(f32 *plane, f32 *ray, f32 *hit);
extern s32 func_800005B4(PcVec3f *origin, PcVec3f *pointA, PcVec3f *pointB, PcVec3f *pointC,
                         PcVec3f *edgeA, PcVec3f *edgeB, PcVec3f *edgeC);

extern s32 D_8009A274;
extern s32 D_8009A278;
extern f32 D_800AE8B0;
extern f32 D_800AE8B8[3];
extern f32 D_800AE8C8[3];
extern s32 D_800AE8D8;
extern s32 D_800AE938;
extern s32 D_800AEC7C;

void func_80001E80(f32 *plane, PcVec3f *vertexA, PcVec3f *vertexB, PcVec3f *vertexC, f32 *ray) {
    PcVec3f edgeA;
    PcVec3f edgeB;
    PcVec3f edgeC;
    f32 hit[3];
    s32 inside;
    f32 distance;
    f32 facing;
    s32 flipped;

    flipped = 0;
    facing = ray[3] * plane[0] + ray[4] * plane[1] + ray[5] * plane[2];
    if (facing > 0.0f) {
        if (D_8009A278 == 0) {
            return;
        }
        flipped = 1;
    } else {
        if (D_8009A274 == 0) {
            return;
        }
    }

    distance = func_80001D34(plane, ray, hit);
    if (distance < 0.0f) {
        return;
    }
    if (!(distance < D_800AE8B0)) {
        return;
    }

    edgeA.x = vertexB->x - vertexA->x;
    edgeA.y = vertexB->y - vertexA->y;
    edgeA.z = vertexB->z - vertexA->z;
    edgeB.x = vertexC->x - vertexB->x;
    edgeB.y = vertexC->y - vertexB->y;
    edgeB.z = vertexC->z - vertexB->z;
    edgeC.x = vertexA->x - vertexC->x;
    edgeC.y = vertexA->y - vertexC->y;
    edgeC.z = vertexA->z - vertexC->z;

    inside = func_800005B4((PcVec3f *)hit, vertexA, vertexB, vertexC, &edgeA, &edgeB, &edgeC);
    if (inside != 0) {
        D_800AEC7C = 1;
        D_800AE8B0 = distance;
        D_800AE8B8[0] = hit[0];
        D_800AE8B8[1] = hit[1];
        D_800AE8B8[2] = hit[2];
        D_800AE8D8 = D_800AE938;
        if (flipped != 0) {
            D_800AE8C8[0] = -plane[0];
            D_800AE8C8[1] = -plane[1];
            D_800AE8C8[2] = -plane[2];
        } else {
            D_800AE8C8[0] = plane[0];
            D_800AE8C8[1] = plane[1];
            D_800AE8C8[2] = plane[2];
        }
    }
}
