/* Independently written from specs/functions/func_80089670.md. */

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
    s16 unk08;
    s32 unk0C;
} PcNotice;

extern void func_8008FC3C(void *queue, void *notice, s32 deadline);

void func_80089670(PcOwner *owner, s16 value) {
    PcNotice notice;
    PcSlot *slots;

    slots = owner->unk40;
    notice.unk00 = 3;
    notice.unk04 = &slots[owner->unk3C];
    notice.unk08 = value;
    func_8008FC3C(owner->unk14, &notice, 0);
}
