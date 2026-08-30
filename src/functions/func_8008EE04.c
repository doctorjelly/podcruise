/* Independently written from specs/functions/recovered/func_8008EE04.md. */

#include "podcruise/types.h"

#define WORD_AT(base, offset) (*(s32 *)((u8 *)(base) + (offset)))
#define HALF_AT(base, offset) (*(s16 *)((u8 *)(base) + (offset)))
#define POINTER_AT(base, offset) (*(void **)((u8 *)(base) + (offset)))

typedef s32 (*Callback8008EE04)(void *, s32, void *);
#define CALLBACK_AT_8008EE04(target) \
    (*(Callback8008EE04 *)((u8 *)(target) + 8))

s32 func_8008EE04(void *state, s32 command, void *value) {
    void *target;

    target = POINTER_AT(state, 0);
    if (command == 1) {
        POINTER_AT(state, 0) = value;
    } else if (command == 3) {
        target = POINTER_AT(state, 0x40);
        if (target == 0) {
            POINTER_AT(state, 0x3C) = value;
        } else {
            *(void **)target = value;
        }
        POINTER_AT(state, 0x40) = value;
    } else if (command == 4) {
        WORD_AT(state, 0x38) = 1;
        WORD_AT(state, 0x48) = 0;
        HALF_AT(state, 0x1A) = 1;
        if (target != 0) {
            CALLBACK_AT_8008EE04(target)(target, 4, value);
        }
    } else if (command == 9) {
        WORD_AT(state, 0x48) = 1;
        if (target != 0) {
            CALLBACK_AT_8008EE04(target)(target, 9, value);
        }
    } else if (target != 0) {
        CALLBACK_AT_8008EE04(target)(target, command, value);
    }
    return 0;
}
