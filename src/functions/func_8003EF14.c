/* Independently written from scratchpad spec specs/func_8003EF14.md. */

#include "podcruise/types.h"

extern void func_8003EA84(s16, s16, u8, u8, u8, u8, s32, s32, s32);

void func_8003EF14(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    func_8003EA84(arg1, arg2, 0xFF, 0xFF, 0xFF, 0xFF, arg3, arg0, 1);
}
