/* Independently written from specs/functions/recovered/func_8002BBA4.md. */

#include "podcruise/types.h"

typedef struct ColorVector8002BBA4 {
    f32 red;
    f32 green;
    f32 blue;
} ColorVector8002BBA4;

typedef struct MenuContext8002BBA4 {
    /* 0x00 */ u8 pad00[8];
    /* 0x08 */ s32 state;
    /* 0x0C */ u8 pad0C[4];
    /* 0x10 */ s32 substate;
    /* 0x14 */ u8 pad14[0x58];
    /* 0x6C */ s8 flag6C;
} MenuContext8002BBA4;

extern ColorVector8002BBA4 D_800A2624;
extern ColorVector8002BBA4 D_800A2630;
extern ColorVector8002BBA4 D_800A263C;
extern ColorVector8002BBA4 D_800A2648;
extern f32 D_800A4B54;
extern u8 D_800A987C[];

extern void func_80014CC0(f32, f32 *, f32 *);
extern void func_80015630(
    ColorVector8002BBA4 *, f32, const ColorVector8002BBA4 *, f32,
    const ColorVector8002BBA4 *);
extern s32 func_80082BE0(void);
extern void func_80015268(ColorVector8002BBA4 *, f32, f32, f32);
extern void func_8000AB24(s16, u8, u8, u8, u8);
extern void func_8003EC40(s16, s16, u8, u8, u8, u8, s32);

#define COLOR_BYTE(value) ((u8)(u32)(value))

void func_8002BBA4(
    MenuContext8002BBA4 *context, s32 x, s32 y, s32 rowSpacing,
    s32 activeIndex, s32 labelIndex, u8 *label) {
    ColorVector8002BBA4 primary;
    ColorVector8002BBA4 secondary;
    ColorVector8002BBA4 blendStart;
    ColorVector8002BBA4 blendEnd;
    f32 trigValue;
    f32 otherTrigValue;
    f32 weight;
    s32 randomRed;
    s32 randomGreen;
    s16 drawY;

    primary = D_800A2624;
    secondary = D_800A2630;
    blendStart = D_800A263C;
    blendEnd = D_800A2648;

    if (activeIndex == labelIndex) {
        func_80014CC0(
            D_800A4B54 * 360.0f, &trigValue, &otherTrigValue);
        weight = (f32)((f64)(trigValue + 1.0f) * 0.5);
        func_80015630(
            &primary, weight, &blendStart,
            (f32)(1.0 - (f64)weight), &blendEnd);
    }

    if ((context->state == 9) && (context->substate == 3)) {
        randomRed = func_80082BE0();
        randomGreen = func_80082BE0();
        func_80015268(
            &primary,
            (f32)((s32)((f32)randomRed / 2147483648.0f * 129.0f) + 64),
            (f32)((s32)((f32)randomGreen / 2147483648.0f * 129.0f) + 64),
            (f32)((s32)((f32)func_80082BE0() / 2147483648.0f * 129.0f) +
                  64));
        func_80015268(&secondary, 25.0f, 128.0f, 128.0f);
    }

    if ((context->state == 9) && (context->substate == 0) &&
        (context->flag6C != 0) && (activeIndex == 4) && (labelIndex == 4)) {
        func_8003EC40(
            (s16)(x - 30),
            (s16)((u32)rowSpacing * (u32)labelIndex + (u32)y),
            COLOR_BYTE(primary.red),
            COLOR_BYTE(primary.green), COLOR_BYTE(primary.blue), 255,
            (s32)(unsigned long)D_800A987C);
    }

    drawY = (s16)((u32)rowSpacing * (u32)labelIndex + (u32)y);

    if ((context->state == 3) && (context->substate == 1)) {
        if ((activeIndex == 0) && (labelIndex == 0)) {
            func_8000AB24(
                0x7F, COLOR_BYTE(primary.red), COLOR_BYTE(primary.green),
                COLOR_BYTE(primary.blue), 255);
        }
        if ((activeIndex == 1) && (labelIndex == 1)) {
            func_8000AB24(
                0x80, COLOR_BYTE(primary.red), COLOR_BYTE(primary.green),
                COLOR_BYTE(primary.blue), 255);
        }
    }

    if (activeIndex == labelIndex) {
        func_8003EC40(
            (s16)x, drawY, COLOR_BYTE(primary.red),
            COLOR_BYTE(primary.green), COLOR_BYTE(primary.blue), 255,
            (s32)(unsigned long)label);
    } else {
        func_8003EC40(
            (s16)x, drawY, COLOR_BYTE(secondary.red),
            COLOR_BYTE(secondary.green), COLOR_BYTE(secondary.blue), 255,
            (s32)(unsigned long)label);
    }
}
