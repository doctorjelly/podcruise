/* Independently written from scratchpad spec specs/func_80034650.md. */

#include "podcruise/types.h"

extern f32 D_800AAAD8;
extern f32 D_800AAADC;
extern s32 D_800D6960[];

void func_80034650(s16 *destination, f32 source[4][3]) {
    s16 *whole;
    s16 *fraction;
    s16 *high;
    s16 *low;
    s16 row;
    s16 column;
    s32 fixed;
    f32 value;
    f32 lowerLimit;
    f32 upperLimit;

    lowerLimit = D_800AAAD8;
    upperLimit = D_800AAADC;
    whole = destination;
    fraction = destination + 16;
    high = (s16 *)&fixed;
    low = ((s16 *)&fixed) + 1;

    for (row = 0; row < 4; row++) {
        for (column = 0; column < 4; column++) {
            if (column < 3) {
                value = source[row][column];
                if (column == 0 && (D_800D6960[7] & 0x4000)) {
                    value = -value;
                }
                if (value > 0.0f) {
                    if (value > 32000.0f) {
                        value = 32000.0f;
                    } else if (value < upperLimit) {
                        value = 0;
                    }
                } else {
                    if (value < -32000.0f) {
                        value = -32000.0f;
                    } else if (value > lowerLimit) {
                        value = 0;
                    }
                }
                fixed = (s32)(value * 65536.0f);
            } else if (row < 3) {
                fixed = 0;
            } else {
                fixed = 0x10000;
            }
            *whole++ = *high;
            *fraction++ = *low;
        }
    }
}
