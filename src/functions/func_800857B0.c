/* Implements specs/functions/recovered/remaining_medium_audit_tranche.md. */
#include "podcruise/types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx800857B0;

typedef struct {
    s32 unk00[8];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30[80];
} Rect800857B0;

extern Rect800857B0 D_80120DF0[];
extern s16 D_80114470[];
extern Gfx800857B0 *D_801217B0;
extern void *D_800D9DB4;
extern u32 func_80088360(void *);

#define EMIT(a, b) { gfx = D_801217B0; D_801217B0 = gfx + 1; gfx->w0 = (a); gfx->w1 = (b); }

void func_800857B0(index, red, green, blue)
s32 index;
s16 red;
s16 green;
s16 blue;
{
    f64 scaleX;
    s16 c[3];
    s32 size;
    s32 y0;
    Gfx800857B0 *gfx;
    s32 xy[2];
    s32 x0;
    Gfx800857B0 *image;
    Rect800857B0 *rect;
    u32 fill;
    f64 scaleY;

    rect = &D_80120DF0[index];
    xy[0] = rect->unk2C;
    xy[1] = rect->unk28;
    scaleX = (f64)D_80114470[0] / 320.0;
    scaleY = (f64)D_80114470[1] / 240.0;
    x0 = rect->unk20 * scaleX;
    y0 = rect->unk24 * scaleY;
    xy[1] = xy[1] * scaleX;
    xy[0] = xy[0] * scaleY;

    EMIT(0xE7000000, 0);
    EMIT(0xE3000A01, 0x00300000);
    image = D_801217B0; D_801217B0 = image + 1;

    if (D_80114470[2] == 0x20) {
        size = 3;
    } else {
        size = 2;
    }
    image->w0 = 0xFF000000 | ((size & 3) << 19) | ((D_80114470[0] - 1) & 0xFFF);
    image->w1 = func_80088360(D_800D9DB4);

    if (D_80114470[2] == 0x10) {
        c[0] = red + 4;
        if (c[0] >= 0x100) {
            c[0] = 0xFF;
        }
        c[1] = green + 4;
        if (c[1] >= 0x100) {
            c[1] = 0xFF;
        }
        c[2] = blue + 4;
        if (c[2] >= 0x100) {
            c[2] = 0xFF;
        }
        fill = (((c[2] >> 2) & 0x3E) | ((c[0] << 8) & 0xF800)) | ((c[1] << 3) & 0x7C0) | 1;
        fill = fill | (fill << 16);
    } else {
        fill = 0xFF;
    }

    EMIT(0xF7000000, fill);
    EMIT(0xF6000000 | (((xy[1] - 1) & 0x3FF) << 14) | (((xy[0] - 1) & 0x3FF) << 2), ((x0 & 0x3FF) << 14) | ((y0 & 0x3FF) << 2));
    EMIT(0xE7000000, 0);
    EMIT(0xE3000A01, 0);
    EMIT(0xE7000000, 0);
}
