/* Independently written from specs/functions/matrix_from_euler.md. */

#include "podcruise/types.h"

extern void func_80014CC0(f32 angle, f32 *sine, f32 *cosine);

void func_8001734C(f32 *rotation, f32 first, f32 second, f32 third) {
    f32 sinFirst;
    f32 cosFirst;
    f32 sinSecond;
    f32 cosSecond;
    f32 sinThird;
    f32 cosThird;
    f32 coscos;
    f32 cossin;
    f32 sincos;
    f32 sinsin;

    func_80014CC0(first, &sinFirst, &cosFirst);
    func_80014CC0(second, &sinSecond, &cosSecond);
    func_80014CC0(third, &sinThird, &cosThird);

    coscos = cosFirst * cosThird;
    cossin = cosFirst * sinThird;
    sincos = sinFirst * cosThird;
    sinsin = sinFirst * sinThird;

    rotation[0] = coscos - sinsin * sinSecond;
    rotation[1] = cossin * sinSecond + sincos;
    rotation[2] = -sinThird * cosSecond;
    rotation[3] = -sinFirst * cosSecond;
    rotation[4] = cosFirst * cosSecond;
    rotation[5] = sinSecond;
    rotation[6] = sincos * sinSecond + cossin;
    rotation[7] = sinsin - coscos * sinSecond;
    rotation[8] = cosThird * cosSecond;
}
