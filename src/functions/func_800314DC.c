/* Independently written from scratchpad spec specs/func_800314DC.md. */

#include "podcruise/types.h"
typedef struct PcSlot {
    u8 unk00[4];
    u16 unk04;
    u16 unk06;
    s16 unk08;
    u8 unk0A[0xC];
    s16 unk16;
    u8 unk18[4];
} PcSlot;
extern PcSlot D_800DB8A0[];
void func_800314DC(s32 index, u16 value, s32 active, s32 mode) {
    PcSlot *slot = &D_800DB8A0[index];
    if (slot->unk06 == 0 || slot->unk04 != value || active == 0) {
        slot->unk06 = 0x8000;
    }
    slot->unk04 = value;
    slot->unk16 = value;
    if (active != 0) {
        if (mode != 0) {
            slot->unk08 = 2;
        } else {
            slot->unk08 = 1;
        }
    } else {
        slot->unk08 = -1;
    }
}
