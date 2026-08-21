/* Independently written from scratchpad spec specs/func_8000D7DC.md. */

#include "podcruise/types.h"

extern void func_8000C5F0(s32);

extern s32 D_8009B7D8;

void func_8000D7DC(s32 arg0) {
    if (arg0 == 8) {
        if (D_8009B7D8 & 2) {
            func_8000C5F0(1);
        }
    }
}
