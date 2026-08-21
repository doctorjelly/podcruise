/* Specification: scratchpad specs/func_80084EB8.md */
#include "podcruise/types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx80084EB8;

typedef struct {
    s32 unk00[8];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30[80];
} Rect80084EB8;

extern Rect80084EB8 D_80120DF0[];
extern s16 D_80114470[];
extern Gfx80084EB8 *D_801217B0;
extern void *D_800D9DB4;
extern void *D_80114528;
extern s32 D_800A4740;
extern s16 D_801488B8[];
extern s16 D_801488BE;
extern u32 func_80088360(void *);
extern void func_800390AC(void);

#define EMIT(a, b) { gfx = D_801217B0; D_801217B0 = gfx + 1; gfx->w0 = (a); gfx->w1 = (b); }

void func_80084EB8(s32 arg0) {
    Gfx80084EB8 *gfx;
    Gfx80084EB8 *image;
    Rect80084EB8 *rect;
    f64 scaleX;
    f64 scaleY;
    s32 x0;
    s32 y0;
    s32 x1;
    s32 y1;
    s32 size;
    u32 fill;
    s16 *source;
    s16 *dest;
    s16 colors[3];

    rect = &D_80120DF0[0];
    scaleX = (f64) D_80114470[0] / 320.0;
    x0 = rect->unk20 * scaleX;
    scaleY = (f64) D_80114470[1] / 240.0;
    y0 = rect->unk24 * scaleY;
    x1 = rect->unk28 * scaleX;
    y1 = rect->unk2C * scaleY;

    if (D_800A4740 != 0) {
        EMIT(0xE7000000, 0);
        EMIT(0xE3000A01, 0x00300000);
        image = D_801217B0; D_801217B0 = image + 1;
        image->w0 = 0xFF100000 | ((D_80114470[0] - 1) & 0xFFF);
        image->w1 = func_80088360(D_80114528);
        EMIT(0xF7000000, 0xFFFCFFFC);
        EMIT(0xF6000000 | (((x1 - 1) & 0x3FF) << 14) | (((y1 - 1) & 0x3FF) << 2),
             ((x0 & 0x3FF) << 14) | ((y0 & 0x3FF) << 2));
    }

    EMIT(0xE7000000, 0);
    image = D_801217B0; D_801217B0 = image + 1;
    if (D_80114470[2] == 0x20) {
        size = 3;
    } else {
        size = 2;
    }
    image->w0 = 0xFF000000 | ((size & 3) << 19) | ((D_80114470[0] - 1) & 0xFFF);
    image->w1 = func_80088360(D_800D9DB4);

    if (arg0 == 0) {
        if (D_80114470[2] == 0x10) {
            source = D_801488B8;
            dest = colors;
            do {
                *dest = *source + 4;
                source++;
                if (!(*dest < 0x100)) {
                    *dest = 0xFF;
                }
                dest++;
            } while (source != &D_801488BE);
            fill = (((colors[2] >> 2) & 0x3E) | ((colors[0] << 8) & 0xF800)) |
                   ((colors[1] << 3) & 0x7C0) | 1;
            fill = fill | (fill << 16);
        } else {
            fill = 0xFF;
        }
        EMIT(0xF7000000, fill);
        EMIT(0xF6000000 | (((x1 - 1) & 0x3FF) << 14) | (((y1 - 1) & 0x3FF) << 2),
             ((x0 & 0x3FF) << 14) | ((y0 & 0x3FF) << 2));
        EMIT(0xE7000000, 0);
    }
    EMIT(0xE3000A01, 0);
    func_800390AC();
}
