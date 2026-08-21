/* Independently written from specs/functions/racer_state_initializer.md. */

#include "podcruise/types.h"

#define FLOAT_AT(base, offset) (*(f32 *)((u8 *)(base) + (offset)))
#define WORD_AT(base, offset) (*(s32 *)((u8 *)(base) + (offset)))
#define HALF_AT(base, offset) (*(s16 *)((u8 *)(base) + (offset)))
#define BYTE_AT(base, offset) (*(u8 *)((u8 *)(base) + (offset)))
#define POINTER_AT(base, offset) (*(void **)((u8 *)(base) + (offset)))

typedef struct {
    /* 0x00 */ s32 tag;
    /* 0x04 */ s32 mode;
} Request80072AD0;

extern f32 D_800AD918;
extern f32 D_800AD91C;
extern f32 D_800AD920;
extern f32 D_800AD924;
extern f32 D_800AD928;
extern f32 D_800AD92C;

extern f32 func_80004FB0(s32 handle, f32 *ray, f32 *hit, f32 *normal);
extern void func_80007D44(s32 kind, s32 index);
extern void func_800156DC(f32 *output, f32 *source);
extern void func_80015268(f32 *output, f32 x, f32 y, f32 z);
extern void func_80015288(f32 *output, f32 *source);
extern void func_80016F0C(f32 *matrix, f32 *output);
extern void func_80017874(f32 *matrix);
extern void func_800319CC(s32 argument);
extern void func_8003B250(void *holder, s32 index);
extern void func_8003F99C(void *slot, Request80072AD0 *request);
extern void func_80073470(void *owner);
extern s32 func_80073708(void *argument);
extern s32 func_80082BE0(void);
extern s32 func_80083D80(void *node, f32 *bounds, s32 flags);

void func_80072AD0(void *object, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   f32 *arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    Request80072AD0 request;
    f32 probe[14];
    f32 bounds[6];
    void *target;
    void *node;
    s32 index;
    s32 flags;
    s32 masked;
    s32 value;
    s32 spare;

    WORD_AT(object, 0xAC) = arg1;
    WORD_AT(object, 0xCC) = 0;
    WORD_AT(object, 0xD0) = 0;
    WORD_AT(object, 0xD4) = 0;
    WORD_AT(object, 0xD8) = 0;
    FLOAT_AT(object, 0xB0) = 0.0f;
    FLOAT_AT(object, 0xB4) = 0.0f;
    FLOAT_AT(object, 0xB8) = 0.0f;
    if (arg1 != 0) {
        func_8003B250((u8 *)object + 0xAC, 0);
    }
    WORD_AT(object, 0x64) = 0;
    WORD_AT(object, 0x60) = 0;
    FLOAT_AT(object, 0xB4) = D_800AD918;
    node = POINTER_AT(object, 0x1E70);
    value = WORD_AT(node, 0x4);
    if (value == 0x4C6F636C) {
        WORD_AT(object, 0x60) = 0x20;
    } else if (value == 0x52656D6F) {
        WORD_AT(object, 0x1E74) = -1;
        WORD_AT(object, 0x60) |= 0x40;
    } else if (value == 0x41414949) {
        WORD_AT(object, 0x60) |= 0x80;
    }
    node = POINTER_AT(object, 0x1E70);
    if (WORD_AT(node, 0x8) & 0x20) {
        WORD_AT(object, 0x60) |= 0x100;
    } else {
        WORD_AT(object, 0x60) &= ~0x100;
    }
    node = POINTER_AT(object, 0x1E70);
    FLOAT_AT(object, 0x6C) = FLOAT_AT(node, 0x1C);
    FLOAT_AT(object, 0x70) = FLOAT_AT(node, 0x20);
    FLOAT_AT(object, 0x74) = FLOAT_AT(node, 0x24);
    FLOAT_AT(object, 0x78) = FLOAT_AT(node, 0x28);
    FLOAT_AT(object, 0x7C) = FLOAT_AT(node, 0x2C);
    FLOAT_AT(object, 0x80) = FLOAT_AT(node, 0x30);
    FLOAT_AT(object, 0x84) = FLOAT_AT(node, 0x34);
    FLOAT_AT(object, 0x88) = FLOAT_AT(node, 0x38);
    FLOAT_AT(object, 0x8C) = FLOAT_AT(node, 0x3C);
    FLOAT_AT(object, 0x90) = FLOAT_AT(node, 0x40);
    FLOAT_AT(object, 0x94) = FLOAT_AT(node, 0x44);
    FLOAT_AT(object, 0x98) = FLOAT_AT(node, 0x48);
    FLOAT_AT(object, 0x9C) = FLOAT_AT(node, 0x4C);
    FLOAT_AT(object, 0xA0) = FLOAT_AT(node, 0x50);
    FLOAT_AT(object, 0xA4) = FLOAT_AT(node, 0x54);
    FLOAT_AT(object, 0xA4) = 2.0f;
    FLOAT_AT(object, 0xA8) = FLOAT_AT(node, 0x54);
    node = (void *)arg5;
    FLOAT_AT(object, 0x20) = FLOAT_AT(node, 0x0);
    FLOAT_AT(object, 0x24) = FLOAT_AT(node, 0x4);
    FLOAT_AT(object, 0x28) = FLOAT_AT(node, 0x8);
    FLOAT_AT(object, 0x2C) = FLOAT_AT(node, 0xC);
    FLOAT_AT(object, 0x30) = FLOAT_AT(node, 0x10);
    FLOAT_AT(object, 0x34) = FLOAT_AT(node, 0x14);
    FLOAT_AT(object, 0x38) = FLOAT_AT(node, 0x18);
    FLOAT_AT(object, 0x3C) = FLOAT_AT(node, 0x1C);
    FLOAT_AT(object, 0x40) = FLOAT_AT(node, 0x20);
    FLOAT_AT(object, 0x44) = FLOAT_AT(node, 0x24);
    FLOAT_AT(object, 0x48) = FLOAT_AT(node, 0x28);
    FLOAT_AT(object, 0x4C) = FLOAT_AT(node, 0x2C);
    FLOAT_AT(object, 0x50) = FLOAT_AT(node, 0x30);
    FLOAT_AT(object, 0x54) = FLOAT_AT(node, 0x34);
    FLOAT_AT(object, 0x58) = FLOAT_AT(node, 0x38);
    FLOAT_AT(object, 0x5C) = FLOAT_AT(node, 0x3C);
    probe[11] = 0.0f;
    probe[10] = 0.0f;
    probe[13] = 40.0f;
    probe[12] = -1.0f;
    probe[7] = FLOAT_AT(object, 0x50);
    probe[8] = FLOAT_AT(object, 0x54);
    probe[9] = FLOAT_AT(object, 0x58);
    FLOAT_AT(object, 0x58) = FLOAT_AT(object, 0x58)
        - (func_80004FB0(arg3, &probe[7], &probe[3], &probe[0]) - FLOAT_AT(object, 0x94));
    func_80016F0C((f32 *)((u8 *)object + 0x20), (f32 *)((u8 *)object + 0x8));
    WORD_AT(object, 0xEC) = 0;
    WORD_AT(object, 0xF8) = 0;
    WORD_AT(object, 0x100) = 0;
    WORD_AT(object, 0xF0) = 0;
    FLOAT_AT(object, 0x124) = 1.0f;
    FLOAT_AT(object, 0x120) = 1.0f;
    FLOAT_AT(object, 0xE0) = D_800AD91C;
    FLOAT_AT(object, 0xE4) = D_800AD91C;
    FLOAT_AT(object, 0x2BC) = 0.0f;
    FLOAT_AT(object, 0xDC) = 0.0f;
    FLOAT_AT(object, 0xE8) = 0.0f;
    FLOAT_AT(object, 0x118) = 0.0f;
    FLOAT_AT(object, 0x11C) = 0.0f;
    FLOAT_AT(object, 0x128) = 0.0f;
    FLOAT_AT(object, 0x130) = 0.0f;
    FLOAT_AT(object, 0x134) = 0.0f;
    FLOAT_AT(object, 0x138) = 0.0f;
    FLOAT_AT(object, 0x12C) = 0.0f;
    FLOAT_AT(object, 0x104) = D_800AD920;
    HALF_AT(object, 0x10C) = 0;
    HALF_AT(object, 0x10E) = 0;
    WORD_AT(object, 0x114) = 0;
    FLOAT_AT(object, 0x110) = 0.0f;
    FLOAT_AT(object, 0x338) = 0.0f;
    FLOAT_AT(object, 0x33C) = 0.0f;
    FLOAT_AT(object, 0x340) = 0.0f;
    FLOAT_AT(object, 0x310) = 0.0f;
    FLOAT_AT(object, 0x108) = D_800AD924;
    for (index = 0; index < 4; index++) {
        WORD_AT(object, 0x314 + index * 4) = 0;
    }
    WORD_AT(object, 0x328) = 0;
    WORD_AT(object, 0x32C) = 0;
    WORD_AT(object, 0x324) = -1;
    FLOAT_AT(object, 0x18C) = 0.0f;
    FLOAT_AT(object, 0x190) = 32.0f;
    func_80015268((f32 *)((u8 *)object + 0x194), 0.0f, 0.0f, -1.0f);
    FLOAT_AT(object, 0x1A0) = 0.0f;
    FLOAT_AT(object, 0x1B0) = 0.0f;
    FLOAT_AT(object, 0x1B4) = 0.0f;
    FLOAT_AT(object, 0x1A4) = 0.0f;
    FLOAT_AT(object, 0x1A8) = 0.0f;
    func_80015268((f32 *)((u8 *)object + 0x1B8), 0.0f, 0.0f, 0.0f);
    FLOAT_AT(object, 0x1EC) = 0.0f;
    FLOAT_AT(object, 0x1F0) = 0.0f;
    FLOAT_AT(object, 0x228) = 0.0f;
    FLOAT_AT(object, 0x220) = 0.0f;
    FLOAT_AT(object, 0x224) = 0.0f;
    FLOAT_AT(object, 0x1F4) = 0.0f;
    FLOAT_AT(object, 0x1F8) = 0.0f;
    FLOAT_AT(object, 0x1FC) = 0.0f;
    FLOAT_AT(object, 0x200) = 0.0f;
    FLOAT_AT(object, 0x204) = 0.0f;
    FLOAT_AT(object, 0x1EBC) = 0.25f;
    func_80015268((f32 *)((u8 *)object + 0x1C4), 0.0f, 0.0f, 0.0f);
    func_80015268((f32 *)((u8 *)object + 0x1D0), 0.0f, 0.0f, 0.0f);
    func_80015268((f32 *)((u8 *)object + 0x1DC), 0.0f, 0.0f, 0.0f);
    func_80015268((f32 *)((u8 *)object + 0x144), 0.0f, 0.0f, 1.0f);
    func_80015268((f32 *)((u8 *)object + 0x154), 0.0f, 0.0f, 0.0f);
    func_80015288((f32 *)((u8 *)object + 0x16C), (f32 *)((u8 *)object + 0x50));
    func_80015288((f32 *)((u8 *)object + 0x178), (f32 *)((u8 *)object + 0x50));
    func_80015268((f32 *)((u8 *)object + 0x160), 0.0f, 0.0f, 1.0f);
    FLOAT_AT(object, 0x150) = 0.0f;
    FLOAT_AT(object, 0x1ED8) = 0.0f;
    FLOAT_AT(object, 0x250) = 0.0f;
    FLOAT_AT(object, 0x1EC4) = 0.0f;
    FLOAT_AT(object, 0x1EC8) = 0.0f;
    FLOAT_AT(object, 0x218) = 100.0f;
    FLOAT_AT(object, 0x1EC0) = 80.0f;
    for (index = 0; index < 2; index++) {
        FLOAT_AT(object, 0x2F0 + index * 4) = 0.0f;
    }
    for (index = 0; index < 4; index++) {
        BYTE_AT(object, 0x2F8 + index) = 0;
    }
    FLOAT_AT(object, 0x2FC) = 0.0f;
    FLOAT_AT(object, 0x19B8) = 0.0f;
    FLOAT_AT(object, 0x1ED4) = 0.0f;
    FLOAT_AT(object, 0x208) = 0.0f;
    FLOAT_AT(object, 0x20C) = 0.0f;
    WORD_AT(object, 0x1E6C) = 0;
    FLOAT_AT(object, 0x184) = 0.0f;
    FLOAT_AT(object, 0x188) = 0.0f;
    FLOAT_AT(object, 0x240) = 0.0f;
    FLOAT_AT(object, 0x330) = 0.0f;
    FLOAT_AT(object, 0x334) = 0.0f;
    FLOAT_AT(object, 0x1E8) = 0.0f;
    FLOAT_AT(object, 0x1AC) = 1.0f;
    FLOAT_AT(object, 0x244) = 1.0f;
    FLOAT_AT(object, 0x248) = 1.0f;
    FLOAT_AT(object, 0x24C) = 1.0f;
    FLOAT_AT(object, 0x22C) = 1.0f;
    FLOAT_AT(object, 0x230) = 1.0f;
    FLOAT_AT(object, 0x234) = 10.0f;
    value = arg6;
    WORD_AT(object, 0x238) = value;
    if (value < 0) {
        WORD_AT(object, 0x238) = 0;
        value = 0;
    } else {
        value = value + 1;
        WORD_AT(object, 0x238) = value;
        if (value >= 3) {
            value = value - 1;
            WORD_AT(object, 0x238) = value;
        }
        if (value >= 6) {
            value = value - 1;
            WORD_AT(object, 0x238) = value;
        }
    }
    WORD_AT(object, 0x23C) = value;
    FLOAT_AT(object, 0x264) = 0.0f;
    WORD_AT(object, 0x1998) = 0;
    WORD_AT(object, 0x26C) = -0x100;
    WORD_AT(object, 0x140) = 0;
    WORD_AT(object, 0x1EE4) = 0;
    WORD_AT(object, 0x1EDC) = 0;
    FLOAT_AT(object, 0x1EE0) = 0.0f;
    FLOAT_AT(object, 0x21C) = 0.0f;
    FLOAT_AT(object, 0x268) = 60.0f;
    for (index = 0; index < 6; index++) {
        FLOAT_AT(object, 0x270 + index * 4) = 0.0f;
        FLOAT_AT(object, 0x288 + index * 4) = 0.0f;
        WORD_AT(object, 0x2A0 + index * 4) = 0;
    }
    FLOAT_AT(object, 0x2B8) = 0.0f;
    FLOAT_AT(object, 0x2BC) = 0.0f;
    FLOAT_AT(object, 0x2C0) = 0.0f;
    FLOAT_AT(object, 0x2C4) = 0.0f;
    FLOAT_AT(object, 0x2C8) = 0.0f;
    FLOAT_AT(object, 0x30C) = 0.0f;
    FLOAT_AT(object, 0x308) = 0.0f;
    WORD_AT(object, 0x1E3C) = 0;
    for (index = 0; index < 0x12; index++) {
        func_800156DC((f32 *)((u8 *)object + 0x19BC + index * 0x40),
                      (f32 *)((u8 *)object + 0x20));
    }
    WORD_AT(object, 0x1E40) = 9;
    WORD_AT(object, 0x1E44) = 6;
    func_80015268((f32 *)((u8 *)object + 0x1E48), 0.0f, 0.0f, 0.0f);
    func_80015268((f32 *)((u8 *)object + 0x1E54), 0.0f, 0.0f, 0.0f);
    FLOAT_AT(object, 0x1E60) = 0.0f;
    WORD_AT(object, 0x344) = arg2;
    WORD_AT(object, 0x13C) = arg3;
    WORD_AT(object, 0x304) = 0;
    WORD_AT(object, 0x300) = arg4;
    if (arg9 != 0) {
        if (WORD_AT(object, 0x60) & 0x20) {
            node = POINTER_AT(object, 0x1E70);
            if (BYTE_AT(node, 0x10) != 0) {
                WORD_AT(object, 0x304) = 2;
            }
        }
    }
    for (index = 0; index < 75; index++) {
        func_80017874((f32 *)((u8 *)object + 0x350 + index * 0x40));
        func_80015268((f32 *)((u8 *)object + 0x1610 + index * 0xC), 0.0f, 0.0f, 0.0f);
    }
    FLOAT_AT(object, 0x13C8) = -2000.0f;
    FLOAT_AT(object, 0x1408) = -2000.0f;
    for (index = 0; index < 4; index++) {
        FLOAT_AT(object, 0x199C + index * 4) =
            (f32)func_80082BE0() / (f32)2147483648.0 * 60.0f;
    }
    FLOAT_AT(object, 0x19B0) = 0.0f;
    request.tag = 0x734C4F44;
    FLOAT_AT(object, 0x19AC) = 1.0f;
    FLOAT_AT(object, 0x19B4) = 1.0f;
    if (arg8 >= 3) {
        request.mode = 3;
    } else if (arg8 >= 2) {
        request.mode = 2;
    } else if (arg7 >= 2) {
        request.mode = 1;
    } else {
        request.mode = 0;
    }
    func_8003F99C(object, &request);
    func_80073470(object);
    target = POINTER_AT(object, 0x344);
    if (target != 0) {
        node = POINTER_AT(target, 0xF8);
        if (node != 0) {
            WORD_AT(node, 0x10) |= 1;
            target = POINTER_AT(object, 0x344);
        }
        node = POINTER_AT(target, 0x8);
        if (node != 0) {
            WORD_AT(node, 0x10) |= 1;
            target = POINTER_AT(object, 0x344);
        }
        node = POINTER_AT(target, 0x10);
        if (node != 0) {
            WORD_AT(node, 0x10) |= 1;
            target = POINTER_AT(object, 0x344);
        }
        node = POINTER_AT(target, 0x38);
        if (node != 0) {
            WORD_AT(node, 0x10) |= 1;
            target = POINTER_AT(object, 0x344);
        }
    }
    FLOAT_AT(object, 0x1E64) = 2.0f;
    FLOAT_AT(object, 0x1E68) = 2.0f;
    if (target != 0) {
        node = POINTER_AT(target, 0xF8);
        if (node != 0) {
            if (func_80083D80(node, &bounds[0], 0) != 0) {
                FLOAT_AT(object, 0x1E64) = (bounds[3] - bounds[0]) * D_800AD928;
                FLOAT_AT(object, 0x1E68) = (bounds[4] - bounds[1]) * D_800AD928;
                FLOAT_AT(object, 0x1E64) = FLOAT_AT(object, 0x1E64) * D_800AD92C;
            }
        }
    }
    node = POINTER_AT(POINTER_AT(object, 0x1E70), 0x18);
    if (WORD_AT(node, 0x0) == 0xE) {
        FLOAT_AT(object, 0x1E64) = 3.0f;
        FLOAT_AT(object, 0x1E68) = 5.0f;
    }
    flags = WORD_AT(object, 0x60);
    masked = flags & 0x20;
    if (masked != 0) {
        node = POINTER_AT(object, 0x1E70);
        func_800319CC(BYTE_AT(node, 0x10));
        flags = WORD_AT(object, 0x60);
        masked = flags & 0x20;
    }
    if ((masked != 0) || (flags & 0x100)) {
        node = POINTER_AT(POINTER_AT(object, 0x1E70), 0x18);
        func_80007D44(1, WORD_AT(node, 0x0));
        masked = WORD_AT(object, 0x60) & 0x20;
    }
    if (masked != 0) {
        func_80073708(object);
    }
    (void)spare;
}
