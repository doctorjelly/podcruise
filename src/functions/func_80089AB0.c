/* Independently written from scratchpad spec specs/func_80089AB0.md. */

#include "podcruise/types.h"

typedef struct PcCommandSlot {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u8 unk2;
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 unk5;
    /* 0x6 */ u8 unk6;
    /* 0x7 */ u8 unk7;
} PcCommandSlot;

extern u32 D_80149C70[15];
extern s32 D_80149CAC;
extern u8 D_80149CB1;

void func_80089AB0(u8 channel) {
    PcCommandSlot *cursor;
    PcCommandSlot slot;
    s32 i;

    for (i = 0; i < 15; i++) {
        D_80149C70[i] = 0;
    }

    D_80149CAC = 1;
    cursor = (PcCommandSlot *)D_80149C70;

    slot.unk0 = 0xFF;
    slot.unk1 = 1;
    slot.unk2 = 3;
    slot.unk3 = channel;
    slot.unk4 = 0xFF;
    slot.unk5 = 0xFF;
    slot.unk6 = 0xFF;
    slot.unk7 = 0xFF;

    for (i = 0; i < D_80149CB1; i++) {
        *cursor = slot;
        cursor++;
    }

    cursor->unk0 = 0xFE;
}
