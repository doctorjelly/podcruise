/* Independently written from specs/functions/recovered/func_80070764.md. */
#include "podcruise/types.h"

typedef struct Pod {
    /* 0x0000 */ u8 unk0000[0x60];
    /* 0x0060 */ u32 unk0060;
    /* 0x0064 */ u32 unk0064;
    /* 0x0068 */ u8 unk0068[0x2A8];
    /* 0x0310 */ f32 unk0310;
    /* 0x0314 */ u8 unk0314[0xAC];
    /* 0x03C0 */ f32 unk03C0;
    /* 0x03C4 */ f32 unk03C4;
    /* 0x03C8 */ f32 unk03C8;
    /* 0x03CC */ u8 unk03CC[0x34];
    /* 0x0400 */ f32 unk0400;
    /* 0x0404 */ f32 unk0404;
    /* 0x0408 */ f32 unk0408;
    /* 0x040C */ u8 unk040C[0x1A64];
    /* 0x1E70 */ struct Owner *unk1E70;
} Pod;

typedef struct Owner {
    /* 0x00 */ u8 unk00[0x18];
    /* 0x18 */ s32 *unk18;
} Owner;

extern s32 func_80082BE0(void);
extern void func_80075648(Pod *pod, s32 kind, f32 *offset, f32 scale);
extern void *func_80065810(s32 kind, s32 flags, f32 value, f32 *position, f32 scale);
extern void func_80008BC4(s32 arg0, s16 arg1, f32 arg2, f32 arg3, void *arg4,
                          s32 arg5, s32 arg6, f32 arg7, f32 arg8);
extern void func_800093B0(s32, s32, s32, s32, s32, s32, s32);

extern u32 D_80000318;
extern f32 D_800AD804;
extern f32 D_800AD808;
extern f64 D_800AD810;
extern f64 D_800AD818;
extern f32 D_800AD820;
extern f32 D_800AD824;
extern f64 D_800AD828;
extern f64 D_800AD830;

void func_80070764(Pod *pod, s32 flags) {
    f32 head[5];
    f32 origin[3];
    s32 gapA;
    s32 fired;
    f32 gapB[2];
    f32 position[3];
    f32 tail[2];
    s32 random;
    s32 channel;
    f32 chance;
    s32 sound;
    f32 unit;

    (void)head;
    (void)gapA;
    (void)gapB;
    (void)tail;
    fired = 0;
    if (!(pod->unk0060 & 0x20)) {
        if (!(pod->unk0064 & 0x4000000)) {
            return;
        }
    }
    if (pod->unk0064 & 0x4000) {
        return;
    }
    if (pod->unk0060 & 0x7000) {
        return;
    }

    pod->unk0060 &= ~0x800000;
    pod->unk0060 &= ~0x200000;
    unit = 1.0f;
    pod->unk0310 = (f32)func_80082BE0() / 2147483648.0f * unit + 2.0f;
    pod->unk0064 = pod->unk0064 | 0x4000;

    if (flags & 2) {
        fired = 1;
        pod->unk0064 = pod->unk0064 | 0x8000;
        position[0] = pod->unk03C0;
        position[1] = pod->unk03C4;
        position[2] = pod->unk03C8;
        origin[2] = 0.0f;
        origin[1] = 0.0f;
        origin[0] = 0.0f;
        func_80075648(pod, 1, origin, 0.3f);
    } else if (flags & 1) {
        fired = 1;
        pod->unk0064 = pod->unk0064 | 0x10000;
        position[0] = pod->unk0400;
        position[1] = pod->unk0404;
        position[2] = pod->unk0408;
        origin[2] = 0.0f;
        origin[1] = 0.0f;
        origin[0] = 0.0f;
        func_80075648(pod, 2, origin, 0.3f);
    }

    if (fired) {
        func_80065810(3, 0, 2.0f, position, 1.0f);
        func_80065810(3, 0, 2.2f, position, 3.0f);

        chance = (f32)func_80082BE0() / 2147483648.0f;
        if (chance < D_800AD804) {
            sound = 0x34;
        } else if (chance < D_800AD808) {
            sound = 0x35;
        } else {
            sound = 0x36;
        }
        random = func_80082BE0();
        func_80008BC4(sound, 7,
                      (f32)((f64)((f32)random / 2147483648.0f) * D_800AD810 + D_800AD818),
                      1.0f, position, 0, 0, 10.0f, 500.0f);

        chance = (f32)func_80082BE0() / 2147483648.0f;
        if (chance < D_800AD820) {
            sound = 0x34;
        } else if (chance < D_800AD824) {
            sound = 0x35;
        } else {
            sound = 0x36;
        }
        random = func_80082BE0();
        func_80008BC4(sound, 7,
                      (f32)((f64)((f32)random / 2147483648.0f) * D_800AD828 + D_800AD830),
                      1.0f, position, 0, 0, 10.0f, 500.0f);

        if (!(D_80000318 < 0x800000) || (pod->unk0060 & 0x120)) {
            channel = *pod->unk1E70->unk18;
        } else {
            channel = -1;
        }
        func_800093B0(1, channel, 9, 9, 9, 9, 9);
    } else {
        if (!(D_80000318 < 0x800000) || (pod->unk0060 & 0x120)) {
            channel = *pod->unk1E70->unk18;
        } else {
            channel = -1;
        }
        func_800093B0(1, channel, 13, 14, 13, 14, 13);
    }
}
