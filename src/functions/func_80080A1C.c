/* Independently written from scratchpad spec specs/func_80080A1C.md. */

#include "podcruise/types.h"

typedef struct Unk80080A1C {
    char unk_00[0x60];
    u32 unk_60;
    char unk_64[0xAC - 0x64];
    f32 unk_AC;
    char unk_B0[0xE0 - 0xB0];
    f32 unk_E0;
    f32 unk_E4;
    f32 unk_E8;
    char unk_EC[0x110 - 0xEC];
    f32 unk_110;
    s32 unk_114;
} Unk80080A1C;

extern f32 func_8008035C(void *arg0);
extern s32 D_800A6704;
extern f32 D_800ADC70;
extern f32 D_800ADC74;
extern f32 D_800ADC78;
extern f32 D_800ADC7C;
extern f64 D_80120BF0;

s32 func_80080A1C(Unk80080A1C *object, s32 force) {
    s32 result;
    s32 hit;
    f32 previous;

    result = 0;
    if (object->unk_60 & 0x4000) {
        force = 1;
    }
    object->unk_E4 = object->unk_E0;
    object->unk_E0 = func_8008035C(&object->unk_AC);
    if (object->unk_114 >= 9) {
        object->unk_110 = 0.0f;
    } else {
        object->unk_110 += (f32)D_80120BF0;
    }
    if (force) {
        if (!(D_800ADC70 < object->unk_E0 && object->unk_E4 < D_800ADC74)) {
            previous = object->unk_E8;
            if (object->unk_E0 < D_800ADC78) {
                if (D_800ADC70 < previous) {
                    previous -= 1.0f;
                }
                if (D_800ADC70 < object->unk_E4) {
                    object->unk_E4 -= 1.0f;
                }
            }
            if (D_800A6704 >= 0) {
                hit = object->unk_E0 >= 1.0f;
                object->unk_110 = 0.0f;
                if (hit) {
                    result = 1;
                }
                object->unk_E8 = object->unk_E0;
            } else if (previous < object->unk_E0 && object->unk_E4 - D_800ADC7C <= previous) {
                hit = previous < 0.0f;
                object->unk_110 = 0.0f;
                if (hit) {
                    result = 1;
                }
                object->unk_E8 = object->unk_E0;
            }
        }
    }
    return result;
}
