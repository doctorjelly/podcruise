/* Recovered from the specification in scratchpad specs/func_80010080.md */
#include "podcruise/types.h"

extern f32 D_800A3FDC[3];
extern f32 D_800A86A0;
extern f32 D_800A86A4;
extern u8 D_800A8670[];
extern u8 D_800A8678[];
extern f32 D_800D59B8[20][3];
extern s32 D_800D5AA8[20];
extern s32 D_800D5AF8[20];
extern s32 D_800D5B48[20];
extern s32 D_800D5B98[20];
extern s32 D_800D5BE8[20];
extern s32 D_800D5FD0[20];
extern s32 D_800D6020[20];
extern s16 D_80114470;
extern s16 D_80114472;

extern f32 func_80015470(f32 *from, f32 *to);
extern void func_8000EBE8(s16 *object, f32 *position, f32 *outX, f32 *outY,
                          f32 *outScale, f32 *outDepth, s32 mode);
extern s32 func_8001004C(s32 encoded);
extern s32 func_8002F054(void);
extern s32 func_8008A6B4(u8 *buffer, u8 *format, s32 value);
extern void func_8000E7F0(s32 x, s32 y, s32 red, s32 green, s32 blue,
                          s32 alpha, u8 *text);

void func_80010080(s16 *arg0, s32 arg1) {
    f32 screenX;
    f32 screenY;
    u8 text[16];
    f32 scale;
    f32 depth;
    f32 alpha;
    f32 fade;
    f32 distance;
    s32 index;
    s32 limit;
    s32 maximum;

    fade = D_800A86A0;
    for (index = 0; index < 20; index++) {
        if (arg1 == 0) {
            D_800D5AF8[index] = -1000;
            D_800D5B48[index] = -1000;
        } else {
            D_800D5B98[index] = -1000;
            D_800D5BE8[index] = -1000;
        }
        if (D_800D5AA8[index] == -9999) {
            continue;
        }
        distance = func_80015470(D_800D59B8[index], D_800A3FDC);
        if (!(distance > 40.0f)) {
            continue;
        }
        if (!(distance < fade)) {
            continue;
        }
        if (distance < 400.0f) {
            alpha = 255.0f;
        } else {
            alpha = ((fade - distance) * (f32)255.0) / D_800A86A4;
        }
        if (alpha > 128.0f) {
            alpha = 128.0f;
        }
        if (func_8002F054() != 0) {
            alpha = alpha / (f32)2.0;
        }
        func_8000EBE8(arg0, D_800D59B8[index], &screenX, &screenY, &scale,
                      &depth, 0);
        if (!(screenX > -4.0f)) {
            continue;
        }
        if (D_800D5AA8[index] >= 0) {
            screenY = screenY - 13.0f;
            screenX = screenX - 4.0f;
        } else {
            screenY = screenY - 20.0f;
            screenX = screenX - 8.0f;
        }
        if (!(screenX < (f32)D_80114470)) {
            continue;
        }
        if (!(screenY > 0.0f)) {
            continue;
        }
        if (!(screenY < (f32)D_80114472)) {
            continue;
        }
        if (arg1 == 0) {
            D_800D5AF8[index] = (s32)screenX;
            D_800D5B48[index] = (s32)screenY;
        } else {
            D_800D5B98[index] = (s32)screenX;
            D_800D5BE8[index] = (s32)screenY;
        }
        limit = (s32)(((scale * (f32)arg0[10]) + (f32)arg0[14]) * 256.0f);
        if (arg1 == 0) {
            maximum = func_8001004C(D_800D5FD0[index]);
        } else {
            maximum = func_8001004C(D_800D6020[index]);
        }
        if (limit >= 0 && limit >= maximum) {
            continue;
        }
        if (D_800D5AA8[index] >= 0) {
            func_8008A6B4(text, D_800A8670, D_800D5AA8[index]);
            func_8000E7F0((s16)(s32)screenX, (s16)(s32)screenY, 255, 255, 255,
                          (u32)alpha, text);
        } else {
            func_8008A6B4(text, D_800A8678, -D_800D5AA8[index]);
            func_8000E7F0((s16)(s32)screenX, (s16)(s32)screenY, 255, 255, 0,
                          ((u32)alpha & 0xFF) + 0x28, text);
        }
    }
}
