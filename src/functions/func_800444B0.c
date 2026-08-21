/* Independently written from scratchpad spec specs/func_800444B0.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ s32 unk00[3];
    /* 0x00C */ f32 unk0C;
    /* 0x010 */ s32 unk10[16];
    /* 0x050 */ s32 unk50;
    /* 0x054 */ s32 unk54[12];
    /* 0x084 */ s32 unk84[697];
    /* 0xB68 */ f32 unkB68;
} PcFadeCtx;

extern f64 D_80120BF0;

extern void func_8003B02C(void *track, void *matrix);
extern void func_8000A920(s16 index, s32 flag);
extern void func_8000AB24(s16 index, s32 red, s32 green, s32 blue, u32 alpha);

void func_800444B0(PcFadeCtx *ctx) {
    f32 alpha;

    if (ctx->unk50 != 0) {
        func_8003B02C(ctx->unk54, ctx->unk84);
    }
    ctx->unkB68 = (f32)((f64)ctx->unkB68 - D_80120BF0);
    ctx->unk0C = (f32)((f64)ctx->unk0C + D_80120BF0);
    alpha = 1.0f;
    if (ctx->unk0C < 0.5f) {
        alpha = ctx->unk0C;
    }
    if (ctx->unkB68 < alpha) {
        alpha = ctx->unkB68;
    }
    if (alpha < 0.5f) {
        if (alpha < 0.0f) {
            func_8000AB24(-103, 0, 0, 0, 0xFF);
        } else {
            func_8000AB24(-103, 0, 0, 0, (u32)(255.0f - alpha / 0.5f * 255.0f));
        }
    } else {
        func_8000A920(-103, 0);
    }
}
