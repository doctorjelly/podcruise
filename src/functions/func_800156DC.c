/* Independently written from specs/functions/vector_math.md. */

#include "podcruise/types.h"

void func_800156DC(f32 output[4][4], const f32 source[4][4]) {
    s32 row;
    s32 column;

    for (row = 0; row < 4; row++) {
        for (column = 0; column < 4; column++) {
            output[row][column] = source[row][column];
        }
    }
}
