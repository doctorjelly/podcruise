/* Independently written from scratchpad spec specs/func_80089610.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 unk00[0x30];
} PcRecord;

typedef struct {
    /* 0x00 */ u8 unk00[0x14];
    /* 0x14 */ u8 unk14[0x28];
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ PcRecord *unk40;
} PcActor;

typedef struct {
    /* 0x00 */ s16 unk00;
    /* 0x04 */ PcRecord *unk04;
    /* 0x08 */ u8 unk08;
    /* 0x09 */ u8 unk09[7];
} PcMessage;

extern void func_8008FC3C(void *target, PcMessage *message, s32 flags);

void func_80089610(PcActor *actor, u8 value) {
    PcMessage message;
    PcRecord *base;

    base = actor->unk40;
    message.unk00 = 8;
    message.unk04 = &base[actor->unk3C];
    message.unk08 = value;
    func_8008FC3C(&actor->unk14, &message, 0);
}
