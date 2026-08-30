/* Independently written from specs/functions/recovered/func_8001A408.md. */

#include "podcruise/types.h"

typedef struct Menu8001A408 {
    u8 pad00[0x51];
    u8 compact51;
    u8 pad52[0x12];
    s32 state64;
    u8 pad68[4];
    u8 choice6C;
    u8 choice6D;
    u8 pad6E[2];
    u8 mode70;
} Menu8001A408;

typedef struct Timers8001A408 {
    f32 first;
    f32 second;
    f32 third;
} Timers8001A408;

extern s32 D_8009B7D8;
extern s32 D_800A2198;
extern f32 D_800A22E4;
extern s32 D_800A2388;
extern s8 D_800A238C;
extern u8 D_800A2390;
extern s32 D_800A2394;
extern s32 D_800A497C;
extern u32 D_800A4BA4[];
extern s32 D_800A4BBC;
extern s32 D_800A4BDC;
extern char D_800A89D4[];
extern char D_800A89DC[];
extern char D_800A89E4[];
extern char D_800A89F4[];
extern char D_800A8A04[];
extern char D_800A8A14[];
extern char D_800A8A24[];
extern char D_800A8A2C[];
extern char D_800A8A38[];
extern char D_800A8A40[];
extern char D_800A8A4C[];
extern char D_800A8A54[];
extern s32 D_800D697C;
extern Timers8001A408 D_800D7278;
extern u8 D_800D7390[];
extern f32 D_80120BF8;

extern void func_80009744(s32, u32);
extern void func_8000A920(s32, s32);
extern void func_8000AA04(s32, s32, s32);
extern void func_8000AAC0(s32, f32, f32);
extern void func_8000AB24(s32, s32, s32, s32, s32);
extern void func_800280D8(Menu8001A408 *);
extern void func_8002BBA4(Menu8001A408 *, s32, s32, s32, s32, s32, char *);
extern void func_8002D4C4(s32);
extern s32 func_8002E8D4(s32);
extern void func_80033DC4(void);
extern void func_8003ECB0(s32, s32, char *);
extern void func_8004CA50(Menu8001A408 *);
extern s32 func_8008A6B4(char *, const char *, ...);

void func_8001A408(Menu8001A408 *menu) {
    char text[40];
    f32 base;
    s32 counter;
    s32 index;

    counter = D_800A2394;
    counter++;
    D_800A2394 = counter;
    if (counter >= 31) {
        D_800A2394 = 0;
    }

    if (D_800A2388 == 0) {
        D_800A2388 = 1;
        func_8004CA50(menu);
    }

    if (D_800A4BBC != 0) {
        D_800A4BBC = 0;
        D_800A4BDC = 1;
        func_80033DC4();
        D_800A22E4 = 30.0f;
        D_800D7278.first = 2.0f;
        D_800D7278.second = 1.0f;
        D_800D7278.third = 1.0f;
        D_800A2390 = 0;
        while (D_800A2390 < 12) {
            D_800D7390[D_800A2390] = 0xFF;
            D_800A2390++;
        }
        D_800D7390[0] = 0;
        D_800D7390[1] = 1;
        D_800D7390[2] = 2;
        D_800A2390 = 3;
        if (func_8002E8D4(1) != 0) {
            D_800D7390[D_800A2390] = 3;
            D_800A2390++;
        }
    }

    D_800D7278.first -= D_80120BF8;
    if (D_800D7278.first <= 0.0f) {
        D_800D7278.first = 0.0f;
    }
    if (D_800D7278.first <= 0.0f) {
        D_800D7278.second -= D_80120BF8;
        if (D_800D7278.second <= 0.0f) {
            D_800D7278.second = 0.0f;
        }
    }
    if (D_800D7278.second <= 0.5f) {
        D_800D7278.third -= D_80120BF8 * 5.0f;
        if (D_800D7278.third <= 0.0f) {
            D_800D7278.third = 0.0f;
        }
    }

    if (D_800A4BDC == 0) {
        func_80009744(1, 0);
        D_800A22E4 -= D_80120BF8;
        if (D_800A22E4 <= 0.0f) {
            D_800A22E4 = 30.0f;
            menu->state64 = 2;
            D_800A4BDC = -1;
        }
    }

    func_8000AA04(0x4D, 0, 0);
    func_8000AAC0(0x4D, 0.5f, 1.0f);
    if (menu->compact51 != 0) {
        func_8000AAC0(0x4D, 1.0f, 1.0f);
    }
    func_8000A920(0x4D, 1);
    func_8000AB24(0x4D, 0xFF, 0xFF, 0xFF, 0xFE);

    if (menu->compact51 == 0) {
        base = 18.0f;
        func_8000AA04(0x4F, 0x0C,
                      (s16)(base - D_800D7278.first * 320.0f));
        func_8000A920(0x4F, 1);
        func_8000AB24(0x4F, 0xFF, 0xFF, 0xFF, 0xFE);
        func_8000AA04(0x50, 0x9B,
                      (s16)(base - D_800D7278.first * 320.0f));
        func_8000A920(0x50, 1);
        func_8000AB24(0x50, 0xFF, 0xFF, 0xFF, 0xFE);
        if (D_800D7278.first <= 0.0f) {
            func_8003ECB0(0x122, 0x12, D_800A89D4);
        }

        func_8000AA04(0x4E, 0x0E, 0x33);
        func_8000A920(0x4E, 1);
        func_8000AB24(0x4E, 0xFF, 0xFF, 0xFF,
                      (u32)((1.0f - D_800D7278.second) * 254.0f));

        func_8000AA04(0x51,
                      (s16)(12.0f - D_800D7278.third * 320.0f), 0x46);
        func_8000A920(0x51, 1);
        func_8000AB24(0x51, 0xFF, 0xFF, 0xFF, 0xFE);
        if (D_800D7278.third <= 0.0f) {
            func_8003ECB0(0x122, 0x46, D_800A89DC);
        }
    }

    if (!(D_800D697C & 0x1000)) {
        for (index = 0; index < D_800A2390; index++) {
            switch (D_800D7390[index]) {
                case 0:
                    func_8008A6B4(text, D_800A89E4);
                    break;
                case 1:
                    func_8008A6B4(text, D_800A89F4);
                    break;
                case 2:
                    func_8008A6B4(text, D_800A8A04);
                    break;
                case 3:
                    func_8008A6B4(text, D_800A8A14);
                    break;
                case 4:
                    if (D_800A497C == 0) {
                        func_8008A6B4(text, D_800A8A24, D_800A8A2C);
                    } else if (D_800A497C == 1) {
                        func_8008A6B4(text, D_800A8A38, D_800A8A40);
                    } else if (D_800A497C == 2) {
                        func_8008A6B4(text, D_800A8A4C, D_800A8A54);
                    }
                    break;
            }
            func_8002BBA4(menu, 0xA0, 0xA0, 0x0A, D_800A238C, index,
                          text);
        }
    }

    for (index = 0; index < 2; index++) {
        u32 buttons = D_800A4BA4[index];

        if ((buttons & 1) || (buttons & 0x200)) {
            if (D_800A238C == 3 && func_8002E8D4(1) == 0) {
                func_8002D4C4(0x4B);
                break;
            }
            if (D_800A238C != 3 && index != 0) {
                func_8002D4C4(0x4B);
                break;
            }

            D_800A2198 = 9;
            D_800A2198 = 0x12;
            switch (D_800A238C) {
                case 0:
                    menu->mode70 = 1;
                    menu->choice6C = 1;
                    menu->choice6D = 0;
                    break;
                case 1:
                    menu->mode70 = 1;
                    menu->choice6C = 0;
                    menu->choice6D = 0;
                    break;
                case 2:
                    menu->mode70 = 1;
                    menu->choice6C = 0;
                    menu->choice6D = 1;
                    break;
                case 3:
                    menu->mode70 = 2;
                    menu->choice6C = 0;
                    menu->choice6D = 0;
                    break;
                case 4:
                    D_800A2198 = -1;
                    D_800A497C++;
                    if (D_800A497C >= 3) {
                        D_800A497C = 0;
                    }
                    func_80033DC4();
                    func_8002D4C4(0x57);
                    return;
            }
            func_8002D4C4(0x55);
            D_800A4BDC = -1;
            return;
        }

        if (buttons != 0) {
            D_800A22E4 = 30.0f;
        }
        if (buttons & 0x8000) {
            D_800A238C++;
            if (D_800A238C >= (s32)D_800A2390) {
                D_800A238C = 0;
            }
            func_8002D4C4(0x57);
        }
        if (buttons & 0x4000) {
            D_800A238C--;
            if (D_800A238C < 0) {
                D_800A238C = D_800A2390 - 1;
            }
            func_8002D4C4(0x57);
        }

        if (D_800D7390[D_800A238C] == 4) {
            buttons = D_800A4BA4[index];
            if (buttons & 0x20000) {
                D_800A497C++;
                if (D_800A497C >= 3) {
                    D_800A497C = 0;
                }
                func_80033DC4();
                func_8002D4C4(0x57);
            }
            if (buttons & 0x10000) {
                D_800A497C--;
                if (D_800A497C < 0) {
                    D_800A497C = 2;
                }
                func_80033DC4();
                func_8002D4C4(0x57);
            }
        }
    }

    if ((D_8009B7D8 & 0x40) && (D_800A4BA4[0] & 0x20)) {
        func_800280D8(menu);
    }
}
