/* Recovered from specification specs/func_80083EFC.md (batch 08). */
#include "podcruise/types.h"

extern void func_80016CAC(f32 *destination, f32 *source, f32 (*transform)[4]);
extern void func_80016BF4(f32 *output, f32 *vector, f32 (*transform)[4]);
extern void func_80016A20(f32 (*out)[4], void *source);
extern f32 func_80081FB0(void *arg0, f32 *pointA, f32 *pointB, f32 *pointC, f32 limit,
                         f32 *hit, f32 *normal);

extern s32 D_800A6898;
extern f32 D_80120D80[3];
extern f32 D_80120D90[3];
extern s32 *D_80120D9C;
extern s32 D_80120DA0[];

void func_80083EFC(s16 *pointA, s16 *pointB, s16 *pointC, void *object, f32 *best,
                   void *arg5, f32 *hitOut, f32 *normalOut) {
    f32 sourceA[3];
    f32 sourceB[3];
    f32 sourceC[3];
    f32 worldA[3];
    f32 worldB[3];
    f32 worldC[3];
    f32 distance;
    f32 hit[3];
    f32 normal[3];
    s32 index;
    f32 matrix[4][4];

    sourceA[0] = pointA[0];
    sourceA[1] = pointA[1];
    sourceA[2] = pointA[2];
    sourceB[0] = pointB[0];
    sourceB[1] = pointB[1];
    sourceB[2] = pointB[2];
    sourceC[0] = pointC[0];
    sourceC[1] = pointC[1];
    sourceC[2] = pointC[2];

    func_80016CAC(worldA, sourceA, object);
    func_80016CAC(worldB, sourceB, object);
    func_80016CAC(worldC, sourceC, object);

    distance = func_80081FB0(arg5, worldA, worldB, worldC, *best, hit, normal);

    if (distance >= 0.0f && distance < *best) {
        hitOut[0] = hit[0];
        hitOut[1] = hit[1];
        hitOut[2] = hit[2];
        normalOut[0] = normal[0];
        normalOut[1] = normal[1];
        normalOut[2] = normal[2];
        *best = distance;

        if (D_800A6898 >= 0) {
            for (index = 0; index < D_800A6898; index++) {
                D_80120D9C[index] = D_80120DA0[index];
            }
            D_80120D9C[D_800A6898] = 0;
            func_80016A20(matrix, object);
            func_80016CAC(D_80120D80, hit, matrix);
            func_80016BF4(D_80120D90, normal, matrix);
        }
    }
}
