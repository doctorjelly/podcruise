/* Independently written from the specification for func_800902A0. */

#include "podcruise/types.h"

typedef struct Event800902A0 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A;
    /* 0x0C */ f32 unk0C;
} Event800902A0;

typedef struct Sink800902A0 {
    /* 0x00 */ u8 unk00[8];
    /* 0x08 */ void (*unk08)(struct Sink800902A0 *sink, s32 kind, Event800902A0 *event);
} Sink800902A0;

typedef struct Stream800902A0 {
    /* 0x00 */ u8 unk00[0xC];
    /* 0x0C */ Sink800902A0 *unk0C;
    /* 0x10 */ u8 unk10[0xC8];
    /* 0xD8 */ s32 unkD8;
} Stream800902A0;

typedef struct Voice800902A0 {
    /* 0x00 */ u8 unk00[8];
    /* 0x08 */ Stream800902A0 *unk08;
} Voice800902A0;

typedef struct Clock800902A0 {
    /* 0x00 */ u8 unk00[0x1C];
    /* 0x1C */ s32 unk1C;
} Clock800902A0;

extern Event800902A0 *func_80088500(void);

void func_800902A0(Clock800902A0 *arg0, Voice800902A0 *arg1, f32 arg2) {
    Event800902A0 *event;

    if (arg1->unk08 != 0) {
        event = func_80088500();
        if (event != 0) {
            event->unk04 = arg0->unk1C + arg1->unk08->unkD8;
            event->unk08 = 7;
            event->unk0C = arg2;
            event->unk00 = 0;
            arg1->unk08->unk0C->unk08(arg1->unk08->unk0C, 3, event);
        }
    }
}
