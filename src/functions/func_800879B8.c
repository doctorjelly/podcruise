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
#define FILL_RECT(ulx, uly, lrx, lry) GFX_CMD(fill | (((lrx) & 0x3FF) << 14) | (((lry) & 0x3FF) << 2), (((ulx) & 0x3FF) << 14) | (((uly) & 0x3FF) << 2))

void func_800879B8(void) {
    u32 i;
    s16 *rect;
    s32 x0;
    s32 y0;
    s32 x1;
    s32 y1;
    f32 sx;
    f32 sy;
    u32 fill = 0xF6000000;

    GFX_CMD(0xE7000000, 0);
    GFX_CMD(0xE3000A01, 0);
    GFX_CMD(0xE200001C, 0x0F5A4240);

    rect = D_80148B60;
    for (i = 0; i < (u32)D_800A6978; i++) {
        s16 *r = rect;
        rect += 4;
        FILL_RECT(r[0] - 1, r[1] - 1, r[2] + 1, r[3] + 1);
    }

    sx = (f32)D_80114470 / 320.0f;
    sy = (f32)D_80114472 / 240.0f;
    x0 = (s32)(D_80120E10 * sx);
    x1 = (s32)(D_80120E18 * sx);
    y1 = (s32)(D_80120E1C * sy);
    y0 = (s32)(D_80120E14 * sy);

    FILL_RECT(x0, y1 - 2, x1, y1 + 2);
    FILL_RECT(x0 - 2, y0, x0 + 2, y1);
    FILL_RECT(x1 - 2, y0, x1 + 2, y1);
    FILL_RECT(x0, y0 - 2, x1, y0 + 2);

    GFX_CMD(0xE7000000, 0);
    D_800A6978 = 0;
}
