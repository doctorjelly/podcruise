/* Independently written from the specification for func_80090170. */

#include "podcruise/types.h"

typedef struct Event80090170 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A;
    /* 0x0C */ s32 unk0C;
} Event80090170;

typedef struct Sink80090170 {
    /* 0x00 */ u8 unk00[8];
    /* 0x08 */ void (*unk08)(struct Sink80090170 *sink, s32 kind, Event80090170 *event);
} Sink80090170;

typedef struct Stream80090170 {
    /* 0x00 */ u8 unk00[0xC];
    /* 0x0C */ Sink80090170 *unk0C;
    /* 0x10 */ u8 unk10[0xC8];
    /* 0xD8 */ s32 unkD8;
} Stream80090170;

typedef struct Voice80090170 {
    /* 0x00 */ u8 unk00[8];
    /* 0x08 */ Stream80090170 *unk08;
} Voice80090170;

typedef struct Clock80090170 {
    /* 0x00 */ u8 unk00[0x1C];
    /* 0x1C */ s32 unk1C;
} Clock80090170;

extern Event80090170 *func_80088500(void);

void func_80090170(Clock80090170 *arg0, Voice80090170 *arg1, u8 arg2) {
    Event80090170 *event;

    if (arg1->unk08 != 0) {
        event = func_80088500();
        if (event != 0) {
            event->unk04 = arg0->unk1C + arg1->unk08->unkD8;
            event->unk08 = 12;
            event->unk0C = arg2;
            event->unk00 = 0;
            arg1->unk08->unk0C->unk08(arg1->unk08->unk0C, 3, event);
        }
    }
}
