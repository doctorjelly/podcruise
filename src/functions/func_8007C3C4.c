/* Independently written from scratchpad spec specs/func_8007C3C4.md. */

#include "podcruise/types.h"

extern void func_8003FD7C(void *object);
extern void func_80015268(f32 *vector, f32 x, f32 y, f32 z);

s32 func_8007C3C4(void *object, u32 *message, void *arg2) {
    (void)arg2;

    switch (message[0]) {
    case 0x4C6F6164:
        func_8003FD7C(object);
        break;
    case 0x52536574:
        func_8003FD7C(object);
        break;
    case 0x416C6F63:
        *(s32 *)((u8 *)object + 0x8) = 0;
        *(s32 *)((u8 *)object + 0xC) = 0;
        *(f32 *)((u8 *)object + 0x10) = 0.0f;
        *(f32 *)((u8 *)object + 0x14) = 0.0f;
        func_80015268((f32 *)((u8 *)object + 0x30), 0.0f, 0.0f, 0.0f);
        *(s32 *)((u8 *)object + 0x3C) = 0;
        *(s32 *)((u8 *)object + 0x40) = 0;
        *(s32 *)((u8 *)object + 0x44) = 0;
        *(s32 *)((u8 *)object + 0x4C) = 0;
        break;
    case 0x46726565:
        func_80015268((f32 *)((u8 *)object + 0x30), 0.0f, 0.0f, 0.0f);
        *(s32 *)((u8 *)object + 0x3C) = 0;
        *(s32 *)((u8 *)object + 0x40) = 0;
        *(s32 *)((u8 *)object + 0x44) = 0;
        *(s32 *)((u8 *)object + 0x4C) = 0;
        *(s32 *)((u8 *)object + 0xC) = 0;
        break;
    default:
        return 0;
    }
    return 1;
}
