/* Independently written from specs/functions/viewport_from_bounds.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 unk00[0x10];
    /* 0x10 */ s16 unk10;
    /* 0x12 */ s16 unk12;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ s16 unk18;
    /* 0x1A */ s16 unk1A;
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
} PcViewport;

extern s32 D_8009B7E8;
extern u32 D_800D5710;
extern s16 D_80114470[2];
void func_80086178(PcViewport *view) {
    f64 scaleX = D_80114470[0] / 320.0;
    s32 left = (f32) view->unk20 * scaleX;
    f64 scaleY = D_80114470[1] / 240.0;
    s32 top = (f32) view->unk24 * scaleY;
    s32 right = (f32) view->unk28 * scaleX;
    s32 bottom = (f32) view->unk2C * scaleY;

    view->unk10 = (right - left) * 2 + 8;
    view->unk12 = (bottom - top) * 2 + 8;
    view->unk18 = (left + right) * 2;
    view->unk1A = (top + bottom) * 2;

    if (D_8009B7E8 != 0) {
        view->unk10 = 0x500;
        view->unk12 = 0x3C0;
        view->unk18 = (D_800D5710 & 1) ? 0 : 0x500;
        view->unk1A = (D_800D5710 & 2) ? 0 : 0x3C0;
    }
    view->unk14 = 0x92;
    view->unk1C = 0x36C;
}
