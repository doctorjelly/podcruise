/* Implements specification specs/func_80060D70.md (guarded dispatch). */
#include "podcruise/types.h"

extern s32 func_80009524(s32, s32);
extern void func_800093B0(s32, s32, s32, s32, s32, s32, s32);

void func_80060D70(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (func_80009524(0, 0x10) == 0) {
        return;
    }
    if (func_80009524(0, 0x20) != 0) {
        return;
    }
    func_800093B0(2, 0, arg0, arg1, arg2, arg3, arg4);
}
