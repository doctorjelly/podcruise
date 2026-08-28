/* Independently written from specs/functions/recovered/func_80034650.md. */

#include "podcruise/types.h"

extern s32 D_800D6960[];
/* Stand-in for the neighbouring function's identical literal pair, which in
   the original object precedes this function's own two constants and is what
   places them at their canonical, non-16-aligned address. */
static const f32 poolPadding[2] = {-1e-6f, 1e-6f};

void func_80034650(s16 *destination, f32 source[4][3]) {
    s16 *whole;
    s16 *fraction;
    s16 *high;
    s16 *low;
    s16 row;
    s16 column;
    s32 fixed;
    f32 value;

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
                    } else if (value < 1e-6f) {
                        value = 0;
                    }
                } else {
                    if (value < -32000.0f) {
                        value = -32000.0f;
                    } else if (value > -1e-6f) {
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
