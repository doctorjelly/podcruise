/* Implements the specification in specs/func_80064E90.md */
#include "podcruise/types.h"

extern void func_800181BC(s32, s32, s32, s32, s32);
extern void func_8003FD7C(s32 *);

void func_80064E90(s32 *arg0) {
    s32 i;

    for (i = 0; i < arg0[0x1C]; i++) {
        if (arg0[0x3D + i] != 0) {
            func_800181BC(arg0[0x3D + i], 2, -4, 0x10, 3);
        }
    }
    if (((s32 **)arg0)[0x3C] != 0) {
        *((s32 **)arg0)[0x3C] = 0;
    }
    func_8003FD7C(arg0);
}
