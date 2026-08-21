/* Independently written from the specification for the plane-offset point projection. */

#include "podcruise/types.h"

void func_800819A4(f32 *plane, f32 *point, f32 *result) {
    f32 dot;
    f32 offset;

    dot = point[0] * plane[0] + point[1] * plane[1] + point[2] * plane[2];
    offset = plane[3] - dot;
    result[0] = plane[0] * offset;
    result[1] = plane[1] * offset;
    result[2] = plane[2] * offset;
    result[0] = point[0] + result[0];
    result[1] = point[1] + result[1];
    result[2] = point[2] + result[2];
}
