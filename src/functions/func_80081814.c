/* Specification: $S/specs/func_80081814.md */
#include "podcruise/types.h"

extern f32 func_800153C0(f32 *vector);

void func_80081814(f32 *source, f32 *translation, f32 *out, f32 *scale) {
    f32 length;
    f32 inverse;

    length = func_800153C0(&source[0]);
    inverse = 1.0f / length;
    scale[0] = length;
    out[0] = source[0] * inverse;
    out[1] = source[1] * inverse;
    out[2] = source[2] * inverse;
    out[3] = 0.0f;

    length = func_800153C0(&source[4]);
    inverse = 1.0f / length;
    scale[1] = length;
    out[4] = source[4] * inverse;
    out[5] = source[5] * inverse;
    out[6] = source[6] * inverse;
    out[7] = 0.0f;

    length = func_800153C0(&source[8]);
    inverse = 1.0f / length;
    scale[2] = length;
    out[8] = source[8] * inverse;
    out[9] = source[9] * inverse;
    out[10] = source[10] * inverse;
    out[11] = 0.0f;

    translation[0] = source[12];
    translation[1] = source[13];
    translation[2] = source[14];
    out[15] = 1.0f;
    out[12] = 0.0f;
    out[13] = 0.0f;
    out[14] = 0.0f;
}
