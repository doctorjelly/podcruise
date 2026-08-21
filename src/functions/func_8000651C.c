/* Recovered per specs/func_8000651C.md */
#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 unk000[0xE4];
    /* 0x0E4 */ f32 unk0E4;
    /* 0x0E8 */ s32 unk0E8;
    /* 0x0EC */ s32 unk0EC;
    /* 0x0F0 */ u8 unk0F0[0x10];
    /* 0x100 */ s32 unk100;
    /* 0x104 */ u8 unk104[0x10];
    /* 0x114 */ f32 unk114;
    /* 0x118 */ s32 unk118;
    /* 0x11C */ u8 unk11C[0x8];
    /* 0x124 */ struct Cursor *unk124;
} Track;

struct Limits {
    u8 unk0[0x4];
    s16 unk4;
    s16 unk6;
};

struct Cursor {
    u8 unk0[0x4];
    s16 unk4;
    s16 unk6;
    struct Limits *unk8;
};

extern void func_80005CD4(f32 *out, Track *track, f32 position, s32 index);
extern void func_80005DA8(f32 *out, Track *track, f32 position, s32 index);

void func_8000651C(Track *track, s32 useSecond) {
    f32 pad0[1];
    struct Cursor *cursor;
    struct Limits *limits;
    f32 primary;
    f32 secondary;

    (void)pad0;
    func_80005CD4(&primary, track, track->unk114, track->unk118);

    if (track->unk100 & 0x20000000) {
        func_80005DA8(&secondary, track, (f32)track->unk0EC, track->unk0E8);
        primary = track->unk0E4 * primary;
        primary = (1.0f - track->unk0E4) * secondary + primary;
    }

    if (track->unk124 != 0) {
        limits = track->unk124->unk8;
        cursor = track->unk124;
        if (limits != 0) {
            if (useSecond == 0) {
                cursor->unk4 = (s16)((f32)limits->unk4 * primary);
                while (cursor->unk4 > limits->unk4) {
                    cursor->unk4 = cursor->unk4 - limits->unk4;
                }
                while (cursor->unk4 < 0) {
                    cursor->unk4 = cursor->unk4 + limits->unk4;
                }
            } else {
                cursor->unk6 = (s16)((f32)limits->unk6 * primary);
                while (cursor->unk6 > limits->unk6) {
                    cursor->unk6 = cursor->unk6 - limits->unk6;
                }
                while (cursor->unk6 < 0) {
                    cursor->unk6 = cursor->unk6 + limits->unk6;
                }
            }
        }
    }
}
