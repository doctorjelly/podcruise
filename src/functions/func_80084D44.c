/* Implements specs/functions/recovered/func_80084D44.md. */
#include "podcruise/types.h"

typedef struct {
    /* 0x0 */ u32 w0;
    /* 0x4 */ u32 w1;
} PcGfx;

typedef struct {
    /* 0x00 */ u32 unk00[13];
    /* 0x34 */ u32 unk34;
} TaskBlock;

extern PcGfx *D_801217B0;
extern PcGfx *D_801217B4;
extern TaskBlock *D_801488C0;
extern s32 D_80135030;
extern s32 D_80135034;
extern s32 D_801488B0;
extern s32 D_801488B4;
extern s32 D_800A268C;
extern s32 D_800A2690;

extern void func_80088AD0(void);
extern void func_80084C30(s16 mode);
extern void func_8002E2FC(void);
extern void func_8002E548(void);
extern void func_8002DFBC(void);
extern void func_8002E034(void);

void func_80084D44(mode, flag)
s16 mode;
s32 flag;
{
    PcGfx *gfx;
    s32 count;

    gfx = D_801217B0;
    D_801217B0 = gfx + 1;
    gfx->w0 = 0xE9000000;
    gfx->w1 = 0;

    gfx = D_801217B0;
    D_801217B0 = gfx + 1;
    gfx->w1 = 0;
    gfx->w0 = 0xDF000000;

    func_80088AD0();

    count = D_801217B0 - D_801217B4;
    if ((D_80135030 != 0) || (D_80135034 != 0) || (D_801488B0 != 0) || (D_801488B4 != 0)) {
        count = D_801217B0 - D_801217B4;
        D_80135030 = 0;
        D_80135034 = 0;
        D_801488B0 = 0;
        D_801488B4 = 0;
    }
    D_801488C0->unk34 = count * 8;

    func_80088AD0();
    func_80084C30(mode);

    if (flag != 0) {
        func_8002E2FC();
        if ((D_800A268C == 0) || (D_800A2690 == 0)) {
            D_800A268C = 1;
            D_800A2690 = 1;
        }
    }
    func_8002E548();
    if (flag != 0) {
        func_8002DFBC();
        func_8002E034();
    }
    func_80088AD0();
}
