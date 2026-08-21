/* Recovered from specification $S/specs/func_80039828.md */
#include "podcruise/types.h"

extern void func_8003960C(void);
extern void func_8003964C(void);
extern s32 func_800396E0(s32);
extern void func_80039768(s32);

void func_80039828(void) {
    s32 handle;

    handle = func_800396E0(0);
    if (handle == 0) {
        handle = func_800396E0(0x400);
        if (handle != 0) {
            func_80039768(0);
        }
    }
    if (handle != 0) {
        func_8003960C();
    } else {
        func_8003964C();
    }
}
