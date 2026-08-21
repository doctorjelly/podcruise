/* See specs/func_800857B0.md (worker specification): screen fill-rectangle emitter. */
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
    Gfx800857B0 *gfx;
    Gfx800857B0 *image;
    Rect800857B0 *rect;
    f64 scaleX;
    f64 scaleY;
    s32 x0;
    s32 y0;
    s32 x1;
    s32 y1;
    s32 size;
    u32 fill;
    s32 r;
    s32 g;
    s32 b;

    rect = &D_80120DF0[index];
    x1 = rect->unk28;
    y1 = rect->unk2C;
    scaleX = (f64)D_80114470[0] / 320.0;
    scaleY = (f64)D_80114470[1] / 240.0;
    x0 = rect->unk20 * scaleX;
    y0 = rect->unk24 * scaleY;
    x1 = x1 * scaleX;
    y1 = y1 * scaleY;

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
        r = (s16)(red + 4);
        if (r >= 0x100) {
            r = 0xFF;
        }
        g = (s16)(green + 4);
        if (g >= 0x100) {
            g = 0xFF;
        }
        b = (s16)(blue + 4);
        if (b >= 0x100) {
            b = 0xFF;
        }
        fill = (((b >> 2) & 0x3E) | ((r << 8) & 0xF800)) | ((g << 3) & 0x7C0) | 1;
        fill = fill | (fill << 16);
    } else {
        fill = 0xFF;
    }

    EMIT(0xF7000000, fill);
    EMIT(0xF6000000 | (((x1 - 1) & 0x3FF) << 14) | (((y1 - 1) & 0x3FF) << 2), ((x0 & 0x3FF) << 14) | ((y0 & 0x3FF) << 2));
    EMIT(0xE7000000, 0);
    EMIT(0xE3000A01, 0);
    EMIT(0xE7000000, 0);
}
