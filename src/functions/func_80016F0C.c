/* Specification: scratchpad specs/func_80016F0C.md */
#include "podcruise/types.h"

extern f64 D_800A87F8;
extern f64 D_800A8800;
extern f64 D_800A8808;

extern f32 func_80014F2C(f32 value);
extern f32 func_800153C0(f32 *vector);

void func_80016F0C(f32 matrix[4][4], f32 *output) {
    f32 rowY[3];
    f32 rowZ[3];
    f32 negRowX[3];
    f32 planar[3];
    f32 perpendicular[3];
    f32 length;
    f32 span;
    f32 value;
    f64 unreferencedPad;

    output[0] = matrix[3][0];
    output[1] = matrix[3][1];
    output[2] = matrix[3][2];

    rowY[0] = matrix[1][0];
    rowY[1] = matrix[1][1];
    rowY[2] = matrix[1][2];

    rowZ[0] = matrix[2][0];
    rowZ[1] = matrix[2][1];
    rowZ[2] = matrix[2][2];

    negRowX[0] = -matrix[0][0];
    negRowX[1] = -matrix[0][1];
    negRowX[2] = -matrix[0][2];

    planar[0] = rowY[0];
    planar[1] = rowY[1];
    planar[2] = 0.0f;

    length = func_800153C0(planar);
    (void)unreferencedPad;
    (void)rowZ;
    if (length < D_800A87F8) {
        value = func_80014F2C(-negRowX[0]);
        if ((0.0f < negRowX[1]) == (0.0f < rowY[2])) {
            value = -value;
        }
        output[5] = value;
        output[3] = 0.0f;
    } else {
        if (1.0f < planar[1] / length) {
            value = 0.0f;
        } else {
            value = func_80014F2C(planar[1] / length);
            if (0.0f < rowY[0]) {
                value = -value;
            }
        }
        output[3] = value;
    }

    if (length < D_800A8800) {
        output[4] = 90.0f;
    } else {
        value = (planar[0] * rowY[0] + planar[1] * rowY[1] + planar[2] * rowY[2]) / length;
        if (1.0f <= value) {
            output[4] = 0.0f;
        } else {
            output[4] = func_80014F2C(value);
        }
    }
    if (rowY[2] < 0.0f) {
        output[4] = -output[4];
    }

    perpendicular[0] = -planar[1];
    perpendicular[1] = planar[0];
    perpendicular[2] = 0.0f;
    span = func_800153C0(perpendicular);
    if (length >= D_800A8808) {
        value = (perpendicular[0] * negRowX[0] + perpendicular[1] * negRowX[1] + perpendicular[2] * negRowX[2]) / span;
        if (1.0f <= value) {
            output[5] = 0.0f;
        } else if (value <= -1.0f) {
            output[5] = 180.0f;
        } else {
            output[5] = func_80014F2C(value);
        }
        if (negRowX[2] < 0.0f) {
            output[5] = -output[5];
        }
    }
}
