/* Independently written from specs/functions/matrix_to_fixed.md. */

#include "podcruise/types.h"

extern s32 D_800D6960[];

void func_800344F4(s16 *dst, f32 src[4][4]) {
    s16 i;
    s16 j;
    s16 *whole;
    s16 *fraction;
    s16 *high;
    s16 *low;
    s32 fixed;
    f32 value;

    whole = dst;
    fraction = dst + 16;
    high = (s16 *) &fixed;
    low = ((s16 *) &fixed) + 1;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            value = src[i][j];
            if (j == 0 && (D_800D6960[7] & 0x4000)) {
                value = -value;
            }
            if (value > 0) {
                if (value > 32000.0f) {
                    value = 32000.0f;
                } else if (value < 0.000001f) {
                    value = 0.0f;
                }
            } else {
                if (value < -32000.0f) {
                    value = -32000.0f;
                } else if (value > -0.000001f) {
                    value = 0.0f;
                }
            }
            fixed = value * 65536.0f;
            *whole++ = *high;
            *fraction++ = *low;
        }
    }
}
