/* Independently written from scratchpad spec specs/func_8006D9DC.md. */

#include "podcruise/types.h"

extern f32 D_800AD6A4;
extern f32 D_800AD6A8;
extern f64 D_800AD6B0;
extern f64 D_80120BF0;

void func_8006D9DC(f32 *state, f32 target) {
    f32 value;

    if (state[104] < 200.0f) {
        target = 0.0f;
    }

    if (state[130] < target) {
        state[130] = state[130] + D_800AD6A4 * (f32)D_80120BF0;
        if (target < state[130]) {
            state[130] = target;
        }
    } else if (target < state[130]) {
        state[130] = state[130] - D_800AD6A8 * (f32)D_80120BF0;
        if (state[130] < target) {
            state[130] = target;
        }
    }

    if (target == 0.0) {
        value = state[130];
        if (((value < 0.0f) ? -value : value) < D_800AD6B0) {
            state[130] = value * 0.5;
        }
    }
}
