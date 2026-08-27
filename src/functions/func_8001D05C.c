/* Recovered from specification specs/func_8001D05C.md (name-entry screen update). */
#include "podcruise/types.h"

#define BS(p, off) (*(s8 *)((u8 *)(p) + (off)))
#define BW(p, off) (*(s32 *)((u8 *)(p) + (off)))

extern s32 D_8009B7D0;
extern u32 D_8009B7D8;
extern s32 D_800A23C4;
extern s32 D_800A23C8;
extern u8 D_800A23CC[];
extern char D_800A2508[];
extern s32 D_800A2514;
extern f32 D_800A2518;
extern s32 D_800A4BA4[];
extern s32 D_800A4BBC;
extern s32 D_800A4BDC;
extern const char D_800A8C08[];
extern const char D_800A8C0C[];
extern const char D_800A8C1C[];
extern const char D_800A8C28[];
extern const char D_800A8C34[];
extern const char D_800A8C3C[];
extern const char D_800A8C5C[];
extern const char D_800A8C70[];
extern const char D_800A8C7C[];
extern const char D_800A8C8C[];
extern const char D_800A8C98[];
extern f32 D_800A9BDC;
extern char D_800D73F8[];
extern s32 D_800D76F0;
extern s32 D_800D7700;
extern u8 D_80113E60[];
extern s32 D_80113E78;
extern f32 D_80118D20[4][4];
extern s32 D_8011A240[];
extern s32 D_8011A26C;
extern s32 D_8011A270;
extern void *D_8011A544;
extern f32 D_80120BF8;

extern void func_80015268(f32 *, f32, f32, f32);
extern void func_80015288(f32 *, f32 *);
extern void func_80015328(f32 *, f32 *, f32 *);
extern void func_800156DC(f32 (*)[4], f32 (*)[4]);
extern void func_80016BF4(f32 *, f32 *, f32 (*)[4]);
extern void func_800178C4(f32 (*)[4], f32 (*)[4], f32, f32, f32, f32);
extern void func_80018480(void *, f32 (*)[4], s32, f32, f32, f32, f32, s32, f32,
                          f32);
extern void func_8002D4C4(s32);
extern s32 func_8002D968(const char *, const char *);
extern void func_80033C70(void);
extern void func_80033D30(void);
extern void func_80039984(s32, s32);
extern void func_800399F0(void);
extern void func_8003E1EC(const char *, f32);
extern void func_8003EC40(s32, s32, s32, s32, s32, s32, const char *);
extern void func_8003ECB0(s32, s32, const char *);
extern void func_800469B4(void *, s32);
extern s32 func_80064B44(s32, f32, s32);
extern s32 func_80082BE0(void);
extern void func_8008A6B4(char *, const char *, ...);

void func_8001D05C(void *arg) {
    char text[28] = "                 ";
    f32 point[3];
    f32 view[4][4];
    f32 place[4][4];
    s32 key;
    s32 selection;
    u32 bits;
    u32 previous;
    s32 found;
    s32 slot;
    s32 letter;
    s32 column;
    s32 index;
    s32 x;
    s32 offset;
    s32 red;
    s32 green;
    s32 blue;
    u8 *record;
    f32 shade;

    if (D_800D76F0 & 0x100) {
        if (D_800D7700 & 0x40) {
            key = D_8011A240[12] - 0x1B;
            if (key != -1) {
                if (key < 0) {
                    key += 0x1B;
                }
            }
            if (key == -1) {
                selection = D_800A23C4;
                bits = D_8009B7D8;
                previous = bits;
                if ((selection == 0xC) || (selection == 0x50)) {
                    bits = bits | 3;
                    D_8009B7D8 = bits;
                }
                if ((selection == 0x11) || (selection == 0x50)) {
                    bits = bits | 1;
                    D_8009B7D8 = bits;
                }
                if ((selection == 0x15) || (selection == 0x50)) {
                    bits = bits | 5;
                    D_8009B7D8 = bits;
                }
                if ((selection == 0x1E) || (selection == 0x50)) {
                    bits = bits | 9;
                    D_8009B7D8 = bits;
                }
                if ((selection == 0x26) || (selection == 0x50)) {
                    bits = bits | 0x11;
                    D_8009B7D8 = bits;
                }
                if ((selection == 0x2E) || (selection == 0x50)) {
                    bits = bits | 0x21;
                    D_8009B7D8 = bits;
                }
                if ((selection == 0x34) || (selection == 0x50)) {
                    bits = bits | 0x40;
                    D_8009B7D8 = bits;
                }
                if ((selection == 0x3B) || (selection == 0x50)) {
                    bits = bits | 0x80;
                    D_8009B7D8 = bits;
                }
                if ((selection == 0x40) || (selection == 0x50)) {
                    bits = bits | 0x101;
                    D_8009B7D8 = bits;
                }
                if ((selection == 0x44) || (selection == 0x50)) {
                    bits = bits | 0x201;
                    D_8009B7D8 = bits;
                }
                if ((selection == 0x55) || (selection == 0x50)) {
                    bits = bits | 0x800;
                    D_8009B7D8 = bits;
                }
                if ((selection == 0x5A) || (selection == 0x50)) {
                    bits = bits | 0x1000;
                    D_8009B7D8 = bits;
                }
                if ((selection == 0x5F) || (selection == 0x50)) {
                    bits = bits | 0x2000;
                    D_8009B7D8 = bits;
                }
                if ((selection == 0x65) || (selection == 0x50)) {
                    bits = bits | 0x4000;
                    D_8009B7D8 = bits;
                }
                if (selection == 0x68) {
                    bits = bits | 0x2000000;
                    D_8009B7D8 = bits;
                }
                if (previous != bits) {
                    func_8002D4C4(0x4B);
                    func_8003E1EC(D_800A8C08, 2.0f);
                    D_800A23C8 = 0;
                    D_800A23C4 = 0;
                }
            } else {
                found = 0;
                if (0xFF != D_800A23CC[0]) {
                    record = &D_800A23CC[0];
                    letter = record[0];
                    do {
                        if (D_800A23C4 != letter) {
                            found++;
                        } else if (key != record[1]) {
                            found++;
                        } else {
                            D_800A23C4 = record[2];
                            found = -1;
                        }
                        if (found < 0) {
                            break;
                        }
                        record = &D_800A23CC[found * 3];
                        letter = record[0];
                    } while (0xFF != letter);
                }
                if (found != -1) {
                    D_800A23C4 = 0;
                }
                if (D_800A23C8 < 0x1E) {
                    D_800D73F8[D_800A23C8] = key + 0x41;
                    D_800A23C8 = D_800A23C8 + 1;
                    D_800D73F8[D_800A23C8] = 0;
                    func_8002D4C4(0x55);
                    func_8003E1EC(D_800D73F8, 1.0f);
                }
            }
        }
    }

    if (D_800A4BBC != 0) {
        D_800A4BBC = 0;
        for (index = 0; index < 3; index++) {
            D_800A2508[index] = 0;
        }
        D_8011A240[12] = 0x1B;
        D_8011A240[11] = 0x36;
    }

    if (BS(arg, 0x70) >= 2) {
        func_8008A6B4(text, D_800A8C0C, BS(arg, 0x6F) + 1);
        func_8003ECB0(0xA0, 0x37, text);
    }
    slot = D_8011A240[12];
    if (slot < 0xD) {
        slot += 0x1B;
        D_8011A240[12] = slot;
    }
    if (slot >= 0x29) {
        slot -= 0x1B;
        D_8011A240[12] = slot;
    }
    letter = slot;
    if (slot >= 0x1B) {
        letter = slot - 0x1B;
    }

    index = 0;
    if (D_8011A240[11] > 0) {
        offset = 0;
        do {
            column = D_8011A270;
            x = (s16)((0xA0 - (column * 4 + column) * 4) + offset);
            if (x < 0xA0) {
                shade = 255.0f - ((f32)(0xA0 - x) + (f32)(0xA0 - x));
            } else {
                shade = 255.0f - ((f32)(x - 0xA0) + (f32)(x - 0xA0));
            }
            if (((f64)shade < 0.0) || (D_800A2514 == 2)) {
                shade = 0.0f;
            }
            if (index < 0x1A) {
                func_8008A6B4(text, D_800A8C1C, index + 0x41);
            } else if ((index >= 0x1B) && (index < 0x35)) {
                func_8008A6B4(text, D_800A8C28, index + 0x26);
            } else {
                func_8008A6B4(text, D_800A8C34, index + 0x41);
                x = (s16)(x + 3);
            }
            if (index == D_8011A270) {
                func_8003EC40((s16)x, 0x64, 0xA3, 0xBE, 0x11, (s32)(u32)shade,
                              text);
            } else {
                func_8003EC40((s16)x, 0x64, 0x32, 0xFF, 0xFF, (s32)(u32)shade,
                              text);
            }
            index++;
            offset += 0x14;
        } while (index < D_8011A26C);
    }

    func_8003EC40(0xA0, 0x19, 0x32, 0xFF, 0xFF, 0xFF, D_800A8C3C);
    if (BW(arg, 0xC) == 5) {
        func_8003ECB0(0xA0, 0xC8, D_800A8C5C);
    }
    func_8008A6B4(text, D_800A8C70, D_800A2508);
    if (D_800A4BDC == -1) {
        record = &D_80113E60[BS(arg, 0x6F) * 0x2C];
        func_8008A6B4(text, D_800A8C7C, record[0], record[1], record[2]);
    }
    func_8003EC40(0x9B, 0x82, 0xA3, 0xBE, 0x11, 0xFF, text);

    if (D_8011A544 != 0) {
        D_800A2518 = (f32)((f64)D_800A2518 - 30.0 * (f64)D_80120BF8);
        if (D_800A2518 < -360.0f) {
            D_800A2518 = D_800A2518 + 360.0f;
        }
        func_800156DC(view, D_80118D20);
        func_800156DC(place, view);
        func_80015268(point, 0.0f, 600.0f, -60.0f);
        func_80016BF4(point, point, view);
        func_800178C4(place, place, D_800A2518, view[2][0], view[2][1],
                      view[2][2]);
        func_80015328(place[3], place[3], point);
        func_80015288(place[3], point);
        func_80018480(D_8011A544, place, 1, 14.0f, 14.0f, 14.0f, D_800A9BDC, 0,
                      1.0f, 1.0f);
    }

    if (D_800A2514 == 2) {
        red = func_80082BE0();
        green = func_80082BE0();
        blue = func_80082BE0();
        func_8003EC40(0xA5, 0x64,
                      (u8)((s32)((f32)red / 2147483648.0f * 129.0f) + 0x40),
                      (u8)((s32)((f32)green / 2147483648.0f * 129.0f) + 0x40),
                      (s32)((f32)blue / 2147483648.0f * 129.0f) + 0x40, 0xFF,
                      D_800A8C8C);
    } else {
        func_80064B44(BS(arg, 0x6F), 2.0f, 0);
    }

    if (D_800A4BA4[BS(arg, 0x6F)] & 1) {
        if (D_8009B7D8 & 0x1000) {
            func_80033C70();
        }
        if (D_8009B7D8 & 0x800) {
            func_80033D30();
        }
        if (D_800A2514 == -1) {
            if (letter == 0x1A) {
                func_8002D4C4(0x4B);
                return;
            }
        }
        func_8002D4C4(0x55);
        slot = D_800A2514 + 1;
        if (slot < 3) {
            if (letter < 0x1A) {
                D_800A2508[slot] = letter + 0x41;
            }
        }
        D_800A2514 = slot;
        if ((slot == 3) || (letter == 0x1A)) {
            for (index = 0; index < 3; index++) {
                D_80113E60[BS(arg, 0x6F) * 0x2C + index] = D_800A2508[index];
            }
            if (D_8009B7D0 > 0) {
                if (func_8002D968(D_800A2508, D_800A8C98) != 0) {
                    *(s32 *)((u8 *)&D_80113E78 + BS(arg, 0x6F) * 0x2C) = 0x2710;
                }
            }
            if (BW(arg, 0xC) == 9) {
                D_80113E60[BS(arg, 0x6F) * 0x2C + 7] = 0;
            }
            record = &D_80113E60[BS(arg, 0x6F) * 0x2C];
            if (record[4] == 1) {
                func_80039984(record[5], BS(arg, 0x6F));
            }
            func_800399F0();
            for (index = 0; index < 3; index++) {
                D_800A2508[index] = 0;
            }
            D_800A23C8 = 0;
            D_800A23C4 = 0;
            D_800A2514 = -1;
            func_800469B4(arg, BW(arg, 0xC));
            return;
        }
    }

    if (D_800A4BA4[BS(arg, 0x6F)] & 2) {
        func_8002D4C4(0x4D);
        slot = D_800A2514;
        if (slot >= 0) {
            D_800A2508[slot] = 0;
            D_800A2514 = slot - 1;
        } else {
            D_800A23C8 = 0;
            if (BW(arg, 0xC) == 9) {
                BW(arg, 0x10) = 0;
                func_800469B4(arg, 9);
            }
        }
    }
}
