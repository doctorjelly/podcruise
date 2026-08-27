/* Recovered from specification specs/func_8005B810.md (scratchpad copy). */
#include "podcruise/types.h"

/* Channel identifiers; the Japanese build numbers these three differently. */
#define CHANNEL_LOW_US 0xA6
#define CHANNEL_MID_US 0xA7
#define CHANNEL_HIGH_US 0xA8
#define CHANNEL_LOW_JP 0x99
#define CHANNEL_MID_JP 0x9A
#define CHANNEL_HIGH_JP 0x9B
#ifndef CHANNEL_LOW
#define CHANNEL_LOW CHANNEL_LOW_US
#endif
#ifndef CHANNEL_MID
#define CHANNEL_MID CHANNEL_MID_US
#endif
#ifndef CHANNEL_HIGH
#define CHANNEL_HIGH CHANNEL_HIGH_US
#endif

typedef struct Unk8005B810 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
} Unk8005B810;

extern s32 D_800A26F4;
extern f32 D_800ACFD0;
extern f32 D_800ACFD4;
extern f32 D_800ACFD8;
extern f32 D_800ACFDC;
extern f32 D_800ACFE0;
extern f32 D_800ACFE4;
extern f32 D_800ACFE8;
extern f32 D_800ACFEC;
extern f32 D_800ACFF0;

extern void func_80008B14(s32, s32, f32, f32, s32);
extern void func_8000A920(s32, s32);
extern void func_8000AA04(s32, s32, s32);
extern void func_8000AAC0(s32, f32, f32);
extern void func_8000AB24(s32, u8, u8, u8, s32);
extern void func_8000EA4C(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_80082BE0(void);

void func_8005B810(Unk8005B810 *arg0) {
    s32 pad[8]; /* frame reservation present in the original */
    f32 level;
    s32 chan0;
    s32 chan1;
    s32 chan2;
    s32 mode;

    (void)pad;
    func_8000A920(CHANNEL_LOW, 0);
    func_8000A920(CHANNEL_MID, 0);
    func_8000A920(CHANNEL_HIGH, 0);

    mode = arg0->unk_08 & 0xF;
    if (mode == 0) {
        if ((2.0f < arg0->unk_0C) && (arg0->unk_0C < 3.0f)) {
            level = arg0->unk_0C - 2.0f;
            if (D_800A26F4 == 0) {
                chan0 = (s32)(((f32)func_80082BE0() / (f32)2147483648.0) * 255.0f);
            } else {
                chan0 = (s32)D_800ACFD0;
            }
            if (D_800A26F4 == 0) {
                chan1 = (s32)(((f32)func_80082BE0() / (f32)2147483648.0) * 255.0f);
            } else {
                chan1 = (s32)D_800ACFD4;
            }
            if (D_800A26F4 == 0) {
                chan2 = (s32)(((f32)func_80082BE0() / (f32)2147483648.0) * 255.0f);
            } else {
                chan2 = (s32)D_800ACFD8;
            }
            func_8000A920(CHANNEL_HIGH, 1);
            func_8000AA04(CHANNEL_HIGH, 0xA0, 0x64);
            func_8000AAC0(CHANNEL_HIGH, level * 2.0f, level * 2.0f);
            func_8000AB24(CHANNEL_HIGH, chan0, chan1, chan2, (s32)(level * 254.0f));
            func_8000EA4C(arg0->unk_28, -1, -1, 0xFF, 0, 0, 0xFF);
            if (arg0->unk_08 & 0x100) {
                func_80008B14(0x59, 7, 0.25f, 1.0f, 0);
                arg0->unk_08 = arg0->unk_08 & ~0x100;
            }
        } else if ((1.0f < arg0->unk_0C) && (arg0->unk_0C < 2.0f)) {
            level = arg0->unk_0C - 1.0f;
            if (D_800A26F4 == 0) {
                chan0 = (s32)(((f32)func_80082BE0() / (f32)2147483648.0) * 255.0f);
            } else {
                chan0 = (s32)D_800ACFDC;
            }
            if (D_800A26F4 == 0) {
                chan1 = (s32)(((f32)func_80082BE0() / (f32)2147483648.0) * 255.0f);
            } else {
                chan1 = (s32)D_800ACFE0;
            }
            if (D_800A26F4 == 0) {
                chan2 = (s32)(((f32)func_80082BE0() / (f32)2147483648.0) * 255.0f);
            } else {
                chan2 = (s32)D_800ACFE4;
            }
            func_8000A920(CHANNEL_MID, 1);
            func_8000AA04(CHANNEL_MID, 0xA0, 0x64);
            func_8000AAC0(CHANNEL_MID, level * 2.0f, level * 2.0f);
            func_8000AB24(CHANNEL_MID, chan0, chan1, chan2, (s32)(level * 254.0f));
            func_8000EA4C(arg0->unk_28, -1, -1, 0xFF, 0x80, 0, 0xFF);
            if (arg0->unk_08 & 0x200) {
                func_80008B14(0x59, 7, 0.25f, 1.0f, 0);
                arg0->unk_08 = arg0->unk_08 & ~0x200;
            }
        } else if ((0.0f < arg0->unk_0C) && (arg0->unk_0C < 1.0f)) {
            level = arg0->unk_0C;
            if (D_800A26F4 == 0) {
                chan0 = (s32)(((f32)func_80082BE0() / (f32)2147483648.0) * 255.0f);
            } else {
                chan0 = (s32)D_800ACFE8;
            }
            if (D_800A26F4 == 0) {
                chan1 = (s32)(((f32)func_80082BE0() / (f32)2147483648.0) * 255.0f);
            } else {
                chan1 = (s32)D_800ACFEC;
            }
            if (D_800A26F4 == 0) {
                chan2 = (s32)(((f32)func_80082BE0() / (f32)2147483648.0) * 255.0f);
            } else {
                chan2 = (s32)D_800ACFF0;
            }
            func_8000A920(CHANNEL_LOW, 1);
            func_8000AA04(CHANNEL_LOW, 0xA0, 0x64);
            func_8000AAC0(CHANNEL_LOW, level * 2.0f, level * 2.0f);
            func_8000AB24(CHANNEL_LOW, chan0, chan1, chan2, (s32)(level * 254.0f));
            func_8000EA4C(arg0->unk_28, -1, -1, 0xFF, 0xFF, 0, 0xFF);
            if (arg0->unk_08 & 0x400) {
                func_80008B14(0x59, 7, 0.25f, 1.0f, 0);
                arg0->unk_08 = arg0->unk_08 & ~0x400;
            }
        }

        if (2.5f < arg0->unk_0C) {
            func_8000EA4C(arg0->unk_10, -1, -1, 0xFF, 0, 0, -1);
            func_8000EA4C(arg0->unk_14, -1, -1, 0xFF, 0, 0, -1);
            func_8000EA4C(arg0->unk_18, -1, -1, 0xFF, 0, 0, -1);
            func_8000EA4C(arg0->unk_1C, -1, -1, 0xFF, 0, 0, -1);
            func_8000EA4C(arg0->unk_20, -1, -1, 0xFF, 0, 0, -1);
            func_8000EA4C(arg0->unk_24, -1, -1, 0xFF, 0, 0, -1);
            mode = arg0->unk_08 & 0xF;
        } else if (2.0f < arg0->unk_0C) {
            func_8000EA4C(arg0->unk_10, -1, -1, 0, 0, 0, -1);
            func_8000EA4C(arg0->unk_14, -1, -1, 0, 0, 0, -1);
            func_8000EA4C(arg0->unk_18, -1, -1, 0, 0, 0, -1);
            func_8000EA4C(arg0->unk_1C, -1, -1, 0, 0, 0, -1);
            func_8000EA4C(arg0->unk_20, -1, -1, 0, 0, 0, -1);
            func_8000EA4C(arg0->unk_24, -1, -1, 0, 0, 0, -1);
            mode = arg0->unk_08 & 0xF;
        } else if (1.0f < arg0->unk_0C) {
            func_8000EA4C(arg0->unk_10, -1, -1, 0xFF, 0, 0, -1);
            func_8000EA4C(arg0->unk_24, -1, -1, 0xFF, 0, 0, -1);
            mode = arg0->unk_08 & 0xF;
        } else {
            func_8000EA4C(arg0->unk_14, -1, -1, 0xFF, 0xFF, 0, -1);
            func_8000EA4C(arg0->unk_20, -1, -1, 0xFF, 0xFF, 0, -1);
            mode = arg0->unk_08 & 0xF;
        }
    }

    if (mode == 1) {
        func_8000EA4C(arg0->unk_28, -1, -1, 0, 0xFF, 0,
                      (s32)((((f32)func_80082BE0() / (f32)2147483648.0) * 127.0f) + 128.0f));
        mode = arg0->unk_08 & 0xF;
    }
    if (mode == 3) {
        func_8000EA4C(arg0->unk_28, -1, -1, 0, 0xFF, 0, 0);
    }
}
