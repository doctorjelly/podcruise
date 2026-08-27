/* Recovered per specs/func_8001E6C0.md (options-menu draw and input handler). */
#include "podcruise/types.h"

typedef struct {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7;
    s32 unk8;
} OptionsState;

typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[0x5C];
    s8 unk70;
} MenuContext;

extern u32 D_80000318;
extern s32 D_800A2520;
extern s32 D_800A2524;
extern s32 D_800A4B94[];
extern s32 D_800A4BA4[];
extern s32 D_800A4BB4;
extern u8 D_800A8D48[];
extern u8 D_800A8D50[];
extern u8 D_800A8D5C[];
extern u8 D_800A8D64[];
extern u8 D_800A8D70[];
extern u8 D_800A8D7C[];
extern u8 D_800A8D88[];
extern u8 D_800A8D90[];
extern u8 D_800A8DA4[];
extern u8 D_800A8DAC[];
extern u8 D_800A8DB4[];
extern u8 D_800A8DC4[];
extern u8 D_800A8DD0[];
extern u8 D_800A8DDC[];
extern f64 D_800A9C30;
extern f64 D_800A9C38;
extern f32 D_800D711C;
extern f32 D_800D7120;
extern OptionsState D_80113680;
extern f32 D_80120BF8;

extern s32 func_80008B14(s32, s32, f32, f32, s32);
extern s32 func_8000A920(s16, s32);
extern s32 func_8000AA04(s16, s16, s16);
extern s32 func_8000AAC0(s16, f32, f32);
extern s32 func_8000AB24(s16, s32, s32, s32, s32);
extern s32 func_8002BBA4(MenuContext *, s32, s32, s32, s32, s32, u8 *);
extern s32 func_8002D4C4(s32);
extern s32 func_800399F0(void);
extern s32 func_80087814(s16, s16, s16, s16);

void func_8001E6C0(MenuContext *context) {
    OptionsState *state;
    s32 *buttons;
    f32 *rate;
    s32 index;
    s32 offset;
    s32 quit;
    s32 selection;
    s32 amount;
    s32 press;
    s32 hold;
    s16 id;
    f64 value;
    f64 step;

    D_800D7120 = 70.0f;
    D_800D711C = 165.0f;
    state = &D_80113680;
    quit = 0;
    id = (s16)(D_800A4BB4++ + 127);

    if (state->unk6 <= 0) {
        func_8002BBA4(context, 0xA5, (s32)D_800D7120, 0xF, D_800A2520, 0, D_800A8D48);
    } else {
        func_8000A920(id, 1);
        func_8000AA04(id, (s16)(s32)D_800D711C, (s16)(s32)D_800D7120);
        func_8000AAC0(id, (f32)(u32)state->unk6 * 80.0f / 255.0f * 0.125f + 0.125f, 1.0f);
        func_8000AB24(id, 0x32, 0xFF, 0xFF, 0xFF);
        func_80087814((s16)(s32)(D_800D711C - 2.0f), (s16)(s32)(D_800D7120 - 2.0f),
                      (s16)(s32)(D_800D711C + 84.0f), (s16)(s32)(D_800D7120 + 12.0f));
    }
    func_8002BBA4(context, 0x9B, (s32)D_800D7120, 0xF, D_800A2520, 0, D_800A8D50);

    id = (s16)(D_800A4BB4++ + 127);
    if (state->unk5 <= 0) {
        func_8002BBA4(context, 0xA5, (s32)D_800D7120, 0xF, D_800A2520, 1, D_800A8D5C);
    } else {
        func_8000A920(id, 1);
        func_8000AA04(id, (s16)(s32)D_800D711C, (s16)(s32)(D_800D7120 + 15.0f));
        func_8000AAC0(id, (f32)(u32)state->unk5 * 80.0f / 255.0f * 0.125f + 0.125f, 1.0f);
        func_8000AB24(id, 0x32, 0xFF, 0xFF, 0xFF);
        func_80087814((s16)(s32)(D_800D711C - 2.0f), (s16)(s32)(D_800D7120 + 15.0f - 2.0f),
                      (s16)(s32)(D_800D711C + 84.0f), (s16)(s32)(D_800D7120 + 15.0f + 12.0f));
    }
    func_8002BBA4(context, 0x9B, (s32)D_800D7120, 0xF, D_800A2520, 1, D_800A8D64);

    func_8002BBA4(context, 0x9B, (s32)D_800D7120, 0xF, D_800A2520, 2, D_800A8D70);
    if (state->unk8 & 1) {
        func_8002BBA4(context, 0xA5, (s32)D_800D7120, 0xF, D_800A2520, 2, D_800A8D7C);
    } else {
        func_8002BBA4(context, 0xA5, (s32)D_800D7120, 0xF, D_800A2520, 2, D_800A8D88);
    }
    func_8002BBA4(context, 0x9B, (s32)D_800D7120, 0xF, D_800A2520, 3, D_800A8D90);
    if (state->unk8 & 2) {
        func_8002BBA4(context, 0xA5, (s32)D_800D7120, 0xF, D_800A2520, 3, D_800A8DA4);
    } else {
        func_8002BBA4(context, 0xA5, (s32)D_800D7120, 0xF, D_800A2520, 3, D_800A8DAC);
    }
    func_8002BBA4(context, 0x9B, (s32)D_800D7120, 0xF, D_800A2520, 4, D_800A8DB4);
    if ((D_80000318 >= 0x800000) && (state->unk8 & 0x10)) {
        func_8002BBA4(context, 0xA5, (s32)D_800D7120, 0xF, D_800A2520, 4, D_800A8DC4);
    } else {
        func_8002BBA4(context, 0xA5, (s32)D_800D7120, 0xF, D_800A2520, 4, D_800A8DD0);
    }
    func_8002BBA4(context, 0xA0, (s32)D_800D7120, 0xF, D_800A2520, 5, D_800A8DDC);

    buttons = D_800A4BA4;
    index = 0;
    offset = 0;
    rate = &D_80120BF8;
    press = 0x10000;
    hold = 0x20000;
    if (context->unk70 > 0) {
        do {
            if (buttons[0] & 1) {
                func_8002D4C4(0x4D);
                quit = 1;
            }
            if (buttons[0] & 2) {
                func_8002D4C4(0x4D);
                quit = 1;
            }
            if (quit) {
                func_800399F0();
                context->unk10 = 0;
                return;
            }
            if (buttons[0] & 0x8000) {
                D_800A2520 = D_800A2520 + 1;
                if (D_800A2524 < D_800A2520) {
                    D_800A2520 = 0;
                }
                func_8002D4C4(0x57);
            }
            if (buttons[0] & 0x4000) {
                D_800A2520 = D_800A2520 - 1;
                if (D_800A2520 < 0) {
                    D_800A2520 = D_800A2524;
                }
                func_8002D4C4(0x57);
            }
            if ((buttons[0] & press) || (buttons[0] & hold)) {
                if (D_800A2520 == 2) {
                    state->unk8 ^= 1;
                }
                if (D_800A2520 == 3) {
                    state->unk8 ^= 2;
                }
                if (D_800A2520 == 4) {
                    if (D_80000318 >= 0x800000) {
                        state->unk8 ^= 0x10;
                    } else {
                        func_8002D4C4(0x4B);
                    }
                }
                selection = D_800A2520;
                if ((selection >= 2) && (selection != 5) &&
                    ((selection < 4) || (D_80000318 >= 0x800000))) {
                    func_8002D4C4(0x57);
                }
            }
            if (D_800A2520 == 0) {
                if (D_800A4B94[offset] & 0x20000) {
                    amount = state->unk6;
                    if (amount < 0xFF) {
                        value = (f64)(u32)amount + D_800A9C38 * (f64)*rate;
                        if (D_800A9C30 < value) {
                            state->unk6 = 0xFF;
                        } else {
                            state->unk6 = (u32)value;
                        }
                    }
                }
                if (D_800A4B94[offset] & 0x10000) {
                    amount = state->unk6;
                    if (amount > 0) {
                        value = (f64)(u32)amount;
                        step = D_800A9C38 * (f64)*rate;
                        if (value < step) {
                            state->unk6 = 0;
                        } else {
                            state->unk6 = (u32)(value - step);
                        }
                    }
                }
                func_80008B14(0x93, 6, 0.25f, 1.0f, 1);
            } else if (D_800A2520 == 1) {
                if (D_800A4B94[offset] & 0x20000) {
                    amount = state->unk5;
                    if (amount < 0xFF) {
                        value = (f64)(u32)amount + D_800A9C38 * (f64)*rate;
                        if (D_800A9C30 < value) {
                            state->unk5 = 0xFF;
                        } else {
                            state->unk5 = (u32)value;
                        }
                    }
                }
                if (D_800A4B94[offset] & 0x10000) {
                    amount = state->unk5;
                    if (amount > 0) {
                        value = (f64)(u32)amount;
                        step = D_800A9C38 * (f64)*rate;
                        if (value < step) {
                            state->unk5 = 0;
                        } else {
                            state->unk5 = (u32)(value - step);
                        }
                    }
                }
                func_80008B14(0x4F, 6, 0.125f, 1.0f, 1);
            }
            index++;
            offset++;
            buttons++;
        } while (index < context->unk70);
    }
}
