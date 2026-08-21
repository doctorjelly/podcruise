/* Independently written from scratchpad spec specs/func_8008035C.md. */

#include "podcruise/types.h"
typedef struct Unk8008035C { char unk_00[0x8]; f32 unk_08; } Unk8008035C;
extern s32 func_8003A568(Unk8008035C *arg0, s32 arg1);
extern s32 D_800A6704;
extern f32 D_800ADC5C;
extern f32 D_80120408[][2];
f32 func_8008035C(Unk8008035C *arg0) {
    f32 value;
    s32 index;
    index = func_8003A568(arg0, 0);
    value = D_80120408[index][0] + (D_80120408[index][1] * arg0->unk_08);
    if (D_800A6704 >= 0) {
        if (value > 1.0f) {
            return 1.0;
        }
        return value;
    }
    if (value >= 1.0f) {
        return D_800ADC5C;
    }
    return value;
}
