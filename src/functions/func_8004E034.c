/* Independently written from scratchpad spec specs/func_8004E034.md. */

#include "podcruise/types.h"

extern void func_80014CC0(f32 degrees, f32 *sine, f32 *cosine);

f32 func_8004E034(f32 arc, f32 radius) {
    f32 result;
    f32 angle;
    f32 sine;
    f32 cosine;

    angle = arc / radius * 180.0f;
    func_80014CC0(angle, &sine, &cosine);
    result = (1.0f - cosine) / (f32)2.0 * radius;
    return result;
}
