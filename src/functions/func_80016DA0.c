/* Specification: $S/specs/func_80016DA0.md */
#include "podcruise/types.h"

void func_80016DA0(f32 *out, f32 scale, f32 *in) {
    int i;

    for (i = 0; i < 4; i++) {
        out[i] = in[i] * scale;
    }
}
