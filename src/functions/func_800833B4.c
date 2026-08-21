/* Recovered from specification $S/specs/func_800833B4.md */
#include "podcruise/types.h"

extern void func_80017D58(void *, s32, f32);
extern s32 func_80017DA4(void *);
extern s32 func_80017DAC(void *);
void func_800833B4(void *arg0, f32 *arg1);

void func_800833B4(void *arg0, f32 *arg1) {
    register s32 flags;
    s32 count;
    s32 index;

    if (arg0 == 0) {
        return;
    }
    if (arg1 == 0) {
        return;
    }

    flags = func_80017DA4(arg0);
    if (flags == 0x5066) {
        for (index = 0; arg1[index] >= 0.0f; index++) {
            if (index == 0) {
                func_80017D58(arg0, index, 0.0f);
            } else {
                func_80017D58(arg0, index, arg1[index]);
            }
        }
        func_80017D58(arg0, index, -1.0f);
    }

    if ((flags & 0x4000) != 0) {
        count = func_80017DAC(arg0);
        for (index = 0; index < count; index++) {
            func_800833B4((*(void ***)((u8 *)arg0 + 0x18))[index], arg1);
        }
    }
}
