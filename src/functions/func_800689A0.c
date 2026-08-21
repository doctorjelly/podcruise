/* Independently written from scratchpad spec specs/func_800689A0.md. */

#include "podcruise/types.h"

typedef struct PcActor800689A0 {
    u8 unk000[0x60];
    s32 unk060;
    u8 unk064[0x24];
    f32 unk088;
    u8 unk08C[0x11C];
    f32 unk1A8;
} PcActor800689A0;

extern f32 D_800AD520;
extern f32 D_800AD524;
extern f64 D_80120BF0;

extern f32 func_80081700(f32 arg0, f32 arg1);

f32 func_800689A0(PcActor800689A0 *actor) {
    f32 result;

    if (actor->unk060 & 0x800000) {
        actor->unk1A8 = actor->unk1A8 + (f32)D_80120BF0 * 1.5f;
    } else {
        if (actor->unk1A8 > 0.0f) {
            actor->unk1A8 *= func_80081700(5.0f, (f32)D_80120BF0);
        }
        if (actor->unk1A8 < D_800AD520) {
            actor->unk1A8 = 0.0f;
        }
    }

    if (actor->unk060 & 0x200) {
        actor->unk060 = actor->unk060 & ~0x800000;
    }

    if (actor->unk1A8 > 0.0f) {
        result = actor->unk088 * actor->unk1A8 / (actor->unk1A8 + D_800AD524);
    } else {
        result = 0.0f;
    }
    return result;
}
