/* Independently written from scratchpad spec specs/func_80016A20.md. */

#include "podcruise/types.h"

typedef struct Unk80016A20 {
    char unk_00[0x30];
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
} Unk80016A20;

typedef struct Work80016A20 {
    char unk_00[0x14];
} Work80016A20;

extern s32 func_80016260(f32 (*matrix)[4], Unk80016A20 *source, Work80016A20 *work);
extern void func_800167E4(f32 (*matrix)[4], Work80016A20 *work, f32 *vector);

void func_80016A20(f32 (*out)[4], Unk80016A20 *source) {
    Work80016A20 work;
    f32 vector[3];
    f32 basis[4][4];
    s32 row;
    s32 column;
    f32 tx;
    f32 ty;
    f32 tz;

    if (func_80016260(out, source, &work)) {
        for (column = 0; column < 3; column++) {
            for (row = 0; row < 3; row++) {
                vector[row] = 0.0f;
            }
            vector[column] = 1.0f;
            func_800167E4(out, &work, vector);
            for (row = 0; row < 3; row++) {
                basis[row][column] = vector[row];
            }
        }
        out[0][0] = basis[0][0];
        out[0][1] = basis[0][1];
        out[0][2] = basis[0][2];
        out[1][0] = basis[1][0];
        out[1][1] = basis[1][1];
        out[1][2] = basis[1][2];
        out[2][0] = basis[2][0];
        out[2][1] = basis[2][1];
        out[2][2] = basis[2][2];
        out[0][3] = 0.0f;
        out[1][3] = 0.0f;
        out[2][3] = 0.0f;
        out[3][3] = 1.0f;
        tx = source->unk_30;
        ty = source->unk_34;
        tz = source->unk_38;
        out[3][0] = -(tx * out[0][0] + ty * out[1][0] + out[2][0] * tz);
        out[3][1] = -(tx * out[0][1] + ty * out[1][1] + out[2][1] * tz);
        out[3][2] = -(tx * out[0][2] + ty * out[1][2] + out[2][2] * tz);
    }
}
