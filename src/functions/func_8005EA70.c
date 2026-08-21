/* Specification: $S/specs/func_8005EA70.md */
#include "podcruise/types.h"

extern void func_80030298(s32, s32);
extern void func_8003FC94(s32);
extern s32 func_8007E0EC(s32, s32, s32);
extern s32 D_8011AC90;

void func_8005EA70(s32 *arg0) {
    func_80030298(0x54726967, 30);
    func_8003FC94(0x54726967);
    D_8011AC90 = func_8007E0EC(arg0[107], arg0[112], arg0[12]);
}
