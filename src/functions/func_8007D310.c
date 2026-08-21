/* Recovered from specification specs/func_8007D310.md */
#include "podcruise/types.h"

typedef struct Ent8007D310 {
    u8 pad0[0x14];
    s32 unk14;
    void *unk18;
} Ent8007D310;

extern s32 D_8011C930[];
extern s32 D_8011C950[];
extern Ent8007D310 *D_8011C970[];

extern Ent8007D310 *func_8007BB28(s32);
extern void func_800181BC(Ent8007D310 *, s32, s32, s32, s32);

Ent8007D310 *func_8007D310(s32 arg0, s32 arg1, s32 arg2) {
    Ent8007D310 *entry;

    entry = func_8007BB28(arg0);
    if (entry != 0) {
        entry->unk14 = 1;
        entry->unk18 = &D_8011C930[arg2];
        D_8011C970[D_8011C950[5]] = entry;
        D_8011C950[5] = D_8011C950[5] + 1;
        func_800181BC(entry, 2, 0xF, 0x10, 3);
        func_800181BC(entry, 2, arg1 & ~0xF, 0x10, 2);
    }
    return entry;
}
