/* See specs/func_80081BE8.md (worker specification) for behavior. */
#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} PcVec3f;

extern f32 D_800ADCC8;
extern f32 D_800ADCCC;
extern void func_80015538(f32 *output, const PcVec3f *left, const PcVec3f *right);

s32 func_80081BE8(PcVec3f *p0, PcVec3f *p1, PcVec3f *p2, PcVec3f *p3, PcVec3f *u, PcVec3f *v, PcVec3f *w) {
    f32 ea[3];
    f32 eb[3];
    f32 ec[3];
    f32 na[3];
    f32 nb[3];
    f32 nc[3];
    f32 mx;
    f32 my;
    f32 mz;
    s32 idx;

    ea[0] = p1->x - p0->x;
    ea[1] = p1->y - p0->y;
    ea[2] = p1->z - p0->z;
    eb[0] = p2->x - p0->x;
    eb[1] = p2->y - p0->y;
    eb[2] = p2->z - p0->z;
    ec[0] = p3->x - p0->x;
    ec[1] = p3->y - p0->y;
    ec[2] = p3->z - p0->z;
    func_80015538(na, u, v);
    if (na[0] == 0) {
        if (na[1] == 0) {
            if (na[2] == 0) {
                return 0;
            }
        }
    }
    func_80015538(na, (PcVec3f *)ea, u);
    func_80015538(nb, (PcVec3f *)eb, v);
    func_80015538(nc, (PcVec3f *)ec, w);
    mx = (na[0] < 0.0f) ? -na[0] : na[0];
    my = (na[1] < 0.0f) ? -na[1] : na[1];
    mz = (na[2] < 0.0f) ? -na[2] : na[2];
    if (D_800ADCC8 < mx + my + mz) {
        if (mx < my) {
            idx = (my < mz) ? 2 : 1;
        } else {
            idx = (mx < mz) ? 2 : 0;
        }
        if ((f64)na[idx] < 0.0) {
            if (nb[idx] <= 0.0f) {
                if (nc[idx] <= 0.0f) {
                    return 1;
                }
            }
        } else {
            if (0.0f <= nb[idx]) {
                if (0.0f <= nc[idx]) {
                    return 1;
                }
            }
        }
    } else {
        mx = (nb[0] < 0.0f) ? -nb[0] : nb[0];
        my = (nb[1] < 0.0f) ? -nb[1] : nb[1];
        mz = (nb[2] < 0.0f) ? -nb[2] : nb[2];
        if (mx + my + mz < D_800ADCCC) {
            return 1;
        }
        if (mx < my) {
            idx = (my < mz) ? 2 : 1;
        } else {
            idx = (mx < mz) ? 2 : 0;
        }
        if ((f64)nb[idx] < 0.0) {
            if (nc[idx] <= 0.0f) {
                return 1;
            }
        } else {
            if (0.0f <= nc[idx]) {
                return 1;
            }
        }
    }
    return 0;
}
