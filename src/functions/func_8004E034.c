/* Independently written from scratchpad spec specs/func_8004E034.md. */

#include "podcruise/types.h"

extern void func_80014CC0(f32 degrees, f32 *sine, f32 *cosine);

f32 func_8004E034(f32 arc, f32 radius) {
    f32 sine;
    f32 cosine;

    func_80014CC0(arc / radius * 180.0f, &sine, &cosine);
    return (1.0f - cosine) / 2.0f * radius;
}
