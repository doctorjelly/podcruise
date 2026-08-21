/* Specification: scratchpad specs/func_80009FA0.md */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ f32 unk08;
    /* 0x0C */ f32 unk0C;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ u8 unk18;
    /* 0x19 */ u8 unk19;
    /* 0x1A */ u8 unk1A;
    /* 0x1B */ u8 unk1B;
    /* 0x1C */ s32 unk1C;
} Item80009FA0;

extern s32 D_8009B7E8;

extern void func_8003D4F4(s32 arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4, f32 arg5,
                          s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, s32 arg11,
                          s32 arg12);

void func_80009FA0(Item80009FA0 *item, s32 mask, f32 scaleX, f32 scaleY) {
    s32 flags;
    s32 style;

    if (D_8009B7E8 == 0) {
        flags = item->unk14;
        if (flags & 0x20) {
            if (flags & mask) {
                if (item->unk1C == 0) {
                    if (item->unk1B < 0xFF) {
                        func_8003D4F4(0, (s16) (s32) (item->unk00 * scaleX),
                                      (s16) (s32) (item->unk02 * scaleY),
                                      item->unk08 * scaleX * 0.0625f, item->unk0C * scaleY,
                                      0.0f, 0, 0, 2, item->unk18, item->unk19, item->unk1A,
                                      item->unk1B);
                    } else {
                        func_8003D4F4(0, (s16) (s32) (item->unk00 * scaleX),
                                      (s16) (s32) (item->unk02 * scaleY),
                                      item->unk08 * scaleX * 0.0625f, item->unk0C * scaleY,
                                      0.0f, 0, 0, 0x10000000, item->unk18, item->unk19,
                                      item->unk1A, 0xFF);
                    }
                } else {
                    style = 0;
                    if (flags & 0x2000) {
                        style = 0x10;
                    }
                    if (!(mask & 1)) {
                        style = style & ~0x10;
                    }
                    if (flags & 0x10) {
                        style = style | 0x8000;
                    }
                    if (item->unk1B != 0xFF || (flags & 0x400)) {
                        style = style | 1;
                    }
                    if (flags & 0x1000) {
                        style = style | 0x20000;
                    }
                    if (flags & 0x4) {
                        style = style | 0x2000;
                    }
                    if (flags & 0x8) {
                        style = style | 0x4000;
                    }
                    if (flags & 0x40) {
                        style = style | 0x10000;
                    }
                    if (flags & 0x80) {
                        style = style | 0x3000000;
                    }
                    if (flags & 0x100) {
                        style = style | 0x800000;
                    }
                    if (flags & 0x8000) {
                        style = style | 0x10000000;
                    }
                    if (flags & 0x4000) {
                        style = style | 0x400000;
                    }
                    if (flags & 0x200) {
                        style = style | 2;
                    }
                    if (flags & 0x10000) {
                        style = style | 0x40;
                    }
                    func_8003D4F4(item->unk1C, (s16) (s32) (item->unk00 * scaleX),
                                  (s16) (s32) (item->unk02 * scaleY), item->unk08 * scaleX,
                                  item->unk0C * scaleY, item->unk10,
                                  (s32) (item->unk04 * scaleX), (s32) (item->unk06 * scaleY),
                                  style, item->unk18, item->unk19, item->unk1A,
                                  item->unk1B);
                }
            }
        }
    }
}
