/* Independently written from the specification for the object colour setter. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u32 unk00[5];
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u8 unk18[4];
    /* 0x1C */ void *unk1C;
} ObjectSlot;

extern ObjectSlot D_800D2190[];
extern u8 D_8009B77C[4];
extern u8 D_8009B780[4];

void func_8000AB24(s16 index, u8 red, u8 green, u8 blue, u8 alpha) {
    if (index == -0x67) {
        D_8009B77C[0] = red;
        D_8009B77C[1] = green;
        D_8009B77C[2] = blue;
        D_8009B77C[3] = alpha;
        return;
    }
    if (index == -0x68) {
        D_8009B780[0] = red;
        D_8009B780[1] = green;
        D_8009B780[2] = blue;
        D_8009B780[3] = alpha;
        return;
    }
    if (index >= 0) {
        D_800D2190[index].unk18[0] = red;
        D_800D2190[index].unk18[1] = green;
        D_800D2190[index].unk18[2] = blue;
        D_800D2190[index].unk18[3] = alpha;
    }
}
