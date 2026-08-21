/* Independently written from scratchpad spec specs/func_8000787C.md. */

#include "podcruise/types.h"

extern s32 D_8009A2B8;
extern s32 D_8009A328;

void func_8000787C(f32 level) {
    if (D_8009A2B8 != 0) {
        D_8009A328 = (s32)(level * 32000.0f);
    }
}
