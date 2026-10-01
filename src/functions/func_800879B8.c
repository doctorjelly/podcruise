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
/* same command through the function-level pointer */
#define GFX_CMD_FN(a, b) { gp = D_801217B0++; gp->w0 = (u32)(a); gp->w1 = (u32)(b); }
#define RECT_W0(lrx, lry) (fill | (((lrx) & 0x3FF) << 14) | (((lry) & 0x3FF) << 2))
#define RECT_W1(ulx, uly) ((((ulx) & 0x3FF) << 14) | (((uly) & 0x3FF) << 2))
#define FILL_RECT(ulx, uly, lrx, lry) GFX_CMD(RECT_W0(lrx, lry), RECT_W1(ulx, uly))
#define FILL_RECT_FN(ulx, uly, lrx, lry) GFX_CMD_FN(RECT_W0(lrx, lry), RECT_W1(ulx, uly))

void func_800879B8(void) {
    u32 i;
    s32 x0;
    s32 y0;
    s32 x1;
    s32 y1;
    f32 sx;
    f32 sy;
    Gfx *gp;
    u32 fill = 0xF6000000;

    GFX_CMD(0xE7000000, 0);
    GFX_CMD(0xE3000A01, 0);
    GFX_CMD(0xE200001C, 0x0F5A4240);

    for (i = 0; i < (u32)D_800A6978; i++) {
        FILL_RECT(D_80148B60[i * 4] - 1, D_80148B60[i * 4 + 1] - 1, D_80148B60[i * 4 + 2] + 1, D_80148B60[i * 4 + 3] + 1);
    }

    sx = (f32)D_80114470 / 320.0f;
    sy = (f32)D_80114472 / 240.0f;
    x0 = (s32)(D_80120E10 * sx);
    x1 = (s32)(D_80120E18 * sx);
    y1 = (s32)(D_80120E1C * sy);
    y0 = (s32)(D_80120E14 * sy);

    FILL_RECT_FN(x0, y1 - 2, x1, y1 + 2);
    FILL_RECT_FN(x0 - 2, y0, x0 + 2, y1);
    FILL_RECT(x1 - 2, y0, x1 + 2, y1);
    FILL_RECT(x0, y0 - 2, x1, y0 + 2);

    GFX_CMD(0xE7000000, 0);
    D_800A6978 = 0;
}
