/* Independently written from scratchpad spec specs/func_80082B38.md. */

#include "podcruise/types.h"

extern void func_80014CC0(f32 angle, f32 *sine, f32 *cosine);
extern void func_800154D0(f32 *vector);

void func_80082B38(f32 *out, f32 *in) {
    f32 unused;
    f32 sine;
    f32 cosine;
    f32 axis[3];

    (void)unused;
    func_80014CC0(in[3] * 0.5f, &sine, &cosine);
    axis[0] = in[0];
    axis[1] = in[1];
    axis[2] = in[2];
    func_800154D0(axis);
    out[0] = axis[0] * sine;
    out[1] = axis[1] * sine;
    out[2] = axis[2] * sine;
    out[3] = cosine;
}
