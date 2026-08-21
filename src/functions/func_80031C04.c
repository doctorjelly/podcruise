/* Independently written from scratchpad spec specs/func_80031C04.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s32 unk00;
} Source80031C04;

typedef struct {
    /* 0x00 */ u8 pad00[0x10];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 pad11[0x7];
    /* 0x18 */ Source80031C04 *unk18;
} Owner80031C04;

typedef struct {
    /* 0x00 */ u8 pad00[0x2C];
    /* 0x2C */ u32 unk2C;
} Flags80031C04;

typedef struct {
    /* 0x0000 */ u8 pad0000[0x60];
    /* 0x0060 */ u32 unk60;
    /* 0x0064 */ u32 unk64;
    /* 0x0068 */ u8 pad0068[0x140 - 0x68];
    /* 0x0140 */ void *unk140;
    /* 0x0144 */ u8 pad0144[0x1A0 - 0x144];
    /* 0x01A0 */ f32 unk1A0;
    /* 0x01A4 */ u8 pad01A4[0x288 - 0x1A4];
    /* 0x0288 */ f32 unk288[6];
    /* 0x02A0 */ s32 unk2A0[6];
    /* 0x02B8 */ u8 pad02B8[0x1E70 - 0x2B8];
    /* 0x1E70 */ Owner80031C04 *unk1E70;
} Craft80031C04;

extern u32 D_80000318;

extern void func_800093B0(s32, s32, s32, s32, s32, s32, s32);
extern u32 func_80009524(s32, u32);
extern void func_8000953C(s32, u32);
extern void func_8000955C(s32, u32);
extern Flags80031C04 *func_800183A8(const void *object);
extern void func_800319F4(s32, s32);
extern void func_80031AB0(s32, s32, s16);
extern void func_80031BBC(s32);
extern s32 func_80082BE0(void);

void func_80031C04(Craft80031C04 *arg0) {
    register Craft80031C04 *craft;
    s32 index;
    Flags80031C04 *flags;
    s32 mask;
    s32 state;
    s32 which;
    s32 i;
    f32 best;
    f32 ratio;

    craft = arg0;
    best = -1.0f;
    mask = 0;
    state = craft->unk64;
    index = craft->unk1E70->unk10;
    if (state & 0x4000000) {
        func_80031BBC(index);
        return;
    }
    if (craft->unk60 & 0x1000) {
        return;
    }
    if (craft->unk60 & 0x4000) {
        return;
    }
    if (state & 0x4000) {
        func_800319F4(index, 0xB);
        return;
    }

    for (i = 0; i < 6; i++) {
        if (best < craft->unk288[i]) {
            mask |= craft->unk2A0[i];
            best = craft->unk288[i];
        }
    }

    if (mask & 8) {
        func_80031AB0(index, 9, (s16)(s32)(best * 248.0f));
        if (func_80009524(index, 0x40000) == 0) {
            if (D_80000318 >= 0x800000 || (craft->unk60 & 0x120) != 0) {
                which = craft->unk1E70->unk18->unk00;
            } else {
                which = -1;
            }
            func_800093B0(1, which, 0xC, 0xC, 0xC, 0xC, 0xC);
            func_8000953C(index, 0x40000);
        }
        return;
    }

    func_8000955C(index, 0x40000);
    state = craft->unk64;
    if (state & 0x200) {
        func_80082BE0();
        func_80031BBC(index);
        return;
    }
    if (state & 0x2000) {
        func_800319F4(index, 4);
        if (func_80009524(index, 0x80000) == 0) {
            if (D_80000318 >= 0x800000 || (craft->unk60 & 0x120) != 0) {
                which = craft->unk1E70->unk18->unk00;
            } else {
                which = -1;
            }
            func_800093B0(1, which, 2, 2, 2, 2, 2);
            func_8000953C(index, 0x80000);
        }
    } else if (craft->unk60 & 0x800000) {
        ratio = craft->unk1A0 / 800.0f;
        if (1.0f < ratio) {
            ratio = 1.0f;
        }
        func_80031AB0(index, 3,
                      (s16)(0xFAFA >> (s32)(((f32)1.0 - ratio) * 16.0f)));
        return;
    }

    if (craft->unk140 != 0 && 50.0f < craft->unk1A0) {
        flags = func_800183A8(craft->unk140);
        if (flags != 0) {
            if (flags->unk2C & 1) {
                func_80031BBC(index);
                return;
            }
            if (flags->unk2C & 8) {
                func_800319F4(index, 0);
            }
            if (flags->unk2C & 0x10) {
                func_800319F4(index, 0);
            }
            if (flags->unk2C & 0x200) {
                func_800319F4(index, 0);
            }
            if (flags->unk2C & 0x400) {
                func_800319F4(index, 0);
            }
        }
    }
}
