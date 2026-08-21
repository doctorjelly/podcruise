/* Independently written from scratchpad spec specs/func_8007E0AC.md. */

#include "podcruise/types.h"

typedef struct {
    u8 unk00[0x14];
    s32 unk14;
    void *unk18;
} Struct8007E0AC;

extern void func_80018324(void *, s32);

extern Struct8007E0AC D_8011C950;
extern u8 D_8011C970[];

Struct8007E0AC *func_8007E0AC(void) {
    func_80018324(&D_8011C950, 0x5064);
    D_8011C950.unk14 = 0;
    D_8011C950.unk18 = D_8011C970;
    return &D_8011C950;
}
