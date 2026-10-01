/* Independently written from specs/functions/recovered/func_80036A1C.md. */
#include "podcruise/types.h"

extern f32 D_80112E60[4][4];

s32 func_80036A1C(f32 *bounds, s32 trackInside) {
    s32 cmp;
    f32 p0[2][3];
    f32 p1[2][3];
    f32 p2[2][3];
    f32 p3[2][3];
    f32 w;
    f32 v;
    s32 i;
    s16 in0;
    s16 in1;
    s16 in2;

    s16 sx;
    s16 sy;
    s16 sz;

    if (bounds[3] < bounds[0] || bounds[4] < bounds[1] || bounds[5] < bounds[2]) {
        return 0;
    }

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

    if (trackInside != 0) {
        in0 = -1;
        in1 = -1;
        in2 = -1;
    } else {
        in0 = 0;
        in1 = 0;
        in2 = 0;
    }
    sx = -2;
    sy = -2;
    sz = -2;


    for (i = 0; i < 8; i++) {

        w = (p3[(i & 4) >> 2][0] + p3[(i & 2) >> 1][1] + p3[i & 1][2]) + D_80112E60[3][3];

        if (in0 != 0 || sx != 0) {
            v = (p0[(i & 4) >> 2][0] + p0[(i & 2) >> 1][1] + p0[i & 1][2]) + D_80112E60[3][0];
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
                } else if (sx == -2) {
                    sx = cmp;
                }
            }
        }

        if (in1 != 0 || sy != 0) {
            v = (p1[(i & 4) >> 2][0] + p1[(i & 2) >> 1][1] + p1[i & 1][2]) + D_80112E60[3][1];
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
                } else if (sy == -2) {
                    sy = cmp;
                }
            }
        }

        if (in2 != 0 || sz != 0) {
            if (0.0f < w) {
                v = (p2[(i & 4) >> 2][0] + p2[(i & 2) >> 1][1] + p2[i & 1][2]) + D_80112E60[3][2];
                if (w < v) {
                    cmp = 1;
                } else {
                    cmp = 0;
                }
            } else {
                cmp = -1;
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
                } else if (sz == -2) {
                    sz = cmp;
                }
            }
        }
    }

    if (in0 != 0 && in1 != 0 && in2 != 0) {
        return 2;
    }
    if (sx != 0 || sy != 0 || sz != 0) {
        return 0;
    }
    return 1;
}
