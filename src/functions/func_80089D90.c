/* Specification: $S/specs/func_80089D90.md */
#include "podcruise/types.h"

extern s32 func_800905F0(void);
extern s32 func_80090634(void);
extern s32 func_80090880(void *, void *);
extern s32 func_800910D4(void *);
extern s32 func_80091630(void *);

s32 func_80089D90(void *arg0, void *arg1, void *arg2) {
    s32 result;

    result = 0;
    func_800905F0();
    result = func_80090880(arg0, arg2);
    func_80090634();
    if (result != 0) {
        return result;
    }
    *(void **)((u8 *)arg1 + 4) = arg0;
    *(void **)((u8 *)arg1 + 8) = arg2;
    *(u32 *)arg1 = 0;
    *((u8 *)arg1 + 0x65) = 0xFF;
    result = func_800910D4(arg1);
    if (result != 0) {
        return result;
    }
    result = func_80091630(arg1);
    *(u32 *)arg1 |= 1;
    return result;
}
