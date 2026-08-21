/* Independently written from specs/functions/recovered/stitched_ui_control_tranche.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s32 unk00[4];
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
} OptionFlags;

extern OptionFlags D_8011A240;
extern f32 D_800A265C;
extern f32 D_800A2660;
extern f32 D_800A9EE0;
extern f32 D_800A9EE4;
extern f32 D_80120BF8;

extern void func_8000A920(s16, s32);
extern void func_8000AA04(s16, s16, s16);
extern void func_8000AAC0(s16, f32, f32);
extern void func_8000AB24(s16, s32, s32, s32, s32);

void func_8002CC28(s32 arg0, s32 arg1, s32 arg2) {
    f32 value;
    s16 span;

    value = D_800A9EE0;
    if (D_8011A240.unk18 == 0) {
        value = D_800A9EE0 * -1.0f;
    }
    value = D_800A265C + value * D_80120BF8; if (value > 254.0f) { value = 254.0f; } D_800A265C = value; if (value < 0.0f) { D_800A265C = 0.0f; }

    value = D_800A9EE0;
    if (D_8011A240.unk1C == 0) {
        value = D_800A9EE0 * -1.0f;
    }
    value = D_800A2660 + value * D_80120BF8; if (value > 254.0f) { value = 254.0f; } D_800A2660 = value; if (value < 0.0f) { D_800A2660 = 0.0f; }

    func_8000A920(0xAB, 1);
    func_8000AA04(0xAB, 0x13, arg1 - 14);
    func_8000AB24(0xAB, 0xA3, 0xBE, 0x11, 0xFE);

    func_8000A920(0xAA, 1);
    func_8000AA04(0xAA, 0x16, arg1 - 7);
    func_8000AB24(0xAA, 0x32, 0xFF, 0xFF, (u32)D_800A265C);

    func_8000A920(0xA8, 1);
    func_8000AA04(0xA8, 0x109, arg1 - 14);
    func_8000AB24(0xA8, 0xA3, 0xBE, 0x11, 0xFE);

    func_8000A920(0xA7, 1);
    func_8000AA04(0xA7, 0x110, arg1 - 7);
    func_8000AB24(0xA7, 0x32, 0xFF, 0xFF, (u32)D_800A2660);

    func_8000A920(0xAD, 1);
    func_8000AA04(0xAD, 0x30, arg1 - 4);
    func_8000AB24(0xAD, 0xA3, 0xBE, 0x11, 0xFE);
    span = 221;
    func_8000AAC0(0xAD, span * D_800A9EE4, 1.0f);

    if (D_8011A240.unk14 != 0) {
        func_8000A920(0xA9, 1);
        func_8000AA04(0xA9, 0xE6, arg1 - 19);
        func_8000AB24(0xA9, 0x32, 0xFF, 0xFF, 0xFE);
    }

    if (D_8011A240.unk10 != 0) {
        func_8000A920(0xAC, 1);
        func_8000AA04(0xAC, 0xC, arg1 - 19);
        func_8000AB24(0xAC, 0x32, 0xFF, 0xFF, 0xFE);
    }

    (void)arg0;
    (void)arg2;
}
