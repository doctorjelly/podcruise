/* Independently written from the specification for func_80087FC0. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 *unk00;
    /* 0x04 */ u8 *unk04;
    /* 0x08 */ u32 unk08;
    /* 0x0C */ s32 unk0C;
} Region;

u8 *func_80087FC0(const char *unused0, s32 unused1, Region *region, u32 count, u32 size) {
    u32 span = (count * size + 0xF) & ~0xF;
    u8 *result = 0;

    (void)unused0;
    (void)unused1;
    if (region->unk00 + region->unk08 >= region->unk04 + span) {
        result = region->unk04;
        region->unk04 = result + span;
    }
    return result;
}
