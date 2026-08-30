/* Independently written from specs/functions/recovered/func_800573E8.md. */

#include "podcruise/types.h"

extern s32 func_80009134(s32, s32);
extern void func_800092EC(s32, s32, s32);
extern u32 func_80009524(s32, u32);
extern void func_8000953C(s32, u32);
extern void func_8000955C(s32, s32);
extern s32 func_8002F054(void);
extern void func_8003EC40(s16, s16, u8, u8, u8, u8, u8 *);
extern void func_8003F084(s16, s16, f32, u8, u8, u8, u8, void *);
extern s32 func_80051FF4(void);
extern void func_80055D38(u8 *, u8 *, s32, s32, s32);
extern void func_80056844(s32);
extern s32 func_80082BE0(void);
extern s32 func_8008A6B4(char *, const char *, ...);

extern s32 D_8009B7D0;
extern s32 D_800A26F4;
extern s32 D_800A2864;
extern s32 D_800A52BC;
extern char D_800ACC80[];
extern char D_800ACC8C[];
extern char D_800ACC94[];
extern char D_800ACCA4[];
extern char D_800ACCB4[];
extern char D_800ACCC8[];
extern char D_800ACCD0[];
extern char D_800ACCDC[];
extern char D_800ACCE4[];
extern char D_800ACCF4[];
extern char D_800ACCFC[];
extern char D_800ACD04[];
extern char D_800ACD14[];
extern char D_800ACD1C[];
extern f32 D_800ACEE4;
extern f32 D_800ACEE8;
extern f32 D_800ACEEC;
extern f32 D_800ACEF0;
extern u8 *D_8011B1C0;
extern f64 D_80120BF0;

void func_800573E8(u8 *arg0, u8 *arg1) {
    char buf[264];
    f32 value;
    f32 f1D8;
    f32 f1D4;
    char pad2[56];
    s32 s198;
    s32 s194;
    u8 *row;
    s32 s18C;
    char pad4[16];
    s32 s178;
    s32 s174;
    char pad5[16];
    u8 *p160;
    s32 count;
    s32 s158;
    s32 s154;
    s32 s150;
    s32 limit;
    f32 f148;
    f32 f144;
    char pad8[244];
    s32 t38;
    s32 t34;
    s32 t30;
    s32 t2C;

    (void)pad2;
    (void)pad4;
    (void)pad5;
    (void)pad8;
    s158 = 0xA4;
    s154 = func_80051FF4();
    if (arg0 == D_8011B1C0) {
        s150 = 1;
    } else {
        s150 = 0;
    }
    p160 = *(u8 **)(arg0 + 0x84);
    if (func_8002F054() == 0) {
        *(f32 *)(p160 + 0x2B8) =
            (f32)((f64)*(f32 *)(p160 + 0x2B8) - D_80120BF0);
        if (*(f32 *)(p160 + 0x2B8) < 0.0f) {
            *(f32 *)(p160 + 0x2B8) = 0.0f;
        }
    }

    if (*(s32 *)(arg1 + 0x124) == 1) {
        func_80056844(5);
    } else if (*(s32 *)(arg1 + 0x124) == 0) {
        func_80056844(2);
    } else {
        func_80056844(0);
    }

    f1D8 = 254.0f;
    f1D4 = 190.0f;
    if (s154 == 2) {
        f1D8 = f1D8 + 23.0f;
        f1D4 = (f32)(s150 * 110 + 0x60);
    }

    value = *(f32 *)(*(u8 **)(arg0 + 0x84) + 0x1A0);
    if (value <= 0.0f) {
        value = 0.0f;
    }
    func_8008A6B4(buf, D_800ACC80, (f64)value);
    func_8003EC40((s16)f1D8, (s16)f1D4, 0, 0xC3, 0xFE, 0xFE, (u8 *)buf);

    if (*(s32 *)(arg1 + 0x124) == 1) {
        f1D8 = 240.0f;
        f1D4 = 30.0f;
    } else {
        f1D8 = 160.0f;
        f1D4 = 23.0f;
        if (s154 == 2) {
            f1D4 = (f32)(s150 * 110 + 0x14);
        }
    }

    s174 = 0;
    s178 = 0;
    count = *(s32 *)(arg0 + 0x78);
    if (count > 0) {
        row = arg0 + count * 4;
        f148 = *(f32 *)(row + 0x5C);
        f144 = 1.0f - *(f32 *)(row + 0x60) * 0.25f;
        if (0.0f < f144 && f144 < 1.0f) {
            if (D_800A26F4 == 0) {
                t38 = (s32)((f32)func_80082BE0() / (f32)2147483648.0 * 127.0f
                            + 128.0f);
            } else {
                t38 = (s32)D_800ACEE4;
            }
            t30 = (s32)(f144 * 255.0f) * 8;
            if (t30 >= 0x100) {
                t30 = 0xFF;
            }
            t34 = t38 & 0xFF;
            t2C = (s32)((f32)t38 * 0.5f) & 0xFF;
            t30 = t30 & 0xFF;
            t38 = (s16)f1D8;
            func_8003F084((s16)f1D8, (s16)f1D4, f148, (u8)t34, (u8)t2C, 0x40,
                          (u8)t30, D_800ACC8C);
            func_8003EC40(t38, (s16)(f1D4 + 17.0f), (u8)t34, (u8)t2C, 0x40,
                          (u8)t30, (u8 *)D_800ACC94);
            if (f148 <= *(f32 *)(arg1 + 0x1D0)) {
                if (((s32)(f144 * 16.0f) & 1) != 0) {
                    func_8003EC40(t38, (s16)(f1D4 + 25.0f), 0xC8, 0xFF, 0,
                                  (u8)t30, (u8 *)D_800ACCA4);
                    if (func_80009524(*(u8 *)(arg0 + 0x10), 0x100000) == 0) {
                        func_800092EC(6, 0, 0x27);
                        func_8000953C(*(u8 *)(arg0 + 0x10), 0x100000);
                    }
                }
            }
            s174 = 1;
            if (*(s32 *)(arg1 + 0x1C8) == *(s32 *)(arg0 + 0x78) + 1) {
                if (D_800A52BC < 2) {
                    f144 = (f144 - 0.5f) + (f144 - 0.5f);
                    if (0.0f < f144) {
                        t30 = (s32)(f144 * 17.0f) * 4;
                        if (t30 >= 0x100) {
                            t30 = 0xFF;
                        }
                        if (D_800A26F4 == 0) {
                            s18C = t30;
                            t38 = (s32)((f32)func_80082BE0()
                                        / (f32)2147483648.0 * 255.0f);
                            t30 = s18C;
                        } else {
                            t38 = (s32)D_800ACEE8;
                        }
                        if (D_800A26F4 == 0) {
                            s198 = t38;
                            s18C = t30;
                            t2C = (s32)((f32)func_80082BE0()
                                        / (f32)2147483648.0 * 255.0f);
                            t38 = s198;
                            t30 = s18C;
                        } else {
                            t2C = (s32)D_800ACEEC;
                        }
                        if (D_800A26F4 == 0) {
                            s198 = t38;
                            s194 = t2C;
                            s18C = t30;
                            t34 = (s32)((f32)func_80082BE0()
                                        / (f32)2147483648.0 * 255.0f);
                            t38 = s198;
                            t2C = s194;
                            t30 = s18C;
                        } else {
                            t34 = (s32)D_800ACEF0;
                        }
                        func_8003EC40(0xA0, 0x46, (u8)t38, (u8)t2C, (u8)t34,
                                      (u8)t30, (u8 *)D_800ACCB4);
                    }
                } else {
                    if ((s32)(f144 * 36.0f) % 2 != 0) {
                        s178 = 1;
                    }
                }
            }
        } else {
            if (func_80009524(*(u8 *)(arg0 + 0x10), 0x100000) != 0) {
                if (func_80009134(6, 0) == 0) {
                    func_8000955C(*(u8 *)(arg0 + 0x10), 0x100000);
                }
            }
        }
    }

    t34 = (s16)f1D4;
    t30 = (s16)(f1D4 + 17.0f);
    if (s174 == 0 && s154 < 2) {
        t38 = (s16)f1D8;
        func_8003F084((s16)f1D8, (s16)t34, *(f32 *)(arg0 + 0x74), 0xFF, 0xFF,
                      0xFF, 0xBE, D_800ACCC8);
        func_8003EC40(t38, (s16)t30, 0xFF, 0xFF, 0xFF, 0xBE,
                      (u8 *)D_800ACCD0);
    }

    if (*(s32 *)(arg1 + 0x124) == 6 || *(s32 *)(arg1 + 0x124) == 7) {
        func_8003F084(0x121, (s16)t34, *(f32 *)(arg0 + 0x74), 0xFF, 0xFF, 0xFF,
                      0xBE, D_800ACCDC);
    }

    count = *(s32 *)(arg0 + 0x78);
    limit = *(s32 *)(arg1 + 0x1C8);
    if (*(s32 *)(arg1 + 0x124) == 1) {
        f1D8 = 62.0f;
    } else {
        f1D8 = 42.0f;
    }
    count = count + 1;
    if (limit < count) {
        count = limit;
    }
    func_8008A6B4(buf, D_800ACCE4, count);
    if (D_800A52BC >= 2 && s178 != 0) {
        t38 = (s16)f1D8;
        func_8003EC40(t38, (s16)t34, 0xFF, 0x3F, 0x3F, 0xFF, (u8 *)buf);
        func_8003EC40(t38, (s16)t30, 0xFF, 0x3F, 0x3F, 0xFF,
                      (u8 *)D_800ACCF4);
    } else {
        t38 = (s16)f1D8;
        func_8003EC40(t38, (s16)t34, 0xFF, 0xFF, 0xFF, 0xBE, (u8 *)buf);
        func_8003EC40(t38, (s16)t30, 0xFF, 0xFF, 0xFF, 0xBE,
                      (u8 *)D_800ACCFC);
    }

    if (*(s32 *)(arg1 + 0x124) != 1 && *(s32 *)(arg1 + 0x124) != 6 &&
        *(s32 *)(arg1 + 0x124) != 7) {
        if (*(s16 *)(arg0 + 0x5C) > 0) {
            func_8008A6B4(buf, D_800ACD04, *(s16 *)(arg0 + 0x5C),
                          *(s32 *)(arg1 + 0x1BC));
            func_8003EC40(0x116, (s16)t34, 0xFF, 0xFF, 0xFF, 0xBE, (u8 *)buf);
        }
        func_8003EC40(0x116, (s16)t30, 0xFF, 0xFF, 0xFF, 0xBE,
                      (u8 *)D_800ACD14);
    }

    if (D_800A52BC >= 2) {
        if (s150 == 0) {
            s158 = 0x36;
        }
    }
    func_80055D38(arg1, p160, 0xE1, s158, s150);

    if (D_8009B7D0 != 0) {
        if (D_800A2864 != 0) {
            func_8003EC40(0xA0, 0x14, 0xFF, 0, 0, 0xFF, (u8 *)D_800ACD1C);
        }
    }
}
