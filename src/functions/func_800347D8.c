/* Independently written from $S/specs/func_800347D8.md. */

#include "podcruise/types.h"

void func_800347D8(f32 destination[4][4], f32 source[4][4]) {
    s16 row;
    s16 column;

    for (row = 0; row < 4; row++) {
        for (column = 0; column < 4; column++) {
            destination[row][column] = source[row][column];
        }
    }
}
