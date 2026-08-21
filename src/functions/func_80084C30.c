/* Independently written from the specification for the graphics task descriptor setup. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ void *unk08;
    /* 0x0C */ u32 unk0C;
    /* 0x10 */ void *unk10;
    /* 0x14 */ u32 unk14;
    /* 0x18 */ void *unk18;
    /* 0x1C */ u32 unk1C;
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ void *unk28;
    /* 0x2C */ void *unk2C;
    /* 0x30 */ void *unk30;
} TaskBlock;

extern TaskBlock *D_801488C0;
extern u8 func_80097FF0[];
extern u8 D_800980C0[];
/* D_800980C0_2 is a second, distinct symbol that resolves to the same
   address as D_800980C0: the end of the blob that starts at
   func_80097FF0 coincides with the start of the blob at D_800980C0. */
extern u8 D_800980C0_2[];
extern u8 D_800AE1D0[];
extern void *D_800DB894;
extern void *D_800DB898;
extern void *D_801217B4;

void func_80084C30(s16 mode) {
    D_801488C0->unk08 = func_80097FF0;
    D_801488C0->unk0C = D_800980C0_2 - func_80097FF0;
    D_801488C0->unk28 = D_800DB894;
    D_801488C0->unk2C = D_800DB898;
    if (mode == 5) {
        D_801488C0->unk10 = D_800980C0;
        D_801488C0->unk18 = D_800AE1D0;
    }
    D_801488C0->unk30 = D_801217B4;
}
