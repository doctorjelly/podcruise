/* Recovered per specs/func_80016260.md (batch 06). */
#include "podcruise/types.h"

s32 func_80016260(f32 a[][4], f32 b[][4], s32 *indx) {
    f32 vv[3];
    f32 big;
    f32 dum;
    f32 sum;
    f32 temp;
    s32 i;
    s32 imax;
    s32 j;
    s32 k;

    for (i = 0; i < 3; i++) {
        big = 0.0;
        for (j = 0; j < 3; j++) {
            a[i][j] = b[i][j];
            temp = (b[i][j] < 0.0) ? -b[i][j] : b[i][j];
            if (temp > big) {
                big = temp;
                if (big == 0.0) {
                    return 0;
                }
                vv[i] = 1.0 / big;
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
        big = 0.0;
        for (i = j; i < 3; i++) {
            sum = a[i][j];
            for (k = 0; k < j; k++) {
                sum -= a[i][k] * a[k][j];
            }
            a[i][j] = sum;
            temp = (sum < 0.0) ? -sum : sum;
            dum = temp * vv[i];
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
        if (a[j][j] == 0.0) {
            return 0;
        }
        if (j != 2) {
            dum = 1.0 / a[j][j];
            for (i = j + 1; i < 3; i++) {
                a[i][j] *= dum;
            }
        }
    }
    return 1;
}
