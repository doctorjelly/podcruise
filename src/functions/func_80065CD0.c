/* Recovered from specification specs/func_80065CD0.md (worker batch_03). */
#include "podcruise/types.h"

extern f32 func_80014F2C(f32 value);
extern f32 func_800153C0(f32 *vector);
extern void func_80015538(f32 *result, f32 *left, f32 *right);

extern f32 D_800AD480;

void func_80065CD0(f32 *arg0, f32 *arg1, f32 *arg2, f32 *out) {
    f32 length;
    f32 angle;
    f32 dot;
    f32 normal[3];
    f32 tangent[3];

    out[0] = 0.0f;
    out[2] = 0.0f;
    dot = arg0[0] * arg2[0] + arg0[1] * arg2[1] + arg0[2] * arg2[2];
    out[1] = func_80014F2C(dot) + -90.0f;
    func_80015538(normal, arg2, arg0);
    func_80015538(tangent, arg1, normal);
    length = func_800153C0(normal);
    if (D_800AD480 < length) {
        angle = func_80014F2C((normal[0] * arg1[0] + normal[1] * arg1[1] + normal[2] * arg1[2]) / length);
        if (tangent[0] * arg0[0] + tangent[1] * arg0[1] + tangent[2] * arg0[2] > 0.0f) {
            out[2] = -angle;
        } else {
            out[2] = angle;
        }
    }
}
