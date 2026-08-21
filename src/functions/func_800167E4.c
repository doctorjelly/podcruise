/* Specification: specs/func_800167E4.md (3x3 LU back-substitution solver) */
#include "podcruise/types.h"

void func_800167E4(f32 a[][4], s32 *indx, f32 *b) {
    s32 i;
    s32 j;
    s32 ip;
    s32 ii;
    f32 sum;

    ii = -1;
    for (i = 0; i < 3; i++) {
        ip = indx[i];
        sum = b[ip];
        b[ip] = b[i];
        if (ii >= 0) {
            for (j = ii; j <= i - 1; j++) {
                sum -= a[i][j] * b[j];
            }
        } else if (sum != 0.0f) {
            ii = i;
        }
        b[i] = sum;
    }
    for (i = 2; i >= 0; i--) {
        sum = b[i];
        for (j = i + 1; j < 3; j++) {
            sum -= a[i][j] * b[j];
        }
        b[i] = sum / a[i][i];
    }
}
