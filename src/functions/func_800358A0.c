/* Independently written from scratchpad spec specs/func_800358A0.md. */

#include "podcruise/types.h"

extern s32 D_800A3D60;
extern s32 D_800A4744;
extern s32 D_800D697C;

s32 func_800358A0(s32 arg0) {
    if (D_800D697C & 0x40) {
        arg0 &= ~0x00010000;
    }
    if (D_800D697C & 0x20) {
        arg0 &= ~0x00020000;
    }

    if (D_800A4744 == 0) {
        arg0 &= ~0x00000400;
        arg0 &= ~0x00000200;
        return arg0;
    }

    if (D_800A3D60 != 0) {
        if ((arg0 & 0x200) != 0) {
            if ((arg0 & 0x400) == 0) {
                arg0 |= 0x400;
                arg0 &= ~0x00000200;
                return arg0;
            }
        } else if ((arg0 & 0x400) != 0) {
            if ((arg0 & 0x200) == 0) {
                arg0 &= ~0x00000400;
                arg0 |= 0x200;
            }
        }
    }
    return arg0;
}
