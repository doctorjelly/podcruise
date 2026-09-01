/* Recovered per specs/func_80024954.md (boundary corrected: entry is func_80024954, not func_80024960). */
#include "podcruise/types.h"

typedef struct {
    u8 pad00[0xC];
    s32 unkC;
    u8 pad10[0x5D - 0x10];
    s8 unk5D;
    s8 unk5E;
    u8 pad5F[0x6C - 0x5F];
    s8 unk6C;
    s8 unk6D;
    u8 pad6E[0x70 - 0x6E];
    s8 unk70;
} Obj;

typedef struct {
    f32 unk0;
    u8 pad04[0x28 - 0x04];
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
} State;

extern State D_8011A240;
extern s32 D_800A4BBC;
extern s32 D_800A256C;
extern s32 D_80119658;
extern s32 D_800A4BA4[];
extern s8 D_800A21C1[];
extern s32 D_800A21B8[];
extern s32 D_800A22E8[][7];
extern u8 D_800D73E4;
extern u8 D_800D73E5;
extern u8 D_800D6DD8[];
extern f32 D_800A9D10;
extern f32 D_800A9D14;
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

extern void func_800503E8(Obj *, s32, s32, s32);
extern void func_80024704(Obj *);
extern void func_80024874(Obj *);
extern s32 func_8002DA0C(s32, u8);
extern void func_8004BAC8(Obj *, s32);
extern void func_80064A88(f32);
extern s32 func_8002DB20(Obj *, s32);
extern void func_800494D0(Obj *, u8, f32);
extern s32 func_8008A6B4(char *, const char *, ...);
extern s32 func_80082BE0(void);
extern void func_8003EC40(s16, s16, u8, u8, u8, u8, char *);
extern void *func_8002D598(s32);
extern s32 func_800129B8(char *, s32);
extern void func_8002CC28(s32, s32, s32);
extern void func_8001C404(Obj *, u8);
extern void func_8000A920(s16, s32);
extern void func_8000AA04(s16, s16, s16);
extern void func_8000AAC0(s16, f32, f32);
extern void func_8000AB24(s16, s32, s32, s32, s32);
extern void func_8002C780(s32, s32, s32);
extern void func_80064B44(s32, f32, s32);
extern void func_8002D4C4(s32);
extern void func_800469B4(Obj *, s32);

void func_80024954(Obj *obj) {
    char text[272];
    s32 *cursor;
    s32 flags;
    s32 value;
    s32 green;
    s32 red;

    if (D_800A4BBC != 0) {
        D_800A4BBC = 0;
        func_800503E8(obj, 0x25, -1, 0);
        D_800A256C = 0;
        if (obj->unkC == 12) {
            D_8011A240.unk0 = 1.0f;
        }
        if (obj->unkC == 9) {
            obj->unk5E = 0;
        }
        func_80024704(obj);
        if (obj->unkC == 9) {
            D_8011A240.unk30 = 0;
            if (obj->unk6C != 0) {
                if (func_8002DA0C(obj->unk5E, (u8)(D_8011A240.unk2C - 1)) != 0) {
                    D_8011A240.unk30 = D_8011A240.unk2C - 1;
                }
            }
        } else {
            func_80024874(obj);
        }
        func_8004BAC8(obj, 1);
        D_800D73E4 = D_800A21C1[obj->unk5D * 12];
        D_800D73E5 = obj->unk5E;
    }

    if (D_800A256C != 0) {
        func_80064A88(D_800A9D10);
    } else if (D_8011A240.unk34 == D_8011A240.unk30) {
        D_800D73E4 = D_800A21C1[obj->unk5D * 12];
        D_800D73E5 = obj->unk5E;
        func_80064A88(D_800A9D14);
    }

    obj->unk5D = D_800A22E8[obj->unk5E][func_8002DB20(obj, D_8011A240.unk30)];
    if (0.0f < D_8011A240.unk0) {
        func_800494D0(obj, *(u8 *)0x800D73E4, D_8011A240.unk0 / 2.0);
    }

    if (D_800A256C != 0) {
        return;
    }

    if (D_800A21B8[obj->unk5D * 3] == -1 || D_800A21B8[obj->unk5D * 3 + 1] == -1) {
        func_8008A6B4(text, D_800A8F38);
        red = func_80082BE0();
        green = func_80082BE0();
        value = func_80082BE0();
        func_8003EC40(0xA0, 0xCD, (s32)((f32)red / (f32)2147483648.0 * 256.0f),
                      (s32)((f32)green / (f32)2147483648.0 * 256.0f),
                      (s32)((f32)value / (f32)2147483648.0 * 256.0f), 0xFF, text);
    }

    func_8008A6B4(text, D_800A8F58, func_8002D598(obj->unk5D));
    func_8003EC40(0xA0, 0x36, 0, 0xFF, 0, 0xFF, text);
    red = func_800129B8(text, 0);
    green = func_800129B8(text, 0);
    func_8002CC28((s32)(160.0 - (f64)red / 2.0), 0x37, green);

    value = obj->unk5E;
    if (value == 0) {
        func_8003EC40(0xA0, 0x22, 0x32, 0xFF, 0xFF, 0xFF, D_800A8F60);
    } else if (value == 1) {
        func_8003EC40(0xA0, 0x22, 0x44, 0xFF, 0x3E, 0xFF, D_800A8F84);
    } else if (value == 2) {
        func_8003EC40(0xA0, 0x22, 0xA3, 0xBE, 0x11, 0xFF, D_800A8FA8);
    } else if (value == 3) {
        func_8003EC40(0xA0, 0x22, 0x9D, 0x59, 0x20, 0xFF, D_800A8FCC);
    }

    if (obj->unk6C != 0) {
        func_8008A6B4(text, D_800A8FF4);
    } else if (obj->unk6D != 0) {
        func_8008A6B4(text, D_800A9004);
    } else if (obj->unk70 == 2) {
        func_8008A6B4(text, D_800A9014);
    } else {
        func_8008A6B4(text, D_800A9024);
    }
    func_8003EC40(0xA0, 0x18, 0x32, 0xFF, 0xFF, 0xFF, text);

    func_8001C404(obj, D_800D73E5);
    green = (s16)(D_800A21C1[obj->unk5D * 12] + 0x45);
    func_8000A920((s16)green, 1);
    func_8000AA04((s16)green, 0xA0, 0x91);
    func_8000AAC0((s16)green, 1.0f, 1.0f);
    func_8000AB24((s16)green, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8003EC40(0xE0, 0x8A, 0, 0xFF, 0, 0xFF,
                  (char *)&D_800D6DD8[D_800A21C1[obj->unk5D * 12] * 92 + 0x1C]);
    func_8002C780(0x2D, 0x54, 0x1E);

    if (D_800A256C != 0) {
        return;
    }
    func_80064B44(0, 1.0f, 1);

    for (cursor = &D_800A4BA4[0]; cursor != &D_800A4BA4[1]; cursor++) {
        flags = *cursor;
        if ((flags & 1) != 0 && D_80119658 == 0) {
            func_8002D4C4(0x55);
            func_8004BAC8(obj, 0);
            func_800469B4(obj, 0xD);
            D_800A256C = 1;
            return;
        }
        if ((flags & 2) != 0 && (flags & 1) == 0 && D_80119658 == 0) {
            func_8002D4C4(0x4D);
            func_8004BAC8(obj, 0);
            func_800469B4(obj, 9);
            return;
        }
        if (obj->unk5E == D_800D73E5) {
            if ((flags & 0x8000) != 0) {
                value = obj->unk5E;
                if (value < D_8011A240.unk28) {
                    obj->unk5E = value + 1;
                    D_8011A240.unk34 = -1;
                    func_8002D4C4(0x57);
                    func_80024704(obj);
                } else {
                    func_8002D4C4(0x4B);
                }
                flags = *cursor;
            }
            if ((flags & 0x4000) != 0) {
                value = obj->unk5E;
                if (value > 0) {
                    obj->unk5E = value - 1;
                    D_8011A240.unk34 = -1;
                    func_8002D4C4(0x57);
                    func_80024704(obj);
                } else {
                    func_8002D4C4(0x4B);
                }
            }
        }
    }
}
