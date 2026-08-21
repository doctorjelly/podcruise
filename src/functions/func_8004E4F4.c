/* Recovered from specification: specs/func_8004E4F4.md (worker batch 05) */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s8 unk0;
    /* 0x01 */ s8 pad1[3];
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10[3];
    /* 0x1C */ f32 unk1C[3];
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30[2];
} Rec;

typedef struct {
    /* 0x00 */ u8 pad0[0x2C];
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
} Ctl;

typedef struct {
    /* 0x00 */ u8 pad0[3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4[0xC];
} Ent;

typedef struct {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ u8 pad14[0xC];
} Slot;

typedef struct {
    /* 0x00 */ u8 pad0[0x38];
    /* 0x38 */ s32 unk38;
} Mode;

extern Rec D_801198A8[35];
extern Rec D_8011A050[8];
extern s8 D_8011A210[];
extern Ctl D_8011A240;
extern s32 D_8011A26C;
extern s32 D_800A21B0;
extern Ent D_800A2DE0[];
extern s32 D_800A4BE8;
extern f32 D_800A4BC8;
extern f32 D_800A4BCC;
extern Slot D_800A4C00[];
extern f32 D_800AB2DC;
extern f32 D_800AB2E0;
extern f32 D_800AB2E4;
extern f32 D_800AB2E8;

extern void func_80015268(f32 *, f32, f32, f32);
extern void func_80014CC0(f32, f32 *, f32 *);
extern void func_80015288(f32 *, f32 *);
extern f32 func_80014F54(f32, f32);

void func_8004E4F4(Mode *arg0) {
    s32 i;
    s32 c;
    s32 mid;
    f32 sp80;
    f32 sp7C;
    s32 angle;

    for (i = 0; i < 35; i++) {
        func_80015268(&D_801198A8[i].unk4, 0.0f, 0.0f, 0.0f);
        if (i < 8) {
            func_80015268(&D_8011A050[i].unk4, 0.0f, 0.0f, 0.0f);
        }
    }

    if (arg0->unk38 == 0) {
        mid = (s32)((f32)(D_8011A240.unk2C + 1) * 0.5f);
        D_8011A240.unk30 = mid;
        if (D_8011A240.unk2C == 0) {
            D_8011A240.unk30 = -1;
            return;
        }
        if (D_800A21B0 == 1) {
            if (D_8011A240.unk2C - 1 > 0) {
                i = 0;
                do {
                    if (D_800A4BE8 == D_800A2DE0[D_801198A8[i].unk0].unk3) {
                        D_8011A240.unk30 = i;
                        break;
                    }
                    i++;
                } while (i < D_8011A240.unk2C - 1);
            }
        }
        if (D_8011A240.unk2C > 0) {
            i = 0;
            do {
            angle = 90 - (i - mid) * 10;
            func_80014CC0((f32)angle, &sp80, &sp7C);
            D_801198A8[i].unk4 = 256.0f * sp7C + 12.0f;
            D_801198A8[i].unk8 = 256.0f * sp80 + -116.0f;
            D_801198A8[i].unkC = 106.0f;
            func_80015288(D_801198A8[i].unk10, &D_801198A8[i].unk4);
            D_801198A8[i].unk28 = func_80014F54(D_801198A8[i].unk4 - 12.0f, -116.0f - D_801198A8[i].unk8) - 90.0f;
            func_80014CC0((1.5f - D_800A4BC8) * 360.0f, &sp80, &sp7C);
            D_801198A8[i].unk2C = 45.0f * D_800A4BCC * sp7C;
            i++;
            } while (i < D_8011A26C);
        }
    }

    if (arg0->unk38 == 1) {
        for (i = 0; i < 16; i += 2) {
            c = D_8011A210[i * 3];
            if (-1 != c) {
                D_801198A8[c].unkC = -130.0f;
                D_801198A8[c].unk2C = 0.0f;
                D_801198A8[c].unk28 = 0.0f;
                D_801198A8[c].unk4 = D_800A4C00[i + 4].unkC;
                D_801198A8[c].unk8 = D_800A4C00[i + 4].unk10;
            }
            c = D_8011A210[i * 3 + 3];
            if (-1 != c) {
                D_801198A8[c].unkC = -130.0f;
                D_801198A8[c].unk2C = 0.0f;
                D_801198A8[c].unk28 = 0.0f;
                D_801198A8[c].unk4 = D_800A4C00[i + 5].unkC;
                D_801198A8[c].unk8 = D_800A4C00[i + 5].unk10;
            }
        }
    }

    if (arg0->unk38 == 2) {
        for (i = 0; i < D_8011A240.unk2C + 1; i++) {
            D_8011A050[i].unk8 = 40.0f;
            D_8011A050[i].unk2C = 0.0f;
            D_8011A050[i].unk28 = 0.0f;
            D_8011A050[i].unk4 = (f32)(i % 2) * D_800AB2E8 + D_800AB2E4;
            D_8011A050[i].unkC = (f32)(i / 2) * D_800AB2E0 + 9.0f;
            if (i == D_8011A240.unk2C) {
                D_8011A050[i].unk28 = 90.0f;
                D_8011A050[i].unkC = D_8011A050[i].unkC - D_800AB2DC;
            }
        }
    }

    for (i = 0; i < 35; i++) {
        func_80015288(D_801198A8[i].unk10, &D_801198A8[i].unk4);
        func_80015288(D_801198A8[i].unk1C, &D_801198A8[i].unk4);
        if (i < 8) {
            func_80015288(D_8011A050[i].unk10, &D_801198A8[i].unk4);
            func_80015288(D_8011A050[i].unk1C, &D_801198A8[i].unk4);
        }
    }
}
