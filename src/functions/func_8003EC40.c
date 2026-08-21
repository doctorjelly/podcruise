/* Independently written from scratchpad spec specs/func_8003EC40.md. */

#include "podcruise/types.h"

extern void func_8003EA84(s16 arg0, s16 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5,
                          s32 arg6, s32 arg7, s32 arg8);

void func_8003EC40(s16 arg0, s16 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, s32 arg6) {
    func_8003EA84(arg0, arg1, arg2, arg3, arg4, arg5, arg6, -1, 0);
}
