/* Independently written from specs/functions/func_8008681C.md. */

#include "podcruise/types.h"

void func_8008681C(f32 dst[4][4], f32 src[4][4]) {
    dst[0][0] = src[0][0];
    dst[1][0] = src[0][1];
    dst[2][0] = src[0][2];
    dst[0][2] = -src[1][0];
    dst[1][2] = -src[1][1];
    dst[2][2] = -src[1][2];
    dst[0][1] = src[2][0];
    dst[1][1] = src[2][1];
    dst[2][1] = src[2][2];
    dst[3][0] = -(src[3][0] * dst[0][0] + src[3][1] * dst[1][0] + src[3][2] * dst[2][0]);
    dst[3][1] = -(src[3][0] * dst[0][1] + src[3][1] * dst[1][1] + src[3][2] * dst[2][1]);
    dst[3][2] = -(src[3][0] * dst[0][2] + src[3][1] * dst[1][2] + src[3][2] * dst[2][2]);
    dst[0][3] = src[0][3];
    dst[1][3] = src[1][3];
    dst[2][3] = src[2][3];
    dst[3][3] = src[3][3];
}
