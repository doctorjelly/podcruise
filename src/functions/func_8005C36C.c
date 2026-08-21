/* Independently written from scratchpad spec specs/func_8005C36C.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ f32 unk00;
    /* 0x04 */ f32 unk04;
    /* 0x08 */ f32 unk08;
} PcTriple8005C36C;

typedef struct {
    /* 0x00 */ u8 unk00[0x5C];
    /* 0x5C */ s16 unk5C;
    /* 0x5E */ u8 unk5E[0x2A];
} PcRacer8005C36C; /* 0x88 */

typedef struct {
    /* 0x00 */ u8 unk00[0x78];
    /* 0x78 */ s32 unk78;
} PcSlot8005C36C;

typedef struct {
    /* 0x000 */ u8 unk000[0x8];
    /* 0x008 */ s32 unk008;
    /* 0x00C */ f32 unk00C;
    /* 0x010 */ u8 unk010[0x19C];
    /* 0x1AC */ u32 unk1AC;
    /* 0x1B0 */ u8 unk1B0[0xC];
    /* 0x1BC */ s32 unk1BC;
    /* 0x1C0 */ u8 unk1C0[0x8];
    /* 0x1C8 */ s32 unk1C8;
} PcSession8005C36C;

extern s32 D_800A52B4;
extern s32 D_800A52BC;
extern u8 D_800A52C4;
extern s32 D_800A52D8;
extern s32 D_800A5998;
extern s32 D_800A599C;
extern PcTriple8005C36C D_800A59F0;
extern char D_800ACE20[];
extern f32 D_800ACFF4;
extern f32 D_800ACFF8;
extern f32 D_800ACFFC;
extern f32 D_800AD000;
extern PcRacer8005C36C *D_8011B1B8;
extern PcSlot8005C36C *D_8011B1BC;
extern PcSlot8005C36C *D_8011B1C0;

extern void func_80008B14(s32 arg0, s16 arg1, f32 arg2, f32 arg3, s32 arg4);
extern void func_80009744(s32 mode, u32 seed);
extern void func_8000A920(s16 mode, s32 flag);
extern void func_8000AB24(s16 mode, u8 red, u8 green, u8 blue, u8 alpha);
extern void func_8000FEAC(s32 arg0, f32 *arg1, s32 arg2);
extern f32 func_8002F060(void);
extern void func_8003ECB0(s16 column, s16 row, const char *text);
extern s32 func_8008A6B4(char *buffer, const char *format, ...);
extern void func_80051D2C(void *object, s32 reset);
extern s32 func_80051FF4(void);
extern void func_80052A08(void *object, s32 flag);
extern void func_800547EC(void *object);
extern void func_80056464(void);
extern void func_80057ED4(void);
extern void func_8005B3F0(void *object, void *slot);
extern void func_8005B810(void *object);
extern void func_8005C210(void *object);

void func_8005C36C(PcSession8005C36C *session) {
    char buffer[0x98];
    PcRacer8005C36C **slot;
    s32 place;
    s32 mode;
    PcTriple8005C36C triple;
    PcRacer8005C36C *racer;
    PcRacer8005C36C *ranks[12];

    triple = D_800A59F0;
    if (D_800A5998 != 0) {
        func_80051D2C(session, 0);
        if (D_800A599C == 2) {
            func_80008B14(0x90, 7, 0.25f, 1.0f, 1);
        } else if (D_800A599C == 3) {
            func_80008B14(0x8E, 7, 0.25f, 1.0f, 1);
        } else if (D_800A599C == 4) {
            func_80008B14(0x91, 7, 0.25f, 1.0f, 1);
        } else if (D_800A599C == 5) {
            func_80008B14(0x8F, 7, 0.25f, 1.0f, 1);
        } else {
            func_80008B14(0x8F, 7, 0.25f, 1.0f, 1);
        }
    } else if ((session->unk008 & 0xF) != 6) {
        if (((session->unk008 & 0xF) == 1) || ((session->unk008 & 0xF) == 2)) {
            mode = 0;
            if (session->unk1C8 >= 2) {
                if (D_8011B1BC != 0) {
                    place = D_8011B1BC->unk78 + 1;
                    if (place >= session->unk1C8) {
                        mode = 1;
                    }
                }
                if (D_8011B1C0 != 0) {
                    place = D_8011B1C0->unk78 + 1;
                    if (place >= session->unk1C8) {
                        mode = 1;
                    }
                }
            }
            if ((0.0f < func_8002F060()) || ((session->unk008 & 0xF) == 6)) {
                func_80009744(0, session->unk1AC);
            } else if (mode != 0) {
                func_80009744(1, session->unk1AC);
            } else if (func_80051FF4() <= 0) {
                func_80009744(1, session->unk1AC);
            }
        }
        D_800A52B4 = 0;
    }

    func_80056464();
    if ((session->unk008 & 0xF) == 4) {
        if (0.0f < session->unk00C) {
            func_8000AB24(-0x67, 0, 0, 0, (u32)((session->unk00C / 0.5f) * 255.0f));
        } else {
            func_8000AB24(-0x67, 0, 0, 0, 0);
        }
    } else if ((session->unk008 & 0xF) == 5) {
        if (D_800ACFF4 < session->unk00C) {
            func_8000AB24(-0x67, 0, 0, 0,
                          (u32)((1.0f - ((D_800ACFFC - session->unk00C) / D_800ACFF8)) * 255.0f));
        } else {
            func_8000AB24(-0x67, 0, 0, 0, 0);
        }
    } else if (((session->unk008 & 0xF) == 1) && ((session->unk008 & 0x20) != 0)) {
        if (session->unk00C < D_800AD000) {
            func_8000AB24(-0x67, 0, 0, 0,
                          (u32)(((D_800AD000 - session->unk00C) / D_800AD000) * 255.0f));
        } else {
            func_8000A920(-0x67, 0);
        }
    } else if ((session->unk008 & 0xF) == 6) {
        if (0.5f < session->unk00C) {
            func_8000AB24(-0x67, 0, 0, 0, 0);
        } else if (0.25f < session->unk00C) {
            func_8000AB24(-0x67, 0, 0, 0,
                          (u32)(((0.5f - session->unk00C) / 0.25f) * 255.0f));
        } else {
            func_8000AB24(-0x67, 0, 0, 0, 0xFF);
        }
        return;
    }

    D_800A52C4 = !D_800A52C4;
    if ((session->unk008 & 0xF) != 1) {
        if (D_800A52D8 != 0) {
            if (D_800A52C4 != 0) {
                func_8008A6B4(buffer, D_800ACE20);
                func_8003ECB0(0x64, 0x64, buffer);
            }
        }
    }
    func_80052A08(session, 0);

    for (slot = &ranks[0]; slot < &ranks[12]; slot++) {
        *slot = 0;
    }

    for (mode = 0; mode < session->unk1BC; mode++) {
        racer = &D_8011B1B8[mode];
        func_8000FEAC(mode, &triple.unk00, -0x270F);
        if (racer->unk5C > 0) {
            ranks[racer->unk5C - 1] = racer;
        }
    }

    for (mode = 0; mode != 0x17; mode++) {
        func_8000A920(mode + 0x2B, 0);
        func_8000A920(0x42, 0);
        func_8000A920(0x43, 0);
    }
    func_8000A920(0x19, 0);

    mode = session->unk008 & 0xF;
    if (mode != 4) {
        if (D_800A52BC >= 2) {
            func_80057ED4();
        }
    }
    if ((mode != 3) && (mode != 4) && (mode != 5)) {
        if (D_8011B1BC != 0) {
            func_8005B3F0(session, D_8011B1BC);
        }
        if (D_8011B1C0 != 0) {
            func_8005B3F0(session, D_8011B1C0);
        }
        if ((session->unk008 & 0xF) != 2) {
            func_800547EC(session);
            func_8005C210(session);
        }
        func_8005B810(session);
    }
}
