/* specification: specs/func_80055D38.md */
#include "podcruise/types.h"

extern void func_8000A920(s16, s16);
extern void func_8000AA04(s16, s16, s16);
extern void func_8000AB24(s16, s32, s32, s32, s32);
extern s32 func_8002F054(void);
extern void func_8003EC40(s32, s32, s32, s32, s32, s32, u8 *);
extern void func_80055AEC(s32, f32);
extern void func_8006E2FC(u8 *, u8 *, u8 *, f32 *);
extern s32 func_80082BE0(void);
extern void func_8008A6B4(u8 *, u8 *, u8 *);

extern s32 D_800A26F4;
extern s32 D_800A52BC;
extern s32 D_800A59B4;
extern u8 D_800ACC70[];
extern u8 D_800ACC78[];
extern f32 D_800ACED4;
extern f32 D_800ACED8;
extern f64 D_80120BF0;

void func_80055D38(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 id;
    s32 x;
    s32 y;
    s16 alpha;
    f32 f1;
    f32 f2;
    f32 v;
    u8 buf[260];
    u8 colorA[4];
    u8 colorB[4];
    f32 result;

    if (arg4 == 0) {
        id = 0x11;
    } else {
        id = 0x15;
    }

    x = arg2;
    if (D_800A52BC >= 2) {
        x = arg2 + 0x1F;
    }

    func_8000A920(id, 1);
    func_8000AA04(id, x, arg3);
    func_8000AB24(id, 0x59, 0x8C, 0x36, 0xFE);

    if (func_8002F054() == 0) {
        if (*(s32 *)(arg1 + 0x60) & 0x200000) {
            *(f32 *)(arg0 + arg4 * 4 + 0x1D8) =
                (f32)((f64)*(f32 *)(arg0 + arg4 * 4 + 0x1D8) + D_80120BF0 * 4.0);
            if (*(f32 *)(arg0 + arg4 * 4 + 0x1D8) > 1.0f) {
                *(f32 *)(arg0 + arg4 * 4 + 0x1D8) = 1.0f;
            }
        } else {
            *(f32 *)(arg0 + arg4 * 4 + 0x1D8) =
                (f32)((f64)*(f32 *)(arg0 + arg4 * 4 + 0x1D8) - D_80120BF0 * 4.0);
            if (*(f32 *)(arg0 + arg4 * 4 + 0x1D8) < 0.0f) {
                *(f32 *)(arg0 + arg4 * 4 + 0x1D8) = 0.0f;
            }
        }
    }

    v = *(f32 *)(arg0 + arg4 * 4 + 0x1D8);
    if (D_800A26F4 == 0) {
        result = ((f32)func_80082BE0() / 2147483648.0f) * (v * D_800ACED4 - v) + v;
    } else {
        result = ((v * D_800ACED8) * 3.0f + v) * 0.25f;
    }

    func_8000A920(0xE, 0);

    if (*(s32 *)(arg1 + 0x60) & 0x800000) {
        colorA[0] = 0xFF;
        colorA[1] = 0;
        colorA[2] = 0;
        colorB[0] = 0;
        colorB[1] = 0xFF;
        colorB[2] = 0;
        colorB[3] = 0xE6;
        f1 = 1.0f;
        alpha = result * 255.0f;
    } else {
        if (arg4 == 0) {
            func_8000A920(0x10, 0);
        } else {
            func_8000A920(0x14, 0);
        }
        alpha = result * 255.0f;
        func_8006E2FC(arg1, colorA, colorB, &f1);
    }

    if (D_800A52BC >= 2) {
        alpha = (s16)(result * 255.0f) * 2.5f;
        if (alpha >= 0x100) {
            alpha = 0xFF;
        }
    }

    if (arg4 == 0) {
        id = 0x12;
    } else {
        id = 0x16;
    }
    x = arg2 + 0x18;
    y = arg3 - 7;
    func_8000A920(id, 1);
    func_8000AA04(id, x, y);
    func_8000AB24(id, colorA[0], colorA[1], colorA[2], (u8)alpha);

    if ((D_800A52BC < 2) && (*(s32 *)(arg0 + 0x1AC) == 0) && (*(s32 *)(arg0 + 0x1C0) == 0) &&
        (colorA[0] >= 0x79) && (colorA[1] >= 0x79) && (colorA[2] < 0x78) &&
        (func_8002F054() == 0) && (((++D_800A59B4) & 1) != 0)) {
        func_8000A920(0xE, 1);
        func_8000AA04(0xE, 0xF7, 0xA9);
        func_8000AB24(0xE, 0xFF, 0xFF, 0xFF, (u32)(alpha * 0.5));
        func_8008A6B4(buf, D_800ACC70, D_800ACC78);
        func_8003EC40(0xF4, 0xA2, 0xFF, 0xFF,
                      (u32)((f32)func_80082BE0() / 2147483648.0f * 255.0f), (u8)alpha, buf);
    }

    if (arg4 == 0) {
        id = 0xF;
    } else {
        id = 0x13;
    }
    x = arg2 + 0x22;
    y = arg3 + 6;
    func_8000A920(id, 1);
    func_8000AA04(id, x, y);
    func_8000AB24(id, colorB[0], colorB[1], colorB[2], colorB[3]);
    func_80055AEC(id, f1);

    if (arg4 == 0) {
        id = 0x10;
    } else {
        id = 0x14;
    }
    if (*(s32 *)(arg1 + 0x60) & 0x800000) {
        f2 = 1.0f - *(f32 *)(arg1 + 0x218) / 100.0f;
        func_8000A920(id, 1);
        func_8000AA04(id, x, y);
        func_8000AB24(id, 0xFF, 0xFF, 0xFF, 0xFF);
        func_80055AEC(id, f2);
    } else {
        func_8000A920(id, 0);
    }
}
