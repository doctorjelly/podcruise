/* Independently written from scratchpad spec specs/func_8002A7D4.md. */
#include "podcruise/types.h"

extern void func_8000A920(s16 index, s32 flag);
extern void func_8000AA04(s16 index, s16 x, s16 y);
extern void func_8000AB24(s16 index, u8 red, u8 green, u8 blue, u8 alpha);
extern void func_8002BBA4(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                          s32 arg5, void *arg6);
extern void func_8002D4C4(s32 arg0);
extern void func_8003EC40(s16 arg0, s16 arg1, u8 arg2, u8 arg3, u8 arg4,
                          u8 arg5, void *arg6);
extern void func_8004A36C(s32 index, f32 spread, f32 lift, f32 scale);
extern s32 func_8008A6B4(char *buffer, const char *format, ...);

extern s32 D_800A4BA4[];
extern s16 D_800A4BC0;
extern char D_800A975C[];
extern char D_800A9770[];
extern char D_800A9790[];
extern char D_800A97B0[];
extern char D_800A97D4[];
extern char D_800A97DC[];
extern char D_800A97E4[];
extern char D_800A97EC[];
extern char D_800A97F4[];
extern char D_800A97FC[];
extern char D_800A9808[];
extern char D_800A9814[];
extern f64 D_800A9E20;
extern f32 D_800D6CC0;
extern s16 D_800D6CC4;
extern s32 D_80113E60[];

void func_8002A7D4(s8 *arg0) {
    char text[48];
    char line[32];
    s32 base;
    s32 y;
    s32 column;
    s32 span;
    s16 row;
    s32 i;

    base = (s16)(s32)(D_800D6CC0 - 5.0f);

    func_8000AB24(0x7C, 0xA3, 0xBE, 0x11, 0xFE);
    func_8000A920(0x7C, 1);
    func_8000AA04(0x7C, 0xAE, base);

    func_8000AB24(0x7E, 0x32, 0xFF, 0xFF, 0xFE);
    func_8000A920(0x7E, 1);
    func_8000AA04(0x7E, 0xB2, base + 0x14);

    func_8000AB24(0x79, 0x32, 0xFF, 0xFF, 0xFE);
    func_8000A920(0x79, 1);
    func_8000AA04(0x79, 0xBE, base + 0x17);

    func_8003EC40(0xC1, base + 0x1A, 0x32, 0xFF, 0xFF, 0xFE, D_800A975C);
    func_8003EC40(0x63, base + 0x1E, 0x32, 0xFF, 0xFF, 0xFF, D_800A9770);
    func_8003EC40(0x63, base + 0x26, 0x32, 0xFF, 0xFF, 0xFF, D_800A9790);
    func_8003EC40(0x63, base + 0x2E, 0x32, 0xFF, 0xFF, 0xFF, D_800A97B0);

    func_8000AB24(0x73, 0x32, 0xFF, 0xFF, 0xFE);
    func_8000A920(0x73, 1);
    func_8000AA04(0x73, 0xC2, base + 0x68);

    func_8008A6B4(text, D_800A97D4, 1000);
    func_8008A6B4(line, D_800A97DC, text);

    y = (s16)(base + 0x6B);
    func_8003EC40(0x114, y, 0x32, 0xFF, 0xFF, 0xFE, line);

    for (i = 0, span = base + 0x7C; i < 2; i++) {
        row = i + 0x71;
        func_8000AB24(row, 0x32, 0xFF, 0xFF, 0xFE);
        func_8000A920(row, 1);
        func_8000AA04(row, 0xDB, span);
        span += 0xD;
    }

    func_8008A6B4(text, D_800A97E4, D_800A97EC);
    func_8003EC40(0xC4, y, 0x32, 0xFF, 0xFF, 0xFE, text);

    column = base + 0x7E;
    func_8002BBA4(arg0, 0xFC, column, 0xD, D_800D6CC4, 0, D_800A97F4);
    func_8002BBA4(arg0, 0xFC, column, 0xD, D_800D6CC4, 1, D_800A97FC);

    func_8003EC40(0xFE, base + 0xA5, 0xA3, 0xBE, 0x11, 0xFE, D_800A9808);

    if (D_800D6CC0 == 20.0f) {
        if (D_800A4BC0 != 1) {
            func_8004A36C(0, 5.0f, (-6.0f + D_800D6CC0) - D_800A9E20, 1.0f);
        }
    }

    func_8008A6B4(text, D_800A9814, D_80113E60[6]);

    row = base + 0xB4;
    func_8003EC40(0x122, row, 0x32, 0xFF, 0xFF, 0xFE, text);
    if (D_80113E60[6] < 1000) {
        func_8003EC40(0x122, row, 0xFF, 0, 0, 0xFE, text);
    }

    for (i = 0; i < arg0[0x70]; i++) {
        if ((D_800A4BA4[i] & 0x8000) || (D_800A4BA4[i] & 0x4000)) {
            if (D_80113E60[6] >= 1000) {
                D_800D6CC4 = !D_800D6CC4;
                func_8002D4C4(0x57);
            } else {
                func_8002D4C4(0x4B);
            }
        }
    }

    if (D_80113E60[6] < 1000) {
        D_800D6CC4 = 1;
    }
}
