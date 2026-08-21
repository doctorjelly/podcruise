#include "podcruise/types.h"
extern void func_80008760(s32, s16, f32, f32, s32, s32);
void func_80008B68(s32 arg0, s16 arg1, f32 arg2, f32 arg3, s32 arg4) {
    if (arg3 < 1.0f) { arg3 = 1.0f; }
    func_80008760(arg0, arg1, arg2, arg3, 0x40, arg4);
}
