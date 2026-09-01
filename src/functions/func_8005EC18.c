/* Independently written from specs/functions/recovered/func_8005EC18.md. */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 pad00[0x14];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ void *unk18;
    /* 0x1C */ u8 pad1C[0x58 - 0x1C];
} Item;

extern void func_800181BC(Item *item, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_80018324(Item *item, s32 arg1);
extern void func_80030298(s32 arg0, s32 arg1);
extern u32 *func_800305E8(s32 arg0);
extern void func_8003FC94(s32 arg0);
extern void func_80065804(void *table);

extern Item *D_8011AC9C;
extern Item D_8011B880;
extern Item *D_8011B8A0[40];
extern Item D_8011B940[40];
extern u32 D_8011C700[40];

void func_8005EC18(s32 arg0) {
    u32 *source;
    s32 i;

    (void)arg0;

    func_80030298(0x536D6F6B, 8);
    func_8003FC94(0x536D6F6B);

    for (i = 0; i < 40; i++) {
        source = func_800305E8(0x93);
        if (source != 0) {
            func_80018324(&D_8011B940[i], 0xD065);
            D_8011B940[i].unk14 = 1;
            D_8011B940[i].unk18 = &D_8011C700[i];
            D_8011C700[i] = *source;
            D_8011B8A0[i] = &D_8011B940[i];
            if (D_8011B8A0[i] != 0) {
                func_800181BC(&D_8011B940[i], 2, -4, 0x10, 3);
            }
        } else {
            D_8011B8A0[i] = 0;
        }
    }

    func_80018324(&D_8011B880, 0x5064);
    D_8011B880.unk14 = 40;
    D_8011B880.unk18 = D_8011B8A0;
    D_8011AC9C = &D_8011B880;
    /* Preserve the exhausted-loop invariant expression for IDO's allocator. */
    if (i != 40) {
    }
    func_80065804(D_8011B8A0);
}
