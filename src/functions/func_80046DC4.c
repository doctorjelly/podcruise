/* Independently written from scratchpad spec specs/func_80046DC4.md. */

#include "podcruise/types.h"

extern void func_8000A920(s16, s32);
extern void func_8000AA04(s16, s16, s16);
extern void func_8000AAC0(s16, f32, f32);
extern void func_8000AB24(s16, s32, s32, s32, s32);
extern void func_8003EC40(s16, s16, u8, u8, u8, u8, u8 *);
extern s32 func_80082BE0(void);

extern s32 D_800A4BB4;
extern f32 D_800A4BF0;
extern u8 D_800AADC4[];
extern u8 D_800AADDC[];
extern u8 D_800AADEC[];
extern u8 D_800AADFC[];
extern u8 D_800AAE08[];
extern u8 D_800AAE18[];
extern u8 D_800AAE28[];
extern u8 D_800AAE38[];
extern f32 D_80119858[];
extern f32 D_80119878[];
extern s16 D_80119898[];

void func_80046DC4(s32 *arg0, f32 x, f32 y) {
    f32 scale;
    f32 level;
    s32 xi;
    s32 xb;
    s16 id;
    s32 sel;
    s32 i;
    u8 alpha;

    sel = -1;
    level = 255.0f;
    scale = 1.0f;
    if (arg0[2] == 8) {
        scale = D_800A4BF0 * 2.5f;
    }
    level = level * scale;
    if (254.0f < level) {
        level = 254.0f;
    }
    for (i = 0; i < 7; i++) {
        if (D_80119898[i] != 0) {
            sel = i;
        }
    }
    alpha = level;

    func_8000A920(0x54, 1);
    func_8000AA04(0x54, x, y);
    func_8000AB24(0x54, 0xA3, 0xBE, 0x11, alpha);

    xi = (s16)(x + 5.0f);
    func_8003EC40(xi, y - 4.0f, 0x32, 0xFF, 0xFF, alpha, D_800AADC4);

    for (i = 0x55; i < 0x5C; i++) {
        id = (s16)i;
        func_8000A920(id, 1);
        func_8000AA04(id, xi, (y + 5.0f) + 9.5f * (f32)(i - 0x55));
        func_8000AB24(id, 0x32, 0xFF, 0xFF, alpha);
    }

    func_8003EC40(xi, (y + 7.0f), 0x32, 0xFF, 0xFF, alpha, D_800AADDC);
    func_8003EC40(xi, (y + 7.0f) + 9.5f, 0x32, 0xFF, 0xFF, alpha, D_800AADEC);
    func_8003EC40(xi, (y + 7.0f) + 19.0f, 0x32, 0xFF, 0xFF, alpha, D_800AADFC);
    func_8003EC40(xi, (y + 7.0f) + 28.5f, 0x32, 0xFF, 0xFF, alpha, D_800AAE08);
    func_8003EC40(xi, (y + 7.0f) + 38.0f, 0x32, 0xFF, 0xFF, alpha, D_800AAE18);
    func_8003EC40(xi, (y + 7.0f) + 47.5f, 0x32, 0xFF, 0xFF, alpha, D_800AAE28);
    func_8003EC40(xi, (y + 7.0f) + 57.0f, 0x32, 0xFF, 0xFF, alpha, D_800AAE38);

    func_8000A920(0x5C, 1);
    func_8000AA04(0x5C, x + 65.0f, y + 69.0f);
    func_8000AB24(0x5C, 0x32, 0xFF, 0xFF, alpha);

    func_8000A920(0x5D, 1);
    func_8000AA04(0x5D, x + 167.0f, y + 5.0f);
    func_8000AB24(0x5D, 0x32, 0xFF, 0xFF, alpha);

    if (sel >= 0) {
        func_8000A920(0x5E, 1);
        func_8000AA04(0x5E, x - 6.0f, y + 9.5f * (f32)sel);
        func_8000AB24(0x5E, 0x32, 0xFF, 0xFF, alpha);
    }

    xb = (s16)(x + 67.0f);
    for (i = 0; i < 7; i++) {
        id = (s16)(D_800A4BB4++ + 0x7F);
        func_8000A920(id, 1);
        xi = (s16)((f32)i * 9.5f + (y + 7.0f));
        func_8000AA04(id, xb, xi);
        if (D_80119858[i] == D_80119878[i]) {
            func_8000AAC0(id, D_80119858[i] * 96.0f * 0.125f, 0.625f);
            func_8000AB24(id, 0x32, 0xFF, 0xFF, alpha);
        } else if (D_80119858[i] < D_80119878[i]) {
            func_8000AAC0(id, D_80119858[i] * 96.0f * 0.125f, 0.625f);
            func_8000AB24(id, 0x32, 0xFF, 0xFF, alpha);
            id = (s16)(D_800A4BB4++ + 0x7F);
            func_8000A920(id, 1);
            func_8000AA04(id, D_80119858[i] * 96.0f + (x + 67.0f), xi);
            func_8000AAC0(id, (D_80119878[i] - D_80119858[i]) * 96.0f * 0.125f, 0.625f);
            func_8000AB24(id, 0xA3, 0xBE, 0x11,
                          (u32)((((f32)func_80082BE0() / (f32)2147483648.0) * 155.0f + 100.0f) * scale));
        } else {
            func_8000AAC0(id, D_80119878[i] * 96.0f * 0.125f, 0.625f);
            func_8000AB24(id, 0x32, 0xFF, 0xFF, alpha);
            id = (s16)(D_800A4BB4++ + 0x7F);
            func_8000A920(id, 1);
            func_8000AA04(id, D_80119878[i] * 96.0f + (x + 67.0f), xi);
            func_8000AAC0(id, (D_80119858[i] - D_80119878[i]) * 96.0f * 0.125f, 0.625f);
            func_8000AB24(id, 0xFF, 0x64, 0x64,
                          (u32)((((f32)func_80082BE0() / (f32)2147483648.0) * 155.0f + 100.0f) * scale));
            if (arg0[2] == 8) {
                func_8000AB24(id, 0xA3, 0xBE, 0x11, alpha);
            }
        }
    }
}
