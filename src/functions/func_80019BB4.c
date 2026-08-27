/* Recovered from specification specs/func_80019BB4.md (credits/attract overlay tick). */
#include "podcruise/types.h"

typedef struct Owner {
    u8 pad0[0x68];
    s32 unk68;
} Owner;

extern s32 D_80000300;
extern u32 D_80000318;
extern s16 D_80114470[2];
extern s32 D_800A4BBC;
extern u8 D_800A2374;
extern f32 D_800A2378;
extern f32 D_800A237C;
extern u8 D_800A2380;
extern s32 D_800A2384;
extern s32 D_800A2198;
extern s32 D_800A4BDC;
extern s32 D_800D697C;
extern f32 D_800A4B50;
extern f32 D_80120BF8;
extern f32 D_800A9B40;

extern const char D_800A8820[];
extern const char D_800A8838[];
extern const char D_800A8850[];
extern const char D_800A8874[];
extern const char D_800A88A0[];
extern const char D_800A88D4[];
extern const char D_800A88F4[];
extern const char D_800A891C[];
extern const char D_800A8940[];
extern const char D_800A8960[];
extern const char D_800A897C[];
extern const char D_800A8998[];
extern const char D_800A89B4[];

extern void func_8003ECB0(s16 column, s16 row, const char *text);
extern void func_8003EC40(s16 arg0, s16 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, const char *arg6);
extern void func_80008B14(s32 arg0, s16 arg1, f32 arg2, f32 arg3, s32 arg4);
extern s32 func_8002E8D4(s32 index);
extern void func_8000AAC0(s16 index, f32 x, f32 y);
extern void func_8000AA04(s16 index, s16 x, s16 y);
extern void func_8000A920(s16 index, s32 flag);
extern void func_8000AB24(s16 index, u8 red, u8 green, u8 blue, u8 alpha);
extern void func_800469B4(void *arg0, s32 arg1);

void func_80019BB4(Owner *owner) {
    s32 state;
    s32 phase;
    s32 row;
    u8 alpha;
    s32 count;

    if (D_80000300 == 0) {
        func_8003ECB0(D_80114470[0] / 2, D_80114470[1] / 2, D_800A8820);
        return;
    }

    if (D_800A4BBC != 0) {
        D_800A4BBC = 0;
        D_800A2374++;
        if (D_800A2374 == 2) {
            func_80008B14(0x74, 6, 0.25f, 0.5f, 0);
            D_800A2378 = 2.5f;
        }
        D_800A237C = 255.0f;
    }

    if (((D_800D697C & 0x1000) != 0) || (func_8002E8D4(0) == 0)) {
        alpha = (u32)(D_800A4B50 * 5.0f);
        func_8003EC40(0xA0, 0xB4, 0xFF, alpha, alpha % 256, 0xFF, D_800A8838);
        func_8000AAC0(0x4D, 1.0f, 1.0f);
        func_8000AA04(0x4D, 0x57, 0x2E);
        func_8000A920(0x4D, 1);
        return;
    }

    phase = D_800A2374;
    switch (phase) {
    case 0:
        count = D_800A2384;
        if (count > 0) {
            D_800A2384 = count - 1;
        } else {
            func_8003ECB0(0x1E, 0x1E, D_800A8850);
            row = 0x32;
            func_8003ECB0(0x1E, row, D_800A8874);
            row += 10;
            func_8003ECB0(0x1E, row, D_800A88A0);
            row += 10;
            func_8003ECB0(0x1E, row, D_800A88D4);
            row += 20;
            func_8003ECB0(0x1E, row, D_800A88F4);
            row += 10;
            func_8003ECB0(0x1E, row, D_800A891C);
            row += 10;
            func_8003ECB0(0x1E, row, D_800A8940);
            row += 20;
            func_8003ECB0(0x1E, row, D_800A8960);
            row += 40;
            if (D_80000318 < 0x800000) {
                row += 10;
                func_8003ECB0(0x1E, row, D_800A8998);
                row += 10;
                func_8003ECB0(0x1E, row, D_800A89B4);
            } else {
                row += 10;
                func_8003ECB0(0x1E, row, D_800A897C);
            }
            func_8000AA04(0x4F, 0xB4, 0x64);
            func_8000AAC0(0x4F, 1.0f, 1.0f);
            func_8000A920(0x4F, 1);
        }
        break;
    case 1:
        func_8000AA04(0x4D, 0x57, 0x2E);
        func_8000AAC0(0x4D, 1.0f, 1.0f);
        func_8000A920(0x4D, 1);
        break;
    case 2:
        if ((D_800A4BDC != 1) || (D_800A2380 != 0)) {
            D_800A237C = D_800A237C - (255.0f * D_80120BF8);
            if (D_800A237C < 0.0f) {
                D_800A237C = 0.0f;
                if (D_800A2380 != 0) {
                    func_8000AB24(-0x67, 0, 0, 0, 0xFF);
                    func_800469B4(owner, D_800A2198);
                    return;
                }
            }
        }
        func_8000AA04(0x53, 0x34, 0);
        func_8000AAC0(0x53, 1.0f, 1.0f);
        if (D_800A2380 == 0) {
            func_8000A920(0x53, 1);
        }
        func_8000AB24(0x53, 0xFF, 0xFF, 0xFF, (u32)D_800A237C);
        if (D_800A4BDC != 1) {
            func_8000AA04(0x52, 0x52, 0xF);
            func_8000AAC0(0x52, 1.0f, 1.0f);
            func_8000A920(0x52, 1);
            if (D_800A2380 != 0) {
                func_8000AB24(0x52, 0xFF, 0xFF, 0xFF, (u32)D_800A237C);
            } else {
                func_8000AB24(0x52, 0xFF, 0xFF, 0xFF, 0xFF);
            }
        }
        break;
    }
    state = D_800A4BDC;

    if (state == 0) {
        if (D_800A2378 > 0.0f) {
            D_800A2378 = D_800A2378 - D_80120BF8;
        }
    }
    if (D_800A2378 <= 0.0f) {
        D_800A2378 = D_800A9B40;
        phase = D_800A2374;
        if (phase < 2) {
            D_800A4BDC = -1;
        } else {
            D_800A2380 = 1;
            D_800A237C = 255.0f;
        }
        switch (phase) {
        case 0:
            D_800A2198 = 0;
            break;
        case 1:
            D_800A2198 = 0;
            break;
        case 2:
            D_800A2198 = 0xE;
            owner->unk68 = 0xF;
            break;
        }
    }
}
