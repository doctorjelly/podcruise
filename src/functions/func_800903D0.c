/* Independently written from specs/functions/recovered/func_800903D0.md. */
#include "podcruise/types.h"

struct Event800903D0;
struct Owner800903D0;

typedef struct Handler800903D0 {
    /* 0x00 */ u8 pad00[0x8];
    /* 0x08 */ void (*unk08)(struct Handler800903D0 *, s32,
                             struct Event800903D0 *, struct Owner800903D0 *);
} Handler800903D0;

typedef struct Context800903D0 {
    /* 0x00 */ u8 pad00[0xC];
    /* 0x0C */ Handler800903D0 *unk0C;
    /* 0x10 */ u8 pad10[0xC8];
    /* 0xD8 */ s32 unkD8;
} Context800903D0;

typedef struct Owner800903D0 {
    /* 0x00 */ u8 pad00[0x8];
    /* 0x08 */ Context800903D0 *unk08;
} Owner800903D0;

typedef struct Source800903D0 {
    /* 0x00 */ u8 pad00[0x1C];
    /* 0x1C */ s32 unk1C;
} Source800903D0;

typedef struct Event800903D0 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s16 unk08;
} Event800903D0;

extern Event800903D0 *func_80088500(void);

void func_800903D0(Source800903D0 *arg0, Owner800903D0 *arg1) {
    Event800903D0 *event;
    Handler800903D0 *handler;

    if (arg1->unk08 != 0) {
        event = func_80088500();
        if (event != 0) {
            event->unk04 = arg0->unk1C + arg1->unk08->unkD8;
            event->unk08 = 15;
            event->unk00 = 0;
            handler = arg1->unk08->unk0C;
            handler->unk08(handler, 3, event, arg1);
        }
    }
}
