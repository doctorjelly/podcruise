/* Independently written from scratchpad spec specs/func_80051934.md. */

#include "podcruise/types.h"

extern s32 func_80082BE0(void);

f32 func_80051934(void) {
    s32 pick;

    pick = (s32)((f64)(func_80082BE0() / 2147483648.0f) * 2);
    return (f32)(pick * 2 - 1);
}
