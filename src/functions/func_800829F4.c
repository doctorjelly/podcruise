/* Recovered from specification specs/func_800829F4.md (worker batch_03). */
#include "podcruise/types.h"

extern f32 func_80014F2C(f32 angle);
extern void func_80014CC0(f32 angle, f32 *sine, f32 *cosine);
extern f32 func_800154D0(f32 *vector);

extern f32 D_800ADCF8;
extern f32 D_800ADCFC;
extern f32 D_800ADD00;

void func_800829F4(f32 *out, f32 *in) {
    f32 half;
    f32 sine;
    f32 cosine;
    f32 magnitude;

    magnitude = in[0] * in[0] + in[1] * in[1] + in[2] * in[2];
    if (magnitude < D_800ADCF8 && -magnitude < D_800ADCF8) {
        out[0] = 0.0f;
        out[1] = 0.0f;
        out[3] = 0.0f;
        out[2] = 1.0f;
        return;
    }

    half = func_80014F2C(in[3]);
    func_80014CC0(half, &sine, &cosine);
    if (D_800ADCFC < sine && sine < D_800ADD00) {
        out[0] = 0.0f;
        out[1] = 0.0f;
        out[3] = 0.0f;
        out[2] = 1.0f;
        return;
    }

    out[3] = half + half;
    out[0] = in[0] / sine;
    out[1] = in[1] / sine;
    out[2] = in[2] / sine;
    func_800154D0(out);
}
