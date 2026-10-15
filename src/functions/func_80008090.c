/* Independently written from specs/functions/recovered/func_80008090.md. */
#include "podcruise/types.h"

typedef struct {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    f32 unk14;
    s32 unk18;
    s16 unk1C;
    s16 unk1E;
} Entry80008090;

extern s32 D_8009A2BC;
extern u8 D_8009A320;
extern u8 D_8009A324;
extern s32 D_8009A328;


extern Entry80008090 D_800D1F38[8];
extern Entry80008090 D_800D2038[8];
extern s32 D_80120BE8;
extern f64 D_80120BF0;

extern s32 func_80007FC8(s32);
extern s32 func_8000803C(s32, s32);
extern void func_80088B00(s32, s16);
extern void func_80088B20(s32);
extern s32 func_80089570(s32);
extern void func_80089590(s32, s16);
extern void func_800895E0(s32, s16, u8);
extern void func_80089610(s32, u8);
extern void func_80089670(s32, s16);
extern void func_800896D0(s32, f32);
extern void func_80089730(s32, u8);
extern void func_80089790(s32);

void func_80008090(void) {
    f64 spare;
    s32 i;
    s32 changed;
    s32 level;
    s32 target;
    s32 current;
    f64 value;
    f64 floor;

    (void)spare;
    target = D_8009A324;
    current = D_8009A320;
    if (target == current) {
        changed = 0;
    } else {
        changed = 1;
        if (target < current) {
            if (current >= 16) {
                D_8009A320 = current - 15;
            } else {
                D_8009A320 = 0;
            }
            if (D_8009A320 < target) {
                D_8009A320 = D_8009A324;
            }
        } else if (current < target) {
            if (current < 250) {
                D_8009A320 = current + 15;
            } else {
                D_8009A320 = 255;
            }
            if (target < D_8009A320) {
                D_8009A320 = D_8009A324;
            }
        }
    }

    floor = 0.05;
    for (i = 0; i < 8; i++) {
        if (D_800D2038[i].unk08 != 0) {
            if ((D_80120BE8 != D_800D2038[i].unk0C) && (D_80120BE8 != D_800D2038[i].unk0C + 1)) {
                value = 64000.0 * D_80120BF0;
                D_800D2038[i].unk18 = (s32)((f64)D_800D2038[i].unk18 - value);
                if ((f64)D_800D2038[i].unk18 <= 0.0) {
                    D_800D2038[i].unk18 = 0;
                    D_800D2038[i].unk00 = -1;
                    D_800D2038[i].unk08 = 0;
                    D_800D2038[i].unk0C = -1;
                }
            }
        }
        if (D_800D1F38[i].unk00 != -1) {
            func_80088B00(D_8009A2BC, D_800D1F38[i].unk00);
            if ((func_80089570(D_8009A2BC) == 2) || (func_80089570(D_8009A2BC) == 0)) {
                if (D_800D2038[i].unk00 == D_800D1F38[i].unk00) {
                    D_800D2038[i].unk00 = -1;
                }
                func_80089590(D_8009A2BC, D_800D1F38[i].unk00);
                D_800D1F38[i].unk00 = -1;
                D_800D1F38[i].unk04 = -1;
            } else if (func_8000803C(D_8009A2BC, D_800D1F38[i].unk00) != 0) {
                func_80088B00(D_8009A2BC, D_800D1F38[i].unk00);
                func_80088B20(D_8009A2BC);
                func_800895E0(D_8009A2BC, D_800D1F38[i].unk00, 0);
                D_800D1F38[i].unk10 = 0;
            }
        }
        if (D_800D2038[i].unk00 == D_800D1F38[i].unk00) {
            if (D_800D1F38[i].unk00 >= 0) {
                func_80088B00(D_8009A2BC, D_800D1F38[i].unk00);
                if (changed != 0) {
                    func_80089610(D_8009A2BC, D_8009A320);
                }
                if ((D_800D1F38[i].unk18 != D_800D2038[i].unk18) || (D_8009A328 < 0x7D00)) {
                    level = D_800D2038[i].unk18;
                    if (D_8009A328 < level) {
                        level = D_8009A328;
                    }
                    func_80089670(D_8009A2BC, level);
                    D_800D1F38[i].unk18 = level;
                }
                if (D_800D1F38[i].unk14 != D_800D2038[i].unk14) {
                    value = D_800D2038[i].unk14;
                    func_800896D0(D_8009A2BC, (value < floor) ? (f32)floor : (f32)value);
                    D_800D1F38[i].unk14 = D_800D2038[i].unk14;
                }
                if (D_800D1F38[i].unk1C != D_800D2038[i].unk1C) {
                    func_80089730(D_8009A2BC, D_800D2038[i].unk1C);
                    D_800D1F38[i].unk1C = D_800D2038[i].unk1C;
                }
            }
        } else if (D_800D1F38[i].unk00 != -1) {
            if (D_800D1F38[i].unk10 != 0) {
                func_80088B00(D_8009A2BC, D_800D1F38[i].unk00);
                func_80088B20(D_8009A2BC);
                func_800895E0(D_8009A2BC, D_800D1F38[i].unk00, 0);
                D_800D1F38[i].unk10 = 0;
            }
        } else if (D_800D2038[i].unk04 != -1) {
            D_800D2038[i].unk00 = func_80007FC8(D_800D2038[i].unk04);
            if (D_800D2038[i].unk00 != -1) {
                func_80088B00(D_8009A2BC, D_800D2038[i].unk00);
                value = D_800D2038[i].unk14;
                func_800896D0(D_8009A2BC, (value < floor) ? (f32)floor : (f32)value);
                func_800895E0(D_8009A2BC, D_800D2038[i].unk00, D_800D2038[i].unk10);
                level = D_800D2038[i].unk18;
                if (D_8009A328 < level) {
                    level = D_8009A328;
                }
                func_80089670(D_8009A2BC, level);
                func_80089730(D_8009A2BC, D_800D2038[i].unk1C);
                func_80089610(D_8009A2BC, D_8009A320);
                func_80089790(D_8009A2BC);
                D_800D1F38[i] = D_800D2038[i];
            }
        }
    }
}
