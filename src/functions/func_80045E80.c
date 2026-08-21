/* Independently written from scratchpad spec specs/func_80045E80.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 unk00[0x14];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ void *unk18;
    /* 0x1C */ u8 unk1C[0x3C];
} Item; /* 0x58 */

/* The single element at 0x16C4 shares storage with the 0x1094 table, so the
   two views of that region are expressed as a union. */
typedef struct {
    /* 0x0000 */ u8 unk0000[0xBB8];
    /* 0x0BB8 */ Item *unk0BB8;
    /* 0x0BBC */ u8 unk0BBC[0x104C - 0xBBC];
    /* 0x104C */ Item *unk104C[18];
    /* 0x1094 */ union {
        Item table[6][3];
        struct {
            u8 pad[0x16C4 - 0x1094];
            Item entry;
        } single;
    } unk1094;
} Owner;

extern void func_80018324(Item *item, s32 kind);

void func_80045E80(Owner *owner) {
    Item *root;
    Item *item;
    s32 i;
    s32 j;

    root = &owner->unk1094.single.entry;
    func_80018324(root, 0x5064);
    root->unk14 = 18;
    root->unk18 = owner->unk104C;
    owner->unk0BB8 = root;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 3; j++) {
            item = &owner->unk1094.table[i][j];
            func_80018324(item, 0xD065);
            item->unk14 = 0;
            item->unk18 = 0;
            owner->unk104C[(i * 3) + j] = item;
        }
    }
}
