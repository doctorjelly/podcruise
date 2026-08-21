/* Independently written from specs/functions/func_80031FA4.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s16 *unk04;
    /* 0x08 */ s16 *unk08;
    /* 0x0C */ s16 unk0C;
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ s16 unk18;
    /* 0x1A */ s16 unk1A;
    /* 0x1C */ u8 *unk1C;
    /* 0x20 */ u8 *unk20;
} StateFA4;

extern StateFA4 *D_800A2DD4;
extern f64 D_80120BF0;

void func_80031FA4(void) {
    s32 steps;
    s32 index;

    steps = 0;
    D_800A2DD4->unk14 = D_800A2DD4->unk14 - D_80120BF0;

    while (D_800A2DD4->unk14 < 0.0f) {
        steps++;
        D_800A2DD4->unk14 = D_800A2DD4->unk14 + D_800A2DD4->unk10;
    }

    if ((D_800A2DD4->unk04 != 0) && (steps > 0)) {
        for (index = 0; index < D_800A2DD4->unk18; index++) {
            D_800A2DD4->unk20[index] =
                (D_800A2DD4->unk20[index] + steps) % D_800A2DD4->unk0C;
            D_800A2DD4->unk04[D_800A2DD4->unk1C[index]] =
                D_800A2DD4->unk08[D_800A2DD4->unk20[index]];
        }
    }
}
