/* Recovered per specs/functions/recovered/func_80025148.md. */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s8 unk08;
    /* 0x09 */ s8 unk09;
    /* 0x0A */ s8 unk0A;
    /* 0x0B */ u8 pad0B;
} Entry80025148;

typedef struct {
    /* 0x00 */ u8 pad00[0x14];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
} Meta80025148;

typedef struct {
    /* 0x00 */ u8 pad00[0x18];
    /* 0x18 */ s32 unk18;
} State80025148;

typedef struct {
    /* 0x00 */ u8 pad00[0x0C];
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ u8 pad10[0x5D - 0x10];
    /* 0x5D */ s8 unk5D;
    /* 0x5E */ s8 unk5E;
    /* 0x5F */ u8 pad5F[0x64 - 0x5F];
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s8 unk6C;
    /* 0x6D */ s8 unk6D;
    /* 0x6E */ s8 unk6E;
    /* 0x6F */ u8 pad6F;
    /* 0x70 */ s8 unk70;
    /* 0x71 */ u8 unk71;
    /* 0x72 */ u8 pad72[0x8E - 0x72];
    /* 0x8E */ s8 unk8E;
    /* 0x8F */ s8 unk8F;
    /* 0x90 */ s8 unk90;
} Menu80025148;

extern Entry80025148 D_800A21B8[];
extern s32 D_800A2570;
extern s32 D_800A2574;
extern u8 D_800A2578;
extern u8 D_800A257C;
extern u8 D_800A2580;
extern Meta80025148 D_800A31E0[];
extern u32 D_800A4BA4;
extern u32 D_800A4BA8;
extern s32 D_800A4BBC;
extern char D_800A9034[];
extern char D_800A9044[];
extern char D_800A904C[];
extern char D_800A9058[];
extern char D_800A9064[];
extern char D_800A9074[];
extern char D_800A908C[];
extern char D_800A909C[];
extern char D_800A90A8[];
extern char D_800A90B4[];
extern char D_800A90C0[];
extern char D_800A90CC[];
extern char D_800A90D8[];
extern char D_800A90E0[];
extern char D_800A90EC[];
extern char D_800A90F4[];
extern char D_800A90FC[];
extern char D_800A910C[];
extern char D_800A9118[];
extern char D_800A9128[];
extern char D_800A9134[];
extern char D_800A9144[];
extern char D_800A9154[];
extern char D_800A915C[];
extern char D_800A9168[];
extern char D_800A9174[];
extern char D_800A917C[];
extern char D_800A918C[];
extern char D_800A91AC[];
extern char D_800A91B4[];
extern char D_800A91C4[];
extern char D_800A91D4[];
extern char D_800A91EC[];
extern char D_800A91FC[];
extern char D_800A9228[];
extern f32 D_800A9D34;
extern f32 D_800A9D38;
extern f32 D_800A9D3C;
extern f32 D_800A9D40;
extern u8 D_800D73E8[];
extern u8 D_80113680[];
extern State80025148 D_80119640;
extern f32 D_8011A240;
extern s32 D_8011A270;

extern void func_8000A920(s16, s32);
extern void func_8000AA04(s16, s16, s16);
extern void func_8000AAC0(s16, f32, f32);
extern void func_8000AB24(s16, u8, u8, u8, u8);
extern s32 func_800129B8();
extern void func_80024704(Menu80025148 *);
extern void func_80024874(Menu80025148 *);
extern void func_8002BBA4(Menu80025148 *, s32, s32, s32, s32, s32,
                          const char *);
extern void func_8002CC28(s32, s32, s32);
extern void func_8002D048();
extern void func_8002D4C4(s32);
extern s32 func_8002D598(s8);
extern u8 func_8002D9D0(s8, s32);
extern s32 func_8002DA0C(s8, u8);
extern s32 func_8002DB20(Menu80025148 *, s32);
extern s32 func_8002DC7C(Menu80025148 *);
extern void func_8003EC40(s16, s16, u8, u8, u8, u8, const void *);
extern void func_800469B4(Menu80025148 *, s32);
extern void func_800494D0(Menu80025148 *, s32, f32);
extern void func_80049C14(Menu80025148 *, s32, f32);
extern void func_8004BAC8(Menu80025148 *, s32);
extern void func_800503E8(Menu80025148 *, s32, s32, s32);
extern f32 func_80064A88(f32);
extern s32 func_80082BE0(void);
extern s32 func_8008A6B4(char *, const char *, ...);

#define RANDOM_UNIT() ((f32)func_80082BE0() / 2147483648.0f)

void func_80025148(Menu80025148 *menu) {
    Entry80025148 *entry;
    Meta80025148 *meta;
    u8 *valueBase;
    char message[84];
    u32 input;
    s32 row;
    s32 option;
    s32 optionType;
    s32 count;
    s32 width;
    s32 value;
    s32 item;
    s32 red;
    s32 green;
    s32 blue;
    s16 sprite;
    u8 raceCount;
    u8 metaIndex;

    if (D_800A2578 == 0) {
        D_800A2578 = 0xC;
    }
    if (D_800A257C == 0) {
        D_800A257C = 2;
    }

    if (D_800A4BBC != 0) {
        D_800A4BBC = 0;
        func_800503E8(menu, 0x25, -1, 0);
        D_800A2570 = 0;
        D_800A2574 = 0;
        if (menu->unk0C == 0xC) {
            D_8011A240 = 1.0f;
        }
        func_80024704(menu);
        if (menu->unk0C != 0xC) {
            func_80024874(menu);
        }

        for (D_800A2580 = 0; D_800A2580 < 0xC; D_800A2580++) {
            D_800D73E8[D_800A2580] = 0xFF;
        }
        D_800A2580 = 0;
        if (func_8002DC7C(menu) != 0) {
            D_800D73E8[0] = 0;
            D_800A2580 = 1;
        }
        if (menu->unk6C != 0) {
            value = func_8002DB20(menu, D_8011A270);
            if (func_8002DA0C(menu->unk5E, (u8)value) != 0) {
                D_800D73E8[D_800A2580++] = 1;
            }
        } else {
            D_800D73E8[D_800A2580++] = 2;
            if (menu->unk6D == 0) {
                D_800D73E8[D_800A2580++] = 3;
                D_800D73E8[D_800A2580++] = 4;
            }
        }
    }

    value = func_8002DB20(menu, D_8011A270);
    raceCount = func_8002D9D0(menu->unk5E, value & 0xFF);

    row = 0xA0;
    if (D_800A2574 == 0) {
        for (option = 0; option < D_800A2580; option++) {
            optionType = D_800D73E8[option];
            switch (optionType) {
            case 0:
                func_8002BBA4(menu, 0x1E, row, 0xA, D_800A2570,
                              option, D_800A9034);
                func_8002BBA4(menu, 0x55, row, 0xA, D_800A2570,
                              option,
                              menu->unk6E != 0 ? D_800A9044 : D_800A904C);
                break;
            case 1:
                if (menu->unk90 == 1) {
                    func_8008A6B4(message, D_800A9058);
                } else if (menu->unk90 == 2) {
                    func_8008A6B4(message, D_800A9064);
                } else {
                    func_8008A6B4(message, D_800A9074);
                }
                func_8002BBA4(menu, 0x1E, row, 0xA, D_800A2570,
                              option, D_800A908C);
                func_8002BBA4(menu, 0x55, row, 0xA, D_800A2570,
                              option, message);
                func_8002BBA4(menu, 0x2D, row + 0xA, 0xA,
                              D_800A2570, option, D_800A909C);
                func_8002BBA4(menu, 0x2D, row + 0x14, 0xA,
                              D_800A2570, option, D_800A90A8);
                func_8002BBA4(menu, 0x2D, row + 0x1E, 0xA,
                              D_800A2570, option, D_800A90B4);
                if (raceCount == 4) {
                    func_8002BBA4(menu, 0x2D, row + 0x28, 0xA,
                                  D_800A2570, option, D_800A90C0);
                }
                for (item = 0; item < raceCount; item++) {
                    value = *(s16 *)((u8 *)menu + 0x8A + menu->unk90 * 8 +
                                     item * 2);
                    value = (s32)((f64)value +
                                  (f64)value * 0.5 * (f64)menu->unk5E);
                    func_8008A6B4(message, D_800A90CC, value);
                    func_8002BBA4(menu, 0x69, row + 0xA + item * 0xA,
                                  0xA, D_800A2570, option, message);
                }
                break;
            case 2:
                func_8008A6B4(message, D_800A90D8, menu->unk8E);
                func_8002BBA4(menu, 0x1E, row, 0xA, D_800A2570,
                              option, D_800A90E0);
                func_8002BBA4(menu, 0x55, row, 0xA, D_800A2570,
                              option, message);
                break;
            case 3:
                func_8008A6B4(message, D_800A90EC, D_800A2578);
                if (menu->unk70 >= 2) {
                    func_8008A6B4(message, D_800A90F4, D_800A257C);
                }
                func_8002BBA4(menu, 0x1E, row, 0xA, D_800A2570,
                              option, D_800A90FC);
                func_8002BBA4(menu, 0x55, row, 0xA, D_800A2570,
                              option, message);
                break;
            case 4:
                if (menu->unk8F == 1) {
                    func_8008A6B4(message, D_800A910C);
                } else if (menu->unk8F == 2) {
                    func_8008A6B4(message, D_800A9118);
                } else {
                    func_8008A6B4(message, D_800A9128);
                }
                func_8002BBA4(menu, 0x1E, row, 0xA, D_800A2570,
                              option, D_800A9134);
                func_8002BBA4(menu, 0x55, row, 0xA, D_800A2570,
                              option, message);
                break;
            case 5:
                row += 0xA;
                func_8002BBA4(menu, 0x1E, row, 0xA, D_800A2570,
                              option, D_800A9144);
                func_8002BBA4(menu, 0x55, row, 0xA, D_800A2570,
                              option,
                              menu->unk64 != 0 ? D_800A9154 : D_800A915C);
                break;
            case 6:
                if (menu->unk68 < 0) {
                    func_8008A6B4(message, D_800A9168);
                } else {
                    func_8008A6B4(message, D_800A9174,
                                  menu->unk68 + 1);
                }
                func_8002BBA4(menu, 0x1E, row, 0xA, D_800A2570,
                              option, D_800A917C);
                func_8002BBA4(menu, 0x55, row, 0xA, D_800A2570,
                              option, message);
                break;
            }
        }
    }

    func_80064A88(D_800A2574 != 0 ? D_800A9D34 : D_800A9D38);
    if (D_8011A240 > 0.0f) {
        entry = &D_800A21B8[menu->unk5D];
        func_800494D0(menu, entry->unk09,
                      (f32)((f64)D_8011A240 * 0.5));
    }
    if (D_800A2574 == 0) {
        func_80049C14(menu, menu->unk5D, 0.5f);
    }

    if (D_800A2574 == 0) {
        entry = &D_800A21B8[menu->unk5D];
        if (entry->unk00 == -1 || entry->unk04 == -1) {
            func_8008A6B4(message, D_800A918C);
            red = (s32)(RANDOM_UNIT() * 256.0f) & 0xFF;
            green = (s32)(RANDOM_UNIT() * 256.0f) & 0xFF;
            blue = (s32)(RANDOM_UNIT() * 256.0f);
            func_8003EC40(0xA0, 0xCD, red, green, blue, 0xFF, message);
        }

        func_8008A6B4(message, D_800A91AC, func_8002D598(menu->unk5D));
        func_8003EC40(0xA0, 0x25, 0, 0xFF, 0, 0xFF, message);
        width = func_800129B8(message, 0);
        func_8002CC28((s32)(160.0 - (f64)width * 0.5), 0x26,
                      func_800129B8(message, 0));

        /* The old-style call keeps these f32 bits in a3 and permits the
           canonical, ignored seventh word. */
        entry = &D_800A21B8[menu->unk5D];
        func_8002D048(menu, 0x64, 0x37, 0x437F0000, entry->unk08, 0,
                      entry->unk09);
        entry = &D_800A21B8[menu->unk5D];
        func_8002D048(menu, 0xDC, 0x37, 0x437F0000, entry->unk08, 3,
                      entry->unk09);

        valueBase = D_80113680 + menu->unk5D * 8 + menu->unk6E * 4;
        if (*(f32 *)(valueBase + 0xC4) < D_800A9D3C) {
            metaIndex = D_80113680[0x380 + menu->unk5D * 2 + menu->unk6E];
            meta = &D_800A31E0[metaIndex];
            func_8008A6B4(message, D_800A91B4, meta->unk14, meta->unk18);
            func_8003EC40(0x64, 0x46, 0xA3, 0xBE, 0x11, 0xFF, message);
            sprite = (s16)(metaIndex + 0x17);
            func_8000A920(sprite, 1);
            func_8000AA04(sprite, 0x54, 0x4D);
            func_8000AAC0(sprite, 0.5f, 0.5f);
            func_8000AB24(sprite, 0xFF, 0xFF, 0xFF, 0xFF);
        }

        valueBase = D_80113680 + menu->unk5D * 8 + menu->unk6E * 4;
        if (*(f32 *)(valueBase + 0x18C) < D_800A9D40) {
            metaIndex = D_80113680[0x3B2 + menu->unk5D * 2 + menu->unk6E];
            meta = &D_800A31E0[metaIndex];
            func_8008A6B4(message, D_800A91C4, meta->unk14, meta->unk18);
            func_8003EC40(0xDC, 0x46, 0xA3, 0xBE, 0x11, 0xFF, message);
            sprite = (s16)(metaIndex + 0x2E);
            func_8000A920(sprite, 1);
            func_8000AA04(sprite, 0xCC, 0x4D);
            func_8000AAC0(sprite, 0.5f, 0.5f);
            func_8000AB24(sprite, 0xFF, 0xFF, 0xFF, 0xFF);
        }

        entry = &D_800A21B8[menu->unk5D];
        metaIndex = entry->unk0A;
        func_8003EC40(0xF0, 0x82, 0x32, 0xFF, 0xFF, 0xFF,
                      D_800A91D4);
        meta = &D_800A31E0[metaIndex];
        func_8008A6B4(message, D_800A91EC, meta->unk14, meta->unk18);
        func_8003EC40(0xF0, 0x89, 0xA3, 0xBE, 0x11, 0xFF, message);
        func_8000A920((s16)metaIndex, 1);
        func_8000AA04((s16)metaIndex, 0xD0, 0x91);
        func_8000AAC0((s16)metaIndex, 1.0f, 1.0f);
        func_8000AB24((s16)metaIndex, 0xFF, 0xFF, 0xFF, 0xFF);

        if (menu->unk6C != 0) {
            value = func_8002DB20(menu, D_8011A270);
            if (func_8002DA0C(menu->unk5E, (u8)value) != 0) {
                func_8003EC40(0xA0, 0x73, 0xA3, 0xBE, 0x11, 0xFF,
                              raceCount == 3 ? D_800A91FC : D_800A9228);
            }
        }

        if (D_8011A240 >= 1.0f) {
            input = D_800A4BA4;
            if ((input & 1) && D_80119640.unk18 == 0) {
                func_8002D4C4(0x55);
                if (menu->unk6C != 0) {
                    menu->unk71 = 0xC;
                } else if (menu->unk6D != 0) {
                    menu->unk71 = 1;
                } else if (menu->unk70 >= 2) {
                    menu->unk71 = D_800A257C;
                } else if (menu->unk64 != 0 && D_800A2578 == 2) {
                    menu->unk71 = 1;
                } else {
                    menu->unk71 = D_800A2578;
                }
                func_8004BAC8(menu, 0);
                func_800503E8(menu, 0x24, 3, 0);
                D_800A2574 = 1;
                return;
            }
            if ((input & 2) && !(input & 1) && D_80119640.unk18 == 0) {
                func_8002D4C4(0x4D);
                func_8004BAC8(menu, 0);
                func_800469B4(menu, 0xC);
                return;
            }

            count = D_800A2580;
            if (count >= 2) {
                if (input & 0x4000) {
                    D_800A2570--;
                    func_8002D4C4(0x57);
                }
                if (D_800A4BA4 & 0x8000) {
                    D_800A2570++;
                    func_8002D4C4(0x57);
                }
                if (D_800A2570 < 0) {
                    D_800A2570 = count - 1;
                }
                if (count - 1 < D_800A2570) {
                    D_800A2570 = 0;
                }
            }

            if (count > 0) {
                optionType = D_800D73E8[D_800A2570];
                if (D_800A4BA4 & 0x20000) {
                    switch (optionType) {
                    case 0: menu->unk6E = menu->unk6E == 0; break;
                    case 1: menu->unk90++; break;
                    case 2: menu->unk8E++; break;
                    case 3:
                        if (menu->unk70 < 2) {
                            if (D_800A2578 == 8) {
                                D_800A2578 = 0xC;
                            } else if (D_800A2578 == 0xC) {
                                D_800A2578 = 2;
                            } else {
                                D_800A2578 *= 2;
                            }
                        } else {
                            D_800A257C += 2;
                            if (D_800A257C == 8) {
                                D_800A257C = 2;
                            }
                        }
                        break;
                    case 4: menu->unk8F++; break;
                    case 5: menu->unk64 = menu->unk64 == 0; break;
                    case 6: menu->unk68++; break;
                    }
                    func_8002D4C4(0x57);
                }
                if (D_800A4BA4 & 0x10000) {
                    switch (optionType) {
                    case 0: menu->unk6E = menu->unk6E == 0; break;
                    case 1: menu->unk90--; break;
                    case 2: menu->unk8E--; break;
                    case 3:
                        if (menu->unk70 < 2) {
                            if (D_800A2578 == 0xC) {
                                D_800A2578 = 8;
                            } else if (D_800A2578 == 2) {
                                D_800A2578 = 0xC;
                            } else {
                                D_800A2578 >>= 1;
                            }
                        } else {
                            D_800A257C -= 2;
                            if (D_800A257C == 0) {
                                D_800A257C = 6;
                            }
                        }
                        break;
                    case 4: menu->unk8F--; break;
                    case 5: menu->unk64 = menu->unk64 == 0; break;
                    case 6: menu->unk68--; break;
                    }
                    func_8002D4C4(0x57);
                }
            }

            if (menu->unk8E <= 0) menu->unk8E = 5;
            if (menu->unk8E >= 6) menu->unk8E = 1;
            if (menu->unk8F <= 0) menu->unk8F = 3;
            if (menu->unk8F >= 4) menu->unk8F = 1;
            if (menu->unk90 <= 0) menu->unk90 = 3;
            if (menu->unk90 >= 4) menu->unk90 = 1;
            if (menu->unk68 < -1) menu->unk68 = 0x14;
            if (menu->unk68 >= 0x15) menu->unk68 = -1;
        }
    }

    (void)D_800A4BA8;
}

#undef RANDOM_UNIT
