/* Specification: specs/func_80067C70.md */
#include "podcruise/types.h"

extern f32 sqrtf(f32 value);
#if defined(__sgi)
#pragma intrinsic (sqrtf)
#endif

typedef struct {
    u8 unk00[0x20];
    f32 unk20[3][4];
    f32 unk50[3];
    u8 unk5C[0x4];
    s32 unk60;
    s32 unk64;
    u8 unk68[0x1930];
    s32 unk1998;
    u8 unk199C[0x4D0];
    s32 unk1E6C;
} Object;

extern void func_80014CC0(f32 angle, f32 *sine, f32 *cosine);
extern void func_800175E0(f32 *matrix, f32 angle, f32 x, f32 y, f32 z);
extern f32 func_800154D0(f32 *vector);
extern f32 D_800AD4E8;

void func_80067C70(Object *object, f32 *velocity, f32 *angles) {
    f32 tilt[4][4];
    f32 turn[4][4];
    f32 spare[4][4];
    f32 second[4][4];
    f32 first[4][4];
    f32 base[4][4];
    f32 extra[9];
    f32 sine;
    f32 cosine;
    f32 pitchCosine;
    f32 pitchSine;
    f32 length;
    f32 axisY;
    f32 axisX;

    base[0][0] = object->unk20[0][0];
    base[0][1] = object->unk20[0][1];
    base[0][2] = object->unk20[0][2];
    base[1][0] = object->unk20[1][0];
    base[1][1] = object->unk20[1][1];
    base[1][2] = object->unk20[1][2];
    base[2][0] = object->unk20[2][0];
    base[2][1] = object->unk20[2][1];
    base[2][2] = object->unk20[2][2];

    if ((((f32)object->unk1998 - 400.0f) / 600.0f) < 1.0 ||
        (object->unk60 & 0x20) || (object->unk64 & 0x04000000)) {
        axisX = -base[1][0];
        axisY = base[1][1];
        length = sqrtf(axisY * axisY + axisX * axisX);
        if (length < D_800AD4E8) {
            axisX = -base[2][0];
            axisY = base[2][1];
            length = sqrtf(axisY * axisY + axisX * axisX);
        }
        axisY = axisY / length;
        axisX = axisX / length;

        func_800175E0(&turn[0][0], angles[2], base[1][0], base[1][1], base[1][2]);
        func_80014CC0(angles[1], &pitchSine, &pitchCosine);

        tilt[2][2] = pitchCosine;
        tilt[0][0] = axisY * axisY + pitchCosine * (axisX * axisX);
        tilt[1][1] = axisX * axisX + pitchCosine * (axisY * axisY);
        tilt[0][1] = (1.0f - pitchCosine) * (axisY * axisX);
        tilt[1][0] = (1.0f - pitchCosine) * (axisY * axisX);
        tilt[0][2] = -(pitchSine * axisX);
        tilt[2][0] = pitchSine * axisX;
        tilt[1][2] = pitchSine * axisY;
        tilt[2][1] = -(pitchSine * axisY);

        first[0][0] = tilt[0][0] * turn[0][0] + tilt[1][0] * turn[0][1] + turn[0][2] * tilt[2][0];
        first[0][1] = tilt[0][1] * turn[0][0] + tilt[1][1] * turn[0][1] + turn[0][2] * tilt[2][1];
        first[0][2] = tilt[0][2] * turn[0][0] + tilt[1][2] * turn[0][1] + turn[0][2] * tilt[2][2];
        first[1][0] = tilt[0][0] * turn[1][0] + tilt[1][0] * turn[1][1] + turn[1][2] * tilt[2][0];
        first[1][1] = tilt[0][1] * turn[1][0] + tilt[1][1] * turn[1][1] + turn[1][2] * tilt[2][1];
        first[1][2] = tilt[0][2] * turn[1][0] + tilt[1][2] * turn[1][1] + turn[1][2] * tilt[2][2];
        first[2][0] = tilt[0][0] * turn[2][0] + tilt[1][0] * turn[2][1] + turn[2][2] * tilt[2][0];
        first[2][1] = tilt[0][1] * turn[2][0] + tilt[1][1] * turn[2][1] + turn[2][2] * tilt[2][1];
        first[2][2] = tilt[0][2] * turn[2][0] + tilt[1][2] * turn[2][1] + turn[2][2] * tilt[2][2];

        func_80014CC0(angles[0], &sine, &cosine);

        second[0][0] = cosine * first[0][0] - first[0][1] * sine;
        second[0][1] = first[0][1] * cosine + sine * first[0][0];
        second[1][0] = cosine * first[1][0] - first[1][1] * sine;
        second[1][1] = first[1][1] * cosine + sine * first[1][0];
        second[2][0] = cosine * first[2][0] - first[2][1] * sine;
        second[2][1] = first[2][1] * cosine + sine * first[2][0];
        second[0][2] = first[0][2];
        second[1][2] = first[1][2];
        second[2][2] = first[2][2];

        object->unk20[0][0] = second[0][0] * base[0][0] + second[1][0] * base[0][1] + base[0][2] * second[2][0];
        object->unk20[0][1] = second[0][1] * base[0][0] + second[1][1] * base[0][1] + base[0][2] * second[2][1];
        object->unk20[0][2] = second[0][2] * base[0][0] + second[1][2] * base[0][1] + base[0][2] * second[2][2];
        object->unk20[1][0] = second[0][0] * base[1][0] + second[1][0] * base[1][1] + base[1][2] * second[2][0];
        object->unk20[1][1] = second[0][1] * base[1][0] + second[1][1] * base[1][1] + base[1][2] * second[2][1];
        object->unk20[1][2] = second[0][2] * base[1][0] + second[1][2] * base[1][1] + base[1][2] * second[2][2];
        object->unk20[2][0] = second[0][0] * base[2][0] + second[1][0] * base[2][1] + base[2][2] * second[2][0];
        object->unk20[2][1] = second[0][1] * base[2][0] + second[1][1] * base[2][1] + base[2][2] * second[2][1];
        object->unk20[2][2] = second[0][2] * base[2][0] + second[1][2] * base[2][1] + base[2][2] * second[2][2];
    } else {
        func_80014CC0(angles[0], &sine, &cosine);
        object->unk20[0][0] = cosine * base[0][0] - base[0][1] * sine;
        object->unk20[0][1] = base[0][1] * cosine + sine * base[0][0];
        object->unk20[1][0] = cosine * base[1][0] - base[1][1] * sine;
        object->unk20[1][1] = base[1][1] * cosine + sine * base[1][0];
        object->unk20[2][0] = cosine * base[2][0] - base[2][1] * sine;
        object->unk20[2][1] = base[2][1] * cosine + sine * base[2][0];
        object->unk20[0][2] = base[0][2];
        object->unk20[1][2] = base[1][2];
        object->unk20[2][2] = base[2][2];
    }

    object->unk1E6C = object->unk1E6C - 1;
    if (object->unk1E6C < 0) {
        func_800154D0(&object->unk20[0][0]);
        func_800154D0(&object->unk20[1][0]);
        func_800154D0(&object->unk20[2][0]);
        object->unk1E6C = 8;
    }

    object->unk50[0] = velocity[0];
    object->unk50[1] = velocity[1];
    object->unk50[2] = velocity[2];
    (void)spare;
    (void)extra;
}
