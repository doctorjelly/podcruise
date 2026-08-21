/* Independently written from scratchpad spec specs/func_80088B20.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 unk00[0x30];
} PcTrackRecord;

typedef struct {
    /* 0x00 */ u8 unk00[0x14];
    /* 0x14 */ u8 unk14[0x28];
    /* 0x3C */ s32 index;
    /* 0x40 */ PcTrackRecord *records;
} PcTrackOwner;

typedef struct {
    /* 0x00 */ s16 kind;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ PcTrackRecord *record;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s32 unk0C;
} PcTrackRequest;

extern void func_8008FC3C(void *queue, PcTrackRequest *request, s32 flags);

void func_80088B20(PcTrackOwner *owner) {
    PcTrackRequest request;
    PcTrackRecord *records;

    records = owner->records;
    request.kind = 1;
    request.record = &records[owner->index];
    func_8008FC3C(owner->unk14, &request, 0);
}
