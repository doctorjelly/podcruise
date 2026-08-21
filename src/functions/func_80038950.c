/* Implements specs/func_80038950.md (display-list preamble builder). */
#include "podcruise/types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u32 words[13];
} RenderConfig;

#define GFX_CMD(pkt, a, b) { Gfx *gp = (Gfx *)(pkt); gp->w0 = (u32)(a); gp->w1 = (u32)(unsigned long)(b); }

extern RenderConfig D_800A3D68;
extern RenderConfig D_80112DE0;
extern s16 D_800A3D44[];
extern s16 D_800A3D4C;
extern s16 D_800A3D50;
extern s16 D_80114470[];
extern u32 D_800A3DB0[];
extern u32 D_800A3DB8[];
extern u32 D_800A4010[];
extern u32 D_800D697C;
extern Gfx *D_80112C90;
extern u32 D_80112DD8;
extern u32 D_80112E14;
extern s32 D_80112E18;
extern s16 D_80112E1C;
extern s16 D_80112E1E;

extern void func_80035BF0(RenderConfig *, s32);

void func_80038950(Gfx **arg0) {
    Gfx *gfx;
    s32 range;
    s32 near;
    s32 hi;
    s32 lo;

    D_80112DD8 = 0x00200405;
    D_80112DE0 = D_800A3D68;
    D_80112E14 = 0;
    D_80112E18 = -1;
    D_80112E1C = 0;
    D_80112E1E = 0;

    gfx = *arg0;
    GFX_CMD(gfx++, 0xD9FFFFFF, 0x00200405u);
    GFX_CMD(gfx++, 0xD9F0FDFF, 0);
    GFX_CMD(gfx++, 0xD7000000, 0);
    GFX_CMD(gfx++, 0xE7000000, 0);
    GFX_CMD(gfx++, 0xDE000000, D_800A4010);
    GFX_CMD(gfx++, 0xE3001801, D_80114470[6]);
    GFX_CMD(gfx++, 0xE3001A01, D_80114470[7]);

    if (!(D_800D697C & 0x40)) {
        near = D_800A3D4C;
        range = D_800A3D50 - near;
        hi = 128000 / range;
        lo = (((-near) << 8) + 128000) / range;
        GFX_CMD(gfx++, 0xDB080000, (hi << 16) | (lo & 0xFFFF));
        GFX_CMD(gfx++, 0xF8000000,
                (((D_800A3D44[0] & 0xFF) << 24) | ((D_800A3D44[1] & 0xFF) << 16) |
                 ((D_800A3D44[2] & 0xFF) << 8) | (D_800A3D44[3] & 0xFF)));
    }

    if (!(D_800D697C & 0x20)) {
        GFX_CMD(gfx++, 0xDB020000, 0x18);
        GFX_CMD(gfx++, 0xDC08060A, D_800A3DB8);
        GFX_CMD(gfx++, 0xDC08090A, D_800A3DB0);
    }

    D_80112C90 = gfx;
    func_80035BF0(&D_800A3D68, 1);
    *arg0 = D_80112C90;
}
