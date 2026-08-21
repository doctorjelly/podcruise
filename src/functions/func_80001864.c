/* Recovered per scratchpad specification specs/func_80001864.md. */
#include "podcruise/types.h"

extern s32 D_8009A27C;
extern s16 D_8009A284[];
extern s32 D_8009A288;
extern f32 D_800AE8B0[];
extern f32 D_800AE8B8[];
extern s32 D_800AE8D8;
extern f32 D_800AE8DC;
extern s16 D_800AE934;
extern s32 D_800AE938;
extern f32 D_800AE978[][3];
extern s32 D_800AEC7C;

extern s32 func_800005B4(f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *);
extern void func_80000E94(f32 *, f32 *, f32 *, f32 *, f32 *, f32, f32 *);
extern void func_800819A4(f32 *, f32 *, f32 *);
extern void func_80081A2C(f32 *, f32 *, f32 *, f32 *);

void func_80001864(f32 *plane, f32 *cornerA, f32 *cornerB, f32 *cornerC, f32 *point) {
    f32 edgeA[3];
    f32 edgeB[3];
    f32 edgeC[3];
    f32 offset[3];
    f32 nearest[3];
    f32 best;
    f32 test;
    s32 flipped;

    flipped = 0;
    offset[0] = point[0] - cornerA[0];
    offset[1] = point[1] - cornerA[1];
    offset[2] = point[2] - cornerA[2];
    if (offset[0] * plane[0] + offset[1] * plane[1] + offset[2] * plane[2] < 0.0f) {
        if (D_8009A27C == 0) {
            return;
        }
        flipped = 1;
    }
    func_800819A4(plane, point, nearest);
    best = (point[0] - nearest[0]) * (point[0] - nearest[0]) +
                   (point[1] - nearest[1]) * (point[1] - nearest[1]) +
                   (point[2] - nearest[2]) * (point[2] - nearest[2]);
    if (best <= D_800AE8DC) {
        edgeA[0] = cornerB[0] - cornerA[0];
        edgeA[1] = cornerB[1] - cornerA[1];
        edgeA[2] = cornerB[2] - cornerA[2];
        edgeB[0] = cornerC[0] - cornerB[0];
        edgeB[1] = cornerC[1] - cornerB[1];
        edgeB[2] = cornerC[2] - cornerB[2];
        edgeC[0] = cornerA[0] - cornerC[0];
        edgeC[1] = cornerA[1] - cornerC[1];
        edgeC[2] = cornerA[2] - cornerC[2];
        if (func_800005B4(nearest, cornerA, cornerB, cornerC, edgeA, edgeB, edgeC) == 0) {
            func_80081A2C(nearest, cornerA, cornerB, edgeA);
            func_80081A2C(nearest, cornerB, cornerC, edgeB);
            func_80081A2C(nearest, cornerC, cornerA, edgeC);
            best = (point[0] - edgeA[0]) * (point[0] - edgeA[0]) +
                   (point[1] - edgeA[1]) * (point[1] - edgeA[1]) +
                   (point[2] - edgeA[2]) * (point[2] - edgeA[2]);
            nearest[0] = edgeA[0];
            nearest[1] = edgeA[1];
            nearest[2] = edgeA[2];
            test = (point[0] - edgeB[0]) * (point[0] - edgeB[0]) +
                   (point[1] - edgeB[1]) * (point[1] - edgeB[1]) +
                   (point[2] - edgeB[2]) * (point[2] - edgeB[2]);
            if (test < best) {
                nearest[0] = edgeB[0];
                nearest[1] = edgeB[1];
                nearest[2] = edgeB[2];
                best = test;
            }
            test = (point[0] - edgeC[0]) * (point[0] - edgeC[0]) +
                   (point[1] - edgeC[1]) * (point[1] - edgeC[1]) +
                   (point[2] - edgeC[2]) * (point[2] - edgeC[2]);
            if (test < best) {
                nearest[0] = edgeC[0];
                nearest[1] = edgeC[1];
                nearest[2] = edgeC[2];
                best = test;
            }
        }
        if (D_8009A288 != 0) {
            if (D_8009A284[0] < 0x3F) {
                D_800AE978[D_8009A284[0]][0] = nearest[0];
                D_800AE978[D_8009A284[0]][1] = nearest[1];
                D_800AE978[D_8009A284[0]][2] = nearest[2];
                D_8009A284[0] = D_8009A284[0] + 1;
            }
        }
        if (best <= D_800AE8B0[0]) {
            if (D_800AE934 == 3) {
                if (flipped != 0) {
                    plane[0] = -plane[0];
                    plane[1] = -plane[1];
                    plane[2] = -plane[2];
                    func_80000E94(nearest, cornerA, cornerC, cornerB, point, best, plane);
                } else {
                    func_80000E94(nearest, cornerA, cornerB, cornerC, point, best, plane);
                }
            } else {
                D_800AEC7C = 1;
                D_800AE8B0[0] = best;
                D_800AE8D8 = D_800AE938;
                D_800AE8B8[0] = nearest[0];
                D_800AE8B8[1] = nearest[1];
                D_800AE8B8[2] = nearest[2];
            }
        }
    }
}
