/* Independently written from scratchpad spec specs/func_80045314.md. */
#include "podcruise/types.h"

extern void func_80039CD8(s32);
extern void func_80039EC0(s32);
extern void func_8003FA24(s32, s32 *);
extern void func_800464E8(void *, s32);
extern void func_800811CC(void);

s32 func_80045314(void *object, u32 *message, s32 arg2) {
    s32 tag[16];

    (void)arg2;
    switch (message[0]) {
    case 0x536C6570:
        *(s16 *)((u8 *)object + 0x6) = *(s16 *)((u8 *)object + 0x6) | 0x1000;
        break;
    case 0x57616B65:
        *(s16 *)((u8 *)object + 0x6) = *(s16 *)((u8 *)object + 0x6) & ~0x1000;
        func_80039EC0(7);
        func_80039CD8(0);
        return 1;
    case 0x4C6F6164:
        *(s32 *)((u8 *)object + 0x8) = 0;
        *(s32 *)((u8 *)object + 0x50) = 0;
        *(s32 *)((u8 *)object + 0xC4) = 0;
        ((f32 *)((u8 *)object + 0x84))[1] = 0.0f;
        ((f32 *)((u8 *)object + 0x84))[2] = 0.0f;
        ((f32 *)((u8 *)object + 0x84))[3] = 0.0f;
        ((f32 *)((u8 *)object + 0x84))[4] = 0.0f;
        ((f32 *)((u8 *)object + 0x84))[6] = 0.0f;
        ((f32 *)((u8 *)object + 0x84))[7] = 0.0f;
        ((f32 *)((u8 *)object + 0x84))[8] = 0.0f;
        ((f32 *)((u8 *)object + 0x84))[9] = 0.0f;
        ((f32 *)((u8 *)object + 0x84))[11] = 0.0f;
        ((f32 *)((u8 *)object + 0x84))[12] = 0.0f;
        ((f32 *)((u8 *)object + 0x84))[13] = 0.0f;
        ((f32 *)((u8 *)object + 0x84))[14] = 0.0f;
        ((f32 *)((u8 *)object + 0xB28))[1] = 0.0f;
        ((f32 *)((u8 *)object + 0xB28))[2] = 0.0f;
        ((f32 *)((u8 *)object + 0xB28))[3] = 0.0f;
        ((f32 *)((u8 *)object + 0xB28))[4] = 0.0f;
        ((f32 *)((u8 *)object + 0xB28))[6] = 0.0f;
        ((f32 *)((u8 *)object + 0xB28))[7] = 0.0f;
        ((f32 *)((u8 *)object + 0xB28))[8] = 0.0f;
        ((f32 *)((u8 *)object + 0xB28))[9] = 0.0f;
        ((f32 *)((u8 *)object + 0xB28))[11] = 0.0f;
        ((f32 *)((u8 *)object + 0xB28))[12] = 0.0f;
        ((f32 *)((u8 *)object + 0xB28))[13] = 0.0f;
        ((f32 *)((u8 *)object + 0xB28))[14] = 0.0f;
        ((f32 *)((u8 *)object + 0x84))[0] = 1.0f;
        ((f32 *)((u8 *)object + 0x84))[5] = 1.0f;
        ((f32 *)((u8 *)object + 0x84))[10] = 1.0f;
        ((f32 *)((u8 *)object + 0x84))[15] = 1.0f;
        ((f32 *)((u8 *)object + 0xB28))[0] = 1.0f;
        ((f32 *)((u8 *)object + 0xB28))[5] = 1.0f;
        ((f32 *)((u8 *)object + 0xB28))[10] = 1.0f;
        ((f32 *)((u8 *)object + 0xB28))[15] = 1.0f;
        *(f32 *)((u8 *)object + 0xC) = 0;
        /* fallthrough */
    case 0x52536574:
        tag[0] = 0x536C6570;
        func_8003FA24(0x5363656E, tag);
        return 1;
    case 0x4265676E:
        func_800464E8(object, (s32)message[1]);
        func_800811CC();
        break;
    default:
        return 0;
    }
    return 1;
}
