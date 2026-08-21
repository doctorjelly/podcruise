/* Independently written from the specification for func_80008BC4. */

#include "podcruise/types.h"

extern f32 D_8009AD08;
extern f32 D_8009AD0C;

extern void func_80008C58(void *arg0, s16 arg1, f32 arg2, f32 arg3, void *arg4,
                          s32 arg5, s32 arg6);

void func_80008BC4(void *arg0, s16 arg1, f32 arg2, f32 arg3, void *arg4,
                   s32 arg5, s32 arg6, f32 arg7, f32 arg8) {
    f32 keepA;
    f32 keepB;

    keepA = D_8009AD08;
    keepB = D_8009AD0C;
    D_8009AD08 = arg7;
    D_8009AD0C = arg8;
    func_80008C58(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
    D_8009AD08 = keepA;
    D_8009AD0C = keepB;
}
