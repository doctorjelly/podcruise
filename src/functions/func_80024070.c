/* Independently written from scratchpad spec specs/func_80024070.md. */

#include "podcruise/types.h"

typedef struct Unk801198A8 {
    /* 0x00 */ s8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 pad2[0x38 - 0x2];
} Unk801198A8;

typedef struct Unk800A2DE0 {
    /* 0x00 */ u8 pad0[0x1];
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 pad2[0x1];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4[0xC - 0x4];
    /* 0x0C */ u8 *unkC;
} Unk800A2DE0;

typedef struct Unk8011A240 {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ u8 pad20[0x30 - 0x20];
    /* 0x30 */ s32 unk30;
} Unk8011A240;

typedef struct Unk80024070 {
    /* 0x00 */ u8 pad0[0x34];
    /* 0x34 */ s32 unk34;
    /* 0x38 */ u8 pad38[0x70 - 0x38];
    /* 0x70 */ s8 unk70;
    /* 0x71 */ u8 pad71[0x1];
    /* 0x72 */ s8 unk72;
} Unk80024070;

extern s32 D_800A2198;
extern s16 D_800A219C;
extern s32 D_800A21A0;
extern s32 D_800A21A4;
extern s32 D_800A21A8;
extern s32 D_800A2564;
extern s32 D_800A2568;
extern Unk800A2DE0 D_800A2DE0[];
extern s32 D_800A4B94[];
extern s32 D_800A4BA4[];
extern s32 D_800A4BBC;
extern s16 D_800A4BC0;
extern s32 D_800A4BC4;
extern s32 D_800A4BD0;
extern s32 D_800A4BDC;
extern s32 D_800A4BEC;
extern u8 D_800A8F30[];
extern f32 D_800D6CC0;
extern s16 D_800D6CC4;
extern Unk801198A8 D_801198A8[];
extern s8 D_8011A204[];
extern Unk8011A240 D_8011A240;

extern s32 func_800092EC(s32, s32, s32);
extern void func_800093B0(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_80009524(s32, s32);
extern void func_8000953C(s32, s32);
extern void func_8000955C(s32, s32);
extern s32 func_800129B8(u8 *, s32);
extern s32 func_80028320(Unk80024070 *, s32, s32);
extern void func_80028498(Unk80024070 *);
extern void func_80029C24(void);
extern void func_80029D38(Unk80024070 *);
extern void func_8002CC28(s32, s32, s32);
extern void func_8002D4C4(s32);
extern void func_8002D6EC(Unk80024070 *);
extern s32 func_8002DBD8(Unk80024070 *);
extern void func_8003EC40(s32, s32, s32, s32, s32, s32, u8 *);
extern void func_800469B4(Unk80024070 *, s32);
extern void func_80046DC4(Unk80024070 *, f32, f32);
extern void func_8004850C(Unk80024070 *);
extern void func_8004E4F4(Unk80024070 *);
extern void func_80050290(Unk80024070 *, s16, s32);
extern void func_800503E8(Unk80024070 *, s32, s32, s32);
extern void func_800511B0(Unk80024070 *, s32);
extern void func_800519C0(s32, s32, s32, s32);
extern s32 func_8008A6B4(u8 *, u8 *, u8 *);

void func_80024070(Unk80024070 *arg0) {
    u8 text[0x100];
    s32 restart;
    s8 request;
    s32 i;
    s32 flags;
    s32 style;
    s32 entry;
    s32 width;

    restart = 0;
    request = 0;

    if (func_80028320(arg0, D_800A4BBC, 20) != 0) {
        return;
    }

    if (D_800A4BBC != 0) {
        D_800A4BBC = 0;
        D_800A2564 = 0;
        D_800A2568 = 0;
        D_800D6CC0 = -300.0f;
        D_800A21A4 = 0;
        D_800A4BEC = 0;
        D_800A4BC4 = 0;
        func_8004E4F4(arg0);

        entry = D_8011A204[arg0->unk34 * 3];
        D_8011A240.unk30 = entry;
        style = D_801198A8[entry].unk0;
        func_800519C0(arg0->unk72, D_800A2DE0[style].unk3, D_800A2DE0[style].unk1,
                      D_801198A8[entry].unk1);
        func_80029C24();
        if (func_8002DBD8(arg0) != 0) {
            func_800503E8(arg0, arg0->unk34, -1, 0);
        } else {
            D_800A4BC0 = 5;
        }
    }

    if (func_80009524(0, 0x10) != 0) {
        if (func_80009524(0, 0x20) != 0) {
            func_8000955C(0, 0x20);
            if (func_80009524(0, 4) == 0) {
                func_8000953C(0, 4);
                func_800092EC(2, 0, 0x35);
            } else {
                func_800093B0(2, 0, 0x1F, 0x25, 0x2F, 0x33, 0x37);
            }
        }
    }

    func_80029D38(arg0);
    if (arg0->unk34 != 3) {
        func_80046DC4(arg0, 20.0f, 135.0f);
    }

    if (D_800A4BC4 == 0 || D_800A4BD0 != 0) {
        if (arg0->unk34 != 3) {
            style = D_801198A8[D_8011A240.unk30].unk0;
            func_8008A6B4(text, D_800A8F30, D_800A2DE0[style].unkC);
            func_8003EC40(0xA0, 0x19, 0x32, 0xFF, 0xFF, 0xFF, text);
            D_8011A240.unk1C = 1;
            D_8011A240.unk18 = 1;
            width = func_800129B8(text, 0);
            func_8002CC28((s32)(160.0 - (f64)width * 0.5), 0x1A, func_800129B8(text, 0));
        }
    }

    func_80028498(arg0);
    func_8004850C(arg0);

    if (D_800A4BC4 != 0) {
        if (D_800A4BD0 == 0) {
            if (D_800A21A4 == 0) {
                if (D_800A2568 == 0) {
                    D_800A2564 = 1;
                }
            }
        }
    }
    if (D_800A2564 != 0) {
        D_800A21A8 = 1;
        D_800A21A4 = 1;
        D_800D6CC4 = 0;
        D_800A2564 = 0;
    }
    if (D_800A4BC4 != 0) {
        if (D_800A21A0 == 0) {
            if (D_800A2568 != 0) {
                D_800A2568 = 0;
                func_800511B0(arg0, 0);
            }
        }
    }

    for (i = 0; i < arg0->unk70 && D_800A4BD0 == 0; i++) {
        if (D_800A219C != 0) {
            return;
        }

        flags = D_800A4BA4[i];
        if (flags & 1) {
            func_8002D4C4(0x55);
            if (D_800A4BC4 == 0) {
                func_800511B0(arg0, 1);
                if (arg0->unk34 == 3) {
                    D_800A4BDC = -1;
                    D_800A2198 = 7;
                    return;
                }
                flags = D_800A4BA4[i];
            } else {
                if (D_800D6CC4 == 0) {
                    func_8002D6EC(arg0);
                }
                D_800A21A8 = 1;
                D_800D6CC4 = 0;
                D_800A21A4 = 0;
                D_800A4BEC = 1;
                D_800A219C = -1;
                D_800A2568 = 1;
                flags = D_800A4BA4[i];
            }
        }

        if ((flags & 2) && !(flags & 1)) {
            func_8002D4C4(0x4D);
            if (D_800A21A4 != 0) {
                D_800A21A8 = 1;
                D_800A21A4 = 0;
                D_800A4BEC = 1;
                D_800D6CC4 = 0;
                D_800A219C = -1;
                D_800A2568 = 1;
            } else {
                func_800469B4(arg0, 3);
            }
        }
        D_8011A240.unk14 = 0;
        D_8011A240.unk10 = 0;

        if (D_800A4BC4 == 0 && D_800A21A4 == 0) {
            if (D_800A4B94[i] & 0x10000) {
                if (D_800A4BC0 == 5 || D_800A4BC0 == 0) {
                    request = -1;
                }
                D_8011A240.unk10 = 1;
            }
            if (D_800A4B94[i] & 0x20000) {
                if (D_800A4BC0 == 5 || D_800A4BC0 == 0) {
                    request = 1;
                }
                D_8011A240.unk14 = 1;
            }
        }

        if (request != 0) {
            func_80050290(arg0, request, 1);
            if (arg0->unk34 != 3) {
                restart = 1;
            }
            func_8002D4C4(0x57);
        }

        if (restart != 0) {
            entry = D_8011A204[arg0->unk34 * 3];
            style = D_801198A8[entry].unk0;
            D_8011A240.unk30 = entry;
            func_800519C0(arg0->unk72, D_800A2DE0[style].unk3, D_800A2DE0[style].unk1,
                          D_801198A8[entry].unk1);
            func_80029C24();
        }
    }
}
