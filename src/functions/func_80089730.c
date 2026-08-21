/* Independently written from specs/functions/func_80089730.md. */

#include "podcruise/types.h"

typedef struct {
    u8 unk00[0x30];
} PcSlot;

typedef struct {
    u8 unk00[0x14];
    u8 unk14[0x28];
    s32 unk3C;
    PcSlot *unk40;
} PcOwner;

typedef struct {
    s16 unk00;
    PcSlot *unk04;
    u8 unk08;
    s32 unk0C;
} PcNotice;

extern void func_8008FC3C(void *queue, void *notice, s32 deadline);

void func_80089730(PcOwner *owner, u8 value) {
    PcNotice notice;
    PcSlot *slots;

    slots = owner->unk40;
    notice.unk00 = 2;
    notice.unk08 = value;
    notice.unk04 = &slots[owner->unk3C];
    func_8008FC3C(owner->unk14, &notice, 0);
}
