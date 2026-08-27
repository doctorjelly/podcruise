/* Recovered per specification specs/func_80084EB8.md (framebuffer image setup and screen clear). */
#include "podcruise/types.h"

extern u32 *D_801217B0;
extern s16 D_80114470[];
extern s32 D_80114528;
extern s32 D_800D9DB4;
extern s32 D_80120DF0[];
extern s32 D_800A4740;
extern s16 D_801488B8[];

extern s32 func_80088360(s32);
extern void func_800390AC(void);

#define GFX(w0, w1) { u32 *g = D_801217B0; D_801217B0 = g + 2; g[0] = (u32)(w0); g[1] = (u32)(w1); }

void func_80084EB8(s32 arg0) {
    s16 rgb[8];
    s32 x0;
    s32 y0;
    s32 x1;
    s32 y1;
    s32 siz;
    s32 color;
    s32 i;
    f64 sx;
    f64 sy;

    sx = (f64)D_80114470[0] / 320.0;
    x0 = D_80120DF0[8] * sx;
    sy = (f64)D_80114470[1] / 240.0;
    y0 = D_80120DF0[9] * sy;
    x1 = D_80120DF0[10] * sx;
    y1 = D_80120DF0[11] * sy;

    if (D_800A4740 != 0) {
        GFX(0xE7000000, 0)
        GFX(0xE3000A01, 0x00300000)
        GFX(0xFF100000 | ((D_80114470[0] - 1) & 0xFFF), func_80088360(D_80114528))
        GFX(0xF7000000, 0xFFFCFFFC)
        GFX(0xF6000000 | (((x1 - 1) & 0x3FF) << 14) | (((y1 - 1) & 0x3FF) << 2), ((x0 & 0x3FF) << 14) | ((y0 & 0x3FF) << 2))
    }

    GFX(0xE7000000, 0)
    if (D_80114470[2] == 0x20) {
        siz = 3;
    } else {
        siz = 2;
    }
    GFX(0xFF000000 | ((siz & 3) << 19) | ((D_80114470[0] - 1) & 0xFFF), func_80088360(D_800D9DB4))

    if (arg0 == 0) {
        if (D_80114470[2] == 0x10) {
            for (i = 0; i < 3; i++) {
                rgb[i] = D_801488B8[i] + 4;
                if (rgb[i] >= 0x100) { rgb[i] = 0xFF; }
            }
            color = ((rgb[0] << 8) & 0xF800) | ((rgb[1] << 3) & 0x7C0) | ((rgb[2] >> 2) & 0x3E);
            color = color | 1;
            color = color | (color << 16);
        } else {
            color = 0xFF;
        }
        GFX(0xF7000000, color)
        GFX(0xF6000000 | (((x1 - 1) & 0x3FF) << 14) | (((y1 - 1) & 0x3FF) << 2), ((x0 & 0x3FF) << 14) | ((y0 & 0x3FF) << 2))
        GFX(0xE7000000, 0)
    }

    GFX(0xE3000A01, 0)
    func_800390AC();
}
