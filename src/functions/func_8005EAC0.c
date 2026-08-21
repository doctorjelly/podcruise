/* Recovered from specification $S/specs/func_8005EAC0.md (batch_06). */
#include "podcruise/types.h"

typedef struct {
    s32 unk00[5];
    s32 unk14;
    s32 *unk18;
    s32 unk1C[15];
} PcSlot;

extern void *D_8011AC98;
extern PcSlot D_8011B260;
extern PcSlot *D_8011B280[16];
extern PcSlot D_8011B2C0[16];
extern s32 D_8011B840[16];

extern void func_80030298(s32 tag, s32 count);
extern void func_8003FC94(s32 tag);
extern s32 *func_800305E8(s32 id);
extern void func_80018324(PcSlot *slot, s32 tag);
extern void func_800181BC(PcSlot *slot, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_8007B41C(void *table);

void func_8005EAC0(s32 arg0) {
    PcSlot *slot;
    s32 *entry;
    s32 i;

    (void)arg0;

    func_80030298(0x546F7373, 0x10);
    func_8003FC94(0x546F7373);

    for (i = 0; i != 16; i++) {
        entry = func_800305E8(0x12A);
        if (entry != 0) {
            slot = &D_8011B2C0[i];
            func_80018324(slot, 0xD065);
            slot->unk14 = 1;
            slot->unk18 = &D_8011B840[i];
            D_8011B840[i] = *entry;
            D_8011B280[i] = slot;
            if (D_8011B280[i] != 0) {
                func_800181BC(slot, 2, -4, 0x10, 3);
            }
        } else {
            D_8011B280[i] = 0;
        }
    }

    func_80018324(&D_8011B260, 0x5064);
    D_8011B260.unk14 = 0x10;
    D_8011B260.unk18 = (s32 *)D_8011B280;
    D_8011AC98 = &D_8011B260;
    func_8007B41C(D_8011B280);
}
