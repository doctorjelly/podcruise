/* Recovered from specs/functions/recovered/medium_pipeline_tranche.md. */
#include "podcruise/types.h"

#define FUNC_80051D2C_MODE_3_COUNT_US 0x4F
#define FUNC_80051D2C_MODE_4_COUNT_US 0x90
#define FUNC_80051D2C_MODE_5_COUNT_US 0x5B
#define FUNC_80051D2C_MODE_3_COUNT_JP 0x56
#define FUNC_80051D2C_MODE_4_COUNT_JP 0x89
#define FUNC_80051D2C_MODE_5_COUNT_JP 0x90

#ifndef FUNC_80051D2C_MODE_3_COUNT
#define FUNC_80051D2C_MODE_3_COUNT FUNC_80051D2C_MODE_3_COUNT_US
#endif

#ifndef FUNC_80051D2C_MODE_4_COUNT
#define FUNC_80051D2C_MODE_4_COUNT FUNC_80051D2C_MODE_4_COUNT_US
#endif

#ifndef FUNC_80051D2C_MODE_5_COUNT
#define FUNC_80051D2C_MODE_5_COUNT FUNC_80051D2C_MODE_5_COUNT_US
#endif

extern void func_8003EC40(s16 x, s16 y, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 *arg6);
extern void func_80051C80(void *object, u32 tag);
extern s32 func_8008A6B4(u8 *buffer, u8 *format, u8 *text);

extern u8 *D_800A5344[];
extern u8 *D_800A53D4[];
extern u8 *D_800A54AC[];
extern u8 *D_800A55E8[];
extern u8 *D_800A5828[];
extern s32 D_800A599C;
extern s32 D_800A59A0;
extern f32 D_800A59A4;
extern u8 D_800ACC24[];
extern u8 D_800ACC30[];
extern f64 D_80120BF0;

void func_80051D2C(void *object, s32 reset) {
    u8 text[0x114];
    s32 count;
    s32 index;
    s32 row;
    u8 *value;
    u8 *entry;
    u8 shade;
    u8 tint;

    if (reset != 0) {
        D_800A59A4 = 0.0f;
    }
    row = (s32)(240.0f - D_800A59A4 * 24.0f);
    D_800A59A4 = (f32)((f64)D_800A59A4 + D_80120BF0);
    count = 0x24;
    if (D_800A599C == 2) {
        count = 0x36;
    }
    if (D_800A599C == 3) {
        count = FUNC_80051D2C_MODE_3_COUNT;
    }
    if (D_800A599C == 4) {
        count = FUNC_80051D2C_MODE_4_COUNT;
    }
    if (D_800A599C == 5) {
        count = FUNC_80051D2C_MODE_5_COUNT;
    }
    for (index = 1; index < count; index++) {
        if (D_800A599C == 1) {
            entry = D_800A5344[index - 1];
            value = D_800A5344[index];
        }
        if (D_800A599C == 2) {
            entry = D_800A53D4[index - 1];
            value = D_800A53D4[index];
        }
        if (D_800A599C == 3) {
            entry = D_800A54AC[index - 1];
            value = D_800A54AC[index];
        }
        if (D_800A599C == 4) {
            entry = D_800A55E8[index - 1];
            value = D_800A55E8[index];
        }
        if (D_800A599C == 5) {
            entry = D_800A5828[index - 1];
            value = D_800A5828[index];
        }
        if (entry[0] == 0) {
            row += 0x28;
        } else if (entry[0] == 0x5C) {
            row += 0x18;
        } else {
            row += 0xC;
        }
        if (row >= -9 && row < 0xFA) {
            if (entry[0] == 0) {
                shade = 0xBE;
                tint = 0xBE;
                func_8008A6B4(text, D_800ACC24, value);
            } else {
                shade = 0xFF;
                tint = 0xFF;
                func_8008A6B4(text, D_800ACC30, value);
            }
            func_8003EC40(0xA0, (s16)row, tint, shade, 0xFF, 0xFF, text);
        }
    }
    if (row <= 0) {
        if (D_800A599C == 5 || D_800A59A0 != 0) {
            func_80051C80(object, 0x41627274);
        } else {
            func_80051C80(object, 0x46696E69);
        }
    }
}
