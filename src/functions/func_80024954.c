/* Independently written from specs/functions/recovered/stitched_ui_control_tranche.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 pad00[0x0C];
    /* 0x0C */ s32 mode;
    /* 0x10 */ u8 pad10[0x4D];
    /* 0x5D */ s8 unk5D;
    /* 0x5E */ s8 unk5E;
    /* 0x5F */ u8 pad5F[0x0D];
    /* 0x6C */ s8 unk6C;
    /* 0x6D */ s8 unk6D;
    /* 0x6E */ u8 pad6E[2];
    /* 0x70 */ s8 unk70;
} Panel80024954;

typedef struct {
    /* 0x00 */ f32 unk00;
    /* 0x04 */ u8 pad04[0x24];
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
} Menu8011A240;

extern s32 D_800A4BBC;
extern s32 D_800A256C;
extern Menu8011A240 D_8011A240;
extern s8 D_800A21C1[];
extern s32 D_800A21B8[][3];
extern s32 D_800A22E8[][7];
extern u8 D_800D73E4;
extern u8 D_800D73E5;
extern f32 D_800A9D10;
extern f32 D_800A9D14;
extern u8 D_800D6DD8[][92];
extern s32 D_800A4BA4[];
extern s32 D_80119658;
extern char D_800A8F38[];
extern char D_800A8F58[];
extern char D_800A8F60[];
extern char D_800A8F84[];
extern char D_800A8FA8[];
extern char D_800A8FCC[];
extern char D_800A8FF4[];
extern char D_800A9004[];
extern char D_800A9014[];
extern char D_800A9024[];

extern void func_800503E8(s32 *, s32, s32, s32);
extern void func_80024704(s8 *);
extern s32 func_8002DA0C(s8, u8);
extern void func_80024874(void *);
extern void func_8004BAC8(void *, s32);
extern f32 func_80064A88(f32);
extern s32 func_8002DB20(void *, s32);
extern void func_800494D0(void *, s32, f32);
extern s32 func_8008A6B4(char *, const char *, ...);
extern void func_8003EC40(s16, s16, u8, u8, u8, u8, u8 *);
extern void *func_8002D598(s32);
extern s32 func_800129B8(u8 *, s32);
extern void func_8002CC28(s32, s32, s32);
extern void func_8001C404(void *, s32);
extern void func_8000A920(s16, s32);
extern void func_8000AA04(s16, s16, s16);
extern void func_8000AAC0(s16, f32, f32);
extern void func_8000AB24(s16, u8, u8, u8, u8);
extern void func_8002C780(s32, s32, s32);
extern void func_80064B44(s32, f32, s32);
extern void func_8002D4C4(s32);
extern void func_800469B4(void *, s32);
extern s32 func_80082BE0(void);

void func_80024954(Panel80024954 *panel) {
    char text[256];
    s32 green;
    s32 blue;
    s32 width;
    s32 height;
    s16 icon;
    s32 slot;
    s32 index;
    s32 red;

    if (D_800A4BBC != 0) {
        D_800A4BBC = 0;
        func_800503E8((s32 *)panel, 0x25, -1, 0);
        D_800A256C = 0;
        if (panel->mode == 12) {
            D_8011A240.unk00 = 1.0f;
        }
        if (panel->mode == 9) {
            panel->unk5E = 0;
        }
        func_80024704((s8 *)panel);
        if (panel->mode == 9) {
            D_8011A240.unk30 = 0;
            if (panel->unk6C != 0) {
                if (func_8002DA0C(panel->unk5E, D_8011A240.unk2C - 1) != 0) {
                    D_8011A240.unk30 = D_8011A240.unk2C - 1;
                }
            }
        } else {
            func_80024874(panel);
        }
        func_8004BAC8(panel, 1);
        D_800D73E4 = D_800A21C1[panel->unk5D * 12];
        D_800D73E5 = panel->unk5E;
    }

    if (D_800A256C != 0) {
        func_80064A88(D_800A9D10);
    } else if (D_8011A240.unk34 == D_8011A240.unk30) {
        D_800D73E4 = D_800A21C1[panel->unk5D * 12];
        D_800D73E5 = panel->unk5E;
        func_80064A88(D_800A9D14);
    }
    slot = func_8002DB20(panel, D_8011A240.unk30);
    panel->unk5D = D_800A22E8[panel->unk5E][slot];
    if (D_8011A240.unk00 > 0.0f) {
        func_800494D0(panel, D_800D73E4, D_8011A240.unk00 * 0.5);
    }
    if (D_800A256C != 0) {
        return;
    }

    if (D_800A21B8[panel->unk5D][0] == -1 || D_800A21B8[panel->unk5D][1] == -1) {
        func_8008A6B4(text, D_800A8F38);
        green = func_80082BE0();
        red = func_80082BE0();
        blue = func_80082BE0();
        func_8003EC40(0xA0, 0xCD,
                      (s32)((f32)red / (f32)2147483648.0 * 256.0f),
                      (s32)((f32)green / (f32)2147483648.0 * 256.0f),
                      (s32)((f32)blue / (f32)2147483648.0 * 256.0f),
                      0xFF, (u8 *)text);
    }
    func_8008A6B4(text, D_800A8F58, func_8002D598(panel->unk5D));
    func_8003EC40(0xA0, 0x36, 0, 0xFF, 0, 0xFF, (u8 *)text);
    width = func_800129B8((u8 *)text, 0);
    height = func_800129B8((u8 *)text, 0);
    func_8002CC28(160.0 - width * 0.5, 0x37, height);

    switch (panel->unk5E) {
    case 0:
        func_8003EC40(0xA0, 0x22, 0x32, 0xFF, 0xFF, 0xFF, (u8 *)D_800A8F60);
        break;
    case 1:
        func_8003EC40(0xA0, 0x22, 0x44, 0xFF, 0x3E, 0xFF, (u8 *)D_800A8F84);
        break;
    case 2:
        func_8003EC40(0xA0, 0x22, 0xA3, 0xBE, 0x11, 0xFF, (u8 *)D_800A8FA8);
        break;
    case 3:
        func_8003EC40(0xA0, 0x22, 0x9D, 0x59, 0x20, 0xFF, (u8 *)D_800A8FCC);
        break;
    }

    if (panel->unk6C != 0) {
        func_8008A6B4(text, D_800A8FF4);
    } else if (panel->unk6D != 0) {
        func_8008A6B4(text, D_800A9004);
    } else if (panel->unk70 == 2) {
        func_8008A6B4(text, D_800A9014);
    } else {
        func_8008A6B4(text, D_800A9024);
    }
    func_8003EC40(0xA0, 0x18, 0x32, 0xFF, 0xFF, 0xFF, (u8 *)text);
    func_8001C404(panel, D_800D73E5);

    icon = D_800A21C1[panel->unk5D * 12] + 0x45;
    func_8000A920(icon, 1);
    func_8000AA04(icon, 0xA0, 0x91);
    func_8000AAC0(icon, 1.0f, 1.0f);
    func_8000AB24(icon, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8003EC40(0xE0, 0x8A, 0, 0xFF, 0, 0xFF,
                  &D_800D6DD8[D_800A21C1[panel->unk5D * 12]][0x1C]);
    func_8002C780(0x2D, 0x54, 0x1E);
    if (D_800A256C != 0) {
        return;
    }
    func_80064B44(0, 1.0f, 1);

    for (index = 0; index < 1; index++) {
        if ((D_800A4BA4[index] & 1) && D_80119658 == 0) {
            func_8002D4C4(0x55);
            func_8004BAC8(panel, 0);
            func_800469B4(panel, 0xD);
            D_800A256C = 1;
            break;
        }
        if ((D_800A4BA4[index] & 2) && !(D_800A4BA4[index] & 1) && D_80119658 == 0) {
            func_8002D4C4(0x4D);
            func_8004BAC8(panel, 0);
            func_800469B4(panel, 9);
            return;
        }
        if (panel->unk5E == D_800D73E5) {
            if (D_800A4BA4[index] & 0x8000) {
                if (panel->unk5E < D_8011A240.unk28) {
                    panel->unk5E = panel->unk5E + 1;
                    D_8011A240.unk34 = -1;
                    func_8002D4C4(0x57);
                    func_80024704((s8 *)panel);
                } else {
                    func_8002D4C4(0x4B);
                }
            }
            if (D_800A4BA4[index] & 0x4000) {
                if (panel->unk5E > 0) {
                    panel->unk5E = panel->unk5E - 1;
                    D_8011A240.unk34 = -1;
                    func_8002D4C4(0x57);
                    func_80024704((s8 *)panel);
                } else {
                    func_8002D4C4(0x4B);
                }
            }
        }
    }
}
