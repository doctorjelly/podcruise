/* Independently written from the specification for func_8008D7D0. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s16 unk08[16];
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
} Unk8008D7D0;

void func_8008D7D0(Unk8008D7D0 *entry) {
    s32 index;
    s32 scaled;
    s16 half;
    f64 ratio;
    f64 power;

    scaled = entry->unk00 * 0x4000;
    half = scaled >> 15;
    entry->unk02 = 0x4000 - half;
    entry->unk2C = 1;
    for (index = 0; index < 8; index++) {
        entry->unk08[index] = 0;
    }
    ratio = (f64)half / 16384.0;
    entry->unk08[index] = half;
    power = ratio;
    for (index++; index < 16; index++) {
        power = power * ratio;
        entry->unk08[index] = (s16)(power * 16384.0);
    }
}
