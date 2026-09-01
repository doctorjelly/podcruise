/* Independently written from specs/functions/recovered/func_8008E9F0.md. */

#include "podcruise/types.h"

typedef s32 (*Callback8008E9F0)(void *, s32, void *);
#define CALLBACK_AT_8008E9F0(target) \
    (*(Callback8008E9F0 *)((u8 *)(target) + 8))

typedef struct {
    void *unk00;
    u8 pad04[0x18 - 0x04];
    f32 unk18;
    s32 unk1C;
    f32 unk20;
    s32 unk24;
    u8 pad28[0x30 - 0x28];
    s32 unk30;
} State8008E9F0;

s32 func_8008E9F0(void *state, s32 command, void *value) {
    union {
        void *pointer;
        s32 word;
        f32 number;
        u8 storage[12];
    } decoded;
    void *target;
    State8008E9F0 *owner;

    owner = state;
    switch (command) {
    case 1:
        owner->unk00 = value;
        break;
    case 4: {
        target = owner->unk00;
        owner->unk24 = 1;
        owner->unk30 = 0;
        owner->unk1C = 0;
        owner->unk20 = 0.0f;
        if (target != 0) {
            CALLBACK_AT_8008E9F0(target)(target, 4, 0);
        }
        break;
    }
    case 9: {
        target = owner->unk00;
        owner->unk30 = 1;
        if (target != 0) {
            CALLBACK_AT_8008E9F0(target)(target, 9, 0);
        }
        break;
    }
    case 7:
        decoded.pointer = value;
        owner->unk18 = decoded.number;
        break;
    case 8:
        owner->unk1C = 1;
        break;
    default: {
        target = owner->unk00;
        if (target != 0) {
            CALLBACK_AT_8008E9F0(target)(target, command, value);
        }
        break;
    }
    }
    return 0;
}
