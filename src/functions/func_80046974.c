/* Independently written from scratchpad spec specs/func_80046974.md. */

#include "podcruise/types.h"

extern void func_80018324(void *, s32);

extern u8 D_8011A288[];
extern s32 D_8011A29C;
extern void *D_8011A2A0;
extern u8 D_8011A2A8[];

void func_80046974(void) {
    func_80018324(D_8011A288, 0x5064);
    D_8011A29C = 0x97;
    D_8011A2A0 = D_8011A2A8;
}
