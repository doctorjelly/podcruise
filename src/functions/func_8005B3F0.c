/* Recovered per specs: func_8005B3F0 (see scratchpad specs/func_8005B3F0.md). */
#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 unk000[0x60];
    /* 0x060 */ u32 unk060;
    /* 0x064 */ u32 unk064;
    /* 0x068 */ u8 unk068[0x44];
    /* 0x0AC */ u8 unk0AC[0x1A8];
    /* 0x254 */ void *unk254;
    /* 0x258 */ f32 unk258[1];
} Obj;

typedef struct {
    /* 0x00 */ u8 unk00[0x84];
    /* 0x84 */ Obj *unk84;
} Actor;

typedef struct {
    /* 0x00 */ u8 unk00[0x8];
    /* 0x08 */ u32 unk08;
} Ctx;

extern void *D_8011AC80[];
extern Actor *D_8011B1BC;
extern Actor *D_8011B1C0;
extern s32 D_800A26F4;
extern f32 D_800ACFB0;
extern s32 D_800ACE14;

extern void func_80015288(f32 *, f32 *);
extern s32 func_800181BC(void *, s32, u32, s32, s32);
extern void func_8003B184(void *, void *, f32);
extern void func_8003EC40(s16, s16, u8, u8, u8, u8, void *);
extern s32 func_80051FF4(void);
extern void func_800573E8(Actor *, Ctx *);
extern void func_80057F48(Actor *);
extern void func_80058058(Actor *, s32);
extern void func_80059E54(Ctx *, Actor *, Obj *);
extern s32 func_8005B2D0(Ctx *, Obj *);
extern s32 func_80082BE0(void);

void func_8005B3F0(Ctx *ctx, Actor *actor) {
    f32 workB[42];
    f32 workA[12];
    Obj *obj;
    s32 mode;
    f32 level;
    s32 slot;
    u8 alpha;
    s32 pad1[1];

    (void)pad1;
    if (actor != 0) {
        if (actor == D_8011B1BC) {
            slot = 0xD;
        } else {
            slot = 0xE;
        }
        if ((ctx->unk08 & 0xF) == 1) {
            mode = 1;
        } else {
            mode = 0;
        }
        obj = actor->unk84;
        if ((obj->unk064 & 0x02000000) != 0) {
            func_80059E54(ctx, actor, obj);
            obj->unk060 &= 0xF7FFFFFF;
            if (D_8011AC80[slot] != 0) {
                func_800181BC(D_8011AC80[slot], 2, -4, 0x10, 3);
            }
            func_80057F48(actor);
            return;
        }
        if (mode != 0) {
            if (func_8005B2D0(ctx, obj) != 0) {
                if (D_8011AC80[slot] != 0) {
                    func_800181BC(D_8011AC80[slot], 2, 3, 0x10, 2);
                }
                obj->unk060 |= 0x08000000;
                func_8003B184(obj->unk0AC, workA, 0.5f);
                func_80015288(obj->unk258, workB);
                obj->unk254 = D_8011AC80[slot];
            } else {
                obj->unk060 &= 0xF7FFFFFF;
                if (D_8011AC80[slot] != 0) {
                    func_800181BC(D_8011AC80[slot], 2, -4, 0x10, 3);
                }
            }
        }
        func_800573E8(actor, ctx);
        if (func_80051FF4() == 2) {
            if (actor == D_8011B1C0) {
                func_80058058(actor, 0);
            } else {
                func_80058058(actor, 1);
            }
        } else {
            func_80058058(actor, 0);
        }
        if ((obj->unk060 & 0x800) != 0) {
            if (D_800A26F4 == 0) {
                level = ((f32)func_80082BE0() / (f32)2147483648.0) * 255.0f;
            } else {
                level = D_800ACFB0;
            }
            alpha = (u8)(u32)level;
            func_8003EC40(0xA0, 0x50, 0xFF, alpha, 0, 0xFF, &D_800ACE14);
        }
    }
}
