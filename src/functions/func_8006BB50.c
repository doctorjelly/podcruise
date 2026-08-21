/* Independently written from scratchpad spec specs/func_8006BB50.md. */

#include "podcruise/types.h"

typedef struct {
    u8 pad00[0x60];
    u32 unk60;
    u32 unk64;
    u8 pad68[0x18C - 0x68];
    f32 unk18C;
    u8 pad190[0x1A0 - 0x190];
    f32 unk1A0;
    u8 pad1A4[0x1F4 - 0x1A4];
    f32 unk1F4;
} Actor8006BB50;

extern f32 D_800A5B54;
extern f32 D_800A5B58;
extern s32 D_800A52D4;

extern void func_80070764(Actor8006BB50 *actor, s32 mode);

void func_8006BB50(Actor8006BB50 *actor, f32 arg1, f32 arg2) {
    if (actor->unk60 & 0x7000) {
        return;
    }
    if (actor->unk64 & 0x02000000) {
        return;
    }
    if (actor->unk64 & 0x10000000) {
        actor->unk64 = actor->unk64 & ~0x10000000;
        return;
    }
    if (!(D_800A5B58 < arg2)) {
        return;
    }
    if (!(D_800A5B54 < arg1)) {
        return;
    }
    if (D_800A52D4 != 0) {
        return;
    }
    if (actor->unk1A0 < 200.0f || (actor->unk60 & 0x80)) {
        actor->unk60 = actor->unk60 | 0x1000;
        return;
    }
    if (actor->unk1F4 < 0.0f) {
        func_80070764(actor, 1);
    } else {
        func_80070764(actor, 2);
    }
    actor->unk60 = actor->unk60 | 0x800000;
    actor->unk18C = 5.0f;
}
