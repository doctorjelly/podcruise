/* Specification: specs/func_80008B14.md (worker-authored) */
#include "podcruise/types.h"

extern void func_80008760(s32 arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5);

void func_80008B14(s32 arg0, s16 arg1, f32 arg2, f32 arg3, s32 arg4) {
    if (arg3 > 0.0f) {
        func_80008760(arg0, arg1, arg2, arg3, 0x40, arg4);
    }
}
