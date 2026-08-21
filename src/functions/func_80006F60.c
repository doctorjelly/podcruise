/* Implements specification specs/func_80006F60.md (queue-and-post helper). */
#include "podcruise/types.h"

extern u8 D_800D9BF8[];

extern void func_80087CC0(s32, s32);
extern void func_80087D70(void*, s32, s32, s32, s32, s32, void*);
extern void func_80087E80(void*, void*, s32);

void func_80006F60(s32 arg0, s32 arg1, s32 arg2) {
    u8 sp30[0x18];
    s32 sp2C;

    func_80087CC0(arg1, arg2);
    func_80087D70(sp30, 0, 0, arg0, arg1, arg2, D_800D9BF8);
    func_80087E80(D_800D9BF8, &sp2C, 1);
}
