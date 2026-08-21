/* Independently written from scratchpad spec specs/func_800334F4.md. */

#include "podcruise/types.h"

extern f64 D_80120BF0;

void func_800334F4(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 current;
    f32 target;

    (void)arg2;

    current = *arg0;
    target = -(arg1 / arg3) * arg4;
    if (target > 80.0f) {
        target = 80.0f;
    }
    if (target < -80.0f) {
        target = -80.0f;
    }
    current = current + (target - current) * 5.0 * D_80120BF0;
    *arg0 = current;
}
