/* Independently written from specs/functions/func_8002C780.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s32 unk00[6];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
} OptionFlags;

extern OptionFlags D_8011A240;
extern f32 D_800A2654;
extern f32 D_800A2658;
extern s32 D_800A4B94;
extern f32 D_800A9ED8;
extern f32 D_800A9EDC;
extern f32 D_80120BF8;

extern void func_8000A920(s16, s32);
extern void func_8000AA04(s16, s16, s16);
extern void func_8000AAC0(s16, f32, f32);
extern void func_8000AB24(s16, s32, s32, s32, s32);

void func_8002C780(s32 arg0, s32 arg1, s32 arg2) {
    f32 step;
    f32 value;

    step = D_800A9ED8;
    if (D_8011A240.unk20 == 0) {
        step = D_800A9ED8 * -1.0f;
    }
    value = D_800A2654 + step * D_80120BF8; if (value > 254.0f) { value = 254.0f; } D_800A2654 = value; if (value < 0.0f) { D_800A2654 = 0.0f; }

    step = D_800A9ED8;
    if (D_8011A240.unk24 == 0) {
        step = D_800A9ED8 * -1.0f;
    }
    value = D_800A2658 + step * D_80120BF8; if (value > 254.0f) { value = 254.0f; } D_800A2658 = value; if (value < 0.0f) { D_800A2658 = 0.0f; }

    func_8000A920(0xAF, 1);
    func_8000AA04(0xAF, arg0 - 27, arg1 - 11);
    func_8000AB24(0xAF, 0xA3, 0xBE, 0x11, 0xFE);

    func_8000A920(0xAE, 1);
    func_8000AA04(0xAE, arg0 - 20, arg1 - 7);
    func_8000AB24(0xAE, 0x32, 0xFF, 0xFF, (u32)D_800A2654);

    func_8000A920(0xB2, 1);
    func_8000AA04(0xB2, arg0 - 27, arg1 + arg2 + 15);
    func_8000AB24(0xB2, 0xA3, 0xBE, 0x11, 0xFE);

    func_8000A920(0xB1, 1);
    func_8000AA04(0xB1, arg0 - 20, arg1 + arg2 + 23);
    func_8000AB24(0xB1, 0x32, 0xFF, 0xFF, (u32)D_800A2658);

    func_8000A920(0xB4, 1);
    func_8000AA04(0xB4, arg0 - 17, arg1 + 18);
    func_8000AB24(0xB4, 0xA3, 0xBE, 0x11, 0xFE);
    func_8000AAC0(0xB4, 1.0f, (f32)arg2 * D_800A9EDC);

    if (D_8011A240.unk24 != 0) {
        if ((D_800A4B94 & 0x8000) != 0) {
            func_8000A920(0xB3, 1);
            func_8000AA04(0xB3, arg0 - 32, arg1 + arg2 - 19);
            func_8000AB24(0xB3, 0x32, 0xFF, 0xFF, 0xFE);
        }
    }

    if (D_8011A240.unk20 != 0) {
        if ((D_800A4B94 & 0x4000) != 0) {
            func_8000A920(0xB0, 1);
            func_8000AA04(0xB0, arg0 - 32, arg1 - 17);
            func_8000AB24(0xB0, 0x32, 0xFF, 0xFF, 0xFE);
        }
    }
}
