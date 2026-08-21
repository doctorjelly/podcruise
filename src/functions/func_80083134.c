/* Independently written from scratchpad spec specs/func_80083134.md. */

#include "podcruise/types.h"

extern void func_80082FA4(s32, s32, s32 *, s32, s32, s32 *);

void func_80083134(s32 arg0, s32 arg1, s32 *arg2, s32 arg3) {
    s32 accepted;

    if (arg1 == 0) {
        *arg2 = 0;
        return;
    }

    accepted = 0;
    func_80082FA4(arg0, arg1, arg2, 0, arg3, &accepted);
    if (accepted == 0) {
        *arg2 = 0;
    }
}
