/* Recovered from specification: specs/func_80011F38.md (scratchpad) */
#include "podcruise/types.h"

typedef struct {
    u32 w0;
    u32 w1;
} DisplayWord;

extern s16 D_800D6914;
extern s16 D_800D6916;
extern s16 D_800D6918;
extern s16 D_800D691A;
extern s16 D_80114470[2];
extern DisplayWord *D_801217B0;

void func_80011F38(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8) {
    DisplayWord *gp;
    f32 sx;
    f32 sy;
    s16 x1;
    s16 y1;

    sx = D_80114470[0] / 320.0;
    sy = D_80114470[1] / 240.0;
    if (sx < 1.0) {
        sx = 1.0;
    }
    arg1 = arg1 - arg3;
    if (sy < 1.0) {
        sy = 1.0;
    }
    arg0 = arg0 - arg2;
    x1 = arg0 + arg4;
    y1 = arg1 + arg5;

    if (D_800D691A < D_800D6918) {
        D_800D6918 = arg0 * sx;
        D_800D6914 = arg1 * sy;
        D_800D691A = x1 * sx;
        D_800D6916 = y1 * sy;
    } else {
        if (arg0 * sx < D_800D6918) {
            D_800D6918 = arg0 * sx;
        }
        if (arg1 * sy < D_800D6914) {
            D_800D6914 = arg1 * sy;
        }
        if (D_800D691A < x1 * sx) {
            D_800D691A = x1 * sx;
        }
        if (D_800D6916 < y1 * sy) {
            D_800D6916 = y1 * sy;
        }
    }

    gp = D_801217B0++;
    gp->w0 = 0xE4000000 | (((u32)((s16)(x1 * 4) * sx) & 0xFFF) << 12) | ((u32)((s16)(y1 * 4) * sy) & 0xFFF);
    gp->w1 = (((u32)arg8 & 7) << 24) | (((u32)((s16)(arg0 * 4) * sx) & 0xFFF) << 12) | ((u32)((s16)(arg1 * 4) * sy) & 0xFFF);
    gp = D_801217B0++;
    gp->w0 = 0xE1000000;
    gp->w1 = ((u32)(arg6 * 32) << 16) | ((u32)(arg7 * 32) & 0xFFFF);
    gp = D_801217B0++;
    gp->w0 = 0xF1000000;
    gp->w1 = ((u32)(1024.0f / sx) << 16) | ((u32)(1024.0f / sy) & 0xFFFF);
}
