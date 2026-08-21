/* Independently written from specs/functions/func_8000AAC0.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ f32 unk08;
    /* 0x0C */ f32 unk0C;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ u8 unk18;
    /* 0x19 */ u8 unk19;
    /* 0x1A */ u8 unk1A;
    /* 0x1B */ u8 unk1B;
    /* 0x1C */ s32 unk1C;
} Entry;

extern Entry D_800D2190[];

void func_8000AAC0(s16 index, f32 x, f32 y) {
    if (index >= 0) {
        D_800D2190[index].unk08 = x;
        D_800D2190[index].unk0C = y;
    }
}
