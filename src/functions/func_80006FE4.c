/* Specification: $S/specs/func_80006FE4.md */
#include "podcruise/types.h"

extern s32 func_80087FC0(s32, s32, s32, s32, s32);
extern void func_80006FD4(void);

s32 func_80006FE4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 result;

    (void)arg0;
    result = func_80087FC0(0, 0, arg1, arg2, arg3);
    func_80006FD4();
    return result;
}
