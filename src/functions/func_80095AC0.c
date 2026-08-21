/* Independently written from scratchpad spec specs/func_80095AC0.md. */

#include "podcruise/types.h"

struct Wave80095AC0 {
    u8 pad00[0x10];
    f32 rate;    /* 0x10 */
    f32 phase;   /* 0x14 */
    f32 unk18;   /* 0x18 */
    f32 scale;   /* 0x1C */
};

f32 func_80095AC0(struct Wave80095AC0 *wave, s32 steps) {
    f32 value;

    wave->phase = wave->phase + wave->rate * steps;
    wave->phase = (wave->phase > 2.0) ? (wave->phase - 4.0) : wave->phase;
    value = wave->phase;
    if (value < 0.0f) {
        value = -value;
    }
    value = value - 1.0;
    return wave->scale * value;
}
