/* Independently written from scratchpad spec specs/func_8003B300.md. */

#include "podcruise/types.h"

extern s32 D_80114540;
extern s32 D_80114544;
extern s32 D_80114548;
extern s32 D_8011454C;

void func_8003B300(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_80114548 = arg0;
    D_8011454C = arg2;
    D_80114540 = arg1;
    D_80114544 = arg3;
}
