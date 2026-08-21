/* Independently written from scratchpad spec specs/func_800320E0.md. */

#include "podcruise/types.h"

extern f32 sqrtf(f32 value);
#if defined(__sgi)
#pragma intrinsic (sqrtf)
#endif

extern f32 D_800AA3A0;
extern f32 D_800AA3A4;
extern f32 D_800AA3A8;

void func_800320E0(f32 *settings, f32 *source) {
    f32 minimum;
    u8 index;

    settings[0] = source[0] / 1.0f;
    settings[1] = source[1] / 1000.0f;
    settings[2] = 1.0f - (sqrtf(source[3] / 1.0f) / D_800AA3A0);
    settings[3] = (source[4] - 450.0f) / 200.0f;
    settings[4] = (8.0f / sqrtf(source[5] / 2.0f)) - D_800AA3A4;
    settings[5] = source[9] / 20.0f;
    settings[6] = source[11];

    minimum = D_800AA3A8;

    for (index = 0; index < 7; index++) {
        if (settings[index] < minimum) {
            settings[index] = minimum;
        }
        if (settings[index] > 1.0f) {
            settings[index] = 1.0f;
        }
    }
}
