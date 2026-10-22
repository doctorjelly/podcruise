/* Independently written from specs/functions/recovered/medium_control_math_tranche.md. */
#include "podcruise/types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Cmd8008528C;

typedef struct {
    s16 unk00;
    s16 unk02;
    s16 unk04;
} Screen8008528C;

typedef struct {
    s32 pad00[8];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
} Frame8008528C;

extern s32 D_800A4740;
extern u32 D_800D9DB4;
extern Screen8008528C D_80114470;
extern u32 D_80114528;
extern Frame8008528C D_80120DF0;
extern Cmd8008528C *D_801217B0;

extern u32 func_80088360(u32);
extern void func_800390AC(void);

#define CMDP(p, a, b) { p = D_801217B0++; p->w0 = (u32)(a); p->w1 = (u32)(b); }
#define CMD(a, b) { Cmd8008528C *_c = D_801217B0++; _c->w0 = (u32)(a); _c->w1 = (u32)(b); }

void func_8008528C(flag0, flag1, flag2, red0, green0, blue0, red1, green1, blue1)
s32 flag0;
s32 flag1;
s32 flag2;
s16 red0;
s16 green0;
s16 blue0;
s16 red1;
s16 green1;
s16 blue1;
{
    f64 scale;
    s16 c[3];
    s32 x0;
    s32 y0;
    s32 x1;
    s32 y1;
    s32 mid;

    scale = (f64)D_80114470.unk00 / 320.0;
    x0 = D_80120DF0.unk20;
    y0 = D_80120DF0.unk24;
    x1 = D_80120DF0.unk28;
    y1 = D_80120DF0.unk2C;
    x0 = (s32)(x0 * scale);
    y0 = (s32)(y0 * ((f64)D_80114470.unk02 / 240.0));
    x1 = (s32)(x1 * scale);
    y1 = (s32)(y1 * ((f64)D_80114470.unk02 / 240.0));

    mid = (y0 + y1) / 2;
    if (D_800A4740 != 0) {
        CMD(0xE7000000, 0)
        CMD(0xE3000A01, 0x00300000)
        CMD(0xFF100000 | ((D_80114470.unk00 - 1) & 0xFFF), func_80088360(D_80114528))
        CMD(0xF7000000, 0xFFFCFFFC)
        CMD(0xF6000000 | (((x1 - 1) & 0x3FF) << 14) | (((y1 - 1) & 0x3FF) << 2),
            ((x0 & 0x3FF) << 14) | ((y0 & 0x3FF) << 2))
    }

    CMD(0xE7000000, 0)
    CMD(0xFF000000 | (((D_80114470.unk04 == 0x20 ? 3 : 2) & 3) << 19) | ((D_80114470.unk00 - 1) & 0xFFF), func_80088360(D_800D9DB4))

    if (flag0 == 0) {
        u32 fill;
        if (flag1 == 0) {
            if (D_80114470.unk04 == 0x10) {
                c[0] = red0 + 4;
                if (c[0] >= 0x100) { c[0] = 0xFF; }
                c[1] = green0 + 4;
                if (c[1] >= 0x100) { c[1] = 0xFF; }
                c[2] = blue0 + 4;
                if (c[2] >= 0x100) { c[2] = 0xFF; }
                fill = (((((c[0] << 8) & 0xF800) | ((c[1] << 3) & 0x7C0) | ((c[2] >> 2) & 0x3E)) | 1) << 16) | ((((c[0] << 8) & 0xF800) | ((c[1] << 3) & 0x7C0) | ((c[2] >> 2) & 0x3E)) | 1);
            } else {
                fill = 0xFF;
            }
            CMD(0xF7000000, fill)
            CMD(0xF6000000 | (((x1 - 1) & 0x3FF) << 14) | (((mid - 1) & 0x3FF) << 2),
                ((x0 & 0x3FF) << 14) | ((y0 & 0x3FF) << 2))
        }
        if (flag2 == 0) {
            Cmd8008528C *cmd;
            if (D_80114470.unk04 == 0x10) {
                c[0] = red1 + 4;
                if (c[0] >= 0x100) { c[0] = 0xFF; }
                c[1] = green1 + 4;
                if (c[1] >= 0x100) { c[1] = 0xFF; }
                c[2] = blue1 + 4;
                if (c[2] >= 0x100) { c[2] = 0xFF; }
                fill = (((((c[0] << 8) & 0xF800) | ((c[1] << 3) & 0x7C0) | ((c[2] >> 2) & 0x3E)) | 1) << 16) | ((((c[0] << 8) & 0xF800) | ((c[1] << 3) & 0x7C0) | ((c[2] >> 2) & 0x3E)) | 1);
            } else {
                fill = 0xFF;
            }
            CMDP(cmd, 0xF7000000, fill)
            CMDP(cmd, 0xF6000000 | (((x1 - 1) & 0x3FF) << 14) | (((y1 - 1) & 0x3FF) << 2),
                ((x0 & 0x3FF) << 14) | (((mid) & 0x3FF) << 2))
        }
    }

    CMD(0xE3000A01, 0)
    func_800390AC();
}
