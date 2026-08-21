/* Implements the specification in specs/func_800827E0.md (spherical interpolation of two 4-component orientations). */
#include "podcruise/types.h"

extern f32 func_80014F2C(f32 cosine);
extern void func_80014CC0(f32 angle, f32 *sine, f32 *cosine);
extern f64 D_800ADCF0;

void func_800827E0(f32 *from, f32 *to, f32 amount, f32 *out) {
    f32 fromScale;
    f32 toScale;
    f32 angle;
    f32 dot;
    f32 sineAngle;
    f32 sine;
    f32 cosine;
    f32 unkA;
    f32 flipped[4];
    f32 unkB;

    (void)unkA;
    (void)unkB;
    dot = from[0] * to[0] + from[1] * to[1] + from[2] * to[2] + from[3] * to[3];
    if (dot < 0.0f) {
        flipped[0] = -from[0];
        flipped[1] = -from[1];
        flipped[2] = -from[2];
        flipped[3] = -from[3];
        func_800827E0(flipped, to, amount, out);
        return;
    }
    if (1.0f < dot) {
        dot = 1.0f;
    }
    angle = func_80014F2C(dot);
    if ((f64)angle <= D_800ADCF0) {
        fromScale = 1.0f - amount;
        toScale = amount;
    } else {
        func_80014CC0(angle, &sine, &cosine);
        sineAngle = sine;
        func_80014CC0((1.0f - amount) * angle, &sine, &cosine);
        fromScale = sine / sineAngle;
        func_80014CC0(amount * angle, &sine, &cosine);
        toScale = sine / sineAngle;
    }
    out[0] = fromScale * from[0] + to[0] * toScale;
    out[1] = fromScale * from[1] + to[1] * toScale;
    out[2] = fromScale * from[2] + to[2] * toScale;
    out[3] = fromScale * from[3] + to[3] * toScale;
}
