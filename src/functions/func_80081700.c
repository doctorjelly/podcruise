/* Independently written from scratchpad spec specs/func_80081700.md. */

#include "podcruise/types.h"

extern f32 D_800ADCB0;

f32 func_80081700(f32 arg0, f32 arg1) {
    f32 scaled = arg1 / D_800ADCB0;

    return 1.0f - (scaled / (scaled + arg0));
}
