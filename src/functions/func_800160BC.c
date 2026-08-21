/* Specification: specs/func_800160BC.md (worker-authored) */
#include "podcruise/types.h"

void func_800160BC(f32 dst[4][4], f32 src[4][4]) {
    f32 s0;
    f32 s1;
    f32 s2;

    s0 = src[0][0] * src[0][0] + src[0][1] * src[0][1] + src[0][2] * src[0][2];
    s1 = src[1][0] * src[1][0] + src[1][1] * src[1][1] + src[1][2] * src[1][2];
    s2 = src[2][0] * src[2][0] + src[2][1] * src[2][1] + src[2][2] * src[2][2];

    dst[0][0] = src[0][0] / s0;
    dst[0][1] = src[1][0] / s1;
    dst[0][2] = src[2][0] / s2;
    dst[1][0] = src[0][1] / s0;
    dst[1][1] = src[1][1] / s1;
    dst[1][2] = src[2][1] / s2;
    dst[2][0] = src[0][2] / s0;
    dst[2][1] = src[1][2] / s1;
    dst[2][2] = src[2][2] / s2;
    dst[0][3] = 0.0f;
    dst[1][3] = 0.0f;
    dst[2][3] = 0.0f;
    dst[3][3] = 1.0f;

    s0 = src[3][0];
    s1 = src[3][1];
    s2 = src[3][2];

    dst[3][0] = -(dst[2][0] * s2 + (s0 * dst[0][0] + s1 * dst[1][0]));
    dst[3][1] = -(dst[2][1] * s2 + (s0 * dst[0][1] + s1 * dst[1][1]));
    dst[3][2] = -(dst[2][2] * s2 + (s0 * dst[0][2] + s1 * dst[1][2]));
}
