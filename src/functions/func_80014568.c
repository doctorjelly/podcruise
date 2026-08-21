/* specification: specs/func_80014568.md */
#include "podcruise/types.h"

#define PACK(r, g, b, a) ((((u32)(r) & 0xFF) << 24) | (((u32)(g) & 0xFF) << 16) | (((u32)(b) & 0xFF) << 8) | (((u32)(a) & 0xFF) << 0))


extern void func_80011F38(s16, s16, s16, s16, s32, s32, s32, s32, s32);

extern u8 D_800A1CCC[4];
extern s32 D_800D691C;
extern s32 D_800D6920;
extern s32 D_800D6924;
extern s32 D_800D6928;
extern s32 D_800D692C;
extern s32 D_800D6930;
extern s32 D_800D6934;
extern s32 D_800D6938;
extern u32 *D_801217B0;

void func_80014568(s32 arg0, s32 arg1, u8 arg2) {
    s32 x;
    s32 y;


    x = arg0 - D_800D6924 / 2;
    y = D_800D6928 / 2 + arg1;

    if (arg2 == 0x6F) {
        {
            u32 *gfx;

            gfx = D_801217B0;
            D_801217B0 = gfx + 2;
            gfx[0] = 0xFA000000;
            gfx[1] = PACK(0, 0, 0, D_800A1CCC[3]);
        }

        func_80011F38(x - 1, y - 1, D_800D691C, D_800D6920, D_800D6924, D_800D6928, D_800D692C, D_800D6930, D_800D6934);
        func_80011F38(x + 1, y + 1, D_800D691C, D_800D6920, D_800D6924, D_800D6928, D_800D692C, D_800D6930, D_800D6934);
        func_80011F38(x + 1, y - 1, D_800D691C, D_800D6920, D_800D6924, D_800D6928, D_800D692C, D_800D6930, D_800D6934);
        func_80011F38(x - 1, y + 1, D_800D691C, D_800D6920, D_800D6924, D_800D6928, D_800D692C, D_800D6930, D_800D6934);
        func_80011F38(x - 1, y, D_800D691C, D_800D6920, D_800D6924, D_800D6928, D_800D692C, D_800D6930, D_800D6934);
        func_80011F38(x + 1, y, D_800D691C, D_800D6920, D_800D6924, D_800D6928, D_800D692C, D_800D6930, D_800D6934);
        func_80011F38(x, y - 1, D_800D691C, D_800D6920, D_800D6924, D_800D6928, D_800D692C, D_800D6930, D_800D6934);
        func_80011F38(x, y + 1, D_800D691C, D_800D6920, D_800D6924, D_800D6928, D_800D692C, D_800D6930, D_800D6934);

        {
            u32 *gfx;

            gfx = D_801217B0;
            D_801217B0 = gfx + 2;
            gfx[0] = 0xFA000000;
            gfx[1] = PACK(D_800A1CCC[0], D_800A1CCC[1], D_800A1CCC[2], D_800A1CCC[3]);
        }
        D_800D6938 = 1;
    } else if (arg2 == 0x73) {
        {
            u32 *gfx;

            gfx = D_801217B0;
            D_801217B0 = gfx + 2;
            gfx[0] = 0xFA000000;
            gfx[1] = PACK(0, 0, 0, D_800A1CCC[3]);
        }

        func_80011F38(x + 1, y + 1, D_800D691C, D_800D6920, D_800D6924, D_800D6928, D_800D692C, D_800D6930, D_800D6934);

        {
            u32 *gfx;

            gfx = D_801217B0;
            D_801217B0 = gfx + 2;
            gfx[0] = 0xFA000000;
            gfx[1] = PACK(D_800A1CCC[0], D_800A1CCC[1], D_800A1CCC[2], D_800A1CCC[3]);
        }
        D_800D6938 = 1;
    } else if (arg2 == 0x66) {
        {
            u32 *gfx;

            gfx = D_801217B0;
            D_801217B0 = gfx + 2;
            gfx[0] = 0xFA000000;
            gfx[1] = PACK(0, 0, 0, D_800A1CCC[3]);
        }

        func_80011F38(x - 1, y, D_800D691C, D_800D6920, D_800D6924, D_800D6928, D_800D692C, D_800D6930, D_800D6934);
        func_80011F38(x + 1, y, D_800D691C, D_800D6920, D_800D6924, D_800D6928, D_800D692C, D_800D6930, D_800D6934);
        func_80011F38(x, y - 1, D_800D691C, D_800D6920, D_800D6924, D_800D6928, D_800D692C, D_800D6930, D_800D6934);
        func_80011F38(x, y + 1, D_800D691C, D_800D6920, D_800D6924, D_800D6928, D_800D692C, D_800D6930, D_800D6934);

        {
            u32 *gfx;

            gfx = D_801217B0;
            D_801217B0 = gfx + 2;
            gfx[0] = 0xFA000000;
            gfx[1] = PACK(D_800A1CCC[0], D_800A1CCC[1], D_800A1CCC[2], D_800A1CCC[3]);
        }
        D_800D6938 = 1;
    }

    if (D_800D6938 == 0) {
        {
            u32 *gfx;

            gfx = D_801217B0;
            D_801217B0 = gfx + 2;
            gfx[0] = 0xFA000000;
            gfx[1] = PACK(D_800A1CCC[0], D_800A1CCC[1], D_800A1CCC[2], D_800A1CCC[3]);
        }
        D_800D6938 = 1;
    }

    func_80011F38(x, y, D_800D691C, D_800D6920, D_800D6924, D_800D6928, D_800D692C, D_800D6930, D_800D6934);
}
