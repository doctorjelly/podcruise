/* Independently written from specs/functions/recovered/func_80036A1C.md. */
#include "podcruise/types.h"

extern f32 D_80112E60[4][4];

s32 func_80036A1C(f32 *bounds, s32 trackInside) {
    f32 p0[2][3];
    f32 p1[2][3];
    f32 p2[2][3];
    f32 p3[2][3];
    f32 w;
    f32 v;
    s32 i;
    s32 cmp;
    s32 in0;
    s32 in1;
    s32 in2;
        s16 unset;

    s16 sx;
    s16 sy;
    s16 sz;
    s32 ia;
    s32 ib;
    s32 ic;

    if (bounds[3] < bounds[0] || bounds[4] < bounds[1] || bounds[5] < bounds[2]) {
        return 0;
    }

    in0 = 0;
    in1 = 0;
    in2 = 0;
    if (trackInside != 0) {
        in0 = -1;
        in1 = -1;
        in2 = -1;
    }
    unset = -2;
    sx = unset;
    sy = unset;
    sz = unset;


    p0[0][0] = bounds[0] * D_80112E60[0][0];
    p0[1][0] = bounds[3] * D_80112E60[0][0];
    p0[0][1] = bounds[1] * D_80112E60[1][0];
    p0[1][1] = bounds[4] * D_80112E60[1][0];
    p0[0][2] = bounds[2] * D_80112E60[2][0];
    p0[1][2] = bounds[5] * D_80112E60[2][0];

    p1[0][0] = bounds[0] * D_80112E60[0][1];
    p1[1][0] = bounds[3] * D_80112E60[0][1];
    p1[0][1] = bounds[1] * D_80112E60[1][1];
    p1[1][1] = bounds[4] * D_80112E60[1][1];
    p1[0][2] = bounds[2] * D_80112E60[2][1];
    p1[1][2] = bounds[5] * D_80112E60[2][1];

    p2[0][0] = bounds[0] * D_80112E60[0][2];
    p2[1][0] = bounds[3] * D_80112E60[0][2];
    p2[0][1] = bounds[1] * D_80112E60[1][2];
    p2[1][1] = bounds[4] * D_80112E60[1][2];
    p2[0][2] = bounds[2] * D_80112E60[2][2];
    p2[1][2] = bounds[5] * D_80112E60[2][2];

    p3[0][0] = bounds[0] * D_80112E60[0][3];
    p3[1][0] = bounds[3] * D_80112E60[0][3];
    p3[0][1] = bounds[1] * D_80112E60[1][3];
    p3[1][1] = bounds[4] * D_80112E60[1][3];
    p3[0][2] = bounds[2] * D_80112E60[2][3];
    p3[1][2] = bounds[5] * D_80112E60[2][3];



    for (i = 0; i < 8; i++) {
        ia = (i & 4) >> 2;
        ib = (i & 2) >> 1;
        ic = i & 1;

        w = D_80112E60[3][3] + (p3[ia][0] + p3[ib][1] + p3[ic][2]);

        if (in0 != 0 || sx != 0) {
            v = D_80112E60[3][0] + (p0[ia][0] + p0[ib][1] + p0[ic][2]);
            if (0.0f < w) {
                if (w < v) {
                    cmp = 1;
                } else if (v < -w) {
                    cmp = -1;
                } else {
                    cmp = 0;
                }
            } else {
                if (-w < v) {
                    cmp = 1;
                } else if (v < w) {
                    cmp = -1;
                } else {
                    cmp = 0;
                }
            }
            if (cmp == 0) {
                sx = 0;
                if (in0 != 0) {
                    in0 = 1;
                }
            } else {
                in0 = 0;
                if (sx == -cmp) {
                    sx = 0;
                } else if (sx == unset) {
                    sx = cmp;
                }
            }
        }

        if (in1 != 0 || sy != 0) {
            v = D_80112E60[3][1] + (p1[ia][0] + p1[ib][1] + p1[ic][2]);
            if (0.0f < w) {
                if (w < v) {
                    cmp = 1;
                } else if (v < -w) {
                    cmp = -1;
                } else {
                    cmp = 0;
                }
            } else {
                if (-w < v) {
                    cmp = 1;
                } else if (v < w) {
                    cmp = -1;
                } else {
                    cmp = 0;
                }
            }
            if (cmp == 0) {
                sy = 0;
                if (in1 != 0) {
                    in1 = 1;
                }
            } else {
                in1 = 0;
                if (sy == -cmp) {
                    sy = 0;
                } else if (sy == unset) {
                    sy = cmp;
                }
            }
        }

        if (in2 != 0 || sz != 0) {
            cmp = -1;
            if (0.0f < w) {
                v = D_80112E60[3][2] + (p2[ia][0] + p2[ib][1] + p2[ic][2]);
                if (w < v) {
                    cmp = 1;
                } else {
                    cmp = 0;
                }
            }
            if (cmp == 0) {
                sz = 0;
                if (in2 != 0) {
                    in2 = 1;
                }
            } else {
                in2 = 0;
                if (sz == -cmp) {
                    sz = 0;
                } else if (sz == unset) {
                    sz = cmp;
                }
            }
        }
    }

    if (in0 != 0 && in1 != 0 && in2 != 0) {
        return 2;
    }
    if (sx == 0 && sy == 0 && sz == 0) {
        return 1;
    }
    return 0;
}
