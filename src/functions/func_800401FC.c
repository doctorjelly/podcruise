/* Independently written from specs/functions/recovered/func_800401FC.md. */
#include "podcruise/types.h"

typedef struct Obj800401FC {
    /* 0x000 */ u8 unk000[0x2E4];
    /* 0x2E4 */ u32 unk2E4;
    /* 0x2E8 */ f32 unk2E8[3];
    /* 0x2F4 */ f32 unk2F4[3];
    /* 0x300 */ f32 unk300[3];
    /* 0x30C */ f32 unk30C[3];
    /* 0x318 */ f32 unk318[3];
    /* 0x324 */ f32 unk324[3];
    /* 0x330 */ f32 unk330;
    /* 0x334 */ f32 unk334[3];
    /* 0x340 */ f32 unk340[3];
    /* 0x34C */ f32 unk34C[3];
    /* 0x358 */ f32 unk358[3];
    /* 0x364 */ u8 unk364[0x34];
    /* 0x398 */ f32 unk398;
} Obj800401FC;

typedef struct Ctx800401FC {
    /* 0x0000 */ u8 unk0000[0x50];
    /* 0x0050 */ f32 unk0050[3];
    /* 0x005C */ u8 unk005C[0x300 - 0x5C];
    /* 0x0300 */ s32 unk0300;
    /* 0x0304 */ s32 unk0304;
    /* 0x0308 */ u8 unk0308[0x13C0 - 0x308];
    /* 0x13C0 */ f32 unk13C0[3];
} Ctx800401FC;

extern f32 func_800154D0(f32 *);
extern s32 func_80082BE0(void);
extern void func_80086A20(s32, f32 *, f32 *, f32 *);
extern void func_80086B8C(s32, s32, f32 *, f32 *);

extern f64 D_80120BF0;

static const f32 D_800AAC30[2] = {0.0f, 0.0f};

#define TRUNCF(x) ((x) < (f32)0 ? (s32)((x) - 0.999999f) : (s32)(x))

void func_800401FC(Obj800401FC *object, Ctx800401FC *context) {
    s32 changed;
    f32 sp78[3];
    f32 color[3];
    f32 offset[3];
    f32 sp54[3];
    f32 sp48[3];
    f32 sum;
    f32 quotient;
    f32 blend;
    f32 rest;
    f32 random;

#if defined(__GNUC__)
    (void)D_800AAC30;
#endif
    (void)sp78;
    changed = 0;
    if (context->unk0300 < 0) {
        return;
    }

    sp78[0] = object->unk2F4[0];
    sp78[1] = object->unk2F4[1];
    sp78[2] = object->unk2F4[2];

    if (object->unk2E4 & 0x40) {
        object->unk2E4 &= ~0x40;
        changed = 1;
    }

    if (object->unk2E4 & 1) {
        if ((s32)object->unk2E4 < 0) {
            object->unk2E8[0] = object->unk334[0];
            object->unk2E8[1] = object->unk334[1];
            object->unk2E8[2] = object->unk334[2];
            object->unk2E4 &= 0x7FFFFFFF;
            object->unk2E4 &= ~1;
            object->unk2E4 &= ~2;
            object->unk300[2] = object->unk34C[2];
            object->unk300[1] = object->unk34C[1];
            object->unk300[0] = object->unk34C[0];
            object->unk2F4[0] = object->unk340[0];
            changed = 1;
            object->unk2F4[2] = object->unk340[2];
            object->unk2F4[1] = object->unk340[1];
            func_800154D0(object->unk2F4);
        } else {
            if (object->unk2E4 & 2) {
                object->unk318[0] = object->unk2F4[0];
                object->unk318[1] = object->unk2F4[1];
                object->unk318[2] = object->unk2F4[2];
                object->unk324[1] = object->unk300[1];
                object->unk324[0] = object->unk300[0];
                object->unk324[2] = object->unk300[2];
                object->unk2E4 &= ~2;
                object->unk30C[1] = object->unk2E8[1];
                object->unk30C[2] = object->unk2E8[2];
                object->unk30C[0] = object->unk2E8[0];
            }
            object->unk2F4[0] = object->unk340[0];
            object->unk2F4[1] = object->unk340[1];
            object->unk2F4[2] = object->unk340[2];
            object->unk300[1] = object->unk34C[1];
            object->unk300[0] = object->unk34C[0];
            object->unk300[2] = object->unk34C[2];
            object->unk2E8[1] = object->unk334[1];
            object->unk2E8[2] = object->unk334[2];
            object->unk2E8[0] = object->unk334[0];
        }
    }

    if (object->unk2E4 & 8) {
        object->unk2F4[0] = context->unk0050[0] - object->unk340[0];
        object->unk2F4[1] = context->unk0050[1] - object->unk340[1];
        object->unk2F4[2] = context->unk0050[2] - object->unk340[2];
        changed = 1;
        func_800154D0(object->unk2F4);
    }

    if (object->unk2E4 & 4) {
        changed = 1;
        sum = context->unk0050[0] * object->unk358[0] + context->unk0050[1] * object->unk358[1] +
              context->unk0050[2] * object->unk358[2];
        quotient = sum / 100.0f;
        if (50.0f < sum - (f32)TRUNCF(quotient) * 100.0f) {
            rest = -(50.0f - (sum - (f32)TRUNCF(quotient) * 100.0f));
        } else {
            rest = 50.0f - (sum - (f32)TRUNCF(quotient) * 100.0f);
        }
        blend = rest / 50.0f;
        object->unk300[0] = object->unk34C[0] * blend;
        object->unk300[1] = object->unk34C[1] * blend;
        object->unk300[2] = object->unk34C[2] * blend;
    }

    if (object->unk2E4 & 1) {
        object->unk398 -= D_80120BF0 / 0.5;
        changed = 1;
        if (object->unk398 < 0) {
            object->unk398 = 0;
            object->unk2E4 &= ~1;
        }
        blend = object->unk398;
        rest = 1.0f - blend;
        object->unk2E8[0] = object->unk30C[0] * blend + object->unk2E8[0] * rest;
        object->unk2E8[1] = object->unk30C[1] * blend + object->unk2E8[1] * rest;
        object->unk2E8[2] = object->unk30C[2] * blend + object->unk2E8[2] * rest;
        object->unk300[0] = object->unk324[0] * blend + object->unk300[0] * rest;
        object->unk300[1] = object->unk324[1] * blend + object->unk300[1] * rest;
        object->unk300[2] = object->unk324[2] * blend + object->unk300[2] * rest;
        object->unk2F4[0] = object->unk318[0] * blend + object->unk2F4[0] * rest;
        object->unk2F4[1] = object->unk318[1] * blend + object->unk2F4[1] * rest;
        object->unk2F4[2] = object->unk318[2] * blend + object->unk2F4[2] * rest;
        if (object->unk2F4[0] * object->unk2F4[0] + object->unk2F4[1] * object->unk2F4[1] +
                object->unk2F4[2] * object->unk2F4[2] < 0.1f) {
            sp78[0] = object->unk2F4[0];
            sp78[1] = object->unk2F4[1];
            sp78[2] = object->unk2F4[2];
        }
    }

    if (object->unk2E4 & 0x10) {
        random = ((f32)func_80082BE0() / (f32)2147483648.0) * 0.5f + 0.5f;
        color[0] = 200.0f * random;
        color[1] = 200.0f * random;
        color[2] = 255.0f * random;
        offset[0] = context->unk0050[0] - context->unk13C0[0];
        offset[1] = context->unk0050[1] - context->unk13C0[1];
        offset[2] = context->unk0050[2] - context->unk13C0[2];
        func_800154D0(offset);
        object->unk2E4 |= 0x20;
        func_80086B8C(context->unk0300, 1, color, offset);
    } else if (object->unk2E4 & 0x20) {
        object->unk2E4 &= ~0x20;
        func_80086B8C(context->unk0300, 0, color, offset);
    }

    if (changed != 0) {
        if (context->unk0304 != 0) {
            sp54[0] = object->unk2E8[0];
            sp54[1] = object->unk2E8[1];
            sp54[2] = object->unk2E8[2];
            sp48[0] = object->unk300[0];
            sp48[1] = object->unk300[1];
            sp48[2] = object->unk300[2];
            if (context->unk0304 == 1) {
                sp54[0] = 0.0f;
                sp54[1] = (f32)0.0;
            } else {
                sp54[1] = 0.0f;
                sp54[2] = (f32)0.0;
            }
            func_80086A20(context->unk0300, sp54, sp48, object->unk2F4);
        } else {
            func_80086A20(context->unk0300, object->unk2E8, object->unk300, object->unk2F4);
        }
    }
}
