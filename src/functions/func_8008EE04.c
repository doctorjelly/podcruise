/* Independently written from specs/functions/recovered/func_8008EE04.md. */

#include "podcruise/types.h"

typedef s32 (*Callback8008EE04)(void *, s32, void *);
#define CALLBACK_AT_8008EE04(target) \
    (*(Callback8008EE04 *)((u8 *)(target) + 8))

typedef struct {
    void *unk00;
    u8 pad04[0x1A - 0x04];
    s16 unk1A;
    u8 pad1C[0x38 - 0x1C];
    s32 unk38;
    void *unk3C;
    void *unk40;
    u8 pad44[0x48 - 0x44];
    s32 unk48;
} State8008EE04;

s32 func_8008EE04(void *state, s32 command, void *value) {
    void *target;
    State8008EE04 *owner;

    owner = state;
    switch (command) {
    case 3: {
        void *link;

        link = owner->unk40;
        if (link != 0) {
            *(void **)link = value;
        } else {
            owner->unk3C = value;
        }
        owner->unk40 = value;
        break;
    }
    case 4:
        target = owner->unk00;
        owner->unk38 = 1;
        owner->unk48 = 0;
        owner->unk1A = 1;
        if (target != 0) {
            CALLBACK_AT_8008EE04(target)(target, 4, value);
        }
        break;
    case 9:
        target = owner->unk00;
        owner->unk48 = 1;
        if (target != 0) {
            CALLBACK_AT_8008EE04(target)(target, 9, value);
        }
        break;
    case 1:
        owner->unk00 = value;
        break;
    default:
        target = owner->unk00;
        if (target != 0) {
            CALLBACK_AT_8008EE04(target)(target, command, value);
        }
        break;
    }
    return 0;
}
