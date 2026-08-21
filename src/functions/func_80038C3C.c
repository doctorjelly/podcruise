/* Independently written from scratchpad spec specs/func_80038C3C.md. */

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
extern u32 D_800A4090[];
extern Gfx *D_80112C90;
extern s32 D_80112DD8;
extern u32 D_80112E14;
extern s32 D_80112E18;

extern void func_80035BF0(RenderConfig *, s32);

void func_80038C3C(void) {
    D_80112DD8 = 0x00200405;
    D_80112DE0 = D_800A3D68;
    D_80112E14 = 0;
    D_80112E18 = -1;

    GFX_CMD(D_80112C90++, 0xD9FFFFFF, 0x00200405u);
    GFX_CMD(D_80112C90++, 0xD9F0FDFF, 0);
    GFX_CMD(D_80112C90++, 0xD7000000, 0);
    GFX_CMD(D_80112C90++, 0xE7000000, 0);
    GFX_CMD(D_80112C90++, 0xDE000000, D_800A4090);

    func_80035BF0(&D_800A3D68, 1);
}
