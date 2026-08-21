/* Independently written from scratchpad spec specs/func_80033C70.md. */

#include "podcruise/types.h"

extern s32 D_800A31E0[];
extern f32 D_800A5CA0[];
extern u8 D_800AA640[];
extern u8 D_800AA648[];
extern f32 D_800AAA90;
extern f32 D_800AAA94;
extern f32 D_800AAA98;
extern f32 D_800AAA9C;
extern f32 D_800AAAA0;
extern f32 D_800AAAA4;
extern f32 D_800AAAA8;
extern f32 D_800AAAAC;
extern f32 D_800AAAB0;

void func_80033C70(void) {
    D_800A31E0[105] = 0x11B;
    D_800A31E0[106] = 0x11A;
    D_800A31E0[107] = 0x11E;
    D_800A31E0[109] = (s32)(long)D_800AA640;
    D_800A31E0[110] = (s32)(long)D_800AA648;
    D_800A31E0[116] = 0x120;

    D_800A5CA0[219] = D_800AAA90;
    D_800A5CA0[231] = D_800AAA94;
    D_800A5CA0[232] = D_800AAA98;
    D_800A5CA0[233] = 0.0f;
    D_800A5CA0[225] = D_800AAA9C;
    D_800A5CA0[226] = D_800AAAA0;
    D_800A5CA0[227] = D_800AAAA4;
    D_800A5CA0[228] = D_800AAAA8;
    D_800A5CA0[229] = D_800AAAAC;
    D_800A5CA0[230] = D_800AAAB0;
}
