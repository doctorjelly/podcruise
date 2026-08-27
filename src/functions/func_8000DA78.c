/* Recovered from specification specs/func_8000DA78.md (controller-pak slot browser overlay). */
#include "podcruise/types.h"

extern s32 D_8009B7D4;
extern s32 D_8009B7D8;
extern s32 D_8009B7DC;
extern s32 D_8009B7E8;
extern s32 D_8009B7F4[];
extern s32 D_8009B800;
extern s32 D_8009B808;
extern s32 D_8009B80C;
extern const char D_800A8528[];
extern const char D_800A8530[];
extern const char D_800A853C[];
extern const char D_800A8548[];
extern const char D_800A854C[];
extern const char D_800A8554[];
extern const char D_800A855C[];
extern f64 D_800A8660;
extern s32 D_800D5710;
extern s32 D_800D5714;
extern s32 D_800D7700;

extern void func_80008B14(s32, s32, f32, f32, s32);
extern void func_8000C658(void);
extern s32 func_8000D89C(s32, char *, u8 *, s32 *, f32 *);
extern void func_8000D90C(s32, f32);
extern void func_8000D960(s32);
extern f32 func_8002F060(void);
extern void func_8002F144(void);
extern void func_8003EC40(s32, s32, s32, s32, s32, s32, char *);
extern void func_8003EDD4(s32, s32, s32, s32, s32, s32, char *);
extern s32 func_80053220(s32);
extern s32 func_80082BE0(void);
extern void func_8008A6B4(char *, const char *, ...);

void func_8000DA78(void) {
    char sp2DC[256];
    char sp1DC[256];
    char sp19C[64];
    u8 sp9C[256];
    f32 sp98;
    s32 sp94;
    f32 value;
    f32 pulse;
    f32 red;
    f32 blue;
    f32 green;
    s32 index;
    s32 base;
    s32 x;
    s32 y;

    if (D_8009B7E8 != 0) {
        D_800D5714 = D_800D5714 - 1;
        if (D_800D5714 > 0) {
            return;
        }
        D_800D5714 = 10;
        D_800D5710 = D_800D5710 + 1;
        if (D_800D5710 < 4) {
            return;
        }
        D_8009B7E8 = 0;
        return;
    }

    if (D_8009B800 != 2) {
        if (D_8009B80C == 0) { D_8009B808 = 1; }
    }

    value = func_8002F060();
    pulse = (f32)((f64)((f32)func_80082BE0() / (f32)2147483648.0) * 0.25 + 0.75);

    if (D_8009B7D8 & 1) {
        if (D_8009B7D4 <= 0) {
            if (D_800D7700 != 0) {
                if ((D_8009B7D4 == 0) && (D_800D7700 == 0x1000)) {
                    D_8009B7D4 = -1;
                } else if ((D_8009B7D4 == -1) && (D_800D7700 == 0x800)) {
                    D_8009B7D4 = -2;
                } else if ((D_8009B7D4 == -2) && (D_800D7700 == 0x2000)) {
                    D_8009B7D4 = -3;
                } else if ((D_8009B7D4 == -3) && (D_800D7700 == 0x400)) {
                    D_8009B7D4 = 1;
                } else {
                    D_8009B7D4 = 0;
                }
            }
        }
    }

    red = 1.0f;
    if (red <= value) {
        if (D_8009B800 == 2) {
            if (func_80053220(0x4000) != 0) {
                D_8009B7DC = D_8009B7DC - 1;
                if (D_8009B7DC < 0) {
                    D_8009B7DC = 0;
                } else {
                    func_80008B14(0x55, 6, 0.25f, red, 0);
                }
            }
            if (func_80053220(0x8000) != 0) {
                D_8009B7DC = D_8009B7DC + 1;
                if (func_8000D89C(D_8009B7DC, sp19C, sp9C, &sp94, &sp98) == 0) {
                    D_8009B7DC = D_8009B7DC - 1;
                } else {
                    func_80008B14(0x55, 6, 0.25f, red, 0);
                }
            }
            if (func_80053220(1) != 0) {
                func_8000D960(D_8009B7DC);
            }
            if (func_80053220(0x200) != 0) {
                func_8000D960(D_8009B7DC);
            }
        } else {
            if ((D_800D7700 & 4) || (D_800D7700 & 0x4000)) {
                D_8009B7DC = D_8009B7DC - 1;
                if (D_8009B7DC < 0) {
                    D_8009B7DC = 0;
                    if (func_8000D89C(0, sp19C, sp9C, &sp94, &sp98) != 0) {
                        do {
                            D_8009B7DC = D_8009B7DC + 1;
                        } while (func_8000D89C(D_8009B7DC, sp19C, sp9C, &sp94, &sp98) != 0);
                    }
                    D_8009B7DC = D_8009B7DC - 1;
                }
            }
            if ((D_800D7700 & 8) || (D_800D7700 & 0x8000)) {
                D_8009B7DC = D_8009B7DC + 1;
                if (func_8000D89C(D_8009B7DC, sp19C, sp9C, &sp94, &sp98) == 0) {
                    D_8009B7DC = 0;
                }
            }
            if (D_800D7700 & 0x20) {
                func_8000D90C(D_8009B7DC, red);
            }
            if (D_800D7700 & 0x10) {
                func_8000D90C(D_8009B7DC, -1.0f);
            }
            if (D_800D7700 & 0x1000) {
                func_8000D90C(D_8009B7DC, -1.0f);
            }
            if ((D_800D7700 & 0x2000) || (D_800D7700 & 1)) {
                func_8000D90C(D_8009B7DC, red);
            }
            if (D_800D7700 & 0x400) {
                func_8000D90C(D_8009B7DC, 10.0f);
            }
            if (D_800D7700 & 0x800) {
                func_8000D90C(D_8009B7DC, -10.0f);
            }
            if (D_800D7700 & 1) {
                func_8000D960(D_8009B7DC);
            }
            if (D_800D7700 & 0x200) {
                func_8002F144();
            }
            if (D_800D7700 & 2) {
                func_8000C658();
            }
        }
    }

    for (index = 0; index != 0x18; index++) {
        if (func_8000D89C(index, sp19C, sp9C, &sp94, &sp98) == 0) {
            continue;
        }
        base = index * 14;
        red = 255.0f;
        blue = 255.0f;
        if ((f64)sp98 < D_800A8660) {
            if (sp94 < -9999) {
                func_8008A6B4(sp1DC, D_800A8528, sp19C);
                goto laid_out;
            }
        }
        if (D_800A8660 < (f64)sp98) {
            func_8008A6B4(sp1DC, D_800A8530, sp19C, (f64)sp98);
        } else {
            func_8008A6B4(sp1DC, D_800A853C, sp19C, sp94);
        }
laid_out:
        if (index < 12) {
            y = base + 0x14;
            x = 0x19;
        } else {
            y = base - 0x78;
            x = 0xA5;
        }
        if (index == D_8009B7DC) {
            red = 0.0f;
            blue = 55.0f;
        }
        if (D_8009B800 == 2) {
            x = 0xA0;
            if (D_8009B7D4 > 0) {
                y = (index * 4 - index) * 4 + 0x42;
            } else {
                y = index * 16 + index + 0x42;
            }
            value = func_8002F060();
            if (0.0f < value) {
                if (index == D_8009B7DC) {
                    red = 255.0f * pulse;
                    green = 250.0f * pulse;
                    blue = 50.0f * pulse;
                } else {
                    red = 170.0f;
                    green = 160.0f;
                    blue = 0.0f;
                }
                func_8008A6B4(sp2DC, D_800A8548, sp1DC);
                func_8003EDD4(0xA0, (s16)y, (u8)(u32)red, (u8)(u32)green,
                              (s32)(u32)blue, (s32)(u32)(255.0f * value), sp2DC);
            }
        } else {
            green = 255.0f;
            func_8008A6B4(sp2DC, D_800A854C, sp1DC, (u8)(u32)green);
            func_8003EC40((s16)x, (s16)y, (u8)(u32)red, (u8)(u32)green,
                          (s32)(u32)blue, (u8)(u32)green, sp2DC);
            if (index == D_8009B7DC) {
                if (sp9C[0] != 0) {
                    func_8008A6B4(sp2DC, D_800A8554, sp9C);
                    func_8003EC40((s16)(x + 0x82), (s16)(y - 0x1E), 0, 255, 0x80,
                                  255, sp2DC);
                }
            }
        }
        if (index == D_8009B7DC) {
            if (sp9C[0] != 0) {
                func_8008A6B4(sp2DC, D_800A855C, sp9C);
                func_8003EC40((s16)(x + 0x82), (s16)(y - 0x1E), 0, 255, 0x80, 255,
                              sp2DC);
            }
        }
    }

    D_8009B7F4[D_8009B800] = D_8009B7DC;
}
