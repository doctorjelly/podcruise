/* Independently written from specs/func_80017918.md. */

#include "podcruise/types.h"

void func_80017918(f32 dest[4][4], f32 x, f32 y, f32 z, f32 source[4][4]) {
    dest[0][0] = source[0][0] * x;
    dest[0][1] = source[0][1] * x;
    dest[0][2] = source[0][2] * x;
    dest[0][3] = source[0][3] * x;
    dest[1][0] = source[1][0] * y;
    dest[1][1] = source[1][1] * y;
    dest[1][2] = source[1][2] * y;
    dest[1][3] = source[1][3] * y;
    dest[2][0] = source[2][0] * z;
    dest[2][1] = source[2][1] * z;
    dest[2][2] = source[2][2] * z;
    dest[2][3] = source[2][3] * z;
    dest[3][0] = source[3][0];
    dest[3][1] = source[3][1];
    dest[3][2] = source[3][2];
    dest[3][3] = source[3][3];
}
