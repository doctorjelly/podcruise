/* Specification: $S/specs/func_80017824.md */
#include "podcruise/types.h"

extern void func_800175E0(f32 *, f32, f32, f32, f32);
extern void func_80015724(void *, f32 *, s32);

void func_80017824(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    f32 temp[16];

    func_800175E0(temp, arg1, arg2, arg3, arg4);
    func_80015724(arg0, temp, arg5);
}
