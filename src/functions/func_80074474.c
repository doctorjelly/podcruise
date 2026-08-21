/* Specification: specs/func_80074474.md (scratchpad) */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u32 unk00;
} Record80074474;

typedef struct {
    /* 0x00 */ u8 pad00[0x18];
    /* 0x18 */ Record80074474 *unk18;
} Holder80074474;

typedef struct {
    /* 0x0000 */ u8 pad0000[0x50];
    /* 0x0050 */ u32 unk50;
    /* 0x0054 */ u8 pad0054[0x60 - 0x54];
    /* 0x0060 */ s32 unk60;
    /* 0x0064 */ s32 unk64;
    /* 0x0068 */ u8 pad0068[0x1A0 - 0x68];
    /* 0x01A0 */ f32 unk1A0;
    /* 0x01A4 */ u8 pad01A4[0x1998 - 0x1A4];
    /* 0x1998 */ s32 unk1998;
    /* 0x199C */ u8 pad199C[0x1E70 - 0x199C];
    /* 0x1E70 */ Holder80074474 *unk1E70;
} Actor80074474;

extern void func_80073CD0(Actor80074474 *, f32);
extern s32 func_80051FF4(void);
extern void func_80008BC4(s16, s32, f32, f32, void *, s32, s32, f32, f32);
extern f64 D_800AD970;
extern f32 D_800AD978;

void func_80074474(Actor80074474 *actor) {
    s32 flags;
    s16 index;
    f32 value;

    flags = actor->unk60;
    if ((flags & 0x20) || ((actor->unk64 << 5) < 0)) {
        func_80073CD0(actor, 0.7f);
        return;
    }
    if (flags & 0x100) {
        if (func_80051FF4() == 0) {
            func_80073CD0(actor, 0.7f);
            return;
        }
    }
    if ((f64)actor->unk1998 < D_800AD970) {
        value = actor->unk1A0 * D_800AD978 + 0.5f;
        index = (actor->unk1E70->unk18->unk00 & 1) + 0x9E;
        if (1.0f < value) {
            value = 1.0f;
        }
        func_80008BC4(index, 4, 0.25f, value, &actor->unk50, 1, 0, 10.0f, 500.0f);
    }
}
