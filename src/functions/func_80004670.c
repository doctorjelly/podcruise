/* Implements specs/func_80004670.md (dispatch wrapper, recovered specification). */
#include "podcruise/types.h"

extern s32 func_80003E4C(void *, void *, s32);
extern s32 func_80004000(void *, s32, s32, s32, f32);
extern s32 func_80004160(void *, s32, s32, s32, f32, s32, s32, s32);

s32 func_80004670(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5,
                  s32 arg6, s32 arg7, s32 arg8) {
    if (arg0 == 0) {
        return 0;
    }
    func_80004000(arg1, arg2, arg3, arg4, arg5);
    func_80003E4C(arg0, arg1, 0);
    return func_80004160(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
