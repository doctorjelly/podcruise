/* Independently written from the specification for func_800895E0. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 pad00[0x1C];
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ u16 unk20;
    /* 0x22 */ u8 pad22[0x6];
    /* 0x28 */ s32 unk28;
    /* 0x2C */ u8 pad2C[0x4];
} Slot;

typedef struct {
    /* 0x00 */ u8 pad00[0x3C];
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ Slot *unk40;
} Manager;

void func_800895E0(Manager *manager, s16 index, u8 value) {
    Slot *slots = manager->unk40;

    slots[index].unk20 = value;
}
