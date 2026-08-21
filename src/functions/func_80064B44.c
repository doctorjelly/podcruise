/* Independently written from scratchpad spec specs/func_80064B44.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ f32 unk00;
    /* 0x04 */ s32 unk04[3];
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20[3];
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ s32 unk40;
} Unk8011A240;

extern void func_8002D4C4(s32 arg0);
extern f32 func_80064A88(f32 arg0);
extern Unk8011A240 D_8011A240;
extern u32 D_800A4B94[];
extern u32 D_800A4BA4[];
extern f32 D_800AD434;
extern f32 D_800AD438;
extern f32 D_800AD43C;
extern f32 D_800AD440;
extern f32 D_800AD444;
extern f32 D_800AD448;

void func_80064B44(s32 arg0, f32 arg1, s32 arg2) {
    s32 moved;

    moved = 0;
    D_8011A240.unk10 = 0;
    D_8011A240.unk14 = 0;
    D_8011A240.unk18 = 0;
    D_8011A240.unk1C = 0;
    if (D_8011A240.unk30 > 0) {
        D_8011A240.unk18 = 1;
    }
    if (D_8011A240.unk30 < D_8011A240.unk2C - 1) {
        D_8011A240.unk1C = 1;
    }
    if (D_800A4B94[arg0] & 0x20000) {
        if (D_8011A240.unk30 < D_8011A240.unk2C - 1) {
            D_8011A240.unk14 = 1;
            if (D_8011A240.unk38 == 0.0f || (D_800A4BA4[arg0] & 0x20000)) {
                D_8011A240.unk40 = 1;
                moved = 1;
                D_8011A240.unk38 = D_800AD434;
                if (D_8011A240.unk3C > 0) {
                    D_8011A240.unk38 = D_800AD438 / arg1;
                }
            }
        } else if (D_8011A240.unk00 == 1.0f) {
            func_8002D4C4(0x4B);
        }
    }
    if (D_800A4B94[arg0] & 0x10000) {
        if (D_8011A240.unk30 > 0) {
            D_8011A240.unk10 = 1;
            if (D_8011A240.unk38 == 0.0f || (D_800A4BA4[arg0] & 0x10000)) {
                D_8011A240.unk40 = -1;
                moved = 1;
                D_8011A240.unk38 = D_800AD43C;
                if (D_8011A240.unk3C < 0) {
                    D_8011A240.unk38 = D_800AD440 / arg1;
                }
            }
        } else if (D_8011A240.unk00 == 1.0f) {
            func_8002D4C4(0x4B);
        }
    }
    if (D_8011A240.unk10 != 0 || D_8011A240.unk14 != 0) {
        D_800A4BA4[arg0] &= ~1;
        D_800A4BA4[arg0] &= ~2;
    }
    if (moved != 0) {
        if (D_8011A240.unk3C * D_8011A240.unk40 < 0) {
            D_8011A240.unk3C = 0;
        }
        D_8011A240.unk3C = D_8011A240.unk3C + D_8011A240.unk40;
        D_8011A240.unk30 = D_8011A240.unk30 + D_8011A240.unk40;
        func_8002D4C4(0x57);
    }
    if (D_8011A240.unk14 == 0 && D_8011A240.unk10 == 0) {
        D_8011A240.unk3C = 0;
    }
    if (D_8011A240.unk34 != D_8011A240.unk30 || D_8011A240.unk10 != 0 || D_8011A240.unk14 != 0) {
        func_80064A88(D_800AD444 * arg1);
        if (D_8011A240.unk00 == 0.0f) {
            D_8011A240.unk34 = D_8011A240.unk30;
        }
    } else if (D_8011A240.unk10 == 0 && D_8011A240.unk14 == 0 && arg2 != 0) {
        func_80064A88(D_800AD448 * arg1);
    }
}
