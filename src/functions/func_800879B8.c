/* Implements specs/func_800879B8.md (debug rectangle overlay). */
#include "podcruise/types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

extern Gfx *D_801217B0;
extern s16 D_800A6978;
extern s16 D_80148B60[];
extern s16 D_80114470;
extern s16 D_80114472;
extern s32 D_80120E10;
extern s32 D_80120E14;
extern s32 D_80120E18;
extern s32 D_80120E1C;

#define GFX_CMD(a, b) { Gfx *gp = D_801217B0++; gp->w0 = (u32)(a); gp->w1 = (u32)(b); }
#define FILL_RECT(ulx, uly, lrx, lry) GFX_CMD(0xF6000000 | (((lrx) & 0x3FF) << 14) | (((lry) & 0x3FF) << 2), (((ulx) & 0x3FF) << 14) | (((uly) & 0x3FF) << 2))

void func_800879B8(void) {
    u32 i;
    s16 *rect;
    s32 x0;
    s32 y0;
    s32 x1;
    s32 y1;
    f32 sx;
    f32 sy;

    GFX_CMD(0xE7000000, 0);
    GFX_CMD(0xE3000A01, 0);
    GFX_CMD(0xE200001C, 0x0F5A4240);

    rect = D_80148B60;
    for (i = 0; i < (u32)D_800A6978; i++) {
        FILL_RECT(rect[0] - 1, rect[1] - 1, rect[2] + 1, rect[3] + 1);
        rect += 4;
    }

    sx = (f32)D_80114470 / 320.0f;
    sy = (f32)D_80114472 / 240.0f;
    x0 = (s32)(D_80120E10 * sx);
    y0 = (s32)(D_80120E14 * sy);
    x1 = (s32)(D_80120E18 * sx);
    y1 = (s32)(D_80120E1C * sy);

    FILL_RECT(x0, y1 - 2, x1, y1 + 2);
    FILL_RECT(x0 - 2, y0, x0 + 2, y1);
    FILL_RECT(x1 - 2, y0, x1 + 2, y1);
    FILL_RECT(x0, y0 - 2, x1, y0 + 2);

    GFX_CMD(0xE7000000, 0);
    D_800A6978 = 0;
}
