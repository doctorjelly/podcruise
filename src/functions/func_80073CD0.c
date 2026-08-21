/* Implements the specification in specs/func_80073CD0.md (engine sound band update). */
#include "podcruise/types.h"

typedef struct Obj73CD0 {
    /* 0x00 */ u8 pad00[0x18];
    /* 0x18 */ s32 *kind;
    /* 0x1C */ u8 pad1C[0x2C - 0x1C];
    /* 0x2C */ f32 span;
} Obj73CD0;

typedef struct Ctx73CD0 {
    /* 0x0000 */ u8 pad0000[0x50];
    /* 0x0050 */ u8 anchor[0x10];
    /* 0x0060 */ s32 stateA;
    /* 0x0064 */ s32 stateB;
    /* 0x0068 */ u8 pad0068[0xAC - 0x68];
    /* 0x00AC */ u8 source[0x18C - 0xAC];
    /* 0x018C */ f32 load;
    /* 0x0190 */ u8 pad0190[0x1A0 - 0x190];
    /* 0x01A0 */ f32 value;
    /* 0x01A4 */ u8 pad01A4[0x1E70 - 0x1A4];
    /* 0x1E70 */ Obj73CD0 *owner;
} Ctx73CD0;

extern f32 D_800A36BC[][15];
extern s32 D_800A59FC;
extern s32 D_800A5A00;
extern f32 D_800A6670[];
extern f32 D_800A6688[];
extern s32 D_800A669C;
extern f32 D_800A66A0[][2];
extern f32 D_800AD944;
extern f32 D_800AD948;
extern f32 D_800AD94C;
extern f32 D_800AD950;
extern f32 D_800AD954;
extern f64 D_800AD958;
extern f64 D_800AD960;
extern f64 D_800AD968;
extern s32 D_8011C8A0[];
extern f64 D_80120BF0;

extern void func_80008BC4(s32 id, s16 kind, f32 level, f32 pan, void *anchor,
                          s32 flagA, s32 flagB, f32 near, f32 far);
extern void func_80009C0C(s32 arg0, s32 arg1, f32 arg2, f32 arg3);
extern s32 func_80051FF4(void);
extern s32 func_800520C8(Obj73CD0 *owner);
extern f32 func_8008035C(void *source);
extern s32 func_80082BE0(void);

void func_80073CD0(Ctx73CD0 *ctx, f32 pan) {
    f32 pad[8];
    f32 scaleA;
    f32 scaleB;
    s32 muted;
    s16 newIndex;
    s16 prevIndex;
    Obj73CD0 *owner;
    s32 mode;
    s32 index;
    s32 band;
    f32 ratio;
    f32 *level;
    s16 soundId;
    f32 amount;
    f32 low;
    f32 high;

    (void)pad;

    muted = 0;
    low = 50.0f;
    high = 73.0f;
    scaleA = ((1.0f - (D_800A36BC[*ctx->owner->kind][0] - low) / (high - low)) * 0.5f) + 0.75f;
    scaleB = scaleA;
    func_80009C0C(D_800A59FC, D_800A5A00, func_8008035C(&ctx->source), ctx->value);

    if (ctx->stateA & 0x5800) {
        muted = 1;
    }

    owner = ctx->owner;
    mode = func_80051FF4();
    if (mode != 0) {
        index = func_800520C8(owner);
        if (index < 0) {
            return;
        }
    } else {
        index = 0;
    }

    ratio = ctx->value / owner->span;
    if ((ctx->stateA & 0xF) != 2) {
        D_8011C8A0[index] = 0;
        D_800A6670[index] = 1.0f;
        D_800A669C = 0;
    }

    band = D_8011C8A0[index];
    level = &D_800A6670[index];
    amount = D_800A6688[band] - D_800AD944;
    if (amount < 0.0f) {
        amount = 0.0f;
    }
    prevIndex = band;
    if (ratio < amount) {
        band = band - 1;
        D_8011C8A0[index] = band;
    }
    if ((D_800A6688[prevIndex + 1] + D_800AD944) < ratio) {
        band = band + 1;
        D_8011C8A0[index] = band;
    }
    if (band < 0) {
        band = 0;
        D_8011C8A0[index] = band;
    }
    if (band >= 4) {
        band = 3;
        D_8011C8A0[index] = band;
    }
    newIndex = band;

    if (level == D_800A6670) {
        soundId = band + 0xA2;
    } else {
        soundId = band + 0xA8;
    }

    if (soundId >= 0) {
        amount = (D_800A66A0[newIndex][1] + D_800A66A0[newIndex][0]) * 0.5f;
        if (((f32)func_80082BE0() / (f32)2147483648.0) < D_800AD948) {
            func_80082BE0();
        }
        amount = amount * scaleB;
        if (ctx->stateB & 0x4000) {
            amount = amount * 1.5f;
        } else if (ctx->stateB & 0x200) {
            if (level == D_800A6670) {
                soundId = 0xA7;
            } else {
                soundId = 0xAD;
            }
            amount = 0.25f;
        }
        if (muted == 0) {
            func_80008BC4(soundId, 6, amount, pan, &ctx->anchor, 1, 0, 20.0f, 500.0f);
        }
    }

    if ((ctx->stateB & 0x2000) && D_800A669C == 0) {
        D_800A669C = 1;
        func_80082BE0();
        if (muted == 0) {
            func_80008BC4(0x72, 7, 0.25f, pan, &ctx->anchor, 0, 1, 10.0f, 500.0f);
        }
    }

    if (0.5f < ctx->load) {
        if (mode == 1) {
            if (level == D_800A6670) {
                soundId = 0xA6;
            } else {
                soundId = 0xAC;
            }
            amount = D_800AD94C * pan;
            if (1.0f < amount) {
                amount = 1.0f;
            }
            if (ctx->stateB & 0x200) {
                amount = amount * D_800AD950;
            }
            if (muted == 0) {
                func_80008BC4(soundId, 6, D_800AD954 * scaleB, amount, &ctx->anchor, 1, 0,
                              10.0f, 500.0f);
            }
        }
    }

    if (ctx->stateA & 0x200) {
        if (1.0f == *level) {
            if (muted == 0) {
                func_80008BC4(0x80, 6, 0.25f * scaleB, pan, &ctx->anchor, 0, 1, 10.0f, 500.0f);
            }
        }
        *level = (f32)((f64)*level - D_80120BF0);
        if (*level < 0.0f) {
            *level = 0.0f;
        }
    } else {
        if (0.0f == *level) {
            if (muted == 0) {
                func_80008BC4(0x7F, 6, 0.25f * scaleB, pan, &ctx->anchor, 0, 1, 10.0f, 500.0f);
            }
        }
        *level = (f32)((f64)*level + D_80120BF0);
        if (1.0f < *level) {
            *level = 1.0f;
        }
    }

    if (newIndex < prevIndex) {
        func_80082BE0();
        func_80082BE0();
    } else if (prevIndex < newIndex) {
        amount = (f32)((f64)((f32)func_80082BE0() / (f32)2147483648.0) * D_800AD958 + D_800AD960) * scaleA;
        ratio = (f32)((f64)((f32)func_80082BE0() / (f32)2147483648.0) * D_800AD968 + 0.5) * pan;
        if (muted == 0) {
            func_80008BC4(0x7A, 6, amount, ratio, &ctx->anchor, 0, 1, 10.0f, 500.0f);
        }
    }
}
