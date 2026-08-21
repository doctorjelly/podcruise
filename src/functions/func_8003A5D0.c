/* Independently written from specs/functions/func_8003A5D0.md. */

#include "podcruise/types.h"

typedef struct SplineObject {
    s16 unk00;
    s16 unk02;
    s32 unk04;
    s32 unk08;
    void *unk0C;
} SplineObject;

extern void func_80016DD8(f32 *output, const f32 *vector, const f32 matrix[4][4]);

extern f32 D_800A4750[4][4];
extern f32 D_800A4790[4][4];
extern f32 D_800A47D0[4][4];
extern f32 D_800A4810[4][4];
extern f32 D_800A4850[4][4];
extern f32 D_800A4890[4][4];

void func_8003A5D0(SplineObject *object, s32 flags, f32 t, s32 *indices,
                   f32 output[4][3]) {
    f32 powers[4];
    f32 basis[4];
    f32 *p0;
    f32 *p1;
    f32 *p2;
    f32 *p3;
    u8 *nodes;

    powers[3] = 1.0f;
    powers[2] = powers[3] * t;
    powers[1] = powers[2] * t;
    powers[0] = powers[1] * t;

    if (object->unk00 == 0) {
        func_80016DD8(basis, powers, D_800A4750);
        nodes = (u8 *)object->unk0C;
        p0 = (f32 *)(indices[0] * 0x54 + nodes + 0x10);
        p1 = (f32 *)(indices[1] * 0x54 + nodes + 0x10);
        p2 = (f32 *)(indices[2] * 0x54 + nodes + 0x10);
        p3 = (f32 *)(indices[3] * 0x54 + nodes + 0x10);
    } else {
        func_80016DD8(basis, powers, D_800A4810);
        nodes = (u8 *)object->unk0C;
        p0 = (f32 *)(indices[0] * 0x54 + nodes + 0x10);
        p1 = (f32 *)(indices[0] * 0x54 + nodes + 0x34);
        p2 = (f32 *)(indices[1] * 0x54 + nodes + 0x28);
        p3 = (f32 *)(indices[1] * 0x54 + nodes + 0x10);
    }

    if (flags & 1) {
        output[0][0] = p0[0] * basis[0] + p1[0] * basis[1] + p2[0] * basis[2] + p3[0] * basis[3];
        output[0][1] = p0[1] * basis[0] + p1[1] * basis[1] + p2[1] * basis[2] + p3[1] * basis[3];
        output[0][2] = p0[2] * basis[0] + p1[2] * basis[1] + p2[2] * basis[2] + p3[2] * basis[3];
    }

    if (flags & 8) {
        if (object->unk00 == 1) {
            output[3][0] = 0.0f;
            output[3][1] = 0.0f;
            output[3][2] = 1.0f;
        } else {
            f32 *q0;
            f32 *q1;
            f32 *q2;
            f32 *q3;

            nodes = (u8 *)object->unk0C;
            q0 = (f32 *)(indices[0] * 0x54 + nodes + 0x1C);
            q1 = (f32 *)(indices[1] * 0x54 + nodes + 0x1C);
            q2 = (f32 *)(indices[2] * 0x54 + nodes + 0x1C);
            q3 = (f32 *)(indices[3] * 0x54 + nodes + 0x1C);

            output[3][0] = q0[0] * basis[0] + q1[0] * basis[1] + q2[0] * basis[2] + q3[0] * basis[3];
            output[3][1] = q0[1] * basis[0] + q1[1] * basis[1] + q2[1] * basis[2] + q3[1] * basis[3];
            output[3][2] = q0[2] * basis[0] + q1[2] * basis[1] + q2[2] * basis[2] + q3[2] * basis[3];
        }
    }

    if (flags & 2) {
        if (object->unk00 == 0) {
            func_80016DD8(basis, powers, D_800A4790);
        } else {
            func_80016DD8(basis, powers, D_800A4850);
        }
        output[1][0] = p0[0] * basis[0] + p1[0] * basis[1] + p2[0] * basis[2] + p3[0] * basis[3];
        output[1][1] = p0[1] * basis[0] + p1[1] * basis[1] + p2[1] * basis[2] + p3[1] * basis[3];
        output[1][2] = p0[2] * basis[0] + p1[2] * basis[1] + p2[2] * basis[2] + p3[2] * basis[3];
    }

    if (flags & 4) {
        if (object->unk00 == 0) {
            func_80016DD8(basis, powers, D_800A47D0);
        } else {
            func_80016DD8(basis, powers, D_800A4890);
        }
        output[2][0] = p0[0] * basis[0] + p1[0] * basis[1] + p2[0] * basis[2] + p3[0] * basis[3];
        output[2][1] = p0[1] * basis[0] + p1[1] * basis[1] + p2[1] * basis[2] + p3[1] * basis[3];
        output[2][2] = p0[2] * basis[0] + p1[2] * basis[1] + p2[2] * basis[2] + p3[2] * basis[3];
    }
}
