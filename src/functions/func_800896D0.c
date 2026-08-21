/* Independently written from scratchpad spec specs/func_800896D0.md. */

#include "podcruise/types.h"

typedef struct Entry800896D0 {
    /* 0x00 */ u8 unk00[0x30];
} Entry800896D0;

typedef struct Owner800896D0 {
    /* 0x00 */ u8 unk00[0x14];
    /* 0x14 */ u8 unk14[0x28];
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ Entry800896D0 *unk40;
} Owner800896D0;

typedef struct Notice800896D0 {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ Entry800896D0 *unk04;
    /* 0x08 */ f32 unk08;
    /* 0x0C */ s32 unk0C;
} Notice800896D0;

extern void func_8008FC3C(void *sink, Notice800896D0 *notice, s32 flags);

void func_800896D0(Owner800896D0 *arg0, f32 arg1) {
    Notice800896D0 notice;
    Entry800896D0 *entries;

    entries = arg0->unk40;
    notice.unk00 = 4;
    notice.unk04 = &entries[arg0->unk3C];
    notice.unk08 = arg1;
    func_8008FC3C(arg0->unk14, &notice, 0);
}
