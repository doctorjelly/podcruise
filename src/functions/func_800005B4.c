/* Independently written from scratchpad spec specs/func_800005B4.md. */

#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} PcVec3f;

extern void func_80015538(PcVec3f *output, const PcVec3f *left, const PcVec3f *right);
extern f32 D_800A80F0;
extern f32 D_800A80F4;

s32 func_800005B4(PcVec3f *origin, PcVec3f *pointA, PcVec3f *pointB, PcVec3f *pointC,
                  PcVec3f *edgeA, PcVec3f *edgeB, PcVec3f *edgeC) {
    f32 legA[3];
    f32 legB[3];
    f32 legC[3];
    f32 testA[3];
    f32 testB[3];
    f32 testC[3];
    f32 magX;
    f32 magY;
    f32 magZ;
    s32 axis;

    legA[0] = pointA->x - origin->x;
    legA[1] = pointA->y - origin->y;
    legA[2] = pointA->z - origin->z;
    legB[0] = pointB->x - origin->x;
    legB[1] = pointB->y - origin->y;
    legB[2] = pointB->z - origin->z;
    legC[0] = pointC->x - origin->x;
    legC[1] = pointC->y - origin->y;
    legC[2] = pointC->z - origin->z;

    func_80015538((PcVec3f *)testA, edgeA, edgeB);
    if (!testA[0] && !testA[1] && !testA[2]) {
        return 0;
    }

    func_80015538((PcVec3f *)testA, (PcVec3f *)legA, edgeA);
    func_80015538((PcVec3f *)testB, (PcVec3f *)legB, edgeB);
    func_80015538((PcVec3f *)testC, (PcVec3f *)legC, edgeC);

    magX = testA[0] < 0.0f ? -testA[0] : testA[0];
    magY = testA[1] < 0.0f ? -testA[1] : testA[1];
    magZ = testA[2] < 0.0f ? -testA[2] : testA[2];
    if (magX + magY + magZ > D_800A80F0) {
        if (magX < magY) {
            if (magY < magZ) {
                axis = 2;
            } else {
                axis = 1;
            }
        } else {
            axis = magX < magZ ? 2 : 0;
        }
        if (testA[axis] < 0.0) {
            if (testB[axis] <= 0.0f && testC[axis] <= 0.0f) {
                return 1;
            }
        } else if (testB[axis] >= 0.0f && testC[axis] >= 0.0f) {
            return 1;
        }
    } else {
        magX = testB[0] < 0.0f ? -testB[0] : testB[0];
        magY = testB[1] < 0.0f ? -testB[1] : testB[1];
        magZ = testB[2] < 0.0f ? -testB[2] : testB[2];
        if (magX + magY + magZ < D_800A80F4) {
            return 1;
        }
        if (magX < magY) {
            if (magY < magZ) {
                axis = 2;
            } else {
                axis = 1;
            }
        } else {
            axis = magX < magZ ? 2 : 0;
        }
        if (testB[axis] < 0.0) {
            if (testC[axis] <= 0.0f) {
                return 1;
            }
        } else if (testC[axis] >= 0.0f) {
            return 1;
        }
    }
    return 0;
}
