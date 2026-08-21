/* Independently written from scratchpad spec specs/func_800900E0.md. */

#include "podcruise/types.h"

typedef struct Event800900E0 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A;
    /* 0x0C */ s32 unk0C;
} Event800900E0;

typedef struct Sink800900E0 {
    /* 0x00 */ u8 unk00[8];
    /* 0x08 */ void (*unk08)(struct Sink800900E0 *sink, s32 kind, Event800900E0 *event);
} Sink800900E0;

typedef struct Stream800900E0 {
    /* 0x00 */ u8 unk00[0xC];
    /* 0x0C */ Sink800900E0 *unk0C;
    /* 0x10 */ u8 unk10[0xC8];
    /* 0xD8 */ s32 unkD8;
} Stream800900E0;

typedef struct Voice800900E0 {
    /* 0x00 */ u8 unk00[8];
    /* 0x08 */ Stream800900E0 *unk08;
    /* 0x0C */ u8 unk0C[0xE];
    /* 0x1A */ s16 unk1A;
} Voice800900E0;

typedef struct Clock800900E0 {
    /* 0x00 */ u8 unk00[0x1C];
    /* 0x1C */ s32 unk1C;
} Clock800900E0;

extern Event800900E0 *func_80088500(void);

void func_800900E0(Clock800900E0 *arg0, Voice800900E0 *arg1, s32 arg2) {
    Event800900E0 *event;

    if (arg1->unk08 != 0) {
        event = func_80088500();
        if (event != 0) {
            event->unk04 = arg0->unk1C + arg1->unk08->unkD8;
            event->unk08 = 14;
            event->unk0C = arg2;
            event->unk00 = 0;
            event->unk0A = arg1->unk1A;
            arg1->unk08->unk0C->unk08(arg1->unk08->unk0C, 3, event);
        }
    }
}
