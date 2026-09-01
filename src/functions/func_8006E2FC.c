/* Independently written from specs/functions/recovered/func_8006E2FC.md. */

#include "podcruise/types.h"

typedef struct {
    u8 pad00[0x7C];
    f32 unk7C;
    u8 pad80[0x1A0 - 0x80];
    f32 unk1A0;
    u8 pad1A4[0x210 - 0x1A4];
    s32 mode210;
    f32 unk214;
} Object8006E2FC;

void func_8006E2FC(u8 *arg0, u8 *colorA, u8 *colorB, f32 *factor) {
    Object8006E2FC *object;
    s32 mode;

    object = (Object8006E2FC *)arg0;
    colorA[0] = 0;
    colorA[1] = 255;
    colorA[2] = 0;
    colorB[0] = 255;
    colorB[1] = 255;
    colorB[2] = 255;
    colorB[3] = 100;
    *factor = 0.0f;

    mode = object->mode210;
    switch (mode) {
    case 0:
        colorA[0] = 0;
        colorA[1] = 255;
        colorA[2] = 0;
        colorB[0] = 255;
        colorB[1] = 255;
        colorB[2] = 255;
        colorB[3] = 100;
        *factor = (f32)((f64)object->unk1A0 / ((f64)object->unk7C * 0.75));
        if (*factor > 1.0f) {
            *factor = 1.0f;
        }
        break;
    case 1:
        colorA[0] = 0;
        colorA[1] = 255;
        colorA[2] = 0;
        colorB[0] = 255;
        colorB[1] = 128;
        colorB[2] = 0;
        colorB[3] = 200;
        *factor = object->unk214 / 1.0f;
        break;
    case 2:
        colorA[0] = 255;
        colorA[1] = 255;
        colorA[2] = 0;
        colorB[0] = 255;
        colorB[1] = 128;
        colorB[2] = 0;
        colorB[3] = 200;
        *factor = 1.0f;
        break;
    }
}
