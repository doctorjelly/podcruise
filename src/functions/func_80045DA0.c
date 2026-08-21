/* Independently written from scratchpad spec specs/func_80045DA0.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 unk00[0x14];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ void *unk18;
    /* 0x1C */ u8 unk1C[0x3C];
} Item; /* 0x58 */

typedef struct {
    /* 0x0000 */ u8 unk0000[0xBC4];
    /* 0x0BC4 */ Item *unk0BC4;
    /* 0x0BC8 */ u8 unk0BC8[0x16E0 - 0xBC8];
    /* 0x16E0 */ Item *unk16E0[12];
    /* 0x1710 */ Item unk1710[6][2];
    /* 0x1B30 */ Item unk1B30;
} Owner;

extern void func_80018324(Item *item, s32 kind);

void func_80045DA0(Owner *owner) {
    Item *root;
    Item *item;
    s32 i;
    s32 j;

    root = &owner->unk1B30;
    func_80018324(root, 0x5064);
    root->unk14 = 12;
    root->unk18 = owner->unk16E0;
    owner->unk0BC4 = root;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 2; j++) {
            item = &owner->unk1710[i][j];
            func_80018324(item, 0xD065);
            item->unk14 = 0;
            item->unk18 = 0;
            owner->unk16E0[(i * 2) + j] = item;
        }
    }
}
