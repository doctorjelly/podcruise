/* Independently written from the specification for func_80088110. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s32 unk0C;
} Region;

void func_80088110(Region *region, u32 base, s32 size) {
    u32 slack = 16 - (base & 0xF);

    if (slack != 16) {
        region->unk00 = base + slack;
    } else {
        region->unk00 = base;
    }
    region->unk04 = region->unk00;
    region->unk08 = size;
    region->unk0C = 0;
}
