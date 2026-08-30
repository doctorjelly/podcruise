/* Independently written from specs/functions/recovered/func_80029298.md. */

#include "podcruise/types.h"

typedef struct {
    u8 pad00[8];
    f32 value0;
    u8 pad0C[8];
    f32 value1;
    s16 phase;
    u8 pad1A[6];
} PcEntry80029298;

extern PcEntry80029298 D_800A4C00[];
extern PcEntry80029298 D_800A5100[];

void func_80029298(f32 offset) {
    PcEntry80029298 *entry;

    entry = D_800A4C00;
    do {
        switch (entry->phase + 1) {
            case 1:
                entry->value0 = -60.0f + offset;
                break;
            case 2:
                entry->value0 = -157.0f + offset;
                entry->value1 = entry->value0;
                break;
            case 0:
            case 5:
                entry->value0 = -145.0f + offset;
                break;
            case 3:
                entry->value0 = -157.0f + offset;
                break;
        }
        entry++;
    } while (entry != D_800A5100);
}
