/* Independently written from scratchpad spec specs/func_8003EF78.md. */

#include "podcruise/types.h"

extern void func_8003EFDC(s16, s16, f32, u8, u8, u8, u8, s32);

void func_8003EF78(s16 arg0, s16 arg1, f32 arg2, s32 arg3) {
    func_8003EFDC(arg0, arg1, arg2, 0xFF, 0xFF, 0xFF, 0xFF, arg3);
}
