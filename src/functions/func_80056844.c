/* Independently written from the specification in specs/func_80056844.md. */

#include "podcruise/types.h"

extern f32 D_800A59B0;
extern f32 D_800ACEDC;
extern f32 D_800ACEE0;

extern s32 func_80051FF4(void);
extern void func_8000A920(s16 id, s32 enable);
extern void func_8000AA04(s16 index, s16 x, s16 y);
extern void func_8000AAC0(s16 index, f32 x, f32 y);
extern void func_8000AB24(s16 index, u8 red, u8 green, u8 blue, u8 alpha);
extern f32 func_8002F060(void);

void func_80056844(s32 arg0) {
    f32 zero = 0.0f;
    f32 c1 = 1.0f;
    f32 c3 = 3.0f;
    f32 c4 = 4.0f;
    f32 c14 = 14.0f;
    f32 c24 = 24.0f;
    f32 c48 = 48.0f;
    f32 c90 = 90.0f;
    f32 c102 = 102.0f;
    f32 c18 = 18.0f;
    f32 c109 = 109.0f;
    f32 c254 = 254.0f;
    f32 c23 = 23.0f;
    f32 c220 = 220.0f;
    f32 c20 = 20.0f;
    f32 c229 = (f32)0xE5;
    f32 c180 = (f32)0xB4;
    f32 c22 = 22.0f;
    f32 c21 = 21.0f;
    f32 c275 = (f32)0x113;
    f32 c160 = (f32)0xA0;
    f32 c164 = (f32)0xA4;
    f32 c6075 = 60.75f;
    s16 pos;
    s16 column;
    f32 rowA;
    f32 rowB;
    f32 span;
    f32 level;
    f32 rest;
    f32 shade;

    if (func_80051FF4() < 2) {
        if (!(arg0 & 1)) {
            func_8000A920(5, 1);
            pos = zero;
            func_8000AA04(5, pos, c20 + c1);
            func_8000AAC0(5, 320.0f, 2.0f);
            func_8000AB24(5, 0x59, 0x8C, 0x36, 0x40);

            func_8000A920(6, 0);

            func_8000A920(0xD, 1);
            func_8000AA04(0xD, pos, c20 + c3);
            func_8000AAC0(0xD, 80.0f, 1.0f);
            func_8000AB24(0xD, 0, 0x6E, 0x8F, 0xFE);

            rowA = c20 + c14;
            func_8000A920(0, 1);
            func_8000AA04(0, c18, rowA);
            func_8000AB24(0, 0x59, 0x8C, 0x36, 0xFE);

            rowB = c18 + c48;
            rowA = rowA + c1;
            func_8000A920(0xB, 1);
            pos = rowA;
            func_8000AA04(0xB, rowB, pos);
            func_8000AAC0(0xB, 21.5f, 1.0f);
            func_8000AB24(0xB, 0x59, 0x8C, 0x36, 0xFE);

            func_8000A920(4, 1);
            func_8000AA04(4, c109, pos);
            func_8000AB24(4, 0x59, 0x8C, 0x36, 0xFE);

            rowB = c109 + c102;
            func_8000A920(0xC, 1);
            func_8000AA04(0xC, rowB, pos);
            func_8000AAC0(0xC, 21.5f, 1.0f);
            func_8000AB24(0xC, 0x59, 0x8C, 0x36, 0xFE);

            rowA = rowA - c1;
            func_8000A920(1, 1);
            func_8000AA04(1, c254, rowA);
            func_8000AB24(1, 0x59, 0x8C, 0x36, 0xFE);
        } else {
            func_8000A920(6, 1);
            pos = c23;
            func_8000AA04(6, pos, c220);
            func_8000AAC0(6, 270.0f, 2.0f);
            func_8000AB24(6, 0x59, 0x8C, 0x36, 0x40);

            func_8000A920(5, 1);
            func_8000AA04(5, pos, c20);
            func_8000AAC0(5, 270.0f, 2.0f);
            func_8000AB24(5, 0x59, 0x8C, 0x36, 0x40);

            func_8000A920(0xD, 0);
            func_8000A920(0, 0);
            func_8000A920(0xB, 0);
            func_8000A920(4, 0);
            func_8000A920(0xC, 0);
            func_8000A920(1, 0);
        }

        func_8000A920(3, 1);
        span = c229;
        pos = c180;
        func_8000AA04(3, span, pos);
        func_8000AB24(3, 0, 0x6E, 0x8F, 0xFE);

        rowB = span + c14;
        func_8000A920(2, 1);
        func_8000AA04(2, rowB, pos);
        func_8000AAC0(2, 6.0f, 1.0f);
        func_8000AB24(2, 0, 0x6E, 0x8F, 0xFE);

        rowB = rowB + c24;
        func_8000A920(0xA, 1);
        func_8000AA04(0xA, rowB, pos);
        func_8000AB24(0xA, 0, 0x6E, 0x8F, 0xFE);

        if (arg0 & 4) {
            func_8000A920(7, 1);
            pos = c21;
            func_8000AA04(7, c22, pos);
            func_8000AAC0(7, 1.0f, 99.5f);
            func_8000AB24(7, 0x59, 0x8C, 0x36, 0xFE);

            func_8000A920(8, 1);
            func_8000AA04(8, D_800ACEDC, pos);
            func_8000AAC0(8, 1.0f, 99.5f);
            func_8000AB24(8, 0x59, 0x8C, 0x36, 0xFE);

            func_8000A920(9, 1);
            func_8000AA04(9, c275, c160);
            func_8000AB24(9, 0x59, 0x8C, 0x36, 0xFE);
        } else {
            if (arg0 & 2) {
                level = c1 - func_8002F060();
                level = level + level;
                if (c1 < level) {
                    level = c1;
                }
                level = level * (c1 - D_800A59B0);
            } else {
                level = 0.0f;
            }
            func_8000A920(7, 1);
            rest = c90 * level;
            column = c275;
            span = c164 - rest;
            func_8000AA04(7, column, span);
            func_8000AAC0(7, 1.0f, rest / (f32)2.0);
            func_8000AB24(7, 0x59, 0x8C, 0x36, 0xFE);

            rowA = span - c4;
            func_8000A920(9, 1);
            func_8000AA04(9, column, rowA);
            func_8000AB24(9, 0x59, 0x8C, 0x36, 0xFE);

            func_8000A920(8, 0);
        }

        shade = D_800A59B0;
        if (zero < shade) {
            func_8000A920(0x19, 1);
        } else {
            func_8000A920(0x19, 0);
        }
        func_8000AA04(0x19, D_800ACEE0, c6075);
        func_8000AAC0(0x19, 15.625f, 3.90625f);
        func_8000AB24(0x19, 0 * 0.5, 0x6E * 0.5, 0x8F * 0.5, 0xFE * shade);
    }
}
