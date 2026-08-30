/* Independently written from specs/functions/recovered/func_8008E9F0.md. */

#include "podcruise/types.h"

#define WORD_AT(base, offset) (*(s32 *)((u8 *)(base) + (offset)))
#define FLOAT_AT(base, offset) (*(f32 *)((u8 *)(base) + (offset)))
#define POINTER_AT(base, offset) (*(void **)((u8 *)(base) + (offset)))

typedef s32 (*Callback8008E9F0)(void *, s32, void *);
#define CALLBACK_AT_8008E9F0(target) \
    (*(Callback8008E9F0 *)((u8 *)(target) + 8))

s32 func_8008E9F0(void *state, s32 command, void *value) {
    union {
        void *pointer;
        s32 word;
        f32 number;
    } decoded;
    void *target;

    target = POINTER_AT(state, 0);
    switch (command) {
    case 1:
        POINTER_AT(state, 0) = value;
        break;
    case 4:
        WORD_AT(state, 0x24) = 1;
        WORD_AT(state, 0x30) = 0;
        WORD_AT(state, 0x1C) = 0;
        FLOAT_AT(state, 0x20) = 0.0f;
        if (target != 0) {
            CALLBACK_AT_8008E9F0(target)(target, 4, 0);
        }
        break;
    case 7:
        decoded.pointer = value;
        FLOAT_AT(state, 0x18) = decoded.number;
        break;
    case 8:
        WORD_AT(state, 0x1C) = 1;
        break;
    case 9:
        WORD_AT(state, 0x30) = 1;
        if (target != 0) {
            CALLBACK_AT_8008E9F0(target)(target, 9, 0);
        }
        break;
    default:
        if (target != 0) {
            CALLBACK_AT_8008E9F0(target)(target, command, value);
        }
        break;
    }
    return 0;
}
