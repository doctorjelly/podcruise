/* Recovered from specification specs/func_80042BB8.md (worker batch 04, reworked in batch 25). */
#include "podcruise/types.h"

typedef struct Part80042BB8 {
    /* 0x000 */ u8 unk000[0x50];
    /* 0x050 */ f32 unk050[3];
    /* 0x05C */ u8 unk05C[0x4];
    /* 0x060 */ s32 unk060;
    /* 0x064 */ u8 unk064[0x1F0];
    /* 0x254 */ void *unk254;
    /* 0x258 */ f32 unk258[3];
} Part80042BB8;

typedef struct Actor80042BB8 {
    /* 0x000 */ u8 unk000[0x40];
    /* 0x040 */ f32 unk040[3];
    /* 0x04C */ u8 unk04C[0x4];
    /* 0x050 */ f32 unk050[3];
    /* 0x05C */ u8 unk05C[0x98];
    /* 0x0F4 */ Part80042BB8 *unk0F4;
    /* 0x0F8 */ u8 unk0F8[0x40];
    /* 0x138 */ f32 unk138[3];
} Actor80042BB8;

extern f32 D_800A4AF0;
extern f64 D_80120BF0;

extern void func_8000EA4C(void *node, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern void func_80015288(f32 *output, f32 *source);
extern void func_8001535C(f32 *output, f32 *left, f32 *right);
extern f32 func_800154D0(f32 *vector);
extern void func_80015538(f32 *output, f32 *left, f32 *right);
extern void func_800155EC(f32 *output, f32 *source, f32 angle, f32 *axis);
extern void func_80017874(f32 (*matrix)[4]);
extern void func_80017918(f32 (*output)[4], f32 x, f32 y, f32 z, f32 (*source)[4]);
extern void func_80017BA8(void *node, f32 (*matrix)[4]);
extern void func_800181BC(void *node, s32 which, s32 value, s32 flags, s32 mode);
extern s32 func_80051FF4(void);

void func_80042BB8(Actor80042BB8 *actor) {
    f32 second[4][4];
    f32 first[4][4];
    s16 alpha;
    f32 spare[3];
    Part80042BB8 *part;
    f32 spread;
    f32 fade;
    f32 level;
    f32 value;

    (void)spare;
    if (func_80051FF4() == 1) {
        spread = 2.0f;
        fade = D_800A4AF0 + D_80120BF0 * 3.0;
    } else {
        spread = 1.5f;
        fade = D_800A4AF0 + D_80120BF0 * (3.0f / (f32)func_80051FF4());
    }
    D_800A4AF0 = fade;
    if (fade > 1.0f) {
        D_800A4AF0 = -1.0f;
    }
    part = actor->unk0F4;
    if (part != 0 && (part->unk060 << 4) < 0 && part->unk254 != 0) {
        func_80017874(first);
        func_8001535C(first[1], actor->unk138, actor->unk050);
        func_80015288(first[2], actor->unk040);
        func_80015538(first[0], first[1], first[2]);
        func_80015538(first[2], first[0], first[1]);
        func_800154D0(first[0]);
        func_800154D0(first[1]);
        func_800154D0(first[2]);
        func_80015288(first[3], actor->unk050);
        if (part->unk254 != 0) {
            func_800181BC(part->unk254, 2, 3, 0x10, 2);
        }
        alpha = 255;
        value = D_800A4AF0;
        if (value < 0.0f) {
            D_800A4AF0 = value;
            level = -value;
        } else {
            D_800A4AF0 = value;
            level = value;
        }
        func_8000EA4C(part->unk254, 0, 0, 0x59, 0x8C, 0x36, (s32)(alpha * (1.0f - level)));
        func_80017874(second);
        func_8001535C(second[1], part->unk258, part->unk050);
        second[1][2] = 0.0f;
        func_800154D0(second[1]);
        func_80015538(second[0], second[1], second[2]);
        func_80015538(second[2], second[0], second[1]);
        func_800154D0(second[0]);
        func_800154D0(second[2]);
        func_80017918(second, -0.015f, 0.015f, -0.0075f, second);
        func_80015288(second[3], first[3]);
        func_800155EC(second[3], second[3], 5.0f, first[1]);
        func_800155EC(second[3], second[3], spread, first[2]);
        func_800155EC(second[3], second[3], 0.0f, first[0]);
        func_800155EC(second[3], second[3], (f32)(D_800A4AF0 * 100.0), second[1]);
        func_80017BA8(part->unk254, second);
    }
}
