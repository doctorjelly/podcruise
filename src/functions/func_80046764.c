/* Independently written from scratchpad spec specs/func_8004678C.md. */

#include "podcruise/types.h"

extern void func_80005B80(void);

extern s32 D_8011A2A8;
extern s32 D_8011A2AC;
extern s32 D_8011A2B0;
extern s32 D_8011A2B4[148];
extern s32 D_8011A508;
extern s32 D_8011A50C;
extern s32 D_8011A510;
extern s32 D_8011A514[148];

void func_80046764(void) {
    s32 i;

    D_8011A508 = 0; D_8011A2A8 = 0;
    D_8011A50C = 0; D_8011A2AC = 0;
    D_8011A510 = 0;
    D_8011A2B0 = 0; for (i = 0; i < 148; i++) {
        D_8011A514[i] = 0;
        D_8011A2B4[i] = 0;
    }
    func_80005B80();
}
