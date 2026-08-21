/* Implements specification specs/func_8008A710.md (recovered behavior). */
#include "podcruise/types.h"

extern void func_80093820(void);
extern void func_80093864(void);
extern s32 func_80093890(s32 arg0, s32 arg1);

s32 func_8008A710(s32 arg0, s32 arg1) {
    register s32 result;

    func_80093820();
    result = func_80093890(arg0, arg1);
    func_80093864();
    return result;
}
