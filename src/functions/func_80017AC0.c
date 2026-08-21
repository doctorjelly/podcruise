/* Recovered from specification scratchpad specs/func_80017AC0.md */
#include "podcruise/types.h"

extern f32 func_800154D0(f32 *);

void func_80017AC0(f32 *arg0, f32 *arg1, f32 *arg2) {
    arg0[0] = arg1[0];
    arg0[1] = arg1[1];
    arg0[2] = arg1[2];
    func_800154D0(arg0);
    arg0[3] = arg0[0] * arg2[0] + arg0[1] * arg2[1] + arg0[2] * arg2[2];
}
