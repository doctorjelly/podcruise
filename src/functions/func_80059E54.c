/* Independently written from specs/functions/recovered/func_80059E54.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 pad000[0x0C];
    /* 0x00C */ f32 unk00C;
    /* 0x010 */ u8 pad010[0x1AC];
    /* 0x1BC */ s32 unk1BC;
    /* 0x1C0 */ u8 pad1C0[8];
    /* 0x1C8 */ s32 unk1C8;
    /* 0x1CC */ u8 pad1CC[4];
    /* 0x1D0 */ f32 unk1D0;
    /* 0x1D4 */ f32 unk1D4;
} PcSession80059E54;

typedef struct {
    /* 0x00 */ u8 pad00[0x5C];
    /* 0x5C */ s16 unk5C;
    /* 0x5E */ u8 pad5E[2];
    /* 0x60 */ f32 unk60[5];
    /* 0x74 */ f32 unk74;
} PcRacer80059E54;

extern void func_8000A920(s16 id, s32 enabled);
extern void func_8000AA04(s16 id, s16 x, s16 y);
extern void func_8003EC40(s16 x, s16 y, u8 red, u8 green, u8 blue,
                          u8 alpha, const char *text);
extern void func_8003F084(s16 x, s16 y, f32 value, u8 red, u8 green,
                          u8 blue, u8 alpha, const char *suffix);
extern s32 func_80051FF4(void);
extern s32 func_80082BE0(void);
extern void func_80087814(s16 left, s16 top, s16 right, s16 bottom);
extern s32 func_8008A6B4(char *buffer, const char *format, ...);

extern s32 D_800A26F4;
extern s32 D_800A52BC;
extern char D_800ACD80[];
extern char D_800ACD88[];
extern char D_800ACD90[];
extern char D_800ACD98[];
extern char D_800ACDA0[];
extern char D_800ACDA8[];
extern char D_800ACDB4[];
extern char D_800ACDBC[];
extern char D_800ACDC4[];
extern char D_800ACDCC[];
extern char D_800ACDD4[];
extern char D_800ACDDC[];
extern char D_800ACDE8[];
extern char D_800ACDF0[];
extern char D_800ACDF8[];
extern char D_800ACE00[];
extern char D_800ACE08[];
extern f32 D_800ACF78;
extern f32 D_800ACF7C;
extern f32 D_800ACF80;
extern f32 D_800ACF84;
extern f32 D_800ACF88;
extern f32 D_800ACF8C;
extern f32 D_800ACF90;
extern f32 D_800ACF94;
extern f32 D_800ACF98;
extern f32 D_800ACF9C;
extern PcRacer80059E54 *D_8011B1BC;

void func_80059E54(PcSession80059E54 *session, PcRacer80059E54 *racer,
                   void *object) {
    char text[0x20];
    const char *label;
    f32 value;
    s32 row;
    s32 rowY;
    s32 baseY;
    s32 valueX;
    s32 iconX;
    s32 mode;
    u8 red;
    u8 green;
    u8 blue;

    (void)object;
    mode = func_80051FF4();
    if (mode == 2) {
        rowY = 0xD7;
        if (racer == D_8011B1BC) {
            rowY = 0x69;
            baseY = 0x1E;
            for (row = 0xF; row != 0x13; row++) {
                func_8000A920((s16)row, 0);
            }
        } else {
            baseY = 0x8C;
            for (row = 0x13; row != 0x17; row++) {
                func_8000A920((s16)row, 0);
            }
        }
    } else {
        for (row = 0; row != 0x13; row++) {
            func_8000A920((s16)row, 0);
        }
        rowY = 0xD7;
        baseY = 0x37;
    }

    rowY -= session->unk1C8 * 14;
    value = racer->unk74;
    if (value < 60.0f) {
        valueX = 0x5B;
    } else if (value < 600.0f) {
        valueX = 0x69;
    } else if (value < D_800ACF78) {
        valueX = 0x73;
    } else if (value < D_800ACF7C) {
        valueX = 0x7D;
    } else {
        valueX = 0x87;
    }

    for (row = 0; row < session->unk1C8; row++) {
        func_8008A6B4(text, D_800ACD80, D_800ACD88);
        func_8003EC40(0x19, (s16)(rowY + 1), 0xFF, 0xFF, 0, 0xFF,
                      text);
        func_8008A6B4(text, D_800ACD90, row + 1);
        func_8003EC40(0x2D, (s16)rowY, 0xFF, 0xFF, 0, 0xFF, text);

        red = 0xFF;
        green = 0x80;
        if (racer->unk60[row] <= session->unk1D0) {
            if (D_800A26F4 == 0) {
                red = (u8)(u32)((((f32)func_80082BE0() /
                                  (f32)2147483648.0) *
                                 127.0f) +
                                128.0f);
            } else {
                red = (u8)(u32)D_800ACF80;
            }
            green = (u8)(red - 0x14);
        }
        func_8003F084((s16)valueX, (s16)(rowY - 3), racer->unk60[row],
                      red, green, 0, 0xFF, D_800ACD98);
        rowY += 14;
    }

    red = 0x32;
    green = 0xFF;
    blue = 5;
    value = racer->unk74;
    if (value <= session->unk1D4) {
        session->unk1D4 = value;
        if (D_800A26F4 == 0) {
            red = (u8)(u32)((((f32)func_80082BE0() /
                              (f32)2147483648.0) *
                             26.0f) +
                            24.0f);
        } else {
            red = (u8)(u32)43.5f;
        }
        if (D_800A26F4 == 0) {
            green = (u8)(u32)((((f32)func_80082BE0() /
                                (f32)2147483648.0) *
                               127.0f) +
                              128.0f);
        } else {
            green = (u8)(u32)D_800ACF84;
        }
        blue = 0;
    }
    func_8008A6B4(text, D_800ACDA0, D_800ACDA8);
    func_8003EC40(0x19, (s16)(rowY + 1), 0xF0, 0xFF, 0, 0xFF, text);
    func_8003F084((s16)valueX, (s16)(rowY - 3), racer->unk74, red, green,
                  blue, 0xFF, D_800ACDB4);

    if (D_800A52BC >= 2) {
        if (racer->unk5C == 1) {
            label = D_800ACDBC;
        } else if (racer->unk5C == 2) {
            label = D_800ACDC4;
        } else if (racer->unk5C == 3) {
            label = D_800ACDCC;
        } else {
            label = D_800ACDD4;
        }
        if (D_800A26F4 == 0) {
            red = (u8)(u32)((((f32)func_80082BE0() /
                              (f32)2147483648.0) *
                             127.0f) +
                            128.0f);
            green = (u8)(u32)((((f32)func_80082BE0() /
                                (f32)2147483648.0) *
                               127.0f) +
                              128.0f);
            blue = (u8)(u32)((((f32)func_80082BE0() /
                               (f32)2147483648.0) *
                              127.0f) +
                             128.0f);
        } else {
            red = (u8)(u32)D_800ACF88;
            green = (u8)(u32)D_800ACF8C;
            blue = (u8)(u32)D_800ACF90;
        }
        func_8008A6B4(text, D_800ACDDC, racer->unk5C);
        func_8003EC40(0xA0, (s16)baseY, red, green, blue, 0xFE, text);
        func_8003EC40(0xA1, (s16)baseY, red, green, blue, 0xFE, label);
        return;
    }

    if (session->unk1BC >= 2) {
        value = session->unk00C;
        if (value > 8.0f) {
            func_8000A920(0xA9, 0);
            func_8000A920(0xAA, 0);
            func_8000A920(0xAB, 0);
            return;
        }

        valueX = 0xA0;
        rowY = baseY;
        if (value < 0.5f) {
            valueX = (s32)((f32)0xA0 -
                           (2.0f * (0.5f - value) * 190.0f));
        }
        if (value > 7.5f) {
            valueX = (s32)((f32)valueX +
                           (2.0f * (value - 7.5f) * 190.0f));
        }

        if (D_800A52BC < 2 && racer->unk5C < 4) {
            valueX -= 0x14;
            iconX = 0x140 - valueX;
            rowY = baseY + 0x14;
            func_80087814((s16)(iconX - 0x11), (s16)(rowY - 0x21),
                          (s16)(iconX + 0x11), (s16)(rowY + 0x21));
            if (racer->unk5C == 1) {
                func_8000A920(0xA9, 1);
                func_8000AA04(0xA9, (s16)iconX, (s16)(rowY - 0x14));
            }
            if (racer->unk5C == 2) {
                func_8000A920(0xAA, 1);
                func_8000AA04(0xAA, (s16)iconX, (s16)(rowY - 0x14));
            }
            if (racer->unk5C == 3) {
                func_8000A920(0xAB, 1);
                func_8000AA04(0xAB, (s16)iconX, (s16)(rowY - 0x14));
            }
        }

        if (racer->unk5C == 1) {
            label = D_800ACDE8;
        } else if (racer->unk5C == 2) {
            label = D_800ACDF0;
        } else if (racer->unk5C == 3) {
            label = D_800ACDF8;
        } else {
            label = D_800ACE00;
        }
        if (D_800A26F4 == 0) {
            red = (u8)(u32)((((f32)func_80082BE0() /
                              (f32)2147483648.0) *
                             127.0f) +
                            128.0f);
            green = (u8)(u32)((((f32)func_80082BE0() /
                                (f32)2147483648.0) *
                               127.0f) +
                              128.0f);
            blue = (u8)(u32)((((f32)func_80082BE0() /
                               (f32)2147483648.0) *
                              127.0f) +
                             128.0f);
        } else {
            red = (u8)(u32)D_800ACF94;
            green = (u8)(u32)D_800ACF98;
            blue = (u8)(u32)D_800ACF9C;
        }
        func_8008A6B4(text, D_800ACE08, racer->unk5C);
        func_8003EC40((s16)valueX, (s16)rowY, red, green, blue, 0xFE,
                      text);
        func_8003EC40((s16)(valueX + 1), (s16)rowY, red, green, blue,
                      0xFE, label);
    }
}
