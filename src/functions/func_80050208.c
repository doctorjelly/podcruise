/* Independently written from specs/functions/func_80050208.md. */

#include "podcruise/types.h"

typedef struct {
    u8 pad00[0x64];
    s32 unk64;
    s32 unk68;
    u8 unk6C;
    u8 unk6D;
    u8 unk6E;
    u8 unk6F;
    u8 unk70;
    u8 unk71;
    u8 unk72[23];
    u8 pad89[5];
    u8 unk8E;
    u8 unk8F;
    u8 unk90;
} Slots80050208;

void func_80050208(Slots80050208 *state) {
    s32 index;

    state->unk64 = 0;
    state->unk68 = -1;
    state->unk6C = 1;
    state->unk6D = 0;
    state->unk6E = 0;
    state->unk6F = 0;
    state->unk70 = 1;
    state->unk71 = 12;
    state->unk8E = 3;
    state->unk8F = 2;
    state->unk90 = 2;

    state->unk72[2] = 2;
    state->unk72[1] = 1;
    state->unk72[0] = 0;

    for (index = 3; index < 23; index++) {
        state->unk72[index] = index;
    }
}
