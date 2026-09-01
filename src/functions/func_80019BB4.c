/* Recovered from specification specs/func_80019BB4.md (scratchpad). */
#include "podcruise/types.h"

typedef struct Controller80019BB4 {
    u8 pad[0x68];
    s32 state;
} Controller80019BB4;

extern s32 D_80000300;
extern u32 D_80000318;
extern s32 D_800A2198;
extern u8 D_800A2374;
extern f32 D_800A2378;
extern f32 D_800A237C;
extern u8 D_800A2380;
extern s32 D_800A2384;
extern f32 D_800A4B50;
extern s32 D_800A4BBC;
extern s32 D_800A4BDC;
extern f32 D_800A9B40;
extern s32 D_800D697C;
extern f32 D_80120BF8;
extern s16 D_80114470[];
extern u8 D_800A8820[];
extern u8 D_800A8838[];
extern u8 D_800A8850[];
extern u8 D_800A8874[];
extern u8 D_800A88A0[];
extern u8 D_800A88D4[];
extern u8 D_800A88F4[];
extern u8 D_800A891C[];
extern u8 D_800A8940[];
extern u8 D_800A8960[];
extern u8 D_800A897C[];
extern u8 D_800A8998[];
extern u8 D_800A89B4[];

extern void func_80008B14(s32, s32, f32, f32, s32);
extern void func_8000A920(s32, s32);
extern void func_8000AA04(s32, s32, s32);
extern void func_8000AAC0(s32, f32, f32);
extern void func_8000AB24(s32, s32, s32, s32, s32);
extern s32 func_8002E8D4(s32);
extern void func_8003EC40(s16, s16, u8, u8, u8, u8, const u8 *);
extern void func_8003ECB0(s16, s16, const u8 *);
extern void func_800469B4(Controller80019BB4 *, s32);

void func_80019BB4(Controller80019BB4 *controller) {
    s32 mode;
    u8 raw;
    s32 y;
    f32 fade;


    if (D_80000300 == 0) {
        func_8003ECB0(D_80114470[0] / 2, D_80114470[1] / 2, D_800A8820);
    } else {
        if (D_800A4BBC != 0) {
            D_800A4BBC = 0;
            D_800A2374++;
            if (D_800A2374 == 2) {
                func_80008B14(0x74, 6, 0.25f, 0.5f, 0);
                D_800A2378 = 2.5f;
            }
            D_800A237C = 255.0f;
        }

        if ((D_800D697C & 0x1000) != 0 || func_8002E8D4(0) == 0) {
            raw = (u32)(D_800A4B50 * 5.0f);
            func_8003EC40(0xA0, 0xB4, 0xFF, raw % 0x100, raw % 0x100, 0xFF, D_800A8838);
            func_8000AAC0(0x4D, 1.0f, 1.0f);
            func_8000AA04(0x4D, 0x57, 0x2E);
            func_8000A920(0x4D, 1);
            return;
        } else {
            switch (D_800A2374) {
            case 0:
                if (D_800A2384 > 0) {
                    D_800A2384--;
                } else {
                    y = 0x1E;
                    func_8003ECB0(0x1E, y, D_800A8850);
                    y += 0x14;
                    func_8003ECB0(0x1E, y, D_800A8874);
                    y += 0xA;
                    func_8003ECB0(0x1E, y, D_800A88A0);
                    y += 0xA;
                    func_8003ECB0(0x1E, y, D_800A88D4);
                    y += 0x14;
                    func_8003ECB0(0x1E, y, D_800A88F4);
                    y += 0xA;
                    func_8003ECB0(0x1E, y, D_800A891C);
                    y += 0xA;
                    func_8003ECB0(0x1E, y, D_800A8940);
                    y += 0x14;
                    func_8003ECB0(0x1E, y, D_800A8960);
                    y += 0x28;
                    if (D_80000318 >= 0x800000) {
                        y += 0xA;
                        func_8003ECB0(0x1E, y, D_800A897C);
                    } else {
                        y += 0xA;
                        func_8003ECB0(0x1E, y, D_800A8998);
                        y += 0xA;
                        func_8003ECB0(0x1E, y, D_800A89B4);
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
                if (D_800A4BDC != 1 || D_800A2380 != 0) {
                    fade = D_800A237C - 255.0f * D_80120BF8;
                    D_800A237C = fade;
                    if (fade < 0.0f) {
                        D_800A237C = 0.0f;
                        if (D_800A2380 != 0) {
                            func_8000AB24(-0x67, 0, 0, 0, 0xFF);
                            func_800469B4(controller, D_800A2198);
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
                        func_8000AB24(0x52, 0xFF, 0xFF, 0xFF,
                                      (u32)D_800A237C);
                    } else {
                        func_8000AB24(0x52, 0xFF, 0xFF, 0xFF, 0xFF);
                    }
                }
                break;
            }
        }

        mode = D_800A4BDC;
        if (mode == 0) {
            if (D_800A2378 > 0.0f) {
                D_800A2378 = D_800A2378 - D_80120BF8;
            }
        }
        if (D_800A2378 <= 0.0f) {
            D_800A2378 = D_800A9B40;
            mode = D_800A2374;
            if (mode < 2) {
                D_800A4BDC = -1;
            } else {
                D_800A2380 = 1;
                D_800A237C = 255.0f;
            }
            if (mode == 0) {
                D_800A2198 = 0;
            } else if (mode == 1) {
                D_800A2198 = 0;
            } else if (mode == 2) {
                D_800A2198 = 0xE;
                controller->state = 0xF;
            }
        }
    }
}
