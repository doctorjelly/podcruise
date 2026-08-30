/* Independently written from specs/functions/recovered/func_800105DC.md. */

#include "podcruise/types.h"

extern f32 D_8009B8C8;
extern f32 D_800A3FDC;
extern f32 D_800A86A8;
extern u8 D_800D5C38[40];
extern f32 D_800D5C60[40][3];
extern s32 D_800D5E40[40];
extern s32 D_800D5EE0[40];
extern s32 D_800D5F80[10];
extern s32 D_800D5FA8[10];
extern s32 D_800D5FD0;
extern s32 D_800D60A0[40];
extern s16 D_80114470;
extern s16 D_80114472;

extern void func_8000A920(s16 index, s32 flag);
extern void func_8000AAC0(s16 index, f32 x, f32 y);
extern void func_8000AAF8(s16 index, f32 value);
extern void func_8000AB24(s16 index, s32 red, s32 green, s32 blue, s32 alpha);
extern void func_8000E680(s16 arg0, s16 arg1, s16 arg2);
extern void func_8000EBE8(s16 *object, f32 *position, f32 *outX, f32 *outY,
                          f32 *outZ, f32 *outW, s32 mode);
extern s32 func_8001004C(s32 encoded);
extern f32 func_80015470(f32 *from, f32 *to);
extern s32 func_8002F054(void);

void func_800105DC(s16 *object) {
    f32 alpha;
    f32 brightness;
    f32 screenX;
    f32 screenY;
    f32 radius;
    s32 pixel;
    s32 limit;
    s32 slot;
    s32 i;
    f32 depth;
    f32 scale;
    s32 *first;
    s32 *second;
    s32 shade;

    first = D_800D5F80;
    second = D_800D5FA8;
    do {
        func_8000A920((s16)*first, 0);
        func_8000A920((s16)*second, 0);
        second++;
        first++;
    } while (second < &D_800D5FD0);

    i = 0;
    slot = 0;
    for (; i < 40; i++) {
        D_800D5E40[i] = -1000;
        D_800D5EE0[i] = -1000;
        if (D_800D5C38[i] == 0) {
            continue;
        }
        if (!(func_80015470(D_800D5C60[i], &D_800A3FDC) < D_8009B8C8)) {
            continue;
        }
        if (func_8002F054()) {
            alpha = 128.0f;
        } else {
            alpha = 255.0f;
        }
        func_8000EBE8(object, D_800D5C60[i], &screenX, &screenY, &depth, &scale,
                      0);
        if (!(0.0f < screenX)) {
            continue;
        }
        if (scale <= D_800A86A8) {
            brightness = 1000.0f;
        } else {
            brightness = 100.0f / scale;
        }
        if (2.0f < brightness) {
            brightness = 2.0f;
        }
        if (!(screenX < (f32)D_80114470)) {
            continue;
        }
        if (!(0.0f < screenY)) {
            continue;
        }
        if (!(screenY < (f32)D_80114472)) {
            continue;
        }
        D_800D5E40[i] = (s32)screenX;
        D_800D5EE0[i] = (s32)screenY;
        pixel = (s32)((depth * (f32)object[10] + (f32)object[14]) * 256.0f);
        if (D_800D60A0[i] == -1000) {
            continue;
        }
        limit = func_8001004C(D_800D60A0[i]);
        if (pixel >= 0 && pixel >= limit) {
            continue;
        }
        radius = (160.0f - screenX) / 3.0f;
        if (slot >= 10) {
            continue;
        }
        first = &D_800D5F80[slot];
        second = &D_800D5FA8[slot];
        if (*first != -1) {
            func_8000A920((s16)*first, 1);
            func_8000E680((s16)*first, (s16)(s32)screenX, (s16)(s32)screenY);
            func_8000AAF8((s16)*first, radius);
            func_8000AAC0((s16)*first, 1.0f, 1.0f);
            func_8000AB24((s16)*first, 255, 255, 255, (u32)alpha);
        }
        if (*second != -1) {
            shade = (u32)alpha & 0xFF;
            func_8000A920((s16)*second, 1);
            func_8000E680((s16)*second, (s16)(s32)screenX, (s16)(s32)screenY);
            func_8000AAF8((s16)*second, radius);
            func_8000AAC0((s16)*second, brightness, brightness);
            func_8000AB24((s16)*second, 255, 255, 255, shade);
        }
        slot++;
    }
}
