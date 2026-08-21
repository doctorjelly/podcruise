/* Independently written from scratchpad spec specs/func_8008A5F8.md. */

#include "podcruise/types.h"

typedef union {
    /* 0x0 */ u16 half;
    struct {
        /* 0x0 */ u8 hi;
        /* 0x1 */ u8 lo;
    } b;
} PcLink;

typedef struct {
    /* 0x00 */ u8 unk00[0x60];
    /* 0x60 */ s32 unk60;
} PcLinkOwner;

s32 func_8008A5F8(PcLinkOwner *owner, PcLink *table, u8 low, u8 high, PcLink *out) {
    PcLink cur;
    PcLink prev;

    cur.half = (high << 8) + low;
    do {
        prev = cur;
        cur = table[cur.b.lo];
        table[prev.b.lo].half = 3;
    } while (cur.half >= owner->unk60 && cur.b.hi == high);
    *out = cur;
    return 0;
}
