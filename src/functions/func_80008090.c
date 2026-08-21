/* Independently written from the specification scratchpad/specs/func_80008090.md. */
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
extern f64 D_800A81D0;
extern f64 D_800A81D8;
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
    Entry80008090 *shadow;
    Entry80008090 *state;
    s32 spare;
    s32 changed;
    s32 level;
    s32 id;
    s32 target;
    s32 current;
    f64 value;
    register f64 floor;

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

    shadow = D_800D1F38;
    state = D_800D2038;
    floor = D_800A81D0;
    do {
        if (state->unk08 != 0) {
            if ((D_80120BE8 != state->unk0C) && (D_80120BE8 != state->unk0C + 1)) {
                value = D_800A81D8 * D_80120BF0;
                state->unk18 = (s32)((f64)state->unk18 - value);
                if ((f64)state->unk18 <= 0.0) {
                    state->unk18 = 0;
                    state->unk00 = -1;
                    state->unk08 = 0;
                    state->unk0C = -1;
                }
            }
        }
        if (shadow->unk00 != -1) {
            func_80088B00(D_8009A2BC, shadow->unk00);
            if ((func_80089570(D_8009A2BC) == 2) || (func_80089570(D_8009A2BC) == 0)) {
                id = shadow->unk00;
                if (state->unk00 == id) {
                    state->unk00 = -1;
                }
                func_80089590(D_8009A2BC, id);
                shadow->unk00 = -1;
                shadow->unk04 = -1;
            } else if (func_8000803C(D_8009A2BC, shadow->unk00) != 0) {
                func_80088B00(D_8009A2BC, shadow->unk00);
                func_80088B20(D_8009A2BC);
                func_800895E0(D_8009A2BC, shadow->unk00, 0);
                shadow->unk10 = 0;
            }
        }
        if (shadow->unk00 == state->unk00) {
            if (shadow->unk00 >= 0) {
                func_80088B00(D_8009A2BC, shadow->unk00);
                if (changed != 0) {
                    func_80089610(D_8009A2BC, D_8009A320);
                }
                if ((state->unk18 != shadow->unk18) || (D_8009A328 < 0x7D00)) {
                    level = state->unk18;
                    if (D_8009A328 < level) {
                        level = D_8009A328;
                    }
                    func_80089670(D_8009A2BC, level);
                    shadow->unk18 = level;
                }
                if (state->unk14 != shadow->unk14) {
                    value = state->unk14;
                    func_800896D0(D_8009A2BC, (value < floor) ? (f32)floor : (f32)value);
                    shadow->unk14 = state->unk14;
                }
                if (state->unk1C != shadow->unk1C) {
                    func_80089730(D_8009A2BC, state->unk1C);
                    shadow->unk1C = state->unk1C;
                }
            }
        } else if (shadow->unk00 != -1) {
            if (shadow->unk10 != 0) {
                func_80088B00(D_8009A2BC, shadow->unk00);
                func_80088B20(D_8009A2BC);
                func_800895E0(D_8009A2BC, shadow->unk00, 0);
                shadow->unk10 = 0;
            }
        } else if (state->unk04 != -1) {
            state->unk00 = func_80007FC8(state->unk04);
            if (state->unk00 != -1) {
                func_80088B00(D_8009A2BC, state->unk00);
                value = state->unk14;
                func_800896D0(D_8009A2BC, (value < floor) ? (f32)floor : (f32)value);
                func_800895E0(D_8009A2BC, state->unk00, state->unk10);
                level = state->unk18;
                if (D_8009A328 < level) {
                    level = D_8009A328;
                }
                func_80089670(D_8009A2BC, level);
                func_80089730(D_8009A2BC, state->unk1C);
                func_80089610(D_8009A2BC, D_8009A320);
                func_80089790(D_8009A2BC);
                *shadow = *state;
            }
        }
        state++;
        shadow++;
    } while (shadow != D_800D2038);
}
