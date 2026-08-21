/* Independently written from scratchpad spec specs/func_80089CC0.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u8 unk2;
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u16 unk4;
    /* 0x6 */ signed char unk6;
    /* 0x7 */ signed char unk7;
} PcCmd;

extern s32 D_80149C70[];
extern u8 D_80149CB1;

void func_80089CC0(void) {
    PcCmd *entry;
    PcCmd item;
    s32 index;

    entry = (PcCmd *)D_80149C70;

    for (index = 0; index < 15; index++) {
        D_80149C70[index] = 0;
    }
    D_80149C70[15] = 1;

    item.unk0 = 0xFF;
    item.unk1 = 1;
    item.unk2 = 4;
    item.unk3 = 1;
    item.unk4 = 0xFFFF;
    item.unk6 = -1;
    item.unk7 = -1;

    for (index = 0; index < D_80149CB1; index++) {
        *entry++ = item;
    }
    entry->unk0 = 0xFE;
}
