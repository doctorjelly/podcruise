/* Independently written from the specification for func_8006A3EC. */

#include "podcruise/types.h"

typedef struct Actor {
    /* 0x000 */ u8 pad000[0x50];
    /* 0x050 */ u8 pad050[0xF4];
    /* 0x144 */ f32 unk144;
    /* 0x148 */ f32 unk148;
    /* 0x14C */ f32 unk14C;
    /* 0x150 */ f32 unk150;
} Actor;

typedef struct Message {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ f32 unk08;
    /* 0x0C */ u8 pad0C[0x14];
} Message;

extern void func_800155EC(f32 *result, void *arg1, f32 arg2, f32 *arg3);
extern void func_80067718(Actor *actor, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4, s32 arg5);
extern void func_8003F99C(Actor *actor, Message *message);

void func_8006A3EC(Actor *actor) {
    f32 sp54[3];
    f32 sp48[3];
    Message message;

    func_800155EC(sp54, (u8 *)actor + 0x50, 6.0f, &actor->unk144);

    sp48[0] = -actor->unk144;
    sp48[1] = -actor->unk148;
    sp48[2] = -actor->unk14C;
    func_80067718(actor, 0.2f, 0.0f, sp54, sp48, 2);

    message.unk00 = 0x48697474;
    message.unk04 = 0x56684C74;
    message.unk08 = actor->unk150;
    func_8003F99C(actor, &message);
}
