/* Independently written from scratchpad spec specs/func_8006E1CC.md. */

#include "podcruise/types.h"

typedef struct Actor {
    /* 0x000 */ u8 pad000[0x60];
    /* 0x060 */ s32 unk060;
    /* 0x064 */ s32 unk064;
    /* 0x068 */ u8 pad068[0x124];
    /* 0x18C */ f32 unk18C;
} Actor;

typedef struct Event {
    /* 0x00 */ s32 tag;
    /* 0x04 */ s32 value;
    /* 0x08 */ u8 pad08[0x20];
} Event;

extern s32 D_800A5998;
extern s32 D_8009B7D0;
extern s32 D_8009B7D8;
extern s32 D_800D76F0;

extern void func_8003F99C(Actor *, Event *);
extern void func_8006C6D0(Actor *, s32);
extern void func_8006D150(Actor *);
extern void func_8006D9DC(Actor *, f32);

void func_8006E1CC(Actor *actor) {
    s32 flags;
    Event event;

    if (D_800A5998 != 0) {
        event.tag = 0x536E6170;
        event.value = 2;
        func_8003F99C(actor, &event);
    }

    if ((D_8009B7D8 & 0x100) != 0 && D_8009B7D0 != 0) {
        func_8006C6D0(actor, 1);
        flags = D_800D76F0;
        if ((flags & 0x800) != 0 || (flags & 0x400) != 0) {
            event.tag = 0x536E6170;
            if ((flags & 0x800) != 0) {
                event.value = -1;
            } else {
                event.value = 1;
            }
            func_8003F99C(actor, &event);
        }
    }

    if ((actor->unk060 & 0xF) == 2) {
        func_8006D150(actor);
        if ((actor->unk060 & 0x4000) != 0) {
            actor->unk18C = 0.0f;
        } else if ((actor->unk064 & 0x20) != 0) {
            func_8006D9DC(actor, 1.0f);
        } else {
            func_8006D9DC(actor, 0.0f);
        }
    }
}
