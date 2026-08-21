/* Independently written from scratchpad spec specs/func_8003EE48.md. */

#include "podcruise/types.h"

extern void func_8003EA84(s16, s16, u8, u8, u8, u8, s32, s32, s32);

void func_8003EE48(arg0, arg1, arg2)
s16 arg0;
s16 arg1;
s32 arg2;
{
    func_8003EA84(arg0, arg1, 0xFF, 0xFF, 0xFF, 0xFF, arg2, -1, 1);
}
