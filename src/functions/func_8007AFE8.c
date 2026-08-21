/* Recovered per specs/func_8007AFE8.md (worker specification). */
#include "podcruise/types.h"

typedef struct Actor {
    u8 pad0[0x68];
    f32 unk68;
    u8 pad6C[0xC];
    s32 unk78;
} Actor;

extern f64 D_80120BF0;
extern void func_800181BC(s32, s32, s32, s32, s32);
extern void func_8003FD7C(Actor *);

void func_8007AFE8(Actor *actor) {
    if (actor->unk68 > 0.0f) {
        actor->unk68 = actor->unk68 - D_80120BF0;
    } else {
        if (actor->unk78 != 0) {
            if (actor->unk78 != 0) {
                func_800181BC(actor->unk78, 2, -4, 0x10, 3);
            }
        }
        func_8003FD7C(actor);
    }
}
