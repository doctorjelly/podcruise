/* Independently written from specs/functions/recovered/func_80016260.md. */
#include "podcruise/types.h"

s32 func_80016260(f32 a[][4], f32 b[][4], s32 *indx) {
    s32 i;
    s32 j;
    s32 k;
    s32 imax;
    f32 big;
    f32 dum;
    f32 sum;
    f32 vv[3];

    for (i = 0; i < 3; i++) {
        big = 0.0f;
        for (j = 0; j < 3; j++) {
            a[i][j] = b[i][j];
            dum = (b[i][j] < 0) ? -b[i][j] : b[i][j];
            if (dum > big) {
                big = dum;
                if (big == 0.0f) {
                    return 0;
                }
                vv[i] = 1.0f / big;
            }
        }
    }
    for (j = 0; j < 3; j++) {
        for (i = 0; i < j; i++) {
            sum = a[i][j];
            for (k = 0; k < i; k++) {
                sum -= a[i][k] * a[k][j];
            }
            a[i][j] = sum;
        }
        big = 0;
        for (i = j; i < 3; i++) {
            sum = a[i][j];
            for (k = 0; k < j; k++) {
                sum -= a[i][k] * a[k][j];
            }
            a[i][j] = sum;
            dum = vv[i] * ((sum < 0) ? -sum : sum);
            if (dum >= big) {
                big = dum;
                imax = i;
            }
        }
        if (j != imax) {
            for (k = 0; k < 3; k++) {
                dum = a[imax][k];
                a[imax][k] = a[j][k];
                a[j][k] = dum;
            }
            vv[imax] = vv[j];
        }
        indx[j] = imax;
        if (a[j][j] == 0.0f) {
            return 0;
        }
        if (j != 2) {
            dum = 1.0f / a[j][j];
            for (i = j + 1; i < 3; i++) { a[i][j] *= dum; }
        }
    }
    return 1;
}
