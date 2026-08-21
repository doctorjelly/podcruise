/* Recovered from specification specs/func_8003B860.md (batch 08). */
#include "podcruise/types.h"

typedef struct {
    u32 w0;
    u32 w1;
} PcGfx;

extern u8 D_800A4920[];

#define PC_CMD(a, b) { PcGfx *g_ = gfx++; g_->w0 = (u32)(a); g_->w1 = (u32)(b); }

void func_8003B860(PcGfx **listp, s32 ulx, s32 lrx, s32 uly, s32 lry, s32 x, s32 y,
                   s32 uls, s32 lrs, s32 ult, s32 lrt) {
    PcGfx *gfx;
    s32 vx;
    s32 vy;
    u32 w;

    gfx = *listp;

    PC_CMD(0x01004008, (unsigned long)D_800A4920)
    PC_CMD(0x021C0000, 0)
    PC_CMD(0x021C0002, 0)
    PC_CMD(0x021C0004, 0)
    PC_CMD(0x021C0006, 0)

    if (x < ulx && y < uly) {
        vx = x;
        vy = y;
    } else {
        vx = ulx;
        vy = uly;
    }
    w = ((u32)vx << 16) | ((u32)vy & 0xFFFF);
    PC_CMD(0x02180000, w)

    if (x >= ulx && y < uly) {
        vx = x;
        vy = y;
    } else {
        vx = lrx;
        vy = uly;
    }
    w = ((u32)vx << 16) | ((u32)vy & 0xFFFF);
    PC_CMD(0x02180002, w)

    if (x >= ulx && y >= uly) {
        vx = x;
        vy = y;
    } else {
        vx = lrx;
        vy = lry;
    }
    w = ((u32)vx << 16) | ((u32)vy & 0xFFFF);
    PC_CMD(0x02180004, w)

    if (x < ulx && y >= uly) {
        vx = x;
        vy = y;
    } else {
        vx = ulx;
        vy = lry;
    }
    w = ((u32)vx << 16) | ((u32)vy & 0xFFFF);
    PC_CMD(0x02180006, w)

    PC_CMD(0x02140000, ((u32)uls << 16) | ((u32)ult & 0xFFFF))
    PC_CMD(0x02140002, ((u32)lrs << 16) | ((u32)ult & 0xFFFF))
    PC_CMD(0x02140004, ((u32)lrs << 16) | ((u32)lrt & 0xFFFF))
    PC_CMD(0x02140006, ((u32)uls << 16) | ((u32)lrt & 0xFFFF))
    PC_CMD(0x06000402, 0x604)

    *listp = gfx;
}
