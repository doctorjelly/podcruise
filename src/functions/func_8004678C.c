/* Specification: specs/func_8004678C.md (paired slot table reset) */
#include "podcruise/types.h"

typedef struct { s32 unk_00; s32 unk_04; s32 unk_08; s32 unk_0C; } Slot;

extern s32 D_8011A2B0;
extern Slot D_8011A2B4[37];
extern Slot D_8011A514[37];
extern void func_80005B80(void);

void func_8004678C(void) {
    s32 i;

    for (D_8011A2B0 = 0, i = 0; i < 37; i++) {
        D_8011A514[i].unk_04 = 0;
        D_8011A2B4[i].unk_04 = 0;
        D_8011A514[i].unk_08 = 0;
        D_8011A2B4[i].unk_08 = 0;
        D_8011A514[i].unk_0C = 0;
        D_8011A2B4[i].unk_0C = 0;
        D_8011A514[i].unk_00 = 0;
        D_8011A2B4[i].unk_00 = 0;
    }
    func_80005B80();
}
