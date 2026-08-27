/* Independently written from scratchpad spec specs/func_80029D38.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 unk00;
    /* 0x01 */ u8 unk01;
    /* 0x02 */ u8 unk02;
    /* 0x03 */ u8 unk03;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s32 unk0C;
} Rec16;

extern void func_8000A920(s16, s32);
extern void func_8000AA04(s16, s16, s16);
extern void func_8000AB24(s16, s32, s32, s32, s32);
extern void func_8002BBA4(void *, s32, s32, s32, s32, s32, u8 *);
extern void func_8002D4C4(s32);
extern void func_8003EC40(s16, s16, u8, u8, u8, u8, u8 *);
extern void func_80047A78(void *, s32, s32, f32, f32, f32, f32);
extern void func_8004A36C(s32, f32, f32, f32);
extern s32 func_8008A6B4(char *, const char *, ...);

extern s32 D_800A21A4;
extern Rec16 D_800A2DE0[];
extern s32 D_800A4BA4[];
extern s32 D_800A4BC4;
extern s32 D_800A4BEC;
extern char D_800A96BC[];
extern char D_800A96C8[];
extern char D_800A96D0[];
extern char D_800A96D8[];
extern char D_800A96E4[];
extern char D_800A96F0[];
extern char D_800A96F8[];
extern char D_800A9700[];
extern char D_800A9708[];
extern char D_800A9710[];
extern char D_800A9718[];
extern char D_800A9720[];
extern char D_800A9728[];
extern char D_800A9730[];
extern char D_800A9738[];
extern char D_800A9744[];
extern char D_800A9750[];
extern f32 D_800A9E0C;
extern f32 D_800A9E10;
extern f64 D_800A9E18;
extern f32 D_800D6CC0;
extern s16 D_800D6CC4;
extern s32 D_800D6CC8[];
extern s32 D_800D6CCC;
extern s32 D_80113E78;
extern u8 D_80113E84[];
extern s8 D_801198A8[];
extern s8 D_8011A050[];
extern s32 D_8011A270;

void func_80029D38(void *arg0) {
    char buf[48];
    char buf2[32];
    f32 shade;
    s32 base;
    s32 row;
    s32 yA;
    s32 yB;
    s32 i;
    s32 av;

    if (D_800A21A4 == 0) {
        if (D_800A4BEC == 0) {
            return;
        }
    }
    if (D_800A4BC4 == 0) {
        return;
    }

    av = 0xFE;
    base = (s16)(D_800D6CC0 - 3.0f);
    func_8000AB24(0x78, 0xA3, 0xBE, 0x11, av);
    func_8000A920(0x78, 1);
    func_8000AA04(0x78, 0x1E, base);
    func_8000AB24(0x75, 0x32, 0xFF, 0xFF, av);
    func_8000A920(0x75, 1);
    func_8000AA04(0x75, 0x22, base + 4);
    func_8008A6B4(buf, D_800A96BC,
                  D_800A2DE0[D_801198A8[D_8011A270 * 0x38]].unk0C);
    func_8003EC40(0x56, base + 6, 0x32, 0xFF, 0xFF, av, (u8 *)buf);
    func_8000AB24(0x7D, 0x32, 0xFF, 0xFF, av);
    func_8000A920(0x7D, 1);
    func_8000AA04(0x7D, 0x21, base + 0x13);
    shade = (f32)av;
    func_80047A78(arg0, 0x88, base + 0x11,
                  (f32)(u32) * (u8 *)&D_801198A8[D_8011A270 * 0x38 + 1] * D_800A9E0C,
                  shade, 10.0f, 41.0f);
    func_8000AB24(0x76, 0x32, 0xFF, 0xFF, av);
    func_8000A920(0x76, 1);
    func_8000AA04(0x76, 0x2A, base + 0x10);
    yA = (s16)(base + 0x12);
    func_8003EC40(0x2C, yA, 0x32, 0xFF, 0xFF, av, (u8 *)D_800A96C8);
    func_8008A6B4(buf, D_800A96D0, D_800D6CCC);
    func_8003EC40(0x87, yA, 0x32, 0xFF, 0xFF, av, (u8 *)buf);
    func_8000AB24(0x77, 0x32, 0xFF, 0xFF, av);
    func_8000A920(0x77, 1);
    func_8000AA04(0x77, 0x29, base + 0x1B);

    base = (s16)(D_800D6CC0 - 5.0f);
    func_8000AB24(0x7C, 0xA3, 0xBE, 0x11, av);
    func_8000A920(0x7C, 1);
    func_8000AA04(0x7C, 0xAE, base);
    func_8000AB24(0x7A, 0x32, 0xFF, 0xFF, av);
    func_8000A920(0x7A, 1);
    func_8000AA04(0x7A, 0xB3, base + 5);
    func_8003EC40(0xB6, base + 6, 0x32, 0xFF, 0xFF, av, (u8 *)D_800A96D8);
    func_8000AB24(0x7E, 0x32, 0xFF, 0xFF, av);
    func_8000A920(0x7E, 1);
    func_8000AA04(0x7E, 0xB2, base + 0x14);
    func_8000AB24(0x79, 0x32, 0xFF, 0xFF, av);
    func_8000A920(0x79, 1);
    func_8000AA04(0x79, 0xBE, base + 0x17);

    row = D_800A2DE0[D_801198A8[D_8011A270 * 0x38]].unk03;
    func_8008A6B4(buf, D_800A96E4, D_800A2DE0[D_8011A050[row * 0x38]].unk0C);
    func_8003EC40(0xEE, base + 0x1A, 0x32, 0xFF, 0xFF, av, (u8 *)buf);
    func_8000AB24(0x7B, 0x32, 0xFF, 0xFF, av);
    func_8000A920(0x7B, 1);
    func_8000AA04(0x7B, 0xD6, base + 0x28);
    func_80047A78(arg0, 0xFF, base + 0x30,
                  (f32)(u32)D_80113E84[row] * D_800A9E10, shade, 7.0f, 26.0f);

    i = 0;
    yA = base + 0x5D;
    yB = base + 0x7C;
    do {
        func_8000AB24((s16)(i + 0x73), 0x32, 0xFF, 0xFF, av);
        func_8000A920((s16)(i + 0x73), 1);
        func_8000AA04((s16)(i + 0x73), 0xC2, yA);
        func_8000AB24((s16)(i + 0x71), 0x32, 0xFF, 0xFF, av);
        func_8000A920((s16)(i + 0x71), 1);
        func_8000AA04((s16)(i + 0x71), 0xDB, yB);
        yA += 0xB;
        yB += 0xD;
        i++;
    } while (i < 2);

    func_8008A6B4(buf, D_800A96F0, D_800A96F8);
    yA = (s16)(base + 0x60);
    func_8003EC40(0xC4, yA, 0x32, 0xFF, 0xFF, av, (u8 *)buf);
    func_8008A6B4(buf, D_800A9700, D_800A9708);
    yB = (s16)(base + 0x6B);
    func_8003EC40(0xC4, yB, 0x32, 0xFF, 0xFF, av, (u8 *)buf);
    func_8008A6B4(buf, D_800A9710, D_800D6CC8[0]);
    func_8008A6B4(buf2, D_800A9718, buf);
    func_8003EC40(0x114, yA, 0x32, 0xFF, 0xFF, av, (u8 *)buf2);
    func_8008A6B4(buf, D_800A9720, D_800D6CCC - D_800D6CC8[0]);
    func_8008A6B4(buf2, D_800A9728, buf);
    func_8003EC40(0x114, yB, 0x32, 0xFF, 0xFF, av, (u8 *)buf2);

    if (D_80113E78 < D_800D6CCC - D_800D6CC8[0]) {
        D_800D6CC4 = 1;
    }
    yA = base + 0x7E;
    func_8002BBA4(arg0, 0xFC, yA, 0xD, D_800D6CC4, 0, (u8 *)D_800A9730);
    func_8002BBA4(arg0, 0xFC, yA, 0xD, D_800D6CC4, 1, (u8 *)D_800A9738);
    func_8003EC40(av, base + 0xA5, 0xA3, 0xBE, 0x11, av, (u8 *)D_800A9744);
    func_8004A36C(0, 5.0f,
                  (f32)((f64)(-6.0f + D_800D6CC0) - D_800A9E18), 1.0f);
    func_8008A6B4(buf, D_800A9750, D_80113E78);
    yA = (s16)(base + 0xB4);
    func_8003EC40(0x122, yA, 0x32, 0xFF, 0xFF, av, (u8 *)buf);
    if (D_80113E78 < D_800D6CCC - D_800D6CC8[0]) {
        func_8003EC40(0x122, yA, 0xFF, 0, 0, av, (u8 *)buf);
    }

    for (i = 0; i != 1; i++) {
        if (D_800A21A4 != 0) {
            if ((D_800A4BA4[i] & 0x8000) || (D_800A4BA4[i] & 0x4000)) {
                if (D_80113E78 < D_800D6CCC - D_800D6CC8[0]) {
                    func_8002D4C4(0x4B);
                } else {
                    D_800D6CC4 = D_800D6CC4 == 0;
                    func_8002D4C4(0x57);
                }
            }
        }
    }
}
