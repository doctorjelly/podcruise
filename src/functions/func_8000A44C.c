/* Independently written from specs/functions/func_8000A44C.md. */

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
extern s32 D_8009B770;

void func_8000A44C(s16 index, s32 arg1) {
    Entry *entry;

    if (index < 200) {
        if (index >= D_8009B770) {
            D_8009B770 = index + 1;
        }
        entry = &D_800D2190[index];
        entry->unk00 = 0;
        entry->unk02 = 0;
        entry->unk08 = 1.0f;
        entry->unk0C = 1.0f;
        entry->unk10 = 0.0f;
        entry->unk14 = 1;
        entry->unk18 = 0xFF;
        entry->unk19 = 0xFF;
        entry->unk1A = 0xFF;
        entry->unk1B = 0xFF;
        entry->unk1C = arg1;
    }
}
