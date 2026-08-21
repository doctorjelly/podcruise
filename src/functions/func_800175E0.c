/* Specification: specs/func_800175E0.md */
#include "podcruise/types.h"

extern f32 D_800A8810;
extern f32 D_800A8814;
extern void func_80014CC0(f32 angle, f32 *sine, f32 *cosine);

void func_800175E0(f32 *m, f32 angle, f32 x, f32 y, f32 z) {
    f32 cosine;
    f32 sine;
    f32 omc;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 xx;
    f32 yy;
    f32 zz;
    f32 cxx;
    f32 cyy;
    f32 d;

    func_80014CC0(angle, &sine, &cosine);
    if (z >= D_800A8810) {
        m[0] = cosine;
        m[5] = cosine;
        m[1] = sine;
        m[2] = 0.0f;
        m[6] = 0.0f;
        m[8] = 0.0f;
        m[4] = -sine;
        m[9] = 0.0f;
        m[10] = 1.0f;
    } else if (z <= D_800A8814) {
        m[0] = cosine;
        m[5] = cosine;
        m[1] = -sine;
        m[2] = 0.0f;
        m[6] = 0.0f;
        m[8] = 0.0f;
        m[9] = 0.0f;
        m[10] = 1.0f;
        m[4] = sine;
    } else {
        omc = 1.0f - cosine;
        sx = sine * x;
        sy = sine * y;
        sz = sine * z;
        yy = y * y;
        cyy = cosine * yy;
        xx = x * x;
        cxx = cosine * xx;
        zz = 1.0f - xx - yy;
        d = 1.0f - zz;
        m[0] = (cxx * zz + cyy) / d + xx;
        m[5] = (cyy * zz + cxx) / d + yy;
        m[10] = zz + cxx + cyy;
        m[1] = omc * (x * y) + sz;
        m[4] = omc * (x * y) - sz;
        m[2] = omc * (z * x) - sy;
        m[6] = omc * (z * y) + sx;
        m[9] = omc * (z * y) - sx;
        m[8] = omc * (z * x) + sy;
    }
    m[12] = 0.0f;
    m[13] = 0.0f;
    m[14] = 0.0f;
    m[3] = 0.0f;
    m[7] = 0.0f;
    m[11] = 0.0f;
    m[15] = 1.0f;
}
