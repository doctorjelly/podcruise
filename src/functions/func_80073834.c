/* Independently written from the specification for func_80073834. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
} Func80073834Flags;

typedef struct {
    /* 0x000 */ u8 pad000[0x250];
    /* 0x250 */ f32 unk250;
    /* 0x254 */ u8 pad254[0xF0];
    /* 0x344 */ Func80073834Flags *unk344;
    /* 0x348 */ u8 pad348[0x80];
    /* 0x3C8 */ f32 unk3C8;
    /* 0x3CC */ u8 pad3CC[0x3C];
    /* 0x408 */ f32 unk408;
    /* 0x40C */ u8 pad40C[0x3C];
    /* 0x448 */ f32 unk448;
    /* 0x44C */ u8 pad44C[0x3C];
    /* 0x488 */ f32 unk488;
    /* 0x48C */ u8 pad48C[0x3C];
    /* 0x4C8 */ f32 unk4C8;
} Func80073834Target;

void func_80073834(Func80073834Target *arg0) {
    f32 step = arg0->unk250;

    if (arg0->unk344 == 0) {
        return;
    }
    if (arg0->unk344->unk04 != 0) {
        arg0->unk3C8 += step;
    }
    if (arg0->unk344->unk08 != 0) {
        arg0->unk408 += step;
    }
    if (arg0->unk344->unk0C != 0) {
        arg0->unk448 += step;
    }
    if (arg0->unk344->unk10 != 0) {
        arg0->unk488 += step;
    }
    if (arg0->unk344->unk14 != 0) {
        arg0->unk4C8 += step;
    }
}
