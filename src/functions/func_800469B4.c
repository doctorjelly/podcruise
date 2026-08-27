/* Specification: scratchpad specs/func_800469B4.md (race mode change announcer). */
#include "podcruise/types.h"

typedef struct Race {
    u8 pad0[8];
    s32 mode;
    s32 previousMode;
    u8 pad10[4];
    s32 flags;
    u8 pad18[0x20];
    s32 stage;
    s32 previousStage;
    u8 pad40[0x14];
    f32 unk54;
    f32 unk58;
    u8 pad5C;
} Race;

typedef struct Timer {
    u8 pad0[0x38];
    f32 unk38;
    s32 unk3C;
    s32 unk40;
} Timer;

extern s16 D_800A219C;
extern s32 D_800A2198;
extern s32 D_800A4BBC;
extern s32 D_800A4BDC;
extern Timer D_8011A240;
extern s32 D_80118EF8;

extern char D_800AAD20[];
extern char D_800AAD28[];
extern char D_800AAD30[];
extern char D_800AAD3C[];
extern char D_800AAD44[];
extern char D_800AAD50[];
extern char D_800AAD5C[];
extern char D_800AAD6C[];
extern char D_800AAD80[];
extern char D_800AAD90[];
extern char D_800AADA0[];
extern char D_800AADB0[];

extern void func_8000953C(s32, s32);
extern void func_8000955C(s32, s32);
extern void func_80039EC0(s32);
extern void func_8004BE90(Race *);
extern void func_8004CA50(Race *);
extern s32 func_8008A6B4(char *buffer, const char *format, ...);

#define PADDING_ONE 1
#define PADDING_TWO 2
#ifndef PADDING_WORDS
#define PADDING_WORDS PADDING_TWO
#endif

static const s32 padding[PADDING_WORDS] = { 0 };

void func_800469B4(Race *race, s32 mode) {
    char message[256];

    if (race == 0) {
        for (;;) {
        }
    }
    if (race->flags == 0) {
        for (;;) {
        }
    }
    if (race->flags & 1) {
        D_800A219C = 0;
        race->previousMode = race->mode;
        race->previousStage = race->stage;
        race->mode = mode;
        D_800A2198 = -1;
        D_800A4BBC = 1;
        race->pad5C = 1;
        race->unk54 = 0.0f;
        race->unk58 = 0.0f;
        if (D_800A4BDC != 0 || race->stage == 3 ||
            (race->previousMode != 3 && race->mode != 3)) {
            if (race->mode != 0) {
                func_8004BE90(race);
                func_8004CA50(race);
            }
            D_8011A240.unk38 = 0.0f;
            D_8011A240.unk3C = 0;
            D_8011A240.unk40 = 0;
            race->flags |= 4;
        }
    }
    switch (race->mode) {
    case 0:
        func_8008A6B4(message, D_800AAD20);
        break;
    case 1:
        func_8008A6B4(message, D_800AAD28);
        break;
    case 2:
        func_8008A6B4(message, D_800AAD30);
        break;
    case 7:
        func_8008A6B4(message, D_800AAD3C);
        break;
    case 3:
        func_8008A6B4(message, D_800AAD44);
        break;
    case 4:
        func_8008A6B4(message, D_800AAD50);
        break;
    case 5:
        func_8008A6B4(message, D_800AAD5C);
        break;
    case 8:
        func_8008A6B4(message, D_800AAD6C);
        break;
    case 9:
        func_8008A6B4(message, D_800AAD80);
        break;
    case 12:
        func_8008A6B4(message, D_800AAD90);
        break;
    case 13:
        func_8008A6B4(message, D_800AADA0);
        break;
    default:
        func_8008A6B4(message, D_800AADB0);
        break;
    }
    switch (race->mode) {
    case 1:
    case 2:
    case 5:
    case 9:
    case 12:
    case 13:
        func_8000953C(0, 0x80000000);
        break;
    default:
        func_8000955C(0, 0x80000000);
        break;
    }
    switch (race->mode) {
    case 0:
    case 1:
        func_80039EC0(0);
        break;
    case 3:
        switch (race->stage) {
        case 0:
            func_80039EC0(5);
            break;
        case 1:
            func_80039EC0(6);
            break;
        case 2:
            func_80039EC0(4);
            break;
        case 3:
            func_80039EC0(1);
            break;
        default:
            func_80039EC0(1);
            break;
        }
        break;
    case 4:
        if (race->previousStage != 1) {
            func_8000953C(0, 0x20);
            func_8000955C(0, 1);
        }
        func_80039EC0(6);
        break;
    case 7:
        if (race->previousStage != 0 ||
            (race->previousStage == 0 && race->previousMode == 3)) {
            func_8000953C(0, 0x20);
            func_8000953C(0, 1);
        }
        func_80039EC0(5);
        break;
    case 8:
        func_80039EC0(4);
        break;
    case 16:
        func_80039EC0(7);
        break;
    case 15:
        func_80039EC0(2);
        break;
    case 17:
    default:
        func_80039EC0(1);
        break;
    }
    D_80118EF8 = race->mode;
}
