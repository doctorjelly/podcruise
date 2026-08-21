/* Independently written from the specification for the entry-order table build. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 unk00[0x70];
    /* 0x70 */ signed char unk70;
} EntryOwner;

extern s32 D_800A4B7C[4];

void func_8004F6E8(EntryOwner *owner) {
    s32 count;
    s32 slot;
    s32 i;

    count = owner->unk70;
    for (i = 0; i < 4; i++) {
        D_800A4B7C[i] = -1;
    }
    slot = 0;
    for (i = 0; i < count; i++) {
        D_800A4B7C[slot] = i;
        slot++;
    }
}
