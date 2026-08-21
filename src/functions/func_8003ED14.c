/* Implements specification $S/specs/func_8003ED14.md (draw-record append forwarder). */
#include "podcruise/types.h"

extern void func_8003EA84();

void func_8003ED14(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7)
s32 arg0;
s16 arg1;
s16 arg2;
u8 arg3;
u8 arg4;
u8 arg5;
u8 arg6;
s32 arg7;
{
    func_8003EA84(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg0, 0);
}
