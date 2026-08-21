/* Recovered from specification specs/func_80089790.md (worker tier2_18). */
#include "podcruise/types.h"

typedef struct {
    u8 unk00[0x28];
    s32 unk28;
    u8 unk2C[0x4];
} Slot;

typedef struct {
    u8 unk00[0x14];
    u8 unk14[0x28];
    s32 unk3C;
    Slot *unk40;
} Owner;

typedef struct {
    s16 unk00;
    s16 unk02;
    Slot *unk04;
    s32 unk08;
    s32 unk0C;
} Request;

extern void func_8008FC3C(void *channel, Request *request, s32 flags);

void func_80089790(Owner *owner) {
    Request request;
    Slot *slots;

    slots = owner->unk40;
    if ((slots + owner->unk3C)->unk28 == 0) {
        request.unk00 = 0;
        request.unk04 = &slots[owner->unk3C];
        func_8008FC3C(owner->unk14, &request, 0);
    }
}
