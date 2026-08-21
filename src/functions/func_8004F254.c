/* Independently written from scratchpad spec specs/func_8004F254.md. */

#include "podcruise/types.h"

typedef struct Owner {
    /* 0x00 */ u8 pad00[0x71];
    /* 0x71 */ s8 unk71;
} Owner;

typedef struct Record {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ u8 pad0C[0x78];
    /* 0x84 */ s32 unk84;
} Record;

typedef struct Message {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ u8 pad0C[0x14];
} Message;

typedef struct Slot Slot;

extern Record D_80118F90[];
extern Slot *func_8003F714(s32 id, s32 key);
extern void func_8003F99C(Slot *slot, Message *message);

void func_8004F254(Owner *arg0) {
    Message message;
    Record *record;
    s32 index;
    s32 count;
    s32 slot;

    index = 0;
    count = 1;
    record = D_80118F90;
    for (slot = 0; slot < arg0->unk71; slot++) {
        if (record->unk04 == 0x4C6F636C || (record->unk08 & 0x20)) {
            message.unk00 = 0x4E41736E;
            message.unk04 = count;
            message.unk08 = record->unk84;
            func_8003F99C(func_8003F714(0x634D616E, index), &message);
            index++;
            count++;
        }
        record++;
    }
}
