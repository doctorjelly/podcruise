/* Independently written from the specification for func_80090330. */

#include "podcruise/types.h"

struct Owner;
struct Sink;

typedef struct Event {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A;
    /* 0x0C */ s32 unk0C;
} Event;

typedef struct Sink {
    /* 0x00 */ u8 pad00[0x8];
    /* 0x08 */ void (*unk08)(struct Sink *, s32, Event *, struct Owner *);
} Sink;

typedef struct Stream {
    /* 0x00 */ u8 pad00[0xC];
    /* 0x0C */ Sink *unk0C;
    /* 0x10 */ u8 pad10[0xC8];
    /* 0xD8 */ s32 unkD8;
} Stream;

typedef struct Owner {
    /* 0x00 */ u8 pad00[0x8];
    /* 0x08 */ Stream *unk08;
} Owner;

typedef struct Origin {
    /* 0x00 */ u8 pad00[0x1C];
    /* 0x1C */ s32 unk1C;
} Origin;

extern void *func_80088500(void);

void func_80090330(Origin *origin, Owner *owner, u8 value) {
    Event *event;
    Sink *sink;
    s32 amount;

    if (owner->unk08 != 0) {
        event = func_80088500();
        if (event != 0) {
            event->unk04 = origin->unk1C + owner->unk08->unkD8;
            event->unk08 = 0x10;
            amount = value;
            event->unk0C = (amount < 0) ? -amount : amount;
            event->unk00 = 0;
            sink = owner->unk08->unk0C;
            sink->unk08(sink, 3, event, owner);
        }
    }
}
