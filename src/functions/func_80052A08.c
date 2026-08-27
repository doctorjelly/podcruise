/* Independently written from the specification in specs/func_80052A08.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 pad000[0x8];
    /* 0x008 */ u32 unk008;
    /* 0x00C */ u8 pad00C[0x1D4];
    /* 0x1E0 */ s32 unk1E0;
    /* 0x1E4 */ f32 unk1E4;
} Screen;

extern s32 D_800A52B8;
extern f32 D_800A52C8;
extern f32 D_800A52CC;

extern void func_800862D8(s32, s32, s32, s32, s32);
extern void func_8008635C(s32, s32);
extern void func_80086730(s32, f32, f32, f32, f32, f32);
extern s32 func_80051FF4(void);
extern void func_8000A920(s16, s32);

static const s32 D_800ACE40[3] = { 0, 0, 0 };

void func_80052A08(Screen *screen, s32 request) {
    s32 players;
    s32 state;
    s32 left;
    s32 top;
    s32 bottom;
    s32 right;
    s32 splitTop;
    s32 nextState;
    f32 border;

    if (request != 0) {
        screen->unk1E0 = request;
        screen->unk1E4 = 0.0f;
    }

    top = 8;
    bottom = 232;
    right = 312;
    left = 8;
    splitTop = 119;
    nextState = 5;
    border = 0.0f;
    state = screen->unk1E0;
    if (state == 0) {
        return;
    }
    if (nextState == state) {
        return;
    }
    if (state == 4) {
        screen->unk1E0 = nextState;
        screen->unk1E4 = 1.0f;
    }

    func_800862D8(0, left, top, right, bottom);
    func_8008635C(2, -1);

    if ((screen->unk008 & 0x20) || (screen->unk008 & 0x40)) {
        func_8008635C(1, 7);
        func_800862D8(1, left, (s32)(top + border), right, (s32)(bottom - border));
        func_80086730(1, 100.0f, -1.0f, -1.0f, -1.0f, -1.0f);
        return;
    }

    players = func_80051FF4();
    func_8000A920(-201, 0);

    switch (screen->unk1E0) {
        case 1:
            func_8008635C(1, 5);
            func_800862D8(1, left, top, right, bottom);
            func_80086730(1, 100.0f, -1.0f, -1.0f, -1.0f, -1.0f);
            screen->unk1E0 = 0;
            break;
        case 2:
            border = 40.0f;
            func_8008635C(1, 5);
            func_800862D8(1, left, (s32)(top + border), right, (s32)(bottom - border));
            func_800862D8(0, left, (s32)(top + border), right, (s32)(bottom - border));
            func_80086730(1, 45.0f, -1.0f, D_800A52C8, D_800A52CC, -1.0f);
            return;
        case 3:
        case 4:
        case 5:
            func_8008635C(1, 7);
            if (players == 1 || players == 0) {
                func_800862D8(1, left, (s32)(top + border), right, (s32)(bottom - border));
                func_80086730(1, 100.0f, -1.0f, -1.0f, -1.0f, -1.0f);
                return;
            } else if (players == 2) {
                func_8008635C(2, 8);
                func_800862D8(1, left, top, (s32)(right - border), splitTop);
                func_800862D8(2, (s32)(top + border), 121, right, bottom);
                if (D_800A52B8 != 0) {
                    func_80086730(1, 120.0f, -1.0f, -1.0f, -1.0f, -1.0f);
                    func_80086730(2, 120.0f, -1.0f, -1.0f, -1.0f, -1.0f);
                    return;
                }
                func_80086730(1, 100.0f, -1.0f, -1.0f, -1.0f, -1.0f);
                func_80086730(2, 100.0f, -1.0f, -1.0f, -1.0f, -1.0f);
            }
            break;
    }
}
