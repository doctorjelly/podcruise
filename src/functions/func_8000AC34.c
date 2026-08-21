/* Independently written from the specification for the object flag setters. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u32 unk00[5];
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u8 unk18[4];
    /* 0x1C */ void *unk1C;
} ObjectSlot;

extern ObjectSlot D_800D2190[];

void func_8000AC34(s16 index, u32 bits) {
    D_800D2190[index].unk14 |= bits;
}
