/* Specification: specs/func_80044414.md (worker scratchpad) */
#include "podcruise/types.h"

typedef struct {
    u8 pad0[0x50];
    s32 unk50;
    u8 pad54[0x20];
    s32 unk74;
    u8 pad78[0xAF0];
    f32 unkB68;
} Actor;

extern s32 D_800D7700;
extern u32 D_800A4B10;
extern void func_80044370(s16 *, s32);

void func_80044414(Actor *actor) {
    s32 flags;

    flags = D_800D7700;
    if ((flags & 0x200) || (flags & 1)) {
        D_800A4B10 = 0x41627274;
        if (actor->unkB68 > 0.5f) {
            actor->unkB68 = 0.5f;
        }
    } else if ((actor->unk50 != 0 && actor->unk74 != 0) || actor->unkB68 <= 0.0f) {
        func_80044370((s16 *)actor, (s32)D_800A4B10);
    }
}
