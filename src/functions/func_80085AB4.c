/* Recovered per specs/func_80085AB4.md (histogram accumulation and weighted mean). */
#include "podcruise/types.h"

extern u16 *D_800A68B0;
extern s16 D_80114470[];
extern s32 D_801488C8[];
extern s32 D_80148948[];
extern s32 D_801489C8[];

f32 func_80085AB4(void) {
    u16 *samples;
    s32 index;
    s32 value;
    f32 total;

    samples = D_800A68B0;
    index = 0;
    do {
        D_801488C8[index] = 0; D_80148948[index] = 0; index++;
    } while (&D_80148948[index] < D_801489C8);

    for (index = 0; index < D_80114470[1] * D_80114470[0]; index++) {
        value = *samples;
        D_801488C8[(value >> 1) & 0x1F]++;
        D_80148948[(value >> 11) & 0x1F]++;
        samples++;
    }

    total = 0.0f;
    for (index = 2; index < 16; index++) {
        total = total + ((f32)(D_80148948[index] >> 2) / 19200.0f) * (f32)(index - 1);
    }
    return total;
}
